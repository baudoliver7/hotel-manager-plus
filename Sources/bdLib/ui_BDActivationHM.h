/********************************************************************************
** Form generated from reading UI file 'BDActivationHM.ui'
**
** Created: Thu 29. Dec 17:14:43 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDACTIVATIONHM_H
#define UI_BDACTIVATIONHM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_BDActivationHM
{
public:

    void setupUi(QDialog *BDActivationHM)
    {
        if (BDActivationHM->objectName().isEmpty())
            BDActivationHM->setObjectName(QString::fromUtf8("BDActivationHM"));
        BDActivationHM->resize(473, 300);

        retranslateUi(BDActivationHM);

        QMetaObject::connectSlotsByName(BDActivationHM);
    } // setupUi

    void retranslateUi(QDialog *BDActivationHM)
    {
        BDActivationHM->setWindowTitle(QApplication::translate("BDActivationHM", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDActivationHM: public Ui_BDActivationHM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDACTIVATIONHM_H
