#include "CompagnonFidele.h"

CompagnonFidele::CompagnonFidele(QGraphicsScene *scene, agent *r, QTextEdit *historique, Horloge *h, QString path)
{
    m_chemin = path;
    m_recepteur = r;
    m_horloge = h;
    m_historiqueDesMsgs = historique;

    m_pilote = new PiloteCompagnonFidele(scene, m_recepteur, m_chemin);
    connect(m_pilote, SIGNAL(msgAffiche()), this, SLOT(ecrireDansHistoriqueMsgs()));
    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(programmerVerif()));

    initialiserTimes();
    chargerInfos();    
}

CompagnonFidele::~CompagnonFidele()
{
    delete m_pilote;
    delete m_timeOccup;
    delete m_timeReserv;
}

void CompagnonFidele::setMuteVolume(bool mute)
{
    m_pilote->setMuteVolume(mute);
}

void CompagnonFidele::chargerInfos()
{
    m_occupations.clear();
    m_reservations.clear();

    QDateTime today = Horloge::currentDateTime();

    QList<QSqlRecord> recordsOccup;
    recordsOccup << occupation::occupationsEnCours();

    for(int i = 0; i < recordsOccup.count(); i++)
    {
        occupation oc(recordsOccup.at(i));
        if(oc.datedSortie().addSecs(-1*61*60) <= today)
        {
            m_occupations << oc;
        }
    }

    QList<QSqlRecord> recordsReserv;
    recordsReserv << chambreReservee::chambresReserveesEnCours();

    for(int i = 0; i < recordsReserv.count(); i++)
    {
        chambreReservee rv(recordsReserv.at(i));
        reservation reserv(rv.numReservation());
        if(reserv.datedEntree().addSecs(-3*61*60) <= today)
        {
            m_reservations << rv;
        }
    }
}

void CompagnonFidele::verifierFinOccupation(QTime now)
{
    if(m_occupations.isEmpty()) // pour être en phase avec la base de données
        return;

    int intervalle = 2; // 2 secondes d'intervalle

    if(now == t_1hAV)
        // 1 heure avant
    {
        afficherMsgFinLocationDans1H(intervalle);
        return;
    }

    if(now == t_30minAV) // 30 min avant
    {
        afficherMsgFinLocationDans30Min(intervalle);
        return;
    }

    if(now == t_10minAV)
        // 10 min avant
    {
        afficherMsgFinLocationDans10Min(intervalle);
        return;
    }

    if(now == timeEnd)
        // il est l'heure
    {
        afficherMsgLocationFinie(intervalle);
        return;
    }

    if(now > timeEnd && now < timeFinTol)
    {
        if(Horloge::currentTime().minute()%10 == 0) // chaque 10 minutes
        {
            signalerOccupTerminee();
        }
    }
}

void CompagnonFidele::signalerOccupTerminee()
{
    if(m_occupations.isEmpty())
        return;

    int intervalle = 2; // s
    // signaler
    afficherMsgApresFinLocation(intervalle);
}

void CompagnonFidele::programmerVerif()
{
    chargerInfos();

    // les autres avertissements
    if(m_occupations.isEmpty() && m_reservations.isEmpty())// pour être en phase avec la base de données
        return; // pas de vérif programmées

    //avertirTempsDeTolDepasse();

    QTime now = Horloge::currentTime();
    now.setHMS(now.hour(), now.minute(),0,0); // hh:mm:00:00 pour se rassurer

    if(!m_occupations.isEmpty())
    {
        verifierFinOccupation(now);
    }

    if(!m_reservations.isEmpty())
    {
        verifierReservEnCours(now);
    }
}

void CompagnonFidele::initialiserTimes()
{
    HeureLimite hl(1);
    timeEnd = hl.heureFinOccupation();// QTime(HEURE_DE_SORTIE, MINUTE_DE_SORTIE); // hh:mm:00:00
    timeFinTol = timeEnd.addSecs(hl.tempsTolerance() * 60);

    t_3hAV = timeEnd.addSecs(-3 * 60 * 60); // 3h avant
    t_2hAV = timeEnd.addSecs(-2 * 60 * 60); // 2h avant
    t_1hAV = timeEnd.addSecs(-1 * 60 * 60); //1 h avant
    t_50MinAV = timeEnd.addSecs(- 50 * 60); //50 min avant
    t_30minAV = timeEnd.addSecs(-30 * 60); // 30 min avant
    t_10minAV = timeEnd.addSecs(-10 * 60); // 10 min avant

    m_timeOccup = new QTimer(this);
    m_timeOccup->setInterval(5*60*1000); // 5 min
    connect(m_timeOccup, SIGNAL(timeout()), this, SLOT(signalerOccupTerminee()));

    m_timeReserv = new QTimer(this);
    m_timeReserv->setInterval(7*60*1000); // 7 min
    connect(m_timeReserv, SIGNAL(timeout()), this, SLOT(signalerReservATerme()));
}

