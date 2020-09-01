/********************************************************************************
** Form generated from reading UI file 'DialogContact.ui'
**
** Created: Sat 17. Dec 22:00:19 2011
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
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogContact
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditCel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditTel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditEmail;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditBP;
    QFormLayout *formLayout;
    QPushButton *btn_OK;
    QPushButton *btn_Annuler;

    void setupUi(QDialog *DialogContact)
    {
        if (DialogContact->objectName().isEmpty())
            DialogContact->setObjectName(QString::fromUtf8("DialogContact"));
        DialogContact->resize(273, 157);
        gridLayout = new QGridLayout(DialogContact);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DialogContact);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditCel = new QLineEdit(DialogContact);
        lineEditCel->setObjectName(QString::fromUtf8("lineEditCel"));

        horizontalLayout->addWidget(lineEditCel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(35);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DialogContact);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditTel = new QLineEdit(DialogContact);
        lineEditTel->setObjectName(QString::fromUtf8("lineEditTel"));

        horizontalLayout_2->addWidget(lineEditTel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(DialogContact);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditEmail = new QLineEdit(DialogContact);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));

        horizontalLayout_3->addWidget(lineEditEmail);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(DialogContact);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditBP = new QLineEdit(DialogContact);
        lineEditBP->setObjectName(QString::fromUtf8("lineEditBP"));

        horizontalLayout_4->addWidget(lineEditBP);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_OK = new QPushButton(DialogContact);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));
        btn_OK->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_OK);

        btn_Annuler = new QPushButton(DialogContact);
        btn_Annuler->setObjectName(QString::fromUtf8("btn_Annuler"));
        btn_Annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_Annuler);


        gridLayout->addLayout(formLayout, 1, 0, 1, 1);


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
        btn_OK->setText(QApplication::translate("DialogContact", "OK", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("DialogContact", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogContact: public Ui_DialogContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONTACT_H
