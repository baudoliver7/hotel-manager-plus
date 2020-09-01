/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 17. Dec 05:10:40 2011
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
#include <QtGui/QDateTimeEdit>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBoxCompagnonFidele;
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidgetCompagnonFidele;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QGraphicsView *compagnonGraphicsView;
    QPushButton *btn_planifier;
    QPushButton *btn_actualiser;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateTimeEdit *heure;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTextEdit *textEditMessage;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(723, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBoxCompagnonFidele = new QGroupBox(centralWidget);
        groupBoxCompagnonFidele->setObjectName(QString::fromUtf8("groupBoxCompagnonFidele"));
        groupBoxCompagnonFidele->setGeometry(QRect(310, 40, 404, 302));
        groupBoxCompagnonFidele->setMaximumSize(QSize(500, 16777215));
        groupBoxCompagnonFidele->setLayoutDirection(Qt::LeftToRight);
        gridLayout_5 = new QGridLayout(groupBoxCompagnonFidele);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tabWidgetCompagnonFidele = new QTabWidget(groupBoxCompagnonFidele);
        tabWidgetCompagnonFidele->setObjectName(QString::fromUtf8("tabWidgetCompagnonFidele"));
        tabWidgetCompagnonFidele->setLayoutDirection(Qt::LeftToRight);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        compagnonGraphicsView = new QGraphicsView(tab_3);
        compagnonGraphicsView->setObjectName(QString::fromUtf8("compagnonGraphicsView"));

        gridLayout_4->addWidget(compagnonGraphicsView, 0, 0, 1, 1);

        tabWidgetCompagnonFidele->addTab(tab_3, QString());

        gridLayout_5->addWidget(tabWidgetCompagnonFidele, 0, 0, 1, 1);

        btn_planifier = new QPushButton(centralWidget);
        btn_planifier->setObjectName(QString::fromUtf8("btn_planifier"));
        btn_planifier->setGeometry(QRect(210, 150, 75, 23));
        btn_actualiser = new QPushButton(centralWidget);
        btn_actualiser->setObjectName(QString::fromUtf8("btn_actualiser"));
        btn_actualiser->setGeometry(QRect(210, 180, 75, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 150, 161, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        heure = new QDateTimeEdit(layoutWidget);
        heure->setObjectName(QString::fromUtf8("heure"));

        horizontalLayout->addWidget(heure);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 50, 258, 94));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        textEditMessage = new QTextEdit(layoutWidget1);
        textEditMessage->setObjectName(QString::fromUtf8("textEditMessage"));
        textEditMessage->setFrameShape(QFrame::Panel);
        textEditMessage->setLineWidth(1);

        verticalLayout->addWidget(textEditMessage);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 723, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidgetCompagnonFidele->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBoxCompagnonFidele->setTitle(QApplication::translate("MainWindow", "Agent Hotel Manager", 0, QApplication::UnicodeUTF8));
        tabWidgetCompagnonFidele->setTabText(tabWidgetCompagnonFidele->indexOf(tab_3), QApplication::translate("MainWindow", "Je suis votre compagnon fid\303\250le!", 0, QApplication::UnicodeUTF8));
        btn_planifier->setText(QApplication::translate("MainWindow", "Planifier", 0, QApplication::UnicodeUTF8));
        btn_actualiser->setText(QApplication::translate("MainWindow", "Actualiser", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Date", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Message \303\240 afficher", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
