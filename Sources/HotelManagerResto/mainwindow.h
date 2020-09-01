#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// classes de qt
#include <QMainWindow>
#include <QCloseEvent>
#include <QTimer>
#include <QSplashScreen>
#include <QMdiSubWindow>

// classes personnalisées
#include "BDEditerCptAdmin.h"
#include "DialogConnexion.h"
#include "agent.h"
#include "horloge.h"
#include "BDMessagerie.h"
#include "BDApropos.h"
#include "serviceEntreprise.h"
#include "BDActiverNvCpte.h"
#include "MdiService.h"
#include "BDReglerFacture.h"
#include "BDCreerUnCompteClient.h"
#include "BDDebiterUnCompteClient.h"
#include "service.h"
#include "BDConfigurerTableResto.h"
#include "BDConfigurerModule.h"
#include "FormConnexion.h"

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

signals:
    void actualiserMdi();
    void actualiserTables();
    void actualiserCategories(bool bar);

public slots:
    void lancerFenetre();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    BDD * m_db;
    bool m_bilanEnCours;
    bool m_connectReceptEnCours;
    agent * m_agent;
    bool m_fermer;
    Horloge * m_horloge;
    QSplashScreen * m_splash;
    QString m_chemin;
    service * m_heuresConnections;
    serviceEntreprise * m_service;
    BDMessagerie * m_bdMessagerie;

    MdiService * activeMdiService();
    MdiService * newMdiService();
    void initialiserMessagerie();
    void terminerMessagerie();
    void initialiserService();
    void terminerService();
    void afficherDateDeConnection();
    FormConnexion * activeMdiFormConnexion();

private slots:
    void warningDBState();
    void afficherFormConnexion();
    void fermerFormConnexion();
    void seConnecterAuService();
    void on_actionConfigurer_mon_module_triggered();
    void on_actionConfigurer_mes_tables_triggered();
    void updateHeureFin();
    void on_actionD_biter_un_compte_client_triggered();
    void on_actionCr_er_un_compte_client_triggered();
    void deconnecter();
    void on_actionFacture_non_pay_triggered();
    void afficherHorloge();
    void fermerMdiService();
    void on_actionActiver_son_compte_triggered();
    void updateActivitesAgent();
    void updateEtatsActions(bool connecte);
    void on_actionA_propos_de_Hotel_Manager_Plus_triggered();
    void on_actionSe_d_connecter_triggered();
    void on_actionSe_connecter_triggered();
    void on_actionChanger_password_triggered();
    void on_actionQuitter_triggered();
};

#endif // MAINWINDOW_H
