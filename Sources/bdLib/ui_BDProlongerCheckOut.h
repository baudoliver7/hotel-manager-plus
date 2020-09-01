/********************************************************************************
** Form generated from reading UI file 'BDProlongerCheckOut.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDPROLONGERCHECKOUT_H
#define UI_BDPROLONGERCHECKOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BDProlongerCheckOut
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDProlongerCheckOut)
    {
        if (BDProlongerCheckOut->objectName().isEmpty())
            BDProlongerCheckOut->setObjectName(QString::fromUtf8("BDProlongerCheckOut"));
        BDProlongerCheckOut->resize(216, 73);
        gridLayout = new QGridLayout(BDProlongerCheckOut);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(BDProlongerCheckOut);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(BDProlongerCheckOut);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_ok = new QPushButton(BDProlongerCheckOut);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDProlongerCheckOut);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);


        retranslateUi(BDProlongerCheckOut);

        QMetaObject::connectSlotsByName(BDProlongerCheckOut);
    } // setupUi

    void retranslateUi(QDialog *BDProlongerCheckOut)
    {
        BDProlongerCheckOut->setWindowTitle(QApplication::translate("BDProlongerCheckOut", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDProlongerCheckOut", "Nombre de jours \303\240 ajouter:", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDProlongerCheckOut", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDProlongerCheckOut", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDProlongerCheckOut: public Ui_BDProlongerCheckOut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDPROLONGERCHECKOUT_H
