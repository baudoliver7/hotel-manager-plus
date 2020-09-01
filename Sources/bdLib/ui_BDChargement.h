/********************************************************************************
** Form generated from reading UI file 'BDChargement.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCHARGEMENT_H
#define UI_BDCHARGEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_BDChargement
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *BDChargement)
    {
        if (BDChargement->objectName().isEmpty())
            BDChargement->setObjectName(QString::fromUtf8("BDChargement"));
        BDChargement->resize(400, 41);
        gridLayout = new QGridLayout(BDChargement);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(BDChargement);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(BDChargement);

        QMetaObject::connectSlotsByName(BDChargement);
    } // setupUi

    void retranslateUi(QDialog *BDChargement)
    {
        BDChargement->setWindowTitle(QApplication::translate("BDChargement", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDChargement", "Chargement...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDChargement: public Ui_BDChargement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCHARGEMENT_H
