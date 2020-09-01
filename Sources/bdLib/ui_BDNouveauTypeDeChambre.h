/********************************************************************************
** Form generated from reading UI file 'BDNouveauTypeDeChambre.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDNOUVEAUTYPEDECHAMBRE_H
#define UI_BDNOUVEAUTYPEDECHAMBRE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BDNouveauTypeDeChambre
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QPushButton *btn_annuler;
    QPushButton *btn_ok;
    QLabel *label;
    QLineEdit *lineEditDesignation;

    void setupUi(QDialog *BDNouveauTypeDeChambre)
    {
        if (BDNouveauTypeDeChambre->objectName().isEmpty())
            BDNouveauTypeDeChambre->setObjectName(QString::fromUtf8("BDNouveauTypeDeChambre"));
        BDNouveauTypeDeChambre->resize(320, 69);
        gridLayout = new QGridLayout(BDNouveauTypeDeChambre);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_annuler = new QPushButton(BDNouveauTypeDeChambre);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);

        btn_ok = new QPushButton(BDNouveauTypeDeChambre);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));
        btn_ok->setDefault(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);


        gridLayout->addLayout(formLayout, 1, 1, 1, 1);

        label = new QLabel(BDNouveauTypeDeChambre);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditDesignation = new QLineEdit(BDNouveauTypeDeChambre);
        lineEditDesignation->setObjectName(QString::fromUtf8("lineEditDesignation"));

        gridLayout->addWidget(lineEditDesignation, 0, 1, 1, 1);


        retranslateUi(BDNouveauTypeDeChambre);

        QMetaObject::connectSlotsByName(BDNouveauTypeDeChambre);
    } // setupUi

    void retranslateUi(QDialog *BDNouveauTypeDeChambre)
    {
        BDNouveauTypeDeChambre->setWindowTitle(QApplication::translate("BDNouveauTypeDeChambre", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDNouveauTypeDeChambre", "Annuler", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDNouveauTypeDeChambre", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDNouveauTypeDeChambre", "D\303\251signation:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDNouveauTypeDeChambre: public Ui_BDNouveauTypeDeChambre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDNOUVEAUTYPEDECHAMBRE_H
