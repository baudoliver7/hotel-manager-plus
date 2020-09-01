/********************************************************************************
** Form generated from reading UI file 'BDReglerFacture.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDREGLERFACTURE_H
#define UI_BDREGLERFACTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_BDReglerFacture
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLineEdit *lineEditNomEntier;
    QPushButton *btn_identifier;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *rb_payees;
    QRadioButton *rb_nonPayees;
    QTreeWidget *treeWidgetFactures;
    QGroupBox *groupBoxReglement;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEditMontantARegler;
    QLabel *label_3;
    QSpinBox *spinBoxMontantEncaisse;
    QLabel *label_4;
    QComboBox *comboBoxModeDePayement;
    QLabel *label_5;
    QComboBox *comboBoxCompteClient;
    QLabel *label_6;
    QLineEdit *lineEditSolde;
    QPushButton *btn_regler;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDReglerFacture)
    {
        if (BDReglerFacture->objectName().isEmpty())
            BDReglerFacture->setObjectName(QString::fromUtf8("BDReglerFacture"));
        BDReglerFacture->resize(596, 430);
        gridLayout_3 = new QGridLayout(BDReglerFacture);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(BDReglerFacture);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        lineEditNomEntier = new QLineEdit(groupBox);
        lineEditNomEntier->setObjectName(QString::fromUtf8("lineEditNomEntier"));
        lineEditNomEntier->setReadOnly(true);

        gridLayout_4->addWidget(lineEditNomEntier, 0, 1, 1, 1);

        btn_identifier = new QPushButton(groupBox);
        btn_identifier->setObjectName(QString::fromUtf8("btn_identifier"));

        gridLayout_4->addWidget(btn_identifier, 0, 2, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(BDReglerFacture);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rb_payees = new QRadioButton(groupBox_2);
        rb_payees->setObjectName(QString::fromUtf8("rb_payees"));

        gridLayout_2->addWidget(rb_payees, 0, 0, 1, 1);

        rb_nonPayees = new QRadioButton(groupBox_2);
        rb_nonPayees->setObjectName(QString::fromUtf8("rb_nonPayees"));

        gridLayout_2->addWidget(rb_nonPayees, 0, 1, 1, 1);

        treeWidgetFactures = new QTreeWidget(groupBox_2);
        treeWidgetFactures->setObjectName(QString::fromUtf8("treeWidgetFactures"));
        treeWidgetFactures->header()->setCascadingSectionResizes(false);
        treeWidgetFactures->header()->setDefaultSectionSize(136);
        treeWidgetFactures->header()->setStretchLastSection(false);

        gridLayout_2->addWidget(treeWidgetFactures, 1, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 2);

        groupBoxReglement = new QGroupBox(BDReglerFacture);
        groupBoxReglement->setObjectName(QString::fromUtf8("groupBoxReglement"));
        groupBoxReglement->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(groupBoxReglement);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBoxReglement);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEditMontantARegler = new QLineEdit(groupBoxReglement);
        lineEditMontantARegler->setObjectName(QString::fromUtf8("lineEditMontantARegler"));
        lineEditMontantARegler->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantARegler->setReadOnly(true);

        gridLayout->addWidget(lineEditMontantARegler, 0, 1, 1, 1);

        label_3 = new QLabel(groupBoxReglement);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        spinBoxMontantEncaisse = new QSpinBox(groupBoxReglement);
        spinBoxMontantEncaisse->setObjectName(QString::fromUtf8("spinBoxMontantEncaisse"));
        spinBoxMontantEncaisse->setSingleStep(500);

        gridLayout->addWidget(spinBoxMontantEncaisse, 1, 1, 1, 1);

        label_4 = new QLabel(groupBoxReglement);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        comboBoxModeDePayement = new QComboBox(groupBoxReglement);
        comboBoxModeDePayement->setObjectName(QString::fromUtf8("comboBoxModeDePayement"));

        gridLayout->addWidget(comboBoxModeDePayement, 1, 3, 1, 1);

        label_5 = new QLabel(groupBoxReglement);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        comboBoxCompteClient = new QComboBox(groupBoxReglement);
        comboBoxCompteClient->setObjectName(QString::fromUtf8("comboBoxCompteClient"));

        gridLayout->addWidget(comboBoxCompteClient, 2, 3, 1, 1);

        label_6 = new QLabel(groupBoxReglement);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 4, 1, 1);

        lineEditSolde = new QLineEdit(groupBoxReglement);
        lineEditSolde->setObjectName(QString::fromUtf8("lineEditSolde"));
        lineEditSolde->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditSolde->setReadOnly(true);

        gridLayout->addWidget(lineEditSolde, 2, 5, 1, 1);

        btn_regler = new QPushButton(groupBoxReglement);
        btn_regler->setObjectName(QString::fromUtf8("btn_regler"));
        btn_regler->setMaximumSize(QSize(75, 23));
        btn_regler->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(btn_regler, 3, 5, 1, 1);


        gridLayout_3->addWidget(groupBoxReglement, 2, 0, 1, 2);

        btn_fermer = new QPushButton(BDReglerFacture);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(btn_fermer, 3, 1, 1, 1);


        retranslateUi(BDReglerFacture);

        QMetaObject::connectSlotsByName(BDReglerFacture);
    } // setupUi

    void retranslateUi(QDialog *BDReglerFacture)
    {
        BDReglerFacture->setWindowTitle(QApplication::translate("BDReglerFacture", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDReglerFacture", "Client s\303\251lectionn\303\251", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDReglerFacture", "Nom entier:", 0, QApplication::UnicodeUTF8));
        btn_identifier->setText(QApplication::translate("BDReglerFacture", "Identifier", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDReglerFacture", "Factures", 0, QApplication::UnicodeUTF8));
        rb_payees->setText(QApplication::translate("BDReglerFacture", "Pay\303\251es", 0, QApplication::UnicodeUTF8));
        rb_nonPayees->setText(QApplication::translate("BDReglerFacture", "Non pay\303\251es", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetFactures->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("BDReglerFacture", "Montant restant", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("BDReglerFacture", "Montant pay\303\251", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("BDReglerFacture", "Total \303\240 payer", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("BDReglerFacture", "Facture", 0, QApplication::UnicodeUTF8));
        groupBoxReglement->setTitle(QApplication::translate("BDReglerFacture", "R\303\250glement", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDReglerFacture", "Montant \303\240 r\303\251gler :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDReglerFacture", "Montant encaiss\303\251 :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDReglerFacture", "Mode de payement :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDReglerFacture", "Compte :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDReglerFacture", "Solde :", 0, QApplication::UnicodeUTF8));
        btn_regler->setText(QApplication::translate("BDReglerFacture", "R\303\251gler", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDReglerFacture", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDReglerFacture: public Ui_BDReglerFacture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDREGLERFACTURE_H
