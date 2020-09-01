/********************************************************************************
** Form generated from reading UI file 'BDStatutProduit.ui'
**
** Created: Sat 28. Jan 18:36:53 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDSTATUTPRODUIT_H
#define UI_BDSTATUTPRODUIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
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

class Ui_BDStatutProduit
{
public:
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *comboBoxNomProduit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *labelReponse;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditIID;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditKey;
    QFormLayout *formLayout;
    QPushButton *btn_supprimer;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDStatutProduit)
    {
        if (BDStatutProduit->objectName().isEmpty())
            BDStatutProduit->setObjectName(QString::fromUtf8("BDStatutProduit"));
        BDStatutProduit->resize(297, 155);
        BDStatutProduit->setMinimumSize(QSize(297, 155));
        BDStatutProduit->setMaximumSize(QSize(297, 155));
        gridLayout = new QGridLayout(BDStatutProduit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(BDStatutProduit);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        comboBoxNomProduit = new QComboBox(BDStatutProduit);
        comboBoxNomProduit->setObjectName(QString::fromUtf8("comboBoxNomProduit"));
        comboBoxNomProduit->setMaximumSize(QSize(190, 20));

        gridLayout->addWidget(comboBoxNomProduit, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(BDStatutProduit);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        labelReponse = new QLabel(BDStatutProduit);
        labelReponse->setObjectName(QString::fromUtf8("labelReponse"));

        horizontalLayout_2->addWidget(labelReponse);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(BDStatutProduit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditIID = new QLineEdit(BDStatutProduit);
        lineEditIID->setObjectName(QString::fromUtf8("lineEditIID"));
        lineEditIID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditIID->setReadOnly(true);

        horizontalLayout->addWidget(lineEditIID);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(57);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(BDStatutProduit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditKey = new QLineEdit(BDStatutProduit);
        lineEditKey->setObjectName(QString::fromUtf8("lineEditKey"));
        lineEditKey->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditKey->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditKey);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_supprimer = new QPushButton(BDStatutProduit);
        btn_supprimer->setObjectName(QString::fromUtf8("btn_supprimer"));
        btn_supprimer->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_supprimer);

        btn_fermer = new QPushButton(BDStatutProduit);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_fermer);


        gridLayout->addLayout(formLayout, 3, 1, 1, 1);


        retranslateUi(BDStatutProduit);

        QMetaObject::connectSlotsByName(BDStatutProduit);
    } // setupUi

    void retranslateUi(QDialog *BDStatutProduit)
    {
        BDStatutProduit->setWindowTitle(QApplication::translate("BDStatutProduit", "Dialog", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDStatutProduit", "Nom du produit: ", 0, QApplication::UnicodeUTF8));
        comboBoxNomProduit->clear();
        comboBoxNomProduit->insertItems(0, QStringList()
         << QApplication::translate("BDStatutProduit", "Hotel Manager Administration Plus", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDStatutProduit", "Hotel Manager Comptabilit\303\251 Plus", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDStatutProduit", "Hotel Manager R\303\251ception Plus", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("BDStatutProduit", "Produit install\303\251 :", 0, QApplication::UnicodeUTF8));
        labelReponse->setText(QApplication::translate("BDStatutProduit", "Oui", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDStatutProduit", "Installation ID :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDStatutProduit", "Cl\303\251 :", 0, QApplication::UnicodeUTF8));
        btn_supprimer->setText(QApplication::translate("BDStatutProduit", "Supprimer", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDStatutProduit", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDStatutProduit: public Ui_BDStatutProduit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDSTATUTPRODUIT_H
