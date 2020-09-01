/********************************************************************************
** Form generated from reading UI file 'BDActivationProduct.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDACTIVATIONPRODUCT_H
#define UI_BDACTIVATIONPRODUCT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_BDActivationProduct
{
public:

    void setupUi(QDialog *BDActivationProduct)
    {
        if (BDActivationProduct->objectName().isEmpty())
            BDActivationProduct->setObjectName(QString::fromUtf8("BDActivationProduct"));
        BDActivationProduct->resize(400, 300);

        retranslateUi(BDActivationProduct);

        QMetaObject::connectSlotsByName(BDActivationProduct);
    } // setupUi

    void retranslateUi(QDialog *BDActivationProduct)
    {
        BDActivationProduct->setWindowTitle(QApplication::translate("BDActivationProduct", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDActivationProduct: public Ui_BDActivationProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDACTIVATIONPRODUCT_H
