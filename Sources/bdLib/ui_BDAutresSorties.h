/********************************************************************************
** Form generated from reading UI file 'BDAutresSorties.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDAUTRESSORTIES_H
#define UI_BDAUTRESSORTIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BDAutresSorties
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditDescription;

    void setupUi(QDialog *BDAutresSorties)
    {
        if (BDAutresSorties->objectName().isEmpty())
            BDAutresSorties->setObjectName(QString::fromUtf8("BDAutresSorties"));
        BDAutresSorties->resize(272, 79);
        buttonBox = new QDialogButtonBox(BDAutresSorties);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 40, 201, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(BDAutresSorties);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 251, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditDescription = new QLineEdit(widget);
        lineEditDescription->setObjectName(QString::fromUtf8("lineEditDescription"));

        horizontalLayout->addWidget(lineEditDescription);


        retranslateUi(BDAutresSorties);
        QObject::connect(buttonBox, SIGNAL(accepted()), BDAutresSorties, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BDAutresSorties, SLOT(reject()));

        QMetaObject::connectSlotsByName(BDAutresSorties);
    } // setupUi

    void retranslateUi(QDialog *BDAutresSorties)
    {
        BDAutresSorties->setWindowTitle(QApplication::translate("BDAutresSorties", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDAutresSorties", "Description :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDAutresSorties: public Ui_BDAutresSorties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDAUTRESSORTIES_H
