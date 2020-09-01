/********************************************************************************
** Form generated from reading UI file 'BDConfigurerTableResto.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCONFIGURERTABLERESTO_H
#define UI_BDCONFIGURERTABLERESTO_H

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
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_BDConfigurerTableResto
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditLibelle;
    QPushButton *btn_ajouter;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableView *tableView;
    QFormLayout *formLayout;
    QPushButton *btn_appliquer;
    QPushButton *btn_supprimer;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDConfigurerTableResto)
    {
        if (BDConfigurerTableResto->objectName().isEmpty())
            BDConfigurerTableResto->setObjectName(QString::fromUtf8("BDConfigurerTableResto"));
        BDConfigurerTableResto->resize(302, 311);
        gridLayout_3 = new QGridLayout(BDConfigurerTableResto);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(BDConfigurerTableResto);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(276, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditLibelle = new QLineEdit(groupBox);
        lineEditLibelle->setObjectName(QString::fromUtf8("lineEditLibelle"));

        gridLayout->addWidget(lineEditLibelle, 0, 1, 1, 1);

        btn_ajouter = new QPushButton(groupBox);
        btn_ajouter->setObjectName(QString::fromUtf8("btn_ajouter"));

        gridLayout->addWidget(btn_ajouter, 0, 2, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(BDConfigurerTableResto);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setDefaultSectionSize(22);

        gridLayout_2->addWidget(tableView, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 9, -1);
        btn_appliquer = new QPushButton(groupBox_2);
        btn_appliquer->setObjectName(QString::fromUtf8("btn_appliquer"));
        btn_appliquer->setMaximumSize(QSize(75, 23));
        btn_appliquer->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_appliquer);

        btn_supprimer = new QPushButton(groupBox_2);
        btn_supprimer->setObjectName(QString::fromUtf8("btn_supprimer"));
        btn_supprimer->setMaximumSize(QSize(75, 23));
        btn_supprimer->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_supprimer);


        gridLayout_2->addLayout(formLayout, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        btn_fermer = new QPushButton(BDConfigurerTableResto);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(btn_fermer, 2, 0, 1, 1);


        retranslateUi(BDConfigurerTableResto);

        QMetaObject::connectSlotsByName(BDConfigurerTableResto);
    } // setupUi

    void retranslateUi(QDialog *BDConfigurerTableResto)
    {
        BDConfigurerTableResto->setWindowTitle(QApplication::translate("BDConfigurerTableResto", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDConfigurerTableResto", "Cr\303\251er une table", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDConfigurerTableResto", "Libell\303\251 :", 0, QApplication::UnicodeUTF8));
        btn_ajouter->setText(QApplication::translate("BDConfigurerTableResto", "Ajouter", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDConfigurerTableResto", "Tables actuellement libres", 0, QApplication::UnicodeUTF8));
        btn_appliquer->setText(QApplication::translate("BDConfigurerTableResto", "Appliquer", 0, QApplication::UnicodeUTF8));
        btn_supprimer->setText(QApplication::translate("BDConfigurerTableResto", "Supprimer", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDConfigurerTableResto", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDConfigurerTableResto: public Ui_BDConfigurerTableResto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCONFIGURERTABLERESTO_H
