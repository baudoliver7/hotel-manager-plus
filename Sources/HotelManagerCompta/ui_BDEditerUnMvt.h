/********************************************************************************
** Form generated from reading UI file 'BDEditerUnMvt.ui'
**
** Created: Fri 25. Jan 23:18:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDEDITERUNMVT_H
#define UI_BDEDITERUNMVT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BDEditerUnMvt
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBoxLibelleCpt;
    QFormLayout *formLayout_3;
    QLabel *labelMontant;
    QSpinBox *spinBoxMontant;
    QFormLayout *formLayout_4;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDEditerUnMvt)
    {
        if (BDEditerUnMvt->objectName().isEmpty())
            BDEditerUnMvt->setObjectName(QString::fromUtf8("BDEditerUnMvt"));
        BDEditerUnMvt->resize(439, 99);
        gridLayout = new QGridLayout(BDEditerUnMvt);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(BDEditerUnMvt);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBoxLibelleCpt = new QComboBox(BDEditerUnMvt);
        comboBoxLibelleCpt->setObjectName(QString::fromUtf8("comboBoxLibelleCpt"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxLibelleCpt);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_3->setContentsMargins(-1, -1, 8, -1);
        labelMontant = new QLabel(BDEditerUnMvt);
        labelMontant->setObjectName(QString::fromUtf8("labelMontant"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelMontant);

        spinBoxMontant = new QSpinBox(BDEditerUnMvt);
        spinBoxMontant->setObjectName(QString::fromUtf8("spinBoxMontant"));
        spinBoxMontant->setMaximumSize(QSize(150, 16777215));
        spinBoxMontant->setMaximum(1000000000);
        spinBoxMontant->setSingleStep(1000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBoxMontant);


        gridLayout->addLayout(formLayout_3, 1, 0, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_4->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_4->setContentsMargins(-1, -1, 8, -1);
        btn_ok = new QPushButton(BDEditerUnMvt);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDEditerUnMvt);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 16777215));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout_4, 2, 0, 1, 1);


        retranslateUi(BDEditerUnMvt);

        QMetaObject::connectSlotsByName(BDEditerUnMvt);
    } // setupUi

    void retranslateUi(QDialog *BDEditerUnMvt)
    {
        BDEditerUnMvt->setWindowTitle(QApplication::translate("BDEditerUnMvt", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDEditerUnMvt", "Libell\303\251 du compte :", 0, QApplication::UnicodeUTF8));
        labelMontant->setText(QApplication::translate("BDEditerUnMvt", "Montant :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDEditerUnMvt", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDEditerUnMvt", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDEditerUnMvt: public Ui_BDEditerUnMvt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDEDITERUNMVT_H
