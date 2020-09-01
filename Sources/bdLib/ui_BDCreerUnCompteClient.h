/********************************************************************************
** Form generated from reading UI file 'BDCreerUnCompteClient.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCREERUNCOMPTECLIENT_H
#define UI_BDCREERUNCOMPTECLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_BDCreerUnCompteClient
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditLibelle;
    QLabel *label_2;
    QLineEdit *lineEditClient;
    QToolButton *btn_client;
    QLabel *label_3;
    QSpinBox *spinBoxSolde;
    QLabel *label_4;
    QComboBox *comboBoxModeDePayement;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidgetComptes;
    QFormLayout *formLayout;
    QPushButton *btn_creer;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDCreerUnCompteClient)
    {
        if (BDCreerUnCompteClient->objectName().isEmpty())
            BDCreerUnCompteClient->setObjectName(QString::fromUtf8("BDCreerUnCompteClient"));
        BDCreerUnCompteClient->resize(518, 192);
        gridLayout_3 = new QGridLayout(BDCreerUnCompteClient);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(BDCreerUnCompteClient);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditLibelle = new QLineEdit(groupBox_2);
        lineEditLibelle->setObjectName(QString::fromUtf8("lineEditLibelle"));

        gridLayout->addWidget(lineEditLibelle, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditClient = new QLineEdit(groupBox_2);
        lineEditClient->setObjectName(QString::fromUtf8("lineEditClient"));
        lineEditClient->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClient->setReadOnly(true);

        gridLayout->addWidget(lineEditClient, 1, 1, 1, 1);

        btn_client = new QToolButton(groupBox_2);
        btn_client->setObjectName(QString::fromUtf8("btn_client"));

        gridLayout->addWidget(btn_client, 1, 2, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spinBoxSolde = new QSpinBox(groupBox_2);
        spinBoxSolde->setObjectName(QString::fromUtf8("spinBoxSolde"));
        spinBoxSolde->setMaximum(100000000);
        spinBoxSolde->setSingleStep(500);

        gridLayout->addWidget(spinBoxSolde, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboBoxModeDePayement = new QComboBox(groupBox_2);
        comboBoxModeDePayement->setObjectName(QString::fromUtf8("comboBoxModeDePayement"));
        comboBoxModeDePayement->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout->addWidget(comboBoxModeDePayement, 3, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(BDCreerUnCompteClient);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        treeWidgetComptes = new QTreeWidget(groupBox);
        treeWidgetComptes->setObjectName(QString::fromUtf8("treeWidgetComptes"));
        treeWidgetComptes->setColumnCount(2);
        treeWidgetComptes->header()->setDefaultSectionSize(120);
        treeWidgetComptes->header()->setStretchLastSection(false);

        gridLayout_2->addWidget(treeWidgetComptes, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_creer = new QPushButton(BDCreerUnCompteClient);
        btn_creer->setObjectName(QString::fromUtf8("btn_creer"));
        btn_creer->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_creer);

        btn_annuler = new QPushButton(BDCreerUnCompteClient);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout_3->addLayout(formLayout, 1, 1, 1, 1);


        retranslateUi(BDCreerUnCompteClient);

        QMetaObject::connectSlotsByName(BDCreerUnCompteClient);
    } // setupUi

    void retranslateUi(QDialog *BDCreerUnCompteClient)
    {
        BDCreerUnCompteClient->setWindowTitle(QApplication::translate("BDCreerUnCompteClient", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDCreerUnCompteClient", "Nouveau compte", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDCreerUnCompteClient", "Libell\303\251 : ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDCreerUnCompteClient", "Client :", 0, QApplication::UnicodeUTF8));
        btn_client->setText(QApplication::translate("BDCreerUnCompteClient", "...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDCreerUnCompteClient", "Solde :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDCreerUnCompteClient", "Mode :", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDCreerUnCompteClient", "Comptes existants du client s\303\251lectionn\303\251", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetComptes->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("BDCreerUnCompteClient", "Solde", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("BDCreerUnCompteClient", "Libell\303\251", 0, QApplication::UnicodeUTF8));
        btn_creer->setText(QApplication::translate("BDCreerUnCompteClient", "Cr\303\251er", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDCreerUnCompteClient", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDCreerUnCompteClient: public Ui_BDCreerUnCompteClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCREERUNCOMPTECLIENT_H
