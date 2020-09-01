#include "horloge.h"
#include <QMetaType>
#include <QDebug>

Horloge::Horloge(QObject *parent) :
    QThread(parent), m_ready(false)
{
    qDebug() << Q_FUNC_INFO << QThread::currentThreadId(); // Le thread principal
     // On démarre le thread travailleur.
    start();
    // On attend que le thread soit prêt.
     while(!m_ready) msleep(50);
}

void Horloge::startHorloge()
{    
    qDebug() << Q_FUNC_INFO << QThread::currentThreadId(); // Le thread principal
    m_connected = true;
    QDateTime fullDate = HeureLimite::currentHourSyst();
    systemDate.setCurrentDateTime(fullDate);
    emit startHorlogeRequested(fullDate);
}

void Horloge::restartHorloge()
{
    qDebug() << Q_FUNC_INFO << QThread::currentThreadId(); // Le thread principal
    m_connected = true;
    QDateTime fullDate = HeureLimite::currentHourSyst();
    systemDate.setCurrentDateTime(fullDate);
    emit restartHorlogeRequested(fullDate);
}

QDate Horloge::currentDate()
{
    return MySystemDate::currentDate();
}

QDateTime Horloge::currentDateTime()
{
    return MySystemDate::currentDateTime();
}

QTime Horloge::currentTime()
{
    return MySystemDate::currentTime();
}

void Horloge::run()
{
    qDebug() << Q_FUNC_INFO << QThread::currentThreadId(); // Le thread travailleur
    // Ce QObject vit dans le thread travailleur
    HorlogeWorker worker; // NE PAS définir le pointeur this comme parent.

    connect(this, SIGNAL(startHorlogeRequested(QDateTime)), &worker, SLOT(start(QDateTime)));
    connect(this, SIGNAL(restartHorlogeRequested(QDateTime)), &worker, SLOT(restart(QDateTime)));
    connect(&worker, SIGNAL(updateTime(QTime)), this, SLOT(updateTime(QTime)));
    connect(&worker, SIGNAL(updateDate(QDate)), this, SLOT(updateDate(QDate)));
    connect(&worker, SIGNAL(secondOvered(QTime)), this, SLOT(updateSecond(QTime)));
    connect(&worker, SIGNAL(twoSecsOvered(QTime)), this, SLOT(updateTwoSecs(QTime)));
    connect(&worker, SIGNAL(fiveSecsOvered(QTime)), this, SLOT(updateFiveSecs(QTime)));
    connect(&worker, SIGNAL(tenSecsOvered(QTime)), this, SLOT(updateTenSecs(QTime)));
    connect(&worker, SIGNAL(minuteOvered(QTime)), this, SLOT(updateMinute(QTime)));
    connect(&worker, SIGNAL(hourOvered(QTime)), this, SLOT(updateHour(QTime)));
    connect(&worker, SIGNAL(dayOvered(QDate)), this, SLOT(updateDay(QDate)));
    connect(&worker, SIGNAL(connexionIsBroken()), this, SLOT(warningDBState()));

    m_ready = true;

    exec();
}

void Horloge::warningDBState()
{    
    m_connected = false;
    emit connexionIsBroken();
}

void Horloge::updateDay(QDate day)
{
    systemDate.setCurrentDate(day);
    emit dayOvered();
}

void Horloge::updateFiveSecs(QTime time)
{
    emit fiveSecsOvered();
}

void Horloge::updateHour(QTime time)
{
    emit hourOvered();
}

void Horloge::updateMinute(QTime time)
{
    emit minuteOvered();
}

void Horloge::updateSecond(QTime time)
{    
    systemDate.setCurrentTime(time);
    emit secondOvered();
}

void Horloge::updateTenSecs(QTime time)
{    
    emit tenSecsOvered();    
}

void Horloge::updateTwoSecs(QTime time)
{
    emit twoSecsOvered();
}

void Horloge::updateDate(QDate date)
{
    systemDate.setCurrentDate(date);
}

void Horloge::updateTime(QTime time)
{
    systemDate.setCurrentTime(time);
}

/* --------------- implémentation de l'horloge worker ------------------------------*/
HorlogeWorker::HorlogeWorker(QObject *parent) :
        QObject(parent)
{        
    connect(&m_second, SIGNAL(timeout()), this, SLOT(waitOneSecond()));
}

void HorlogeWorker::waitOneSecond()
{
    if(m_model.select())
    {        
        // hh : mm : 00
        m_time = m_time.addSecs(1);
        emit secondOvered(m_time);

        if(m_time.second() == 0)
            emit minuteOvered(m_time);

        if(m_time.minute() == 0)
            emit hourOvered(m_time);

        if(m_time == QTime(0,0)) // 24 h
        {
            m_date = m_date.addDays(1);
            emit dayOvered(m_date);
        }

        if(m_time.second() % 10 == 0)
        {
            // synchroniser l'heure à celle du serveur
            m_time = HeureLimite::currentHourSyst().time();
            emit tenSecsOvered(m_time);
        }

        if(m_time.second() % 5 == 0)        
            emit fiveSecsOvered(m_time);

        if(m_time.second() % 2 == 0)        
            emit twoSecsOvered(m_time);        

        m_second.start();
    }else
    {
        // connexion rompue
        m_second.stop();
        emit connexionIsBroken();
    }
}

void HorlogeWorker::restart(QDateTime time)
{    
    start(time);
}

void HorlogeWorker::start(QDateTime fullDate)
{
    qDebug() << Q_FUNC_INFO << QThread::currentThreadId(); // Thread travailleur    

    m_model.setTable(Actualiser::Libelle);
    m_second.setInterval(990);

    m_time = fullDate.time();
    m_date = fullDate.date();

    waitOneSecond();
}

/* -------------------------------- My system date ------------------------------------------*/
QTime MySystemDate::s_time = QTime();
QDate MySystemDate::s_date = QDate();

QDate MySystemDate::currentDate()
{
    return s_date;
}

QDateTime MySystemDate::currentDateTime()
{
    QDateTime current(s_date);
    current.setTime(s_time);

    return current;
}

QTime MySystemDate::currentTime()
{
    qDebug() << s_time.hour();
    qDebug() << Q_FUNC_INFO << QThread::currentThreadId(); // Thread travailleur
    return s_time;
}

void MySystemDate::setCurrentDate(QDate date)
{
    s_date = date;        
}

void MySystemDate::setCurrentDateTime(QDateTime dateTime)
{
    setCurrentDate(dateTime.date());
    setCurrentTime(dateTime.time());
}

void MySystemDate::setCurrentTime(QTime time)
{
    s_time = time;        
}
