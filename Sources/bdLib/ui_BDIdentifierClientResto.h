/********************************************************************************
** Form generated from reading UI file 'BDIdentifierClientResto.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDIDENTIFIERCLIENTRESTO_H
#define UI_BDIDENTIFIERCLIENTRESTO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_BDIdentifierClientResto
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *rb_clientInconnu;
    QPushButton *btn_identifier;
    QRadioButton *rb_clientConnu;
    QLabel *label;
    QLineEdit *lineEditClientConnu;
    QCheckBox *checkBoxMasculin;
    QTableView *tableView;
    QPushButton *btn_choisir;
    QRadioButton *rb_clientLocataire;
    QLabel *label_2;
    QComboBox *comboBoxChambre;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *lineEditRechercherCh;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEditClientSelectionne;
    QPushButton *btn_details;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDIdentifierClientResto)
    {
        if (BDIdentifierClientResto->objectName().isEmpty())
            BDIdentifierClientResto->setObjectName(QString::fromUtf8("BDIdentifierClientResto"));
        BDIdentifierClientResto->resize(529, 379);
        gridLayout_3 = new QGridLayout(BDIdentifierClientResto);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(BDIdentifierClientResto);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rb_clientInconnu = new QRadioButton(groupBox_2);
        rb_clientInconnu->setObjectName(QString::fromUtf8("rb_clientInconnu"));

        gridLayout_2->addWidget(rb_clientInconnu, 0, 0, 1, 1);

        btn_identifier = new QPushButton(groupBox_2);
        btn_identifier->setObjectName(QString::fromUtf8("btn_identifier"));
        btn_identifier->setMaximumSize(QSize(75, 23));

        gridLayout_2->addWidget(btn_identifier, 0, 1, 1, 2);

        rb_clientConnu = new QRadioButton(groupBox_2);
        rb_clientConnu->setObjectName(QString::fromUtf8("rb_clientConnu"));

        gridLayout_2->addWidget(rb_clientConnu, 1, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        lineEditClientConnu = new QLineEdit(groupBox_2);
        lineEditClientConnu->setObjectName(QString::fromUtf8("lineEditClientConnu"));

        gridLayout_2->addWidget(lineEditClientConnu, 1, 2, 1, 2);

        checkBoxMasculin = new QCheckBox(groupBox_2);
        checkBoxMasculin->setObjectName(QString::fromUtf8("checkBoxMasculin"));
        checkBoxMasculin->setChecked(true);

        gridLayout_2->addWidget(checkBoxMasculin, 1, 4, 1, 1);

        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setDefaultSectionSize(120);
        tableView->verticalHeader()->setDefaultSectionSize(17);

        gridLayout_2->addWidget(tableView, 2, 0, 1, 6);

        btn_choisir = new QPushButton(groupBox_2);
        btn_choisir->setObjectName(QString::fromUtf8("btn_choisir"));
        btn_choisir->setMaximumSize(QSize(75, 23));

        gridLayout_2->addWidget(btn_choisir, 3, 5, 1, 1);

        rb_clientLocataire = new QRadioButton(groupBox_2);
        rb_clientLocataire->setObjectName(QString::fromUtf8("rb_clientLocataire"));

        gridLayout_2->addWidget(rb_clientLocataire, 4, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 4, 1, 1, 2);

        comboBoxChambre = new QComboBox(groupBox_2);
        comboBoxChambre->setObjectName(QString::fromUtf8("comboBoxChambre"));

        gridLayout_2->addWidget(comboBoxChambre, 4, 3, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        lineEditRechercherCh = new QLineEdit(groupBox_2);
        lineEditRechercherCh->setObjectName(QString::fromUtf8("lineEditRechercherCh"));
        lineEditRechercherCh->setMaximumSize(QSize(100, 16777215));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditRechercherCh);


        gridLayout_2->addLayout(formLayout_2, 4, 4, 1, 2);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(BDIdentifierClientResto);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEditClientSelectionne = new QLineEdit(groupBox);
        lineEditClientSelectionne->setObjectName(QString::fromUtf8("lineEditClientSelectionne"));
        lineEditClientSelectionne->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClientSelectionne->setReadOnly(true);

        gridLayout->addWidget(lineEditClientSelectionne, 0, 1, 1, 1);

        btn_details = new QPushButton(groupBox);
        btn_details->setObjectName(QString::fromUtf8("btn_details"));

        gridLayout->addWidget(btn_details, 0, 2, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_ok = new QPushButton(BDIdentifierClientResto);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDIdentifierClientResto);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout_3->addLayout(formLayout, 2, 0, 1, 1);


        retranslateUi(BDIdentifierClientResto);

        QMetaObject::connectSlotsByName(BDIdentifierClientResto);
    } // setupUi

    void retranslateUi(QDialog *BDIdentifierClientResto)
    {
        BDIdentifierClientResto->setWindowTitle(QApplication::translate("BDIdentifierClientResto", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDIdentifierClientResto", "Choisir un client", 0, QApplication::UnicodeUTF8));
        rb_clientInconnu->setText(QApplication::translate("BDIdentifierClientResto", "Client inconnu", 0, QApplication::UnicodeUTF8));
        btn_identifier->setText(QApplication::translate("BDIdentifierClientResto", "Identifier", 0, QApplication::UnicodeUTF8));
        rb_clientConnu->setText(QApplication::translate("BDIdentifierClientResto", "Client connu", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDIdentifierClientResto", "Nom :", 0, QApplication::UnicodeUTF8));
        checkBoxMasculin->setText(QApplication::translate("BDIdentifierClientResto", "Masculin", 0, QApplication::UnicodeUTF8));
        btn_choisir->setText(QApplication::translate("BDIdentifierClientResto", "S\303\251lectionner", 0, QApplication::UnicodeUTF8));
        rb_clientLocataire->setText(QApplication::translate("BDIdentifierClientResto", "Client locataire", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDIdentifierClientResto", "Chambre :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDIdentifierClientResto", "Rechercher :", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDIdentifierClientResto", "Client choisi", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDIdentifierClientResto", "Nom complet :", 0, QApplication::UnicodeUTF8));
        btn_details->setText(QApplication::translate("BDIdentifierClientResto", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDIdentifierClientResto", "Choisir", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDIdentifierClientResto", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDIdentifierClientResto: public Ui_BDIdentifierClientResto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDIDENTIFIERCLIENTRESTO_H
