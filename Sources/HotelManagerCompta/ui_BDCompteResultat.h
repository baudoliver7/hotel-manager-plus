/********************************************************************************
** Form generated from reading UI file 'BDCompteResultat.ui'
**
** Created: Fri 25. Jan 23:18:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCOMPTERESULTAT_H
#define UI_BDCOMPTERESULTAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSplitter>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_BDCompteResultat
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *rb_annuelle;
    QRadioButton *rb_periode;
    QSplitter *splitter;
    QLineEdit *lineEditDebut;
    QToolButton *btn_debut;
    QLabel *label;
    QSplitter *splitter_2;
    QLineEdit *lineEditFin;
    QToolButton *btn_fin;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEditProduits;
    QLabel *label_4;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditCharges;
    QLabel *label_6;
    QFormLayout *formLayout_3;
    QLabel *labelResultat;
    QLineEdit *lineEditResultat;

    void setupUi(QDialog *BDCompteResultat)
    {
        if (BDCompteResultat->objectName().isEmpty())
            BDCompteResultat->setObjectName(QString::fromUtf8("BDCompteResultat"));
        BDCompteResultat->resize(911, 547);
        gridLayout_4 = new QGridLayout(BDCompteResultat);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(BDCompteResultat);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rb_annuelle = new QRadioButton(groupBox);
        rb_annuelle->setObjectName(QString::fromUtf8("rb_annuelle"));

        gridLayout->addWidget(rb_annuelle, 0, 0, 1, 1);

        rb_periode = new QRadioButton(groupBox);
        rb_periode->setObjectName(QString::fromUtf8("rb_periode"));

        gridLayout->addWidget(rb_periode, 0, 1, 1, 1);

        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        lineEditDebut = new QLineEdit(splitter);
        lineEditDebut->setObjectName(QString::fromUtf8("lineEditDebut"));
        lineEditDebut->setReadOnly(true);
        splitter->addWidget(lineEditDebut);
        btn_debut = new QToolButton(splitter);
        btn_debut->setObjectName(QString::fromUtf8("btn_debut"));
        splitter->addWidget(btn_debut);

        gridLayout->addWidget(splitter, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        splitter_2 = new QSplitter(groupBox);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        lineEditFin = new QLineEdit(splitter_2);
        lineEditFin->setObjectName(QString::fromUtf8("lineEditFin"));
        lineEditFin->setReadOnly(true);
        splitter_2->addWidget(lineEditFin);
        btn_fin = new QToolButton(splitter_2);
        btn_fin->setObjectName(QString::fromUtf8("btn_fin"));
        splitter_2->addWidget(btn_fin);

        gridLayout->addWidget(splitter_2, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(BDCompteResultat);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setDefaultSectionSize(210);

        gridLayout_3->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(BDCompteResultat);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEditProduits = new QLineEdit(groupBox_3);
        lineEditProduits->setObjectName(QString::fromUtf8("lineEditProduits"));
        lineEditProduits->setMaximumSize(QSize(130, 16777215));
        lineEditProduits->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditProduits);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEditCharges = new QLineEdit(groupBox_3);
        lineEditCharges->setObjectName(QString::fromUtf8("lineEditCharges"));
        lineEditCharges->setMaximumSize(QSize(130, 16777215));
        lineEditCharges->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditCharges);


        gridLayout_2->addLayout(formLayout_2, 0, 2, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 0, 3, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        labelResultat = new QLabel(groupBox_3);
        labelResultat->setObjectName(QString::fromUtf8("labelResultat"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelResultat);

        lineEditResultat = new QLineEdit(groupBox_3);
        lineEditResultat->setObjectName(QString::fromUtf8("lineEditResultat"));
        lineEditResultat->setMaximumSize(QSize(130, 16777215));
        lineEditResultat->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEditResultat);


        gridLayout_2->addLayout(formLayout_3, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 1);


        retranslateUi(BDCompteResultat);

        QMetaObject::connectSlotsByName(BDCompteResultat);
    } // setupUi

    void retranslateUi(QDialog *BDCompteResultat)
    {
        BDCompteResultat->setWindowTitle(QApplication::translate("BDCompteResultat", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDCompteResultat", "P\303\251riode s\303\251lectionn\303\251e", 0, QApplication::UnicodeUTF8));
        rb_annuelle->setText(QApplication::translate("BDCompteResultat", "Annuelle", 0, QApplication::UnicodeUTF8));
        rb_periode->setText(QApplication::translate("BDCompteResultat", "La p\303\251riode du", 0, QApplication::UnicodeUTF8));
        btn_debut->setText(QApplication::translate("BDCompteResultat", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDCompteResultat", "au", 0, QApplication::UnicodeUTF8));
        btn_fin->setText(QApplication::translate("BDCompteResultat", "...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDCompteResultat", "Inventaire des charges et produits", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BDCompteResultat", "Charges", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BDCompteResultat", "Montant", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BDCompteResultat", "Produits", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BDCompteResultat", "Montant", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("BDCompteResultat", "R\303\251sultats", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDCompteResultat", "Produits :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDCompteResultat", "-", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDCompteResultat", "Charges :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDCompteResultat", "=", 0, QApplication::UnicodeUTF8));
        labelResultat->setText(QApplication::translate("BDCompteResultat", "B\303\251n\303\251fice comptable :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDCompteResultat: public Ui_BDCompteResultat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCOMPTERESULTAT_H
