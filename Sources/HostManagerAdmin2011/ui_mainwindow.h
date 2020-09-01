/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 25. Oct 17:20:29 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QAction *actionChanger_password;
    QAction *actionConfigurer_les_chambres;
    QAction *actionGererDesComptesRecepteur;
    QAction *actionBilanActivitesReception;
    QAction *actionAjusterDateHeure;
    QAction *actionSe_connecter_au_service_R_ception;
    QAction *actionSe_connecter;
    QAction *actionSe_d_connecter;
    QAction *actionConfigurer_type_de_client;
    QAction *actionActiver_son_compte;
    QAction *actionConfigurer_heures_de_sortie;
    QAction *actionEcrire_et_recevoir_des_messages;
    QAction *actionAide_en_ligne;
    QAction *actionA_propos_de_Hotel_Manager_Plus;
    QAction *actionObserver_la_tr_sorerie;
    QAction *actionHistorique_des_bilans_journaliers;
    QAction *actionInformations_g_n_rales;
    QAction *actionRenseigner_les_informations_sur_votre_h_tel;
    QAction *actionConfigurer_le_menu_du_restaurant;
    QAction *actionVisualiser_le_cardex;
    QAction *actionConfigurer_taux_des_taxes;
    QAction *actionLa_r_ception;
    QAction *actionActualiser;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEditer;
    QMenu *menuParam_tres;
    QMenu *menuAide;
    QMenu *menuVisualiser;
    QMenu *menuAffichage;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(683, 474);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo_a.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionChanger_password = new QAction(MainWindow);
        actionChanger_password->setObjectName(QString::fromUtf8("actionChanger_password"));
        actionConfigurer_les_chambres = new QAction(MainWindow);
        actionConfigurer_les_chambres->setObjectName(QString::fromUtf8("actionConfigurer_les_chambres"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/config_ch.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigurer_les_chambres->setIcon(icon1);
        actionGererDesComptesRecepteur = new QAction(MainWindow);
        actionGererDesComptesRecepteur->setObjectName(QString::fromUtf8("actionGererDesComptesRecepteur"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/gerer_compte.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGererDesComptesRecepteur->setIcon(icon2);
        actionBilanActivitesReception = new QAction(MainWindow);
        actionBilanActivitesReception->setObjectName(QString::fromUtf8("actionBilanActivitesReception"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/bilan_activites.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBilanActivitesReception->setIcon(icon3);
        actionAjusterDateHeure = new QAction(MainWindow);
        actionAjusterDateHeure->setObjectName(QString::fromUtf8("actionAjusterDateHeure"));
        actionSe_connecter_au_service_R_ception = new QAction(MainWindow);
        actionSe_connecter_au_service_R_ception->setObjectName(QString::fromUtf8("actionSe_connecter_au_service_R_ception"));
        actionSe_connecter = new QAction(MainWindow);
        actionSe_connecter->setObjectName(QString::fromUtf8("actionSe_connecter"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/connecter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSe_connecter->setIcon(icon4);
        actionSe_d_connecter = new QAction(MainWindow);
        actionSe_d_connecter->setObjectName(QString::fromUtf8("actionSe_d_connecter"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/d\303\251connecter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSe_d_connecter->setIcon(icon5);
        actionConfigurer_type_de_client = new QAction(MainWindow);
        actionConfigurer_type_de_client->setObjectName(QString::fromUtf8("actionConfigurer_type_de_client"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/config_type_client.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigurer_type_de_client->setIcon(icon6);
        actionActiver_son_compte = new QAction(MainWindow);
        actionActiver_son_compte->setObjectName(QString::fromUtf8("actionActiver_son_compte"));
        actionConfigurer_heures_de_sortie = new QAction(MainWindow);
        actionConfigurer_heures_de_sortie->setObjectName(QString::fromUtf8("actionConfigurer_heures_de_sortie"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/regler_heure.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigurer_heures_de_sortie->setIcon(icon7);
        actionEcrire_et_recevoir_des_messages = new QAction(MainWindow);
        actionEcrire_et_recevoir_des_messages->setObjectName(QString::fromUtf8("actionEcrire_et_recevoir_des_messages"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/msgs2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEcrire_et_recevoir_des_messages->setIcon(icon8);
        actionAide_en_ligne = new QAction(MainWindow);
        actionAide_en_ligne->setObjectName(QString::fromUtf8("actionAide_en_ligne"));
        actionA_propos_de_Hotel_Manager_Plus = new QAction(MainWindow);
        actionA_propos_de_Hotel_Manager_Plus->setObjectName(QString::fromUtf8("actionA_propos_de_Hotel_Manager_Plus"));
        actionObserver_la_tr_sorerie = new QAction(MainWindow);
        actionObserver_la_tr_sorerie->setObjectName(QString::fromUtf8("actionObserver_la_tr_sorerie"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/etat_caisse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionObserver_la_tr_sorerie->setIcon(icon9);
        actionHistorique_des_bilans_journaliers = new QAction(MainWindow);
        actionHistorique_des_bilans_journaliers->setObjectName(QString::fromUtf8("actionHistorique_des_bilans_journaliers"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/historique_bilan.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHistorique_des_bilans_journaliers->setIcon(icon10);
        actionInformations_g_n_rales = new QAction(MainWindow);
        actionInformations_g_n_rales->setObjectName(QString::fromUtf8("actionInformations_g_n_rales"));
        actionRenseigner_les_informations_sur_votre_h_tel = new QAction(MainWindow);
        actionRenseigner_les_informations_sur_votre_h_tel->setObjectName(QString::fromUtf8("actionRenseigner_les_informations_sur_votre_h_tel"));
        actionConfigurer_le_menu_du_restaurant = new QAction(MainWindow);
        actionConfigurer_le_menu_du_restaurant->setObjectName(QString::fromUtf8("actionConfigurer_le_menu_du_restaurant"));
        actionVisualiser_le_cardex = new QAction(MainWindow);
        actionVisualiser_le_cardex->setObjectName(QString::fromUtf8("actionVisualiser_le_cardex"));
        actionConfigurer_taux_des_taxes = new QAction(MainWindow);
        actionConfigurer_taux_des_taxes->setObjectName(QString::fromUtf8("actionConfigurer_taux_des_taxes"));
        actionLa_r_ception = new QAction(MainWindow);
        actionLa_r_ception->setObjectName(QString::fromUtf8("actionLa_r_ception"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/booking_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLa_r_ception->setIcon(icon11);
        actionActualiser = new QAction(MainWindow);
        actionActualiser->setObjectName(QString::fromUtf8("actionActualiser"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/actualiser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionActualiser->setIcon(icon12);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 683, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEditer = new QMenu(menuBar);
        menuEditer->setObjectName(QString::fromUtf8("menuEditer"));
        menuParam_tres = new QMenu(menuBar);
        menuParam_tres->setObjectName(QString::fromUtf8("menuParam_tres"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        menuVisualiser = new QMenu(menuBar);
        menuVisualiser->setObjectName(QString::fromUtf8("menuVisualiser"));
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setIconSize(QSize(32, 32));
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEditer->menuAction());
        menuBar->addAction(menuVisualiser->menuAction());
        menuBar->addAction(menuParam_tres->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionSe_connecter);
        menuFichier->addAction(actionSe_d_connecter);
        menuFichier->addAction(actionActiver_son_compte);
        menuFichier->addSeparator();
        menuFichier->addAction(actionBilanActivitesReception);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuEditer->addAction(actionChanger_password);
        menuEditer->addSeparator();
        menuEditer->addAction(actionVisualiser_le_cardex);
        menuParam_tres->addAction(actionConfigurer_les_chambres);
        menuParam_tres->addAction(actionConfigurer_le_menu_du_restaurant);
        menuParam_tres->addAction(actionGererDesComptesRecepteur);
        menuParam_tres->addAction(actionConfigurer_heures_de_sortie);
        menuParam_tres->addAction(actionConfigurer_taux_des_taxes);
        menuParam_tres->addAction(actionAjusterDateHeure);
        menuParam_tres->addAction(actionRenseigner_les_informations_sur_votre_h_tel);
        menuAide->addAction(actionAide_en_ligne);
        menuAide->addSeparator();
        menuAide->addAction(actionA_propos_de_Hotel_Manager_Plus);
        menuVisualiser->addAction(actionLa_r_ception);
        menuAffichage->addAction(actionActualiser);
        mainToolBar->addAction(actionSe_connecter);
        mainToolBar->addAction(actionSe_d_connecter);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionActualiser);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBilanActivitesReception);
        mainToolBar->addAction(actionLa_r_ception);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionConfigurer_les_chambres);
        mainToolBar->addAction(actionGererDesComptesRecepteur);
        mainToolBar->addAction(actionConfigurer_heures_de_sortie);
        mainToolBar->addAction(actionEcrire_et_recevoir_des_messages);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Hotel Manager Admin 2011 [bienvenue au service administration]", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionChanger_password->setText(QApplication::translate("MainWindow", "Editer votre compte...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionChanger_password->setToolTip(QApplication::translate("MainWindow", "Changer le mot de passe du compte administrateur en cours", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionConfigurer_les_chambres->setText(QApplication::translate("MainWindow", "Configurer les chambres et les profiles client", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionConfigurer_les_chambres->setToolTip(QApplication::translate("MainWindow", "Configurer les chambres", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionGererDesComptesRecepteur->setText(QApplication::translate("MainWindow", "G\303\251rer les comptes...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionGererDesComptesRecepteur->setToolTip(QApplication::translate("MainWindow", "G\303\251rer les comptes r\303\251cepteur", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionBilanActivitesReception->setText(QApplication::translate("MainWindow", "Bilan des activit\303\251s de la r\303\251ception", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBilanActivitesReception->setToolTip(QApplication::translate("MainWindow", "Bilan des activit\303\251s de la r\303\251ception", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAjusterDateHeure->setText(QApplication::translate("MainWindow", "Ajuster Date/Heure...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAjusterDateHeure->setToolTip(QApplication::translate("MainWindow", "Ajuster la date et l'heure du syst\303\250me", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSe_connecter_au_service_R_ception->setText(QApplication::translate("MainWindow", "Se connecter au service R\303\251ception", 0, QApplication::UnicodeUTF8));
        actionSe_connecter->setText(QApplication::translate("MainWindow", "Se connecter", 0, QApplication::UnicodeUTF8));
        actionSe_d_connecter->setText(QApplication::translate("MainWindow", "Se d\303\251connecter", 0, QApplication::UnicodeUTF8));
        actionConfigurer_type_de_client->setText(QApplication::translate("MainWindow", "Configurer les types de client...", 0, QApplication::UnicodeUTF8));
        actionActiver_son_compte->setText(QApplication::translate("MainWindow", "Activer un nouveau compte...", 0, QApplication::UnicodeUTF8));
        actionConfigurer_heures_de_sortie->setText(QApplication::translate("MainWindow", "Configurer heures limites...", 0, QApplication::UnicodeUTF8));
        actionEcrire_et_recevoir_des_messages->setText(QApplication::translate("MainWindow", "Envoyer et/ou recevoir des messages", 0, QApplication::UnicodeUTF8));
        actionAide_en_ligne->setText(QApplication::translate("MainWindow", "Aide en ligne", 0, QApplication::UnicodeUTF8));
        actionA_propos_de_Hotel_Manager_Plus->setText(QApplication::translate("MainWindow", "A propos de Hotel Manager Plus...", 0, QApplication::UnicodeUTF8));
        actionObserver_la_tr_sorerie->setText(QApplication::translate("MainWindow", "Etat de la tr\303\251sorerie", 0, QApplication::UnicodeUTF8));
        actionHistorique_des_bilans_journaliers->setText(QApplication::translate("MainWindow", "Historique des bilans journaliers", 0, QApplication::UnicodeUTF8));
        actionInformations_g_n_rales->setText(QApplication::translate("MainWindow", "Informations g\303\251n\303\251rales", 0, QApplication::UnicodeUTF8));
        actionRenseigner_les_informations_sur_votre_h_tel->setText(QApplication::translate("MainWindow", "Renseigner les informations sur votre h\303\264tel", 0, QApplication::UnicodeUTF8));
        actionConfigurer_le_menu_du_restaurant->setText(QApplication::translate("MainWindow", "Configurer le menu du restaurant", 0, QApplication::UnicodeUTF8));
        actionVisualiser_le_cardex->setText(QApplication::translate("MainWindow", "Visualiser le cardex", 0, QApplication::UnicodeUTF8));
        actionConfigurer_taux_des_taxes->setText(QApplication::translate("MainWindow", "Configurer taux des taxes", 0, QApplication::UnicodeUTF8));
        actionLa_r_ception->setText(QApplication::translate("MainWindow", "La r\303\251ception", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLa_r_ception->setToolTip(QApplication::translate("MainWindow", "Visualiser la r\303\251ception", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionActualiser->setText(QApplication::translate("MainWindow", "Actualiser", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEditer->setTitle(QApplication::translate("MainWindow", "Editer", 0, QApplication::UnicodeUTF8));
        menuParam_tres->setTitle(QApplication::translate("MainWindow", "Param\303\250tres", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        menuVisualiser->setTitle(QApplication::translate("MainWindow", "Visualiser", 0, QApplication::UnicodeUTF8));
        menuAffichage->setTitle(QApplication::translate("MainWindow", "Affichage", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
