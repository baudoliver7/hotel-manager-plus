/********************************************************************************
** Form generated from reading UI file 'BDAjouterUneChambre.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDAJOUTERUNECHAMBRE_H
#define UI_BDAJOUTERUNECHAMBRE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BDAjouterUneChambre
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditIdentifiant;
    QLabel *label_2;
    QComboBox *comboBoxNiveau;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDAjouterUneChambre)
    {
        if (BDAjouterUneChambre->objectName().isEmpty())
            BDAjouterUneChambre->setObjectName(QString::fromUtf8("BDAjouterUneChambre"));
        BDAjouterUneChambre->resize(231, 95);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        BDAjouterUneChambre->setWindowIcon(icon);
        gridLayout = new QGridLayout(BDAjouterUneChambre);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(BDAjouterUneChambre);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        lineEditIdentifiant = new QLineEdit(BDAjouterUneChambre);
        lineEditIdentifiant->setObjectName(QString::fromUtf8("lineEditIdentifiant"));

        gridLayout->addWidget(lineEditIdentifiant, 0, 2, 1, 1);

        label_2 = new QLabel(BDAjouterUneChambre);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBoxNiveau = new QComboBox(BDAjouterUneChambre);
        comboBoxNiveau->setObjectName(QString::fromUtf8("comboBoxNiveau"));

        gridLayout->addWidget(comboBoxNiveau, 1, 2, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_ok = new QPushButton(BDAjouterUneChambre);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDAjouterUneChambre);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout, 2, 1, 1, 2);


        retranslateUi(BDAjouterUneChambre);

        QMetaObject::connectSlotsByName(BDAjouterUneChambre);
    } // setupUi

    void retranslateUi(QDialog *BDAjouterUneChambre)
    {
        BDAjouterUneChambre->setWindowTitle(QApplication::translate("BDAjouterUneChambre", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDAjouterUneChambre", "Identifiant :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDAjouterUneChambre", "Niveau :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDAjouterUneChambre", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDAjouterUneChambre", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDAjouterUneChambre: public Ui_BDAjouterUneChambre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDAJOUTERUNECHAMBRE_H
