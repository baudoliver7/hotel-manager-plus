/********************************************************************************
** Form generated from reading UI file 'BDFacturerUnGroupe.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDFACTURERUNGROUPE_H
#define UI_BDFACTURERUNGROUPE_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_BDFacturerUnGroupe
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditGroupe;
    QToolButton *btn_groupe;
    QLabel *label_10;
    QLineEdit *lineEditResponsable;
    QPushButton *btn_details;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditFraisDeLocation;
    QLabel *label_3;
    QLineEdit *lineEditFraisDeRestauration;
    QPushButton *btn_detailsResto;
    QLabel *label_11;
    QLineEdit *lineEditFraisDeBar;
    QPushButton *btn_detailsBar;
    QLabel *label_4;
    QLineEdit *lineEditPenaliteRetard;
    QLabel *label_5;
    QLineEdit *lineEditTotalAPayer;
    QLabel *label_6;
    QLineEdit *lineEditMontantPaye;
    QLabel *label_7;
    QLineEdit *lineEditMontantRestant;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QRadioButton *rb_regler;
    QRadioButton *rb_restituer;
    QLabel *label_8;
    QSpinBox *spinBoxMontantAVerser;
    QPushButton *btn_payerTout;
    QLabel *label_9;
    QComboBox *comboBoxModeDePaye;
    QFormLayout *formLayout_2;
    QPushButton *btn_ok;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDFacturerUnGroupe)
    {
        if (BDFacturerUnGroupe->objectName().isEmpty())
            BDFacturerUnGroupe->setObjectName(QString::fromUtf8("BDFacturerUnGroupe"));
        BDFacturerUnGroupe->resize(309, 475);
        gridLayout_4 = new QGridLayout(BDFacturerUnGroupe);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(BDFacturerUnGroupe);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditGroupe = new QLineEdit(groupBox);
        lineEditGroupe->setObjectName(QString::fromUtf8("lineEditGroupe"));
        lineEditGroupe->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditGroupe->setReadOnly(true);

        gridLayout->addWidget(lineEditGroupe, 0, 1, 1, 1);

        btn_groupe = new QToolButton(groupBox);
        btn_groupe->setObjectName(QString::fromUtf8("btn_groupe"));
        btn_groupe->setMaximumSize(QSize(25, 19));

        gridLayout->addWidget(btn_groupe, 0, 2, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        lineEditResponsable = new QLineEdit(groupBox);
        lineEditResponsable->setObjectName(QString::fromUtf8("lineEditResponsable"));
        lineEditResponsable->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditResponsable->setReadOnly(true);

        gridLayout->addWidget(lineEditResponsable, 1, 1, 1, 1);

        btn_details = new QPushButton(groupBox);
        btn_details->setObjectName(QString::fromUtf8("btn_details"));
        btn_details->setMaximumSize(QSize(25, 19));

        gridLayout->addWidget(btn_details, 1, 2, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(BDFacturerUnGroupe);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEditFraisDeLocation = new QLineEdit(groupBox_2);
        lineEditFraisDeLocation->setObjectName(QString::fromUtf8("lineEditFraisDeLocation"));
        lineEditFraisDeLocation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFraisDeLocation->setReadOnly(true);

        gridLayout_2->addWidget(lineEditFraisDeLocation, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        lineEditFraisDeRestauration = new QLineEdit(groupBox_2);
        lineEditFraisDeRestauration->setObjectName(QString::fromUtf8("lineEditFraisDeRestauration"));
        lineEditFraisDeRestauration->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFraisDeRestauration->setReadOnly(true);

        gridLayout_2->addWidget(lineEditFraisDeRestauration, 1, 1, 1, 1);

        btn_detailsResto = new QPushButton(groupBox_2);
        btn_detailsResto->setObjectName(QString::fromUtf8("btn_detailsResto"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/22352-bubka-Print.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_detailsResto->setIcon(icon);
        btn_detailsResto->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(btn_detailsResto, 1, 2, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 2, 0, 1, 1);

        lineEditFraisDeBar = new QLineEdit(groupBox_2);
        lineEditFraisDeBar->setObjectName(QString::fromUtf8("lineEditFraisDeBar"));
        lineEditFraisDeBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditFraisDeBar->setReadOnly(true);

        gridLayout_2->addWidget(lineEditFraisDeBar, 2, 1, 1, 1);

        btn_detailsBar = new QPushButton(groupBox_2);
        btn_detailsBar->setObjectName(QString::fromUtf8("btn_detailsBar"));
        btn_detailsBar->setIcon(icon);
        btn_detailsBar->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(btn_detailsBar, 2, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        lineEditPenaliteRetard = new QLineEdit(groupBox_2);
        lineEditPenaliteRetard->setObjectName(QString::fromUtf8("lineEditPenaliteRetard"));
        lineEditPenaliteRetard->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPenaliteRetard->setReadOnly(true);

        gridLayout_2->addWidget(lineEditPenaliteRetard, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        lineEditTotalAPayer = new QLineEdit(groupBox_2);
        lineEditTotalAPayer->setObjectName(QString::fromUtf8("lineEditTotalAPayer"));
        lineEditTotalAPayer->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTotalAPayer->setReadOnly(true);

        gridLayout_2->addWidget(lineEditTotalAPayer, 4, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        lineEditMontantPaye = new QLineEdit(groupBox_2);
        lineEditMontantPaye->setObjectName(QString::fromUtf8("lineEditMontantPaye"));
        lineEditMontantPaye->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantPaye->setReadOnly(true);

        gridLayout_2->addWidget(lineEditMontantPaye, 5, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 6, 0, 1, 1);

        lineEditMontantRestant = new QLineEdit(groupBox_2);
        lineEditMontantRestant->setObjectName(QString::fromUtf8("lineEditMontantRestant"));
        lineEditMontantRestant->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMontantRestant->setReadOnly(true);

        gridLayout_2->addWidget(lineEditMontantRestant, 6, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(BDFacturerUnGroupe);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        rb_regler = new QRadioButton(groupBox_3);
        rb_regler->setObjectName(QString::fromUtf8("rb_regler"));

        gridLayout_3->addWidget(rb_regler, 0, 0, 1, 1);

        rb_restituer = new QRadioButton(groupBox_3);
        rb_restituer->setObjectName(QString::fromUtf8("rb_restituer"));

        gridLayout_3->addWidget(rb_restituer, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        spinBoxMontantAVerser = new QSpinBox(groupBox_3);
        spinBoxMontantAVerser->setObjectName(QString::fromUtf8("spinBoxMontantAVerser"));
        spinBoxMontantAVerser->setMaximum(100000000);
        spinBoxMontantAVerser->setSingleStep(500);

        gridLayout_3->addWidget(spinBoxMontantAVerser, 1, 1, 1, 1);

        btn_payerTout = new QPushButton(groupBox_3);
        btn_payerTout->setObjectName(QString::fromUtf8("btn_payerTout"));
        btn_payerTout->setMaximumSize(QSize(75, 23));

        gridLayout_3->addWidget(btn_payerTout, 1, 2, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        comboBoxModeDePaye = new QComboBox(groupBox_3);
        comboBoxModeDePaye->setObjectName(QString::fromUtf8("comboBoxModeDePaye"));

        gridLayout_3->addWidget(comboBoxModeDePaye, 2, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_2->setContentsMargins(-1, -1, 6, -1);
        btn_ok = new QPushButton(BDFacturerUnGroupe);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMaximumSize(QSize(75, 23));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, btn_ok);

        btn_annuler = new QPushButton(BDFacturerUnGroupe);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout_4->addLayout(formLayout_2, 3, 0, 1, 1);


        retranslateUi(BDFacturerUnGroupe);

        QMetaObject::connectSlotsByName(BDFacturerUnGroupe);
    } // setupUi

    void retranslateUi(QDialog *BDFacturerUnGroupe)
    {
        BDFacturerUnGroupe->setWindowTitle(QApplication::translate("BDFacturerUnGroupe", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDFacturerUnGroupe", "Description du groupe", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDFacturerUnGroupe", "Groupe :", 0, QApplication::UnicodeUTF8));
        btn_groupe->setText(QApplication::translate("BDFacturerUnGroupe", "...", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BDFacturerUnGroupe", "Responsable :", 0, QApplication::UnicodeUTF8));
        btn_details->setText(QApplication::translate("BDFacturerUnGroupe", "...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDFacturerUnGroupe", "D\303\251tails des montants", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDFacturerUnGroupe", "Frais de location :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDFacturerUnGroupe", "Frais de restauration :", 0, QApplication::UnicodeUTF8));
        btn_detailsResto->setText(QString());
        label_11->setText(QApplication::translate("BDFacturerUnGroupe", "Frais de bar :", 0, QApplication::UnicodeUTF8));
        btn_detailsBar->setText(QString());
        label_4->setText(QApplication::translate("BDFacturerUnGroupe", "Frais p\303\251nalit\303\251 retard :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDFacturerUnGroupe", "Total \303\240 payer :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDFacturerUnGroupe", "Montant pay\303\251:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BDFacturerUnGroupe", "Montant restant :", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("BDFacturerUnGroupe", "R\303\250glement des frais", 0, QApplication::UnicodeUTF8));
        rb_regler->setText(QApplication::translate("BDFacturerUnGroupe", "R\303\251gler", 0, QApplication::UnicodeUTF8));
        rb_restituer->setText(QApplication::translate("BDFacturerUnGroupe", "Restituer", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BDFacturerUnGroupe", "Montant \303\240 verser :", 0, QApplication::UnicodeUTF8));
        btn_payerTout->setText(QApplication::translate("BDFacturerUnGroupe", "Payer tout", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BDFacturerUnGroupe", "Mode :", 0, QApplication::UnicodeUTF8));
        btn_ok->setText(QApplication::translate("BDFacturerUnGroupe", "OK", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDFacturerUnGroupe", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDFacturerUnGroupe: public Ui_BDFacturerUnGroupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDFACTURERUNGROUPE_H
