/********************************************************************************
** Form generated from reading UI file 'MdiPlanning.ui'
**
** Created: Sun 27. Oct 20:00:19 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDIPLANNING_H
#define UI_MDIPLANNING_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MdiPlanning
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QTableWidget *tableWidgetPlanning;
    QFrame *frame;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditDateDebut;
    QLabel *label_2;
    QFormLayout *formLayout_2;
    QLineEdit *lineEditDateFin;
    QToolButton *btn_setPeriodeReserv;
    QFormLayout *formLayout_6;
    QLabel *label_3;
    QLineEdit *lineEditDuree;
    QWidget *tab_5;
    QGridLayout *gridLayout_8;
    QTableWidget *tableWidgetPlanningOccup;
    QFrame *frame_2;
    QGridLayout *gridLayout_7;
    QFormLayout *formLayout_12;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLineEdit *lineEditDateDebutOccup;
    QLabel *label_9;
    QFormLayout *formLayout_18;
    QLineEdit *lineEditDateFinOccup;
    QToolButton *btn_setPeriodeOccup;
    QFormLayout *formLayout_19;
    QLabel *label_10;
    QLineEdit *lineEditDureeOccup;
    QWidget *tabFacturesDeCeJour;
    QGridLayout *gridLayout_6;
    QTableWidget *tableWidgetFacturesDeJour;
    QFormLayout *formLayout_14;
    QFormLayout *formLayout_11;
    QLabel *label_7;
    QLineEdit *lineEditMontantEncaisse;
    QFormLayout *formLayout_13;
    QLabel *label_6;
    QLineEdit *lineEditMontantRestantDeCeJour;
    QPushButton *btn_imprimerFactureDeCeJour;
    QWidget *tabFacturesNonReglees;
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidgetFactures;
    QFormLayout *formLayout_9;
    QLabel *label_5;
    QLineEdit *lineEditMontantRestant;
    QFormLayout *formLayout_10;
    QPushButton *btn_reglerFacture;
    QPushButton *btn_imprimerFacture;
    QWidget *tabActivites;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_21;
    QFormLayout *formLayout_8;
    QLineEdit *lineEditMontantTotalEncaisse;
    QLabel *label_4;
    QFormLayout *formLayout_20;
    QLabel *label_11;
    QLineEdit *lineEditMontantTotalRetire;
    QFormLayout *formLayout_7;
    QPushButton *btn_imprimerRecu;
    QPushButton *btn_cloturer;
    QTableView *tableViewActivites;

    void setupUi(QWidget *MdiPlanning)
    {
        if (MdiPlanning->objectName().isEmpty())
            MdiPlanning->setObjectName(QString::fromUtf8("MdiPlanning"));
        MdiPlanning->resize(864, 571);
        gridLayout_2 = new QGridLayout(MdiPlanning);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(MdiPlanning);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tableWidgetPlanning = new QTableWidget(tab);
        if (tableWidgetPlanning->columnCount() < 7)
            tableWidgetPlanning->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetPlanning->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetPlanning->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetPlanning->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetPlanning->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetPlanning->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetPlanning->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetPlanning->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidgetPlanning->rowCount() < 8)
            tableWidgetPlanning->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetPlanning->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetPlanning->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetPlanning->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetPlanning->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetPlanning->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetPlanning->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetPlanning->setVerticalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetPlanning->setVerticalHeaderItem(7, __qtablewidgetitem14);
        tableWidgetPlanning->setObjectName(QString::fromUtf8("tableWidgetPlanning"));
        tableWidgetPlanning->setSelectionMode(QAbstractItemView::ContiguousSelection);
        tableWidgetPlanning->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_5->addWidget(tableWidgetPlanning, 0, 0, 1, 1);

        frame = new QFrame(tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lineEditDateDebut = new QLineEdit(frame);
        lineEditDateDebut->setObjectName(QString::fromUtf8("lineEditDateDebut"));
        lineEditDateDebut->setMinimumSize(QSize(160, 0));
        lineEditDateDebut->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDateDebut->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditDateDebut);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        lineEditDateFin = new QLineEdit(frame);
        lineEditDateFin->setObjectName(QString::fromUtf8("lineEditDateFin"));
        lineEditDateFin->setMinimumSize(QSize(160, 0));
        lineEditDateFin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDateFin->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lineEditDateFin);

        btn_setPeriodeReserv = new QToolButton(frame);
        btn_setPeriodeReserv->setObjectName(QString::fromUtf8("btn_setPeriodeReserv"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_setPeriodeReserv);


        formLayout->setLayout(0, QFormLayout::FieldRole, formLayout_2);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_6->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEditDuree = new QLineEdit(frame);
        lineEditDuree->setObjectName(QString::fromUtf8("lineEditDuree"));
        lineEditDuree->setMaximumSize(QSize(180, 16777215));
        lineEditDuree->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDuree->setReadOnly(true);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, lineEditDuree);


        gridLayout->addLayout(formLayout_6, 0, 1, 1, 1);


        gridLayout_5->addWidget(frame, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_8 = new QGridLayout(tab_5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        tableWidgetPlanningOccup = new QTableWidget(tab_5);
        if (tableWidgetPlanningOccup->columnCount() < 7)
            tableWidgetPlanningOccup->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setHorizontalHeaderItem(6, __qtablewidgetitem21);
        if (tableWidgetPlanningOccup->rowCount() < 8)
            tableWidgetPlanningOccup->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setVerticalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setVerticalHeaderItem(1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setVerticalHeaderItem(2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setVerticalHeaderItem(3, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setVerticalHeaderItem(4, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setVerticalHeaderItem(5, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setVerticalHeaderItem(6, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidgetPlanningOccup->setVerticalHeaderItem(7, __qtablewidgetitem29);
        tableWidgetPlanningOccup->setObjectName(QString::fromUtf8("tableWidgetPlanningOccup"));
        tableWidgetPlanningOccup->setSelectionMode(QAbstractItemView::ContiguousSelection);
        tableWidgetPlanningOccup->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_8->addWidget(tableWidgetPlanningOccup, 0, 0, 1, 1);

        frame_2 = new QFrame(tab_5);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        formLayout_12 = new QFormLayout();
        formLayout_12->setObjectName(QString::fromUtf8("formLayout_12"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        lineEditDateDebutOccup = new QLineEdit(frame_2);
        lineEditDateDebutOccup->setObjectName(QString::fromUtf8("lineEditDateDebutOccup"));
        lineEditDateDebutOccup->setMinimumSize(QSize(160, 0));
        lineEditDateDebutOccup->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDateDebutOccup->setReadOnly(true);

        horizontalLayout->addWidget(lineEditDateDebutOccup);


        horizontalLayout_2->addLayout(horizontalLayout);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_2->addWidget(label_9);


        formLayout_12->setLayout(0, QFormLayout::LabelRole, horizontalLayout_2);

        formLayout_18 = new QFormLayout();
        formLayout_18->setObjectName(QString::fromUtf8("formLayout_18"));
        lineEditDateFinOccup = new QLineEdit(frame_2);
        lineEditDateFinOccup->setObjectName(QString::fromUtf8("lineEditDateFinOccup"));
        lineEditDateFinOccup->setMinimumSize(QSize(160, 0));
        lineEditDateFinOccup->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDateFinOccup->setReadOnly(true);

        formLayout_18->setWidget(0, QFormLayout::LabelRole, lineEditDateFinOccup);

        btn_setPeriodeOccup = new QToolButton(frame_2);
        btn_setPeriodeOccup->setObjectName(QString::fromUtf8("btn_setPeriodeOccup"));

        formLayout_18->setWidget(0, QFormLayout::FieldRole, btn_setPeriodeOccup);


        formLayout_12->setLayout(0, QFormLayout::FieldRole, formLayout_18);


        gridLayout_7->addLayout(formLayout_12, 0, 0, 1, 1);

        formLayout_19 = new QFormLayout();
        formLayout_19->setObjectName(QString::fromUtf8("formLayout_19"));
        formLayout_19->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_19->setWidget(0, QFormLayout::LabelRole, label_10);

        lineEditDureeOccup = new QLineEdit(frame_2);
        lineEditDureeOccup->setObjectName(QString::fromUtf8("lineEditDureeOccup"));
        lineEditDureeOccup->setMaximumSize(QSize(180, 16777215));
        lineEditDureeOccup->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDureeOccup->setReadOnly(true);

        formLayout_19->setWidget(0, QFormLayout::FieldRole, lineEditDureeOccup);


        gridLayout_7->addLayout(formLayout_19, 0, 1, 1, 1);


        gridLayout_8->addWidget(frame_2, 1, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tabFacturesDeCeJour = new QWidget();
        tabFacturesDeCeJour->setObjectName(QString::fromUtf8("tabFacturesDeCeJour"));
        gridLayout_6 = new QGridLayout(tabFacturesDeCeJour);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tableWidgetFacturesDeJour = new QTableWidget(tabFacturesDeCeJour);
        if (tableWidgetFacturesDeJour->columnCount() < 11)
            tableWidgetFacturesDeJour->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(4, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(5, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(6, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(7, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(8, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(9, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidgetFacturesDeJour->setHorizontalHeaderItem(10, __qtablewidgetitem40);
        tableWidgetFacturesDeJour->setObjectName(QString::fromUtf8("tableWidgetFacturesDeJour"));
        tableWidgetFacturesDeJour->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetFacturesDeJour->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetFacturesDeJour->horizontalHeader()->setDefaultSectionSize(130);

        gridLayout_6->addWidget(tableWidgetFacturesDeJour, 0, 0, 1, 2);

        formLayout_14 = new QFormLayout();
        formLayout_14->setObjectName(QString::fromUtf8("formLayout_14"));
        formLayout_11 = new QFormLayout();
        formLayout_11->setObjectName(QString::fromUtf8("formLayout_11"));
        label_7 = new QLabel(tabFacturesDeCeJour);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_11->setWidget(0, QFormLayout::LabelRole, label_7);

        lineEditMontantEncaisse = new QLineEdit(tabFacturesDeCeJour);
        lineEditMontantEncaisse->setObjectName(QString::fromUtf8("lineEditMontantEncaisse"));
        lineEditMontantEncaisse->setMaximumSize(QSize(150, 16777215));
        lineEditMontantEncaisse->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantEncaisse->setReadOnly(true);

        formLayout_11->setWidget(0, QFormLayout::FieldRole, lineEditMontantEncaisse);


        formLayout_14->setLayout(0, QFormLayout::LabelRole, formLayout_11);

        formLayout_13 = new QFormLayout();
        formLayout_13->setObjectName(QString::fromUtf8("formLayout_13"));
        label_6 = new QLabel(tabFacturesDeCeJour);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_13->setWidget(0, QFormLayout::LabelRole, label_6);

        lineEditMontantRestantDeCeJour = new QLineEdit(tabFacturesDeCeJour);
        lineEditMontantRestantDeCeJour->setObjectName(QString::fromUtf8("lineEditMontantRestantDeCeJour"));
        lineEditMontantRestantDeCeJour->setMaximumSize(QSize(150, 16777215));
        lineEditMontantRestantDeCeJour->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantRestantDeCeJour->setReadOnly(true);

        formLayout_13->setWidget(0, QFormLayout::FieldRole, lineEditMontantRestantDeCeJour);


        formLayout_14->setLayout(0, QFormLayout::FieldRole, formLayout_13);


        gridLayout_6->addLayout(formLayout_14, 1, 0, 1, 1);

        btn_imprimerFactureDeCeJour = new QPushButton(tabFacturesDeCeJour);
        btn_imprimerFactureDeCeJour->setObjectName(QString::fromUtf8("btn_imprimerFactureDeCeJour"));
        btn_imprimerFactureDeCeJour->setMaximumSize(QSize(75, 23));
        btn_imprimerFactureDeCeJour->setLayoutDirection(Qt::RightToLeft);

        gridLayout_6->addWidget(btn_imprimerFactureDeCeJour, 1, 1, 1, 1);

        tabWidget->addTab(tabFacturesDeCeJour, QString());
        tabFacturesNonReglees = new QWidget();
        tabFacturesNonReglees->setObjectName(QString::fromUtf8("tabFacturesNonReglees"));
        gridLayout_4 = new QGridLayout(tabFacturesNonReglees);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tableWidgetFactures = new QTableWidget(tabFacturesNonReglees);
        if (tableWidgetFactures->columnCount() < 11)
            tableWidgetFactures->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(1, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(2, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(3, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(4, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(5, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(6, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(7, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(8, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(9, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidgetFactures->setHorizontalHeaderItem(10, __qtablewidgetitem51);
        tableWidgetFactures->setObjectName(QString::fromUtf8("tableWidgetFactures"));
        tableWidgetFactures->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetFactures->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetFactures->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout_4->addWidget(tableWidgetFactures, 0, 0, 1, 2);

        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        label_5 = new QLabel(tabFacturesNonReglees);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, label_5);

        lineEditMontantRestant = new QLineEdit(tabFacturesNonReglees);
        lineEditMontantRestant->setObjectName(QString::fromUtf8("lineEditMontantRestant"));
        lineEditMontantRestant->setMaximumSize(QSize(150, 16777215));
        lineEditMontantRestant->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantRestant->setReadOnly(true);

        formLayout_9->setWidget(0, QFormLayout::FieldRole, lineEditMontantRestant);


        gridLayout_4->addLayout(formLayout_9, 1, 0, 1, 1);

        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QString::fromUtf8("formLayout_10"));
        formLayout_10->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_10->setContentsMargins(-1, -1, 8, -1);
        btn_reglerFacture = new QPushButton(tabFacturesNonReglees);
        btn_reglerFacture->setObjectName(QString::fromUtf8("btn_reglerFacture"));
        btn_reglerFacture->setMinimumSize(QSize(100, 0));
        btn_reglerFacture->setMaximumSize(QSize(110, 23));
        btn_reglerFacture->setLayoutDirection(Qt::RightToLeft);

        formLayout_10->setWidget(0, QFormLayout::LabelRole, btn_reglerFacture);

        btn_imprimerFacture = new QPushButton(tabFacturesNonReglees);
        btn_imprimerFacture->setObjectName(QString::fromUtf8("btn_imprimerFacture"));
        btn_imprimerFacture->setMaximumSize(QSize(75, 23));
        btn_imprimerFacture->setLayoutDirection(Qt::RightToLeft);

        formLayout_10->setWidget(0, QFormLayout::FieldRole, btn_imprimerFacture);


        gridLayout_4->addLayout(formLayout_10, 1, 1, 1, 1);

        tabWidget->addTab(tabFacturesNonReglees, QString());
        tabActivites = new QWidget();
        tabActivites->setObjectName(QString::fromUtf8("tabActivites"));
        gridLayout_3 = new QGridLayout(tabActivites);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        formLayout_21 = new QFormLayout();
        formLayout_21->setObjectName(QString::fromUtf8("formLayout_21"));
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        lineEditMontantTotalEncaisse = new QLineEdit(tabActivites);
        lineEditMontantTotalEncaisse->setObjectName(QString::fromUtf8("lineEditMontantTotalEncaisse"));
        lineEditMontantTotalEncaisse->setMaximumSize(QSize(133, 16777215));
        lineEditMontantTotalEncaisse->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantTotalEncaisse->setReadOnly(true);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, lineEditMontantTotalEncaisse);

        label_4 = new QLabel(tabActivites);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, label_4);


        formLayout_21->setLayout(0, QFormLayout::LabelRole, formLayout_8);

        formLayout_20 = new QFormLayout();
        formLayout_20->setObjectName(QString::fromUtf8("formLayout_20"));
        label_11 = new QLabel(tabActivites);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_20->setWidget(0, QFormLayout::LabelRole, label_11);

        lineEditMontantTotalRetire = new QLineEdit(tabActivites);
        lineEditMontantTotalRetire->setObjectName(QString::fromUtf8("lineEditMontantTotalRetire"));
        lineEditMontantTotalRetire->setMaximumSize(QSize(133, 16777215));
        lineEditMontantTotalRetire->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantTotalRetire->setReadOnly(true);

        formLayout_20->setWidget(0, QFormLayout::FieldRole, lineEditMontantTotalRetire);


        formLayout_21->setLayout(0, QFormLayout::FieldRole, formLayout_20);


        gridLayout_3->addLayout(formLayout_21, 1, 0, 1, 1);

        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        formLayout_7->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_7->setContentsMargins(-1, -1, 7, -1);
        btn_imprimerRecu = new QPushButton(tabActivites);
        btn_imprimerRecu->setObjectName(QString::fromUtf8("btn_imprimerRecu"));
        btn_imprimerRecu->setMaximumSize(QSize(75, 23));
        btn_imprimerRecu->setLayoutDirection(Qt::LeftToRight);

        formLayout_7->setWidget(0, QFormLayout::LabelRole, btn_imprimerRecu);

        btn_cloturer = new QPushButton(tabActivites);
        btn_cloturer->setObjectName(QString::fromUtf8("btn_cloturer"));
        btn_cloturer->setMaximumSize(QSize(75, 23));
        btn_cloturer->setLayoutDirection(Qt::LeftToRight);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, btn_cloturer);


        gridLayout_3->addLayout(formLayout_7, 1, 1, 1, 1);

        tableViewActivites = new QTableView(tabActivites);
        tableViewActivites->setObjectName(QString::fromUtf8("tableViewActivites"));
        tableViewActivites->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewActivites->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewActivites->horizontalHeader()->setDefaultSectionSize(210);

        gridLayout_3->addWidget(tableViewActivites, 0, 0, 1, 2);

        tabWidget->addTab(tabActivites, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(MdiPlanning);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MdiPlanning);
    } // setupUi

    void retranslateUi(QWidget *MdiPlanning)
    {
        MdiPlanning->setWindowTitle(QApplication::translate("MdiPlanning", "Form", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetPlanning->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MdiPlanning", "Lundi 8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetPlanning->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MdiPlanning", "Mardi 9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetPlanning->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MdiPlanning", "Mercredi 10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetPlanning->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MdiPlanning", "Jeudi 11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetPlanning->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MdiPlanning", "Vendredi 12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetPlanning->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MdiPlanning", "Samedi 13", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetPlanning->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MdiPlanning", "Dimanche 14", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetPlanning->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MdiPlanning", "Disponible", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetPlanning->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MdiPlanning", "Occup\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetPlanning->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MdiPlanning", "Reserv\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetPlanning->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MdiPlanning", "CV1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetPlanning->verticalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("MdiPlanning", "CV2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetPlanning->verticalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("MdiPlanning", "CV3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetPlanning->verticalHeaderItem(7);
        ___qtablewidgetitem13->setText(QApplication::translate("MdiPlanning", "CV4", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MdiPlanning", "P\303\251riode allant du :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MdiPlanning", "\303\240", 0, QApplication::UnicodeUTF8));
        btn_setPeriodeReserv->setText(QApplication::translate("MdiPlanning", "...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MdiPlanning", "Dur\303\251e :", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MdiPlanning", "Planning des r\303\251servations", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetPlanningOccup->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MdiPlanning", "Lundi 8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetPlanningOccup->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MdiPlanning", "Mardi 9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetPlanningOccup->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("MdiPlanning", "Mercredi 10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetPlanningOccup->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("MdiPlanning", "Jeudi 11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetPlanningOccup->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("MdiPlanning", "Vendredi 12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetPlanningOccup->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QApplication::translate("MdiPlanning", "Samedi 13", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetPlanningOccup->horizontalHeaderItem(6);
        ___qtablewidgetitem20->setText(QApplication::translate("MdiPlanning", "Dimanche 14", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetPlanningOccup->verticalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("MdiPlanning", "Disponible", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetPlanningOccup->verticalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("MdiPlanning", "Occup\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetPlanningOccup->verticalHeaderItem(2);
        ___qtablewidgetitem23->setText(QApplication::translate("MdiPlanning", "Reserv\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidgetPlanningOccup->verticalHeaderItem(4);
        ___qtablewidgetitem24->setText(QApplication::translate("MdiPlanning", "CV1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidgetPlanningOccup->verticalHeaderItem(5);
        ___qtablewidgetitem25->setText(QApplication::translate("MdiPlanning", "CV2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidgetPlanningOccup->verticalHeaderItem(6);
        ___qtablewidgetitem26->setText(QApplication::translate("MdiPlanning", "CV3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidgetPlanningOccup->verticalHeaderItem(7);
        ___qtablewidgetitem27->setText(QApplication::translate("MdiPlanning", "CV4", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MdiPlanning", "P\303\251riode allant du :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MdiPlanning", "\303\240", 0, QApplication::UnicodeUTF8));
        btn_setPeriodeOccup->setText(QApplication::translate("MdiPlanning", "...", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MdiPlanning", "Dur\303\251e :", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MdiPlanning", "Planning des occupations", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidgetFacturesDeJour->horizontalHeaderItem(0);
        ___qtablewidgetitem28->setText(QApplication::translate("MdiPlanning", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidgetFacturesDeJour->horizontalHeaderItem(1);
        ___qtablewidgetitem29->setText(QApplication::translate("MdiPlanning", "Facture", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidgetFacturesDeJour->horizontalHeaderItem(2);
        ___qtablewidgetitem30->setText(QApplication::translate("MdiPlanning", "Client", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidgetFacturesDeJour->horizontalHeaderItem(3);
        ___qtablewidgetitem31->setText(QApplication::translate("MdiPlanning", "Chambre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidgetFacturesDeJour->horizontalHeaderItem(4);
        ___qtablewidgetitem32->setText(QApplication::translate("MdiPlanning", "Date d'arriv\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidgetFacturesDeJour->horizontalHeaderItem(5);
        ___qtablewidgetitem33->setText(QApplication::translate("MdiPlanning", "Date de d\303\251part", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidgetFacturesDeJour->horizontalHeaderItem(6);
        ___qtablewidgetitem34->setText(QApplication::translate("MdiPlanning", "Dur\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidgetFacturesDeJour->horizontalHeaderItem(7);
        ___qtablewidgetitem35->setText(QApplication::translate("MdiPlanning", "Montant total", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidgetFacturesDeJour->horizontalHeaderItem(8);
        ___qtablewidgetitem36->setText(QApplication::translate("MdiPlanning", "Montant pay\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidgetFacturesDeJour->horizontalHeaderItem(9);
        ___qtablewidgetitem37->setText(QApplication::translate("MdiPlanning", "Montant restant", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidgetFacturesDeJour->horizontalHeaderItem(10);
        ___qtablewidgetitem38->setText(QApplication::translate("MdiPlanning", "Matricule agent", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MdiPlanning", "Montant encaiss\303\251 total :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MdiPlanning", "Montant restant total :", 0, QApplication::UnicodeUTF8));
        btn_imprimerFactureDeCeJour->setText(QApplication::translate("MdiPlanning", "Imprimer", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabFacturesDeCeJour), QApplication::translate("MdiPlanning", "Factures de ce jour", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidgetFactures->horizontalHeaderItem(0);
        ___qtablewidgetitem39->setText(QApplication::translate("MdiPlanning", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidgetFactures->horizontalHeaderItem(1);
        ___qtablewidgetitem40->setText(QApplication::translate("MdiPlanning", "Facture", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidgetFactures->horizontalHeaderItem(2);
        ___qtablewidgetitem41->setText(QApplication::translate("MdiPlanning", "Client", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidgetFactures->horizontalHeaderItem(3);
        ___qtablewidgetitem42->setText(QApplication::translate("MdiPlanning", "Chambre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidgetFactures->horizontalHeaderItem(4);
        ___qtablewidgetitem43->setText(QApplication::translate("MdiPlanning", "Date d'arriv\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidgetFactures->horizontalHeaderItem(5);
        ___qtablewidgetitem44->setText(QApplication::translate("MdiPlanning", "Date de d\303\251part", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidgetFactures->horizontalHeaderItem(6);
        ___qtablewidgetitem45->setText(QApplication::translate("MdiPlanning", "Dur\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidgetFactures->horizontalHeaderItem(7);
        ___qtablewidgetitem46->setText(QApplication::translate("MdiPlanning", "Montant total", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidgetFactures->horizontalHeaderItem(8);
        ___qtablewidgetitem47->setText(QApplication::translate("MdiPlanning", "Montant pay\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidgetFactures->horizontalHeaderItem(9);
        ___qtablewidgetitem48->setText(QApplication::translate("MdiPlanning", "Montant restant", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidgetFactures->horizontalHeaderItem(10);
        ___qtablewidgetitem49->setText(QApplication::translate("MdiPlanning", "Matricule agent", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MdiPlanning", "Montant restant total :", 0, QApplication::UnicodeUTF8));
        btn_reglerFacture->setText(QApplication::translate("MdiPlanning", "R\303\251gler la facture", 0, QApplication::UnicodeUTF8));
        btn_imprimerFacture->setText(QApplication::translate("MdiPlanning", "Imprimer", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabFacturesNonReglees), QApplication::translate("MdiPlanning", "Factures non r\303\251gl\303\251es", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MdiPlanning", "Montant total encaiss\303\251 :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MdiPlanning", "Montant total retir\303\251 :", 0, QApplication::UnicodeUTF8));
        btn_imprimerRecu->setText(QApplication::translate("MdiPlanning", "Imprimer", 0, QApplication::UnicodeUTF8));
        btn_cloturer->setText(QApplication::translate("MdiPlanning", "Cl\303\264turer", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabActivites), QApplication::translate("MdiPlanning", "Activit\303\251s", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MdiPlanning: public Ui_MdiPlanning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDIPLANNING_H
