#ifndef HORLOGE_H
#define HORLOGE_H

#include "MesTables_global.h"

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QThread>

#include "HeureLimite.h"

class MESTABLESSHARED_EXPORT MySystemDate
{
private:
    static QTime s_time;
    static QDate s_date;

public:
    static QTime currentTime();
    static QDate currentDate();
    static QDateTime currentDateTime();

    static void setCurrentTime(QTime time);
    static void setCurrentDate(QDate date);
    static void setCurrentDateTime(QDateTime);
};

class MESTABLESSHARED_EXPORT Horloge : public QThread
{
Q_OBJECT
public:
    Horloge(QObject *parent = 0);

    void startHorloge();
    void restartHorloge();
    void quitApp() { emit fermerApp(); }
    bool dbIsOpen()const { return m_connected;};    

signals:
    void minuteOvered();
    void secondOvered();
    void hourOvered();
    void dayOvered();
    void tenSecsOvered();
    void fiveSecsOvered();
    void twoSecsOvered();    
    void connexionIsBroken();
    void startHorlogeRequested(QDateTime);
    void restartHorlogeRequested(QDateTime);
    void fermerApp();

private:         
    bool m_connected;
    bool m_ready;   
    MySystemDate systemDate;

private slots:    
    void updateTime(QTime time);
    void updateDate(QDate date);
    void updateSecond(QTime time);
    void updateTwoSecs(QTime time);
    void updateFiveSecs(QTime time);
    void updateTenSecs(QTime time);
    void updateMinute(QTime time);
    void updateHour(QTime time);
    void updateDay(QDate day);
    void warningDBState();

protected:
    void run();

public:
    static QTime currentTime();
    static QDate currentDate();
    static QDateTime currentDateTime();
};

class MESTABLESSHARED_EXPORT HorlogeWorker : public QObject
{
    Q_OBJECT

public:
    HorlogeWorker(QObject * parent = 0);

signals:
    void updateTime(QTime time);
    void updateDate(QDate date);
    void minuteOvered(QTime time);
    void secondOvered(QTime time);
    void hourOvered(QTime time);
    void dayOvered(QDate day);
    void tenSecsOvered(QTime time);
    void fiveSecsOvered(QTime time);
    void twoSecsOvered(QTime time);    
    void connexionIsBroken();

private slots:
    void waitOneSecond();
    void restart(QDateTime);
    void start(QDateTime);

private:
    QTime m_time;
    QTimer m_second;
    QDate m_date;
    int m_restMSec;
    QSqlTableModel m_model;
};

#endif // HORLOGE_H