void CompagnonFidele::afficherMsgApresFinLocation(int intervalle)
{
    QTime now = Horloge::currentTime();
    now.setHMS(now.hour(), now.minute(),0,0); // hh:mm:00

    int interSec = 0;
    if(m_occupations.count() == 1)
    {
        interSec += intervalle;

        int reste = (timeFinTol.hour() - now.hour()) * 60 + (timeFinTol.minute() - now.minute());
        QString msg1 = QObject::tr(MSG_APRES_OCCUP)
                       .arg(m_occupations.first().chambreOccupee())
                       .arg(reste);

        QDateTime date = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg1, date.addSecs(interSec));// planifier à interSec
    }else
    {
        int reste = (timeFinTol.hour() - now.hour()) * 60 + (timeFinTol.minute() - now.minute());
        QString msg = QObject::tr("Certaines chambres doivent être libérées avant %1 minutes. Ces chambres sont...")
                         .arg(reste);
        QDateTime date = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg, date.addSecs(interSec), 1000);// planifier à interSec

        for(int i = 0; i < m_occupations.count() - 1; i++)
        {
            interSec += intervalle;
            QString msg1 = tr("...%1,").arg(m_occupations.at(i).chambreOccupee());
            QDateTime date1 = Horloge::currentDateTime();
            m_pilote->planifierUneTache(msg1, date1.addSecs(interSec), 1000);
        }

        interSec += intervalle;
        QString msg2 = tr("et la chambre %1.").arg(m_occupations.last().chambreOccupee());
        QDateTime date2 = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg2, date2.addSecs(interSec), 3000);
    }
}

void CompagnonFidele::afficherMsgFinLocationDans1H(int intervalle)
{
    int interSec = 0;

    if(m_occupations.count() == 1)
    {
        interSec += intervalle;
        QString msg = QObject::tr(MSG_1H_AV_FIN_OCCUP).arg(m_occupations.at(0).chambreOccupee());
        QDateTime date = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg, date.addSecs(interSec));
    }else
    {
        interSec += intervalle;
        QString msg("La location de certaines chambres prend fin dans 1 heure. Ces chambres sont...");
        QDateTime date = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg, date.addSecs(interSec), 1000);

        for(int i = 0; i < m_occupations.count() - 1; i++)
        {
            interSec += intervalle;
            QString msg1 = tr("...%1,").arg(m_occupations.at(i).chambreOccupee());
            QDateTime date1 = Horloge::currentDateTime();
            m_pilote->planifierUneTache(msg1, date1.addSecs(interSec), 1000);
        }

        interSec += intervalle;
        QString msg2 = tr("et la chambre %1.").arg(m_occupations.last().chambreOccupee());
        QDateTime date2 = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg2, date2.addSecs(interSec), 3000);
    }
}

void CompagnonFidele::afficherMsgFinLocationDans30Min(int intervalle)
{
    int interSec = 0;

    if(m_occupations.count() == 1)
    {
        interSec += intervalle;
        QString msg = QObject::tr(MSG_30MIN_AV_FIN_OCCUP).arg(m_occupations.at(0).chambreOccupee());
        QDateTime date = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg, date.addSecs(interSec));
    }else
    {
        interSec += intervalle;
        QString msg("La location de certaines chambres prend fin dans 30 minutes. Ces chambres sont...");
        QDateTime date = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg, date.addSecs(interSec), 1000);

        for(int i = 0; i < m_occupations.count() - 1; i++)
        {
            interSec += intervalle;
            QString msg1 = tr("...%1,").arg(m_occupations.at(i).chambreOccupee());
            QDateTime date1 = Horloge::currentDateTime();
            m_pilote->planifierUneTache(msg1, date1.addSecs(interSec), 1000);
        }

        interSec += intervalle;
        QString msg2 = tr("et la chambre %1.").arg(m_occupations.last().chambreOccupee());
        QDateTime date2 = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg2, date2.addSecs(interSec), 3000);
    }
}

