/********************************************************************************
** Form generated from reading UI file 'BDRechercherUtil.ui'
**
** Created: Sat 24. Mar 10:43:34 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDRECHERCHERUTIL_H
#define UI_BDRECHERCHERUTIL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_BDRechercherUtil
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *Masculin;
    QRadioButton *Feminin;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *lineEditNom;
    QTableView *tableViewUtilisateurs;
    QFormLayout *formLayout;
    QPushButton *btn_choisir;
    QPushButton *btn_Annuler;

    void setupUi(QDialog *BDRechercherUtil)
    {
        if (BDRechercherUtil->objectName().isEmpty())
            BDRechercherUtil->setObjectName(QString::fromUtf8("BDRechercherUtil"));
        BDRechercherUtil->resize(752, 358);
        gridLayout_2 = new QGridLayout(BDRechercherUtil);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(BDRechercherUtil);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Masculin = new QRadioButton(groupBox);
        Masculin->setObjectName(QString::fromUtf8("Masculin"));
        Masculin->setChecked(true);

        gridLayout->addWidget(Masculin, 0, 0, 1, 1);

        Feminin = new QRadioButton(groupBox);
        Feminin->setObjectName(QString::fromUtf8("Feminin"));

        gridLayout->addWidget(Feminin, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label = new QLabel(BDRechercherUtil);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        lineEditNom = new QLineEdit(BDRechercherUtil);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));
        lineEditNom->setMaximumSize(QSize(133, 16777215));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditNom);


        gridLayout_2->addLayout(formLayout_2, 0, 1, 1, 1);

        tableViewUtilisateurs = new QTableView(BDRechercherUtil);
        tableViewUtilisateurs->setObjectName(QString::fromUtf8("tableViewUtilisateurs"));
        tableViewUtilisateurs->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewUtilisateurs->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewUtilisateurs->setTextElideMode(Qt::ElideMiddle);
        tableViewUtilisateurs->horizontalHeader()->setDefaultSectionSize(150);

        gridLayout_2->addWidget(tableViewUtilisateurs, 1, 0, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_choisir = new QPushButton(BDRechercherUtil);
        btn_choisir->setObjectName(QString::fromUtf8("btn_choisir"));
        btn_choisir->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_choisir);

        btn_Annuler = new QPushButton(BDRechercherUtil);
        btn_Annuler->setObjectName(QString::fromUtf8("btn_Annuler"));
        btn_Annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_Annuler);


        gridLayout_2->addLayout(formLayout, 2, 1, 1, 1);


        retranslateUi(BDRechercherUtil);

        QMetaObject::connectSlotsByName(BDRechercherUtil);
    } // setupUi

    void retranslateUi(QDialog *BDRechercherUtil)
    {
        BDRechercherUtil->setWindowTitle(QApplication::translate("BDRechercherUtil", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDRechercherUtil", "Sexe", 0, QApplication::UnicodeUTF8));
        Masculin->setText(QApplication::translate("BDRechercherUtil", "Masculin", 0, QApplication::UnicodeUTF8));
        Feminin->setText(QApplication::translate("BDRechercherUtil", "F\303\251minin", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDRechercherUtil", "Nom :", 0, QApplication::UnicodeUTF8));
        btn_choisir->setText(QApplication::translate("BDRechercherUtil", "Choisir", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("BDRechercherUtil", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDRechercherUtil: public Ui_BDRechercherUtil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDRECHERCHERUTIL_H
