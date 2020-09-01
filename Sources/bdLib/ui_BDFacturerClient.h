/********************************************************************************
** Form generated from reading UI file 'BDFacturerClient.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDFACTURERCLIENT_H
#define UI_BDFACTURERCLIENT_H

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

QT_BEGIN_NAMESPACE

class Ui_BDFacturerClient
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEditDureeOccup;
    QLabel *label_4;
    QLabel *label_2;
    QSpinBox *spinBoxTarif;
    QPushButton *btn_appliquerTarifNorm;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *lineEditFraisLocation;
    QLabel *label_7;
    QLineEdit *lineEditFraisResto;
    QPushButton *btn_details;
    QLabel *label_14;
    QLineEdit *lineEditFraisBar;
    QLabel *label_8;
    QSpinBox *spinBoxFraisPenaliteRetard;
    QLabel *label_11;
    QLineEdit *lineEditTotalAPayer;
    QLabel *label_9;
    QLineEdit *lineEditSommePayee;
    QLabel *label_5;
    QLineEdit *lineEditResteAPayer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QRadioButton *rb_regler;
    QRadioButton *rb_restituer;
    QLabel *label_6;
    QSpinBox *spinBoxVersement;
    QPushButton *btn_maximum_SV;
    QLabel *label_10;
    QComboBox *comboBoxModeDePayement;
    QLabel *label_12;
    QComboBox *comboBoxCompteClient;
    QLabel *label_13;
    QLineEdit *lineEditSolde;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDFacturerClient)
    {
        if (BDFacturerClient->objectName().isEmpty())
            BDFacturerClient->setObjectName(QString::fromUtf8("BDFacturerClient"));
        BDFacturerClient->resize(344, 517);
        gridLayout_4 = new QGridLayout(BDFacturerClient);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(BDFacturerClient);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEditDureeOccup = new QLineEdit(groupBox);
        lineEditDureeOccup->setObjectName(QString::fromUtf8("lineEditDureeOccup"));
        lineEditDureeOccup->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDureeOccup->setReadOnly(true);

        gridLayout->addWidget(lineEditDureeOccup, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBoxTarif = new QSpinBox(groupBox);
        spinBoxTarif->setObjectName(QString::fromUtf8("spinBoxTarif"));
        spinBoxTarif->setSingleStep(500);

        gridLayout->addWidget(spinBoxTarif, 1, 1, 1, 1);

        btn_appliquerTarifNorm = new QPushButton(groupBox);
        btn_appliquerTarifNorm->setObjectName(QString::fromUtf8("btn_appliquerTarifNorm"));
        btn_appliquerTarifNorm->setMaximumSize(QSize(121, 23));

        gridLayout->addWidget(btn_appliquerTarifNorm, 1, 2, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(BDFacturerClient);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        lineEditFraisLocation = new QLineEdit(groupBox_2);
        lineEditFraisLocation->setObjectName(QString::fromUtf8("lineEditFraisLocation"));
        lineEditFraisLocation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFraisLocation->setReadOnly(true);

        gridLayout_3->addWidget(lineEditFraisLocation, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        lineEditFraisResto = new QLineEdit(groupBox_2);
        lineEditFraisResto->setObjectName(QString::fromUtf8("lineEditFraisResto"));
        lineEditFraisResto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFraisResto->setReadOnly(true);

        gridLayout_3->addWidget(lineEditFraisResto, 1, 1, 1, 1);

        btn_details = new QPushButton(groupBox_2);
        btn_details->setObjectName(QString::fromUtf8("btn_details"));
        btn_details->setMaximumSize(QSize(75, 23));

        gridLayout_3->addWidget(btn_details, 1, 2, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 2, 0, 1, 1);

        lineEditFraisBar = new QLineEdit(groupBox_2);
        lineEditFraisBar->setObjectName(QString::fromUtf8("lineEditFraisBar"));
        lineEditFraisBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFraisBar->setReadOnly(true);

        gridLayout_3->addWidget(lineEditFraisBar, 2, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 3, 0, 1, 1);

        spinBoxFraisPenaliteRetard = new QSpinBox(groupBox_2);
        spinBoxFraisPenaliteRetard->setObjectName(QString::fromUtf8("spinBoxFraisPenaliteRetard"));
        spinBoxFraisPenaliteRetard->setMaximum(10000000);
        spinBoxFraisPenaliteRetard->setSingleStep(500);

        gridLayout_3->addWidget(spinBoxFraisPenaliteRetard, 3, 1, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 4, 0, 1, 1);

        lineEditTotalAPayer = new QLineEdit(groupBox_2);
        lineEditTotalAPayer->setObjectName(QString::fromUtf8("lineEditTotalAPayer"));
        lineEditTotalAPayer->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTotalAPayer->setReadOnly(true);

        gridLayout_3->addWidget(lineEditTotalAPayer, 4, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 5, 0, 1, 1);

        lineEditSommePayee = new QLineEdit(groupBox_2);
        lineEditSommePayee->setObjectName(QString::fromUtf8("lineEditSommePayee"));
        lineEditSommePayee->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditSommePayee->setReadOnly(true);

        gridLayout_3->addWidget(lineEditSommePayee, 5, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 6, 0, 1, 1);

        lineEditResteAPayer = new QLineEdit(groupBox_2);
        lineEditResteAPayer->setObjectName(QString::fromUtf8("lineEditResteAPayer"));
        lineEditResteAPayer->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditResteAPayer->setReadOnly(true);

        gridLayout_3->addWidget(lineEditResteAPayer, 6, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(BDFacturerClient);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rb_regler = new QRadioButton(groupBox_3);
        rb_regler->setObjectName(QString::fromUtf8("rb_regler"));

        gridLayout_2->addWidget(rb_regler, 0, 0, 1, 1);

        rb_restituer = new QRadioButton(groupBox_3);
        rb_restituer->setObjectName(QString::fromUtf8("rb_restituer"));

        gridLayout_2->addWidget(rb_restituer, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        spinBoxVersement = new QSpinBox(groupBox_3);
        spinBoxVersement->setObjectName(QString::fromUtf8("spinBoxVersement"));
        spinBoxVersement->setMaximum(99);
        spinBoxVersement->setSingleStep(500);

        gridLayout_2->addWidget(spinBoxVersement, 1, 1, 1, 1);

        btn_maximum_SV = new QPushButton(groupBox_3);
        btn_maximum_SV->setObjectName(QString::fromUtf8("btn_maximum_SV"));
        btn_maximum_SV->setMaximumSize(QSize(75, 23));

        gridLayout_2->addWidget(btn_maximum_SV, 1, 2, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 2, 0, 1, 1);

        comboBoxModeDePayement = new QComboBox(groupBox_3);
        comboBoxModeDePayement->setObjectName(QString::fromUtf8("comboBoxModeDePayement"));
        comboBoxModeDePayement->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_2->addWidget(comboBoxModeDePayement, 2, 1, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 3, 0, 1, 1);

        comboBoxCompteClient = new QComboBox(groupBox_3);
        comboBoxCompteClient->setObjectName(QString::fromUtf8("comboBoxCompteClient"));
        comboBoxCompteClient->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_2->addWidget(comboBoxCompteClient, 3, 1, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 4, 0, 1, 1);

        lineEditSolde = new QLineEdit(groupBox_3);
        lineEditSolde->setObjectName(QString::fromUtf8("lineEditSolde"));
        lineEditSolde->setMaximumSize(QSize(1000, 16777215));
        lineEditSolde->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditSolde->setReadOnly(true);

        gridLayout_2->addWidget(lineEditSolde, 4, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 8, -1);
        btn_ok = new QPushButton(BDFacturerClient);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDFacturerClient);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout_4->addLayout(formLayout, 3, 0, 1, 1);


        retranslateUi(BDFacturerClient);

        QMetaObject::connectSlotsByName(BDFacturerClient);
    } // setupUi

    void retranslateUi(QDialog *BDFacturerClient)
    {
        BDFacturerClient->setWindowTitle(QApplication::translate("BDFacturerClient", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDFacturerClient", "Caract\303\251ristiques de l'occupation", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDFacturerClient", "Dur\303\251e d'occupation :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDFacturerClient", "jour (s)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDFacturerClient", "Tarif :", 0, QApplication::UnicodeUTF8));
        btn_appliquerTarifNorm->setText(QApplication::translate("BDFacturerClient", "Appliquer tarif normal", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDFacturerClient", "D\303\251tails des montants", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDFacturerClient", "Frais de location :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BDFacturerClient", "Frais de restaurant :", 0, QApplication::UnicodeUTF8));
        btn_details->setText(QApplication::translate("BDFacturerClient", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("BDFacturerClient", "Frais de bar :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BDFacturerClient", "P\303\251nalit\303\251 retard :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BDFacturerClient", "Total \303\240 payer :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BDFacturerClient", "Somme pay\303\251e :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDFacturerClient", "Reste \303\240 payer :", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("BDFacturerClient", "R\303\250glement des frais", 0, QApplication::UnicodeUTF8));
        rb_regler->setText(QApplication::translate("BDFacturerClient", "R\303\251gler", 0, QApplication::UnicodeUTF8));
        rb_restituer->setText(QApplication::translate("BDFacturerClient", "Restituer", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDFacturerClient", "Somme :", 0, QApplication::UnicodeUTF8));
        btn_maximum_SV->setText(QApplication::translate("BDFacturerClient", "Payer tout", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BDFacturerClient", "Mode  :", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("BDFacturerClient", "Comptes:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("BDFacturerClient", "Solde :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDFacturerClient", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDFacturerClient", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDFacturerClient: public Ui_BDFacturerClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDFACTURERCLIENT_H
