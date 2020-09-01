/********************************************************************************
** Form generated from reading UI file 'BDModifierUneChambre.ui'
**
** Created: Mon 20. Jun 16:30:34 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDMODIFIERUNECHAMBRE_H
#define UI_BDMODIFIERUNECHAMBRE_H

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

class Ui_BDModifierUneChambre
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBoxTypeDeCh;
    QGroupBox *groupBox;
    QPushButton *btn_nouveauInitial;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBoxInitial;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBoxNumero;

    void setupUi(QDialog *BDModifierUneChambre)
    {
        if (BDModifierUneChambre->objectName().isEmpty())
            BDModifierUneChambre->setObjectName(QString::fromUtf8("BDModifierUneChambre"));
        BDModifierUneChambre->resize(242, 212);
        buttonBox = new QDialogButtonBox(BDModifierUneChambre);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 180, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(BDModifierUneChambre);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 215, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBoxTypeDeCh = new QComboBox(layoutWidget);
        comboBoxTypeDeCh->setObjectName(QString::fromUtf8("comboBoxTypeDeCh"));

        horizontalLayout->addWidget(comboBoxTypeDeCh);

        groupBox = new QGroupBox(BDModifierUneChambre);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 221, 121));
        btn_nouveauInitial = new QPushButton(groupBox);
        btn_nouveauInitial->setObjectName(QString::fromUtf8("btn_nouveauInitial"));
        btn_nouveauInitial->setGeometry(QRect(114, 90, 101, 23));
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(40, 30, 141, 52));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBoxInitial = new QComboBox(layoutWidget_2);
        comboBoxInitial->setObjectName(QString::fromUtf8("comboBoxInitial"));

        horizontalLayout_2->addWidget(comboBoxInitial);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBoxNumero = new QSpinBox(layoutWidget_2);
        spinBoxNumero->setObjectName(QString::fromUtf8("spinBoxNumero"));
        spinBoxNumero->setMaximum(1000);

        horizontalLayout_3->addWidget(spinBoxNumero);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(BDModifierUneChambre);
        QObject::connect(buttonBox, SIGNAL(accepted()), BDModifierUneChambre, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BDModifierUneChambre, SLOT(reject()));

        QMetaObject::connectSlotsByName(BDModifierUneChambre);
    } // setupUi

    void retranslateUi(QDialog *BDModifierUneChambre)
    {
        BDModifierUneChambre->setWindowTitle(QApplication::translate("BDModifierUneChambre", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDModifierUneChambre", "Type de chambre :", 0, QApplication::UnicodeUTF8));
        comboBoxTypeDeCh->clear();
        comboBoxTypeDeCh->insertItems(0, QStringList()
         << QApplication::translate("BDModifierUneChambre", "Chambre ventil\303\251e", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDModifierUneChambre", "Chambre climatis\303\251e", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BDModifierUneChambre", "Suite", 0, QApplication::UnicodeUTF8)
        );
        groupBox->setTitle(QApplication::translate("BDModifierUneChambre", "Identifiant", 0, QApplication::UnicodeUTF8));
        btn_nouveauInitial->setText(QApplication::translate("BDModifierUneChambre", "Nouveau initial", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDModifierUneChambre", "Initial :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDModifierUneChambre", "Numero :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDModifierUneChambre: public Ui_BDModifierUneChambre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDMODIFIERUNECHAMBRE_H
