/********************************************************************************
** Form generated from reading UI file 'BDNouveauInitial.ui'
**
** Created: Wed 30. May 16:07:41 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDNOUVEAUINITIAL_H
#define UI_BDNOUVEAUINITIAL_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDNouveauInitial
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditInitial;
    QFormLayout *formLayout;
    QPushButton *btn_OK;
    QPushButton *btn_Annuler;

    void setupUi(QDialog *BDNouveauInitial)
    {
        if (BDNouveauInitial->objectName().isEmpty())
            BDNouveauInitial->setObjectName(QString::fromUtf8("BDNouveauInitial"));
        BDNouveauInitial->resize(322, 73);
        BDNouveauInitial->setMinimumSize(QSize(322, 73));
        BDNouveauInitial->setMaximumSize(QSize(322, 73));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        BDNouveauInitial->setWindowIcon(icon);
        gridLayout = new QGridLayout(BDNouveauInitial);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(49);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(BDNouveauInitial);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEditInitial = new QLineEdit(BDNouveauInitial);
        lineEditInitial->setObjectName(QString::fromUtf8("lineEditInitial"));

        horizontalLayout_2->addWidget(lineEditInitial);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_OK = new QPushButton(BDNouveauInitial);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_OK);

        btn_Annuler = new QPushButton(BDNouveauInitial);
        btn_Annuler->setObjectName(QString::fromUtf8("btn_Annuler"));
        btn_Annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_Annuler);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);


        retranslateUi(BDNouveauInitial);

        QMetaObject::connectSlotsByName(BDNouveauInitial);
    } // setupUi

    void retranslateUi(QDialog *BDNouveauInitial)
    {
        BDNouveauInitial->setWindowTitle(QApplication::translate("BDNouveauInitial", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDNouveauInitial", "Initial :", 0, QApplication::UnicodeUTF8));
        btn_OK->setText(QApplication::translate("BDNouveauInitial", "OK", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("BDNouveauInitial", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDNouveauInitial: public Ui_BDNouveauInitial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDNOUVEAUINITIAL_H
