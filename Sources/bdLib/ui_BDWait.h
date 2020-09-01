/********************************************************************************
** Form generated from reading UI file 'BDWait.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDWAIT_H
#define UI_BDWAIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_BDWait
{
public:
    QLabel *label;

    void setupUi(QDialog *BDWait)
    {
        if (BDWait->objectName().isEmpty())
            BDWait->setObjectName(QString::fromUtf8("BDWait"));
        BDWait->resize(321, 57);
        BDWait->setMinimumSize(QSize(321, 57));
        BDWait->setMaximumSize(QSize(321, 57));
        label = new QLabel(BDWait);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 291, 41));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        retranslateUi(BDWait);

        QMetaObject::connectSlotsByName(BDWait);
    } // setupUi

    void retranslateUi(QDialog *BDWait)
    {
        BDWait->setWindowTitle(QApplication::translate("BDWait", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDWait", "Veuillez patienter quelques secondes...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDWait: public Ui_BDWait {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDWAIT_H
