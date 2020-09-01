/********************************************************************************
** Form generated from reading UI file 'bdconfigtaux.ui'
**
** Created: Sun 27. Oct 20:00:19 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCONFIGTAUX_H
#define UI_BDCONFIGTAUX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BDConfigTaux
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *doubleSpinBoxTTVA;
    QDoubleSpinBox *doubleSpinBoxTTT;

    void setupUi(QDialog *BDConfigTaux)
    {
        if (BDConfigTaux->objectName().isEmpty())
            BDConfigTaux->setObjectName(QString::fromUtf8("BDConfigTaux"));
        BDConfigTaux->resize(270, 123);
        buttonBox = new QDialogButtonBox(BDConfigTaux);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 80, 221, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(BDConfigTaux);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 20, 172, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        doubleSpinBoxTTVA = new QDoubleSpinBox(widget);
        doubleSpinBoxTTVA->setObjectName(QString::fromUtf8("doubleSpinBoxTTVA"));
        doubleSpinBoxTTVA->setMaximum(1);
        doubleSpinBoxTTVA->setSingleStep(0.01);

        verticalLayout->addWidget(doubleSpinBoxTTVA);

        doubleSpinBoxTTT = new QDoubleSpinBox(widget);
        doubleSpinBoxTTT->setObjectName(QString::fromUtf8("doubleSpinBoxTTT"));
        doubleSpinBoxTTT->setMaximum(1);
        doubleSpinBoxTTT->setSingleStep(0.01);

        verticalLayout->addWidget(doubleSpinBoxTTT);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(BDConfigTaux);
        QObject::connect(buttonBox, SIGNAL(accepted()), BDConfigTaux, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BDConfigTaux, SLOT(reject()));

        QMetaObject::connectSlotsByName(BDConfigTaux);
    } // setupUi

    void retranslateUi(QDialog *BDConfigTaux)
    {
        BDConfigTaux->setWindowTitle(QApplication::translate("BDConfigTaux", "Configurer taux", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDConfigTaux", "Taux TVA :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDConfigTaux", "Taux Taxe Touristique :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDConfigTaux: public Ui_BDConfigTaux {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCONFIGTAUX_H
