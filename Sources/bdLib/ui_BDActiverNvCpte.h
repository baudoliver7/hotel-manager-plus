/********************************************************************************
** Form generated from reading UI file 'BDActiverNvCpte.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDACTIVERNVCPTE_H
#define UI_BDACTIVERNVCPTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_BDActiverNvCpte
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMatricule;
    QLabel *labelValide;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditLogin;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *Password;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditConfirmation;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BDActiverNvCpte)
    {
        if (BDActiverNvCpte->objectName().isEmpty())
            BDActiverNvCpte->setObjectName(QString::fromUtf8("BDActiverNvCpte"));
        BDActiverNvCpte->resize(291, 153);
        gridLayout = new QGridLayout(BDActiverNvCpte);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(BDActiverNvCpte);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditMatricule = new QLineEdit(BDActiverNvCpte);
        lineEditMatricule->setObjectName(QString::fromUtf8("lineEditMatricule"));

        horizontalLayout->addWidget(lineEditMatricule);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        labelValide = new QLabel(BDActiverNvCpte);
        labelValide->setObjectName(QString::fromUtf8("labelValide"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelValide->setFont(font);

        gridLayout->addWidget(labelValide, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(47);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(BDActiverNvCpte);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditLogin = new QLineEdit(BDActiverNvCpte);
        lineEditLogin->setObjectName(QString::fromUtf8("lineEditLogin"));

        horizontalLayout_2->addWidget(lineEditLogin);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(BDActiverNvCpte);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        Password = new QLineEdit(BDActiverNvCpte);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(Password);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(15);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(BDActiverNvCpte);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditConfirmation = new QLineEdit(BDActiverNvCpte);
        lineEditConfirmation->setObjectName(QString::fromUtf8("lineEditConfirmation"));
        lineEditConfirmation->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEditConfirmation);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        buttonBox = new QDialogButtonBox(BDActiverNvCpte);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 1);


        retranslateUi(BDActiverNvCpte);
        QObject::connect(buttonBox, SIGNAL(accepted()), BDActiverNvCpte, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BDActiverNvCpte, SLOT(reject()));

        QMetaObject::connectSlotsByName(BDActiverNvCpte);
    } // setupUi

    void retranslateUi(QDialog *BDActiverNvCpte)
    {
        BDActiverNvCpte->setWindowTitle(QApplication::translate("BDActiverNvCpte", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDActiverNvCpte", "Matricule:", 0, QApplication::UnicodeUTF8));
        labelValide->setText(QApplication::translate("BDActiverNvCpte", "Invalide", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDActiverNvCpte", "Login:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDActiverNvCpte", "Mot de passe: ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDActiverNvCpte", "A nouveau: ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDActiverNvCpte: public Ui_BDActiverNvCpte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDACTIVERNVCPTE_H
