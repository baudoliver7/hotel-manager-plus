/********************************************************************************
** Form generated from reading UI file 'DialogContact.ui'
**
** Created: Sat 24. Mar 10:43:34 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONTACT_H
#define UI_DIALOGCONTACT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_DialogContact
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditCel;
    QLabel *label_2;
    QLineEdit *lineEditTel;
    QLabel *label_3;
    QLineEdit *lineEditEmail;
    QLabel *label_4;
    QLineEdit *lineEditBP;
    QSplitter *splitter;
    QPushButton *btn_Annuler;
    QPushButton *btn_OK;

    void setupUi(QDialog *DialogContact)
    {
        if (DialogContact->objectName().isEmpty())
            DialogContact->setObjectName(QString::fromUtf8("DialogContact"));
        DialogContact->resize(226, 184);
        gridLayout = new QGridLayout(DialogContact);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DialogContact);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditCel = new QLineEdit(DialogContact);
        lineEditCel->setObjectName(QString::fromUtf8("lineEditCel"));

        gridLayout->addWidget(lineEditCel, 0, 2, 1, 1);

        label_2 = new QLabel(DialogContact);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditTel = new QLineEdit(DialogContact);
        lineEditTel->setObjectName(QString::fromUtf8("lineEditTel"));

        gridLayout->addWidget(lineEditTel, 1, 2, 1, 1);

        label_3 = new QLabel(DialogContact);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEditEmail = new QLineEdit(DialogContact);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));

        gridLayout->addWidget(lineEditEmail, 2, 2, 1, 1);

        label_4 = new QLabel(DialogContact);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 2);

        lineEditBP = new QLineEdit(DialogContact);
        lineEditBP->setObjectName(QString::fromUtf8("lineEditBP"));

        gridLayout->addWidget(lineEditBP, 3, 2, 1, 1);

        splitter = new QSplitter(DialogContact);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setLayoutDirection(Qt::RightToLeft);
        splitter->setOrientation(Qt::Horizontal);
        btn_Annuler = new QPushButton(splitter);
        btn_Annuler->setObjectName(QString::fromUtf8("btn_Annuler"));
        btn_Annuler->setMaximumSize(QSize(75, 23));
        splitter->addWidget(btn_Annuler);
        btn_OK = new QPushButton(splitter);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));
        btn_OK->setMaximumSize(QSize(75, 23));
        splitter->addWidget(btn_OK);

        gridLayout->addWidget(splitter, 4, 1, 1, 2);


        retranslateUi(DialogContact);

        QMetaObject::connectSlotsByName(DialogContact);
    } // setupUi

    void retranslateUi(QDialog *DialogContact)
    {
        DialogContact->setWindowTitle(QApplication::translate("DialogContact", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogContact", "Cellulaire:", 0, QApplication::UnicodeUTF8));
        lineEditCel->setInputMask(QApplication::translate("DialogContact", "00-00-00-00 / 00-00-00-00; ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogContact", "Tel:", 0, QApplication::UnicodeUTF8));
        lineEditTel->setInputMask(QApplication::translate("DialogContact", "00-00-00-00; ", 0, QApplication::UnicodeUTF8));
        lineEditTel->setText(QApplication::translate("DialogContact", "---", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogContact", "E-mail:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogContact", "Bo\303\256te postale:", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("DialogContact", "Annuler", 0, QApplication::UnicodeUTF8));
        btn_OK->setText(QApplication::translate("DialogContact", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogContact: public Ui_DialogContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONTACT_H