void CompagnonFidele::afficherMsgFinLocationDans10Min(int intervalle)
{
    int interSec = 0;

    if(m_occupations.count() == 1)
    {
        interSec += intervalle;
        QString msg = QObject::tr(MSG_10MIN_AV_FIN_OCCUP).arg(m_occupations.at(0).chambreOccupee());
        QDateTime date = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg, date.addSecs(interSec));
    }else
    {
        interSec += intervalle;
        QString msg("La location de certaines chambres prend fin dans 10 minutes. Ces chambres sont...");
        QDateTime date = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg, date.addSecs(interSec), 1000);

        for(int i = 0; i < m_occupations.count() - 1; i++)
        {
            interSec += intervalle;
            QString msg1 = tr("...%1,").arg(m_occupations.at(i).chambreOccupee());
            QDateTime date1 = Horloge::currentDateTime();
            m_pilote->planifierUneTache(msg1, date1.addSecs(interSec), 1000);
        }

        interSec += intervalle;
        QString msg2 = tr("et la chambre %1.").arg(m_occupations.last().chambreOccupee());
        QDateTime date2 = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg2, date2.addSecs(interSec), 3000);
    }
}

void CompagnonFidele::afficherMsgLocationFinie(int intervalle)
{
    int interSec = 0;

    if(m_occupations.count() == 1)
    {
        interSec += intervalle;
        QString msg = QObject::tr(MSG_FIN_OCCUP).arg(m_occupations.at(0).chambreOccupee());
        QDateTime date = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg, date.addSecs(interSec));
    }else
    {
        interSec += intervalle;
        QString msg("La location de certaines chambres prend fin. Ces chambres sont...");
        QDateTime date = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg, date.addSecs(interSec), 1000);

        for(int i = 0; i < m_occupations.count() - 1; i++)
        {
            interSec += intervalle;
            QString msg1 = tr("...%1,").arg(m_occupations.at(i).chambreOccupee());
            QDateTime date1 = Horloge::currentDateTime();
            m_pilote->planifierUneTache(msg1, date1.addSecs(interSec), 1000);
        }

        interSec += intervalle;
        QString msg2 = tr("et la chambre %1.").arg(m_occupations.last().chambreOccupee());
        QDateTime date2 = Horloge::currentDateTime();
        m_pilote->planifierUneTache(msg2, date2.addSecs(interSec), 3000);
    }
}

void CompagnonFidele::afficherMsgRTDans3h(int intervalle)
{
//    if(m_reservations.count() == 1)
//    {
//        int interSec = 0;
//        for(int i = 0; i < m_reservations.count(); i++)
//        {
//            interSec += intervalle;
//            QString msg = QObject::tr(MSG_3H_AV_RESERV_A_TERME).arg(m_reservations.at(i).chambreReservee());
//            QDateTime date = Horloge::currentDateTime();
//            m_pilote->planifierUneTache(msg, date.addSecs(interSec));
//        }
//    }else
//    {
//        int interSec = 0;
//        interSec += intervalle;
//        QString msg = QObject::tr("Certaines chambres reservées doivent être occupées dans 3 heures. Ces chambres sont...");
//        QDateTime date = Horloge::currentDateTime();
//        m_pilote->planifierUneTache(msg, date.addSecs(interSec), 1000);
//
//        for(int i = 0; i < m_reservations.count() - 1; i++)
//        {
//            interSec += intervalle;
//            QString msg1 = tr("...%1,").arg(m_reservations.at(i).chambreReservee());
//            QDateTime date1 = Horloge::currentDateTime();
//            m_pilote->planifierUneTache(msg1, date1.addSecs(interSec), 1000);
//        }
//
//        interSec += intervalle;
//        QString msg2 = tr("et la chambre %1.").arg(m_reservations.last().chambreReservee());
//        QDateTime date2 = Horloge::currentDateTime();
//        m_pilote->planifierUneTache(msg2, date2.addSecs(interSec), 3000);
//    }
}

