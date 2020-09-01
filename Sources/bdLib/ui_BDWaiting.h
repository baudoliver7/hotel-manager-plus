/********************************************************************************
** Form generated from reading UI file 'BDWaiting.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDWAITING_H
#define UI_BDWAITING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_BDWaiting
{
public:
    QLabel *label;

    void setupUi(QDialog *BDWaiting)
    {
        if (BDWaiting->objectName().isEmpty())
            BDWaiting->setObjectName(QString::fromUtf8("BDWaiting"));
        BDWaiting->resize(230, 66);
        BDWaiting->setMinimumSize(QSize(230, 66));
        BDWaiting->setMaximumSize(QSize(266, 83));
        BDWaiting->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(BDWaiting);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-10, -10, 251, 91));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/wait.png")));
        label->setScaledContents(true);

        retranslateUi(BDWaiting);

        QMetaObject::connectSlotsByName(BDWaiting);
    } // setupUi

    void retranslateUi(QDialog *BDWaiting)
    {
        BDWaiting->setWindowTitle(QApplication::translate("BDWaiting", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BDWaiting: public Ui_BDWaiting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDWAITING_H
