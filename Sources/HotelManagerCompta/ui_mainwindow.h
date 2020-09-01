/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 25. Jan 23:18:57 2013
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
    QAction *actionSe_connecter;
    QAction *actionSe_d_connecter;
    QAction *actionQuitter;
    QAction *actionEditer_votre_compte;
    QAction *actionActiver_un_nouveau_compte;
    QAction *actionAide_en_ligne;
    QAction *actionA_propos_de_Hotel_Manager;
    QAction *actionEnvoyer_et_ou_recevoir_des_messages;
    QAction *actionConfigurer_les_comptes;
    QAction *actionUne_operation;
    QAction *actionSupprimer_une_op_ration;
    QAction *actionLa_comptabilit_des_services;
    QAction *actionMes_comptes_en_arbre;
    QAction *actionMes_comptes_uniquement;
    QAction *actionD_terminer_le_compte_r_sultat;
    QAction *actionEditer_les_cl_tures;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEditer;
    QMenu *menu;
    QMenu *menuConfiguration;
    QMenu *menuEx_cuter;
    QMenu *menuPr_f_rences;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo_c.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
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
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionEditer_votre_compte = new QAction(MainWindow);
        actionEditer_votre_compte->setObjectName(QString::fromUtf8("actionEditer_votre_compte"));
        actionActiver_un_nouveau_compte = new QAction(MainWindow);
        actionActiver_un_nouveau_compte->setObjectName(QString::fromUtf8("actionActiver_un_nouveau_compte"));
        actionAide_en_ligne = new QAction(MainWindow);
        actionAide_en_ligne->setObjectName(QString::fromUtf8("actionAide_en_ligne"));
        actionA_propos_de_Hotel_Manager = new QAction(MainWindow);
        actionA_propos_de_Hotel_Manager->setObjectName(QString::fromUtf8("actionA_propos_de_Hotel_Manager"));
        actionEnvoyer_et_ou_recevoir_des_messages = new QAction(MainWindow);
        actionEnvoyer_et_ou_recevoir_des_messages->setObjectName(QString::fromUtf8("actionEnvoyer_et_ou_recevoir_des_messages"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/msgs2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnvoyer_et_ou_recevoir_des_messages->setIcon(icon3);
        actionConfigurer_les_comptes = new QAction(MainWindow);
        actionConfigurer_les_comptes->setObjectName(QString::fromUtf8("actionConfigurer_les_comptes"));
        actionUne_operation = new QAction(MainWindow);
        actionUne_operation->setObjectName(QString::fromUtf8("actionUne_operation"));
        actionSupprimer_une_op_ration = new QAction(MainWindow);
        actionSupprimer_une_op_ration->setObjectName(QString::fromUtf8("actionSupprimer_une_op_ration"));
        actionLa_comptabilit_des_services = new QAction(MainWindow);
        actionLa_comptabilit_des_services->setObjectName(QString::fromUtf8("actionLa_comptabilit_des_services"));
        actionMes_comptes_en_arbre = new QAction(MainWindow);
        actionMes_comptes_en_arbre->setObjectName(QString::fromUtf8("actionMes_comptes_en_arbre"));
        actionMes_comptes_en_arbre->setCheckable(true);
        actionMes_comptes_en_arbre->setChecked(false);
        actionMes_comptes_uniquement = new QAction(MainWindow);
        actionMes_comptes_uniquement->setObjectName(QString::fromUtf8("actionMes_comptes_uniquement"));
        actionMes_comptes_uniquement->setCheckable(true);
        actionMes_comptes_uniquement->setChecked(true);
        actionD_terminer_le_compte_r_sultat = new QAction(MainWindow);
        actionD_terminer_le_compte_r_sultat->setObjectName(QString::fromUtf8("actionD_terminer_le_compte_r_sultat"));
        actionEditer_les_cl_tures = new QAction(MainWindow);
        actionEditer_les_cl_tures->setObjectName(QString::fromUtf8("actionEditer_les_cl_tures"));
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
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setIconSize(QSize(32, 32));
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEditer = new QMenu(menuBar);
        menuEditer->setObjectName(QString::fromUtf8("menuEditer"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuConfiguration = new QMenu(menuBar);
        menuConfiguration->setObjectName(QString::fromUtf8("menuConfiguration"));
        menuEx_cuter = new QMenu(menuBar);
        menuEx_cuter->setObjectName(QString::fromUtf8("menuEx_cuter"));
        menuPr_f_rences = new QMenu(menuBar);
        menuPr_f_rences->setObjectName(QString::fromUtf8("menuPr_f_rences"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(actionSe_connecter);
        mainToolBar->addAction(actionSe_d_connecter);
        mainToolBar->addAction(actionEnvoyer_et_ou_recevoir_des_messages);
        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEditer->menuAction());
        menuBar->addAction(menuEx_cuter->menuAction());
        menuBar->addAction(menuConfiguration->menuAction());
        menuBar->addAction(menuPr_f_rences->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFichier->addAction(actionSe_connecter);
        menuFichier->addAction(actionSe_d_connecter);
        menuFichier->addSeparator();
        menuFichier->addAction(actionActiver_un_nouveau_compte);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuEditer->addAction(actionEditer_votre_compte);
        menuEditer->addSeparator();
        menuEditer->addAction(actionSupprimer_une_op_ration);
        menuEditer->addSeparator();
        menuEditer->addAction(actionEditer_les_cl_tures);
        menu->addAction(actionAide_en_ligne);
        menu->addSeparator();
        menu->addAction(actionA_propos_de_Hotel_Manager);
        menuConfiguration->addAction(actionConfigurer_les_comptes);
        menuConfiguration->addAction(actionLa_comptabilit_des_services);
        menuEx_cuter->addAction(actionUne_operation);
        menuEx_cuter->addAction(actionD_terminer_le_compte_r_sultat);
        menuPr_f_rences->addAction(actionMes_comptes_en_arbre);
        menuPr_f_rences->addAction(actionMes_comptes_uniquement);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSe_connecter->setText(QApplication::translate("MainWindow", "Se connecter", 0, QApplication::UnicodeUTF8));
        actionSe_d_connecter->setText(QApplication::translate("MainWindow", "Se d\303\251connecter", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionEditer_votre_compte->setText(QApplication::translate("MainWindow", "Editer votre compte", 0, QApplication::UnicodeUTF8));
        actionActiver_un_nouveau_compte->setText(QApplication::translate("MainWindow", "Activer un nouveau compte", 0, QApplication::UnicodeUTF8));
        actionAide_en_ligne->setText(QApplication::translate("MainWindow", "Aide en ligne", 0, QApplication::UnicodeUTF8));
        actionA_propos_de_Hotel_Manager->setText(QApplication::translate("MainWindow", "A propos de Hotel Manager Plus", 0, QApplication::UnicodeUTF8));
        actionEnvoyer_et_ou_recevoir_des_messages->setText(QApplication::translate("MainWindow", "Envoyer et/ou recevoir des messages ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEnvoyer_et_ou_recevoir_des_messages->setToolTip(QApplication::translate("MainWindow", "Envoyer et/ou recevoir des messages ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionConfigurer_les_comptes->setText(QApplication::translate("MainWindow", "Les comptes", 0, QApplication::UnicodeUTF8));
        actionUne_operation->setText(QApplication::translate("MainWindow", "Enregister une nouvelle op\303\251ration", 0, QApplication::UnicodeUTF8));
        actionSupprimer_une_op_ration->setText(QApplication::translate("MainWindow", "Supprimer une op\303\251ration", 0, QApplication::UnicodeUTF8));
        actionLa_comptabilit_des_services->setText(QApplication::translate("MainWindow", "La comptabilit\303\251 des services", 0, QApplication::UnicodeUTF8));
        actionMes_comptes_en_arbre->setText(QApplication::translate("MainWindow", "Mes comptes en arbre", 0, QApplication::UnicodeUTF8));
        actionMes_comptes_uniquement->setText(QApplication::translate("MainWindow", "Mes comptes uniquement", 0, QApplication::UnicodeUTF8));
        actionD_terminer_le_compte_r_sultat->setText(QApplication::translate("MainWindow", "Obtenir le compte r\303\251sultat", 0, QApplication::UnicodeUTF8));
        actionEditer_les_cl_tures->setText(QApplication::translate("MainWindow", "Editer les cl\303\264tures", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEditer->setTitle(QApplication::translate("MainWindow", "Editer", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        menuConfiguration->setTitle(QApplication::translate("MainWindow", "Configurer", 0, QApplication::UnicodeUTF8));
        menuEx_cuter->setTitle(QApplication::translate("MainWindow", "Ex\303\251cuter", 0, QApplication::UnicodeUTF8));
        menuPr_f_rences->setTitle(QApplication::translate("MainWindow", "Afficher", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