void CompagnonFidele::afficherMsgRTDans2h(int intervalle)
{
//    if(m_reservations.count() == 1)
//    {
//        int interSec = 0;
//        for(int i = 0; i < m_reservations.count(); i++)
//        {
//            interSec += intervalle;
//            QString msg = QObject::tr(MSG_2H_AV_RESERV_A_TERME).arg(m_reservations.at(i).chambreReservee());
//            QDateTime date = Horloge::currentDateTime();
//            m_pilote->planifierUneTache(msg, date.addSecs(interSec));
//        }
//    }else
//    {
//        int interSec = 0;
//        interSec += intervalle;
//        QString msg = QObject::tr("Certaines chambres reservées doivent être occupées dans 2 heures. Ces chambres sont...");
//        QDateTime date = Horloge::currentDateTime();
//        m_pilote->planifierUneTache(msg, date.addSecs(interSec), 1000);
//
//        for(int i = 0; i < m_reservations.count() - 1; i++)
//        {
//            interSec += intervalle;
//            QString msg1 = tr("...%1,").arg(m_reservations.at(i).chambreReservee());
//            QDateTime date1 = Horloge::currentDateTime();
//            m_pilote->planifierUneTache(msg1, date1.addSecs(interSec), 1000);
//        }
//
//        interSec += intervalle;
//        QString msg2 = tr("et la chambre %1.").arg(m_reservations.last().chambreReservee());
//        QDateTime date2 = Horloge::currentDateTime();
//        m_pilote->planifierUneTache(msg2, date2.addSecs(interSec), 3000);
//    }
}

void CompagnonFidele::afficherMsgRTDans50Min(int intervalle)
{
//    if(m_reservations.count() == 1)
//    {
//        int interSec = 0;
//        for(int i = 0; i < m_reservations.count(); i++)
//        {
//            interSec += intervalle;
//            QString msg = QObject::tr(MSG_50Min_AV_RESERV_A_TERME).arg(m_reservations.at(i).chambreReservee());
//            QDateTime date = Horloge::currentDateTime();
//            m_pilote->planifierUneTache(msg, date.addSecs(interSec));
//        }
//    }else
//    {
//        int interSec = 0;
//        interSec += intervalle;
//        QString msg = QObject::tr("Certaines chambres reservées doivent être occupées dans 50 minutes. Ces chambres sont...");
//        QDateTime date = Horloge::currentDateTime();
//        m_pilote->planifierUneTache(msg, date.addSecs(interSec), 1000);
//
//        for(int i = 0; i < m_reservations.count() - 1; i++)
//        {
//            interSec += intervalle;
//            QString msg1 = tr("...%1,").arg(m_reservations.at(i).chambreReservee());
//            QDateTime date1 = Horloge::currentDateTime();
//            m_pilote->planifierUneTache(msg1, date1.addSecs(interSec), 1000);
//        }
//
//        interSec += intervalle;
//        QString msg2 = tr("et la chambre %1.").arg(m_reservations.last().chambreReservee());
//        QDateTime date2 = Horloge::currentDateTime();
//        m_pilote->planifierUneTache(msg2, date2.addSecs(interSec), 3000);
//    }
}

void CompagnonFidele::afficherMsgApresRT(int intervalle)
{
//    QTime now = Horloge::currentTime();
//    now.setHMS(now.hour(), now.minute(),0,0); // hh:mm:00
//
//    int interSec = 0;
//    if(m_reservations.count() == 1)
//    {
//        interSec += intervalle;
//
//        int reste = (timeFinTol.hour() - now.hour()) * 60 + (timeFinTol.minute() - now.minute());
//        QString msg1 = QObject::tr(MSG_RESERV1_ANNULEE)
//                       .arg(m_reservations.first().chambreReservee())
//                       .arg(reste);
//
//        QDateTime date = Horloge::currentDateTime();
//        m_pilote->planifierUneTache(msg1, date.addSecs(interSec));// planifier à interSec
//    }else
//    {
//        int reste = (timeFinTol.hour() - now.hour()) * 60 + (timeFinTol.minute() - now.minute());
//        QString msg = QObject::tr("Certaines chambres doivent être libérées avant %1 minutes. Ces chambres sont...")
//                         .arg(reste);
//        QDateTime date = Horloge::currentDateTime();
//        m_pilote->planifierUneTache(msg, date.addSecs(interSec), 1000);// planifier à interSec
//
//        for(int i = 0; i < m_reservations.count() - 1; i++)
//        {
//            interSec += intervalle;
//            QString msg1 = tr("...%1,").arg(m_reservations.at(i).chambreReservee());
//            QDateTime date1 = Horloge::currentDateTime();
//            m_pilote->planifierUneTache(msg1, date1.addSecs(interSec), 1000);
//        }
//
//        interSec += intervalle;
//        QString msg2 = tr("et la chambre %1.").arg(m_reservations.last().chambreReservee());
//        QDateTime date2 = Horloge::currentDateTime();
//        m_pilote->planifierUneTache(msg2, date2.addSecs(interSec), 3000);
//    }
}

