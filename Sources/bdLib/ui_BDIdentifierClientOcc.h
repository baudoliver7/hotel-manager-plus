/********************************************************************************
** Form generated from reading UI file 'BDIdentifierClientOcc.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDIDENTIFIERCLIENTOCC_H
#define UI_BDIDENTIFIERCLIENTOCC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
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
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDIdentifierClientOcc
{
public:
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout_4;
    QRadioButton *rb_clientInconnu;
    QPushButton *btn_identifier;
    QRadioButton *rb_clientConnu;
    QFormLayout *formLayout_6;
    QFormLayout *formLayout_5;
    QLabel *label;
    QLineEdit *lineEditClientConnu;
    QCheckBox *checkBoxMasculin;
    QTableView *tableView;
    QPushButton *btn_choisir;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout_8;
    QFormLayout *formLayout_7;
    QLabel *label_3;
    QLineEdit *lineEditClientSelectionne;
    QPushButton *btn_details;
    QGroupBox *groupBoxPiece;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEditNature;
    QLineEdit *lineEditNumero;
    QDateEdit *dateEditDateDelivrance;
    QLineEdit *lineEditLieuDelivrance;
    QLineEdit *lineEditAgentDelivreur;
    QGroupBox *groupBoxCategorie;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *comboBoxTypeDeClient;
    QLabel *label_4;
    QComboBox *comboBoxProfile;
    QGroupBox *groupBoxInfosSupp;
    QGridLayout *gridLayout_4;
    QFormLayout *formLayout_3;
    QLabel *label_18;
    QSpinBox *spinBoxNbEnfants;
    QFormLayout *formLayout_2;
    QLabel *label_19;
    QLineEdit *lineEditDestinationExacte;
    QFormLayout *formLayout;
    QPushButton *btn_annuler;
    QPushButton *btn_ok;

    void setupUi(QDialog *BDIdentifierClientOcc)
    {
        if (BDIdentifierClientOcc->objectName().isEmpty())
            BDIdentifierClientOcc->setObjectName(QString::fromUtf8("BDIdentifierClientOcc"));
        BDIdentifierClientOcc->resize(648, 582);
        gridLayout_6 = new QGridLayout(BDIdentifierClientOcc);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox_2 = new QGroupBox(BDIdentifierClientOcc);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        rb_clientInconnu = new QRadioButton(groupBox_2);
        rb_clientInconnu->setObjectName(QString::fromUtf8("rb_clientInconnu"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, rb_clientInconnu);

        btn_identifier = new QPushButton(groupBox_2);
        btn_identifier->setObjectName(QString::fromUtf8("btn_identifier"));
        btn_identifier->setMaximumSize(QSize(75, 23));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, btn_identifier);


        gridLayout_2->addLayout(formLayout_4, 0, 0, 1, 2);

        rb_clientConnu = new QRadioButton(groupBox_2);
        rb_clientConnu->setObjectName(QString::fromUtf8("rb_clientConnu"));

        gridLayout_2->addWidget(rb_clientConnu, 1, 0, 1, 1);

        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label);

        lineEditClientConnu = new QLineEdit(groupBox_2);
        lineEditClientConnu->setObjectName(QString::fromUtf8("lineEditClientConnu"));
        lineEditClientConnu->setMaximumSize(QSize(133, 16777215));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, lineEditClientConnu);


        formLayout_6->setLayout(0, QFormLayout::LabelRole, formLayout_5);

        checkBoxMasculin = new QCheckBox(groupBox_2);
        checkBoxMasculin->setObjectName(QString::fromUtf8("checkBoxMasculin"));
        checkBoxMasculin->setChecked(true);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, checkBoxMasculin);


        gridLayout_2->addLayout(formLayout_6, 1, 1, 1, 1);

        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setDefaultSectionSize(120);
        tableView->verticalHeader()->setDefaultSectionSize(17);

        gridLayout_2->addWidget(tableView, 2, 0, 1, 3);

        btn_choisir = new QPushButton(groupBox_2);
        btn_choisir->setObjectName(QString::fromUtf8("btn_choisir"));
        btn_choisir->setMaximumSize(QSize(75, 23));

        gridLayout_2->addWidget(btn_choisir, 3, 2, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(BDIdentifierClientOcc);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEditClientSelectionne = new QLineEdit(groupBox);
        lineEditClientSelectionne->setObjectName(QString::fromUtf8("lineEditClientSelectionne"));
        lineEditClientSelectionne->setMinimumSize(QSize(335, 0));
        lineEditClientSelectionne->setMaximumSize(QSize(335, 16777215));
        lineEditClientSelectionne->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClientSelectionne->setReadOnly(true);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, lineEditClientSelectionne);


        formLayout_8->setLayout(0, QFormLayout::LabelRole, formLayout_7);

        btn_details = new QPushButton(groupBox);
        btn_details->setObjectName(QString::fromUtf8("btn_details"));
        btn_details->setMaximumSize(QSize(75, 23));

        formLayout_8->setWidget(0, QFormLayout::FieldRole, btn_details);


        gridLayout_5->addLayout(formLayout_8, 0, 0, 1, 2);

        groupBoxPiece = new QGroupBox(groupBox);
        groupBoxPiece->setObjectName(QString::fromUtf8("groupBoxPiece"));
        groupBoxPiece->setMaximumSize(QSize(16777215, 170));
        gridLayout_3 = new QGridLayout(groupBoxPiece);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_11 = new QLabel(groupBoxPiece);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11);

        label_12 = new QLabel(groupBoxPiece);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_4->addWidget(label_12);

        label_13 = new QLabel(groupBoxPiece);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_4->addWidget(label_13);

        label_14 = new QLabel(groupBoxPiece);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_4->addWidget(label_14);

        label_15 = new QLabel(groupBoxPiece);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_4->addWidget(label_15);


        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEditNature = new QLineEdit(groupBoxPiece);
        lineEditNature->setObjectName(QString::fromUtf8("lineEditNature"));

        verticalLayout_3->addWidget(lineEditNature);

        lineEditNumero = new QLineEdit(groupBoxPiece);
        lineEditNumero->setObjectName(QString::fromUtf8("lineEditNumero"));

        verticalLayout_3->addWidget(lineEditNumero);

        dateEditDateDelivrance = new QDateEdit(groupBoxPiece);
        dateEditDateDelivrance->setObjectName(QString::fromUtf8("dateEditDateDelivrance"));

        verticalLayout_3->addWidget(dateEditDateDelivrance);

        lineEditLieuDelivrance = new QLineEdit(groupBoxPiece);
        lineEditLieuDelivrance->setObjectName(QString::fromUtf8("lineEditLieuDelivrance"));

        verticalLayout_3->addWidget(lineEditLieuDelivrance);

        lineEditAgentDelivreur = new QLineEdit(groupBoxPiece);
        lineEditAgentDelivreur->setObjectName(QString::fromUtf8("lineEditAgentDelivreur"));

        verticalLayout_3->addWidget(lineEditAgentDelivreur);


        gridLayout_3->addLayout(verticalLayout_3, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBoxPiece, 1, 0, 2, 1);

        groupBoxCategorie = new QGroupBox(groupBox);
        groupBoxCategorie->setObjectName(QString::fromUtf8("groupBoxCategorie"));
        groupBoxCategorie->setMaximumSize(QSize(327, 16777215));
        gridLayout = new QGridLayout(groupBoxCategorie);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBoxCategorie);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        comboBoxTypeDeClient = new QComboBox(groupBoxCategorie);
        comboBoxTypeDeClient->setObjectName(QString::fromUtf8("comboBoxTypeDeClient"));
        comboBoxTypeDeClient->setMaximumSize(QSize(140, 16777215));

        gridLayout->addWidget(comboBoxTypeDeClient, 0, 1, 1, 1);

        label_4 = new QLabel(groupBoxCategorie);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        comboBoxProfile = new QComboBox(groupBoxCategorie);
        comboBoxProfile->setObjectName(QString::fromUtf8("comboBoxProfile"));
        comboBoxProfile->setMaximumSize(QSize(140, 16777215));

        gridLayout->addWidget(comboBoxProfile, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBoxCategorie, 1, 1, 1, 1);

        groupBoxInfosSupp = new QGroupBox(groupBox);
        groupBoxInfosSupp->setObjectName(QString::fromUtf8("groupBoxInfosSupp"));
        groupBoxInfosSupp->setMaximumSize(QSize(327, 16777215));
        gridLayout_4 = new QGridLayout(groupBoxInfosSupp);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_18 = new QLabel(groupBoxInfosSupp);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_18);

        spinBoxNbEnfants = new QSpinBox(groupBoxInfosSupp);
        spinBoxNbEnfants->setObjectName(QString::fromUtf8("spinBoxNbEnfants"));
        spinBoxNbEnfants->setMaximum(100);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBoxNbEnfants);


        gridLayout_4->addLayout(formLayout_3, 0, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_19 = new QLabel(groupBoxInfosSupp);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_19);

        lineEditDestinationExacte = new QLineEdit(groupBoxInfosSupp);
        lineEditDestinationExacte->setObjectName(QString::fromUtf8("lineEditDestinationExacte"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditDestinationExacte);


        gridLayout_4->addLayout(formLayout_2, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBoxInfosSupp, 2, 1, 1, 1);


        gridLayout_6->addWidget(groupBox, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_annuler = new QPushButton(BDIdentifierClientOcc);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);

        btn_ok = new QPushButton(BDIdentifierClientOcc);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);


        gridLayout_6->addLayout(formLayout, 2, 0, 1, 1);


        retranslateUi(BDIdentifierClientOcc);

        QMetaObject::connectSlotsByName(BDIdentifierClientOcc);
    } // setupUi

    void retranslateUi(QDialog *BDIdentifierClientOcc)
    {
        BDIdentifierClientOcc->setWindowTitle(QApplication::translate("BDIdentifierClientOcc", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDIdentifierClientOcc", "Choisir un client", 0, QApplication::UnicodeUTF8));
        rb_clientInconnu->setText(QApplication::translate("BDIdentifierClientOcc", "Client inconnu", 0, QApplication::UnicodeUTF8));
        btn_identifier->setText(QApplication::translate("BDIdentifierClientOcc", "Identifier", 0, QApplication::UnicodeUTF8));
        rb_clientConnu->setText(QApplication::translate("BDIdentifierClientOcc", "Client connu", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDIdentifierClientOcc", "Nom :", 0, QApplication::UnicodeUTF8));
        checkBoxMasculin->setText(QApplication::translate("BDIdentifierClientOcc", "Masculin", 0, QApplication::UnicodeUTF8));
        btn_choisir->setText(QApplication::translate("BDIdentifierClientOcc", "S\303\251lectionner", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDIdentifierClientOcc", "Client choisi", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDIdentifierClientOcc", "Nom complet :", 0, QApplication::UnicodeUTF8));
        btn_details->setText(QApplication::translate("BDIdentifierClientOcc", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        groupBoxPiece->setTitle(QApplication::translate("BDIdentifierClientOcc", "Pi\303\250ces d'identit\303\251 produites", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BDIdentifierClientOcc", "Nature:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("BDIdentifierClientOcc", "N\302\260 :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("BDIdentifierClientOcc", "D\303\251livr\303\251 le:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("BDIdentifierClientOcc", "A :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("BDIdentifierClientOcc", "Par :", 0, QApplication::UnicodeUTF8));
        groupBoxCategorie->setTitle(QApplication::translate("BDIdentifierClientOcc", "Cat\303\251gorie", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDIdentifierClientOcc", "Type de client :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDIdentifierClientOcc", "Profile :", 0, QApplication::UnicodeUTF8));
        groupBoxInfosSupp->setTitle(QApplication::translate("BDIdentifierClientOcc", "Autres informations", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("BDIdentifierClientOcc", "Nombre d'enfants de moins de 15 ans accompagnant:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("BDIdentifierClientOcc", "Destination exacte: ", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDIdentifierClientOcc", "Annuler", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDIdentifierClientOcc", "Choisir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDIdentifierClientOcc: public Ui_BDIdentifierClientOcc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDIDENTIFIERCLIENTOCC_H
