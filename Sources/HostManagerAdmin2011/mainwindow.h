#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include "DialogConfigChambre.h"
#include "dialoggerercompterecepteur.h"
#include "BDEditerCptAdmin.h"
#include "MdiBilanActivitesReceptionception.h"
#include "DialogConnexion.h"
#include "agent.h"
#include "BDConfigHeureSortie.h"
#include "horloge.h"
#include "BDMessagerie.h"
#include "BDApropos.h"
#include "serviceEntreprise.h"
#include "BDActiverNvCpte.h"
#include "BDInfosHotels.h"
#include "BDConfigurerMenuResto.h"
#include <QCloseEvent>
#include <QTimer>
#include <QSplashScreen>
#include <QProgressBar>
#include "BDCardex.h"
#include "BDWaiting.h"
#include "FormConnexion.h"
#include "BDConfigTaux.h"
#include "bdd.h"
#include "MdiPlanning.h"

#define TITLE "Hotel Manager %1 Plus [Version d'évaluation]- [Statut: %2]"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(BDD * db, Horloge * h, QSplashScreen * splash, QString path, int idService, QWidget *parent = 0);
    ~MainWindow();

    agent * utilisateur();

public slots:
    void lancerFenetre();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    bool m_bilanEnCours;
    agent * m_admin;
    bool m_fermer;
    Horloge * m_horloge;
    QSplashScreen * m_splash;
    QString m_chemin;
    serviceEntreprise * m_service;
    QProgressBar * m_progressBar;
    BDWaiting * m_bdWaiting;
    FormConnexion * activeMdiFormConnexion();
    QDateTime m_dateDeConnection;
    BDD * m_db;


    void initialiserProgressBar();
    MdiBilanActivitesReception * mdiBilanActivitesReceptionEnCours();
    MdiPlanning * mdiPlanningEnCours();
    QMdiSubWindow * windowOfMdiBilanActivitesReceptionEnCours();
    QMdiSubWindow * windowOfMdiPlanningEnCours();

private slots:    
    void actualiserFenetre();
    void on_actionActualiser_triggered();
    void on_actionLa_r_ception_triggered();
    void warningDBState();
    void on_actionConfigurer_taux_des_taxes_triggered();
    void seConnecterAuService();
    void fermerFormConnexion();
    void afficherFormConnexion();
    void configurerChambres();
    void on_actionVisualiser_le_cardex_triggered();
    void debuterProgressBar();
    void terminerProgressBar();
    void updateProgressBar();
    void on_actionConfigurer_le_menu_du_restaurant_triggered();
    void on_actionRenseigner_les_informations_sur_votre_h_tel_triggered();
    void on_actionActiver_son_compte_triggered();
    void updateActivitesAgent();
    void updateEtatsActions(bool connecte);
    void on_actionA_propos_de_Hotel_Manager_Plus_triggered();
    void on_actionConfigurer_heures_de_sortie_triggered();
    void on_actionSe_d_connecter_triggered();
    void on_actionSe_connecter_triggered();
    void closeBilan();
    void on_actionBilanActivitesReception_triggered();
    void on_actionChanger_password_triggered();
    void on_actionGererDesComptesRecepteur_triggered();
    void on_actionConfigurer_les_chambres_triggered();
    void on_actionQuitter_triggered();
    void nouveauCompteAdmin();
};

#endif // MAINWINDOW_H
