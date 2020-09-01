/********************************************************************************
** Form generated from reading UI file 'FenServiceReception.ui'
**
** Created: Sun 25. Sep 09:08:59 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENSERVICERECEPTION_H
#define UI_FENSERVICERECEPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenServiceReception
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QPushButton *btn_contactOcc;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditNomOcc;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditContactOcc;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxFemme;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBoxTypeClient;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_2;
    QLineEdit *lineEditPrenomOcc;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLineEdit *lineEditPrixNuit;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    QLineEdit *lineEditPrixTotal;
    QLabel *label_14;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_25;
    QLineEdit *lineEditTypeChAOccuper;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QComboBox *comboBoxIdentifiantCh;
    QPushButton *btn_initialiser;
    QPushButton *btn_occuper;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *comboBoxDureeOcc;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QDateTimeEdit *dateTimeEditDateEntree;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLabel *labelNumeroClient;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinBoxNbJoursOcc;
    QLabel *label_7;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_22;
    QWidget *tab_2;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget9;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_23;
    QLineEdit *lineEditTypeChReserv;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_24;
    QComboBox *comboBoxIdChReserv;
    QGroupBox *groupBox_5;
    QPushButton *btn_contactReserv;
    QWidget *layoutWidget10;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_32;
    QLineEdit *lineEditContactReserv;
    QWidget *layoutWidget11;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_30;
    QLineEdit *lineEditNomReserv;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_31;
    QLineEdit *lineEditPrenomReserv;
    QCheckBox *checkBoxSexeReserv;
    QPushButton *btn_initialiserReserv;
    QPushButton *btn_reserver;
    QPushButton *btn_calendrier;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_29;
    QComboBox *comboBoxDureeJoursReserv;
    QWidget *layoutWidget12;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_20;
    QLineEdit *lineEditDateOccupReserv;
    QWidget *layoutWidget13;
    QHBoxLayout *horizontalLayout_18;
    QSpinBox *spinBoxNbJoursReserv;
    QLabel *label_22;
    QWidget *layoutWidget14;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLabel *labelNbDeReserv;
    QFrame *frame;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_15;
    QLabel *labelSalutation;
    QLabel *labelNomComplet;
    QWidget *layoutWidget15;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_17;
    QLabel *labelDateTime;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_23;
    QGroupBox *groupBox;
    QGraphicsView *graphicsView_2;
    QComboBox *comboBoxTypeChGraphic_2;

    void setupUi(QWidget *FenServiceReception)
    {
        if (FenServiceReception->objectName().isEmpty())
            FenServiceReception->setObjectName(QString::fromUtf8("FenServiceReception"));
        FenServiceReception->resize(950, 600);
        tabWidget = new QTabWidget(FenServiceReception);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 320, 511, 271));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 70, 231, 141));
        btn_contactOcc = new QPushButton(groupBox_2);
        btn_contactOcc->setObjectName(QString::fromUtf8("btn_contactOcc"));
        btn_contactOcc->setGeometry(QRect(200, 110, 21, 23));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 194, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(34);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditNomOcc = new QLineEdit(layoutWidget);
        lineEditNomOcc->setObjectName(QString::fromUtf8("lineEditNomOcc"));

        horizontalLayout->addWidget(lineEditNomOcc);

        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 112, 183, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditContactOcc = new QLineEdit(layoutWidget1);
        lineEditContactOcc->setObjectName(QString::fromUtf8("lineEditContactOcc"));
        lineEditContactOcc->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditContactOcc);

        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 21, 217, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBoxFemme = new QCheckBox(layoutWidget2);
        checkBoxFemme->setObjectName(QString::fromUtf8("checkBoxFemme"));

        horizontalLayout_2->addWidget(checkBoxFemme);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBoxTypeClient = new QComboBox(layoutWidget2);
        comboBoxTypeClient->setObjectName(QString::fromUtf8("comboBoxTypeClient"));

        horizontalLayout_4->addWidget(comboBoxTypeClient);


        horizontalLayout_2->addLayout(horizontalLayout_4);

        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 80, 194, 22));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_16->addWidget(label_2);

        lineEditPrenomOcc = new QLineEdit(layoutWidget3);
        lineEditPrenomOcc->setObjectName(QString::fromUtf8("lineEditPrenomOcc"));

        horizontalLayout_16->addWidget(lineEditPrenomOcc);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(260, 70, 231, 141));
        layoutWidget4 = new QWidget(groupBox_3);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 80, 191, 54));
        verticalLayout_2 = new QVBoxLayout(layoutWidget4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_10->addWidget(label_11);

        lineEditPrixNuit = new QLineEdit(layoutWidget4);
        lineEditPrixNuit->setObjectName(QString::fromUtf8("lineEditPrixNuit"));
        lineEditPrixNuit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPrixNuit->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEditPrixNuit);

        label_13 = new QLabel(layoutWidget4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_10->addWidget(label_13);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(21);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_12 = new QLabel(layoutWidget4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_11->addWidget(label_12);

        lineEditPrixTotal = new QLineEdit(layoutWidget4);
        lineEditPrixTotal->setObjectName(QString::fromUtf8("lineEditPrixTotal"));
        lineEditPrixTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPrixTotal->setReadOnly(true);

        horizontalLayout_11->addWidget(lineEditPrixTotal);


        horizontalLayout_12->addLayout(horizontalLayout_11);

        label_14 = new QLabel(layoutWidget4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_12->addWidget(label_14);


        verticalLayout_2->addLayout(horizontalLayout_12);

        layoutWidget5 = new QWidget(groupBox_3);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(30, 20, 161, 52));
        verticalLayout_3 = new QVBoxLayout(layoutWidget5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_25 = new QLabel(layoutWidget5);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_21->addWidget(label_25);

        lineEditTypeChAOccuper = new QLineEdit(layoutWidget5);
        lineEditTypeChAOccuper->setObjectName(QString::fromUtf8("lineEditTypeChAOccuper"));
        lineEditTypeChAOccuper->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTypeChAOccuper->setReadOnly(true);

        horizontalLayout_21->addWidget(lineEditTypeChAOccuper);


        verticalLayout_3->addLayout(horizontalLayout_21);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(layoutWidget5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        comboBoxIdentifiantCh = new QComboBox(layoutWidget5);
        comboBoxIdentifiantCh->setObjectName(QString::fromUtf8("comboBoxIdentifiantCh"));

        horizontalLayout_9->addWidget(comboBoxIdentifiantCh);


        verticalLayout_3->addLayout(horizontalLayout_9);

        btn_initialiser = new QPushButton(tab);
        btn_initialiser->setObjectName(QString::fromUtf8("btn_initialiser"));
        btn_initialiser->setGeometry(QRect(330, 220, 75, 23));
        btn_occuper = new QPushButton(tab);
        btn_occuper->setObjectName(QString::fromUtf8("btn_occuper"));
        btn_occuper->setGeometry(QRect(410, 220, 75, 23));
        layoutWidget_8 = new QWidget(tab);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(240, 40, 181, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        comboBoxDureeOcc = new QComboBox(layoutWidget_8);
        comboBoxDureeOcc->setObjectName(QString::fromUtf8("comboBoxDureeOcc"));

        horizontalLayout_5->addWidget(comboBoxDureeOcc);

        layoutWidget6 = new QWidget(tab);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 40, 208, 22));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget6);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        dateTimeEditDateEntree = new QDateTimeEdit(layoutWidget6);
        dateTimeEditDateEntree->setObjectName(QString::fromUtf8("dateTimeEditDateEntree"));
        dateTimeEditDateEntree->setReadOnly(true);

        horizontalLayout_7->addWidget(dateTimeEditDateEntree);

        layoutWidget7 = new QWidget(tab);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(430, 0, 81, 20));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget7);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_13->addWidget(label_15);

        labelNumeroClient = new QLabel(layoutWidget7);
        labelNumeroClient->setObjectName(QString::fromUtf8("labelNumeroClient"));

        horizontalLayout_13->addWidget(labelNumeroClient);

        layoutWidget8 = new QWidget(tab);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(420, 41, 78, 22));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        spinBoxNbJoursOcc = new QSpinBox(layoutWidget8);
        spinBoxNbJoursOcc->setObjectName(QString::fromUtf8("spinBoxNbJoursOcc"));
        spinBoxNbJoursOcc->setMinimum(1);
        spinBoxNbJoursOcc->setMaximum(30);
        spinBoxNbJoursOcc->setValue(1);

        horizontalLayout_6->addWidget(spinBoxNbJoursOcc);

        label_7 = new QLabel(layoutWidget8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, -20, 171, 101));
        horizontalLayout_22 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(260, 100, 231, 91));
        layoutWidget9 = new QWidget(groupBox_4);
        layoutWidget9->setObjectName(QString::fromUtf8("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(31, 20, 170, 52));
        verticalLayout_4 = new QVBoxLayout(layoutWidget9);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_23 = new QLabel(layoutWidget9);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_19->addWidget(label_23);

        lineEditTypeChReserv = new QLineEdit(layoutWidget9);
        lineEditTypeChReserv->setObjectName(QString::fromUtf8("lineEditTypeChReserv"));
        lineEditTypeChReserv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTypeChReserv->setReadOnly(true);

        horizontalLayout_19->addWidget(lineEditTypeChReserv);


        verticalLayout_4->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_24 = new QLabel(layoutWidget9);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_20->addWidget(label_24);

        comboBoxIdChReserv = new QComboBox(layoutWidget9);
        comboBoxIdChReserv->setObjectName(QString::fromUtf8("comboBoxIdChReserv"));

        horizontalLayout_20->addWidget(comboBoxIdChReserv);


        verticalLayout_4->addLayout(horizontalLayout_20);

        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 80, 231, 131));
        btn_contactReserv = new QPushButton(groupBox_5);
        btn_contactReserv->setObjectName(QString::fromUtf8("btn_contactReserv"));
        btn_contactReserv->setGeometry(QRect(180, 100, 21, 23));
        layoutWidget10 = new QWidget(groupBox_5);
        layoutWidget10->setObjectName(QString::fromUtf8("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(11, 100, 161, 22));
        horizontalLayout_27 = new QHBoxLayout(layoutWidget10);
        horizontalLayout_27->setSpacing(16);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(0, 0, 0, 0);
        label_32 = new QLabel(layoutWidget10);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_27->addWidget(label_32);

        lineEditContactReserv = new QLineEdit(layoutWidget10);
        lineEditContactReserv->setObjectName(QString::fromUtf8("lineEditContactReserv"));
        lineEditContactReserv->setReadOnly(true);

        horizontalLayout_27->addWidget(lineEditContactReserv);

        layoutWidget11 = new QWidget(groupBox_5);
        layoutWidget11->setObjectName(QString::fromUtf8("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(11, 40, 196, 52));
        verticalLayout_5 = new QVBoxLayout(layoutWidget11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(34);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_30 = new QLabel(layoutWidget11);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_25->addWidget(label_30);

        lineEditNomReserv = new QLineEdit(layoutWidget11);
        lineEditNomReserv->setObjectName(QString::fromUtf8("lineEditNomReserv"));

        horizontalLayout_25->addWidget(lineEditNomReserv);


        verticalLayout_5->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_31 = new QLabel(layoutWidget11);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_26->addWidget(label_31);

        lineEditPrenomReserv = new QLineEdit(layoutWidget11);
        lineEditPrenomReserv->setObjectName(QString::fromUtf8("lineEditPrenomReserv"));

        horizontalLayout_26->addWidget(lineEditPrenomReserv);


        verticalLayout_5->addLayout(horizontalLayout_26);

        checkBoxSexeReserv = new QCheckBox(groupBox_5);
        checkBoxSexeReserv->setObjectName(QString::fromUtf8("checkBoxSexeReserv"));
        checkBoxSexeReserv->setGeometry(QRect(150, 20, 61, 18));
        btn_initialiserReserv = new QPushButton(tab_2);
        btn_initialiserReserv->setObjectName(QString::fromUtf8("btn_initialiserReserv"));
        btn_initialiserReserv->setGeometry(QRect(320, 220, 75, 23));
        btn_reserver = new QPushButton(tab_2);
        btn_reserver->setObjectName(QString::fromUtf8("btn_reserver"));
        btn_reserver->setGeometry(QRect(410, 220, 75, 23));
        btn_calendrier = new QPushButton(tab_2);
        btn_calendrier->setObjectName(QString::fromUtf8("btn_calendrier"));
        btn_calendrier->setGeometry(QRect(230, 50, 21, 23));
        layoutWidget_5 = new QWidget(tab_2);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 20, 181, 22));
        horizontalLayout_24 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_24->setContentsMargins(0, 0, 0, 0);
        label_29 = new QLabel(layoutWidget_5);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_24->addWidget(label_29);

        comboBoxDureeJoursReserv = new QComboBox(layoutWidget_5);
        comboBoxDureeJoursReserv->setObjectName(QString::fromUtf8("comboBoxDureeJoursReserv"));

        horizontalLayout_24->addWidget(comboBoxDureeJoursReserv);

        layoutWidget12 = new QWidget(tab_2);
        layoutWidget12->setObjectName(QString::fromUtf8("layoutWidget12"));
        layoutWidget12->setGeometry(QRect(12, 50, 211, 22));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget12);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(layoutWidget12);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_17->addWidget(label_20);

        lineEditDateOccupReserv = new QLineEdit(layoutWidget12);
        lineEditDateOccupReserv->setObjectName(QString::fromUtf8("lineEditDateOccupReserv"));
        lineEditDateOccupReserv->setLayoutDirection(Qt::LeftToRight);
        lineEditDateOccupReserv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDateOccupReserv->setReadOnly(true);

        horizontalLayout_17->addWidget(lineEditDateOccupReserv);

        layoutWidget13 = new QWidget(tab_2);
        layoutWidget13->setObjectName(QString::fromUtf8("layoutWidget13"));
        layoutWidget13->setGeometry(QRect(190, 20, 78, 22));
        horizontalLayout_18 = new QHBoxLayout(layoutWidget13);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        spinBoxNbJoursReserv = new QSpinBox(layoutWidget13);
        spinBoxNbJoursReserv->setObjectName(QString::fromUtf8("spinBoxNbJoursReserv"));
        spinBoxNbJoursReserv->setMinimum(1);
        spinBoxNbJoursReserv->setMaximum(30);

        horizontalLayout_18->addWidget(spinBoxNbJoursReserv);

        label_22 = new QLabel(layoutWidget13);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_18->addWidget(label_22);

        layoutWidget14 = new QWidget(tab_2);
        layoutWidget14->setObjectName(QString::fromUtf8("layoutWidget14"));
        layoutWidget14->setGeometry(QRect(400, 10, 93, 15));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget14);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget14);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        labelNbDeReserv = new QLabel(layoutWidget14);
        labelNbDeReserv->setObjectName(QString::fromUtf8("labelNbDeReserv"));

        horizontalLayout_8->addWidget(labelNbDeReserv);

        tabWidget->addTab(tab_2, QString());
        frame = new QFrame(FenServiceReception);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 931, 16));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 289, 15));
        horizontalLayout_15 = new QHBoxLayout(widget);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        labelSalutation = new QLabel(widget);
        labelSalutation->setObjectName(QString::fromUtf8("labelSalutation"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setBold(true);
        font.setWeight(75);
        labelSalutation->setFont(font);

        horizontalLayout_15->addWidget(labelSalutation);

        labelNomComplet = new QLabel(widget);
        labelNomComplet->setObjectName(QString::fromUtf8("labelNomComplet"));
        labelNomComplet->setFont(font);
        labelNomComplet->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        labelNomComplet->setWordWrap(false);

        horizontalLayout_15->addWidget(labelNomComplet);

        layoutWidget15 = new QWidget(frame);
        layoutWidget15->setObjectName(QString::fromUtf8("layoutWidget15"));
        layoutWidget15->setGeometry(QRect(590, 0, 338, 15));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget15);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget15);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_14->addWidget(label_17);

        labelDateTime = new QLabel(layoutWidget15);
        labelDateTime->setObjectName(QString::fromUtf8("labelDateTime"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        labelDateTime->setFont(font1);

        horizontalLayout_14->addWidget(labelDateTime);

        horizontalLayoutWidget_2 = new QWidget(FenServiceReception);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 40, 931, 271));
        horizontalLayout_23 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(FenServiceReception);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 921, 261));
        graphicsView_2 = new QGraphicsView(groupBox);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(10, 20, 911, 201));
        comboBoxTypeChGraphic_2 = new QComboBox(groupBox);
        comboBoxTypeChGraphic_2->setObjectName(QString::fromUtf8("comboBoxTypeChGraphic_2"));
        comboBoxTypeChGraphic_2->setGeometry(QRect(800, 230, 123, 20));
        comboBoxTypeChGraphic_2->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        retranslateUi(FenServiceReception);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FenServiceReception);
    } // setupUi

    void retranslateUi(QWidget *FenServiceReception)
    {
        FenServiceReception->setWindowTitle(QApplication::translate("FenServiceReception", "Bienvenue au service R\303\251ception", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("FenServiceReception", "Identification du client", 0, QApplication::UnicodeUTF8));
        btn_contactOcc->setText(QApplication::translate("FenServiceReception", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FenServiceReception", "Nom:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FenServiceReception", "Contacts:", 0, QApplication::UnicodeUTF8));
        checkBoxFemme->setText(QApplication::translate("FenServiceReception", "Femme", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FenServiceReception", "Type de client:", 0, QApplication::UnicodeUTF8));
        comboBoxTypeClient->clear();
        comboBoxTypeClient->insertItems(0, QStringList()
         << QApplication::translate("FenServiceReception", "Normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FenServiceReception", "Privil\303\251gi\303\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FenServiceReception", "Fid\303\250le", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("FenServiceReception", "Pr\303\251nom(s):", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("FenServiceReception", "Chambre \303\240 occuper", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("FenServiceReception", "Prix d'une nuit:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("FenServiceReception", "FCFA", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("FenServiceReception", "Prix totale:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("FenServiceReception", "FCFA", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("FenServiceReception", "Type:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("FenServiceReception", "Identifiant:", 0, QApplication::UnicodeUTF8));
        btn_initialiser->setText(QApplication::translate("FenServiceReception", "Initialiser", 0, QApplication::UnicodeUTF8));
        btn_occuper->setText(QApplication::translate("FenServiceReception", "Occuper", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("FenServiceReception", "Dur\303\251e d'occupation:", 0, QApplication::UnicodeUTF8));
        comboBoxDureeOcc->clear();
        comboBoxDureeOcc->insertItems(0, QStringList()
         << QApplication::translate("FenServiceReception", "Une nuit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FenServiceReception", "Un s\303\251jour", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("FenServiceReception", "Date d'entr\303\251e", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("FenServiceReception", "Client N\302\260", 0, QApplication::UnicodeUTF8));
        labelNumeroClient->setText(QApplication::translate("FenServiceReception", "000", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("FenServiceReception", "jours", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FenServiceReception", "Occuper une chambre", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("FenServiceReception", "Chambre \303\240 occuper", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("FenServiceReception", "Type:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("FenServiceReception", "Identifiant:", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("FenServiceReception", "Identification du client", 0, QApplication::UnicodeUTF8));
        btn_contactReserv->setText(QApplication::translate("FenServiceReception", "...", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("FenServiceReception", "Contact:", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("FenServiceReception", "Nom:", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("FenServiceReception", "Pr\303\251nom(s):", 0, QApplication::UnicodeUTF8));
        checkBoxSexeReserv->setText(QApplication::translate("FenServiceReception", "Femme", 0, QApplication::UnicodeUTF8));
        btn_initialiserReserv->setText(QApplication::translate("FenServiceReception", "Initialiser", 0, QApplication::UnicodeUTF8));
        btn_reserver->setText(QApplication::translate("FenServiceReception", "R\303\251server", 0, QApplication::UnicodeUTF8));
        btn_calendrier->setText(QApplication::translate("FenServiceReception", "...", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("FenServiceReception", "Dur\303\251e d'occupation:", 0, QApplication::UnicodeUTF8));
        comboBoxDureeJoursReserv->clear();
        comboBoxDureeJoursReserv->insertItems(0, QStringList()
         << QApplication::translate("FenServiceReception", "Une nuit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FenServiceReception", "Un s\303\251jour", 0, QApplication::UnicodeUTF8)
        );
        label_20->setText(QApplication::translate("FenServiceReception", "Date d'occupation :", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("FenServiceReception", "jours", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("FenServiceReception", "R\303\251servation N\302\260", 0, QApplication::UnicodeUTF8));
        labelNbDeReserv->setText(QApplication::translate("FenServiceReception", "00", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("FenServiceReception", "R\303\251server une chambre", 0, QApplication::UnicodeUTF8));
        labelSalutation->setText(QApplication::translate("FenServiceReception", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400;\">Bienvenue</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelNomComplet->setText(QApplication::translate("FenServiceReception", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("FenServiceReception", "Vous \303\252tes connect\303\251s depuis", 0, QApplication::UnicodeUTF8));
        labelDateTime->setText(QApplication::translate("FenServiceReception", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">jjjjjjjj JJ xxxxxxxx aaaa \303\240 00:00:00</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FenServiceReception", "Etat des chambres", 0, QApplication::UnicodeUTF8));
        comboBoxTypeChGraphic_2->clear();
        comboBoxTypeChGraphic_2->insertItems(0, QStringList()
         << QApplication::translate("FenServiceReception", "Chambre ventil\303\251e", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FenServiceReception", "Chambre climatis\303\251e", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FenServiceReception", "Suite", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class FenServiceReception: public Ui_FenServiceReception {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENSERVICERECEPTION_H
