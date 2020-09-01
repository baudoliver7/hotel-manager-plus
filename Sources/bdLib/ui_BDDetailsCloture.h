/********************************************************************************
** Form generated from reading UI file 'BDDetailsCloture.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDDETAILSCLOTURE_H
#define UI_BDDETAILSCLOTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_BDDetailsCloture
{
public:
    QGridLayout *gridLayout;
    QTableView *tableViewActivites;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDDetailsCloture)
    {
        if (BDDetailsCloture->objectName().isEmpty())
            BDDetailsCloture->setObjectName(QString::fromUtf8("BDDetailsCloture"));
        BDDetailsCloture->resize(938, 539);
        gridLayout = new QGridLayout(BDDetailsCloture);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableViewActivites = new QTableView(BDDetailsCloture);
        tableViewActivites->setObjectName(QString::fromUtf8("tableViewActivites"));
        tableViewActivites->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewActivites->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewActivites->horizontalHeader()->setDefaultSectionSize(210);
        tableViewActivites->verticalHeader()->setDefaultSectionSize(25);

        gridLayout->addWidget(tableViewActivites, 0, 0, 1, 2);

        btn_fermer = new QPushButton(BDDetailsCloture);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(btn_fermer, 1, 1, 1, 1);


        retranslateUi(BDDetailsCloture);

        QMetaObject::connectSlotsByName(BDDetailsCloture);
    } // setupUi

    void retranslateUi(QDialog *BDDetailsCloture)
    {
        BDDetailsCloture->setWindowTitle(QApplication::translate("BDDetailsCloture", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDDetailsCloture", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDDetailsCloture: public Ui_BDDetailsCloture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDDETAILSCLOTURE_H
