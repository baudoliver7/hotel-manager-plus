/********************************************************************************
** Form generated from reading UI file 'BDDebiterUnCompteClient.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDDEBITERUNCOMPTECLIENT_H
#define UI_BDDEBITERUNCOMPTECLIENT_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_BDDebiterUnCompteClient
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *lineEditClient;
    QToolButton *btn_identifier;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidgetComptesExistants;
    QGroupBox *groupBoxDebiterCompte;
    QGridLayout *gridLayout_2;
    QRadioButton *rb_debiter;
    QRadioButton *rb_crediter;
    QLabel *label_2;
    QSpinBox *spinBoxMontantVerse;
    QFormLayout *formLayout;
    QLabel *label_3;
    QComboBox *comboBoxModeDePaye;
    QPushButton *btn_debiter;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDDebiterUnCompteClient)
    {
        if (BDDebiterUnCompteClient->objectName().isEmpty())
            BDDebiterUnCompteClient->setObjectName(QString::fromUtf8("BDDebiterUnCompteClient"));
        BDDebiterUnCompteClient->resize(409, 343);
        gridLayout_3 = new QGridLayout(BDDebiterUnCompteClient);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(BDDebiterUnCompteClient);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        lineEditClient = new QLineEdit(BDDebiterUnCompteClient);
        lineEditClient->setObjectName(QString::fromUtf8("lineEditClient"));
        lineEditClient->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClient->setReadOnly(true);

        gridLayout_3->addWidget(lineEditClient, 0, 1, 1, 1);

        btn_identifier = new QToolButton(BDDebiterUnCompteClient);
        btn_identifier->setObjectName(QString::fromUtf8("btn_identifier"));

        gridLayout_3->addWidget(btn_identifier, 0, 2, 1, 1);

        groupBox = new QGroupBox(BDDebiterUnCompteClient);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeWidgetComptesExistants = new QTreeWidget(groupBox);
        treeWidgetComptesExistants->setObjectName(QString::fromUtf8("treeWidgetComptesExistants"));
        treeWidgetComptesExistants->setColumnCount(3);
        treeWidgetComptesExistants->header()->setDefaultSectionSize(150);
        treeWidgetComptesExistants->header()->setStretchLastSection(false);

        gridLayout->addWidget(treeWidgetComptesExistants, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 3);

        groupBoxDebiterCompte = new QGroupBox(BDDebiterUnCompteClient);
        groupBoxDebiterCompte->setObjectName(QString::fromUtf8("groupBoxDebiterCompte"));
        gridLayout_2 = new QGridLayout(groupBoxDebiterCompte);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rb_debiter = new QRadioButton(groupBoxDebiterCompte);
        rb_debiter->setObjectName(QString::fromUtf8("rb_debiter"));

        gridLayout_2->addWidget(rb_debiter, 0, 0, 1, 1);

        rb_crediter = new QRadioButton(groupBoxDebiterCompte);
        rb_crediter->setObjectName(QString::fromUtf8("rb_crediter"));

        gridLayout_2->addWidget(rb_crediter, 0, 1, 1, 1);

        label_2 = new QLabel(groupBoxDebiterCompte);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        spinBoxMontantVerse = new QSpinBox(groupBoxDebiterCompte);
        spinBoxMontantVerse->setObjectName(QString::fromUtf8("spinBoxMontantVerse"));
        spinBoxMontantVerse->setMaximum(100000000);
        spinBoxMontantVerse->setSingleStep(500);

        gridLayout_2->addWidget(spinBoxMontantVerse, 1, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(groupBoxDebiterCompte);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        comboBoxModeDePaye = new QComboBox(groupBoxDebiterCompte);
        comboBoxModeDePaye->setObjectName(QString::fromUtf8("comboBoxModeDePaye"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxModeDePaye);


        gridLayout_2->addLayout(formLayout, 1, 2, 1, 1);

        btn_debiter = new QPushButton(groupBoxDebiterCompte);
        btn_debiter->setObjectName(QString::fromUtf8("btn_debiter"));
        btn_debiter->setMaximumSize(QSize(75, 16777215));
        btn_debiter->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btn_debiter, 2, 2, 1, 1);


        gridLayout_3->addWidget(groupBoxDebiterCompte, 2, 0, 1, 3);

        btn_fermer = new QPushButton(BDDebiterUnCompteClient);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 16777215));

        gridLayout_3->addWidget(btn_fermer, 3, 2, 1, 1);


        retranslateUi(BDDebiterUnCompteClient);

        QMetaObject::connectSlotsByName(BDDebiterUnCompteClient);
    } // setupUi

    void retranslateUi(QDialog *BDDebiterUnCompteClient)
    {
        BDDebiterUnCompteClient->setWindowTitle(QApplication::translate("BDDebiterUnCompteClient", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDDebiterUnCompteClient", "Client :", 0, QApplication::UnicodeUTF8));
        btn_identifier->setText(QApplication::translate("BDDebiterUnCompteClient", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDDebiterUnCompteClient", "Comptes existants", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetComptesExistants->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("BDDebiterUnCompteClient", "Solde", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("BDDebiterUnCompteClient", "Libell\303\251", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("BDDebiterUnCompteClient", "IdCompteClient", 0, QApplication::UnicodeUTF8));
        groupBoxDebiterCompte->setTitle(QApplication::translate("BDDebiterUnCompteClient", "Compte", 0, QApplication::UnicodeUTF8));
        rb_debiter->setText(QApplication::translate("BDDebiterUnCompteClient", "D\303\251biter", 0, QApplication::UnicodeUTF8));
        rb_crediter->setText(QApplication::translate("BDDebiterUnCompteClient", "Cr\303\251diter", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDDebiterUnCompteClient", "Montant vers\303\251 :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDDebiterUnCompteClient", "Mode :", 0, QApplication::UnicodeUTF8));
        btn_debiter->setText(QApplication::translate("BDDebiterUnCompteClient", "D\303\251biter", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDDebiterUnCompteClient", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDDebiterUnCompteClient: public Ui_BDDebiterUnCompteClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDDEBITERUNCOMPTECLIENT_H
