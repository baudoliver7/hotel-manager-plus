/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 24. Mar 10:43:33 2012
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
    QAction *actionEn_diff_r;
    QAction *actionEn_ligne;
    QAction *actionQuitter;
    QAction *actionStatut_d_un_produit;
    QAction *actionWin32;
    QAction *actionWin64;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuMode_d_activation;
    QMenu *menuConfiguration;
    QMenu *menuDriver_odbc;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 482);
        MainWindow->setMinimumSize(QSize(600, 482));
        MainWindow->setMaximumSize(QSize(600, 482));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionEn_diff_r = new QAction(MainWindow);
        actionEn_diff_r->setObjectName(QString::fromUtf8("actionEn_diff_r"));
        actionEn_ligne = new QAction(MainWindow);
        actionEn_ligne->setObjectName(QString::fromUtf8("actionEn_ligne"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionStatut_d_un_produit = new QAction(MainWindow);
        actionStatut_d_un_produit->setObjectName(QString::fromUtf8("actionStatut_d_un_produit"));
        actionWin32 = new QAction(MainWindow);
        actionWin32->setObjectName(QString::fromUtf8("actionWin32"));
        actionWin64 = new QAction(MainWindow);
        actionWin64->setObjectName(QString::fromUtf8("actionWin64"));
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
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuMode_d_activation = new QMenu(menuFichier);
        menuMode_d_activation->setObjectName(QString::fromUtf8("menuMode_d_activation"));
        menuConfiguration = new QMenu(menuBar);
        menuConfiguration->setObjectName(QString::fromUtf8("menuConfiguration"));
        menuDriver_odbc = new QMenu(menuConfiguration);
        menuDriver_odbc->setObjectName(QString::fromUtf8("menuDriver_odbc"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuConfiguration->menuAction());
        menuFichier->addAction(menuMode_d_activation->menuAction());
        menuFichier->addAction(actionQuitter);
        menuMode_d_activation->addAction(actionEn_diff_r);
        menuMode_d_activation->addAction(actionEn_ligne);
        menuConfiguration->addAction(actionStatut_d_un_produit);
        menuConfiguration->addAction(menuDriver_odbc->menuAction());
        menuDriver_odbc->addAction(actionWin32);
        menuDriver_odbc->addAction(actionWin64);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Activateur master de Hotel Manager Plus", 0, QApplication::UnicodeUTF8));
        actionEn_diff_r->setText(QApplication::translate("MainWindow", "En diff\303\251r\303\251", 0, QApplication::UnicodeUTF8));
        actionEn_ligne->setText(QApplication::translate("MainWindow", "En ligne", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionStatut_d_un_produit->setText(QApplication::translate("MainWindow", "Statut d'un produit", 0, QApplication::UnicodeUTF8));
        actionWin32->setText(QApplication::translate("MainWindow", "win32", 0, QApplication::UnicodeUTF8));
        actionWin64->setText(QApplication::translate("MainWindow", "win64", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuMode_d_activation->setTitle(QApplication::translate("MainWindow", "Mode d'activation", 0, QApplication::UnicodeUTF8));
        menuConfiguration->setTitle(QApplication::translate("MainWindow", "Configuration", 0, QApplication::UnicodeUTF8));
        menuDriver_odbc->setTitle(QApplication::translate("MainWindow", "Driver odbc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
