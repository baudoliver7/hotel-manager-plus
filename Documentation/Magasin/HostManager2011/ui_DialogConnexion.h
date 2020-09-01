/********************************************************************************
** Form generated from reading UI file 'DialogConnexion.ui'
**
** Created: Tue 27. Sep 18:24:16 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONNEXION_H
#define UI_DIALOGCONNEXION_H

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

class Ui_DialogConnexion
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditLogin;
    QLabel *label_2;
    QLineEdit *lineEditPassword;
    QPushButton *btn_passer;
    QSplitter *splitter;
    QPushButton *btn_Annuler;
    QPushButton *btn_OK;

    void setupUi(QDialog *DialogConnexion)
    {
        if (DialogConnexion->objectName().isEmpty())
            DialogConnexion->setObjectName(QString::fromUtf8("DialogConnexion"));
        DialogConnexion->resize(289, 105);
        DialogConnexion->setMinimumSize(QSize(289, 105));
        DialogConnexion->setMaximumSize(QSize(289, 105));
        gridLayout = new QGridLayout(DialogConnexion);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DialogConnexion);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditLogin = new QLineEdit(DialogConnexion);
        lineEditLogin->setObjectName(QString::fromUtf8("lineEditLogin"));

        gridLayout->addWidget(lineEditLogin, 0, 1, 1, 1);

        label_2 = new QLabel(DialogConnexion);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditPassword = new QLineEdit(DialogConnexion);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditPassword, 1, 1, 1, 1);

        btn_passer = new QPushButton(DialogConnexion);
        btn_passer->setObjectName(QString::fromUtf8("btn_passer"));

        gridLayout->addWidget(btn_passer, 2, 0, 1, 1);

        splitter = new QSplitter(DialogConnexion);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setLayoutDirection(Qt::RightToLeft);
        splitter->setOrientation(Qt::Horizontal);
        btn_Annuler = new QPushButton(splitter);
        btn_Annuler->setObjectName(QString::fromUtf8("btn_Annuler"));
        btn_Annuler->setMinimumSize(QSize(75, 0));
        btn_Annuler->setMaximumSize(QSize(75, 16777215));
        splitter->addWidget(btn_Annuler);
        btn_OK = new QPushButton(splitter);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));
        btn_OK->setMinimumSize(QSize(75, 0));
        btn_OK->setMaximumSize(QSize(75, 16777215));
        splitter->addWidget(btn_OK);

        gridLayout->addWidget(splitter, 2, 1, 1, 1);


        retranslateUi(DialogConnexion);

        QMetaObject::connectSlotsByName(DialogConnexion);
    } // setupUi

    void retranslateUi(QDialog *DialogConnexion)
    {
        DialogConnexion->setWindowTitle(QApplication::translate("DialogConnexion", "Connexion au service R\303\251ception", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogConnexion", "Pseudo:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogConnexion", "Mot de passe:", 0, QApplication::UnicodeUTF8));
        btn_passer->setText(QApplication::translate("DialogConnexion", "Passer", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("DialogConnexion", "Annuler", 0, QApplication::UnicodeUTF8));
        btn_OK->setText(QApplication::translate("DialogConnexion", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogConnexion: public Ui_DialogConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONNEXION_H
