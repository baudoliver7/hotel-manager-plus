/********************************************************************************
** Form generated from reading UI file 'BDExecuterNlleOperation.ui'
**
** Created: Fri 25. Jan 23:18:57 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDEXECUTERNLLEOPERATION_H
#define UI_BDEXECUTERNLLEOPERATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSplitter>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_BDExecuterNlleOperation
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBoxDate;
    QGridLayout *gridLayout_2;
    QRadioButton *rb_enLive;
    QRadioButton *rb_enDiffere;
    QFormLayout *formLayout_4;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QLineEdit *lineEditDate;
    QToolButton *btn_calendrier;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditDescription;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableWidget *tableWidgetOperation;
    QSplitter *splitter;
    QPushButton *btn_mvtDebiteur;
    QPushButton *btn_mvtCrediteur;
    QPushButton *btn_supprimerMvt;
    QPushButton *btn_editer;
    QFormLayout *formLayout_2;
    QPushButton *btn_executer;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDExecuterNlleOperation)
    {
        if (BDExecuterNlleOperation->objectName().isEmpty())
            BDExecuterNlleOperation->setObjectName(QString::fromUtf8("BDExecuterNlleOperation"));
        BDExecuterNlleOperation->resize(903, 349);
        gridLayout_3 = new QGridLayout(BDExecuterNlleOperation);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBoxDate = new QGroupBox(BDExecuterNlleOperation);
        groupBoxDate->setObjectName(QString::fromUtf8("groupBoxDate"));
        groupBoxDate->setMaximumSize(QSize(360, 16777215));
        gridLayout_2 = new QGridLayout(groupBoxDate);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rb_enLive = new QRadioButton(groupBoxDate);
        rb_enLive->setObjectName(QString::fromUtf8("rb_enLive"));

        gridLayout_2->addWidget(rb_enLive, 0, 0, 1, 1);

        rb_enDiffere = new QRadioButton(groupBoxDate);
        rb_enDiffere->setObjectName(QString::fromUtf8("rb_enDiffere"));

        gridLayout_2->addWidget(rb_enDiffere, 0, 1, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_2 = new QLabel(groupBoxDate);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEditDate = new QLineEdit(groupBoxDate);
        lineEditDate->setObjectName(QString::fromUtf8("lineEditDate"));
        lineEditDate->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEditDate);


        formLayout_4->setLayout(0, QFormLayout::LabelRole, formLayout_3);

        btn_calendrier = new QToolButton(groupBoxDate);
        btn_calendrier->setObjectName(QString::fromUtf8("btn_calendrier"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, btn_calendrier);


        gridLayout_2->addLayout(formLayout_4, 0, 2, 1, 1);


        gridLayout_3->addWidget(groupBoxDate, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(BDExecuterNlleOperation);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditDescription = new QLineEdit(BDExecuterNlleOperation);
        lineEditDescription->setObjectName(QString::fromUtf8("lineEditDescription"));
        lineEditDescription->setMaxLength(160);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditDescription);


        gridLayout_3->addLayout(formLayout, 1, 0, 1, 1);

        groupBox = new QGroupBox(BDExecuterNlleOperation);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidgetOperation = new QTableWidget(groupBox);
        if (tableWidgetOperation->columnCount() < 5)
            tableWidgetOperation->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetOperation->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetOperation->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetOperation->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetOperation->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetOperation->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetOperation->setObjectName(QString::fromUtf8("tableWidgetOperation"));
        tableWidgetOperation->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetOperation->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetOperation->horizontalHeader()->setDefaultSectionSize(170);
        tableWidgetOperation->horizontalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tableWidgetOperation, 0, 0, 1, 1);

        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setLayoutDirection(Qt::RightToLeft);
        splitter->setOrientation(Qt::Horizontal);
        btn_mvtDebiteur = new QPushButton(splitter);
        btn_mvtDebiteur->setObjectName(QString::fromUtf8("btn_mvtDebiteur"));
        btn_mvtDebiteur->setMaximumSize(QSize(120, 23));
        btn_mvtDebiteur->setLayoutDirection(Qt::LeftToRight);
        splitter->addWidget(btn_mvtDebiteur);
        btn_mvtCrediteur = new QPushButton(splitter);
        btn_mvtCrediteur->setObjectName(QString::fromUtf8("btn_mvtCrediteur"));
        btn_mvtCrediteur->setMaximumSize(QSize(120, 23));
        btn_mvtCrediteur->setLayoutDirection(Qt::LeftToRight);
        splitter->addWidget(btn_mvtCrediteur);
        btn_supprimerMvt = new QPushButton(splitter);
        btn_supprimerMvt->setObjectName(QString::fromUtf8("btn_supprimerMvt"));
        btn_supprimerMvt->setMaximumSize(QSize(100, 23));
        btn_supprimerMvt->setLayoutDirection(Qt::LeftToRight);
        splitter->addWidget(btn_supprimerMvt);
        btn_editer = new QPushButton(splitter);
        btn_editer->setObjectName(QString::fromUtf8("btn_editer"));
        btn_editer->setMaximumSize(QSize(100, 16777215));
        splitter->addWidget(btn_editer);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 2, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_2->setContentsMargins(-1, -1, 8, -1);
        btn_executer = new QPushButton(BDExecuterNlleOperation);
        btn_executer->setObjectName(QString::fromUtf8("btn_executer"));
        btn_executer->setMaximumSize(QSize(75, 23));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, btn_executer);

        btn_annuler = new QPushButton(BDExecuterNlleOperation);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout_3->addLayout(formLayout_2, 3, 0, 1, 1);


        retranslateUi(BDExecuterNlleOperation);

        QMetaObject::connectSlotsByName(BDExecuterNlleOperation);
    } // setupUi

    void retranslateUi(QDialog *BDExecuterNlleOperation)
    {
        BDExecuterNlleOperation->setWindowTitle(QApplication::translate("BDExecuterNlleOperation", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBoxDate->setTitle(QApplication::translate("BDExecuterNlleOperation", "Date de l'op\303\251ration", 0, QApplication::UnicodeUTF8));
        rb_enLive->setText(QApplication::translate("BDExecuterNlleOperation", "En live", 0, QApplication::UnicodeUTF8));
        rb_enDiffere->setText(QApplication::translate("BDExecuterNlleOperation", "En diff\303\251r\303\251", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDExecuterNlleOperation", "Date :", 0, QApplication::UnicodeUTF8));
        btn_calendrier->setText(QApplication::translate("BDExecuterNlleOperation", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDExecuterNlleOperation", "Description de l'op\303\251ration :", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDExecuterNlleOperation", "Param\303\251trage de l'op\303\251ration", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetOperation->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BDExecuterNlleOperation", "N\302\260 compte d\303\251bit", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetOperation->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BDExecuterNlleOperation", "N\302\260 compte cr\303\251dit", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetOperation->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BDExecuterNlleOperation", "Libell\303\251 du compte", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetOperation->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BDExecuterNlleOperation", "Montant d\303\251bit", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetOperation->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("BDExecuterNlleOperation", "Montant cr\303\251dit", 0, QApplication::UnicodeUTF8));
        btn_mvtDebiteur->setText(QApplication::translate("BDExecuterNlleOperation", "D\303\251biter un compte", 0, QApplication::UnicodeUTF8));
        btn_mvtCrediteur->setText(QApplication::translate("BDExecuterNlleOperation", "Cr\303\251diter un compte", 0, QApplication::UnicodeUTF8));
        btn_supprimerMvt->setText(QApplication::translate("BDExecuterNlleOperation", "Supprimer", 0, QApplication::UnicodeUTF8));
        btn_editer->setText(QApplication::translate("BDExecuterNlleOperation", "Editer", 0, QApplication::UnicodeUTF8));
        btn_executer->setText(QApplication::translate("BDExecuterNlleOperation", "Ex\303\251cuter", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDExecuterNlleOperation", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDExecuterNlleOperation: public Ui_BDExecuterNlleOperation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDEXECUTERNLLEOPERATION_H
