/********************************************************************************
** Form generated from reading UI file 'MdiModeDiffere.ui'
**
** Created: Sat 28. Jan 18:36:53 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDIMODEDIFFERE_H
#define UI_MDIMODEDIFFERE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MdiModeDiffere
{
public:
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_2;
    QLabel *label;
    QComboBox *comboBoxNomProduit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEditActivation;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *spinBoxDureeActiva;
    QComboBox *comboBoxPeriode;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spinBoxDureeTol;
    QLabel *label_5;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_13;
    QLineEdit *lineEditServeur;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_14;
    QLineEdit *lineEditUtil;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QLineEdit *lineEditPassword;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_16;
    QLineEdit *lineEditPort;
    QFormLayout *formLayout_3;
    QPushButton *btn_charger;
    QPushButton *btn_test;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *btn_rechercheUtil;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QDateTimeEdit *dateTimeEditInscription;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *lineEditNom;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLineEdit *lineEditHotel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *lineEditPrenoms;
    QHBoxLayout *horizontalLayout;
    QLabel *label_12;
    QLineEdit *lineEditVille;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QRadioButton *Masculin;
    QRadioButton *Feminin;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *lineEditContacts;
    QToolButton *btn_contacts;
    QFormLayout *formLayout;
    QPushButton *btn_initialiser;
    QPushButton *btn_activer;

    void setupUi(QWidget *MdiModeDiffere)
    {
        if (MdiModeDiffere->objectName().isEmpty())
            MdiModeDiffere->setObjectName(QString::fromUtf8("MdiModeDiffere"));
        MdiModeDiffere->resize(590, 444);
        MdiModeDiffere->setMinimumSize(QSize(590, 444));
        MdiModeDiffere->setMaximumSize(QSize(590, 444));
        gridLayout_3 = new QGridLayout(MdiModeDiffere);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_2->setContentsMargins(-1, -1, 7, -1);
        label = new QLabel(MdiModeDiffere);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        comboBoxNomProduit = new QComboBox(MdiModeDiffere);
        comboBoxNomProduit->setObjectName(QString::fromUtf8("comboBoxNomProduit"));
        comboBoxNomProduit->setMaximumSize(QSize(190, 20));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboBoxNomProduit);


        gridLayout_3->addLayout(formLayout_2, 0, 0, 1, 2);

        groupBox = new QGroupBox(MdiModeDiffere);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(301, 111));
        groupBox->setMaximumSize(QSize(301, 111));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        dateTimeEditActivation = new QDateTimeEdit(groupBox);
        dateTimeEditActivation->setObjectName(QString::fromUtf8("dateTimeEditActivation"));

        horizontalLayout_2->addWidget(dateTimeEditActivation);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        spinBoxDureeActiva = new QSpinBox(groupBox);
        spinBoxDureeActiva->setObjectName(QString::fromUtf8("spinBoxDureeActiva"));
        spinBoxDureeActiva->setMinimum(1);

        horizontalLayout_3->addWidget(spinBoxDureeActiva);

        comboBoxPeriode = new QComboBox(groupBox);
        comboBoxPeriode->setObjectName(QString::fromUtf8("comboBoxPeriode"));

        horizontalLayout_3->addWidget(comboBoxPeriode);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        spinBoxDureeTol = new QSpinBox(groupBox);
        spinBoxDureeTol->setObjectName(QString::fromUtf8("spinBoxDureeTol"));

        horizontalLayout_4->addWidget(spinBoxDureeTol);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(MdiModeDiffere);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(232, 168));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(32);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_11->addWidget(label_13);

        lineEditServeur = new QLineEdit(groupBox_3);
        lineEditServeur->setObjectName(QString::fromUtf8("lineEditServeur"));

        horizontalLayout_11->addWidget(lineEditServeur);


        gridLayout_4->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(21);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_12->addWidget(label_14);

        lineEditUtil = new QLineEdit(groupBox_3);
        lineEditUtil->setObjectName(QString::fromUtf8("lineEditUtil"));

        horizontalLayout_12->addWidget(lineEditUtil);


        gridLayout_4->addLayout(horizontalLayout_12, 1, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_13->addWidget(label_15);

        lineEditPassword = new QLineEdit(groupBox_3);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));

        horizontalLayout_13->addWidget(lineEditPassword);


        gridLayout_4->addLayout(horizontalLayout_13, 2, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(49);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_14->addWidget(label_16);

        lineEditPort = new QLineEdit(groupBox_3);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        horizontalLayout_14->addWidget(lineEditPort);


        gridLayout_4->addLayout(horizontalLayout_14, 3, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_3->setContentsMargins(-1, -1, 7, -1);
        btn_charger = new QPushButton(groupBox_3);
        btn_charger->setObjectName(QString::fromUtf8("btn_charger"));
        btn_charger->setMaximumSize(QSize(75, 23));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, btn_charger);

        btn_test = new QPushButton(groupBox_3);
        btn_test->setObjectName(QString::fromUtf8("btn_test"));
        btn_test->setMaximumSize(QSize(75, 23));
        btn_test->setLayoutDirection(Qt::RightToLeft);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, btn_test);


        gridLayout_4->addLayout(formLayout_3, 4, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 1, 1, 1, 1);

        groupBox_2 = new QGroupBox(MdiModeDiffere);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_rechercheUtil = new QPushButton(groupBox_2);
        btn_rechercheUtil->setObjectName(QString::fromUtf8("btn_rechercheUtil"));
        btn_rechercheUtil->setMaximumSize(QSize(140, 23));
        btn_rechercheUtil->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(btn_rechercheUtil, 0, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_7->addWidget(label_8);

        dateTimeEditInscription = new QDateTimeEdit(groupBox_2);
        dateTimeEditInscription->setObjectName(QString::fromUtf8("dateTimeEditInscription"));

        horizontalLayout_7->addWidget(dateTimeEditInscription);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(27);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEditNom = new QLineEdit(groupBox_2);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));

        horizontalLayout_5->addWidget(lineEditNom);


        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_10->addWidget(label_11);

        lineEditHotel = new QLineEdit(groupBox_2);
        lineEditHotel->setObjectName(QString::fromUtf8("lineEditHotel"));

        horizontalLayout_10->addWidget(lineEditHotel);


        gridLayout->addLayout(horizontalLayout_10, 2, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        lineEditPrenoms = new QLineEdit(groupBox_2);
        lineEditPrenoms->setObjectName(QString::fromUtf8("lineEditPrenoms"));

        horizontalLayout_6->addWidget(lineEditPrenoms);


        gridLayout->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout->addWidget(label_12);

        lineEditVille = new QLineEdit(groupBox_2);
        lineEditVille->setObjectName(QString::fromUtf8("lineEditVille"));

        horizontalLayout->addWidget(lineEditVille);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        Masculin = new QRadioButton(groupBox_2);
        Masculin->setObjectName(QString::fromUtf8("Masculin"));
        Masculin->setChecked(true);

        horizontalLayout_8->addWidget(Masculin);

        Feminin = new QRadioButton(groupBox_2);
        Feminin->setObjectName(QString::fromUtf8("Feminin"));

        horizontalLayout_8->addWidget(Feminin);


        gridLayout->addLayout(horizontalLayout_8, 4, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        lineEditContacts = new QLineEdit(groupBox_2);
        lineEditContacts->setObjectName(QString::fromUtf8("lineEditContacts"));
        lineEditContacts->setReadOnly(true);

        horizontalLayout_9->addWidget(lineEditContacts);

        btn_contacts = new QToolButton(groupBox_2);
        btn_contacts->setObjectName(QString::fromUtf8("btn_contacts"));

        horizontalLayout_9->addWidget(btn_contacts);


        gridLayout->addLayout(horizontalLayout_9, 5, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 2, 0, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_initialiser = new QPushButton(MdiModeDiffere);
        btn_initialiser->setObjectName(QString::fromUtf8("btn_initialiser"));
        btn_initialiser->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_initialiser);

        btn_activer = new QPushButton(MdiModeDiffere);
        btn_activer->setObjectName(QString::fromUtf8("btn_activer"));
        btn_activer->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_activer);


        gridLayout_3->addLayout(formLayout, 3, 1, 1, 1);


        retranslateUi(MdiModeDiffere);

        QMetaObject::connectSlotsByName(MdiModeDiffere);
    } // setupUi

    void retranslateUi(QWidget *MdiModeDiffere)
    {
        MdiModeDiffere->setWindowTitle(QApplication::translate("MdiModeDiffere", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MdiModeDiffere", "Nom du produit: ", 0, QApplication::UnicodeUTF8));
        comboBoxNomProduit->clear();
        comboBoxNomProduit->insertItems(0, QStringList()
         << QApplication::translate("MdiModeDiffere", "Hotel Manager Administration Plus", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MdiModeDiffere", "Hotel Manager Comptabilit\303\251 Plus", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MdiModeDiffere", "Hotel Manager R\303\251ception Plus", 0, QApplication::UnicodeUTF8)
        );
        groupBox->setTitle(QApplication::translate("MdiModeDiffere", "Informations sur l'activation", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MdiModeDiffere", "Date d'activation :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MdiModeDiffere", "Dur\303\251e d'activation :", 0, QApplication::UnicodeUTF8));
        comboBoxPeriode->clear();
        comboBoxPeriode->insertItems(0, QStringList()
         << QApplication::translate("MdiModeDiffere", "jour(s)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MdiModeDiffere", "mois", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MdiModeDiffere", "Dur\303\251e de tol\303\251rance :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MdiModeDiffere", "jours", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MdiModeDiffere", "Param\303\250tres du serveur", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MdiModeDiffere", "Serveur :", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MdiModeDiffere", "Utilisateur :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MdiModeDiffere", "Mot de passe :", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MdiModeDiffere", "Port :", 0, QApplication::UnicodeUTF8));
        btn_charger->setText(QApplication::translate("MdiModeDiffere", "Charger", 0, QApplication::UnicodeUTF8));
        btn_test->setText(QApplication::translate("MdiModeDiffere", "Tester", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MdiModeDiffere", "Informations sur l'utilisateur", 0, QApplication::UnicodeUTF8));
        btn_rechercheUtil->setText(QApplication::translate("MdiModeDiffere", "Rechercher un utilisateur", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MdiModeDiffere", "Date d'inscription :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MdiModeDiffere", "Nom :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MdiModeDiffere", "Hotel :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MdiModeDiffere", "Pr\303\251nom(s)", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MdiModeDiffere", "Ville :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MdiModeDiffere", "Sexe :", 0, QApplication::UnicodeUTF8));
        Masculin->setText(QApplication::translate("MdiModeDiffere", "Masculin", 0, QApplication::UnicodeUTF8));
        Feminin->setText(QApplication::translate("MdiModeDiffere", "F\303\251minin", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MdiModeDiffere", "Contacts :", 0, QApplication::UnicodeUTF8));
        btn_contacts->setText(QApplication::translate("MdiModeDiffere", "...", 0, QApplication::UnicodeUTF8));
        btn_initialiser->setText(QApplication::translate("MdiModeDiffere", "Initialiser", 0, QApplication::UnicodeUTF8));
        btn_activer->setText(QApplication::translate("MdiModeDiffere", "Activer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MdiModeDiffere: public Ui_MdiModeDiffere {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDIMODEDIFFERE_H
