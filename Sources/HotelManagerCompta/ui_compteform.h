/********************************************************************************
** Form generated from reading UI file 'compteform.ui'
**
** Created: Fri 25. Jan 23:18:57 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPTEFORM_H
#define UI_COMPTEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompteForm
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *rb_periode1;
    QRadioButton *rb_periode2;
    QFormLayout *formLayout;
    QLineEdit *lineEditDebut;
    QToolButton *btn_debut;
    QLabel *label_8;
    QFormLayout *formLayout_2;
    QLineEdit *lineEditFin;
    QToolButton *btn_fin;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QTableView *tableView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditCredit;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditDebit;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEditSolde;
    QPushButton *btn_afficherOp;

    void setupUi(QWidget *CompteForm)
    {
        if (CompteForm->objectName().isEmpty())
            CompteForm->setObjectName(QString::fromUtf8("CompteForm"));
        CompteForm->resize(824, 447);
        gridLayout_3 = new QGridLayout(CompteForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(CompteForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(550, 55));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rb_periode1 = new QRadioButton(groupBox_2);
        rb_periode1->setObjectName(QString::fromUtf8("rb_periode1"));

        gridLayout_2->addWidget(rb_periode1, 0, 0, 1, 1);

        rb_periode2 = new QRadioButton(groupBox_2);
        rb_periode2->setObjectName(QString::fromUtf8("rb_periode2"));

        gridLayout_2->addWidget(rb_periode2, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lineEditDebut = new QLineEdit(groupBox_2);
        lineEditDebut->setObjectName(QString::fromUtf8("lineEditDebut"));
        lineEditDebut->setMaximumSize(QSize(130, 16777215));
        lineEditDebut->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDebut->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, lineEditDebut);

        btn_debut = new QToolButton(groupBox_2);
        btn_debut->setObjectName(QString::fromUtf8("btn_debut"));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_debut);


        gridLayout_2->addLayout(formLayout, 0, 2, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 0, 3, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        lineEditFin = new QLineEdit(groupBox_2);
        lineEditFin->setObjectName(QString::fromUtf8("lineEditFin"));
        lineEditFin->setMaximumSize(QSize(130, 16777215));
        lineEditFin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFin->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lineEditFin);

        btn_fin = new QToolButton(groupBox_2);
        btn_fin->setObjectName(QString::fromUtf8("btn_fin"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_fin);


        gridLayout_2->addLayout(formLayout_2, 0, 4, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(CompteForm);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tableView = new QTableView(groupBox_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setDefaultSectionSize(170);
        tableView->horizontalHeader()->setMinimumSectionSize(170);

        gridLayout_4->addWidget(tableView, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 1, 0, 1, 2);

        groupBox = new QGroupBox(CompteForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 57));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditCredit = new QLineEdit(groupBox);
        lineEditCredit->setObjectName(QString::fromUtf8("lineEditCredit"));
        lineEditCredit->setMaximumSize(QSize(133, 16777215));
        lineEditCredit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditCredit->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditCredit);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditDebit = new QLineEdit(groupBox);
        lineEditDebit->setObjectName(QString::fromUtf8("lineEditDebit"));
        lineEditDebit->setMaximumSize(QSize(133, 16777215));
        lineEditDebit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDebit->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEditDebit);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEditSolde = new QLineEdit(groupBox);
        lineEditSolde->setObjectName(QString::fromUtf8("lineEditSolde"));
        lineEditSolde->setMaximumSize(QSize(133, 16777215));
        lineEditSolde->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditSolde->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEditSolde);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 2, 0, 1, 1);

        btn_afficherOp = new QPushButton(CompteForm);
        btn_afficherOp->setObjectName(QString::fromUtf8("btn_afficherOp"));
        btn_afficherOp->setMaximumSize(QSize(145, 16777215));

        gridLayout_3->addWidget(btn_afficherOp, 0, 1, 1, 1);


        retranslateUi(CompteForm);

        QMetaObject::connectSlotsByName(CompteForm);
    } // setupUi

    void retranslateUi(QWidget *CompteForm)
    {
        CompteForm->setWindowTitle(QApplication::translate("CompteForm", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CompteForm", "P\303\251riode s\303\251lectionn\303\251e", 0, QApplication::UnicodeUTF8));
        rb_periode1->setText(QApplication::translate("CompteForm", "Annuelle", 0, QApplication::UnicodeUTF8));
        rb_periode2->setText(QApplication::translate("CompteForm", "La p\303\251riode allant de", 0, QApplication::UnicodeUTF8));
        btn_debut->setText(QApplication::translate("CompteForm", "...", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CompteForm", "\303\240", 0, QApplication::UnicodeUTF8));
        btn_fin->setText(QApplication::translate("CompteForm", "...", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CompteForm", "Op\303\251rations r\303\251alis\303\251es", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CompteForm", "R\303\251sultat", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CompteForm", "Cr\303\251dit :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CompteForm", "  -", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CompteForm", "D\303\251bit :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CompteForm", "=", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CompteForm", "Solde :", 0, QApplication::UnicodeUTF8));
        btn_afficherOp->setText(QApplication::translate("CompteForm", "Afficher l'op\303\251ration compl\303\250te", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CompteForm: public Ui_CompteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPTEFORM_H
