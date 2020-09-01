/********************************************************************************
** Form generated from reading UI file 'BDDetailsRepas.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDDETAILSREPAS_H
#define UI_BDDETAILSREPAS_H

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
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_BDDetailsRepas
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditTotal;
    QFormLayout *formLayout_2;
    QPushButton *btn_imprimerFacture;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDDetailsRepas)
    {
        if (BDDetailsRepas->objectName().isEmpty())
            BDDetailsRepas->setObjectName(QString::fromUtf8("BDDetailsRepas"));
        BDDetailsRepas->resize(646, 438);
        gridLayout_2 = new QGridLayout(BDDetailsRepas);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(BDDetailsRepas);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(groupBox);
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
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 8, -1);
        label = new QLabel(BDDetailsRepas);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(30, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditTotal = new QLineEdit(BDDetailsRepas);
        lineEditTotal->setObjectName(QString::fromUtf8("lineEditTotal"));
        lineEditTotal->setMaximumSize(QSize(133, 16777215));
        lineEditTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTotal->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditTotal);


        gridLayout_2->addLayout(formLayout, 1, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_2->setContentsMargins(-1, -1, 8, -1);
        btn_imprimerFacture = new QPushButton(BDDetailsRepas);
        btn_imprimerFacture->setObjectName(QString::fromUtf8("btn_imprimerFacture"));
        btn_imprimerFacture->setMaximumSize(QSize(75, 23));
        btn_imprimerFacture->setLayoutDirection(Qt::RightToLeft);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, btn_imprimerFacture);

        btn_fermer = new QPushButton(BDDetailsRepas);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_fermer);


        gridLayout_2->addLayout(formLayout_2, 2, 0, 1, 1);


        retranslateUi(BDDetailsRepas);

        QMetaObject::connectSlotsByName(BDDetailsRepas);
    } // setupUi

    void retranslateUi(QDialog *BDDetailsRepas)
    {
        BDDetailsRepas->setWindowTitle(QApplication::translate("BDDetailsRepas", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDDetailsRepas", "Menus command\303\251s", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BDDetailsRepas", "Menu", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BDDetailsRepas", "Prix unitaire", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BDDetailsRepas", "Quantit\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BDDetailsRepas", "Prix total", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDDetailsRepas", "Total :", 0, QApplication::UnicodeUTF8));
        btn_imprimerFacture->setText(QApplication::translate("BDDetailsRepas", "Imprimer", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDDetailsRepas", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDDetailsRepas: public Ui_BDDetailsRepas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDDETAILSREPAS_H
