/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 4. Jun 08:56:16 2012
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
    QAction *actionSe_connecter_au_service_R_ception;
    QAction *actionSe_connecter;
    QAction *actionSe_d_connecter;
    QAction *actionActiver_son_compte;
    QAction *actionEcrire_et_recevoir_des_messages;
    QAction *actionAide_en_ligne;
    QAction *actionA_propos_de_Hotel_Manager_Plus;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEditer;
    QMenu *menuAide;
    QMenu *menuMessagerie;
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
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        menuMessagerie = new QMenu(menuBar);
        menuMessagerie->setObjectName(QString::fromUtf8("menuMessagerie"));
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
        menuBar->addAction(menuMessagerie->menuAction());
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
        menuMessagerie->addAction(actionEcrire_et_recevoir_des_messages);
        mainToolBar->addAction(actionSe_connecter);
        mainToolBar->addAction(actionSe_d_connecter);
        mainToolBar->addSeparator();
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
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEditer->setTitle(QApplication::translate("MainWindow", "Editer", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        menuMessagerie->setTitle(QApplication::translate("MainWindow", "Messagerie", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
