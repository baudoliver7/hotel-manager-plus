/********************************************************************************
** Form generated from reading UI file 'BDRestituerAuClient.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDRESTITUERAUCLIENT_H
#define UI_BDRESTITUERAUCLIENT_H

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

QT_BEGIN_NAMESPACE

class Ui_BDRestituerAuClient
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *labelSomme;
    QLineEdit *lineEditAvance;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QSpinBox *spinBoxSommeARestituer;
    QFormLayout *formLayout_3;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDRestituerAuClient)
    {
        if (BDRestituerAuClient->objectName().isEmpty())
            BDRestituerAuClient->setObjectName(QString::fromUtf8("BDRestituerAuClient"));
        BDRestituerAuClient->resize(234, 99);
        gridLayout = new QGridLayout(BDRestituerAuClient);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setContentsMargins(-1, 0, 0, -1);
        labelSomme = new QLabel(BDRestituerAuClient);
        labelSomme->setObjectName(QString::fromUtf8("labelSomme"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelSomme);

        lineEditAvance = new QLineEdit(BDRestituerAuClient);
        lineEditAvance->setObjectName(QString::fromUtf8("lineEditAvance"));
        lineEditAvance->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditAvance);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(BDRestituerAuClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        spinBoxSommeARestituer = new QSpinBox(BDRestituerAuClient);
        spinBoxSommeARestituer->setObjectName(QString::fromUtf8("spinBoxSommeARestituer"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBoxSommeARestituer);


        gridLayout->addLayout(formLayout_2, 1, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_3->setContentsMargins(-1, -1, 8, -1);
        btn_ok = new QPushButton(BDRestituerAuClient);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDRestituerAuClient);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout_3, 2, 0, 1, 1);


        retranslateUi(BDRestituerAuClient);

        QMetaObject::connectSlotsByName(BDRestituerAuClient);
    } // setupUi

    void retranslateUi(QDialog *BDRestituerAuClient)
    {
        BDRestituerAuClient->setWindowTitle(QApplication::translate("BDRestituerAuClient", "Dialog", 0, QApplication::UnicodeUTF8));
        labelSomme->setText(QApplication::translate("BDRestituerAuClient", "Avance :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDRestituerAuClient", "Somme \303\240 restituer :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDRestituerAuClient", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDRestituerAuClient", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDRestituerAuClient: public Ui_BDRestituerAuClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDRESTITUERAUCLIENT_H
