/********************************************************************************
** Form generated from reading UI file 'DgRechercherUneOccupation.ui'
**
** Created: Sun 27. Oct 20:00:15 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DGRECHERCHERUNEOCCUPATION_H
#define UI_DGRECHERCHERUNEOCCUPATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_DgRechercherUneOccupation
{
public:
    QGridLayout *gridLayout_7;
    QFormLayout *formLayout_2;
    QLabel *label;
    QComboBox *typesDeChambre;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QRadioButton *rb_locationEnCours;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rb_periode;
    QLineEdit *lineEditDebut;
    QToolButton *btn_debut;
    QLabel *label_7;
    QLineEdit *lineEditFin;
    QToolButton *btn_fin;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QGroupBox *groupBoxMR;
    QGridLayout *gridLayout_6;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *lineEditMontantTotal;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QLineEdit *lineEditMontantRestant;
    QFormLayout *formLayout_6;
    QLabel *label_6;
    QSpinBox *spinBoxMontantRegl;
    QRadioButton *rb_payementLoc;
    QRadioButton *rb_ailleursLoc;
    QPushButton *btn_enregistrer;
    QGroupBox *groupBoxRestaurationRegl;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_4;
    QLabel *label_10;
    QLineEdit *lineEditRestaurationRegl;
    QFormLayout *formLayout_9;
    QLabel *label_14;
    QLineEdit *lineEditMontantRestantRestoMR;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QSpinBox *spinBoxRestaurationMR;
    QRadioButton *rb_payementResto;
    QRadioButton *rb_ailleursResto;
    QPushButton *btn_enregistrerResto;
    QGroupBox *groupBoxFraisSup;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout_5;
    QLabel *label_12;
    QLineEdit *lineEditFraisSupRegl;
    QFormLayout *formLayout_10;
    QLabel *label_15;
    QLineEdit *lineEditMontantRestantFraisSupMR;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_13;
    QSpinBox *spinBoxFraisSupMR;
    QRadioButton *rb_payementFraisSup;
    QRadioButton *rb_ailleursFraisSup;
    QPushButton *btn_enregistrerFraisSup;
    QGroupBox *groupBoxFS;
    QGridLayout *gridLayout;
    QFormLayout *formLayout_7;
    QLabel *label_2;
    QLineEdit *lineEditRestauration;
    QFormLayout *formLayout_8;
    QLabel *label_3;
    QSpinBox *spinBoxMontantSup;
    QPushButton *btn_liberer;
    QPushButton *btn_imprimerRecu;
    QPushButton *btn_supprimer;
    QPushButton *btn_annuler;

    void setupUi(QDialog *DgRechercherUneOccupation)
    {
        if (DgRechercherUneOccupation->objectName().isEmpty())
            DgRechercherUneOccupation->setObjectName(QString::fromUtf8("DgRechercherUneOccupation"));
        DgRechercherUneOccupation->resize(654, 661);
        DgRechercherUneOccupation->setLayoutDirection(Qt::LeftToRight);
        gridLayout_7 = new QGridLayout(DgRechercherUneOccupation);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label = new QLabel(DgRechercherUneOccupation);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        typesDeChambre = new QComboBox(DgRechercherUneOccupation);
        typesDeChambre->setObjectName(QString::fromUtf8("typesDeChambre"));
        typesDeChambre->setMaximumSize(QSize(250, 16777215));
        typesDeChambre->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, typesDeChambre);


        gridLayout_7->addLayout(formLayout_2, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(DgRechercherUneOccupation);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        rb_locationEnCours = new QRadioButton(groupBox_4);
        rb_locationEnCours->setObjectName(QString::fromUtf8("rb_locationEnCours"));

        gridLayout_4->addWidget(rb_locationEnCours, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rb_periode = new QRadioButton(groupBox_4);
        rb_periode->setObjectName(QString::fromUtf8("rb_periode"));

        horizontalLayout->addWidget(rb_periode);

        lineEditDebut = new QLineEdit(groupBox_4);
        lineEditDebut->setObjectName(QString::fromUtf8("lineEditDebut"));
        lineEditDebut->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDebut->setReadOnly(true);

        horizontalLayout->addWidget(lineEditDebut);

        btn_debut = new QToolButton(groupBox_4);
        btn_debut->setObjectName(QString::fromUtf8("btn_debut"));

        horizontalLayout->addWidget(btn_debut);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        lineEditFin = new QLineEdit(groupBox_4);
        lineEditFin->setObjectName(QString::fromUtf8("lineEditFin"));
        lineEditFin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFin->setReadOnly(true);

        horizontalLayout->addWidget(lineEditFin);

        btn_fin = new QToolButton(groupBox_4);
        btn_fin->setObjectName(QString::fromUtf8("btn_fin"));

        horizontalLayout->addWidget(btn_fin);


        gridLayout_4->addLayout(horizontalLayout, 0, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_4, 1, 0, 1, 4);

        groupBox_2 = new QGroupBox(DgRechercherUneOccupation);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_2, 2, 0, 1, 4);

        groupBoxMR = new QGroupBox(DgRechercherUneOccupation);
        groupBoxMR->setObjectName(QString::fromUtf8("groupBoxMR"));
        gridLayout_6 = new QGridLayout(groupBoxMR);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_4 = new QLabel(groupBoxMR);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        lineEditMontantTotal = new QLineEdit(groupBoxMR);
        lineEditMontantTotal->setObjectName(QString::fromUtf8("lineEditMontantTotal"));
        lineEditMontantTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantTotal->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditMontantTotal);


        gridLayout_6->addLayout(formLayout, 0, 0, 1, 2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_5 = new QLabel(groupBoxMR);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        lineEditMontantRestant = new QLineEdit(groupBoxMR);
        lineEditMontantRestant->setObjectName(QString::fromUtf8("lineEditMontantRestant"));
        lineEditMontantRestant->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantRestant->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEditMontantRestant);


        gridLayout_6->addLayout(formLayout_3, 0, 2, 1, 1);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        label_6 = new QLabel(groupBoxMR);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_6);

        spinBoxMontantRegl = new QSpinBox(groupBoxMR);
        spinBoxMontantRegl->setObjectName(QString::fromUtf8("spinBoxMontantRegl"));
        spinBoxMontantRegl->setMaximum(100000000);
        spinBoxMontantRegl->setSingleStep(1000);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, spinBoxMontantRegl);


        gridLayout_6->addLayout(formLayout_6, 0, 3, 1, 1);

        rb_payementLoc = new QRadioButton(groupBoxMR);
        rb_payementLoc->setObjectName(QString::fromUtf8("rb_payementLoc"));

        gridLayout_6->addWidget(rb_payementLoc, 1, 0, 1, 1);

        rb_ailleursLoc = new QRadioButton(groupBoxMR);
        rb_ailleursLoc->setObjectName(QString::fromUtf8("rb_ailleursLoc"));

        gridLayout_6->addWidget(rb_ailleursLoc, 1, 1, 1, 1);

        btn_enregistrer = new QPushButton(groupBoxMR);
        btn_enregistrer->setObjectName(QString::fromUtf8("btn_enregistrer"));
        btn_enregistrer->setMaximumSize(QSize(75, 23));
        btn_enregistrer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_6->addWidget(btn_enregistrer, 1, 3, 1, 1);


        gridLayout_7->addWidget(groupBoxMR, 3, 0, 1, 4);

        groupBoxRestaurationRegl = new QGroupBox(DgRechercherUneOccupation);
        groupBoxRestaurationRegl->setObjectName(QString::fromUtf8("groupBoxRestaurationRegl"));
        gridLayout_3 = new QGridLayout(groupBoxRestaurationRegl);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_10 = new QLabel(groupBoxRestaurationRegl);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_10);

        lineEditRestaurationRegl = new QLineEdit(groupBoxRestaurationRegl);
        lineEditRestaurationRegl->setObjectName(QString::fromUtf8("lineEditRestaurationRegl"));
        lineEditRestaurationRegl->setMaximumSize(QSize(120, 16777215));
        lineEditRestaurationRegl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRestaurationRegl->setReadOnly(true);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEditRestaurationRegl);


        gridLayout_3->addLayout(formLayout_4, 0, 0, 1, 2);

        formLayout_9 = new QFormLayout();
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        label_14 = new QLabel(groupBoxRestaurationRegl);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, label_14);

        lineEditMontantRestantRestoMR = new QLineEdit(groupBoxRestaurationRegl);
        lineEditMontantRestantRestoMR->setObjectName(QString::fromUtf8("lineEditMontantRestantRestoMR"));
        lineEditMontantRestantRestoMR->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantRestantRestoMR->setReadOnly(true);

        formLayout_9->setWidget(0, QFormLayout::FieldRole, lineEditMontantRestantRestoMR);


        gridLayout_3->addLayout(formLayout_9, 0, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_11 = new QLabel(groupBoxRestaurationRegl);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_2->addWidget(label_11);

        spinBoxRestaurationMR = new QSpinBox(groupBoxRestaurationRegl);
        spinBoxRestaurationMR->setObjectName(QString::fromUtf8("spinBoxRestaurationMR"));
        spinBoxRestaurationMR->setMaximumSize(QSize(16777215, 16777215));
        spinBoxRestaurationMR->setMaximum(100000000);
        spinBoxRestaurationMR->setSingleStep(1000);

        horizontalLayout_2->addWidget(spinBoxRestaurationMR);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 3, 1, 1);

        rb_payementResto = new QRadioButton(groupBoxRestaurationRegl);
        rb_payementResto->setObjectName(QString::fromUtf8("rb_payementResto"));

        gridLayout_3->addWidget(rb_payementResto, 1, 0, 1, 1);

        rb_ailleursResto = new QRadioButton(groupBoxRestaurationRegl);
        rb_ailleursResto->setObjectName(QString::fromUtf8("rb_ailleursResto"));

        gridLayout_3->addWidget(rb_ailleursResto, 1, 1, 1, 1);

        btn_enregistrerResto = new QPushButton(groupBoxRestaurationRegl);
        btn_enregistrerResto->setObjectName(QString::fromUtf8("btn_enregistrerResto"));
        btn_enregistrerResto->setMaximumSize(QSize(75, 23));
        btn_enregistrerResto->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(btn_enregistrerResto, 1, 3, 1, 1);


        gridLayout_7->addWidget(groupBoxRestaurationRegl, 4, 0, 1, 4);

        groupBoxFraisSup = new QGroupBox(DgRechercherUneOccupation);
        groupBoxFraisSup->setObjectName(QString::fromUtf8("groupBoxFraisSup"));
        gridLayout_5 = new QGridLayout(groupBoxFraisSup);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_12 = new QLabel(groupBoxFraisSup);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_12);

        lineEditFraisSupRegl = new QLineEdit(groupBoxFraisSup);
        lineEditFraisSupRegl->setObjectName(QString::fromUtf8("lineEditFraisSupRegl"));
        lineEditFraisSupRegl->setMaximumSize(QSize(120, 16777215));
        lineEditFraisSupRegl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFraisSupRegl->setReadOnly(true);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, lineEditFraisSupRegl);


        gridLayout_5->addLayout(formLayout_5, 0, 0, 1, 2);

        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QString::fromUtf8("formLayout_10"));
        label_15 = new QLabel(groupBoxFraisSup);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_10->setWidget(0, QFormLayout::LabelRole, label_15);

        lineEditMontantRestantFraisSupMR = new QLineEdit(groupBoxFraisSup);
        lineEditMontantRestantFraisSupMR->setObjectName(QString::fromUtf8("lineEditMontantRestantFraisSupMR"));
        lineEditMontantRestantFraisSupMR->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantRestantFraisSupMR->setReadOnly(true);

        formLayout_10->setWidget(0, QFormLayout::FieldRole, lineEditMontantRestantFraisSupMR);


        gridLayout_5->addLayout(formLayout_10, 0, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_13 = new QLabel(groupBoxFraisSup);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_3->addWidget(label_13);

        spinBoxFraisSupMR = new QSpinBox(groupBoxFraisSup);
        spinBoxFraisSupMR->setObjectName(QString::fromUtf8("spinBoxFraisSupMR"));
        spinBoxFraisSupMR->setMaximumSize(QSize(16777215, 16777215));
        spinBoxFraisSupMR->setMaximum(100000000);
        spinBoxFraisSupMR->setSingleStep(1000);

        horizontalLayout_3->addWidget(spinBoxFraisSupMR);


        gridLayout_5->addLayout(horizontalLayout_3, 0, 3, 1, 1);

        rb_payementFraisSup = new QRadioButton(groupBoxFraisSup);
        rb_payementFraisSup->setObjectName(QString::fromUtf8("rb_payementFraisSup"));

        gridLayout_5->addWidget(rb_payementFraisSup, 1, 0, 1, 1);

        rb_ailleursFraisSup = new QRadioButton(groupBoxFraisSup);
        rb_ailleursFraisSup->setObjectName(QString::fromUtf8("rb_ailleursFraisSup"));

        gridLayout_5->addWidget(rb_ailleursFraisSup, 1, 1, 1, 2);

        btn_enregistrerFraisSup = new QPushButton(groupBoxFraisSup);
        btn_enregistrerFraisSup->setObjectName(QString::fromUtf8("btn_enregistrerFraisSup"));
        btn_enregistrerFraisSup->setMaximumSize(QSize(75, 23));
        btn_enregistrerFraisSup->setLayoutDirection(Qt::RightToLeft);

        gridLayout_5->addWidget(btn_enregistrerFraisSup, 1, 3, 1, 1);


        gridLayout_7->addWidget(groupBoxFraisSup, 5, 0, 1, 4);

        groupBoxFS = new QGroupBox(DgRechercherUneOccupation);
        groupBoxFS->setObjectName(QString::fromUtf8("groupBoxFS"));
        gridLayout = new QGridLayout(groupBoxFS);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_2 = new QLabel(groupBoxFS);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEditRestauration = new QLineEdit(groupBoxFS);
        lineEditRestauration->setObjectName(QString::fromUtf8("lineEditRestauration"));
        lineEditRestauration->setMaximumSize(QSize(120, 16777215));
        lineEditRestauration->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRestauration->setReadOnly(true);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, lineEditRestauration);


        gridLayout->addLayout(formLayout_7, 0, 0, 1, 1);

        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        label_3 = new QLabel(groupBoxFS);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, label_3);

        spinBoxMontantSup = new QSpinBox(groupBoxFS);
        spinBoxMontantSup->setObjectName(QString::fromUtf8("spinBoxMontantSup"));
        spinBoxMontantSup->setMaximumSize(QSize(16777215, 16777215));
        spinBoxMontantSup->setMaximum(100000000);
        spinBoxMontantSup->setSingleStep(1000);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, spinBoxMontantSup);


        gridLayout->addLayout(formLayout_8, 0, 1, 1, 1);

        btn_liberer = new QPushButton(groupBoxFS);
        btn_liberer->setObjectName(QString::fromUtf8("btn_liberer"));
        btn_liberer->setMaximumSize(QSize(75, 16777215));
        btn_liberer->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(btn_liberer, 0, 2, 1, 1);


        gridLayout_7->addWidget(groupBoxFS, 6, 0, 1, 4);

        btn_imprimerRecu = new QPushButton(DgRechercherUneOccupation);
        btn_imprimerRecu->setObjectName(QString::fromUtf8("btn_imprimerRecu"));
        btn_imprimerRecu->setMaximumSize(QSize(110, 23));
        btn_imprimerRecu->setLayoutDirection(Qt::LeftToRight);

        gridLayout_7->addWidget(btn_imprimerRecu, 7, 1, 1, 1);

        btn_supprimer = new QPushButton(DgRechercherUneOccupation);
        btn_supprimer->setObjectName(QString::fromUtf8("btn_supprimer"));
        btn_supprimer->setMaximumSize(QSize(110, 23));
        btn_supprimer->setLayoutDirection(Qt::LeftToRight);

        gridLayout_7->addWidget(btn_supprimer, 7, 2, 1, 1);

        btn_annuler = new QPushButton(DgRechercherUneOccupation);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 16777215));
        btn_annuler->setLayoutDirection(Qt::LeftToRight);

        gridLayout_7->addWidget(btn_annuler, 7, 3, 1, 1);


        retranslateUi(DgRechercherUneOccupation);

        QMetaObject::connectSlotsByName(DgRechercherUneOccupation);
    } // setupUi

    void retranslateUi(QDialog *DgRechercherUneOccupation)
    {
        DgRechercherUneOccupation->setWindowTitle(QApplication::translate("DgRechercherUneOccupation", "Rechercher une occupation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DgRechercherUneOccupation", "Type de chambre:", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("DgRechercherUneOccupation", "Crit\303\250re de s\303\251lection", 0, QApplication::UnicodeUTF8));
        rb_locationEnCours->setText(QApplication::translate("DgRechercherUneOccupation", "Location en cours", 0, QApplication::UnicodeUTF8));
        rb_periode->setText(QApplication::translate("DgRechercherUneOccupation", "P\303\251riode allant du", 0, QApplication::UnicodeUTF8));
        btn_debut->setText(QApplication::translate("DgRechercherUneOccupation", "...", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DgRechercherUneOccupation", "au", 0, QApplication::UnicodeUTF8));
        btn_fin->setText(QApplication::translate("DgRechercherUneOccupation", "...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DgRechercherUneOccupation", "Locations", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DgRechercherUneOccupation", "NumeroReserv", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DgRechercherUneOccupation", "Chambre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DgRechercherUneOccupation", "Date d'entr\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DgRechercherUneOccupation", "Locataire", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DgRechercherUneOccupation", "Dur\303\251e en jours", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("DgRechercherUneOccupation", "Date de sortie", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("DgRechercherUneOccupation", "Prix total", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("DgRechercherUneOccupation", "Montant vers\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("DgRechercherUneOccupation", "Montant restant", 0, QApplication::UnicodeUTF8));
        groupBoxMR->setTitle(QApplication::translate("DgRechercherUneOccupation", "R\303\250glement de location", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DgRechercherUneOccupation", "Montant total :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DgRechercherUneOccupation", "Montant restant :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DgRechercherUneOccupation", "Montant de r\303\250glement :", 0, QApplication::UnicodeUTF8));
        rb_payementLoc->setText(QApplication::translate("DgRechercherUneOccupation", "payement \303\240 la caisse", 0, QApplication::UnicodeUTF8));
        rb_ailleursLoc->setText(QApplication::translate("DgRechercherUneOccupation", "ailleurs", 0, QApplication::UnicodeUTF8));
        btn_enregistrer->setText(QApplication::translate("DgRechercherUneOccupation", "Enregistrer", 0, QApplication::UnicodeUTF8));
        groupBoxRestaurationRegl->setTitle(QApplication::translate("DgRechercherUneOccupation", "R\303\250glement de la restauration", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("DgRechercherUneOccupation", "Restauration :", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("DgRechercherUneOccupation", "Montant restant :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("DgRechercherUneOccupation", "Montant de r\303\250glement :", 0, QApplication::UnicodeUTF8));
        rb_payementResto->setText(QApplication::translate("DgRechercherUneOccupation", "payement \303\240 la caisse", 0, QApplication::UnicodeUTF8));
        rb_ailleursResto->setText(QApplication::translate("DgRechercherUneOccupation", "ailleurs", 0, QApplication::UnicodeUTF8));
        btn_enregistrerResto->setText(QApplication::translate("DgRechercherUneOccupation", "Enregistrer", 0, QApplication::UnicodeUTF8));
        groupBoxFraisSup->setTitle(QApplication::translate("DgRechercherUneOccupation", "R\303\250glement de p\303\251nalit\303\251 de r\303\251tard de sortie", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("DgRechercherUneOccupation", "P\303\251nalit\303\251 totale :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("DgRechercherUneOccupation", "Montant restant :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("DgRechercherUneOccupation", "Montant de r\303\250glement :", 0, QApplication::UnicodeUTF8));
        rb_payementFraisSup->setText(QApplication::translate("DgRechercherUneOccupation", "payement \303\240 la caisse", 0, QApplication::UnicodeUTF8));
        rb_ailleursFraisSup->setText(QApplication::translate("DgRechercherUneOccupation", "ailleurs", 0, QApplication::UnicodeUTF8));
        btn_enregistrerFraisSup->setText(QApplication::translate("DgRechercherUneOccupation", "Enregistrer", 0, QApplication::UnicodeUTF8));
        groupBoxFS->setTitle(QApplication::translate("DgRechercherUneOccupation", "Frais suppl\303\251mentaires", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DgRechercherUneOccupation", "Restauration :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DgRechercherUneOccupation", "P\303\251nalit\303\251 de sortie :", 0, QApplication::UnicodeUTF8));
        btn_liberer->setText(QApplication::translate("DgRechercherUneOccupation", "Lib\303\251rer", 0, QApplication::UnicodeUTF8));
        btn_imprimerRecu->setText(QApplication::translate("DgRechercherUneOccupation", "Imprimer le r\303\251\303\247u", 0, QApplication::UnicodeUTF8));
        btn_supprimer->setText(QApplication::translate("DgRechercherUneOccupation", "Annuler la location", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("DgRechercherUneOccupation", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DgRechercherUneOccupation: public Ui_DgRechercherUneOccupation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DGRECHERCHERUNEOCCUPATION_H
