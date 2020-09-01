/********************************************************************************
** Form generated from reading UI file 'BDModifierUneChambre.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
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
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDModifierUneChambre
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBoxInitial;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBoxNumero;
    QPushButton *btn_nouveauInitial;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BDModifierUneChambre)
    {
        if (BDModifierUneChambre->objectName().isEmpty())
            BDModifierUneChambre->setObjectName(QString::fromUtf8("BDModifierUneChambre"));
        BDModifierUneChambre->resize(215, 193);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        BDModifierUneChambre->setWindowIcon(icon);
        gridLayout = new QGridLayout(BDModifierUneChambre);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(BDModifierUneChambre);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBoxInitial = new QComboBox(groupBox);
        comboBoxInitial->setObjectName(QString::fromUtf8("comboBoxInitial"));

        horizontalLayout_2->addWidget(comboBoxInitial);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBoxNumero = new QSpinBox(groupBox);
        spinBoxNumero->setObjectName(QString::fromUtf8("spinBoxNumero"));
        spinBoxNumero->setMinimum(1);
        spinBoxNumero->setMaximum(1000);

        horizontalLayout_3->addWidget(spinBoxNumero);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        btn_nouveauInitial = new QPushButton(groupBox);
        btn_nouveauInitial->setObjectName(QString::fromUtf8("btn_nouveauInitial"));
        btn_nouveauInitial->setMaximumSize(QSize(90, 23));
        btn_nouveauInitial->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_2->addWidget(btn_nouveauInitial);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(BDModifierUneChambre);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(BDModifierUneChambre);
        QObject::connect(buttonBox, SIGNAL(accepted()), BDModifierUneChambre, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BDModifierUneChambre, SLOT(reject()));

        QMetaObject::connectSlotsByName(BDModifierUneChambre);
    } // setupUi

    void retranslateUi(QDialog *BDModifierUneChambre)
    {
        BDModifierUneChambre->setWindowTitle(QApplication::translate("BDModifierUneChambre", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDModifierUneChambre", "Identifiant", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDModifierUneChambre", "Initial :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDModifierUneChambre", "Numero :", 0, QApplication::UnicodeUTF8));
        btn_nouveauInitial->setText(QApplication::translate("BDModifierUneChambre", "Nouveau initial", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDModifierUneChambre: public Ui_BDModifierUneChambre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDMODIFIERUNECHAMBRE_H
