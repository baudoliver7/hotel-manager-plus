/********************************************************************************
** Form generated from reading UI file 'BDDetailsRestoGroupe.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDDETAILSRESTOGROUPE_H
#define UI_BDDETAILSRESTOGROUPE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_BDDetailsRestoGroupe
{
public:

    void setupUi(QDialog *BDDetailsRestoGroupe)
    {
        if (BDDetailsRestoGroupe->objectName().isEmpty())
            BDDetailsRestoGroupe->setObjectName(QString::fromUtf8("BDDetailsRestoGroupe"));
        BDDetailsRestoGroupe->resize(400, 300);

        retranslateUi(BDDetailsRestoGroupe);

        QMetaObject::connectSlotsByName(BDDetailsRestoGroupe);
    } // setupUi

    void retranslateUi(QDialog *BDDetailsRestoGroupe)
    {
        BDDetailsRestoGroupe->setWindowTitle(QApplication::translate("BDDetailsRestoGroupe", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDDetailsRestoGroupe: public Ui_BDDetailsRestoGroupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDDETAILSRESTOGROUPE_H
