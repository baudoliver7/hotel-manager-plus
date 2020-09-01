#ifndef MDIBILANACTIVITESRECEPTIONCEPTION_H
#define MDIBILANACTIVITESRECEPTIONCEPTION_H

#include <QWidget>
#include <QDate>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QCloseEvent>
#include <QPixmap>
#include <QTimer>

#include "DialogCalendar.h"
#include "agent.h"
#include "reservation.h"
#include "occupation.h"
#include "client.h"
#include "service.h"
#include "horloge.h"
#include "recevoirOccup.h"
#include "libererOccup.h"
#include "emettreReserv.h"
#include "effectuerReserv.h"
#include "MesTables.h"
#include "serviceEntreprise.h"
#include "chambreReservee.h"
#include "BDMessagerie.h"
#include "clotureService.h"
#include "BDDetailsRepas.h"
#include "factureRestoIndividu.h"
#include "BDDetailsCloture.h"
#include "BDWaiting.h"
#include "BDSetPeriode.h"

#define CLIENT_RV 0
#define DATE_DEM 1
#define DATE_OCCUP_RV 2
#define DUREE_OC_RV 3
#define CHAMBRE_RV 4
#define EXECUTEE 5

#define CLIENT_OC 0
#define DATE_OCCUP 1
#define FIN_OCCUP 2
#define DUREE_OC 3
#define CHAMBRE_OC 4

#define DEBUT_SER 0
#define DUREE_SER 2

#define TOUT_LES_RECEPTEURS "Tous les réceptionnistes"
#define IDRECEPTION 3
#define IDRESTAURATION 4

namespace Ui {
    class MdiBilanActivitesReception;
}

class MdiBilanActivitesReception : public QWidget {
    Q_OBJECT
public:
    MdiBilanActivitesReception(agent * ag, QString path, Horloge * horloge, serviceEntreprise * service, QDateTime dateDeConnection, QWidget *parent = 0);
    ~MdiBilanActivitesReception();

    void lancerLireMsg();
    BDMessagerie * bdMessagerie()const{return m_bdMessagerie;};

public slots:
    void actualiserOngletActif();

signals:
    void closed();
    void lireMsg();
    void rangerColumn(int column, int oldIndex, int newIndex);
    void debuterTraitement();
    void terminerTraitement();
    void updateProgressBar(int value);

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent * e);

private:
    Ui::MdiBilanActivitesReception *ui;
    QDate m_dateDebut;
    QDate m_dateFin;
    double m_chiffredAffaires;
    QString m_chemin;
    int m_nbAnomaliesLoc;
    Horloge * m_horloge;
    serviceEntreprise * m_service;
    BDMessagerie * m_bdMessagerie;
    double m_avances;
    agent * m_admin;
    QWidget * m_parent;
    QSqlTableModel * m_modelCloturesRecept;
    QSqlTableModel * m_modelCloturesResto;
    bool m_affichage;
    BDWaiting * m_bdWaiting;

    void initPeriode();
    void afficherPeriode(QDate debut, QDate fin);
    void initCloturesReception();
    void initCloturesRestauration();
    void chargerActivites(QString matricule);
    void chargerDureeActivites(QString matricule);
    void chargerDureeActivitesResto(QString matricule);
    void chargerActivitesReserv(QString matricule);
    void chargerActivitesOccup(QString matricule);
    void ajouterReservation(chambreReservee rv, bool effectuee);
    void ajouterOccupation(occupation oc);
    void ajouterEltReserv(int row, int column, QString valeur);
    void ajouterEltOccup(int row, int column, QString valeur, bool rouge = false);
    QString convertirAnMoisSemaineJour(int nbDeJours);
    QString convertirHeureMinute(int minute);
    void ajouterService(service s);
    void ajouterEltService(int row, int column, QString valeur);
    void rafraichirRecept();
    void rafraichirResto();
    void initialiserMessagerie();
    void afficherDateDeConnection(QDateTime date);
    void chargerActivitesResto(QString matricule);

private slots:
    void setPeriode();    
    void on_btn_detailsRecept_clicked();
    void on_btn_detailsResto_clicked();
    void on_btn_imprimerFacture_clicked();
    void on_btn_details_clicked();
    void rafraichir();
    void on_comboBoxRestaurataires_currentIndexChanged(QString );
    void afficherHorloge();
    void on_btn_lire_clicked();
    void on_btn_actualiser_clicked();
    void on_comboBoxRecepteur_currentIndexChanged(QString );
    void chargerRecepteurs();
    void chargerRestaurataires();
    void chargerCloturesReception(QString matricule);
    void chargerCloturesRestauration(QString matricule);
    void updateEtatBtnDetailsClotureRecept(QModelIndex);
    void updateEtatBtnDetailsClotureResto(QModelIndex);
    void updateEtatBtnDetailsConsoResto(QModelIndex);
};

#endif // MDIBILANACTIVITESRECEPTIONCEPTION_H
