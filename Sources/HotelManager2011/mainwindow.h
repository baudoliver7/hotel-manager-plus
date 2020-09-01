#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* classses de qt */
#include <QMainWindow>
#include <QCloseEvent>
#include <QMdiSubWindow>
#include <QSplashScreen>

/* classes personnalisées */
#include "bdd.h"
#include "DialogConnexion.h"
#include "DialogRechercherUnClient.h"
#include "DgRechercherUneOccupation.h"
#include "DgRechercherUneReserv.h"
#include "BDActiverNvCpte.h"
#include "BDEditerCptAdmin.h"
#include "horloge.h"
#include "BDAjusterHeureSyst.h"
#include "BDApropos.h"
#include "MdiPlanning.h"
#include "BDCreerUnCompteClient.h"
#include "BDCreerUnGroupe.h"
#include "BDDebiterUnCompteClient.h"
#include "BDModifierUnGroupeClient.h"
#include "BDFacturerUnGroupe.h"
#include "BDRechercherUnGroupe.h"
#include "BDMessagerie.h"
#include "service.h"
#include "BDCardex.h"
#include "operation.h"
#include "BDWaiting.h"
#include "FormConnexion.h"
#include <QProgressDialog>
#include <QTimer>

#define TITLE "Hotel Manager %1 Plus [Version d'évaluation]- [Statut: %2]"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(BDD * db, Horloge * h, QSplashScreen * splash, QString path, int idService, QWidget *parent = 0);
    ~MainWindow();

    bool seConnecterALaBDGestionDeLaClientele();
    agent * utilisateur();

public slots:
    void lancerFenetre();

signals:
    void remplirOccuper(client cl);
    void remplirReserver(client cl);
    void groupeFacture(QList<occupation>);

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    BDD * m_gestionClientele;
    agent * m_utilisateur;
    Horloge * m_horloge;
    BDD * m_db;
    QSplashScreen * m_splash;
    QString m_chemin;
    serviceEntreprise * m_serviceEntreprise;
    BDMessagerie * m_bdMessagerie;
    bool m_connecte;
    service * m_service;
    BDWaiting * m_bdWaiting;
    bool m_fermer;

private:
    void setEnableActionsCompteRecepteur(bool enabled);
    void setWindowTitlePlusEtatConnexion(bool connecte);
    MdiPlanning * activeMdiPlanning();
    FormConnexion * activeMdiFormConnexion();
    void initialiserMessagerie();
    void initialiserService();
    void terminerService();
    void afficherDateDeConnection();
    void terminerMessagerie();

private slots:
    void warningDBState();
    void seConnecterAuService();
    void fermerFormConnexion();
    void afficherFormConnexion();
    void actualiserFenetre();
    void on_actionActualiser_la_fen_tre_triggered();
    void enregistrerTout();
    void on_actionEnregistrer_tout_triggered();
    void on_actionEditer_le_cardex_triggered();
    void on_actionRechercher_un_groupe_de_client_triggered();
    void deconnecter();
    void on_actionFacturer_un_groupe_de_client_triggered();
    void on_actionAjouter_un_client_un_groupe_triggered();
    void on_actionDebiterUnCompteClient_triggered();
    void on_actionCreer_Un_groupe_de_client_triggered();
    void on_actionCreer_Un_compte_client_triggered();
    void afficherHorloge();
    void updateActivitesAgent();
    void newMdiPlanningSimplifie();
    void newMdiPlanningComplet();
    void on_actionA_propos_de_hotel_manger_plus_triggered();
    void on_actionAjuster_Heure_Date_triggered();
    void on_actionEditer_votre_compte_triggered();
    void on_actionActiver_un_nouveau_compte_triggered();
    void on_actionActiver_son_de_compagnon_triggered(bool checked);
    void on_actionRechercherUneReservation_triggered();
    void on_actionRechercherUneOccupation_triggered();
    void on_actionRechercherUnClient_triggered();
    void on_actionSeDeconnecter_triggered();
    void updateHeureFin();
    void on_actionSeConnecter_triggered();
    void on_actionQuitter_triggered();
    void fermerPlanningSimplifie();
    void etablirEtat_Deconnection();
    void etablirEtat_Connection();
    void rechercherUnClient();
};

#endif // MAINWINDOW_H
