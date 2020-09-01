/********************************************************************************
** Form generated from reading UI file 'BDConfigurerModule.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCONFIGURERMODULE_H
#define UI_BDCONFIGURERMODULE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_BDConfigurerModule
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *rb_bar;
    QRadioButton *rb_restoBar;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDConfigurerModule)
    {
        if (BDConfigurerModule->objectName().isEmpty())
            BDConfigurerModule->setObjectName(QString::fromUtf8("BDConfigurerModule"));
        BDConfigurerModule->resize(247, 122);
        gridLayout = new QGridLayout(BDConfigurerModule);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(BDConfigurerModule);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rb_bar = new QRadioButton(groupBox);
        rb_bar->setObjectName(QString::fromUtf8("rb_bar"));

        gridLayout_2->addWidget(rb_bar, 0, 0, 1, 1);

        rb_restoBar = new QRadioButton(groupBox);
        rb_restoBar->setObjectName(QString::fromUtf8("rb_restoBar"));

        gridLayout_2->addWidget(rb_restoBar, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_ok = new QPushButton(BDConfigurerModule);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDConfigurerModule);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);


        retranslateUi(BDConfigurerModule);

        QMetaObject::connectSlotsByName(BDConfigurerModule);
    } // setupUi

    void retranslateUi(QDialog *BDConfigurerModule)
    {
        BDConfigurerModule->setWindowTitle(QApplication::translate("BDConfigurerModule", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDConfigurerModule", "Utiliser le module comme un gestionnaire de", 0, QApplication::UnicodeUTF8));
        rb_bar->setText(QApplication::translate("BDConfigurerModule", "Bar", 0, QApplication::UnicodeUTF8));
        rb_restoBar->setText(QApplication::translate("BDConfigurerModule", "Restaurant ou restaurant-Bar", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDConfigurerModule", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDConfigurerModule", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDConfigurerModule: public Ui_BDConfigurerModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCONFIGURERMODULE_H
