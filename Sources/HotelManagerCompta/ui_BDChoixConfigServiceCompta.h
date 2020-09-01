/********************************************************************************
** Form generated from reading UI file 'BDChoixConfigServiceCompta.ui'
**
** Created: Fri 25. Jan 23:18:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCHOIXCONFIGSERVICECOMPTA_H
#define UI_BDCHOIXCONFIGSERVICECOMPTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BDChoixConfigServiceCompta
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBoxCompteAssocie;
    QFormLayout *formLayout_3;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDChoixConfigServiceCompta)
    {
        if (BDChoixConfigServiceCompta->objectName().isEmpty())
            BDChoixConfigServiceCompta->setObjectName(QString::fromUtf8("BDChoixConfigServiceCompta"));
        BDChoixConfigServiceCompta->resize(381, 71);
        gridLayout = new QGridLayout(BDChoixConfigServiceCompta);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(BDChoixConfigServiceCompta);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBoxCompteAssocie = new QComboBox(BDChoixConfigServiceCompta);
        comboBoxCompteAssocie->setObjectName(QString::fromUtf8("comboBoxCompteAssocie"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxCompteAssocie);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_3->setContentsMargins(-1, -1, 7, -1);
        btn_ok = new QPushButton(BDChoixConfigServiceCompta);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDChoixConfigServiceCompta);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout_3, 1, 0, 1, 1);


        retranslateUi(BDChoixConfigServiceCompta);

        QMetaObject::connectSlotsByName(BDChoixConfigServiceCompta);
    } // setupUi

    void retranslateUi(QDialog *BDChoixConfigServiceCompta)
    {
        BDChoixConfigServiceCompta->setWindowTitle(QApplication::translate("BDChoixConfigServiceCompta", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDChoixConfigServiceCompta", "Compte associ\303\251 :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDChoixConfigServiceCompta", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDChoixConfigServiceCompta", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDChoixConfigServiceCompta: public Ui_BDChoixConfigServiceCompta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCHOIXCONFIGSERVICECOMPTA_H
