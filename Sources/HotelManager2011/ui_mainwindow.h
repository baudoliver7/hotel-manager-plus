/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 25. Oct 17:20:37 2013
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
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSeConnecter;
    QAction *actionSeDeconnecter;
    QAction *actionQuitter;
    QAction *actionTaches_du_service_en_cours;
    QAction *actionRechercherUnClient;
    QAction *actionRechercherUneReservation;
    QAction *actionRechercherUneOccupation;
    QAction *actionActiver_son_de_compagnon;
    QAction *actionActiver_un_nouveau_compte;
    QAction *actionEditer_votre_compte;
    QAction *actionAjuster_Heure_Date;
    QAction *actionActualiser_la_fen_tre;
    QAction *actionEnvoyer_et_ou_recevoir_des_messages;
    QAction *actionEnregistrer_passe;
    QAction *actionAide_en_ligne;
    QAction *actionA_propos_de_hotel_manger_plus;
    QAction *actionFen_tre_visuelle;
    QAction *actionPlanning_complet;
    QAction *actionAfficher_r_servations;
    QAction *actionAfficher_locations;
    QAction *actionAfficher_r_servations_locations;
    QAction *actionCreer_Un_compte_client;
    QAction *actionCreer_Un_groupe_de_client;
    QAction *actionDebiterUnCompteClient;
    QAction *actionFacturer_un_groupe_de_client;
    QAction *actionAjouter_un_client_un_groupe;
    QAction *actionRechercher_un_groupe_de_client;
    QAction *actionEditer_le_cardex;
    QAction *actionEnregistrer_tout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QFormLayout *formLayout_2;
    QLabel *label_logo;
    QLabel *label_horloge;
    QFrame *frameMessagerie;
    QFormLayout *formLayout;
    QLabel *labelEnveloppe;
    QHBoxLayout *horizontalLayout;
    QLabel *labelNbMsgNonLus;
    QPushButton *btn_lire;
    QFrame *frame_3;
    QFormLayout *formLayout_3;
    QLabel *label_heureDeConnection;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;
    QMenu *menu;
    QMenu *menuConfigurer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1018, 676);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo_r.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionSeConnecter = new QAction(MainWindow);
        actionSeConnecter->setObjectName(QString::fromUtf8("actionSeConnecter"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/conpf.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSeConnecter->setIcon(icon1);
        actionSeDeconnecter = new QAction(MainWindow);
        actionSeDeconnecter->setObjectName(QString::fromUtf8("actionSeDeconnecter"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/d\303\251connecter_pf.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSeDeconnecter->setIcon(icon2);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionTaches_du_service_en_cours = new QAction(MainWindow);
        actionTaches_du_service_en_cours->setObjectName(QString::fromUtf8("actionTaches_du_service_en_cours"));
        actionRechercherUnClient = new QAction(MainWindow);
        actionRechercherUnClient->setObjectName(QString::fromUtf8("actionRechercherUnClient"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/recherch_client_pf.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRechercherUnClient->setIcon(icon3);
        actionRechercherUneReservation = new QAction(MainWindow);
        actionRechercherUneReservation->setObjectName(QString::fromUtf8("actionRechercherUneReservation"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/recherch_reserv_pf.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRechercherUneReservation->setIcon(icon4);
        actionRechercherUneOccupation = new QAction(MainWindow);
        actionRechercherUneOccupation->setObjectName(QString::fromUtf8("actionRechercherUneOccupation"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/recherch_loc_pf.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRechercherUneOccupation->setIcon(icon5);
        actionActiver_son_de_compagnon = new QAction(MainWindow);
        actionActiver_son_de_compagnon->setObjectName(QString::fromUtf8("actionActiver_son_de_compagnon"));
        actionActiver_son_de_compagnon->setCheckable(true);
        actionActiver_un_nouveau_compte = new QAction(MainWindow);
        actionActiver_un_nouveau_compte->setObjectName(QString::fromUtf8("actionActiver_un_nouveau_compte"));
        actionEditer_votre_compte = new QAction(MainWindow);
        actionEditer_votre_compte->setObjectName(QString::fromUtf8("actionEditer_votre_compte"));
        actionAjuster_Heure_Date = new QAction(MainWindow);
        actionAjuster_Heure_Date->setObjectName(QString::fromUtf8("actionAjuster_Heure_Date"));
        actionActualiser_la_fen_tre = new QAction(MainWindow);
        actionActualiser_la_fen_tre->setObjectName(QString::fromUtf8("actionActualiser_la_fen_tre"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/actualiser_pf.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionActualiser_la_fen_tre->setIcon(icon6);
        actionEnvoyer_et_ou_recevoir_des_messages = new QAction(MainWindow);
        actionEnvoyer_et_ou_recevoir_des_messages->setObjectName(QString::fromUtf8("actionEnvoyer_et_ou_recevoir_des_messages"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/msgs2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnvoyer_et_ou_recevoir_des_messages->setIcon(icon7);
        actionEnregistrer_passe = new QAction(MainWindow);
        actionEnregistrer_passe->setObjectName(QString::fromUtf8("actionEnregistrer_passe"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/enreg_passe_pf.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregistrer_passe->setIcon(icon8);
        actionAide_en_ligne = new QAction(MainWindow);
        actionAide_en_ligne->setObjectName(QString::fromUtf8("actionAide_en_ligne"));
        actionA_propos_de_hotel_manger_plus = new QAction(MainWindow);
        actionA_propos_de_hotel_manger_plus->setObjectName(QString::fromUtf8("actionA_propos_de_hotel_manger_plus"));
        actionFen_tre_visuelle = new QAction(MainWindow);
        actionFen_tre_visuelle->setObjectName(QString::fromUtf8("actionFen_tre_visuelle"));
        actionPlanning_complet = new QAction(MainWindow);
        actionPlanning_complet->setObjectName(QString::fromUtf8("actionPlanning_complet"));
        actionAfficher_r_servations = new QAction(MainWindow);
        actionAfficher_r_servations->setObjectName(QString::fromUtf8("actionAfficher_r_servations"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/afficherReservation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAfficher_r_servations->setIcon(icon9);
        actionAfficher_locations = new QAction(MainWindow);
        actionAfficher_locations->setObjectName(QString::fromUtf8("actionAfficher_locations"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/afficherLocations.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAfficher_locations->setIcon(icon10);
        actionAfficher_r_servations_locations = new QAction(MainWindow);
        actionAfficher_r_servations_locations->setObjectName(QString::fromUtf8("actionAfficher_r_servations_locations"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/afficherMixte.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAfficher_r_servations_locations->setIcon(icon11);
        actionCreer_Un_compte_client = new QAction(MainWindow);
        actionCreer_Un_compte_client->setObjectName(QString::fromUtf8("actionCreer_Un_compte_client"));
        actionCreer_Un_groupe_de_client = new QAction(MainWindow);
        actionCreer_Un_groupe_de_client->setObjectName(QString::fromUtf8("actionCreer_Un_groupe_de_client"));
        actionDebiterUnCompteClient = new QAction(MainWindow);
        actionDebiterUnCompteClient->setObjectName(QString::fromUtf8("actionDebiterUnCompteClient"));
        actionFacturer_un_groupe_de_client = new QAction(MainWindow);
        actionFacturer_un_groupe_de_client->setObjectName(QString::fromUtf8("actionFacturer_un_groupe_de_client"));
        actionAjouter_un_client_un_groupe = new QAction(MainWindow);
        actionAjouter_un_client_un_groupe->setObjectName(QString::fromUtf8("actionAjouter_un_client_un_groupe"));
        actionRechercher_un_groupe_de_client = new QAction(MainWindow);
        actionRechercher_un_groupe_de_client->setObjectName(QString::fromUtf8("actionRechercher_un_groupe_de_client"));
        actionEditer_le_cardex = new QAction(MainWindow);
        actionEditer_le_cardex->setObjectName(QString::fromUtf8("actionEditer_le_cardex"));
        actionEnregistrer_tout = new QAction(MainWindow);
        actionEnregistrer_tout->setObjectName(QString::fromUtf8("actionEnregistrer_tout"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregistrer_tout->setIcon(icon12);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 52));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 52));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frame_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setContentsMargins(0, -1, 0, 0);
        label_logo = new QLabel(frame_2);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setMaximumSize(QSize(38, 32));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_logo->setScaledContents(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_logo);

        label_horloge = new QLabel(frame_2);
        label_horloge->setObjectName(QString::fromUtf8("label_horloge"));
        label_horloge->setMaximumSize(QSize(180, 16777215));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_horloge);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);

        frameMessagerie = new QFrame(frame);
        frameMessagerie->setObjectName(QString::fromUtf8("frameMessagerie"));
        frameMessagerie->setMinimumSize(QSize(290, 0));
        frameMessagerie->setMaximumSize(QSize(10000, 52));
        frameMessagerie->setLayoutDirection(Qt::LeftToRight);
        frameMessagerie->setFrameShape(QFrame::StyledPanel);
        frameMessagerie->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frameMessagerie);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(0, 0, 0, 0);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        labelEnveloppe = new QLabel(frameMessagerie);
        labelEnveloppe->setObjectName(QString::fromUtf8("labelEnveloppe"));
        labelEnveloppe->setMinimumSize(QSize(50, 23));
        labelEnveloppe->setMaximumSize(QSize(50, 23));
        labelEnveloppe->setLayoutDirection(Qt::LeftToRight);
        labelEnveloppe->setPixmap(QPixmap(QString::fromUtf8(":/images/enveloppe verte.png")));
        labelEnveloppe->setScaledContents(true);
        labelEnveloppe->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelEnveloppe);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelNbMsgNonLus = new QLabel(frameMessagerie);
        labelNbMsgNonLus->setObjectName(QString::fromUtf8("labelNbMsgNonLus"));
        labelNbMsgNonLus->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(labelNbMsgNonLus);

        btn_lire = new QPushButton(frameMessagerie);
        btn_lire->setObjectName(QString::fromUtf8("btn_lire"));
        btn_lire->setMinimumSize(QSize(120, 0));
        btn_lire->setMaximumSize(QSize(120, 23));

        horizontalLayout->addWidget(btn_lire);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);


        gridLayout->addWidget(frameMessagerie, 0, 1, 1, 1);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMaximumSize(QSize(16777215, 52));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        formLayout_3 = new QFormLayout(frame_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_heureDeConnection = new QLabel(frame_3);
        label_heureDeConnection->setObjectName(QString::fromUtf8("label_heureDeConnection"));
        label_heureDeConnection->setMaximumSize(QSize(390, 16777215));
        label_heureDeConnection->setLayoutDirection(Qt::RightToLeft);
        label_heureDeConnection->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_heureDeConnection);


        gridLayout->addWidget(frame_3, 0, 2, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(mdiArea, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1018, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuConfigurer = new QMenu(menuBar);
        menuConfigurer->setObjectName(QString::fromUtf8("menuConfigurer"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::AllToolBarAreas);
        mainToolBar->setIconSize(QSize(32, 32));
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuConfigurer->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addAction(actionSeConnecter);
        menuFichier->addAction(actionSeDeconnecter);
        menuFichier->addSeparator();
        menuFichier->addAction(actionActiver_un_nouveau_compte);
        menuFichier->addSeparator();
        menuFichier->addAction(actionEnregistrer_passe);
        menuFichier->addAction(actionEnregistrer_tout);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuEdition->addAction(actionRechercherUnClient);
        menuEdition->addAction(actionRechercherUneOccupation);
        menuEdition->addAction(actionRechercherUneReservation);
        menuEdition->addSeparator();
        menuEdition->addAction(actionEditer_votre_compte);
        menuEdition->addSeparator();
        menuEdition->addAction(actionEditer_le_cardex);
        menuAffichage->addAction(actionActualiser_la_fen_tre);
        menu->addAction(actionAide_en_ligne);
        menu->addSeparator();
        menu->addAction(actionA_propos_de_hotel_manger_plus);
        menuConfigurer->addAction(actionCreer_Un_compte_client);
        menuConfigurer->addAction(actionDebiterUnCompteClient);
        menuConfigurer->addSeparator();
        menuConfigurer->addAction(actionCreer_Un_groupe_de_client);
        menuConfigurer->addAction(actionAjouter_un_client_un_groupe);
        menuConfigurer->addAction(actionFacturer_un_groupe_de_client);
        menuConfigurer->addAction(actionRechercher_un_groupe_de_client);
        mainToolBar->addAction(actionSeConnecter);
        mainToolBar->addAction(actionSeDeconnecter);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRechercherUnClient);
        mainToolBar->addAction(actionRechercherUneOccupation);
        mainToolBar->addAction(actionRechercherUneReservation);
        mainToolBar->addAction(actionActualiser_la_fen_tre);
        mainToolBar->addAction(actionEnvoyer_et_ou_recevoir_des_messages);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionEnregistrer_tout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Hotel Manger R\303\251ception Plus", 0, QApplication::UnicodeUTF8));
        actionSeConnecter->setText(QApplication::translate("MainWindow", "Se connecter", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSeConnecter->setToolTip(QApplication::translate("MainWindow", "Se connecter \303\240 un compte r\303\251cepteur", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSeDeconnecter->setText(QApplication::translate("MainWindow", "Se d\303\251connecter", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSeDeconnecter->setToolTip(QApplication::translate("MainWindow", "Se d\303\251connecter du compte en cours", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionTaches_du_service_en_cours->setText(QApplication::translate("MainWindow", "T\303\242ches du service en cours", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionTaches_du_service_en_cours->setToolTip(QApplication::translate("MainWindow", "T\303\242ches minimales \303\240 effectuer durant le service", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRechercherUnClient->setText(QApplication::translate("MainWindow", "Rechercher un client", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRechercherUnClient->setToolTip(QApplication::translate("MainWindow", "Rechercher un client", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRechercherUneReservation->setText(QApplication::translate("MainWindow", "Rechercher une r\303\251servation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRechercherUneReservation->setToolTip(QApplication::translate("MainWindow", "Rechercher une r\303\251servation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRechercherUneOccupation->setText(QApplication::translate("MainWindow", "Rechercher une location", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRechercherUneOccupation->setToolTip(QApplication::translate("MainWindow", "Rechercher une location", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionActiver_son_de_compagnon->setText(QApplication::translate("MainWindow", "Muter le volume (Agent Hotel Manager)", 0, QApplication::UnicodeUTF8));
        actionActiver_un_nouveau_compte->setText(QApplication::translate("MainWindow", "Activer un nouveau compte...", 0, QApplication::UnicodeUTF8));
        actionEditer_votre_compte->setText(QApplication::translate("MainWindow", "Editer votre compte", 0, QApplication::UnicodeUTF8));
        actionAjuster_Heure_Date->setText(QApplication::translate("MainWindow", "Ajuster Date/Heure", 0, QApplication::UnicodeUTF8));
        actionActualiser_la_fen_tre->setText(QApplication::translate("MainWindow", "Actualiser l'onglet actif", 0, QApplication::UnicodeUTF8));
        actionEnvoyer_et_ou_recevoir_des_messages->setText(QApplication::translate("MainWindow", "Envoyer et/ou recevoir des messages", 0, QApplication::UnicodeUTF8));
        actionEnregistrer_passe->setText(QApplication::translate("MainWindow", "Enregistrer une passe", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEnregistrer_passe->setToolTip(QApplication::translate("MainWindow", "Enregistrer une passe", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAide_en_ligne->setText(QApplication::translate("MainWindow", "Aide en ligne", 0, QApplication::UnicodeUTF8));
        actionA_propos_de_hotel_manger_plus->setText(QApplication::translate("MainWindow", "A propos de Hotel Manger Plus", 0, QApplication::UnicodeUTF8));
        actionFen_tre_visuelle->setText(QApplication::translate("MainWindow", "Planning simplifi\303\251", 0, QApplication::UnicodeUTF8));
        actionPlanning_complet->setText(QApplication::translate("MainWindow", "Planning complet", 0, QApplication::UnicodeUTF8));
        actionAfficher_r_servations->setText(QApplication::translate("MainWindow", "Afficher r\303\251servations", 0, QApplication::UnicodeUTF8));
        actionAfficher_locations->setText(QApplication::translate("MainWindow", "Afficher locations", 0, QApplication::UnicodeUTF8));
        actionAfficher_r_servations_locations->setText(QApplication::translate("MainWindow", "Afficher locations/r\303\251servations", 0, QApplication::UnicodeUTF8));
        actionCreer_Un_compte_client->setText(QApplication::translate("MainWindow", "Cr\303\251er un compte client", 0, QApplication::UnicodeUTF8));
        actionCreer_Un_groupe_de_client->setText(QApplication::translate("MainWindow", "Cr\303\251er un groupe de client", 0, QApplication::UnicodeUTF8));
        actionDebiterUnCompteClient->setText(QApplication::translate("MainWindow", "D\303\251biter / cr\303\251diter un compte client", 0, QApplication::UnicodeUTF8));
        actionFacturer_un_groupe_de_client->setText(QApplication::translate("MainWindow", "Facturer un groupe de client", 0, QApplication::UnicodeUTF8));
        actionAjouter_un_client_un_groupe->setText(QApplication::translate("MainWindow", "Ajouter / retirer un client d'un groupe", 0, QApplication::UnicodeUTF8));
        actionRechercher_un_groupe_de_client->setText(QApplication::translate("MainWindow", "Rechercher un groupe de client", 0, QApplication::UnicodeUTF8));
        actionEditer_le_cardex->setText(QApplication::translate("MainWindow", "Visualiser le cardex", 0, QApplication::UnicodeUTF8));
        actionEnregistrer_tout->setText(QApplication::translate("MainWindow", "Enregistrer tout", 0, QApplication::UnicodeUTF8));
        label_logo->setText(QString());
        label_horloge->setText(QApplication::translate("MainWindow", "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, QApplication::UnicodeUTF8));
        labelEnveloppe->setText(QString());
        labelNbMsgNonLus->setText(QApplication::translate("MainWindow", "00 messages non lus", 0, QApplication::UnicodeUTF8));
        btn_lire->setText(QApplication::translate("MainWindow", "Lire", 0, QApplication::UnicodeUTF8));
        label_heureDeConnection->setText(QApplication::translate("MainWindow", "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Editer", 0, QApplication::UnicodeUTF8));
        menuAffichage->setTitle(QApplication::translate("MainWindow", "Actualiser", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        menuConfigurer->setTitle(QApplication::translate("MainWindow", "Compte et groupe", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
