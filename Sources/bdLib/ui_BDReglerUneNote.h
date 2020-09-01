/********************************************************************************
** Form generated from reading UI file 'BDReglerUneNote.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDREGLERUNENOTE_H
#define UI_BDREGLERUNENOTE_H

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
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDReglerUneNote
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditMontantRestant;
    QSpinBox *spinBoxMontantEncaisse;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDReglerUneNote)
    {
        if (BDReglerUneNote->objectName().isEmpty())
            BDReglerUneNote->setObjectName(QString::fromUtf8("BDReglerUneNote"));
        BDReglerUneNote->resize(245, 102);
        gridLayout = new QGridLayout(BDReglerUneNote);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(BDReglerUneNote);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(BDReglerUneNote);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEditMontantRestant = new QLineEdit(BDReglerUneNote);
        lineEditMontantRestant->setObjectName(QString::fromUtf8("lineEditMontantRestant"));
        lineEditMontantRestant->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantRestant->setReadOnly(true);

        verticalLayout->addWidget(lineEditMontantRestant);

        spinBoxMontantEncaisse = new QSpinBox(BDReglerUneNote);
        spinBoxMontantEncaisse->setObjectName(QString::fromUtf8("spinBoxMontantEncaisse"));
        spinBoxMontantEncaisse->setSingleStep(500);

        verticalLayout->addWidget(spinBoxMontantEncaisse);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 8, -1);
        btn_ok = new QPushButton(BDReglerUneNote);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDReglerUneNote);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);


        retranslateUi(BDReglerUneNote);

        QMetaObject::connectSlotsByName(BDReglerUneNote);
    } // setupUi

    void retranslateUi(QDialog *BDReglerUneNote)
    {
        BDReglerUneNote->setWindowTitle(QApplication::translate("BDReglerUneNote", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDReglerUneNote", "Montant restant :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDReglerUneNote", "Montant encaiss\303\251 :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDReglerUneNote", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDReglerUneNote", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDReglerUneNote: public Ui_BDReglerUneNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDREGLERUNENOTE_H