void CompagnonFidele::verifierReservEnCours(QTime now)
{
    if(m_reservations.isEmpty()) // pour être en phase avec la base de données
        return;

    int intervalle = 2; // 2 secondes d'intervalle

    if(now == t_3hAV)
        // 3 heures avant
    {
        afficherMsgRTDans3h(intervalle);
        return;
    }

    if(now == t_2hAV)
        // 2 heures avant
    {
        afficherMsgRTDans2h(intervalle);
        return;
    }

    if(now == t_50MinAV)
        // 50 min avant
    {
        afficherMsgRTDans50Min(intervalle);
        return;
    }

    // ici la date est passée
    if((timeEnd < now) && (Horloge::currentTime().minute()%5 == 0)) // chaque 5 minutes
    {
        signalerReservATerme();
    }
}

void CompagnonFidele::signalerReservATerme()
{
    if(m_reservations.isEmpty())
        return;

//    int intervalle = 2; // s
//
//    // signaler
//    int interSec = 0;
//    for(int i = 0; i < m_reservations.count(); i++)
//    {
//        interSec += intervalle;
//
//        QString periode;
//        QDate datet = m_reservations.at(i).datedEntree().date();
//        if(Horloge::currentDate() == datet)
//        {
//            periode = "aujourd'hui";
//        }else
//        {
//            if(Horloge::currentDate().addDays(-1) == datet)
//            {
//                periode = "hier";
//            }else
//            {
//                periode = QString("le " + datet.toString(Qt::SystemLocaleLongDate));
//            }
//
//        }
//
//        QString msg1 = QObject::tr(MSG_APRES_RESERV)
//                       .arg(m_reservations.at(i).chambreReservee())
//                       .arg(periode);
//
//        QDateTime date = Horloge::currentDateTime();
//        m_pilote->planifierUneTache(msg1, date.addSecs(interSec));
//    }
}

void CompagnonFidele::ecrireDansHistoriqueMsgs()
{
    QString date = Horloge::currentDateTime().toString(Qt::SystemLocaleLongDate);
    QTextEdit text(date);
    QFont font(text.font());
    font.setBold(true);
    text.setFont(font);

    m_historiqueDesMsgs->append(tr("%1 - %2 \n").arg(text.toPlainText())
                                             .arg(m_pilote->derMsgAffiche()));
}

void CompagnonFidele::avertirTempsDeTolDepasse()
{
    if((Horloge::currentTime() > timeFinTol) && (!m_occupations.isEmpty() || !m_reservations.isEmpty()))
    {
        emit tempsToleranceDepasse(); // chaque une minute
    }
}

void CompagnonFidele::afficherMsgChambresLiberees(int nb)
{
    QString msg;
    if(nb == 1)
        msg = tr(MSG_OCCUP1_ARRETEE);
    else
        msg = tr(MSG_OCCUPN_ARRETEE).arg(nb);

    m_pilote->planifierUneTache(msg);
}

void CompagnonFidele::afficherMsgReservAnnulees(int nb)
{
    QString msg;
    if(nb == 1)
        msg = tr(MSG_RESERV1_ANNULEE);
    else
        msg = tr(MSG_RESERVN_ANNULEE).arg(nb);

    m_pilote->planifierUneTache(msg);
}

void CompagnonFidele::afficherMsgOccupationsReconduites(int nb)
{
    QString msg;
    if(nb == 1)
        msg = tr(MSG_OCCUP1_REC);
    else
        msg = tr(MSG_OCCUPN_REC).arg(nb);

    m_pilote->planifierUneTache(msg);
}

void CompagnonFidele::afficherMsgReservEffectues(int nb)
{
    QString msg;
    if(nb == 1)
        msg = tr(MSG_RESERV1_EFFECTUEE);
    else
        msg = tr(MSG_RESERVN_EFFECTUEE).arg(nb);

    m_pilote->planifierUneTache(msg);
}

