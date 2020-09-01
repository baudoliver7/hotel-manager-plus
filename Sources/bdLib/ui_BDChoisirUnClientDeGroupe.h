/********************************************************************************
** Form generated from reading UI file 'BDChoisirUnClientDeGroupe.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCHOISIRUNCLIENTDEGROUPE_H
#define UI_BDCHOISIRUNCLIENTDEGROUPE_H

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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDChoisirUnClientDeGroupe
{
public:
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidgetGroupesEnCours;
    QGroupBox *groupBoxMembres;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidgetMembres;
    QGroupBox *groupBox_2;
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
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QComboBox *comboBoxTypeDeClient;
    QLabel *label_4;
    QComboBox *comboBoxProfile;
    QGroupBox *groupBoxInfosSupp;
    QGridLayout *gridLayout_6;
    QFormLayout *formLayout_3;
    QLabel *label_18;
    QSpinBox *spinBoxNbEnfants;
    QFormLayout *formLayout_4;
    QLabel *label_19;
    QLineEdit *lineEditDestinationExacte;
    QFormLayout *formLayout_2;
    QPushButton *btn_choisir;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDChoisirUnClientDeGroupe)
    {
        if (BDChoisirUnClientDeGroupe->objectName().isEmpty())
            BDChoisirUnClientDeGroupe->setObjectName(QString::fromUtf8("BDChoisirUnClientDeGroupe"));
        BDChoisirUnClientDeGroupe->resize(639, 622);
        gridLayout_7 = new QGridLayout(BDChoisirUnClientDeGroupe);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox = new QGroupBox(BDChoisirUnClientDeGroupe);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeWidgetGroupesEnCours = new QTreeWidget(groupBox);
        treeWidgetGroupesEnCours->setObjectName(QString::fromUtf8("treeWidgetGroupesEnCours"));
        treeWidgetGroupesEnCours->header()->setDefaultSectionSize(170);
        treeWidgetGroupesEnCours->header()->setStretchLastSection(true);

        gridLayout->addWidget(treeWidgetGroupesEnCours, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxMembres = new QGroupBox(BDChoisirUnClientDeGroupe);
        groupBoxMembres->setObjectName(QString::fromUtf8("groupBoxMembres"));
        gridLayout_2 = new QGridLayout(groupBoxMembres);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        treeWidgetMembres = new QTreeWidget(groupBoxMembres);
        treeWidgetMembres->setObjectName(QString::fromUtf8("treeWidgetMembres"));
        treeWidgetMembres->header()->setDefaultSectionSize(170);
        treeWidgetMembres->header()->setStretchLastSection(true);

        gridLayout_2->addWidget(treeWidgetMembres, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBoxMembres, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(BDChoisirUnClientDeGroupe);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEditClientSelectionne = new QLineEdit(groupBox_2);
        lineEditClientSelectionne->setObjectName(QString::fromUtf8("lineEditClientSelectionne"));
        lineEditClientSelectionne->setMinimumSize(QSize(335, 0));
        lineEditClientSelectionne->setMaximumSize(QSize(335, 16777215));
        lineEditClientSelectionne->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClientSelectionne->setReadOnly(true);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, lineEditClientSelectionne);


        formLayout_8->setLayout(0, QFormLayout::LabelRole, formLayout_7);

        btn_details = new QPushButton(groupBox_2);
        btn_details->setObjectName(QString::fromUtf8("btn_details"));
        btn_details->setMaximumSize(QSize(75, 23));

        formLayout_8->setWidget(0, QFormLayout::FieldRole, btn_details);


        gridLayout_5->addLayout(formLayout_8, 0, 0, 1, 2);

        groupBoxPiece = new QGroupBox(groupBox_2);
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

        groupBoxCategorie = new QGroupBox(groupBox_2);
        groupBoxCategorie->setObjectName(QString::fromUtf8("groupBoxCategorie"));
        groupBoxCategorie->setMaximumSize(QSize(327, 16777215));
        gridLayout_4 = new QGridLayout(groupBoxCategorie);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_2 = new QLabel(groupBoxCategorie);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        comboBoxTypeDeClient = new QComboBox(groupBoxCategorie);
        comboBoxTypeDeClient->setObjectName(QString::fromUtf8("comboBoxTypeDeClient"));
        comboBoxTypeDeClient->setMaximumSize(QSize(140, 16777215));

        gridLayout_4->addWidget(comboBoxTypeDeClient, 0, 1, 1, 1);

        label_4 = new QLabel(groupBoxCategorie);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        comboBoxProfile = new QComboBox(groupBoxCategorie);
        comboBoxProfile->setObjectName(QString::fromUtf8("comboBoxProfile"));
        comboBoxProfile->setMaximumSize(QSize(140, 16777215));

        gridLayout_4->addWidget(comboBoxProfile, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBoxCategorie, 1, 1, 1, 1);

        groupBoxInfosSupp = new QGroupBox(groupBox_2);
        groupBoxInfosSupp->setObjectName(QString::fromUtf8("groupBoxInfosSupp"));
        groupBoxInfosSupp->setMaximumSize(QSize(327, 16777215));
        gridLayout_6 = new QGridLayout(groupBoxInfosSupp);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_18 = new QLabel(groupBoxInfosSupp);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_18);

        spinBoxNbEnfants = new QSpinBox(groupBoxInfosSupp);
        spinBoxNbEnfants->setObjectName(QString::fromUtf8("spinBoxNbEnfants"));
        spinBoxNbEnfants->setMaximum(100);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBoxNbEnfants);


        gridLayout_6->addLayout(formLayout_3, 0, 0, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_19 = new QLabel(groupBoxInfosSupp);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_19);

        lineEditDestinationExacte = new QLineEdit(groupBoxInfosSupp);
        lineEditDestinationExacte->setObjectName(QString::fromUtf8("lineEditDestinationExacte"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEditDestinationExacte);


        gridLayout_6->addLayout(formLayout_4, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBoxInfosSupp, 2, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_2, 2, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_2->setContentsMargins(-1, -1, 7, -1);
        btn_choisir = new QPushButton(BDChoisirUnClientDeGroupe);
        btn_choisir->setObjectName(QString::fromUtf8("btn_choisir"));
        btn_choisir->setMaximumSize(QSize(75, 23));
        btn_choisir->setLayoutDirection(Qt::RightToLeft);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, btn_choisir);

        btn_fermer = new QPushButton(BDChoisirUnClientDeGroupe);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_fermer);


        gridLayout_7->addLayout(formLayout_2, 3, 0, 1, 1);


        retranslateUi(BDChoisirUnClientDeGroupe);

        QMetaObject::connectSlotsByName(BDChoisirUnClientDeGroupe);
    } // setupUi

    void retranslateUi(QDialog *BDChoisirUnClientDeGroupe)
    {
        BDChoisirUnClientDeGroupe->setWindowTitle(QApplication::translate("BDChoisirUnClientDeGroupe", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDChoisirUnClientDeGroupe", "Groupes en cours", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetGroupesEnCours->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("BDChoisirUnClientDeGroupe", "Nombre de personnes", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("BDChoisirUnClientDeGroupe", "Responsable", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("BDChoisirUnClientDeGroupe", "Libell\303\251", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("BDChoisirUnClientDeGroupe", "IdGroupe", 0, QApplication::UnicodeUTF8));
        groupBoxMembres->setTitle(QApplication::translate("BDChoisirUnClientDeGroupe", "Membres du groupe (nb membres)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetMembres->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("BDChoisirUnClientDeGroupe", "Log\303\251", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("BDChoisirUnClientDeGroupe", "Client", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("BDChoisirUnClientDeGroupe", "IdClient", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDChoisirUnClientDeGroupe", "Client choisi", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "Nom complet :", 0, QApplication::UnicodeUTF8));
        btn_details->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        groupBoxPiece->setTitle(QApplication::translate("BDChoisirUnClientDeGroupe", "Pi\303\250ces d'identit\303\251 produites", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "Nature:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "N\302\260 :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "D\303\251livr\303\251 le:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "A :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "Par :", 0, QApplication::UnicodeUTF8));
        groupBoxCategorie->setTitle(QApplication::translate("BDChoisirUnClientDeGroupe", "Cat\303\251gorie", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "Type de client :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "Profile :", 0, QApplication::UnicodeUTF8));
        groupBoxInfosSupp->setTitle(QApplication::translate("BDChoisirUnClientDeGroupe", "Autres informations", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "Nombre d'enfants de moins de 15 ans accompagnant:", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "Destination exacte: ", 0, QApplication::UnicodeUTF8));
        btn_choisir->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "Choisir", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDChoisirUnClientDeGroupe", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDChoisirUnClientDeGroupe: public Ui_BDChoisirUnClientDeGroupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCHOISIRUNCLIENTDEGROUPE_H
