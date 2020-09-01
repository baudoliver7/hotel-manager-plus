/********************************************************************************
** Form generated from reading UI file 'BDNomDuServeur.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDNOMDUSERVEUR_H
#define UI_BDNOMDUSERVEUR_H

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

class Ui_BDNomDuServeur
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditNomDuServeur;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BDNomDuServeur)
    {
        if (BDNomDuServeur->objectName().isEmpty())
            BDNomDuServeur->setObjectName(QString::fromUtf8("BDNomDuServeur"));
        BDNomDuServeur->resize(261, 99);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        BDNomDuServeur->setWindowIcon(icon);
        gridLayout = new QGridLayout(BDNomDuServeur);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(BDNomDuServeur);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditNomDuServeur = new QLineEdit(BDNomDuServeur);
        lineEditNomDuServeur->setObjectName(QString::fromUtf8("lineEditNomDuServeur"));

        horizontalLayout->addWidget(lineEditNomDuServeur);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        label_2 = new QLabel(BDNomDuServeur);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(BDNomDuServeur);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(BDNomDuServeur);
        QObject::connect(buttonBox, SIGNAL(rejected()), BDNomDuServeur, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), BDNomDuServeur, SLOT(accept()));

        QMetaObject::connectSlotsByName(BDNomDuServeur);
    } // setupUi

    void retranslateUi(QDialog *BDNomDuServeur)
    {
        BDNomDuServeur->setWindowTitle(QApplication::translate("BDNomDuServeur", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDNomDuServeur", "Nom du serveur:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDNomDuServeur", "Par exemple \"monServeur\"", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDNomDuServeur: public Ui_BDNomDuServeur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDNOMDUSERVEUR_H
