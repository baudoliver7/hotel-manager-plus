/********************************************************************************
** Form generated from reading UI file 'BDConfigComptaService.ui'
**
** Created: Fri 25. Jan 23:18:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCONFIGCOMPTASERVICE_H
#define UI_BDCONFIGCOMPTASERVICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_BDConfigComptaService
{
public:
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBoxServices;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QSplitter *splitter;
    QPushButton *btn_editer;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDConfigComptaService)
    {
        if (BDConfigComptaService->objectName().isEmpty())
            BDConfigComptaService->setObjectName(QString::fromUtf8("BDConfigComptaService"));
        BDConfigComptaService->resize(535, 321);
        gridLayout_2 = new QGridLayout(BDConfigComptaService);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(BDConfigComptaService);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBoxServices = new QComboBox(BDConfigComptaService);
        comboBoxServices->setObjectName(QString::fromUtf8("comboBoxServices"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxServices);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        groupBox = new QGroupBox(BDConfigComptaService);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setDefaultSectionSize(200);

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setLayoutDirection(Qt::RightToLeft);
        splitter->setOrientation(Qt::Horizontal);
        btn_editer = new QPushButton(splitter);
        btn_editer->setObjectName(QString::fromUtf8("btn_editer"));
        btn_editer->setMaximumSize(QSize(75, 23));
        splitter->addWidget(btn_editer);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 2);

        btn_fermer = new QPushButton(BDConfigComptaService);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btn_fermer, 2, 1, 1, 1);


        retranslateUi(BDConfigComptaService);

        QMetaObject::connectSlotsByName(BDConfigComptaService);
    } // setupUi

    void retranslateUi(QDialog *BDConfigComptaService)
    {
        BDConfigComptaService->setWindowTitle(QApplication::translate("BDConfigComptaService", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDConfigComptaService", "Service :", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDConfigComptaService", "Param\303\251trage des actions", 0, QApplication::UnicodeUTF8));
        btn_editer->setText(QApplication::translate("BDConfigComptaService", "Editer", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDConfigComptaService", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDConfigComptaService: public Ui_BDConfigComptaService {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCONFIGCOMPTASERVICE_H
