/********************************************************************************
** Form generated from reading UI file 'DialogCalendar.ui'
**
** Created: Mon 20. Jun 16:30:34 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCALENDAR_H
#define UI_DIALOGCALENDAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DialogCalendar
{
public:
    QDialogButtonBox *buttonBox;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *DialogCalendar)
    {
        if (DialogCalendar->objectName().isEmpty())
            DialogCalendar->setObjectName(QString::fromUtf8("DialogCalendar"));
        DialogCalendar->resize(374, 186);
        buttonBox = new QDialogButtonBox(DialogCalendar);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        calendarWidget = new QCalendarWidget(DialogCalendar);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(20, 20, 256, 155));

        retranslateUi(DialogCalendar);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogCalendar, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogCalendar, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogCalendar);
    } // setupUi

    void retranslateUi(QDialog *DialogCalendar)
    {
        DialogCalendar->setWindowTitle(QApplication::translate("DialogCalendar", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogCalendar: public Ui_DialogCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCALENDAR_H
