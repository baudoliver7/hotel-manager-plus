/********************************************************************************
** Form generated from reading UI file 'BDConfigHeureSortie.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCONFIGHEURESORTIE_H
#define UI_BDCONFIGHEURESORTIE_H

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
#include <QtGui/QSpinBox>
#include <QtGui/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_BDConfigHeureSortie
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QTimeEdit *timeEditSortie;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *spinBoxTpsTol;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpinBox *spinBoxTpsTol_3;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;
    QLabel *label_4;

    void setupUi(QDialog *BDConfigHeureSortie)
    {
        if (BDConfigHeureSortie->objectName().isEmpty())
            BDConfigHeureSortie->setObjectName(QString::fromUtf8("BDConfigHeureSortie"));
        BDConfigHeureSortie->resize(254, 166);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        BDConfigHeureSortie->setWindowIcon(icon);
        gridLayout = new QGridLayout(BDConfigHeureSortie);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(BDConfigHeureSortie);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        timeEditSortie = new QTimeEdit(BDConfigHeureSortie);
        timeEditSortie->setObjectName(QString::fromUtf8("timeEditSortie"));

        horizontalLayout_2->addWidget(timeEditSortie);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(BDConfigHeureSortie);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBoxTpsTol = new QSpinBox(BDConfigHeureSortie);
        spinBoxTpsTol->setObjectName(QString::fromUtf8("spinBoxTpsTol"));
        spinBoxTpsTol->setMinimum(1);
        spinBoxTpsTol->setMaximum(100);
        spinBoxTpsTol->setSingleStep(5);

        horizontalLayout->addWidget(spinBoxTpsTol);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(BDConfigHeureSortie);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        spinBoxTpsTol_3 = new QSpinBox(BDConfigHeureSortie);
        spinBoxTpsTol_3->setObjectName(QString::fromUtf8("spinBoxTpsTol_3"));
        spinBoxTpsTol_3->setMinimum(15);
        spinBoxTpsTol_3->setMaximum(100);
        spinBoxTpsTol_3->setSingleStep(5);

        horizontalLayout_4->addWidget(spinBoxTpsTol_3);


        gridLayout->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        label_3 = new QLabel(BDConfigHeureSortie);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(BDConfigHeureSortie);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        label_4 = new QLabel(BDConfigHeureSortie);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);


        retranslateUi(BDConfigHeureSortie);
        QObject::connect(buttonBox, SIGNAL(accepted()), BDConfigHeureSortie, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BDConfigHeureSortie, SLOT(reject()));

        QMetaObject::connectSlotsByName(BDConfigHeureSortie);
    } // setupUi

    void retranslateUi(QDialog *BDConfigHeureSortie)
    {
        BDConfigHeureSortie->setWindowTitle(QApplication::translate("BDConfigHeureSortie", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDConfigHeureSortie", "Heure de sortie:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDConfigHeureSortie", "Temps de tol\303\251rance:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDConfigHeureSortie", "Temps Location annulation:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDConfigHeureSortie", "minutes", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDConfigHeureSortie", "minutes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDConfigHeureSortie: public Ui_BDConfigHeureSortie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCONFIGHEURESORTIE_H
