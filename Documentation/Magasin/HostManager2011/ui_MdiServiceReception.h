/********************************************************************************
** Form generated from reading UI file 'MdiServiceReception.ui'
**
** Created: Thu 15. Dec 13:54:13 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDISERVICERECEPTION_H
#define UI_MDISERVICERECEPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MdiServiceReception
{
public:
    QGridLayout *gridLayout_13;
    QFrame *frame_2;
    QGridLayout *gridLayout_11;
    QLabel *label_bienvenue;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QLabel *label_heureDeConnection;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGraphicsView *chambreGraphicsView;
    QFrame *frame;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxTypeCh;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_12;
    QTabWidget *tabWidgetEnregistrement;
    QWidget *tab;
    QGridLayout *gridLayout_9;
    QHBoxLayout *horizontalLayout_34;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QComboBox *comboBoxDureeOcc;
    QHBoxLayout *horizontalLayout_17;
    QSpinBox *spinBoxNbJoursOcc;
    QLabel *label_18;
    QLabel *label_NumeroClient;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *lineEditNomOcc;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_9;
    QLineEdit *lineEditPrenomOcc;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *lineEditContactOcc;
    QPushButton *btn_contactOcc;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QComboBox *comboBoxTypeClient;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QRadioButton *MasculinOccup;
    QRadioButton *FemininOccup;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_25;
    QLineEdit *lineEditTypeChAOccuper;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QComboBox *comboBoxIdentifiantCh;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLineEdit *lineEditPrixNuit;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    QLineEdit *lineEditPrixTotal;
    QLabel *label_14;
    QWidget *tab_2;
    QGridLayout *gridLayout_10;
    QLabel *label_NumeroReservation;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_20;
    QLineEdit *lineEditDateOccupReserv;
    QPushButton *btn_calendrier;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_29;
    QComboBox *comboBoxDureeJoursReserv;
    QHBoxLayout *horizontalLayout_22;
    QSpinBox *spinBoxNbJoursReserv;
    QLabel *label_22;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_30;
    QLineEdit *lineEditNomReserv;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_31;
    QLineEdit *lineEditPrenomReserv;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_32;
    QLineEdit *lineEditContactReserv;
    QPushButton *btn_contactReserv;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QRadioButton *MasculinReserv;
    QRadioButton *FemininReserv;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_23;
    QLineEdit *lineEditTypeChReserv;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_24;
    QComboBox *comboBoxIdentifiantChReserv;
    QSplitter *splitter_2;
    QPushButton *btn_enregistrer;
    QPushButton *btn_initialiser;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidgetCptService;
    QWidget *tabMessages;
    QGridLayout *gridLayout_4;
    QGraphicsView *compagnonGraphicsView;
    QWidget *tabHistorique;
    QGridLayout *gridLayout_14;
    QTextEdit *historiqueDesMsgs;
    QPushButton *btn_effacer;
    QWidget *tabSuggestions;
    QGridLayout *gridLayout_15;
    QTableWidget *tableWidgetSuggestions;
    QPushButton *btn_charger;

    void setupUi(QWidget *MdiServiceReception)
    {
        if (MdiServiceReception->objectName().isEmpty())
            MdiServiceReception->setObjectName(QString::fromUtf8("MdiServiceReception"));
        MdiServiceReception->resize(962, 642);
        MdiServiceReception->setMinimumSize(QSize(0, 0));
        gridLayout_13 = new QGridLayout(MdiServiceReception);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        frame_2 = new QFrame(MdiServiceReception);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_2);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_bienvenue = new QLabel(frame_2);
        label_bienvenue->setObjectName(QString::fromUtf8("label_bienvenue"));

        gridLayout_11->addWidget(label_bienvenue, 0, 0, 1, 1);


        gridLayout_13->addWidget(frame_2, 0, 0, 1, 1);

        frame_3 = new QFrame(MdiServiceReception);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setLayoutDirection(Qt::RightToLeft);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_heureDeConnection = new QLabel(frame_3);
        label_heureDeConnection->setObjectName(QString::fromUtf8("label_heureDeConnection"));

        gridLayout_7->addWidget(label_heureDeConnection, 0, 0, 1, 1);


        gridLayout_13->addWidget(frame_3, 0, 1, 1, 2);

        groupBox = new QGroupBox(MdiServiceReception);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        chambreGraphicsView = new QGraphicsView(groupBox);
        chambreGraphicsView->setObjectName(QString::fromUtf8("chambreGraphicsView"));

        gridLayout_2->addWidget(chambreGraphicsView, 0, 0, 1, 1);

        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 41));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(86, 0));

        horizontalLayout->addWidget(label);

        comboBoxTypeCh = new QComboBox(frame);
        comboBoxTypeCh->setObjectName(QString::fromUtf8("comboBoxTypeCh"));
        comboBoxTypeCh->setMinimumSize(QSize(74, 0));
        comboBoxTypeCh->setMaximumSize(QSize(16777215, 16777215));
        comboBoxTypeCh->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(comboBoxTypeCh);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);


        gridLayout_13->addWidget(groupBox, 1, 0, 1, 3);

        groupBox_3 = new QGroupBox(MdiServiceReception);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_12 = new QGridLayout(groupBox_3);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        tabWidgetEnregistrement = new QTabWidget(groupBox_3);
        tabWidgetEnregistrement->setObjectName(QString::fromUtf8("tabWidgetEnregistrement"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_9 = new QGridLayout(tab);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_13->addWidget(label_15);

        comboBoxDureeOcc = new QComboBox(tab);
        comboBoxDureeOcc->setObjectName(QString::fromUtf8("comboBoxDureeOcc"));

        horizontalLayout_13->addWidget(comboBoxDureeOcc);


        horizontalLayout_34->addLayout(horizontalLayout_13);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        spinBoxNbJoursOcc = new QSpinBox(tab);
        spinBoxNbJoursOcc->setObjectName(QString::fromUtf8("spinBoxNbJoursOcc"));
        spinBoxNbJoursOcc->setMinimum(1);
        spinBoxNbJoursOcc->setMaximum(30);
        spinBoxNbJoursOcc->setValue(1);

        horizontalLayout_17->addWidget(spinBoxNbJoursOcc);

        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_17->addWidget(label_18);


        horizontalLayout_34->addLayout(horizontalLayout_17);


        gridLayout_9->addLayout(horizontalLayout_34, 0, 0, 1, 1);

        label_NumeroClient = new QLabel(tab);
        label_NumeroClient->setObjectName(QString::fromUtf8("label_NumeroClient"));
        label_NumeroClient->setLayoutDirection(Qt::RightToLeft);

        gridLayout_9->addWidget(label_NumeroClient, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(34);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEditNomOcc = new QLineEdit(groupBox_4);
        lineEditNomOcc->setObjectName(QString::fromUtf8("lineEditNomOcc"));

        horizontalLayout_5->addWidget(lineEditNomOcc);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_16->addWidget(label_9);

        lineEditPrenomOcc = new QLineEdit(groupBox_4);
        lineEditPrenomOcc->setObjectName(QString::fromUtf8("lineEditPrenomOcc"));

        horizontalLayout_16->addWidget(lineEditPrenomOcc);


        gridLayout->addLayout(horizontalLayout_16, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        lineEditContactOcc = new QLineEdit(groupBox_4);
        lineEditContactOcc->setObjectName(QString::fromUtf8("lineEditContactOcc"));
        lineEditContactOcc->setReadOnly(true);

        horizontalLayout_6->addWidget(lineEditContactOcc);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        btn_contactOcc = new QPushButton(groupBox_4);
        btn_contactOcc->setObjectName(QString::fromUtf8("btn_contactOcc"));
        btn_contactOcc->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(btn_contactOcc, 2, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        comboBoxTypeClient = new QComboBox(groupBox_4);
        comboBoxTypeClient->setObjectName(QString::fromUtf8("comboBoxTypeClient"));

        horizontalLayout_8->addWidget(comboBoxTypeClient);


        gridLayout->addLayout(horizontalLayout_8, 3, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        MasculinOccup = new QRadioButton(groupBox_4);
        MasculinOccup->setObjectName(QString::fromUtf8("MasculinOccup"));

        horizontalLayout_3->addWidget(MasculinOccup);

        FemininOccup = new QRadioButton(groupBox_4);
        FemininOccup->setObjectName(QString::fromUtf8("FemininOccup"));

        horizontalLayout_3->addWidget(FemininOccup);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_8 = new QGridLayout(groupBox_5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_25 = new QLabel(groupBox_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_21->addWidget(label_25);

        lineEditTypeChAOccuper = new QLineEdit(groupBox_5);
        lineEditTypeChAOccuper->setObjectName(QString::fromUtf8("lineEditTypeChAOccuper"));
        lineEditTypeChAOccuper->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTypeChAOccuper->setReadOnly(true);

        horizontalLayout_21->addWidget(lineEditTypeChAOccuper);


        gridLayout_8->addLayout(horizontalLayout_21, 0, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        comboBoxIdentifiantCh = new QComboBox(groupBox_5);
        comboBoxIdentifiantCh->setObjectName(QString::fromUtf8("comboBoxIdentifiantCh"));

        horizontalLayout_9->addWidget(comboBoxIdentifiantCh);


        gridLayout_8->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_7->addWidget(label_11);

        lineEditPrixNuit = new QLineEdit(groupBox_5);
        lineEditPrixNuit->setObjectName(QString::fromUtf8("lineEditPrixNuit"));
        lineEditPrixNuit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPrixNuit->setReadOnly(true);

        horizontalLayout_7->addWidget(lineEditPrixNuit);


        gridLayout_8->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_8->addWidget(label_13, 2, 1, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(21);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_11->addWidget(label_12);

        lineEditPrixTotal = new QLineEdit(groupBox_5);
        lineEditPrixTotal->setObjectName(QString::fromUtf8("lineEditPrixTotal"));
        lineEditPrixTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPrixTotal->setReadOnly(true);

        horizontalLayout_11->addWidget(lineEditPrixTotal);


        gridLayout_8->addLayout(horizontalLayout_11, 3, 0, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_8->addWidget(label_14, 3, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_5, 1, 1, 1, 1);

        tabWidgetEnregistrement->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_10 = new QGridLayout(tab_2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_NumeroReservation = new QLabel(tab_2);
        label_NumeroReservation->setObjectName(QString::fromUtf8("label_NumeroReservation"));
        label_NumeroReservation->setLayoutDirection(Qt::RightToLeft);

        gridLayout_10->addWidget(label_NumeroReservation, 0, 2, 1, 2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_10->addWidget(label_20);

        lineEditDateOccupReserv = new QLineEdit(tab_2);
        lineEditDateOccupReserv->setObjectName(QString::fromUtf8("lineEditDateOccupReserv"));
        lineEditDateOccupReserv->setLayoutDirection(Qt::LeftToRight);
        lineEditDateOccupReserv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDateOccupReserv->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEditDateOccupReserv);


        gridLayout_10->addLayout(horizontalLayout_10, 1, 0, 1, 1);

        btn_calendrier = new QPushButton(tab_2);
        btn_calendrier->setObjectName(QString::fromUtf8("btn_calendrier"));
        btn_calendrier->setMaximumSize(QSize(30, 16777215));

        gridLayout_10->addWidget(btn_calendrier, 1, 1, 1, 1);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_29 = new QLabel(tab_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_24->addWidget(label_29);

        comboBoxDureeJoursReserv = new QComboBox(tab_2);
        comboBoxDureeJoursReserv->setObjectName(QString::fromUtf8("comboBoxDureeJoursReserv"));

        horizontalLayout_24->addWidget(comboBoxDureeJoursReserv);


        gridLayout_10->addLayout(horizontalLayout_24, 1, 2, 1, 1);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        spinBoxNbJoursReserv = new QSpinBox(tab_2);
        spinBoxNbJoursReserv->setObjectName(QString::fromUtf8("spinBoxNbJoursReserv"));
        spinBoxNbJoursReserv->setMinimum(1);
        spinBoxNbJoursReserv->setMaximum(30);

        horizontalLayout_22->addWidget(spinBoxNbJoursReserv);

        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_22->addWidget(label_22);


        gridLayout_10->addLayout(horizontalLayout_22, 1, 3, 1, 1);

        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_3 = new QGridLayout(groupBox_7);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(34);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_30 = new QLabel(groupBox_7);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        horizontalLayout_25->addWidget(label_30);

        lineEditNomReserv = new QLineEdit(groupBox_7);
        lineEditNomReserv->setObjectName(QString::fromUtf8("lineEditNomReserv"));

        horizontalLayout_25->addWidget(lineEditNomReserv);


        gridLayout_3->addLayout(horizontalLayout_25, 0, 0, 1, 1);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        label_31 = new QLabel(groupBox_7);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_26->addWidget(label_31);

        lineEditPrenomReserv = new QLineEdit(groupBox_7);
        lineEditPrenomReserv->setObjectName(QString::fromUtf8("lineEditPrenomReserv"));

        horizontalLayout_26->addWidget(lineEditPrenomReserv);


        gridLayout_3->addLayout(horizontalLayout_26, 1, 0, 1, 1);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(16);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_32 = new QLabel(groupBox_7);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_27->addWidget(label_32);

        lineEditContactReserv = new QLineEdit(groupBox_7);
        lineEditContactReserv->setObjectName(QString::fromUtf8("lineEditContactReserv"));
        lineEditContactReserv->setReadOnly(true);

        horizontalLayout_27->addWidget(lineEditContactReserv);


        gridLayout_3->addLayout(horizontalLayout_27, 2, 0, 1, 1);

        btn_contactReserv = new QPushButton(groupBox_7);
        btn_contactReserv->setObjectName(QString::fromUtf8("btn_contactReserv"));
        btn_contactReserv->setMaximumSize(QSize(30, 16777215));

        gridLayout_3->addWidget(btn_contactReserv, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_7);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        MasculinReserv = new QRadioButton(groupBox_7);
        MasculinReserv->setObjectName(QString::fromUtf8("MasculinReserv"));

        horizontalLayout_2->addWidget(MasculinReserv);

        FemininReserv = new QRadioButton(groupBox_7);
        FemininReserv->setObjectName(QString::fromUtf8("FemininReserv"));

        horizontalLayout_2->addWidget(FemininReserv);


        gridLayout_3->addLayout(horizontalLayout_2, 3, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_7, 2, 0, 1, 2);

        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_19->addWidget(label_23);

        lineEditTypeChReserv = new QLineEdit(groupBox_6);
        lineEditTypeChReserv->setObjectName(QString::fromUtf8("lineEditTypeChReserv"));
        lineEditTypeChReserv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTypeChReserv->setReadOnly(true);

        horizontalLayout_19->addWidget(lineEditTypeChReserv);


        gridLayout_6->addLayout(horizontalLayout_19, 0, 0, 1, 1);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_20->addWidget(label_24);

        comboBoxIdentifiantChReserv = new QComboBox(groupBox_6);
        comboBoxIdentifiantChReserv->setObjectName(QString::fromUtf8("comboBoxIdentifiantChReserv"));

        horizontalLayout_20->addWidget(comboBoxIdentifiantChReserv);


        gridLayout_6->addLayout(horizontalLayout_20, 1, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_6, 2, 2, 1, 2);

        tabWidgetEnregistrement->addTab(tab_2, QString());

        gridLayout_12->addWidget(tabWidgetEnregistrement, 0, 0, 1, 1);

        splitter_2 = new QSplitter(groupBox_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setLayoutDirection(Qt::RightToLeft);
        splitter_2->setOrientation(Qt::Horizontal);
        btn_enregistrer = new QPushButton(splitter_2);
        btn_enregistrer->setObjectName(QString::fromUtf8("btn_enregistrer"));
        btn_enregistrer->setMinimumSize(QSize(0, 23));
        btn_enregistrer->setMaximumSize(QSize(80, 16777215));
        splitter_2->addWidget(btn_enregistrer);
        btn_initialiser = new QPushButton(splitter_2);
        btn_initialiser->setObjectName(QString::fromUtf8("btn_initialiser"));
        btn_initialiser->setMinimumSize(QSize(0, 23));
        btn_initialiser->setMaximumSize(QSize(80, 16777215));
        splitter_2->addWidget(btn_initialiser);

        gridLayout_12->addWidget(splitter_2, 1, 0, 1, 1);


        gridLayout_13->addWidget(groupBox_3, 2, 0, 1, 2);

        groupBox_2 = new QGroupBox(MdiServiceReception);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(404, 303));
        groupBox_2->setLayoutDirection(Qt::LeftToRight);
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tabWidgetCptService = new QTabWidget(groupBox_2);
        tabWidgetCptService->setObjectName(QString::fromUtf8("tabWidgetCptService"));
        tabWidgetCptService->setLayoutDirection(Qt::LeftToRight);
        tabMessages = new QWidget();
        tabMessages->setObjectName(QString::fromUtf8("tabMessages"));
        gridLayout_4 = new QGridLayout(tabMessages);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        compagnonGraphicsView = new QGraphicsView(tabMessages);
        compagnonGraphicsView->setObjectName(QString::fromUtf8("compagnonGraphicsView"));
        compagnonGraphicsView->setMinimumSize(QSize(360, 225));
        compagnonGraphicsView->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(compagnonGraphicsView, 0, 0, 1, 1);

        tabWidgetCptService->addTab(tabMessages, QString());
        tabHistorique = new QWidget();
        tabHistorique->setObjectName(QString::fromUtf8("tabHistorique"));
        gridLayout_14 = new QGridLayout(tabHistorique);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        historiqueDesMsgs = new QTextEdit(tabHistorique);
        historiqueDesMsgs->setObjectName(QString::fromUtf8("historiqueDesMsgs"));
        historiqueDesMsgs->setReadOnly(true);

        gridLayout_14->addWidget(historiqueDesMsgs, 0, 0, 1, 1);

        btn_effacer = new QPushButton(tabHistorique);
        btn_effacer->setObjectName(QString::fromUtf8("btn_effacer"));
        btn_effacer->setMaximumSize(QSize(75, 23));
        btn_effacer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_14->addWidget(btn_effacer, 1, 0, 1, 1);

        tabWidgetCptService->addTab(tabHistorique, QString());
        tabSuggestions = new QWidget();
        tabSuggestions->setObjectName(QString::fromUtf8("tabSuggestions"));
        gridLayout_15 = new QGridLayout(tabSuggestions);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        tableWidgetSuggestions = new QTableWidget(tabSuggestions);
        if (tableWidgetSuggestions->columnCount() < 6)
            tableWidgetSuggestions->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetSuggestions->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetSuggestions->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetSuggestions->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetSuggestions->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetSuggestions->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetSuggestions->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidgetSuggestions->setObjectName(QString::fromUtf8("tableWidgetSuggestions"));
        tableWidgetSuggestions->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetSuggestions->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout_15->addWidget(tableWidgetSuggestions, 0, 0, 1, 1);

        btn_charger = new QPushButton(tabSuggestions);
        btn_charger->setObjectName(QString::fromUtf8("btn_charger"));
        btn_charger->setMaximumSize(QSize(75, 23));
        btn_charger->setLayoutDirection(Qt::RightToLeft);

        gridLayout_15->addWidget(btn_charger, 1, 0, 1, 1);

        tabWidgetCptService->addTab(tabSuggestions, QString());

        gridLayout_5->addWidget(tabWidgetCptService, 0, 0, 1, 1);


        gridLayout_13->addWidget(groupBox_2, 2, 2, 1, 1);


        retranslateUi(MdiServiceReception);

        tabWidgetEnregistrement->setCurrentIndex(0);
        tabWidgetCptService->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MdiServiceReception);
    } // setupUi

    void retranslateUi(QWidget *MdiServiceReception)
    {
        MdiServiceReception->setWindowTitle(QApplication::translate("MdiServiceReception", "Form", 0, QApplication::UnicodeUTF8));
        label_bienvenue->setText(QApplication::translate("MdiServiceReception", "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, QApplication::UnicodeUTF8));
        label_heureDeConnection->setText(QApplication::translate("MdiServiceReception", "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MdiServiceReception", "Etat des chambres", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MdiServiceReception", "Type de chambre:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MdiServiceReception", "Enregistrement des activit\303\251s", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MdiServiceReception", "Dur\303\251e d'occupation:", 0, QApplication::UnicodeUTF8));
        comboBoxDureeOcc->clear();
        comboBoxDureeOcc->insertItems(0, QStringList()
         << QApplication::translate("MdiServiceReception", "Une nuit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MdiServiceReception", "Un s\303\251jour", 0, QApplication::UnicodeUTF8)
        );
        label_18->setText(QApplication::translate("MdiServiceReception", "jour(s)", 0, QApplication::UnicodeUTF8));
        label_NumeroClient->setText(QApplication::translate("MdiServiceReception", "Client N\302\260 000", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MdiServiceReception", "Identification du client", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MdiServiceReception", "Nom:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MdiServiceReception", "Pr\303\251nom(s):", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MdiServiceReception", "Contacts:", 0, QApplication::UnicodeUTF8));
        btn_contactOcc->setText(QApplication::translate("MdiServiceReception", "...", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MdiServiceReception", "Type de client:", 0, QApplication::UnicodeUTF8));
        comboBoxTypeClient->clear();
        comboBoxTypeClient->insertItems(0, QStringList()
         << QApplication::translate("MdiServiceReception", "Normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MdiServiceReception", "Privil\303\251gi\303\251", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MdiServiceReception", "Fid\303\250le", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("MdiServiceReception", "Sexe:", 0, QApplication::UnicodeUTF8));
        MasculinOccup->setText(QApplication::translate("MdiServiceReception", "Masculin", 0, QApplication::UnicodeUTF8));
        FemininOccup->setText(QApplication::translate("MdiServiceReception", "F\303\251minin", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MdiServiceReception", "Chambre \303\240 occuper", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MdiServiceReception", "Type:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MdiServiceReception", "Identifiant:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MdiServiceReception", "Prix d'une nuit:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MdiServiceReception", "FCFA", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MdiServiceReception", "Prix totale:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MdiServiceReception", "FCFA", 0, QApplication::UnicodeUTF8));
        tabWidgetEnregistrement->setTabText(tabWidgetEnregistrement->indexOf(tab), QApplication::translate("MdiServiceReception", "Occuper une chambre", 0, QApplication::UnicodeUTF8));
        label_NumeroReservation->setText(QApplication::translate("MdiServiceReception", "R\303\251servation N\302\260 00", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MdiServiceReception", "Date d'occupation :", 0, QApplication::UnicodeUTF8));
        btn_calendrier->setText(QApplication::translate("MdiServiceReception", "...", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MdiServiceReception", "Dur\303\251e d'occupation:", 0, QApplication::UnicodeUTF8));
        comboBoxDureeJoursReserv->clear();
        comboBoxDureeJoursReserv->insertItems(0, QStringList()
         << QApplication::translate("MdiServiceReception", "Une nuit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MdiServiceReception", "Un s\303\251jour", 0, QApplication::UnicodeUTF8)
        );
        label_22->setText(QApplication::translate("MdiServiceReception", "jour(s)", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MdiServiceReception", "Identification du client", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MdiServiceReception", "Nom:", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MdiServiceReception", "Pr\303\251nom(s):", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MdiServiceReception", "Contact:", 0, QApplication::UnicodeUTF8));
        btn_contactReserv->setText(QApplication::translate("MdiServiceReception", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MdiServiceReception", "Sexe:", 0, QApplication::UnicodeUTF8));
        MasculinReserv->setText(QApplication::translate("MdiServiceReception", "Masculin", 0, QApplication::UnicodeUTF8));
        FemininReserv->setText(QApplication::translate("MdiServiceReception", "F\303\251minin", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MdiServiceReception", "Chambre \303\240 r\303\251server", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MdiServiceReception", "Type:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MdiServiceReception", "Identifiant:", 0, QApplication::UnicodeUTF8));
        tabWidgetEnregistrement->setTabText(tabWidgetEnregistrement->indexOf(tab_2), QApplication::translate("MdiServiceReception", "R\303\251server une chambre", 0, QApplication::UnicodeUTF8));
        btn_enregistrer->setText(QApplication::translate("MdiServiceReception", "Enregistrer", 0, QApplication::UnicodeUTF8));
        btn_initialiser->setText(QApplication::translate("MdiServiceReception", "Initialiser", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MdiServiceReception", "Agent Hotel Manager", 0, QApplication::UnicodeUTF8));
        tabWidgetCptService->setTabText(tabWidgetCptService->indexOf(tabMessages), QApplication::translate("MdiServiceReception", "Messages", 0, QApplication::UnicodeUTF8));
        btn_effacer->setText(QApplication::translate("MdiServiceReception", "Effacer", 0, QApplication::UnicodeUTF8));
        tabWidgetCptService->setTabText(tabWidgetCptService->indexOf(tabHistorique), QApplication::translate("MdiServiceReception", "Historique des messages", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetSuggestions->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MdiServiceReception", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetSuggestions->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MdiServiceReception", "Nom", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetSuggestions->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MdiServiceReception", "Sexe", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetSuggestions->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MdiServiceReception", "Cel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetSuggestions->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MdiServiceReception", "Type actuel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetSuggestions->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MdiServiceReception", "Type conseill\303\251", 0, QApplication::UnicodeUTF8));
        btn_charger->setText(QApplication::translate("MdiServiceReception", "Charger", 0, QApplication::UnicodeUTF8));
        tabWidgetCptService->setTabText(tabWidgetCptService->indexOf(tabSuggestions), QApplication::translate("MdiServiceReception", "Suggestions", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MdiServiceReception: public Ui_MdiServiceReception {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDISERVICERECEPTION_H
