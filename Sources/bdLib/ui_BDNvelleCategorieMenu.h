/********************************************************************************
** Form generated from reading UI file 'BDNvelleCategorieMenu.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDNVELLECATEGORIEMENU_H
#define UI_BDNVELLECATEGORIEMENU_H

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
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_BDNvelleCategorieMenu
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout_2;
    QRadioButton *rb_plat;
    QRadioButton *rb_boisson;
    QLabel *label;
    QLineEdit *lineEditLibelle;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDNvelleCategorieMenu)
    {
        if (BDNvelleCategorieMenu->objectName().isEmpty())
            BDNvelleCategorieMenu->setObjectName(QString::fromUtf8("BDNvelleCategorieMenu"));
        BDNvelleCategorieMenu->resize(321, 94);
        gridLayout = new QGridLayout(BDNvelleCategorieMenu);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        rb_plat = new QRadioButton(BDNvelleCategorieMenu);
        rb_plat->setObjectName(QString::fromUtf8("rb_plat"));
        rb_plat->setChecked(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rb_plat);

        rb_boisson = new QRadioButton(BDNvelleCategorieMenu);
        rb_boisson->setObjectName(QString::fromUtf8("rb_boisson"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, rb_boisson);


        gridLayout->addLayout(formLayout_2, 0, 0, 1, 2);

        label = new QLabel(BDNvelleCategorieMenu);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEditLibelle = new QLineEdit(BDNvelleCategorieMenu);
        lineEditLibelle->setObjectName(QString::fromUtf8("lineEditLibelle"));

        gridLayout->addWidget(lineEditLibelle, 1, 1, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 9, -1);
        btn_ok = new QPushButton(BDNvelleCategorieMenu);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDNvelleCategorieMenu);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout, 2, 2, 1, 1);


        retranslateUi(BDNvelleCategorieMenu);

        QMetaObject::connectSlotsByName(BDNvelleCategorieMenu);
    } // setupUi

    void retranslateUi(QDialog *BDNvelleCategorieMenu)
    {
        BDNvelleCategorieMenu->setWindowTitle(QApplication::translate("BDNvelleCategorieMenu", "Dialog", 0, QApplication::UnicodeUTF8));
        rb_plat->setText(QApplication::translate("BDNvelleCategorieMenu", "Plat", 0, QApplication::UnicodeUTF8));
        rb_boisson->setText(QApplication::translate("BDNvelleCategorieMenu", "Boisson", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDNvelleCategorieMenu", "Libell\303\251 :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDNvelleCategorieMenu", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDNvelleCategorieMenu", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDNvelleCategorieMenu: public Ui_BDNvelleCategorieMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDNVELLECATEGORIEMENU_H
