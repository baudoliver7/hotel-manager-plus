/********************************************************************************
** Form generated from reading UI file 'BDAjusterHeureSyst.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDAJUSTERHEURESYST_H
#define UI_BDAJUSTERHEURESYST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_BDAjusterHeureSyst
{
public:
    QGridLayout *gridLayout;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTimeEdit *timeEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BDAjusterHeureSyst)
    {
        if (BDAjusterHeureSyst->objectName().isEmpty())
            BDAjusterHeureSyst->setObjectName(QString::fromUtf8("BDAjusterHeureSyst"));
        BDAjusterHeureSyst->resize(283, 251);
        gridLayout = new QGridLayout(BDAjusterHeureSyst);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        calendarWidget = new QCalendarWidget(BDAjusterHeureSyst);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        gridLayout->addWidget(calendarWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(BDAjusterHeureSyst);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        timeEdit = new QTimeEdit(BDAjusterHeureSyst);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        horizontalLayout->addWidget(timeEdit);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(BDAjusterHeureSyst);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(BDAjusterHeureSyst);
        QObject::connect(buttonBox, SIGNAL(accepted()), BDAjusterHeureSyst, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BDAjusterHeureSyst, SLOT(reject()));

        QMetaObject::connectSlotsByName(BDAjusterHeureSyst);
    } // setupUi

    void retranslateUi(QDialog *BDAjusterHeureSyst)
    {
        BDAjusterHeureSyst->setWindowTitle(QApplication::translate("BDAjusterHeureSyst", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDAjusterHeureSyst", "Heure:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDAjusterHeureSyst: public Ui_BDAjusterHeureSyst {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDAJUSTERHEURESYST_H
