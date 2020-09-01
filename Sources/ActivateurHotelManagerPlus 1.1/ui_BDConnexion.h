/********************************************************************************
** Form generated from reading UI file 'BDConnexion.ui'
**
** Created: Sat 24. Mar 10:43:34 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCONNEXION_H
#define UI_BDCONNEXION_H

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

QT_BEGIN_NAMESPACE

class Ui_BDConnexion
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditLogin;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditPassword;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDConnexion)
    {
        if (BDConnexion->objectName().isEmpty())
            BDConnexion->setObjectName(QString::fromUtf8("BDConnexion"));
        BDConnexion->resize(268, 99);
        BDConnexion->setMinimumSize(QSize(268, 99));
        BDConnexion->setMaximumSize(QSize(268, 99));
        gridLayout = new QGridLayout(BDConnexion);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(26);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(BDConnexion);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditLogin = new QLineEdit(BDConnexion);
        lineEditLogin->setObjectName(QString::fromUtf8("lineEditLogin"));

        horizontalLayout->addWidget(lineEditLogin);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(BDConnexion);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditPassword = new QLineEdit(BDConnexion);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEditPassword);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_ok = new QPushButton(BDConnexion);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDConnexion);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout, 2, 0, 1, 1);


        retranslateUi(BDConnexion);

        QMetaObject::connectSlotsByName(BDConnexion);
    } // setupUi

    void retranslateUi(QDialog *BDConnexion)
    {
        BDConnexion->setWindowTitle(QApplication::translate("BDConnexion", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDConnexion", "Login :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDConnexion", "Password :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDConnexion", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDConnexion", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDConnexion: public Ui_BDConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCONNEXION_H
