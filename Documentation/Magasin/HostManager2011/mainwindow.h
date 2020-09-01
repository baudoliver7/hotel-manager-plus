#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* classses de qt */
#include <QMainWindow>
#include <QCloseEvent>
#include <QMdiSubWindow>

/* classes personnalisées */
#include "bdd.h"
#include "recepteur.h"
#include "service.h"
#include "DialogConnexion.h"
#include "MdiServiceReception.h"
#include "DialogRechercherUnClient.h"
#include "DgRechercherUneOccupation.h"
#include "DgRechercherUneReserv.h"



namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool seConnecterALaBDGestionDeLaClientele();

signals:
    void remplirOccuper(client cl);
    void remplirReserver(client cl);

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    BDD * m_gestionClientele;
    recepteur * m_utilisateur;
    service * m_service;
    MdiServiceReception * m_mdiServiceReception;

private:
    void setEnableActionsCompteRecepteur(bool enabled);
    void setWindowTitlePlusEtatConnexion(bool connecte);
    void afficherUneNouvelleMdiServiceReception();
    bool seConnecterAuServiceReception();
    MdiServiceReception *  activeMdiServiceReception();

private slots:
    void on_actionActiver_son_de_compagnon_triggered(bool checked);
    void on_actionRechercherUneReservation_triggered();
    void on_actionRechercherUneOccupation_triggered();
    void on_actionRechercherUnClient_triggered();
    void on_actionSeDeconnecter_triggered();
    void on_actionSeConnecter_triggered();
    void on_actionQuitter_triggered();
    void fermerMdiServiceReception();
    void etablirEtat_Deconnection();
    void etablirEtat_Connection();
    void rechercherUnClient();
};

#endif // MAINWINDOW_H
