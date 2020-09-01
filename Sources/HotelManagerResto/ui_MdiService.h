/********************************************************************************
** Form generated from reading UI file 'MdiService.ui'
**
** Created: Sun 27. Oct 20:07:21 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDISERVICE_H
#define UI_MDISERVICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MdiService
{
public:
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayoutPeriode;
    QRadioButton *rb_aujourdhui;
    QFormLayout *formLayout_2;
    QRadioButton *rb_periode;
    QFormLayout *formLayout;
    QSplitter *splitterDebut;
    QSplitter *splitter;
    QLineEdit *lineEditDebut;
    QToolButton *btn_debut;
    QLabel *label;
    QSplitter *splitterFin;
    QLineEdit *lineEditFin;
    QToolButton *btn_fin;
    QTableWidget *tableWidget;
    QFormLayout *formLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *lineEditMontantEncaisse;
    QFormLayout *formLayout_10;
    QLabel *label_8;
    QLineEdit *lineEditMontantRestant;
    QPushButton *btn_details;
    QPushButton *btn_imprimerFacture;
    QWidget *tab_3;
    QGridLayout *gridLayout_6;
    QTableView *tableViewActivites;
    QFormLayout *formLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLineEdit *lineEditMontantTotalEncaisse;
    QFormLayout *formLayout_14;
    QLabel *label_13;
    QLineEdit *lineEditMontantTotalRetire;
    QPushButton *btn_imprimerRecu;
    QPushButton *btn_cloturer;
    QWidget *tab_2;
    QGridLayout *gridLayout_8;
    QTreeWidget *treeWidgetTablesOccupees;
    QGroupBox *groupBoxTable;
    QGridLayout *gridLayout_9;
    QTreeWidget *treeWidgetConsommations;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_18;
    QLabel *labelDateArrivee;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_24;
    QLabel *label_22;
    QLabel *label_23;
    QFormLayout *formLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelClient;
    QLabel *labelTotalAPayer;
    QLabel *labelMontantEncaisse;
    QLabel *labelResteAPayer;
    QLabel *labelDureeOccupation;
    QToolButton *btn_identifierClient;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QLabel *label_11;
    QComboBox *comboBoxModeDePaye;
    QLabel *label_7;
    QComboBox *comboBoxCompteClient;
    QFormLayout *formLayout_12;
    QLabel *label_9;
    QLineEdit *lineEditSolde;
    QLabel *label_28;
    QSpinBox *spinBoxEncaissement;
    QPushButton *btn_supprimerMenu;
    QFormLayout *formLayout_19;
    QPushButton *btn_imprimer_tab_bord;
    QPushButton *btn_terminer;
    QTreeWidget *treeWidgetTablesLibres;
    QPushButton *btn_occuper;
    QGroupBox *groupBoxEnreg;
    QGridLayout *gridLayout_10;
    QLabel *label_12;
    QComboBox *comboBoxCategorie;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget;
    QFormLayout *formLayout_13;
    QLabel *labelCumul;
    QPushButton *btn_supprimer;
    QLabel *label_2;
    QComboBox *comboBoxMenu;
    QFormLayout *formLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBoxPrixUnitaire;
    QSpinBox *spinBoxQuantite;
    QCheckBox *checkBoxModifierPrix;
    QFormLayout *formLayout_11;
    QFormLayout *formLayout_8;
    QLineEdit *lineEditPrixTotal;
    QLabel *label_5;
    QPushButton *btn_ajouter;
    QFormLayout *formLayout_7;
    QPushButton *btn_enregistrer;
    QPushButton *btn_initialiser;

    void setupUi(QWidget *MdiService)
    {
        if (MdiService->objectName().isEmpty())
            MdiService->setObjectName(QString::fromUtf8("MdiService"));
        MdiService->resize(983, 647);
        gridLayout_7 = new QGridLayout(MdiService);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox = new QGroupBox(MdiService);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayoutPeriode = new QFormLayout();
        formLayoutPeriode->setObjectName(QString::fromUtf8("formLayoutPeriode"));
        rb_aujourdhui = new QRadioButton(tab);
        rb_aujourdhui->setObjectName(QString::fromUtf8("rb_aujourdhui"));

        formLayoutPeriode->setWidget(0, QFormLayout::LabelRole, rb_aujourdhui);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        rb_periode = new QRadioButton(tab);
        rb_periode->setObjectName(QString::fromUtf8("rb_periode"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rb_periode);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        splitterDebut = new QSplitter(tab);
        splitterDebut->setObjectName(QString::fromUtf8("splitterDebut"));
        splitterDebut->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitterDebut);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        lineEditDebut = new QLineEdit(splitter);
        lineEditDebut->setObjectName(QString::fromUtf8("lineEditDebut"));
        lineEditDebut->setMaximumSize(QSize(150, 150));
        lineEditDebut->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDebut->setReadOnly(true);
        splitter->addWidget(lineEditDebut);
        btn_debut = new QToolButton(splitter);
        btn_debut->setObjectName(QString::fromUtf8("btn_debut"));
        btn_debut->setMaximumSize(QSize(30, 16777215));
        splitter->addWidget(btn_debut);
        splitterDebut->addWidget(splitter);
        label = new QLabel(splitterDebut);
        label->setObjectName(QString::fromUtf8("label"));
        splitterDebut->addWidget(label);

        formLayout->setWidget(0, QFormLayout::LabelRole, splitterDebut);

        splitterFin = new QSplitter(tab);
        splitterFin->setObjectName(QString::fromUtf8("splitterFin"));
        splitterFin->setOrientation(Qt::Horizontal);
        lineEditFin = new QLineEdit(splitterFin);
        lineEditFin->setObjectName(QString::fromUtf8("lineEditFin"));
        lineEditFin->setMaximumSize(QSize(150, 150));
        lineEditFin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFin->setReadOnly(true);
        splitterFin->addWidget(lineEditFin);
        btn_fin = new QToolButton(splitterFin);
        btn_fin->setObjectName(QString::fromUtf8("btn_fin"));
        btn_fin->setMaximumSize(QSize(30, 16777215));
        splitterFin->addWidget(btn_fin);

        formLayout->setWidget(0, QFormLayout::FieldRole, splitterFin);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, formLayout);


        formLayoutPeriode->setLayout(0, QFormLayout::FieldRole, formLayout_2);


        gridLayout_2->addLayout(formLayoutPeriode, 0, 0, 1, 1);

        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_2->addWidget(tableWidget, 1, 0, 1, 3);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        lineEditMontantEncaisse = new QLineEdit(tab);
        lineEditMontantEncaisse->setObjectName(QString::fromUtf8("lineEditMontantEncaisse"));
        lineEditMontantEncaisse->setMaximumSize(QSize(133, 16777215));
        lineEditMontantEncaisse->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantEncaisse->setReadOnly(true);

        horizontalLayout->addWidget(lineEditMontantEncaisse);


        formLayout_6->setLayout(0, QFormLayout::LabelRole, horizontalLayout);

        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QString::fromUtf8("formLayout_10"));
        formLayout_10->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(85, 16777215));

        formLayout_10->setWidget(0, QFormLayout::LabelRole, label_8);

        lineEditMontantRestant = new QLineEdit(tab);
        lineEditMontantRestant->setObjectName(QString::fromUtf8("lineEditMontantRestant"));
        lineEditMontantRestant->setMaximumSize(QSize(133, 16777215));
        lineEditMontantRestant->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantRestant->setReadOnly(true);

        formLayout_10->setWidget(0, QFormLayout::FieldRole, lineEditMontantRestant);


        formLayout_6->setLayout(0, QFormLayout::FieldRole, formLayout_10);


        gridLayout_2->addLayout(formLayout_6, 2, 0, 1, 1);

        btn_details = new QPushButton(tab);
        btn_details->setObjectName(QString::fromUtf8("btn_details"));
        btn_details->setMaximumSize(QSize(75, 23));
        btn_details->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btn_details, 2, 2, 1, 1);

        btn_imprimerFacture = new QPushButton(tab);
        btn_imprimerFacture->setObjectName(QString::fromUtf8("btn_imprimerFacture"));
        btn_imprimerFacture->setMaximumSize(QSize(75, 23));
        btn_imprimerFacture->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btn_imprimerFacture, 2, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_6 = new QGridLayout(tab_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tableViewActivites = new QTableView(tab_3);
        tableViewActivites->setObjectName(QString::fromUtf8("tableViewActivites"));
        tableViewActivites->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewActivites->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewActivites->horizontalHeader()->setDefaultSectionSize(210);
        tableViewActivites->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_6->addWidget(tableViewActivites, 0, 0, 1, 3);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 9, -1);
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);

        lineEditMontantTotalEncaisse = new QLineEdit(tab_3);
        lineEditMontantTotalEncaisse->setObjectName(QString::fromUtf8("lineEditMontantTotalEncaisse"));
        lineEditMontantTotalEncaisse->setMaximumSize(QSize(133, 16777215));
        lineEditMontantTotalEncaisse->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantTotalEncaisse->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditMontantTotalEncaisse);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, horizontalLayout_2);

        formLayout_14 = new QFormLayout();
        formLayout_14->setObjectName(QString::fromUtf8("formLayout_14"));
        formLayout_14->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_14->setContentsMargins(-1, -1, 9, -1);
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_14->setWidget(0, QFormLayout::LabelRole, label_13);

        lineEditMontantTotalRetire = new QLineEdit(tab_3);
        lineEditMontantTotalRetire->setObjectName(QString::fromUtf8("lineEditMontantTotalRetire"));
        lineEditMontantTotalRetire->setMaximumSize(QSize(133, 16777215));
        lineEditMontantTotalRetire->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantTotalRetire->setReadOnly(true);

        formLayout_14->setWidget(0, QFormLayout::FieldRole, lineEditMontantTotalRetire);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, formLayout_14);


        gridLayout_6->addLayout(formLayout_3, 1, 0, 1, 1);

        btn_imprimerRecu = new QPushButton(tab_3);
        btn_imprimerRecu->setObjectName(QString::fromUtf8("btn_imprimerRecu"));
        btn_imprimerRecu->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(btn_imprimerRecu, 1, 1, 1, 1);

        btn_cloturer = new QPushButton(tab_3);
        btn_cloturer->setObjectName(QString::fromUtf8("btn_cloturer"));
        btn_cloturer->setMaximumSize(QSize(75, 16777215));

        gridLayout_6->addWidget(btn_cloturer, 1, 2, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_8 = new QGridLayout(tab_2);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        treeWidgetTablesOccupees = new QTreeWidget(tab_2);
        treeWidgetTablesOccupees->setObjectName(QString::fromUtf8("treeWidgetTablesOccupees"));
        treeWidgetTablesOccupees->setMaximumSize(QSize(170, 16777215));

        gridLayout_8->addWidget(treeWidgetTablesOccupees, 0, 0, 1, 1);

        groupBoxTable = new QGroupBox(tab_2);
        groupBoxTable->setObjectName(QString::fromUtf8("groupBoxTable"));
        gridLayout_9 = new QGridLayout(groupBoxTable);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        treeWidgetConsommations = new QTreeWidget(groupBoxTable);
        treeWidgetConsommations->setObjectName(QString::fromUtf8("treeWidgetConsommations"));
        treeWidgetConsommations->setUniformRowHeights(false);
        treeWidgetConsommations->header()->setDefaultSectionSize(170);
        treeWidgetConsommations->header()->setMinimumSectionSize(100);
        treeWidgetConsommations->header()->setStretchLastSection(false);

        gridLayout_9->addWidget(treeWidgetConsommations, 0, 0, 2, 1);

        groupBox_3 = new QGroupBox(groupBoxTable);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(375, 153));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_4->addWidget(label_18, 0, 0, 1, 1);

        labelDateArrivee = new QLabel(groupBox_3);
        labelDateArrivee->setObjectName(QString::fromUtf8("labelDateArrivee"));
        labelDateArrivee->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(labelDateArrivee, 0, 1, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_3->addWidget(label_20);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_3->addWidget(label_21);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_3->addWidget(label_24);

        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_3->addWidget(label_22);

        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_3->addWidget(label_23);


        gridLayout_4->addLayout(verticalLayout_3, 1, 0, 1, 2);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelClient = new QLabel(groupBox_3);
        labelClient->setObjectName(QString::fromUtf8("labelClient"));
        labelClient->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(labelClient);

        labelTotalAPayer = new QLabel(groupBox_3);
        labelTotalAPayer->setObjectName(QString::fromUtf8("labelTotalAPayer"));
        labelTotalAPayer->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(labelTotalAPayer);

        labelMontantEncaisse = new QLabel(groupBox_3);
        labelMontantEncaisse->setObjectName(QString::fromUtf8("labelMontantEncaisse"));
        labelMontantEncaisse->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(labelMontantEncaisse);

        labelResteAPayer = new QLabel(groupBox_3);
        labelResteAPayer->setObjectName(QString::fromUtf8("labelResteAPayer"));
        labelResteAPayer->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(labelResteAPayer);

        labelDureeOccupation = new QLabel(groupBox_3);
        labelDureeOccupation->setObjectName(QString::fromUtf8("labelDureeOccupation"));
        labelDureeOccupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_4->addWidget(labelDureeOccupation);


        formLayout_5->setLayout(0, QFormLayout::LabelRole, verticalLayout_4);

        btn_identifierClient = new QToolButton(groupBox_3);
        btn_identifierClient->setObjectName(QString::fromUtf8("btn_identifierClient"));
        btn_identifierClient->setMaximumSize(QSize(25, 17));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, btn_identifierClient);


        gridLayout_4->addLayout(formLayout_5, 1, 2, 1, 1);


        gridLayout_9->addWidget(groupBox_3, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(groupBoxTable);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(375, 150));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 0, 0, 1, 1);

        comboBoxModeDePaye = new QComboBox(groupBox_2);
        comboBoxModeDePaye->setObjectName(QString::fromUtf8("comboBoxModeDePaye"));
        comboBoxModeDePaye->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_5->addWidget(comboBoxModeDePaye, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        comboBoxCompteClient = new QComboBox(groupBox_2);
        comboBoxCompteClient->setObjectName(QString::fromUtf8("comboBoxCompteClient"));
        comboBoxCompteClient->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_5->addWidget(comboBoxCompteClient, 1, 1, 1, 1);

        formLayout_12 = new QFormLayout();
        formLayout_12->setObjectName(QString::fromUtf8("formLayout_12"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_12->setWidget(0, QFormLayout::LabelRole, label_9);

        lineEditSolde = new QLineEdit(groupBox_2);
        lineEditSolde->setObjectName(QString::fromUtf8("lineEditSolde"));
        lineEditSolde->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditSolde->setReadOnly(true);

        formLayout_12->setWidget(0, QFormLayout::FieldRole, lineEditSolde);


        gridLayout_5->addLayout(formLayout_12, 1, 2, 1, 1);

        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_5->addWidget(label_28, 2, 0, 1, 1);

        spinBoxEncaissement = new QSpinBox(groupBox_2);
        spinBoxEncaissement->setObjectName(QString::fromUtf8("spinBoxEncaissement"));
        spinBoxEncaissement->setMaximumSize(QSize(120, 16777215));
        spinBoxEncaissement->setSingleStep(500);

        gridLayout_5->addWidget(spinBoxEncaissement, 2, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_2, 1, 1, 1, 1);

        btn_supprimerMenu = new QPushButton(groupBoxTable);
        btn_supprimerMenu->setObjectName(QString::fromUtf8("btn_supprimerMenu"));
        btn_supprimerMenu->setMaximumSize(QSize(75, 23));
        btn_supprimerMenu->setLayoutDirection(Qt::RightToLeft);

        gridLayout_9->addWidget(btn_supprimerMenu, 2, 0, 1, 1);

        formLayout_19 = new QFormLayout();
        formLayout_19->setObjectName(QString::fromUtf8("formLayout_19"));
        formLayout_19->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_19->setFormAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        formLayout_19->setContentsMargins(-1, -1, 7, -1);
        btn_imprimer_tab_bord = new QPushButton(groupBoxTable);
        btn_imprimer_tab_bord->setObjectName(QString::fromUtf8("btn_imprimer_tab_bord"));
        btn_imprimer_tab_bord->setMaximumSize(QSize(130, 23));
        btn_imprimer_tab_bord->setLayoutDirection(Qt::RightToLeft);

        formLayout_19->setWidget(0, QFormLayout::LabelRole, btn_imprimer_tab_bord);

        btn_terminer = new QPushButton(groupBoxTable);
        btn_terminer->setObjectName(QString::fromUtf8("btn_terminer"));
        btn_terminer->setMaximumSize(QSize(75, 23));
        btn_terminer->setLayoutDirection(Qt::RightToLeft);

        formLayout_19->setWidget(0, QFormLayout::FieldRole, btn_terminer);


        gridLayout_9->addLayout(formLayout_19, 2, 1, 1, 1);


        gridLayout_8->addWidget(groupBoxTable, 0, 1, 3, 1);

        treeWidgetTablesLibres = new QTreeWidget(tab_2);
        treeWidgetTablesLibres->setObjectName(QString::fromUtf8("treeWidgetTablesLibres"));
        treeWidgetTablesLibres->setMaximumSize(QSize(170, 16777215));

        gridLayout_8->addWidget(treeWidgetTablesLibres, 1, 0, 1, 1);

        btn_occuper = new QPushButton(tab_2);
        btn_occuper->setObjectName(QString::fromUtf8("btn_occuper"));
        btn_occuper->setMaximumSize(QSize(75, 23));
        btn_occuper->setLayoutDirection(Qt::RightToLeft);

        gridLayout_8->addWidget(btn_occuper, 2, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        gridLayout_7->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxEnreg = new QGroupBox(MdiService);
        groupBoxEnreg->setObjectName(QString::fromUtf8("groupBoxEnreg"));
        groupBoxEnreg->setMaximumSize(QSize(16777215, 171));
        gridLayout_10 = new QGridLayout(groupBoxEnreg);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_12 = new QLabel(groupBoxEnreg);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_10->addWidget(label_12, 0, 0, 1, 1);

        comboBoxCategorie = new QComboBox(groupBoxEnreg);
        comboBoxCategorie->setObjectName(QString::fromUtf8("comboBoxCategorie"));

        gridLayout_10->addWidget(comboBoxCategorie, 0, 1, 1, 1);

        groupBox_6 = new QGroupBox(groupBoxEnreg);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_3 = new QGridLayout(groupBox_6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        listWidget = new QListWidget(groupBox_6);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout_3->addWidget(listWidget, 0, 0, 1, 1);

        formLayout_13 = new QFormLayout();
        formLayout_13->setObjectName(QString::fromUtf8("formLayout_13"));
        labelCumul = new QLabel(groupBox_6);
        labelCumul->setObjectName(QString::fromUtf8("labelCumul"));

        formLayout_13->setWidget(0, QFormLayout::LabelRole, labelCumul);

        btn_supprimer = new QPushButton(groupBox_6);
        btn_supprimer->setObjectName(QString::fromUtf8("btn_supprimer"));
        btn_supprimer->setMaximumSize(QSize(75, 23));
        btn_supprimer->setLayoutDirection(Qt::RightToLeft);

        formLayout_13->setWidget(0, QFormLayout::FieldRole, btn_supprimer);


        gridLayout_3->addLayout(formLayout_13, 1, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_6, 0, 4, 3, 1);

        label_2 = new QLabel(groupBoxEnreg);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_10->addWidget(label_2, 1, 0, 1, 1);

        comboBoxMenu = new QComboBox(groupBoxEnreg);
        comboBoxMenu->setObjectName(QString::fromUtf8("comboBoxMenu"));
        comboBoxMenu->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_10->addWidget(comboBoxMenu, 1, 1, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(groupBoxEnreg);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(groupBoxEnreg);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        formLayout_4->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        spinBoxPrixUnitaire = new QSpinBox(groupBoxEnreg);
        spinBoxPrixUnitaire->setObjectName(QString::fromUtf8("spinBoxPrixUnitaire"));
        spinBoxPrixUnitaire->setMinimumSize(QSize(100, 0));
        spinBoxPrixUnitaire->setMaximumSize(QSize(100, 16777215));
        spinBoxPrixUnitaire->setMaximum(0);
        spinBoxPrixUnitaire->setSingleStep(500);

        verticalLayout_2->addWidget(spinBoxPrixUnitaire);

        spinBoxQuantite = new QSpinBox(groupBoxEnreg);
        spinBoxQuantite->setObjectName(QString::fromUtf8("spinBoxQuantite"));
        spinBoxQuantite->setMaximumSize(QSize(150, 16777215));
        spinBoxQuantite->setMinimum(1);

        verticalLayout_2->addWidget(spinBoxQuantite);


        formLayout_4->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);


        gridLayout_10->addLayout(formLayout_4, 1, 2, 2, 1);

        checkBoxModifierPrix = new QCheckBox(groupBoxEnreg);
        checkBoxModifierPrix->setObjectName(QString::fromUtf8("checkBoxModifierPrix"));

        gridLayout_10->addWidget(checkBoxModifierPrix, 1, 3, 1, 1);

        formLayout_11 = new QFormLayout();
        formLayout_11->setObjectName(QString::fromUtf8("formLayout_11"));
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        formLayout_8->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout_8->setContentsMargins(-1, -1, 0, -1);
        lineEditPrixTotal = new QLineEdit(groupBoxEnreg);
        lineEditPrixTotal->setObjectName(QString::fromUtf8("lineEditPrixTotal"));
        lineEditPrixTotal->setMaximumSize(QSize(133, 16777215));
        lineEditPrixTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPrixTotal->setReadOnly(true);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, lineEditPrixTotal);

        label_5 = new QLabel(groupBoxEnreg);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, label_5);


        formLayout_11->setLayout(0, QFormLayout::LabelRole, formLayout_8);

        btn_ajouter = new QPushButton(groupBoxEnreg);
        btn_ajouter->setObjectName(QString::fromUtf8("btn_ajouter"));
        btn_ajouter->setMaximumSize(QSize(75, 23));

        formLayout_11->setWidget(0, QFormLayout::FieldRole, btn_ajouter);


        gridLayout_10->addLayout(formLayout_11, 2, 3, 1, 1);

        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        formLayout_7->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_7->setContentsMargins(-1, -1, 7, -1);
        btn_enregistrer = new QPushButton(groupBoxEnreg);
        btn_enregistrer->setObjectName(QString::fromUtf8("btn_enregistrer"));
        btn_enregistrer->setMaximumSize(QSize(75, 23));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, btn_enregistrer);

        btn_initialiser = new QPushButton(groupBoxEnreg);
        btn_initialiser->setObjectName(QString::fromUtf8("btn_initialiser"));
        btn_initialiser->setMaximumSize(QSize(75, 23));

        formLayout_7->setWidget(0, QFormLayout::FieldRole, btn_initialiser);


        gridLayout_10->addLayout(formLayout_7, 3, 4, 1, 1);


        gridLayout_7->addWidget(groupBoxEnreg, 1, 0, 1, 1);


        retranslateUi(MdiService);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MdiService);
    } // setupUi

    void retranslateUi(QWidget *MdiService)
    {
        MdiService->setWindowTitle(QApplication::translate("MdiService", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MdiService", "Activit\303\251s", 0, QApplication::UnicodeUTF8));
        rb_aujourdhui->setText(QApplication::translate("MdiService", "Aujourd'hui", 0, QApplication::UnicodeUTF8));
        rb_periode->setText(QApplication::translate("MdiService", "Periode allant de ", 0, QApplication::UnicodeUTF8));
        btn_debut->setText(QApplication::translate("MdiService", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MdiService", "\303\240", 0, QApplication::UnicodeUTF8));
        btn_fin->setText(QApplication::translate("MdiService", "...", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MdiService", "Facture", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MdiService", "Client", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MdiService", "Date arriv\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MdiService", "Date d\303\251part", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MdiService", "Dur\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MdiService", "Total \303\240 payer", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MdiService", "Montant encaiss\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MdiService", "Montant restant", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MdiService", "Matricule du caissier", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MdiService", "IdRepasCResto", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MdiService", "Montant encaiss\303\251 :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MdiService", "Montant restant :", 0, QApplication::UnicodeUTF8));
        btn_details->setText(QApplication::translate("MdiService", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        btn_imprimerFacture->setText(QApplication::translate("MdiService", "Imprimer", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MdiService", "Consommations de ce jour", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MdiService", "Montant total encaiss\303\251 :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MdiService", "Montant total retir\303\251 :", 0, QApplication::UnicodeUTF8));
        btn_imprimerRecu->setText(QApplication::translate("MdiService", "Imprimer", 0, QApplication::UnicodeUTF8));
        btn_cloturer->setText(QApplication::translate("MdiService", "Cl\303\264turer ", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MdiService", "Activit\303\251s", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetTablesOccupees->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MdiService", "Tables occup\303\251es", 0, QApplication::UnicodeUTF8));
        groupBoxTable->setTitle(QApplication::translate("MdiService", "Table 1", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetConsommations->headerItem();
        ___qtreewidgetitem1->setText(4, QApplication::translate("MdiService", "idConsoRepas", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(3, QApplication::translate("MdiService", "Prix total", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(2, QApplication::translate("MdiService", "Quantit\303\251", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("MdiService", "Prix unitaire", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("MdiService", "Menu", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MdiService", "D\303\251tails sur le service", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MdiService", "Date d'arriv\303\251e :", 0, QApplication::UnicodeUTF8));
        labelDateArrivee->setText(QApplication::translate("MdiService", "Vendredi le 12 mars 2012 \303\240 12 h 34 min 50 s", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MdiService", "Client :", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MdiService", "Total \303\240 payer :", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MdiService", "Montant encaiss\303\251 :", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MdiService", "Reste \303\240 payer :", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MdiService", "Dur\303\251e d'occupation :", 0, QApplication::UnicodeUTF8));
        labelClient->setText(QApplication::translate("MdiService", "OURA Olivier Baudouin", 0, QApplication::UnicodeUTF8));
        labelTotalAPayer->setText(QApplication::translate("MdiService", "12 000", 0, QApplication::UnicodeUTF8));
        labelMontantEncaisse->setText(QApplication::translate("MdiService", "0", 0, QApplication::UnicodeUTF8));
        labelResteAPayer->setText(QApplication::translate("MdiService", "12 000", 0, QApplication::UnicodeUTF8));
        labelDureeOccupation->setText(QApplication::translate("MdiService", "20 minutes", 0, QApplication::UnicodeUTF8));
        btn_identifierClient->setText(QApplication::translate("MdiService", "...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MdiService", "R\303\250glement", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MdiService", "Mode de payement :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MdiService", "Compte :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MdiService", "Solde :", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MdiService", "Montant:", 0, QApplication::UnicodeUTF8));
        btn_supprimerMenu->setText(QApplication::translate("MdiService", "Supprimer", 0, QApplication::UnicodeUTF8));
        btn_imprimer_tab_bord->setText(QApplication::translate("MdiService", "Imprimer la facture", 0, QApplication::UnicodeUTF8));
        btn_terminer->setText(QApplication::translate("MdiService", "Terminer", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidgetTablesLibres->headerItem();
        ___qtreewidgetitem2->setText(0, QApplication::translate("MdiService", "Tables libres", 0, QApplication::UnicodeUTF8));
        btn_occuper->setText(QApplication::translate("MdiService", "Occuper", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MdiService", "Tableau de bord", 0, QApplication::UnicodeUTF8));
        groupBoxEnreg->setTitle(QApplication::translate("MdiService", "Ex\303\251cuter une commande pour la table 1", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MdiService", "Cat\303\251gorie :", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MdiService", "Panier", 0, QApplication::UnicodeUTF8));
        labelCumul->setText(QApplication::translate("MdiService", "Montant cumul\303\251 = 0 ", 0, QApplication::UnicodeUTF8));
        btn_supprimer->setText(QApplication::translate("MdiService", "Supprimer", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MdiService", "Menu :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MdiService", "Prix unitaire :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MdiService", "Quantit\303\251 :", 0, QApplication::UnicodeUTF8));
        checkBoxModifierPrix->setText(QApplication::translate("MdiService", "Modifier le prix", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MdiService", "Prix total :", 0, QApplication::UnicodeUTF8));
        btn_ajouter->setText(QApplication::translate("MdiService", "Ajouter", 0, QApplication::UnicodeUTF8));
        btn_enregistrer->setText(QApplication::translate("MdiService", "Ex\303\251cuter", 0, QApplication::UnicodeUTF8));
        btn_initialiser->setText(QApplication::translate("MdiService", "Initialiser", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MdiService: public Ui_MdiService {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDISERVICE_H
