/********************************************************************************
** Form generated from reading UI file 'BDRenommerCompte.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDRENOMMERCOMPTE_H
#define UI_BDRENOMMERCOMPTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BDRenommerCompte
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditLibelleComplet;
    QLabel *label_2;
    QLineEdit *lineEditLibellePerso;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDRenommerCompte)
    {
        if (BDRenommerCompte->objectName().isEmpty())
            BDRenommerCompte->setObjectName(QString::fromUtf8("BDRenommerCompte"));
        BDRenommerCompte->resize(578, 95);
        gridLayout = new QGridLayout(BDRenommerCompte);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(BDRenommerCompte);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditLibelleComplet = new QLineEdit(BDRenommerCompte);
        lineEditLibelleComplet->setObjectName(QString::fromUtf8("lineEditLibelleComplet"));
        lineEditLibelleComplet->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditLibelleComplet->setReadOnly(true);

        gridLayout->addWidget(lineEditLibelleComplet, 0, 1, 1, 1);

        label_2 = new QLabel(BDRenommerCompte);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditLibellePerso = new QLineEdit(BDRenommerCompte);
        lineEditLibellePerso->setObjectName(QString::fromUtf8("lineEditLibellePerso"));
        lineEditLibellePerso->setMaximumSize(QSize(16777215, 16777215));
        lineEditLibellePerso->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEditLibellePerso->setReadOnly(false);

        gridLayout->addWidget(lineEditLibellePerso, 1, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 9, -1);
        btn_ok = new QPushButton(BDRenommerCompte);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDRenommerCompte);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout, 2, 1, 1, 1);


        retranslateUi(BDRenommerCompte);

        QMetaObject::connectSlotsByName(BDRenommerCompte);
    } // setupUi

    void retranslateUi(QDialog *BDRenommerCompte)
    {
        BDRenommerCompte->setWindowTitle(QApplication::translate("BDRenommerCompte", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDRenommerCompte", "Libell\303\251 complet :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDRenommerCompte", "Libell\303\251 perso :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDRenommerCompte", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDRenommerCompte", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDRenommerCompte: public Ui_BDRenommerCompte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDRENOMMERCOMPTE_H
