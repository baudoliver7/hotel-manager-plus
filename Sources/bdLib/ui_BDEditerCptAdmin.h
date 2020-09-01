/********************************************************************************
** Form generated from reading UI file 'BDEditerCptAdmin.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDEDITERCPTADMIN_H
#define UI_BDEDITERCPTADMIN_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSplitter>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BDEditerCptAdmin
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditNom;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditPrenom;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditResidence;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEditContact;
    QToolButton *btn_contact;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QRadioButton *Monsieur;
    QRadioButton *Madame;
    QRadioButton *Demoiselle;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEditPseudo;
    QSplitter *splitter;
    QLabel *label_9;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEditPassword;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEditConfirmation;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BDEditerCptAdmin)
    {
        if (BDEditerCptAdmin->objectName().isEmpty())
            BDEditerCptAdmin->setObjectName(QString::fromUtf8("BDEditerCptAdmin"));
        BDEditerCptAdmin->resize(305, 280);
        gridLayout = new QGridLayout(BDEditerCptAdmin);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(43);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(BDEditerCptAdmin);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lineEditNom = new QLineEdit(BDEditerCptAdmin);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));

        horizontalLayout_3->addWidget(lineEditNom);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(24);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(BDEditerCptAdmin);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditPrenom = new QLineEdit(BDEditerCptAdmin);
        lineEditPrenom->setObjectName(QString::fromUtf8("lineEditPrenom"));

        horizontalLayout_2->addWidget(lineEditPrenom);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(18);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(BDEditerCptAdmin);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditResidence = new QLineEdit(BDEditerCptAdmin);
        lineEditResidence->setObjectName(QString::fromUtf8("lineEditResidence"));

        horizontalLayout_4->addWidget(lineEditResidence);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(29);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(BDEditerCptAdmin);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEditContact = new QLineEdit(BDEditerCptAdmin);
        lineEditContact->setObjectName(QString::fromUtf8("lineEditContact"));
        lineEditContact->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditContact->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEditContact);


        gridLayout->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        btn_contact = new QToolButton(BDEditerCptAdmin);
        btn_contact->setObjectName(QString::fromUtf8("btn_contact"));

        gridLayout->addWidget(btn_contact, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(BDEditerCptAdmin);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        Monsieur = new QRadioButton(BDEditerCptAdmin);
        Monsieur->setObjectName(QString::fromUtf8("Monsieur"));

        horizontalLayout->addWidget(Monsieur);

        Madame = new QRadioButton(BDEditerCptAdmin);
        Madame->setObjectName(QString::fromUtf8("Madame"));

        horizontalLayout->addWidget(Madame);

        Demoiselle = new QRadioButton(BDEditerCptAdmin);
        Demoiselle->setObjectName(QString::fromUtf8("Demoiselle"));

        horizontalLayout->addWidget(Demoiselle);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(34);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(BDEditerCptAdmin);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEditPseudo = new QLineEdit(BDEditerCptAdmin);
        lineEditPseudo->setObjectName(QString::fromUtf8("lineEditPseudo"));

        horizontalLayout_6->addWidget(lineEditPseudo);


        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        splitter = new QSplitter(BDEditerCptAdmin);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        label_9 = new QLabel(splitter);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter->addWidget(label_9);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_7->addWidget(lineEditPassword);

        splitter->addWidget(layoutWidget);

        gridLayout->addWidget(splitter, 6, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(BDEditerCptAdmin);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEditConfirmation = new QLineEdit(BDEditerCptAdmin);
        lineEditConfirmation->setObjectName(QString::fromUtf8("lineEditConfirmation"));
        lineEditConfirmation->setEchoMode(QLineEdit::Password);

        horizontalLayout_8->addWidget(lineEditConfirmation);


        gridLayout->addLayout(horizontalLayout_8, 7, 0, 1, 1);

        buttonBox = new QDialogButtonBox(BDEditerCptAdmin);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 0, 1, 1);


        retranslateUi(BDEditerCptAdmin);
        QObject::connect(buttonBox, SIGNAL(accepted()), BDEditerCptAdmin, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BDEditerCptAdmin, SLOT(reject()));

        QMetaObject::connectSlotsByName(BDEditerCptAdmin);
    } // setupUi

    void retranslateUi(QDialog *BDEditerCptAdmin)
    {
        BDEditerCptAdmin->setWindowTitle(QApplication::translate("BDEditerCptAdmin", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDEditerCptAdmin", "Nom:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDEditerCptAdmin", "Pr\303\251noms:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDEditerCptAdmin", "R\303\251sidence:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDEditerCptAdmin", "Contact:", 0, QApplication::UnicodeUTF8));
        btn_contact->setText(QApplication::translate("BDEditerCptAdmin", "...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDEditerCptAdmin", "Sexe pr\303\251cis:", 0, QApplication::UnicodeUTF8));
        Monsieur->setText(QApplication::translate("BDEditerCptAdmin", "M.", 0, QApplication::UnicodeUTF8));
        Madame->setText(QApplication::translate("BDEditerCptAdmin", "Mme", 0, QApplication::UnicodeUTF8));
        Demoiselle->setText(QApplication::translate("BDEditerCptAdmin", "Mlle", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDEditerCptAdmin", "Pseudo:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BDEditerCptAdmin", "six (6) caract\303\250res au minimum", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BDEditerCptAdmin", "Mot de passe:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BDEditerCptAdmin", "Confirmation :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDEditerCptAdmin: public Ui_BDEditerCptAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDEDITERCPTADMIN_H
