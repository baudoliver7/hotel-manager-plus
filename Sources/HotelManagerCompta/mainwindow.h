#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QCloseEvent>
#include <QSplashScreen>

#include "MdiServiceComptable.h"
#include "DialogConnexion.h"
#include "horloge.h"
#include "BDEditerCptAdmin.h"
#include "BDActiverNvCpte.h"
#include "BDApropos.h"
#include "BDConfigCpt.h"
#include "BDExecuterNlleOperation.h"
#include "BDConfigComptaService.h"
#include "BDCompteResultat.h"
#include "BDEditerClotures.h"
#include "FormConnexion.h"
#include "bdd.h"

#define TITLE "Hotel Manager Comptabilité Plus [Version d'évaluation]- [statut: %2]"

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
    Horloge * m_horloge;
    agent * m_comptable;
    MdiServiceComptable * m_mdi;
    QSplashScreen * m_splash;
    BDD * m_db;
    QString m_chemin;
    serviceEntreprise * m_service;

    void newMdiServiceComptable();
    MdiServiceComptable * activeMdiServiceComptable();
    void setEnabledEtatActions(bool ouvert);
    FormConnexion * activeMdiFormConnexion();

private slots:
    void warningDBState();
    void afficherFormConnexion();
    void fermerFormConnexion();
    void seConnecterAuService();
    void on_actionEditer_les_cl_tures_triggered();
    void on_actionD_terminer_le_compte_r_sultat_triggered();
    void on_actionMes_comptes_uniquement_triggered();
    void on_actionMes_comptes_en_arbre_triggered();
    void on_actionLa_comptabilit_des_services_triggered();
    void on_actionSupprimer_une_op_ration_triggered();
    void on_actionUne_operation_triggered();
    void on_actionConfigurer_les_comptes_triggered();
    void updateActivitesAgent();
    void on_actionAide_en_ligne_triggered();
    void on_actionEnvoyer_et_ou_recevoir_des_messages_triggered();
    void on_actionA_propos_de_Hotel_Manager_triggered();
    void on_actionActiver_un_nouveau_compte_triggered();
    void on_actionEditer_votre_compte_triggered();
    void fermerMdiServiceComptable();
    void on_actionSe_d_connecter_triggered();
    void on_actionSe_connecter_triggered();
    void on_actionQuitter_triggered();
};

#endif // MAINWINDOW_H
