/********************************************************************************
** Form generated from reading UI file 'BDFormulaireClientHotelSimple.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDFORMULAIRECLIENTHOTELSIMPLE_H
#define UI_BDFORMULAIRECLIENTHOTELSIMPLE_H

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
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDFormulaireClientHotelSimple
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBoxCategorie;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_16;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_5;
    QComboBox *comboBoxTypeDeClient;
    QComboBox *comboBoxProfile;
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
    QFormLayout *formLayout_4;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDFormulaireClientHotelSimple)
    {
        if (BDFormulaireClientHotelSimple->objectName().isEmpty())
            BDFormulaireClientHotelSimple->setObjectName(QString::fromUtf8("BDFormulaireClientHotelSimple"));
        BDFormulaireClientHotelSimple->resize(297, 452);
        gridLayout = new QGridLayout(BDFormulaireClientHotelSimple);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBoxCategorie = new QGroupBox(BDFormulaireClientHotelSimple);
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


        gridLayout->addWidget(groupBoxCategorie, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(BDFormulaireClientHotelSimple);
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


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_4->setContentsMargins(-1, -1, 8, -1);
        btn_ok = new QPushButton(BDFormulaireClientHotelSimple);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDFormulaireClientHotelSimple);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout_4, 2, 0, 1, 1);


        retranslateUi(BDFormulaireClientHotelSimple);

        QMetaObject::connectSlotsByName(BDFormulaireClientHotelSimple);
    } // setupUi

    void retranslateUi(QDialog *BDFormulaireClientHotelSimple)
    {
        BDFormulaireClientHotelSimple->setWindowTitle(QApplication::translate("BDFormulaireClientHotelSimple", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBoxCategorie->setTitle(QApplication::translate("BDFormulaireClientHotelSimple", "Cat\303\251gorie", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Type de client:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Profile:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDFormulaireClientHotelSimple", "Informations sur le client", 0, QApplication::UnicodeUTF8));
        rb_masculin->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Masculin", 0, QApplication::UnicodeUTF8));
        rb_feminin->setText(QApplication::translate("BDFormulaireClientHotelSimple", "F\303\251minin", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Nom (*):", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Pr\303\251nom(s) (*):", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDFormulaireClientHotelSimple", "N\303\251(e) le:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDFormulaireClientHotelSimple", "A :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Fils (Fille) de:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Et de :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Profession:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Domicile habituel:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Contacts (*):", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Nationalit\303\251:", 0, QApplication::UnicodeUTF8));
        btn_calendrier->setText(QApplication::translate("BDFormulaireClientHotelSimple", "...", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDFormulaireClientHotelSimple", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDFormulaireClientHotelSimple", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDFormulaireClientHotelSimple: public Ui_BDFormulaireClientHotelSimple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDFORMULAIRECLIENTHOTELSIMPLE_H
