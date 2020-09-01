/********************************************************************************
** Form generated from reading UI file 'BDInfosHotels.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDINFOSHOTELS_H
#define UI_BDINFOSHOTELS_H

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
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDInfosHotels
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditNom;
    QLineEdit *lineEditVille;
    QLineEdit *lineEditQuartier;
    QFormLayout *formLayout_2;
    QLineEdit *lineEditContacts;
    QToolButton *btn_contacts;
    QLineEdit *lineEditSiteWeb;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btn_insererLogo;
    QLabel *labelLogo;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDInfosHotels)
    {
        if (BDInfosHotels->objectName().isEmpty())
            BDInfosHotels->setObjectName(QString::fromUtf8("BDInfosHotels"));
        BDInfosHotels->resize(390, 211);
        gridLayout_3 = new QGridLayout(BDInfosHotels);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(BDInfosHotels);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEditNom = new QLineEdit(groupBox_2);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));

        verticalLayout->addWidget(lineEditNom);

        lineEditVille = new QLineEdit(groupBox_2);
        lineEditVille->setObjectName(QString::fromUtf8("lineEditVille"));

        verticalLayout->addWidget(lineEditVille);

        lineEditQuartier = new QLineEdit(groupBox_2);
        lineEditQuartier->setObjectName(QString::fromUtf8("lineEditQuartier"));

        verticalLayout->addWidget(lineEditQuartier);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        lineEditContacts = new QLineEdit(groupBox_2);
        lineEditContacts->setObjectName(QString::fromUtf8("lineEditContacts"));
        lineEditContacts->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditContacts->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lineEditContacts);

        btn_contacts = new QToolButton(groupBox_2);
        btn_contacts->setObjectName(QString::fromUtf8("btn_contacts"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_contacts);


        verticalLayout->addLayout(formLayout_2);

        lineEditSiteWeb = new QLineEdit(groupBox_2);
        lineEditSiteWeb->setObjectName(QString::fromUtf8("lineEditSiteWeb"));

        verticalLayout->addWidget(lineEditSiteWeb);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(BDInfosHotels);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_insererLogo = new QPushButton(groupBox);
        btn_insererLogo->setObjectName(QString::fromUtf8("btn_insererLogo"));
        btn_insererLogo->setMaximumSize(QSize(90, 23));

        gridLayout->addWidget(btn_insererLogo, 1, 0, 1, 1);

        labelLogo = new QLabel(groupBox);
        labelLogo->setObjectName(QString::fromUtf8("labelLogo"));
        labelLogo->setMinimumSize(QSize(100, 100));
        labelLogo->setMaximumSize(QSize(100, 100));
        labelLogo->setScaledContents(true);

        gridLayout->addWidget(labelLogo, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_ok = new QPushButton(BDInfosHotels);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDInfosHotels);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout_3->addLayout(formLayout, 1, 0, 1, 2);


        retranslateUi(BDInfosHotels);

        QMetaObject::connectSlotsByName(BDInfosHotels);
    } // setupUi

    void retranslateUi(QDialog *BDInfosHotels)
    {
        BDInfosHotels->setWindowTitle(QApplication::translate("BDInfosHotels", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDInfosHotels", "Informations", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDInfosHotels", "Nom :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDInfosHotels", "Ville :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDInfosHotels", "Quartier :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDInfosHotels", "Contacts :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDInfosHotels", "Site web :", 0, QApplication::UnicodeUTF8));
        btn_contacts->setText(QApplication::translate("BDInfosHotels", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDInfosHotels", "Logo", 0, QApplication::UnicodeUTF8));
        btn_insererLogo->setText(QApplication::translate("BDInfosHotels", "Ins\303\251rer un logo", 0, QApplication::UnicodeUTF8));
        labelLogo->setText(QString());
        btn_ok->setText(QApplication::translate("BDInfosHotels", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDInfosHotels", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDInfosHotels: public Ui_BDInfosHotels {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDINFOSHOTELS_H
