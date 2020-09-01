/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 15. Dec 10:16:21 2011
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
    QAction *actionSeConnecter;
    QAction *actionSeDeconnecter;
    QAction *actionQuitter;
    QAction *actionTaches_du_service_en_cours;
    QAction *actionRechercherUnClient;
    QAction *actionRechercherUneReservation;
    QAction *actionRechercherUneOccupation;
    QAction *actionActiver_son_de_compagnon;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuOptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(950, 646);
        actionSeConnecter = new QAction(MainWindow);
        actionSeConnecter->setObjectName(QString::fromUtf8("actionSeConnecter"));
        actionSeDeconnecter = new QAction(MainWindow);
        actionSeDeconnecter->setObjectName(QString::fromUtf8("actionSeDeconnecter"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionTaches_du_service_en_cours = new QAction(MainWindow);
        actionTaches_du_service_en_cours->setObjectName(QString::fromUtf8("actionTaches_du_service_en_cours"));
        actionRechercherUnClient = new QAction(MainWindow);
        actionRechercherUnClient->setObjectName(QString::fromUtf8("actionRechercherUnClient"));
        actionRechercherUneReservation = new QAction(MainWindow);
        actionRechercherUneReservation->setObjectName(QString::fromUtf8("actionRechercherUneReservation"));
        actionRechercherUneOccupation = new QAction(MainWindow);
        actionRechercherUneOccupation->setObjectName(QString::fromUtf8("actionRechercherUneOccupation"));
        actionActiver_son_de_compagnon = new QAction(MainWindow);
        actionActiver_son_de_compagnon->setObjectName(QString::fromUtf8("actionActiver_son_de_compagnon"));
        actionActiver_son_de_compagnon->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setMinimumSize(QSize(950, 595));

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 950, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFichier->addAction(actionSeConnecter);
        menuFichier->addAction(actionSeDeconnecter);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuEdition->addAction(actionRechercherUnClient);
        menuEdition->addAction(actionRechercherUneOccupation);
        menuEdition->addAction(actionRechercherUneReservation);
        menuOptions->addAction(actionActiver_son_de_compagnon);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Hotel Manger 2011 - Reception", 0, QApplication::UnicodeUTF8));
        actionSeConnecter->setText(QApplication::translate("MainWindow", "Se connecter...", 0, QApplication::UnicodeUTF8));
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
        actionRechercherUneOccupation->setText(QApplication::translate("MainWindow", "Rechercher une occupation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRechercherUneOccupation->setToolTip(QApplication::translate("MainWindow", "Rechercher une occupation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionActiver_son_de_compagnon->setText(QApplication::translate("MainWindow", "Muter le volume (Agent Hotel Manager)", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
