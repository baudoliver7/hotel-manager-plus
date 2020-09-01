/********************************************************************************
** Form generated from reading UI file 'MdiBilanActivitesReception.ui'
**
** Created: Fri 25. Oct 17:11:19 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDIBILANACTIVITESRECEPTION_H
#define UI_MDIBILANACTIVITESRECEPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
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

class Ui_MdiBilanActivitesReception
{
public:
    QGridLayout *gridLayout_12;
    QFrame *frame_2;
    QGridLayout *gridLayout_11;
    QLabel *label_logo;
    QLabel *label_horloge;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QLabel *labelEnveloppe;
    QFormLayout *formLayout_6;
    QLabel *labelNbMsgNonLus;
    QPushButton *btn_lire;
    QFrame *frame_3;
    QGridLayout *gridLayout_8;
    QLabel *label_heureDeConnection;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *dateDebut;
    QToolButton *btn_setPeriode;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *duree;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *dateFin;
    QPushButton *btn_actualiser;
    QTabWidget *tabWidgetActivitesDesServices;
    QWidget *tab;
    QGridLayout *gridLayout_7;
    QFormLayout *formLayout;
    QLabel *label_4;
    QComboBox *comboBoxRecepteur;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *labelNbReserv;
    QTableWidget *tableWidgetReserv;
    QFormLayout *formLayout_5;
    QLabel *label_8;
    QLineEdit *lineEditAvances;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QLabel *labelNbAnomalies;
    QLabel *labelNbOccup;
    QTableWidget *tableWidgetOccup;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QLineEdit *lineEditChAff;
    QWidget *tab3;
    QGridLayout *gridLayout_13;
    QTableView *tableViewCloturesReception;
    QFormLayout *formLayout_14;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QLineEdit *lineEditEncaisseClotureRecept;
    QFormLayout *formLayout_13;
    QLabel *label_15;
    QLineEdit *lineEditRestantClotureRecept;
    QFormLayout *formLayout_15;
    QLabel *label_16;
    QLineEdit *lineEditRetireClotureRecept;
    QPushButton *btn_detailsRecept;
    QWidget *tab2;
    QGridLayout *gridLayout_6;
    QTableWidget *tableWidgetDureeActivites;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QLineEdit *lineEditDureeTotale;
    QWidget *tab_2;
    QGridLayout *gridLayout_9;
    QFormLayout *formLayout_4;
    QLabel *label_5;
    QComboBox *comboBoxRestaurataires;
    QTabWidget *tabWidget_3;
    QWidget *tab1_2;
    QGridLayout *gridLayout_10;
    QTableWidget *tableWidgetActivitesResto;
    QFormLayout *formLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *lineEditEncaisseActivite;
    QFormLayout *formLayout_7;
    QLabel *label_10;
    QLineEdit *lineEditRestantActivite;
    QPushButton *btn_imprimerFacture;
    QPushButton *btn_details;
    QWidget *tab_4;
    QGridLayout *gridLayout_15;
    QTableView *tableViewCloturesRestauration;
    QFormLayout *formLayout_10;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLineEdit *lineEditEncaisseCloture;
    QFormLayout *formLayout_11;
    QLabel *label_13;
    QLineEdit *lineEditClotureRestant;
    QFormLayout *formLayout_12;
    QLabel *label_24;
    QLineEdit *lineEditClotureRetire;
    QPushButton *btn_detailsResto;
    QWidget *tab2_2;
    QGridLayout *gridLayout_14;
    QTableWidget *tableWidgetDureeActivitesResto;
    QFormLayout *formLayout_8;
    QLabel *label_11;
    QLineEdit *lineEditDureeTotaleResto;

    void setupUi(QWidget *MdiBilanActivitesReception)
    {
        if (MdiBilanActivitesReception->objectName().isEmpty())
            MdiBilanActivitesReception->setObjectName(QString::fromUtf8("MdiBilanActivitesReception"));
        MdiBilanActivitesReception->resize(944, 666);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MdiBilanActivitesReception->setWindowIcon(icon);
        MdiBilanActivitesReception->setLayoutDirection(Qt::LeftToRight);
        gridLayout_12 = new QGridLayout(MdiBilanActivitesReception);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        frame_2 = new QFrame(MdiBilanActivitesReception);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setMaximumSize(QSize(283, 52));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_2);
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_logo = new QLabel(frame_2);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setMaximumSize(QSize(38, 32));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_logo->setScaledContents(true);

        gridLayout_11->addWidget(label_logo, 0, 0, 1, 1);

        label_horloge = new QLabel(frame_2);
        label_horloge->setObjectName(QString::fromUtf8("label_horloge"));

        gridLayout_11->addWidget(label_horloge, 0, 1, 1, 1);


        gridLayout_12->addWidget(frame_2, 0, 0, 1, 1);

        frame = new QFrame(MdiBilanActivitesReception);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(75, 0));
        frame->setMaximumSize(QSize(100000, 52));
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        labelEnveloppe = new QLabel(frame);
        labelEnveloppe->setObjectName(QString::fromUtf8("labelEnveloppe"));
        labelEnveloppe->setMinimumSize(QSize(50, 23));
        labelEnveloppe->setMaximumSize(QSize(50, 23));
        labelEnveloppe->setLayoutDirection(Qt::LeftToRight);
        labelEnveloppe->setPixmap(QPixmap(QString::fromUtf8(":/images/enveloppe.png")));
        labelEnveloppe->setScaledContents(true);
        labelEnveloppe->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(labelEnveloppe, 0, 0, 1, 1);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_6->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_6->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelNbMsgNonLus = new QLabel(frame);
        labelNbMsgNonLus->setObjectName(QString::fromUtf8("labelNbMsgNonLus"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, labelNbMsgNonLus);

        btn_lire = new QPushButton(frame);
        btn_lire->setObjectName(QString::fromUtf8("btn_lire"));
        btn_lire->setMaximumSize(QSize(120, 23));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, btn_lire);


        gridLayout_4->addLayout(formLayout_6, 0, 1, 1, 1);


        gridLayout_12->addWidget(frame, 0, 1, 1, 1);

        frame_3 = new QFrame(MdiBilanActivitesReception);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(0, 0));
        frame_3->setMaximumSize(QSize(16777215, 52));
        frame_3->setLayoutDirection(Qt::RightToLeft);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_3);
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_heureDeConnection = new QLabel(frame_3);
        label_heureDeConnection->setObjectName(QString::fromUtf8("label_heureDeConnection"));

        gridLayout_8->addWidget(label_heureDeConnection, 0, 0, 1, 1);


        gridLayout_12->addWidget(frame_3, 0, 2, 1, 1);

        groupBox = new QGroupBox(MdiBilanActivitesReception);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(530, 83));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        dateDebut = new QLineEdit(groupBox);
        dateDebut->setObjectName(QString::fromUtf8("dateDebut"));
        dateDebut->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateDebut->setReadOnly(true);

        horizontalLayout_2->addWidget(dateDebut);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        btn_setPeriode = new QToolButton(groupBox);
        btn_setPeriode->setObjectName(QString::fromUtf8("btn_setPeriode"));

        gridLayout->addWidget(btn_setPeriode, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        duree = new QLineEdit(groupBox);
        duree->setObjectName(QString::fromUtf8("duree"));
        duree->setMinimumSize(QSize(190, 0));
        duree->setMaximumSize(QSize(16777215, 16777215));
        duree->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        duree->setReadOnly(true);

        horizontalLayout->addWidget(duree);


        gridLayout->addLayout(horizontalLayout, 0, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        dateFin = new QLineEdit(groupBox);
        dateFin->setObjectName(QString::fromUtf8("dateFin"));
        dateFin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateFin->setReadOnly(true);

        horizontalLayout_3->addWidget(dateFin);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        gridLayout_12->addWidget(groupBox, 1, 0, 1, 2);

        btn_actualiser = new QPushButton(MdiBilanActivitesReception);
        btn_actualiser->setObjectName(QString::fromUtf8("btn_actualiser"));
        btn_actualiser->setMaximumSize(QSize(75, 23));
        btn_actualiser->setLayoutDirection(Qt::RightToLeft);

        gridLayout_12->addWidget(btn_actualiser, 1, 2, 1, 1);

        tabWidgetActivitesDesServices = new QTabWidget(MdiBilanActivitesReception);
        tabWidgetActivitesDesServices->setObjectName(QString::fromUtf8("tabWidgetActivitesDesServices"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_7 = new QGridLayout(tab);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setContentsMargins(-1, -1, 9, -1);
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        comboBoxRecepteur = new QComboBox(tab);
        comboBoxRecepteur->setObjectName(QString::fromUtf8("comboBoxRecepteur"));
        comboBoxRecepteur->setMaximumSize(QSize(150, 20));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxRecepteur);


        gridLayout_7->addLayout(formLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(tab);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        gridLayout_5 = new QGridLayout(tab1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_3 = new QGroupBox(tab1);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelNbReserv = new QLabel(groupBox_3);
        labelNbReserv->setObjectName(QString::fromUtf8("labelNbReserv"));
        labelNbReserv->setLayoutDirection(Qt::LeftToRight);
        labelNbReserv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelNbReserv, 0, 0, 1, 1);

        tableWidgetReserv = new QTableWidget(groupBox_3);
        if (tableWidgetReserv->columnCount() < 6)
            tableWidgetReserv->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetReserv->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetReserv->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetReserv->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetReserv->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetReserv->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetReserv->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidgetReserv->setObjectName(QString::fromUtf8("tableWidgetReserv"));
        tableWidgetReserv->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetReserv->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetReserv->horizontalHeader()->setDefaultSectionSize(210);
        tableWidgetReserv->horizontalHeader()->setStretchLastSection(true);
        tableWidgetReserv->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_3->addWidget(tableWidgetReserv, 1, 0, 1, 1);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_5->setContentsMargins(-1, -1, 8, -1);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_8);

        lineEditAvances = new QLineEdit(groupBox_3);
        lineEditAvances->setObjectName(QString::fromUtf8("lineEditAvances"));
        lineEditAvances->setMaximumSize(QSize(133, 16777215));
        lineEditAvances->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditAvances->setReadOnly(true);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, lineEditAvances);


        gridLayout_3->addLayout(formLayout_5, 2, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab1);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelNbAnomalies = new QLabel(groupBox_4);
        labelNbAnomalies->setObjectName(QString::fromUtf8("labelNbAnomalies"));
        labelNbAnomalies->setLayoutDirection(Qt::LeftToRight);
        labelNbAnomalies->setTextFormat(Qt::AutoText);
        labelNbAnomalies->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelNbAnomalies, 0, 0, 1, 1);

        labelNbOccup = new QLabel(groupBox_4);
        labelNbOccup->setObjectName(QString::fromUtf8("labelNbOccup"));
        labelNbOccup->setLayoutDirection(Qt::LeftToRight);
        labelNbOccup->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelNbOccup, 0, 1, 1, 1);

        tableWidgetOccup = new QTableWidget(groupBox_4);
        if (tableWidgetOccup->columnCount() < 5)
            tableWidgetOccup->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetOccup->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetOccup->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetOccup->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetOccup->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetOccup->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        tableWidgetOccup->setObjectName(QString::fromUtf8("tableWidgetOccup"));
        tableWidgetOccup->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetOccup->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetOccup->horizontalHeader()->setDefaultSectionSize(210);
        tableWidgetOccup->horizontalHeader()->setStretchLastSection(true);
        tableWidgetOccup->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_2->addWidget(tableWidgetOccup, 1, 0, 1, 2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_3->setContentsMargins(-1, -1, 8, -1);
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(100, 16777215));
        label_6->setLayoutDirection(Qt::LeftToRight);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        lineEditChAff = new QLineEdit(groupBox_4);
        lineEditChAff->setObjectName(QString::fromUtf8("lineEditChAff"));
        lineEditChAff->setMaximumSize(QSize(133, 20));
        lineEditChAff->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditChAff->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEditChAff);


        gridLayout_2->addLayout(formLayout_3, 2, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 1, 0, 1, 1);

        tabWidget->addTab(tab1, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QString::fromUtf8("tab3"));
        gridLayout_13 = new QGridLayout(tab3);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        tableViewCloturesReception = new QTableView(tab3);
        tableViewCloturesReception->setObjectName(QString::fromUtf8("tableViewCloturesReception"));
        tableViewCloturesReception->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewCloturesReception->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewCloturesReception->horizontalHeader()->setDefaultSectionSize(170);
        tableViewCloturesReception->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_13->addWidget(tableViewCloturesReception, 0, 0, 1, 2);

        formLayout_14 = new QFormLayout();
        formLayout_14->setObjectName(QString::fromUtf8("formLayout_14"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_14 = new QLabel(tab3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_6->addWidget(label_14);

        lineEditEncaisseClotureRecept = new QLineEdit(tab3);
        lineEditEncaisseClotureRecept->setObjectName(QString::fromUtf8("lineEditEncaisseClotureRecept"));
        lineEditEncaisseClotureRecept->setMaximumSize(QSize(133, 16777215));
        lineEditEncaisseClotureRecept->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditEncaisseClotureRecept->setReadOnly(true);

        horizontalLayout_6->addWidget(lineEditEncaisseClotureRecept);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        formLayout_13 = new QFormLayout();
        formLayout_13->setObjectName(QString::fromUtf8("formLayout_13"));
        label_15 = new QLabel(tab3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(85, 16777215));

        formLayout_13->setWidget(0, QFormLayout::LabelRole, label_15);

        lineEditRestantClotureRecept = new QLineEdit(tab3);
        lineEditRestantClotureRecept->setObjectName(QString::fromUtf8("lineEditRestantClotureRecept"));
        lineEditRestantClotureRecept->setMaximumSize(QSize(133, 16777215));
        lineEditRestantClotureRecept->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRestantClotureRecept->setReadOnly(true);

        formLayout_13->setWidget(0, QFormLayout::FieldRole, lineEditRestantClotureRecept);


        horizontalLayout_7->addLayout(formLayout_13);


        formLayout_14->setLayout(0, QFormLayout::LabelRole, horizontalLayout_7);

        formLayout_15 = new QFormLayout();
        formLayout_15->setObjectName(QString::fromUtf8("formLayout_15"));
        label_16 = new QLabel(tab3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(85, 16777215));

        formLayout_15->setWidget(0, QFormLayout::LabelRole, label_16);

        lineEditRetireClotureRecept = new QLineEdit(tab3);
        lineEditRetireClotureRecept->setObjectName(QString::fromUtf8("lineEditRetireClotureRecept"));
        lineEditRetireClotureRecept->setMaximumSize(QSize(133, 16777215));
        lineEditRetireClotureRecept->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRetireClotureRecept->setReadOnly(true);

        formLayout_15->setWidget(0, QFormLayout::FieldRole, lineEditRetireClotureRecept);


        formLayout_14->setLayout(0, QFormLayout::FieldRole, formLayout_15);


        gridLayout_13->addLayout(formLayout_14, 1, 0, 1, 1);

        btn_detailsRecept = new QPushButton(tab3);
        btn_detailsRecept->setObjectName(QString::fromUtf8("btn_detailsRecept"));
        btn_detailsRecept->setMaximumSize(QSize(75, 23));
        btn_detailsRecept->setLayoutDirection(Qt::RightToLeft);

        gridLayout_13->addWidget(btn_detailsRecept, 1, 1, 1, 1);

        tabWidget->addTab(tab3, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        gridLayout_6 = new QGridLayout(tab2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tableWidgetDureeActivites = new QTableWidget(tab2);
        if (tableWidgetDureeActivites->columnCount() < 3)
            tableWidgetDureeActivites->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetDureeActivites->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetDureeActivites->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetDureeActivites->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        tableWidgetDureeActivites->setObjectName(QString::fromUtf8("tableWidgetDureeActivites"));
        tableWidgetDureeActivites->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetDureeActivites->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetDureeActivites->horizontalHeader()->setDefaultSectionSize(210);
        tableWidgetDureeActivites->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidgetDureeActivites->horizontalHeader()->setStretchLastSection(true);
        tableWidgetDureeActivites->verticalHeader()->setVisible(false);
        tableWidgetDureeActivites->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_6->addWidget(tableWidgetDureeActivites, 0, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_2->setContentsMargins(-1, -1, 7, -1);
        label_7 = new QLabel(tab2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(64, 20));
        label_7->setLayoutDirection(Qt::LeftToRight);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        lineEditDureeTotale = new QLineEdit(tab2);
        lineEditDureeTotale->setObjectName(QString::fromUtf8("lineEditDureeTotale"));
        lineEditDureeTotale->setMinimumSize(QSize(190, 0));
        lineEditDureeTotale->setMaximumSize(QSize(190, 16777215));
        lineEditDureeTotale->setLayoutDirection(Qt::LeftToRight);
        lineEditDureeTotale->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDureeTotale->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditDureeTotale);


        gridLayout_6->addLayout(formLayout_2, 1, 0, 1, 1);

        tabWidget->addTab(tab2, QString());

        gridLayout_7->addWidget(tabWidget, 1, 0, 1, 1);

        tabWidgetActivitesDesServices->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_9 = new QGridLayout(tab_2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_4->setContentsMargins(-1, -1, 7, -1);
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_5);

        comboBoxRestaurataires = new QComboBox(tab_2);
        comboBoxRestaurataires->setObjectName(QString::fromUtf8("comboBoxRestaurataires"));
        comboBoxRestaurataires->setMaximumSize(QSize(150, 16777215));
        comboBoxRestaurataires->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, comboBoxRestaurataires);


        gridLayout_9->addLayout(formLayout_4, 0, 0, 1, 1);

        tabWidget_3 = new QTabWidget(tab_2);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tab1_2 = new QWidget();
        tab1_2->setObjectName(QString::fromUtf8("tab1_2"));
        gridLayout_10 = new QGridLayout(tab1_2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        tableWidgetActivitesResto = new QTableWidget(tab1_2);
        if (tableWidgetActivitesResto->columnCount() < 10)
            tableWidgetActivitesResto->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetActivitesResto->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidgetActivitesResto->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidgetActivitesResto->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidgetActivitesResto->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidgetActivitesResto->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidgetActivitesResto->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidgetActivitesResto->setHorizontalHeaderItem(6, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidgetActivitesResto->setHorizontalHeaderItem(7, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidgetActivitesResto->setHorizontalHeaderItem(8, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidgetActivitesResto->setHorizontalHeaderItem(9, __qtablewidgetitem23);
        tableWidgetActivitesResto->setObjectName(QString::fromUtf8("tableWidgetActivitesResto"));
        tableWidgetActivitesResto->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetActivitesResto->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetActivitesResto->horizontalHeader()->setDefaultSectionSize(150);
        tableWidgetActivitesResto->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_10->addWidget(tableWidgetActivitesResto, 0, 0, 1, 3);

        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(tab1_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        lineEditEncaisseActivite = new QLineEdit(tab1_2);
        lineEditEncaisseActivite->setObjectName(QString::fromUtf8("lineEditEncaisseActivite"));
        lineEditEncaisseActivite->setMaximumSize(QSize(133, 16777215));
        lineEditEncaisseActivite->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditEncaisseActivite->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEditEncaisseActivite);


        formLayout_9->setLayout(0, QFormLayout::LabelRole, horizontalLayout_4);

        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_10 = new QLabel(tab1_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(85, 16777215));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_10);

        lineEditRestantActivite = new QLineEdit(tab1_2);
        lineEditRestantActivite->setObjectName(QString::fromUtf8("lineEditRestantActivite"));
        lineEditRestantActivite->setMaximumSize(QSize(133, 16777215));
        lineEditRestantActivite->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRestantActivite->setReadOnly(true);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, lineEditRestantActivite);


        formLayout_9->setLayout(0, QFormLayout::FieldRole, formLayout_7);


        gridLayout_10->addLayout(formLayout_9, 1, 0, 1, 1);

        btn_imprimerFacture = new QPushButton(tab1_2);
        btn_imprimerFacture->setObjectName(QString::fromUtf8("btn_imprimerFacture"));
        btn_imprimerFacture->setMaximumSize(QSize(75, 23));
        btn_imprimerFacture->setLayoutDirection(Qt::RightToLeft);

        gridLayout_10->addWidget(btn_imprimerFacture, 1, 1, 1, 1);

        btn_details = new QPushButton(tab1_2);
        btn_details->setObjectName(QString::fromUtf8("btn_details"));
        btn_details->setMaximumSize(QSize(75, 23));
        btn_details->setLayoutDirection(Qt::RightToLeft);

        gridLayout_10->addWidget(btn_details, 1, 2, 1, 1);

        tabWidget_3->addTab(tab1_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_15 = new QGridLayout(tab_4);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        tableViewCloturesRestauration = new QTableView(tab_4);
        tableViewCloturesRestauration->setObjectName(QString::fromUtf8("tableViewCloturesRestauration"));
        tableViewCloturesRestauration->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewCloturesRestauration->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewCloturesRestauration->horizontalHeader()->setDefaultSectionSize(170);
        tableViewCloturesRestauration->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_15->addWidget(tableViewCloturesRestauration, 0, 0, 1, 2);

        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QString::fromUtf8("formLayout_10"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_12 = new QLabel(tab_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        lineEditEncaisseCloture = new QLineEdit(tab_4);
        lineEditEncaisseCloture->setObjectName(QString::fromUtf8("lineEditEncaisseCloture"));
        lineEditEncaisseCloture->setMaximumSize(QSize(133, 16777215));
        lineEditEncaisseCloture->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditEncaisseCloture->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEditEncaisseCloture);


        horizontalLayout_17->addLayout(horizontalLayout_5);

        formLayout_11 = new QFormLayout();
        formLayout_11->setObjectName(QString::fromUtf8("formLayout_11"));
        formLayout_11->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(85, 16777215));

        formLayout_11->setWidget(0, QFormLayout::LabelRole, label_13);

        lineEditClotureRestant = new QLineEdit(tab_4);
        lineEditClotureRestant->setObjectName(QString::fromUtf8("lineEditClotureRestant"));
        lineEditClotureRestant->setMaximumSize(QSize(133, 16777215));
        lineEditClotureRestant->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClotureRestant->setReadOnly(true);

        formLayout_11->setWidget(0, QFormLayout::FieldRole, lineEditClotureRestant);


        horizontalLayout_17->addLayout(formLayout_11);


        formLayout_10->setLayout(0, QFormLayout::LabelRole, horizontalLayout_17);

        formLayout_12 = new QFormLayout();
        formLayout_12->setObjectName(QString::fromUtf8("formLayout_12"));
        formLayout_12->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_24 = new QLabel(tab_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMaximumSize(QSize(85, 16777215));

        formLayout_12->setWidget(0, QFormLayout::LabelRole, label_24);

        lineEditClotureRetire = new QLineEdit(tab_4);
        lineEditClotureRetire->setObjectName(QString::fromUtf8("lineEditClotureRetire"));
        lineEditClotureRetire->setMaximumSize(QSize(133, 16777215));
        lineEditClotureRetire->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClotureRetire->setReadOnly(true);

        formLayout_12->setWidget(0, QFormLayout::FieldRole, lineEditClotureRetire);


        formLayout_10->setLayout(0, QFormLayout::FieldRole, formLayout_12);


        gridLayout_15->addLayout(formLayout_10, 1, 0, 1, 1);

        btn_detailsResto = new QPushButton(tab_4);
        btn_detailsResto->setObjectName(QString::fromUtf8("btn_detailsResto"));
        btn_detailsResto->setMaximumSize(QSize(75, 23));
        btn_detailsResto->setLayoutDirection(Qt::RightToLeft);

        gridLayout_15->addWidget(btn_detailsResto, 1, 1, 1, 1);

        tabWidget_3->addTab(tab_4, QString());
        tab2_2 = new QWidget();
        tab2_2->setObjectName(QString::fromUtf8("tab2_2"));
        gridLayout_14 = new QGridLayout(tab2_2);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        tableWidgetDureeActivitesResto = new QTableWidget(tab2_2);
        if (tableWidgetDureeActivitesResto->columnCount() < 3)
            tableWidgetDureeActivitesResto->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidgetDureeActivitesResto->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidgetDureeActivitesResto->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidgetDureeActivitesResto->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        tableWidgetDureeActivitesResto->setObjectName(QString::fromUtf8("tableWidgetDureeActivitesResto"));
        tableWidgetDureeActivitesResto->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetDureeActivitesResto->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetDureeActivitesResto->horizontalHeader()->setDefaultSectionSize(210);
        tableWidgetDureeActivitesResto->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidgetDureeActivitesResto->horizontalHeader()->setStretchLastSection(true);
        tableWidgetDureeActivitesResto->verticalHeader()->setVisible(false);
        tableWidgetDureeActivitesResto->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_14->addWidget(tableWidgetDureeActivitesResto, 0, 0, 1, 1);

        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        formLayout_8->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_8->setContentsMargins(-1, -1, 7, -1);
        label_11 = new QLabel(tab2_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(64, 20));
        label_11->setLayoutDirection(Qt::LeftToRight);

        formLayout_8->setWidget(0, QFormLayout::LabelRole, label_11);

        lineEditDureeTotaleResto = new QLineEdit(tab2_2);
        lineEditDureeTotaleResto->setObjectName(QString::fromUtf8("lineEditDureeTotaleResto"));
        lineEditDureeTotaleResto->setMinimumSize(QSize(190, 0));
        lineEditDureeTotaleResto->setMaximumSize(QSize(190, 16777215));
        lineEditDureeTotaleResto->setLayoutDirection(Qt::LeftToRight);
        lineEditDureeTotaleResto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDureeTotaleResto->setReadOnly(true);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, lineEditDureeTotaleResto);


        gridLayout_14->addLayout(formLayout_8, 1, 0, 1, 1);

        tabWidget_3->addTab(tab2_2, QString());

        gridLayout_9->addWidget(tabWidget_3, 1, 0, 1, 1);

        tabWidgetActivitesDesServices->addTab(tab_2, QString());

        gridLayout_12->addWidget(tabWidgetActivitesDesServices, 2, 0, 1, 3);


        retranslateUi(MdiBilanActivitesReception);

        tabWidgetActivitesDesServices->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MdiBilanActivitesReception);
    } // setupUi

    void retranslateUi(QWidget *MdiBilanActivitesReception)
    {
        MdiBilanActivitesReception->setWindowTitle(QApplication::translate("MdiBilanActivitesReception", "Form", 0, QApplication::UnicodeUTF8));
        label_logo->setText(QString());
        label_horloge->setText(QApplication::translate("MdiBilanActivitesReception", "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, QApplication::UnicodeUTF8));
        labelEnveloppe->setText(QString());
        labelNbMsgNonLus->setText(QApplication::translate("MdiBilanActivitesReception", "TextLabel", 0, QApplication::UnicodeUTF8));
        btn_lire->setText(QApplication::translate("MdiBilanActivitesReception", "Lire", 0, QApplication::UnicodeUTF8));
        label_heureDeConnection->setText(QApplication::translate("MdiBilanActivitesReception", "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MdiBilanActivitesReception", "P\303\251riode", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MdiBilanActivitesReception", "D\303\251but:", 0, QApplication::UnicodeUTF8));
        btn_setPeriode->setText(QApplication::translate("MdiBilanActivitesReception", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MdiBilanActivitesReception", "Intervalle de temps:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MdiBilanActivitesReception", "Fin:", 0, QApplication::UnicodeUTF8));
        btn_actualiser->setText(QApplication::translate("MdiBilanActivitesReception", "Actualiser", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MdiBilanActivitesReception", "R\303\251ceptionniste:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MdiBilanActivitesReception", "Reservations effectu\303\251es", 0, QApplication::UnicodeUTF8));
        labelNbReserv->setText(QApplication::translate("MdiBilanActivitesReception", "nb de r\303\251servations", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetReserv->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MdiBilanActivitesReception", "Client", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetReserv->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MdiBilanActivitesReception", "Date de demande", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetReserv->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MdiBilanActivitesReception", "D\303\251but de location", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetReserv->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MdiBilanActivitesReception", "Dur\303\251e de location", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetReserv->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MdiBilanActivitesReception", "Chambre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetReserv->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MdiBilanActivitesReception", "Ex\303\251cut\303\251e", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MdiBilanActivitesReception", "Avance totale per\303\247ue :", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MdiBilanActivitesReception", "Locations effectu\303\251es", 0, QApplication::UnicodeUTF8));
        labelNbAnomalies->setText(QApplication::translate("MdiBilanActivitesReception", "nb de r\303\251servations", 0, QApplication::UnicodeUTF8));
        labelNbOccup->setText(QApplication::translate("MdiBilanActivitesReception", "nb de d'occupations", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetOccup->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MdiBilanActivitesReception", "Client", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetOccup->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MdiBilanActivitesReception", "D\303\251but de location", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetOccup->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MdiBilanActivitesReception", "Fin de location", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetOccup->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MdiBilanActivitesReception", "Dur\303\251e de location", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetOccup->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MdiBilanActivitesReception", "Chambre", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MdiBilanActivitesReception", "Montant total per\303\247u :", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MdiBilanActivitesReception", "Activit\303\251s", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MdiBilanActivitesReception", "Montant encaiss\303\251 :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MdiBilanActivitesReception", "Montant restant :", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MdiBilanActivitesReception", "Montant retir\303\251 :", 0, QApplication::UnicodeUTF8));
        btn_detailsRecept->setText(QApplication::translate("MdiBilanActivitesReception", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("MdiBilanActivitesReception", "Cl\303\264tures", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetDureeActivites->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("MdiBilanActivitesReception", "D\303\251but du service", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetDureeActivites->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("MdiBilanActivitesReception", "Fin du service", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetDureeActivites->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("MdiBilanActivitesReception", "Dur\303\251e du service", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MdiBilanActivitesReception", "Dur\303\251e totale:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MdiBilanActivitesReception", "Dur\303\251e des activit\303\251s", 0, QApplication::UnicodeUTF8));
        tabWidgetActivitesDesServices->setTabText(tabWidgetActivitesDesServices->indexOf(tab), QApplication::translate("MdiBilanActivitesReception", "Activit\303\251s service r\303\251ception", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MdiBilanActivitesReception", "Restaurataire :", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetActivitesResto->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MdiBilanActivitesReception", "Facture", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetActivitesResto->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MdiBilanActivitesReception", "Client", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetActivitesResto->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("MdiBilanActivitesReception", "Date arriv\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetActivitesResto->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("MdiBilanActivitesReception", "Date d\303\251part", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetActivitesResto->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("MdiBilanActivitesReception", "Dur\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetActivitesResto->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QApplication::translate("MdiBilanActivitesReception", "Total \303\240 payer", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetActivitesResto->horizontalHeaderItem(6);
        ___qtablewidgetitem20->setText(QApplication::translate("MdiBilanActivitesReception", "Montant encaiss\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetActivitesResto->horizontalHeaderItem(7);
        ___qtablewidgetitem21->setText(QApplication::translate("MdiBilanActivitesReception", "Montant restant", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetActivitesResto->horizontalHeaderItem(8);
        ___qtablewidgetitem22->setText(QApplication::translate("MdiBilanActivitesReception", "Matricule du caissier", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetActivitesResto->horizontalHeaderItem(9);
        ___qtablewidgetitem23->setText(QApplication::translate("MdiBilanActivitesReception", "IdRepasCResto", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MdiBilanActivitesReception", "Montant encaiss\303\251 :", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MdiBilanActivitesReception", "Montant restant :", 0, QApplication::UnicodeUTF8));
        btn_imprimerFacture->setText(QApplication::translate("MdiBilanActivitesReception", "Imprimer", 0, QApplication::UnicodeUTF8));
        btn_details->setText(QApplication::translate("MdiBilanActivitesReception", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab1_2), QApplication::translate("MdiBilanActivitesReception", "Activit\303\251s", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MdiBilanActivitesReception", "Montant encaiss\303\251 :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MdiBilanActivitesReception", "Montant restant :", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MdiBilanActivitesReception", "Montant retir\303\251 :", 0, QApplication::UnicodeUTF8));
        btn_detailsResto->setText(QApplication::translate("MdiBilanActivitesReception", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_4), QApplication::translate("MdiBilanActivitesReception", "Cl\303\264tures", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidgetDureeActivitesResto->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QApplication::translate("MdiBilanActivitesReception", "D\303\251but du service", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidgetDureeActivitesResto->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QApplication::translate("MdiBilanActivitesReception", "Fin du service", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidgetDureeActivitesResto->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QApplication::translate("MdiBilanActivitesReception", "Dur\303\251e du service", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MdiBilanActivitesReception", "Dur\303\251e totale:", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab2_2), QApplication::translate("MdiBilanActivitesReception", "Dur\303\251e des activit\303\251s", 0, QApplication::UnicodeUTF8));
        tabWidgetActivitesDesServices->setTabText(tabWidgetActivitesDesServices->indexOf(tab_2), QApplication::translate("MdiBilanActivitesReception", "Activit\303\251s service restauration", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MdiBilanActivitesReception: public Ui_MdiBilanActivitesReception {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDIBILANACTIVITESRECEPTION_H
