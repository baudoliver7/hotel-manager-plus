/********************************************************************************
** Form generated from reading UI file 'BDInfosConnection.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDINFOSCONNECTION_H
#define UI_BDINFOSCONNECTION_H

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

class Ui_BDInfosConnection
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEditNomBD;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditServeur;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditUser;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditPassword;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEditPort;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BDInfosConnection)
    {
        if (BDInfosConnection->objectName().isEmpty())
            BDInfosConnection->setObjectName(QString::fromUtf8("BDInfosConnection"));
        BDInfosConnection->resize(222, 190);
        gridLayout = new QGridLayout(BDInfosConnection);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(20);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(BDInfosConnection);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEditNomBD = new QLineEdit(BDInfosConnection);
        lineEditNomBD->setObjectName(QString::fromUtf8("lineEditNomBD"));

        horizontalLayout_6->addWidget(lineEditNomBD);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(31);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(BDInfosConnection);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditServeur = new QLineEdit(BDInfosConnection);
        lineEditServeur->setObjectName(QString::fromUtf8("lineEditServeur"));

        horizontalLayout_2->addWidget(lineEditServeur);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(21);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(BDInfosConnection);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditUser = new QLineEdit(BDInfosConnection);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));

        horizontalLayout_3->addWidget(lineEditUser);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(BDInfosConnection);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditPassword = new QLineEdit(BDInfosConnection);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEditPassword);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(49);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(BDInfosConnection);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEditPort = new QLineEdit(BDInfosConnection);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        horizontalLayout_5->addWidget(lineEditPort);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        buttonBox = new QDialogButtonBox(BDInfosConnection);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 1);


        retranslateUi(BDInfosConnection);
        QObject::connect(buttonBox, SIGNAL(accepted()), BDInfosConnection, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BDInfosConnection, SLOT(reject()));

        QMetaObject::connectSlotsByName(BDInfosConnection);
    } // setupUi

    void retranslateUi(QDialog *BDInfosConnection)
    {
        BDInfosConnection->setWindowTitle(QApplication::translate("BDInfosConnection", "Dialog", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDInfosConnection", "Nom de BD", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDInfosConnection", "Serveur:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDInfosConnection", "Utilisateur:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDInfosConnection", "Mot de passe:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDInfosConnection", "Port:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDInfosConnection: public Ui_BDInfosConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDINFOSCONNECTION_H
