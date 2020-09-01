#ifndef COMPAGNONFIDELE_H
#define COMPAGNONFIDELE_H

#include "libCpgFdl_global.h"

#include "PiloteCompagnonFidele.h"
#include "occupation.h"
#include "reservation.h"
#include "agent.h"
#include "client.h"
#include "HeureLimite.h"
#include "horloge.h"
#include "chambreReservee.h"

#define DUREE_VERIF 60000 // 1 min
#define HEURE_DE_SORTIE 12 // heure
#define MINUTE_DE_SORTIE 0
#define HEURE_DE_ENTREE 12 // heure
#define MINUTE_DE_ENTREE 0
#define HEURE_DE_TOLERANCE 1 // heure
#define MINUTE_DE_TOLERANCE 0

#define MSG_1H_AV_FIN_OCCUP "La location de la chambre %1 prend fin dans 1 heure."
#define MSG_30MIN_AV_FIN_OCCUP "La location de la chambre %1 prend fin dans 30 minutes."
#define MSG_10MIN_AV_FIN_OCCUP "La location de la chambre %1 prend fin dans 10 minutes."
#define MSG_FIN_OCCUP "La location de la chambre %1 prend fin."
#define MSG_APRES_OCCUP "La chambre %1 doit être libérée au plutard dans %2 minutes."
#define MSG_OCCUP1_ARRETEE "Une chambre vient d'être libérée."
#define MSG_OCCUPN_ARRETEE "%1 chambres viennent d'être libérées."
#define MSG_OCCUP1_REC "Une location vient d'être reconduite."
#define MSG_OCCUPN_REC "%1 locations viennent d'être reconduites."
#define MSG_3H_AV_RESERV_A_TERME "La chambre %1 sera occupée dans environ 3 heures."
#define MSG_2H_AV_RESERV_A_TERME "La chambre %1 sera occupée dans environ 2 heures."
#define MSG_50Min_AV_RESERV_A_TERME "La chambre %1 sera occupée dans environ 50 minutes."
#define MSG_APRES_RESERV "La chambre %1, réservée pour %2, n'est pas encore occupée."
#define MSG_RESERV1_ANNULEE "Une réservation a été annulée."
#define MSG_RESERVN_ANNULEE "%1 réservations ont été annulées."
#define MSG_RESERV1_EFFECTUEE "Une location vient d'être effectuée."
#define MSG_RESERVN_EFFECTUEE "%1 locations viennent d'être effectuées."

class LIBCPGFDLSHARED_EXPORT CompagnonFidele : public QObject
{
    Q_OBJECT

public:
    CompagnonFidele(QGraphicsScene * scene, agent * r, QTextEdit * historique, Horloge * h, QString path);
    ~CompagnonFidele();

    void setMuteVolume(bool mute);
    inline bool volumeMuted()const{return m_pilote->volumeMuted();};
    QTime timeFinTolerance()const{return timeFinTol;};

signals:
    void etatChambreModifie();
    void tempsToleranceDepasse();

public slots:
    void chargerInfos();

private:
    QList<occupation> m_occupations;
    QList<chambreReservee> m_reservations;
    PiloteCompagnonFidele * m_pilote;
    agent * m_recepteur;
    QTextEdit * m_historiqueDesMsgs;
    QTimer * m_timeOccup;
    QTimer * m_timeReserv;
    bool m_timeReservATermeEnCours;
    bool m_timeOccupTermineeEnCours;
    Horloge * m_horloge;
    QString m_chemin;

    QTime t_3hAV; // 3h avant
    QTime t_2hAV; // 2h avant
    QTime t_1hAV; //1 h avant
    QTime t_50MinAV; // 50 min avant
    QTime t_30minAV; // 30 min avant
    QTime t_10minAV; // 10 min avant
    QTime timeEnd; // temps de sortie
    QTime timeFinTol; // temps fin tolérance

    void initialiserTimes();
    void afficherMsgLocationFinie(int intervalle);
    void afficherMsgFinLocationDans10Min(int intervalle);
    void afficherMsgFinLocationDans30Min(int intervalle);
    void afficherMsgFinLocationDans1H(int intervalle);
    void afficherMsgApresFinLocation(int intervalle);

    void afficherMsgRTDans3h(int intervalle);
    void afficherMsgRTDans2h(int intervalle);
    void afficherMsgRTDans50Min(int intervalle);
    void afficherMsgApresRT(int intervalle);

private slots:
    void afficherMsgChambresLiberees(int nb);
    void afficherMsgReservAnnulees(int nb);
    void afficherMsgOccupationsReconduites(int nb);
    void afficherMsgReservEffectues(int nb);
    void ecrireDansHistoriqueMsgs();
    void verifierFinOccupation(QTime now);
    void signalerOccupTerminee();
    void verifierReservEnCours(QTime now);
    void signalerReservATerme();
    void programmerVerif();
    void avertirTempsDeTolDepasse();

};

#endif // COMPAGNONFIDELE_H
