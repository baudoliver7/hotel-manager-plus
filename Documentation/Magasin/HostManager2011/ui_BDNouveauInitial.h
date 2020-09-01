/********************************************************************************
** Form generated from reading UI file 'BDNouveauInitial.ui'
**
** Created: Mon 20. Jun 16:30:34 2011
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
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BDNouveauInitial
{
public:
    QPushButton *btn_OK;
    QPushButton *btn_Annuler;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBoxTypeDeCh;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditInitial;

    void setupUi(QDialog *BDNouveauInitial)
    {
        if (BDNouveauInitial->objectName().isEmpty())
            BDNouveauInitial->setObjectName(QString::fromUtf8("BDNouveauInitial"));
        BDNouveauInitial->resize(232, 107);
        btn_OK = new QPushButton(BDNouveauInitial);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));
        btn_OK->setGeometry(QRect(70, 80, 75, 23));
        btn_Annuler = new QPushButton(BDNouveauInitial);
        btn_Annuler->setObjectName(QString::fromUtf8("btn_Annuler"));
        btn_Annuler->setGeometry(QRect(150, 80, 75, 23));
        widget = new QWidget(BDNouveauInitial);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(6, 11, 219, 61));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBoxTypeDeCh = new QComboBox(widget);
        comboBoxTypeDeCh->setObjectName(QString::fromUtf8("comboBoxTypeDeCh"));

        horizontalLayout->addWidget(comboBoxTypeDeCh);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(49);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEditInitial = new QLineEdit(widget);
        lineEditInitial->setObjectName(QString::fromUtf8("lineEditInitial"));

        horizontalLayout_2->addWidget(lineEditInitial);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(BDNouveauInitial);

        QMetaObject::connectSlotsByName(BDNouveauInitial);
    } // setupUi

    void retranslateUi(QDialog *BDNouveauInitial)
    {
        BDNouveauInitial->setWindowTitle(QApplication::translate("BDNouveauInitial", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_OK->setText(QApplication::translate("BDNouveauInitial", "OK", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("BDNouveauInitial", "Annuler", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDNouveauInitial", "Type de chambre :", 0, QApplication::UnicodeUTF8));
        comboBoxTypeDeCh->clear();
        comboBoxTypeDeCh->insertItems(0, QStringList()
         << QApplication::translate("BDNouveauInitial", "Chambre ventil\303\251e", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDNouveauInitial", "Chambre climatis\303\251e", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDNouveauInitial", "Suite", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("BDNouveauInitial", "Initial :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDNouveauInitial: public Ui_BDNouveauInitial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDNOUVEAUINITIAL_H
