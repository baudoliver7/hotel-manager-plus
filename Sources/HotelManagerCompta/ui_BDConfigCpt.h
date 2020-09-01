/********************************************************************************
** Form generated from reading UI file 'BDConfigCpt.ui'
**
** Created: Fri 25. Jan 23:18:57 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCONFIGCPT_H
#define UI_BDCONFIGCPT_H

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
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_BDConfigCpt
{
public:
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout_3;
    QLabel *label;
    QComboBox *comboBoxClasse;
    QFormLayout *formLayout_4;
    QLabel *label_4;
    QComboBox *comboBoxNbChiffre;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *rb_cpt_existant;
    QRadioButton *rb_cpt_a_creer;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QComboBox *comboBoxLibelle;
    QPushButton *btn_creer;
    QPushButton *btn_supprimer;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDConfigCpt)
    {
        if (BDConfigCpt->objectName().isEmpty())
            BDConfigCpt->setObjectName(QString::fromUtf8("BDConfigCpt"));
        BDConfigCpt->resize(775, 161);
        gridLayout_2 = new QGridLayout(BDConfigCpt);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label = new QLabel(BDConfigCpt);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        comboBoxClasse = new QComboBox(BDConfigCpt);
        comboBoxClasse->setObjectName(QString::fromUtf8("comboBoxClasse"));
        comboBoxClasse->setMaximumSize(QSize(32, 20));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, comboBoxClasse);


        gridLayout_2->addLayout(formLayout_3, 0, 0, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_4 = new QLabel(BDConfigCpt);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_4);

        comboBoxNbChiffre = new QComboBox(BDConfigCpt);
        comboBoxNbChiffre->setObjectName(QString::fromUtf8("comboBoxNbChiffre"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, comboBoxNbChiffre);


        gridLayout_2->addLayout(formLayout_4, 0, 1, 1, 3);

        groupBox = new QGroupBox(BDConfigCpt);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(100000, 100000));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rb_cpt_existant = new QRadioButton(groupBox);
        rb_cpt_existant->setObjectName(QString::fromUtf8("rb_cpt_existant"));

        gridLayout->addWidget(rb_cpt_existant, 0, 0, 1, 1);

        rb_cpt_a_creer = new QRadioButton(groupBox);
        rb_cpt_a_creer->setObjectName(QString::fromUtf8("rb_cpt_a_creer"));

        gridLayout->addWidget(rb_cpt_a_creer, 0, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        comboBoxLibelle = new QComboBox(groupBox);
        comboBoxLibelle->setObjectName(QString::fromUtf8("comboBoxLibelle"));
        comboBoxLibelle->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboBoxLibelle);


        gridLayout->addLayout(formLayout_2, 1, 0, 1, 2);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 4);

        btn_creer = new QPushButton(BDConfigCpt);
        btn_creer->setObjectName(QString::fromUtf8("btn_creer"));
        btn_creer->setMaximumSize(QSize(75, 23));
        btn_creer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btn_creer, 2, 1, 1, 1);

        btn_supprimer = new QPushButton(BDConfigCpt);
        btn_supprimer->setObjectName(QString::fromUtf8("btn_supprimer"));
        btn_supprimer->setMaximumSize(QSize(75, 23));
        btn_supprimer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btn_supprimer, 2, 2, 1, 1);

        btn_fermer = new QPushButton(BDConfigCpt);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btn_fermer, 2, 3, 1, 1);


        retranslateUi(BDConfigCpt);

        QMetaObject::connectSlotsByName(BDConfigCpt);
    } // setupUi

    void retranslateUi(QDialog *BDConfigCpt)
    {
        BDConfigCpt->setWindowTitle(QApplication::translate("BDConfigCpt", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDConfigCpt", "Classe", 0, QApplication::UnicodeUTF8));
        comboBoxClasse->clear();
        comboBoxClasse->insertItems(0, QStringList()
         << QApplication::translate("BDConfigCpt", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDConfigCpt", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDConfigCpt", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDConfigCpt", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDConfigCpt", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDConfigCpt", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDConfigCpt", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDConfigCpt", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDConfigCpt", "9", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("BDConfigCpt", "Nombre de chiffres dans le num\303\251ro du compte :", 0, QApplication::UnicodeUTF8));
        comboBoxNbChiffre->clear();
        comboBoxNbChiffre->insertItems(0, QStringList()
         << QApplication::translate("BDConfigCpt", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDConfigCpt", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDConfigCpt", "4", 0, QApplication::UnicodeUTF8)
        );
        groupBox->setTitle(QApplication::translate("BDConfigCpt", "Compte", 0, QApplication::UnicodeUTF8));
        rb_cpt_existant->setText(QApplication::translate("BDConfigCpt", "Comptes existants", 0, QApplication::UnicodeUTF8));
        rb_cpt_a_creer->setText(QApplication::translate("BDConfigCpt", "Comptes \303\240 cr\303\251er", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDConfigCpt", "Libell\303\251 complet :", 0, QApplication::UnicodeUTF8));
        btn_creer->setText(QApplication::translate("BDConfigCpt", "Cr\303\251er", 0, QApplication::UnicodeUTF8));
        btn_supprimer->setText(QApplication::translate("BDConfigCpt", "Supprimer", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDConfigCpt", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDConfigCpt: public Ui_BDConfigCpt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCONFIGCPT_H
