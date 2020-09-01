/********************************************************************************
** Form generated from reading UI file 'BDEditerClotures.ui'
**
** Created: Fri 25. Jan 23:18:58 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDEDITERCLOTURES_H
#define UI_BDEDITERCLOTURES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDEditerClotures
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QFrame *frame;
    QFormLayout *formLayout_5;
    QRadioButton *rb_depouillee;
    QRadioButton *rb_nonDepouillee;
    QTableView *tableViewClotures;
    QPushButton *btn_depouilleEntier;
    QGroupBox *groupBoxDetails;
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QFormLayout *formLayout_2;
    QRadioButton *rb_depouilleDetails;
    QRadioButton *rb_nonDepouilleeDetails;
    QTableView *tableViewDetailsCloture;
    QPushButton *btn_operation_depouillee;
    QGroupBox *groupBoxCritere;
    QGridLayout *gridLayout_5;
    QFormLayout *formLayout_6;
    QRadioButton *rb_depotSurCompteClient;
    QRadioButton *rb_vente;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBoxAppliquerTVA;
    QCheckBox *checkBoxAppliquerTT;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBoxTT;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxRessource;
    QLabel *label_3;
    QComboBox *comboBoxEmploi;
    QPushButton *btn_depouiller;
    QFormLayout *formLayout;
    QPushButton *btn_faireUneOperation;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDEditerClotures)
    {
        if (BDEditerClotures->objectName().isEmpty())
            BDEditerClotures->setObjectName(QString::fromUtf8("BDEditerClotures"));
        BDEditerClotures->resize(727, 640);
        gridLayout_4 = new QGridLayout(BDEditerClotures);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(BDEditerClotures);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 255));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(565, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout_5 = new QFormLayout(frame);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setContentsMargins(-1, 0, -1, 0);
        rb_depouillee = new QRadioButton(frame);
        rb_depouillee->setObjectName(QString::fromUtf8("rb_depouillee"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, rb_depouillee);

        rb_nonDepouillee = new QRadioButton(frame);
        rb_nonDepouillee->setObjectName(QString::fromUtf8("rb_nonDepouillee"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, rb_nonDepouillee);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        tableViewClotures = new QTableView(groupBox);
        tableViewClotures->setObjectName(QString::fromUtf8("tableViewClotures"));
        tableViewClotures->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewClotures->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewClotures->horizontalHeader()->setDefaultSectionSize(120);
        tableViewClotures->verticalHeader()->setDefaultSectionSize(25);

        gridLayout->addWidget(tableViewClotures, 1, 0, 1, 1);

        btn_depouilleEntier = new QPushButton(groupBox);
        btn_depouilleEntier->setObjectName(QString::fromUtf8("btn_depouilleEntier"));
        btn_depouilleEntier->setMaximumSize(QSize(120, 16777215));
        btn_depouilleEntier->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(btn_depouilleEntier, 2, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxDetails = new QGroupBox(BDEditerClotures);
        groupBoxDetails->setObjectName(QString::fromUtf8("groupBoxDetails"));
        gridLayout_2 = new QGridLayout(groupBoxDetails);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_2 = new QFrame(groupBoxDetails);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frame_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(-1, 0, -1, 0);
        rb_depouilleDetails = new QRadioButton(frame_2);
        rb_depouilleDetails->setObjectName(QString::fromUtf8("rb_depouilleDetails"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rb_depouilleDetails);

        rb_nonDepouilleeDetails = new QRadioButton(frame_2);
        rb_nonDepouilleeDetails->setObjectName(QString::fromUtf8("rb_nonDepouilleeDetails"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, rb_nonDepouilleeDetails);


        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);

        tableViewDetailsCloture = new QTableView(groupBoxDetails);
        tableViewDetailsCloture->setObjectName(QString::fromUtf8("tableViewDetailsCloture"));
        tableViewDetailsCloture->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewDetailsCloture->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewDetailsCloture->horizontalHeader()->setDefaultSectionSize(150);
        tableViewDetailsCloture->horizontalHeader()->setMinimumSectionSize(150);
        tableViewDetailsCloture->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_2->addWidget(tableViewDetailsCloture, 1, 0, 1, 2);

        btn_operation_depouillee = new QPushButton(groupBoxDetails);
        btn_operation_depouillee->setObjectName(QString::fromUtf8("btn_operation_depouillee"));
        btn_operation_depouillee->setMaximumSize(QSize(120, 16777215));
        btn_operation_depouillee->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btn_operation_depouillee, 2, 1, 1, 1);


        gridLayout_4->addWidget(groupBoxDetails, 1, 0, 1, 1);

        groupBoxCritere = new QGroupBox(BDEditerClotures);
        groupBoxCritere->setObjectName(QString::fromUtf8("groupBoxCritere"));
        groupBoxCritere->setMaximumSize(QSize(16777215, 86));
        gridLayout_5 = new QGridLayout(groupBoxCritere);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        rb_depotSurCompteClient = new QRadioButton(groupBoxCritere);
        rb_depotSurCompteClient->setObjectName(QString::fromUtf8("rb_depotSurCompteClient"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, rb_depotSurCompteClient);

        rb_vente = new QRadioButton(groupBoxCritere);
        rb_vente->setObjectName(QString::fromUtf8("rb_vente"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, rb_vente);


        gridLayout_5->addLayout(formLayout_6, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBoxAppliquerTVA = new QCheckBox(groupBoxCritere);
        checkBoxAppliquerTVA->setObjectName(QString::fromUtf8("checkBoxAppliquerTVA"));

        verticalLayout_2->addWidget(checkBoxAppliquerTVA);

        checkBoxAppliquerTT = new QCheckBox(groupBoxCritere);
        checkBoxAppliquerTT->setObjectName(QString::fromUtf8("checkBoxAppliquerTT"));

        verticalLayout_2->addWidget(checkBoxAppliquerTT);


        gridLayout_5->addLayout(verticalLayout_2, 0, 1, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        doubleSpinBox = new QDoubleSpinBox(groupBoxCritere);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(doubleSpinBox);

        doubleSpinBoxTT = new QDoubleSpinBox(groupBoxCritere);
        doubleSpinBoxTT->setObjectName(QString::fromUtf8("doubleSpinBoxTT"));
        doubleSpinBoxTT->setMaximumSize(QSize(50, 16777215));

        verticalLayout->addWidget(doubleSpinBoxTT);


        gridLayout_5->addLayout(verticalLayout, 0, 2, 2, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBoxCritere);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBoxRessource = new QComboBox(groupBoxCritere);
        comboBoxRessource->setObjectName(QString::fromUtf8("comboBoxRessource"));
        comboBoxRessource->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_2->addWidget(comboBoxRessource);

        label_3 = new QLabel(groupBoxCritere);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        comboBoxEmploi = new QComboBox(groupBoxCritere);
        comboBoxEmploi->setObjectName(QString::fromUtf8("comboBoxEmploi"));
        comboBoxEmploi->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_2->addWidget(comboBoxEmploi);


        gridLayout_5->addLayout(horizontalLayout_2, 0, 3, 1, 1);

        btn_depouiller = new QPushButton(groupBoxCritere);
        btn_depouiller->setObjectName(QString::fromUtf8("btn_depouiller"));
        btn_depouiller->setMaximumSize(QSize(75, 23));
        btn_depouiller->setLayoutDirection(Qt::RightToLeft);

        gridLayout_5->addWidget(btn_depouiller, 1, 3, 1, 1);


        gridLayout_4->addWidget(groupBoxCritere, 2, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 8, -1);
        btn_faireUneOperation = new QPushButton(BDEditerClotures);
        btn_faireUneOperation->setObjectName(QString::fromUtf8("btn_faireUneOperation"));
        btn_faireUneOperation->setMinimumSize(QSize(120, 0));
        btn_faireUneOperation->setMaximumSize(QSize(120, 23));
        btn_faireUneOperation->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_faireUneOperation);

        btn_fermer = new QPushButton(BDEditerClotures);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_fermer);


        gridLayout_4->addLayout(formLayout, 3, 0, 1, 1);


        retranslateUi(BDEditerClotures);

        QMetaObject::connectSlotsByName(BDEditerClotures);
    } // setupUi

    void retranslateUi(QDialog *BDEditerClotures)
    {
        BDEditerClotures->setWindowTitle(QApplication::translate("BDEditerClotures", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDEditerClotures", "Cl\303\264tures", 0, QApplication::UnicodeUTF8));
        rb_depouillee->setText(QApplication::translate("BDEditerClotures", "D\303\251pouill\303\251e", 0, QApplication::UnicodeUTF8));
        rb_nonDepouillee->setText(QApplication::translate("BDEditerClotures", "Non d\303\251pouill\303\251e", 0, QApplication::UnicodeUTF8));
        btn_depouilleEntier->setText(QApplication::translate("BDEditerClotures", "D\303\251clarer d\303\251pouill\303\251e", 0, QApplication::UnicodeUTF8));
        groupBoxDetails->setTitle(QApplication::translate("BDEditerClotures", "Op\303\251rations de la cl\303\264ture s\303\251lectionn\303\251e", 0, QApplication::UnicodeUTF8));
        rb_depouilleDetails->setText(QApplication::translate("BDEditerClotures", "D\303\251pouill\303\251e", 0, QApplication::UnicodeUTF8));
        rb_nonDepouilleeDetails->setText(QApplication::translate("BDEditerClotures", "Non d\303\251pouill\303\251e", 0, QApplication::UnicodeUTF8));
        btn_operation_depouillee->setText(QApplication::translate("BDEditerClotures", "D\303\251clarer d\303\251pouill\303\251e", 0, QApplication::UnicodeUTF8));
        groupBoxCritere->setTitle(QApplication::translate("BDEditerClotures", "Crit\303\250re de d\303\251pouillement", 0, QApplication::UnicodeUTF8));
        rb_depotSurCompteClient->setText(QApplication::translate("BDEditerClotures", "D\303\251p\303\264t/Retrait", 0, QApplication::UnicodeUTF8));
        rb_vente->setText(QApplication::translate("BDEditerClotures", "Vente et location", 0, QApplication::UnicodeUTF8));
        checkBoxAppliquerTVA->setText(QApplication::translate("BDEditerClotures", "Appliquer le taux TVA", 0, QApplication::UnicodeUTF8));
        checkBoxAppliquerTT->setText(QApplication::translate("BDEditerClotures", "Appliquer le taux TT", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDEditerClotures", "CR :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDEditerClotures", "CE :", 0, QApplication::UnicodeUTF8));
        btn_depouiller->setText(QApplication::translate("BDEditerClotures", "D\303\251pouiller", 0, QApplication::UnicodeUTF8));
        btn_faireUneOperation->setText(QApplication::translate("BDEditerClotures", "Faire une op\303\251ration", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDEditerClotures", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDEditerClotures: public Ui_BDEditerClotures {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDEDITERCLOTURES_H
