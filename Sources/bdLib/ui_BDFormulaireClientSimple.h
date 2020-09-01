/********************************************************************************
** Form generated from reading UI file 'BDFormulaireClientSimple.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDFORMULAIRECLIENTSIMPLE_H
#define UI_BDFORMULAIRECLIENTSIMPLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDFormulaireClientSimple
{
public:
    QGridLayout *gridLayout;
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

    void setupUi(QDialog *BDFormulaireClientSimple)
    {
        if (BDFormulaireClientSimple->objectName().isEmpty())
            BDFormulaireClientSimple->setObjectName(QString::fromUtf8("BDFormulaireClientSimple"));
        BDFormulaireClientSimple->resize(295, 342);
        gridLayout = new QGridLayout(BDFormulaireClientSimple);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        rb_masculin = new QRadioButton(BDFormulaireClientSimple);
        rb_masculin->setObjectName(QString::fromUtf8("rb_masculin"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rb_masculin);

        rb_feminin = new QRadioButton(BDFormulaireClientSimple);
        rb_feminin->setObjectName(QString::fromUtf8("rb_feminin"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, rb_feminin);


        gridLayout->addLayout(formLayout_2, 0, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(BDFormulaireClientSimple);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(BDFormulaireClientSimple);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(BDFormulaireClientSimple);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(BDFormulaireClientSimple);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(BDFormulaireClientSimple);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(BDFormulaireClientSimple);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(BDFormulaireClientSimple);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(BDFormulaireClientSimple);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(BDFormulaireClientSimple);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(BDFormulaireClientSimple);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEditNom = new QLineEdit(BDFormulaireClientSimple);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));

        verticalLayout_2->addWidget(lineEditNom);

        lineEditPrenom = new QLineEdit(BDFormulaireClientSimple);
        lineEditPrenom->setObjectName(QString::fromUtf8("lineEditPrenom"));

        verticalLayout_2->addWidget(lineEditPrenom);

        dateEditDateDeNaiss = new QDateEdit(BDFormulaireClientSimple);
        dateEditDateDeNaiss->setObjectName(QString::fromUtf8("dateEditDateDeNaiss"));

        verticalLayout_2->addWidget(dateEditDateDeNaiss);

        lineEditLieuDeNaiss = new QLineEdit(BDFormulaireClientSimple);
        lineEditLieuDeNaiss->setObjectName(QString::fromUtf8("lineEditLieuDeNaiss"));

        verticalLayout_2->addWidget(lineEditLieuDeNaiss);

        lineEditPere = new QLineEdit(BDFormulaireClientSimple);
        lineEditPere->setObjectName(QString::fromUtf8("lineEditPere"));

        verticalLayout_2->addWidget(lineEditPere);

        lineEditMere = new QLineEdit(BDFormulaireClientSimple);
        lineEditMere->setObjectName(QString::fromUtf8("lineEditMere"));

        verticalLayout_2->addWidget(lineEditMere);

        lineEditProfession = new QLineEdit(BDFormulaireClientSimple);
        lineEditProfession->setObjectName(QString::fromUtf8("lineEditProfession"));

        verticalLayout_2->addWidget(lineEditProfession);

        lineEditDomicile = new QLineEdit(BDFormulaireClientSimple);
        lineEditDomicile->setObjectName(QString::fromUtf8("lineEditDomicile"));

        verticalLayout_2->addWidget(lineEditDomicile);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditContacts = new QLineEdit(BDFormulaireClientSimple);
        lineEditContacts->setObjectName(QString::fromUtf8("lineEditContacts"));
        lineEditContacts->setReadOnly(true);

        horizontalLayout->addWidget(lineEditContacts);

        btn_calendrier = new QToolButton(BDFormulaireClientSimple);
        btn_calendrier->setObjectName(QString::fromUtf8("btn_calendrier"));

        horizontalLayout->addWidget(btn_calendrier);


        verticalLayout_2->addLayout(horizontalLayout);

        lineEditNationalite = new QLineEdit(BDFormulaireClientSimple);
        lineEditNationalite->setObjectName(QString::fromUtf8("lineEditNationalite"));

        verticalLayout_2->addWidget(lineEditNationalite);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_4->setContentsMargins(-1, -1, 8, -1);
        btn_ok = new QPushButton(BDFormulaireClientSimple);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDFormulaireClientSimple);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout_4, 2, 1, 1, 1);


        retranslateUi(BDFormulaireClientSimple);

        QMetaObject::connectSlotsByName(BDFormulaireClientSimple);
    } // setupUi

    void retranslateUi(QDialog *BDFormulaireClientSimple)
    {
        BDFormulaireClientSimple->setWindowTitle(QApplication::translate("BDFormulaireClientSimple", "Dialog", 0, QApplication::UnicodeUTF8));
        rb_masculin->setText(QApplication::translate("BDFormulaireClientSimple", "Masculin", 0, QApplication::UnicodeUTF8));
        rb_feminin->setText(QApplication::translate("BDFormulaireClientSimple", "F\303\251minin", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDFormulaireClientSimple", "Nom:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDFormulaireClientSimple", "Pr\303\251nom(s):", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDFormulaireClientSimple", "N\303\251(e) le:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDFormulaireClientSimple", "A :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDFormulaireClientSimple", "Fils (Fille) de:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDFormulaireClientSimple", "Et de :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BDFormulaireClientSimple", "Profession:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BDFormulaireClientSimple", "Domicile habituel:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BDFormulaireClientSimple", "Contacts:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BDFormulaireClientSimple", "Nationalit\303\251:", 0, QApplication::UnicodeUTF8));
        btn_calendrier->setText(QApplication::translate("BDFormulaireClientSimple", "...", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDFormulaireClientSimple", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDFormulaireClientSimple", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDFormulaireClientSimple: public Ui_BDFormulaireClientSimple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDFORMULAIRECLIENTSIMPLE_H
