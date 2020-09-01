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


#define TITLE "Hotel Manager %1 Plus - [Statut: %2]"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(Horloge * h, QSplashScreen * splash, QString path, int idService, QWidget *parent = 0);
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
    bool m_connectReceptEnCours;
    agent * m_agent;
    bool m_fermer;
    Horloge * m_horloge;
    QSplashScreen * m_splash;
    QString m_chemin;
    serviceEntreprise * m_service;

    MdiService * activeMdiService();
    MdiService * newMdiService();

private slots:
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
