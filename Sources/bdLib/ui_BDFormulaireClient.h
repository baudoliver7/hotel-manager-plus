/********************************************************************************
** Form generated from reading UI file 'BDFormulaireClient.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDFORMULAIRECLIENT_H
#define UI_BDFORMULAIRECLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDFormulaireClient
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout_2;
    QRadioButton *rb_masculin;
    QRadioButton *rb_feminin;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditNom;
    QLineEdit *lineEditPrenom;
    QDateEdit *dateEditDateDeNaiss;
    QLineEdit *lineEditLieuDeNaiss;
    QLineEdit *lineEditPere;
    QLineEdit *lineEditMere;
    QLineEdit *lineEditProfession;
    QLineEdit *lineEditDomicile;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditContacts;
    QToolButton *btn_calendrier;
    QLineEdit *lineEditNationalite;
    QGroupBox *groupBoxCategorie;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_16;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboBoxTypeDeClient;
    QComboBox *comboBoxProfile;
    QGroupBox *groupBoxPiece;
    QGridLayout *gridLayout;
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
    QGroupBox *groupBoxInfosSupp;
    QGridLayout *gridLayout_4;
    QFormLayout *formLayout_3;
    QLabel *label_18;
    QSpinBox *spinBoxNbEnfants;
    QFormLayout *formLayout;
    QLabel *label_19;
    QLineEdit *lineEditDestinationExacte;
    QFormLayout *formLayout_4;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDFormulaireClient)
    {
        if (BDFormulaireClient->objectName().isEmpty())
            BDFormulaireClient->setObjectName(QString::fromUtf8("BDFormulaireClient"));
        BDFormulaireClient->resize(667, 384);
        gridLayout_5 = new QGridLayout(BDFormulaireClient);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_2 = new QGroupBox(BDFormulaireClient);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        rb_masculin = new QRadioButton(groupBox_2);
        rb_masculin->setObjectName(QString::fromUtf8("rb_masculin"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rb_masculin);

        rb_feminin = new QRadioButton(groupBox_2);
        rb_feminin->setObjectName(QString::fromUtf8("rb_feminin"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, rb_feminin);


        gridLayout_2->addLayout(formLayout_2, 0, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEditNom = new QLineEdit(groupBox_2);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));

        verticalLayout_2->addWidget(lineEditNom);

        lineEditPrenom = new QLineEdit(groupBox_2);
        lineEditPrenom->setObjectName(QString::fromUtf8("lineEditPrenom"));

        verticalLayout_2->addWidget(lineEditPrenom);

        dateEditDateDeNaiss = new QDateEdit(groupBox_2);
        dateEditDateDeNaiss->setObjectName(QString::fromUtf8("dateEditDateDeNaiss"));

        verticalLayout_2->addWidget(dateEditDateDeNaiss);

        lineEditLieuDeNaiss = new QLineEdit(groupBox_2);
        lineEditLieuDeNaiss->setObjectName(QString::fromUtf8("lineEditLieuDeNaiss"));

        verticalLayout_2->addWidget(lineEditLieuDeNaiss);

        lineEditPere = new QLineEdit(groupBox_2);
        lineEditPere->setObjectName(QString::fromUtf8("lineEditPere"));

        verticalLayout_2->addWidget(lineEditPere);

        lineEditMere = new QLineEdit(groupBox_2);
        lineEditMere->setObjectName(QString::fromUtf8("lineEditMere"));

        verticalLayout_2->addWidget(lineEditMere);

        lineEditProfession = new QLineEdit(groupBox_2);
        lineEditProfession->setObjectName(QString::fromUtf8("lineEditProfession"));

        verticalLayout_2->addWidget(lineEditProfession);

        lineEditDomicile = new QLineEdit(groupBox_2);
        lineEditDomicile->setObjectName(QString::fromUtf8("lineEditDomicile"));

        verticalLayout_2->addWidget(lineEditDomicile);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditContacts = new QLineEdit(groupBox_2);
        lineEditContacts->setObjectName(QString::fromUtf8("lineEditContacts"));
        lineEditContacts->setReadOnly(true);

        horizontalLayout->addWidget(lineEditContacts);

        btn_calendrier = new QToolButton(groupBox_2);
        btn_calendrier->setObjectName(QString::fromUtf8("btn_calendrier"));

        horizontalLayout->addWidget(btn_calendrier);


        verticalLayout_2->addLayout(horizontalLayout);

        lineEditNationalite = new QLineEdit(groupBox_2);
        lineEditNationalite->setObjectName(QString::fromUtf8("lineEditNationalite"));

        verticalLayout_2->addWidget(lineEditNationalite);


        gridLayout_2->addLayout(verticalLayout_2, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 0, 0, 3, 1);

        groupBoxCategorie = new QGroupBox(BDFormulaireClient);
        groupBoxCategorie->setObjectName(QString::fromUtf8("groupBoxCategorie"));
        gridLayout_3 = new QGridLayout(groupBoxCategorie);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_16 = new QLabel(groupBoxCategorie);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_6->addWidget(label_16);

        label_17 = new QLabel(groupBoxCategorie);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_6->addWidget(label_17);


        gridLayout_3->addLayout(verticalLayout_6, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        comboBoxTypeDeClient = new QComboBox(groupBoxCategorie);
        comboBoxTypeDeClient->setObjectName(QString::fromUtf8("comboBoxTypeDeClient"));

        verticalLayout_5->addWidget(comboBoxTypeDeClient);

        comboBoxProfile = new QComboBox(groupBoxCategorie);
        comboBoxProfile->setObjectName(QString::fromUtf8("comboBoxProfile"));

        verticalLayout_5->addWidget(comboBoxProfile);


        gridLayout_3->addLayout(verticalLayout_5, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBoxCategorie, 0, 1, 1, 1);

        groupBoxPiece = new QGroupBox(BDFormulaireClient);
        groupBoxPiece->setObjectName(QString::fromUtf8("groupBoxPiece"));
        groupBoxPiece->setMaximumSize(QSize(16777215, 160));
        gridLayout = new QGridLayout(groupBoxPiece);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

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


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBoxPiece, 1, 1, 1, 1);

        groupBoxInfosSupp = new QGroupBox(BDFormulaireClient);
        groupBoxInfosSupp->setObjectName(QString::fromUtf8("groupBoxInfosSupp"));
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

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_19 = new QLabel(groupBoxInfosSupp);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_19);

        lineEditDestinationExacte = new QLineEdit(groupBoxInfosSupp);
        lineEditDestinationExacte->setObjectName(QString::fromUtf8("lineEditDestinationExacte"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditDestinationExacte);


        gridLayout_4->addLayout(formLayout, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBoxInfosSupp, 2, 1, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_4->setContentsMargins(-1, -1, 8, -1);
        btn_ok = new QPushButton(BDFormulaireClient);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDFormulaireClient);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout_5->addLayout(formLayout_4, 3, 1, 1, 1);


        retranslateUi(BDFormulaireClient);

        QMetaObject::connectSlotsByName(BDFormulaireClient);
    } // setupUi

    void retranslateUi(QDialog *BDFormulaireClient)
    {
        BDFormulaireClient->setWindowTitle(QApplication::translate("BDFormulaireClient", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDFormulaireClient", "Informations sur le client", 0, QApplication::UnicodeUTF8));
        rb_masculin->setText(QApplication::translate("BDFormulaireClient", "Masculin", 0, QApplication::UnicodeUTF8));
        rb_feminin->setText(QApplication::translate("BDFormulaireClient", "F\303\251minin", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDFormulaireClient", "Nom (*):", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDFormulaireClient", "Pr\303\251nom(s) (*):", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDFormulaireClient", "N\303\251(e) le:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDFormulaireClient", "A :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDFormulaireClient", "Fils (Fille) de:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDFormulaireClient", "Et de :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BDFormulaireClient", "Profession:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BDFormulaireClient", "Domicile habituel:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BDFormulaireClient", "Contacts (*):", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BDFormulaireClient", "Nationalit\303\251:", 0, QApplication::UnicodeUTF8));
        btn_calendrier->setText(QApplication::translate("BDFormulaireClient", "...", 0, QApplication::UnicodeUTF8));
        groupBoxCategorie->setTitle(QApplication::translate("BDFormulaireClient", "Cat\303\251gorie", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("BDFormulaireClient", "Type de client:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("BDFormulaireClient", "Profile:", 0, QApplication::UnicodeUTF8));
        groupBoxPiece->setTitle(QApplication::translate("BDFormulaireClient", "Pi\303\250ces d'identit\303\251 produites", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BDFormulaireClient", "Nature:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("BDFormulaireClient", "N\302\260 :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("BDFormulaireClient", "D\303\251livr\303\251 le:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("BDFormulaireClient", "A :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("BDFormulaireClient", "Par :", 0, QApplication::UnicodeUTF8));
        groupBoxInfosSupp->setTitle(QApplication::translate("BDFormulaireClient", "Informations suppl\303\251mentaires", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("BDFormulaireClient", "Nombre d'enfants de moins de 15 ans accompagnant:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("BDFormulaireClient", "Destination exacte: ", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDFormulaireClient", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDFormulaireClient", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDFormulaireClient: public Ui_BDFormulaireClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDFORMULAIRECLIENT_H
