/********************************************************************************
** Form generated from reading UI file 'BDIdentifierClientHotel.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDIDENTIFIERCLIENTHOTEL_H
#define UI_BDIDENTIFIERCLIENTHOTEL_H

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

class Ui_BDIdentifierClientHotel
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
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEditClientSelectionne;
    QPushButton *btn_details;
    QLabel *label_2;
    QComboBox *comboBoxTypeDeClient;
    QLabel *label_4;
    QComboBox *comboBoxProfile;
    QFormLayout *formLayout;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDIdentifierClientHotel)
    {
        if (BDIdentifierClientHotel->objectName().isEmpty())
            BDIdentifierClientHotel->setObjectName(QString::fromUtf8("BDIdentifierClientHotel"));
        BDIdentifierClientHotel->resize(529, 465);
        gridLayout_3 = new QGridLayout(BDIdentifierClientHotel);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(BDIdentifierClientHotel);
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

        gridLayout_2->addWidget(lineEditClientConnu, 1, 2, 1, 1);

        checkBoxMasculin = new QCheckBox(groupBox_2);
        checkBoxMasculin->setObjectName(QString::fromUtf8("checkBoxMasculin"));
        checkBoxMasculin->setChecked(true);

        gridLayout_2->addWidget(checkBoxMasculin, 1, 3, 1, 1);

        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setDefaultSectionSize(120);
        tableView->verticalHeader()->setDefaultSectionSize(17);

        gridLayout_2->addWidget(tableView, 2, 0, 1, 5);

        btn_choisir = new QPushButton(groupBox_2);
        btn_choisir->setObjectName(QString::fromUtf8("btn_choisir"));
        btn_choisir->setMaximumSize(QSize(75, 23));

        gridLayout_2->addWidget(btn_choisir, 3, 4, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(BDIdentifierClientHotel);
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

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboBoxTypeDeClient = new QComboBox(groupBox);
        comboBoxTypeDeClient->setObjectName(QString::fromUtf8("comboBoxTypeDeClient"));
        comboBoxTypeDeClient->setMaximumSize(QSize(140, 16777215));

        gridLayout->addWidget(comboBoxTypeDeClient, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        comboBoxProfile = new QComboBox(groupBox);
        comboBoxProfile->setObjectName(QString::fromUtf8("comboBoxProfile"));
        comboBoxProfile->setMaximumSize(QSize(140, 16777215));

        gridLayout->addWidget(comboBoxProfile, 2, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 7, -1);
        btn_ok = new QPushButton(BDIdentifierClientHotel);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDIdentifierClientHotel);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout_3->addLayout(formLayout, 2, 0, 1, 1);


        retranslateUi(BDIdentifierClientHotel);

        QMetaObject::connectSlotsByName(BDIdentifierClientHotel);
    } // setupUi

    void retranslateUi(QDialog *BDIdentifierClientHotel)
    {
        BDIdentifierClientHotel->setWindowTitle(QApplication::translate("BDIdentifierClientHotel", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDIdentifierClientHotel", "Choisir un client", 0, QApplication::UnicodeUTF8));
        rb_clientInconnu->setText(QApplication::translate("BDIdentifierClientHotel", "Client inconnu", 0, QApplication::UnicodeUTF8));
        btn_identifier->setText(QApplication::translate("BDIdentifierClientHotel", "Identifier", 0, QApplication::UnicodeUTF8));
        rb_clientConnu->setText(QApplication::translate("BDIdentifierClientHotel", "Client connu", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDIdentifierClientHotel", "Nom :", 0, QApplication::UnicodeUTF8));
        checkBoxMasculin->setText(QApplication::translate("BDIdentifierClientHotel", "Masculin", 0, QApplication::UnicodeUTF8));
        btn_choisir->setText(QApplication::translate("BDIdentifierClientHotel", "S\303\251lectionner", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDIdentifierClientHotel", "Client choisi", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDIdentifierClientHotel", "Nom complet :", 0, QApplication::UnicodeUTF8));
        btn_details->setText(QApplication::translate("BDIdentifierClientHotel", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDIdentifierClientHotel", "Type de client :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDIdentifierClientHotel", "Profile :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDIdentifierClientHotel", "Choisir", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDIdentifierClientHotel", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDIdentifierClientHotel: public Ui_BDIdentifierClientHotel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDIDENTIFIERCLIENTHOTEL_H
