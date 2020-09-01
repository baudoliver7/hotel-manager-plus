/********************************************************************************
** Form generated from reading UI file 'BDCreerUnGroupe.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCREERUNGROUPE_H
#define UI_BDCREERUNGROUPE_H

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
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_BDCreerUnGroupe
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditLibelle;
    QLabel *label_8;
    QComboBox *comboBoxTypeDeClient;
    QLabel *label_9;
    QComboBox *comboBoxProfile;
    QLabel *label_2;
    QLineEdit *lineEditClient;
    QToolButton *btn_identifierRespo;
    QLabel *label_12;
    QLineEdit *lineEditContacts;
    QToolButton *btn_contact;
    QLabel *label_11;
    QSpinBox *spinBoxNbPersPrevues;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditDateEntree;
    QToolButton *btn_dateEntree;
    QLabel *label_4;
    QSpinBox *spinBoxDuree;
    QLabel *label_5;
    QLabel *label_13;
    QComboBox *comboBoxTypeDeChambre;
    QLabel *label_15;
    QLineEdit *lineEditPrixUnitaireTTC;
    QLabel *label_10;
    QLineEdit *lineEditFraisHotelEstime;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_14;
    QLineEdit *lineEditNbChDispo;
    QPushButton *btn_rechercher;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QSpinBox *spinBoxAvance;
    QLabel *label_7;
    QComboBox *comboBoxModeDePayement;
    QFormLayout *formLayout;
    QPushButton *btn_creer;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDCreerUnGroupe)
    {
        if (BDCreerUnGroupe->objectName().isEmpty())
            BDCreerUnGroupe->setObjectName(QString::fromUtf8("BDCreerUnGroupe"));
        BDCreerUnGroupe->resize(332, 542);
        gridLayout_5 = new QGridLayout(BDCreerUnGroupe);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox = new QGroupBox(BDCreerUnGroupe);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditLibelle = new QLineEdit(groupBox);
        lineEditLibelle->setObjectName(QString::fromUtf8("lineEditLibelle"));

        gridLayout->addWidget(lineEditLibelle, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        comboBoxTypeDeClient = new QComboBox(groupBox);
        comboBoxTypeDeClient->setObjectName(QString::fromUtf8("comboBoxTypeDeClient"));

        gridLayout->addWidget(comboBoxTypeDeClient, 1, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        comboBoxProfile = new QComboBox(groupBox);
        comboBoxProfile->setObjectName(QString::fromUtf8("comboBoxProfile"));

        gridLayout->addWidget(comboBoxProfile, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        lineEditClient = new QLineEdit(groupBox);
        lineEditClient->setObjectName(QString::fromUtf8("lineEditClient"));
        lineEditClient->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClient->setReadOnly(true);

        gridLayout->addWidget(lineEditClient, 3, 1, 1, 1);

        btn_identifierRespo = new QToolButton(groupBox);
        btn_identifierRespo->setObjectName(QString::fromUtf8("btn_identifierRespo"));

        gridLayout->addWidget(btn_identifierRespo, 3, 2, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 4, 0, 1, 1);

        lineEditContacts = new QLineEdit(groupBox);
        lineEditContacts->setObjectName(QString::fromUtf8("lineEditContacts"));
        lineEditContacts->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditContacts->setReadOnly(true);

        gridLayout->addWidget(lineEditContacts, 4, 1, 1, 1);

        btn_contact = new QToolButton(groupBox);
        btn_contact->setObjectName(QString::fromUtf8("btn_contact"));

        gridLayout->addWidget(btn_contact, 4, 2, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 5, 0, 1, 1);

        spinBoxNbPersPrevues = new QSpinBox(groupBox);
        spinBoxNbPersPrevues->setObjectName(QString::fromUtf8("spinBoxNbPersPrevues"));
        spinBoxNbPersPrevues->setMinimum(1);
        spinBoxNbPersPrevues->setMaximum(1000);

        gridLayout->addWidget(spinBoxNbPersPrevues, 5, 1, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(BDCreerUnGroupe);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lineEditDateEntree = new QLineEdit(groupBox_2);
        lineEditDateEntree->setObjectName(QString::fromUtf8("lineEditDateEntree"));
        lineEditDateEntree->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDateEntree->setReadOnly(true);

        gridLayout_3->addWidget(lineEditDateEntree, 0, 1, 1, 2);

        btn_dateEntree = new QToolButton(groupBox_2);
        btn_dateEntree->setObjectName(QString::fromUtf8("btn_dateEntree"));

        gridLayout_3->addWidget(btn_dateEntree, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        spinBoxDuree = new QSpinBox(groupBox_2);
        spinBoxDuree->setObjectName(QString::fromUtf8("spinBoxDuree"));
        spinBoxDuree->setMinimum(1);
        spinBoxDuree->setMaximum(100);

        gridLayout_3->addWidget(spinBoxDuree, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 2, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 2, 0, 1, 1);

        comboBoxTypeDeChambre = new QComboBox(groupBox_2);
        comboBoxTypeDeChambre->setObjectName(QString::fromUtf8("comboBoxTypeDeChambre"));

        gridLayout_3->addWidget(comboBoxTypeDeChambre, 2, 1, 1, 2);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 3, 0, 1, 1);

        lineEditPrixUnitaireTTC = new QLineEdit(groupBox_2);
        lineEditPrixUnitaireTTC->setObjectName(QString::fromUtf8("lineEditPrixUnitaireTTC"));
        lineEditPrixUnitaireTTC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPrixUnitaireTTC->setReadOnly(true);

        gridLayout_3->addWidget(lineEditPrixUnitaireTTC, 3, 1, 1, 2);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 4, 0, 1, 1);

        lineEditFraisHotelEstime = new QLineEdit(groupBox_2);
        lineEditFraisHotelEstime->setObjectName(QString::fromUtf8("lineEditFraisHotelEstime"));
        lineEditFraisHotelEstime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFraisHotelEstime->setReadOnly(true);

        gridLayout_3->addWidget(lineEditFraisHotelEstime, 4, 1, 1, 2);


        gridLayout_5->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(BDCreerUnGroupe);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 0, 0, 1, 1);

        lineEditNbChDispo = new QLineEdit(groupBox_4);
        lineEditNbChDispo->setObjectName(QString::fromUtf8("lineEditNbChDispo"));
        lineEditNbChDispo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditNbChDispo->setReadOnly(true);

        gridLayout_4->addWidget(lineEditNbChDispo, 0, 1, 1, 1);

        btn_rechercher = new QPushButton(groupBox_4);
        btn_rechercher->setObjectName(QString::fromUtf8("btn_rechercher"));
        btn_rechercher->setMaximumSize(QSize(75, 23));

        gridLayout_4->addWidget(btn_rechercher, 0, 2, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(BDCreerUnGroupe);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        spinBoxAvance = new QSpinBox(groupBox_3);
        spinBoxAvance->setObjectName(QString::fromUtf8("spinBoxAvance"));
        spinBoxAvance->setMaximum(100000000);
        spinBoxAvance->setSingleStep(5000);

        gridLayout_2->addWidget(spinBoxAvance, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        comboBoxModeDePayement = new QComboBox(groupBox_3);
        comboBoxModeDePayement->setObjectName(QString::fromUtf8("comboBoxModeDePayement"));
        comboBoxModeDePayement->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_2->addWidget(comboBoxModeDePayement, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 3, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_creer = new QPushButton(BDCreerUnGroupe);
        btn_creer->setObjectName(QString::fromUtf8("btn_creer"));
        btn_creer->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_creer);

        btn_annuler = new QPushButton(BDCreerUnGroupe);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout_5->addLayout(formLayout, 4, 0, 1, 1);


        retranslateUi(BDCreerUnGroupe);

        QMetaObject::connectSlotsByName(BDCreerUnGroupe);
    } // setupUi

    void retranslateUi(QDialog *BDCreerUnGroupe)
    {
        BDCreerUnGroupe->setWindowTitle(QApplication::translate("BDCreerUnGroupe", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDCreerUnGroupe", "Identification du groupe", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDCreerUnGroupe", "Libell\303\251 :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BDCreerUnGroupe", "Type de client :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BDCreerUnGroupe", "Profile :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDCreerUnGroupe", "Responsable :", 0, QApplication::UnicodeUTF8));
        btn_identifierRespo->setText(QApplication::translate("BDCreerUnGroupe", "...", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("BDCreerUnGroupe", "Contacts :", 0, QApplication::UnicodeUTF8));
        btn_contact->setText(QApplication::translate("BDCreerUnGroupe", "...", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BDCreerUnGroupe", "Nb pers pr\303\251vues :", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDCreerUnGroupe", "D\303\251tails sur location ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDCreerUnGroupe", "Date d'arriv\303\251e :", 0, QApplication::UnicodeUTF8));
        btn_dateEntree->setText(QApplication::translate("BDCreerUnGroupe", "...", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDCreerUnGroupe", "Dur\303\251e d'occupation :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDCreerUnGroupe", "jour(s)", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("BDCreerUnGroupe", "Type de chambre maj :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("BDCreerUnGroupe", "Prix unitaire TTC :", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BDCreerUnGroupe", "Frais h\303\264tel estim\303\251 :", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("BDCreerUnGroupe", "Rechercher chambres disponibles", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("BDCreerUnGroupe", "Nb chambres dispo :", 0, QApplication::UnicodeUTF8));
        btn_rechercher->setText(QApplication::translate("BDCreerUnGroupe", "Rechercher", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("BDCreerUnGroupe", "Versement de montant", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDCreerUnGroupe", "Avance :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BDCreerUnGroupe", "Mode de payement :", 0, QApplication::UnicodeUTF8));
        btn_creer->setText(QApplication::translate("BDCreerUnGroupe", "Cr\303\251er", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDCreerUnGroupe", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDCreerUnGroupe: public Ui_BDCreerUnGroupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCREERUNGROUPE_H
