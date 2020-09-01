/********************************************************************************
** Form generated from reading UI file 'BDSetPeriode.ui'
**
** Created: Sun 27. Oct 20:00:19 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDSETPERIODE_H
#define UI_BDSETPERIODE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_BDSetPeriode
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *dateDebut;
    QToolButton *btn_dateDebut;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *dateFin;
    QToolButton *btn_dateFin;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDSetPeriode)
    {
        if (BDSetPeriode->objectName().isEmpty())
            BDSetPeriode->setObjectName(QString::fromUtf8("BDSetPeriode"));
        BDSetPeriode->resize(260, 99);
        gridLayout = new QGridLayout(BDSetPeriode);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(BDSetPeriode);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        dateDebut = new QLineEdit(BDSetPeriode);
        dateDebut->setObjectName(QString::fromUtf8("dateDebut"));
        dateDebut->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateDebut->setReadOnly(true);

        horizontalLayout_2->addWidget(dateDebut);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        btn_dateDebut = new QToolButton(BDSetPeriode);
        btn_dateDebut->setObjectName(QString::fromUtf8("btn_dateDebut"));

        gridLayout->addWidget(btn_dateDebut, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(BDSetPeriode);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        dateFin = new QLineEdit(BDSetPeriode);
        dateFin->setObjectName(QString::fromUtf8("dateFin"));
        dateFin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateFin->setReadOnly(true);

        horizontalLayout_3->addWidget(dateFin);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        btn_dateFin = new QToolButton(BDSetPeriode);
        btn_dateFin->setObjectName(QString::fromUtf8("btn_dateFin"));

        gridLayout->addWidget(btn_dateFin, 1, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 6, -1);
        btn_ok = new QPushButton(BDSetPeriode);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDSetPeriode);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout->addLayout(formLayout, 2, 0, 1, 2);


        retranslateUi(BDSetPeriode);

        QMetaObject::connectSlotsByName(BDSetPeriode);
    } // setupUi

    void retranslateUi(QDialog *BDSetPeriode)
    {
        BDSetPeriode->setWindowTitle(QApplication::translate("BDSetPeriode", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDSetPeriode", "D\303\251but:", 0, QApplication::UnicodeUTF8));
        btn_dateDebut->setText(QApplication::translate("BDSetPeriode", "...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDSetPeriode", "Fin:", 0, QApplication::UnicodeUTF8));
        btn_dateFin->setText(QApplication::translate("BDSetPeriode", "...", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDSetPeriode", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDSetPeriode", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDSetPeriode: public Ui_BDSetPeriode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDSETPERIODE_H
