/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 27. Oct 20:07:21 2013
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
    QAction *actionQuitter;
    QAction *actionChanger_password;
    QAction *actionSe_connecter_au_service_R_ception;
    QAction *actionSe_connecter;
    QAction *actionSe_d_connecter;
    QAction *actionActiver_son_compte;
    QAction *actionEcrire_et_recevoir_des_messages;
    QAction *actionAide_en_ligne;
    QAction *actionA_propos_de_Hotel_Manager_Plus;
    QAction *actionFacture_non_pay;
    QAction *actionCr_er_un_compte_client;
    QAction *actionD_biter_un_compte_client;
    QAction *actionConfigurer_mes_tables;
    QAction *actionConfigurer_mon_module;
    QAction *actionActualiser_onglet_actif;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QFrame *frameHeureServeur;
    QFormLayout *formLayout_3;
    QLabel *label_logo;
    QLabel *label_horloge;
    QFrame *frameMessagerie;
    QFormLayout *formLayout_2;
    QLabel *labelEnveloppe;
    QFormLayout *formLayout_5;
    QLabel *labelNbMsgNonLus;
    QPushButton *btn_lire;
    QFrame *frameHeureDeConnection;
    QFormLayout *formLayout;
    QLabel *label_heureDeConnection;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEditer;
    QMenu *menuAide;
    QMenu *menuRechercher;
    QMenu *menuComptes;
    QMenu *menuConfigurer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1043, 608);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo_a.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionChanger_password = new QAction(MainWindow);
        actionChanger_password->setObjectName(QString::fromUtf8("actionChanger_password"));
        actionSe_connecter_au_service_R_ception = new QAction(MainWindow);
        actionSe_connecter_au_service_R_ception->setObjectName(QString::fromUtf8("actionSe_connecter_au_service_R_ception"));
        actionSe_connecter = new QAction(MainWindow);
        actionSe_connecter->setObjectName(QString::fromUtf8("actionSe_connecter"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/connecter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSe_connecter->setIcon(icon1);
        actionSe_d_connecter = new QAction(MainWindow);
        actionSe_d_connecter->setObjectName(QString::fromUtf8("actionSe_d_connecter"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/d\303\251connecter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSe_d_connecter->setIcon(icon2);
        actionActiver_son_compte = new QAction(MainWindow);
        actionActiver_son_compte->setObjectName(QString::fromUtf8("actionActiver_son_compte"));
        actionEcrire_et_recevoir_des_messages = new QAction(MainWindow);
        actionEcrire_et_recevoir_des_messages->setObjectName(QString::fromUtf8("actionEcrire_et_recevoir_des_messages"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/msgs2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEcrire_et_recevoir_des_messages->setIcon(icon3);
        actionAide_en_ligne = new QAction(MainWindow);
        actionAide_en_ligne->setObjectName(QString::fromUtf8("actionAide_en_ligne"));
        actionA_propos_de_Hotel_Manager_Plus = new QAction(MainWindow);
        actionA_propos_de_Hotel_Manager_Plus->setObjectName(QString::fromUtf8("actionA_propos_de_Hotel_Manager_Plus"));
        actionFacture_non_pay = new QAction(MainWindow);
        actionFacture_non_pay->setObjectName(QString::fromUtf8("actionFacture_non_pay"));
        actionCr_er_un_compte_client = new QAction(MainWindow);
        actionCr_er_un_compte_client->setObjectName(QString::fromUtf8("actionCr_er_un_compte_client"));
        actionD_biter_un_compte_client = new QAction(MainWindow);
        actionD_biter_un_compte_client->setObjectName(QString::fromUtf8("actionD_biter_un_compte_client"));
        actionConfigurer_mes_tables = new QAction(MainWindow);
        actionConfigurer_mes_tables->setObjectName(QString::fromUtf8("actionConfigurer_mes_tables"));
        actionConfigurer_mon_module = new QAction(MainWindow);
        actionConfigurer_mon_module->setObjectName(QString::fromUtf8("actionConfigurer_mon_module"));
        actionActualiser_onglet_actif = new QAction(MainWindow);
        actionActualiser_onglet_actif->setObjectName(QString::fromUtf8("actionActualiser_onglet_actif"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/actualiser_pf.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionActualiser_onglet_actif->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(0);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, -1, 0);
        frameHeureServeur = new QFrame(frame);
        frameHeureServeur->setObjectName(QString::fromUtf8("frameHeureServeur"));
        frameHeureServeur->setMinimumSize(QSize(0, 0));
        frameHeureServeur->setMaximumSize(QSize(16777215, 52));
        frameHeureServeur->setFrameShape(QFrame::StyledPanel);
        frameHeureServeur->setFrameShadow(QFrame::Raised);
        formLayout_3 = new QFormLayout(frameHeureServeur);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_logo = new QLabel(frameHeureServeur);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setMaximumSize(QSize(38, 32));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_logo->setScaledContents(true);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_logo);

        label_horloge = new QLabel(frameHeureServeur);
        label_horloge->setObjectName(QString::fromUtf8("label_horloge"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_horloge);


        gridLayout_2->addWidget(frameHeureServeur, 0, 0, 1, 1);

        frameMessagerie = new QFrame(frame);
        frameMessagerie->setObjectName(QString::fromUtf8("frameMessagerie"));
        frameMessagerie->setMinimumSize(QSize(75, 0));
        frameMessagerie->setMaximumSize(QSize(100000, 52));
        frameMessagerie->setLayoutDirection(Qt::LeftToRight);
        frameMessagerie->setFrameShape(QFrame::StyledPanel);
        frameMessagerie->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frameMessagerie);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignCenter);
        labelEnveloppe = new QLabel(frameMessagerie);
        labelEnveloppe->setObjectName(QString::fromUtf8("labelEnveloppe"));
        labelEnveloppe->setMinimumSize(QSize(50, 23));
        labelEnveloppe->setMaximumSize(QSize(50, 23));
        labelEnveloppe->setLayoutDirection(Qt::LeftToRight);
        labelEnveloppe->setPixmap(QPixmap(QString::fromUtf8(":/images/enveloppe.png")));
        labelEnveloppe->setScaledContents(true);
        labelEnveloppe->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelEnveloppe);

        formLayout_5 = new QFormLayout();
        formLayout_5->setSpacing(6);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_5->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelNbMsgNonLus = new QLabel(frameMessagerie);
        labelNbMsgNonLus->setObjectName(QString::fromUtf8("labelNbMsgNonLus"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, labelNbMsgNonLus);

        btn_lire = new QPushButton(frameMessagerie);
        btn_lire->setObjectName(QString::fromUtf8("btn_lire"));
        btn_lire->setMaximumSize(QSize(120, 23));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, btn_lire);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, formLayout_5);


        gridLayout_2->addWidget(frameMessagerie, 0, 1, 1, 1);

        frameHeureDeConnection = new QFrame(frame);
        frameHeureDeConnection->setObjectName(QString::fromUtf8("frameHeureDeConnection"));
        frameHeureDeConnection->setMinimumSize(QSize(0, 0));
        frameHeureDeConnection->setMaximumSize(QSize(16777215, 52));
        frameHeureDeConnection->setLayoutDirection(Qt::LeftToRight);
        frameHeureDeConnection->setFrameShape(QFrame::StyledPanel);
        frameHeureDeConnection->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frameHeureDeConnection);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(0, 0, 0, 0);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_heureDeConnection = new QLabel(frameHeureDeConnection);
        label_heureDeConnection->setObjectName(QString::fromUtf8("label_heureDeConnection"));
        label_heureDeConnection->setLayoutDirection(Qt::LeftToRight);
        label_heureDeConnection->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_heureDeConnection);


        gridLayout_2->addWidget(frameHeureDeConnection, 0, 2, 1, 1);


        gridLayout_3->addWidget(frame, 0, 0, 1, 1);

        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setMinimumSize(QSize(1000, 0));

        gridLayout_3->addWidget(mdiArea, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1043, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEditer = new QMenu(menuBar);
        menuEditer->setObjectName(QString::fromUtf8("menuEditer"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        menuRechercher = new QMenu(menuBar);
        menuRechercher->setObjectName(QString::fromUtf8("menuRechercher"));
        menuComptes = new QMenu(menuBar);
        menuComptes->setObjectName(QString::fromUtf8("menuComptes"));
        menuConfigurer = new QMenu(menuBar);
        menuConfigurer->setObjectName(QString::fromUtf8("menuConfigurer"));
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
        menuBar->addAction(menuRechercher->menuAction());
        menuBar->addAction(menuComptes->menuAction());
        menuBar->addAction(menuConfigurer->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionSe_connecter);
        menuFichier->addAction(actionSe_d_connecter);
        menuFichier->addSeparator();
        menuFichier->addAction(actionActiver_son_compte);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuEditer->addAction(actionChanger_password);
        menuAide->addAction(actionAide_en_ligne);
        menuAide->addSeparator();
        menuAide->addAction(actionA_propos_de_Hotel_Manager_Plus);
        menuRechercher->addAction(actionFacture_non_pay);
        menuComptes->addAction(actionCr_er_un_compte_client);
        menuComptes->addAction(actionD_biter_un_compte_client);
        menuConfigurer->addAction(actionConfigurer_mes_tables);
        menuConfigurer->addSeparator();
        menuConfigurer->addAction(actionConfigurer_mon_module);
        mainToolBar->addAction(actionSe_connecter);
        mainToolBar->addAction(actionSe_d_connecter);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionActualiser_onglet_actif);
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
        actionSe_connecter_au_service_R_ception->setText(QApplication::translate("MainWindow", "Se connecter au service R\303\251ception", 0, QApplication::UnicodeUTF8));
        actionSe_connecter->setText(QApplication::translate("MainWindow", "Se connecter", 0, QApplication::UnicodeUTF8));
        actionSe_d_connecter->setText(QApplication::translate("MainWindow", "Se d\303\251connecter", 0, QApplication::UnicodeUTF8));
        actionActiver_son_compte->setText(QApplication::translate("MainWindow", "Activer un nouveau compte...", 0, QApplication::UnicodeUTF8));
        actionEcrire_et_recevoir_des_messages->setText(QApplication::translate("MainWindow", "Envoyer et/ou recevoir des messages", 0, QApplication::UnicodeUTF8));
        actionAide_en_ligne->setText(QApplication::translate("MainWindow", "Aide en ligne", 0, QApplication::UnicodeUTF8));
        actionA_propos_de_Hotel_Manager_Plus->setText(QApplication::translate("MainWindow", "A propos de Hotel Manager Plus...", 0, QApplication::UnicodeUTF8));
        actionFacture_non_pay->setText(QApplication::translate("MainWindow", "Factures non pay\303\251es", 0, QApplication::UnicodeUTF8));
        actionCr_er_un_compte_client->setText(QApplication::translate("MainWindow", "Cr\303\251er un compte client", 0, QApplication::UnicodeUTF8));
        actionD_biter_un_compte_client->setText(QApplication::translate("MainWindow", "D\303\251biter/cr\303\251diter un compte client", 0, QApplication::UnicodeUTF8));
        actionConfigurer_mes_tables->setText(QApplication::translate("MainWindow", "Configurer mes tables", 0, QApplication::UnicodeUTF8));
        actionConfigurer_mon_module->setText(QApplication::translate("MainWindow", "Configurer mon module", 0, QApplication::UnicodeUTF8));
        actionActualiser_onglet_actif->setText(QApplication::translate("MainWindow", "Actualiser onglet actif", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionActualiser_onglet_actif->setToolTip(QApplication::translate("MainWindow", "Actualiser onglet actif", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_logo->setText(QString());
        label_horloge->setText(QApplication::translate("MainWindow", "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, QApplication::UnicodeUTF8));
        labelEnveloppe->setText(QString());
        labelNbMsgNonLus->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        btn_lire->setText(QApplication::translate("MainWindow", "Lire", 0, QApplication::UnicodeUTF8));
        label_heureDeConnection->setText(QApplication::translate("MainWindow", "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEditer->setTitle(QApplication::translate("MainWindow", "Editer", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        menuRechercher->setTitle(QApplication::translate("MainWindow", "Rechercher", 0, QApplication::UnicodeUTF8));
        menuComptes->setTitle(QApplication::translate("MainWindow", "Compte", 0, QApplication::UnicodeUTF8));
        menuConfigurer->setTitle(QApplication::translate("MainWindow", "Configurer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
