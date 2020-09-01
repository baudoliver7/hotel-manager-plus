/********************************************************************************
** Form generated from reading UI file 'BDAjouterUneChambre.ui'
**
** Created: Mon 20. Jun 16:30:34 2011
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
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BDAjouterUneChambre
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QPushButton *btn_nouveauInitial;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBoxInitial;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBoxNumero;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBoxTypeDeCh;

    void setupUi(QDialog *BDAjouterUneChambre)
    {
        if (BDAjouterUneChambre->objectName().isEmpty())
            BDAjouterUneChambre->setObjectName(QString::fromUtf8("BDAjouterUneChambre"));
        BDAjouterUneChambre->resize(242, 212);
        buttonBox = new QDialogButtonBox(BDAjouterUneChambre);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 170, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(BDAjouterUneChambre);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 221, 121));
        btn_nouveauInitial = new QPushButton(groupBox);
        btn_nouveauInitial->setObjectName(QString::fromUtf8("btn_nouveauInitial"));
        btn_nouveauInitial->setGeometry(QRect(114, 90, 101, 23));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 30, 141, 52));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBoxInitial = new QComboBox(widget);
        comboBoxInitial->setObjectName(QString::fromUtf8("comboBoxInitial"));

        horizontalLayout_2->addWidget(comboBoxInitial);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBoxNumero = new QSpinBox(widget);
        spinBoxNumero->setObjectName(QString::fromUtf8("spinBoxNumero"));
        spinBoxNumero->setMaximum(1000);

        horizontalLayout_3->addWidget(spinBoxNumero);


        verticalLayout->addLayout(horizontalLayout_3);

        widget1 = new QWidget(BDAjouterUneChambre);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 20, 215, 22));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBoxTypeDeCh = new QComboBox(widget1);
        comboBoxTypeDeCh->setObjectName(QString::fromUtf8("comboBoxTypeDeCh"));

        horizontalLayout->addWidget(comboBoxTypeDeCh);


        retranslateUi(BDAjouterUneChambre);
        QObject::connect(buttonBox, SIGNAL(accepted()), BDAjouterUneChambre, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BDAjouterUneChambre, SLOT(reject()));

        QMetaObject::connectSlotsByName(BDAjouterUneChambre);
    } // setupUi

    void retranslateUi(QDialog *BDAjouterUneChambre)
    {
        BDAjouterUneChambre->setWindowTitle(QApplication::translate("BDAjouterUneChambre", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDAjouterUneChambre", "Identifiant", 0, QApplication::UnicodeUTF8));
        btn_nouveauInitial->setText(QApplication::translate("BDAjouterUneChambre", "Nouveau initial", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDAjouterUneChambre", "Initial :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDAjouterUneChambre", "Numero :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDAjouterUneChambre", "Type de chambre :", 0, QApplication::UnicodeUTF8));
        comboBoxTypeDeCh->clear();
        comboBoxTypeDeCh->insertItems(0, QStringList()
         << QApplication::translate("BDAjouterUneChambre", "Chambre ventil\303\251e", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDAjouterUneChambre", "Chambre climatis\303\251e", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDAjouterUneChambre", "Suite", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class BDAjouterUneChambre: public Ui_BDAjouterUneChambre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDAJOUTERUNECHAMBRE_H
