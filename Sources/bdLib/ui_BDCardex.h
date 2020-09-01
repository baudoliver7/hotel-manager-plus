/********************************************************************************
** Form generated from reading UI file 'BDCardex.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCARDEX_H
#define UI_BDCARDEX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDCardex
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditClientConnu;
    QCheckBox *checkBoxMasculin;
    QTableView *tableView;
    QFormLayout *formLayout_4;
    QPushButton *btn_modifier;
    QPushButton *btn_ajouter;
    QGroupBox *groupBoxInfosClients;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBoxLocations;
    QGridLayout *gridLayout;
    QTableWidget *tableWidgetLocations;
    QGroupBox *groupBoxPiece;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEditNature;
    QLineEdit *lineEditNumero;
    QDateEdit *dateEditDateDelivrance;
    QLineEdit *lineEditLieuDelivrance;
    QLineEdit *lineEditAgentDelivreur;
    QGroupBox *groupBoxCategorie;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditTypeDeClient;
    QLabel *label_4;
    QLineEdit *lineEditProfile;
    QGroupBox *groupBoxInfosSupp;
    QGridLayout *gridLayout_4;
    QFormLayout *formLayout_3;
    QLabel *label_18;
    QSpinBox *spinBoxNbEnfants;
    QFormLayout *formLayout_2;
    QLabel *label_19;
    QLineEdit *lineEditDestinationExacte;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDCardex)
    {
        if (BDCardex->objectName().isEmpty())
            BDCardex->setObjectName(QString::fromUtf8("BDCardex"));
        BDCardex->resize(1006, 513);
        gridLayout_5 = new QGridLayout(BDCardex);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_2 = new QGroupBox(BDCardex);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_7 = new QGridLayout(groupBox_2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditClientConnu = new QLineEdit(groupBox_2);
        lineEditClientConnu->setObjectName(QString::fromUtf8("lineEditClientConnu"));
        lineEditClientConnu->setMinimumSize(QSize(200, 0));
        lineEditClientConnu->setMaximumSize(QSize(600, 16777215));

        horizontalLayout->addWidget(lineEditClientConnu);

        checkBoxMasculin = new QCheckBox(groupBox_2);
        checkBoxMasculin->setObjectName(QString::fromUtf8("checkBoxMasculin"));
        checkBoxMasculin->setChecked(true);

        horizontalLayout->addWidget(checkBoxMasculin);


        gridLayout_7->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setDefaultSectionSize(120);
        tableView->verticalHeader()->setDefaultSectionSize(17);

        gridLayout_7->addWidget(tableView, 1, 0, 1, 2);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_4->setContentsMargins(-1, -1, 7, -1);
        btn_modifier = new QPushButton(groupBox_2);
        btn_modifier->setObjectName(QString::fromUtf8("btn_modifier"));
        btn_modifier->setMaximumSize(QSize(75, 23));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, btn_modifier);

        btn_ajouter = new QPushButton(groupBox_2);
        btn_ajouter->setObjectName(QString::fromUtf8("btn_ajouter"));
        btn_ajouter->setMaximumSize(QSize(75, 23));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, btn_ajouter);


        gridLayout_7->addLayout(formLayout_4, 2, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBoxInfosClients = new QGroupBox(BDCardex);
        groupBoxInfosClients->setObjectName(QString::fromUtf8("groupBoxInfosClients"));
        groupBoxInfosClients->setMinimumSize(QSize(450, 0));
        gridLayout_6 = new QGridLayout(groupBoxInfosClients);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBoxLocations = new QGroupBox(groupBoxInfosClients);
        groupBoxLocations->setObjectName(QString::fromUtf8("groupBoxLocations"));
        groupBoxLocations->setMinimumSize(QSize(450, 0));
        gridLayout = new QGridLayout(groupBoxLocations);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidgetLocations = new QTableWidget(groupBoxLocations);
        if (tableWidgetLocations->columnCount() < 10)
            tableWidgetLocations->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetLocations->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetLocations->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetLocations->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetLocations->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetLocations->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetLocations->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetLocations->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetLocations->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetLocations->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetLocations->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidgetLocations->setObjectName(QString::fromUtf8("tableWidgetLocations"));
        tableWidgetLocations->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetLocations->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetLocations->horizontalHeader()->setDefaultSectionSize(130);
        tableWidgetLocations->verticalHeader()->setDefaultSectionSize(17);

        gridLayout->addWidget(tableWidgetLocations, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBoxLocations, 0, 0, 2, 1);

        groupBoxPiece = new QGroupBox(groupBoxInfosClients);
        groupBoxPiece->setObjectName(QString::fromUtf8("groupBoxPiece"));
        groupBoxPiece->setMaximumSize(QSize(16777215, 170));
        gridLayout_3 = new QGridLayout(groupBoxPiece);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_11 = new QLabel(groupBoxPiece);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11);

        label_12 = new QLabel(groupBoxPiece);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_4->addWidget(label_12);

        label_13 = new QLabel(groupBoxPiece);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_4->addWidget(label_13);

        label_14 = new QLabel(groupBoxPiece);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_4->addWidget(label_14);

        label_15 = new QLabel(groupBoxPiece);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_4->addWidget(label_15);


        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEditNature = new QLineEdit(groupBoxPiece);
        lineEditNature->setObjectName(QString::fromUtf8("lineEditNature"));
        lineEditNature->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditNature->setReadOnly(true);

        verticalLayout_3->addWidget(lineEditNature);

        lineEditNumero = new QLineEdit(groupBoxPiece);
        lineEditNumero->setObjectName(QString::fromUtf8("lineEditNumero"));
        lineEditNumero->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditNumero->setReadOnly(true);

        verticalLayout_3->addWidget(lineEditNumero);

        dateEditDateDelivrance = new QDateEdit(groupBoxPiece);
        dateEditDateDelivrance->setObjectName(QString::fromUtf8("dateEditDateDelivrance"));
        dateEditDateDelivrance->setReadOnly(true);

        verticalLayout_3->addWidget(dateEditDateDelivrance);

        lineEditLieuDelivrance = new QLineEdit(groupBoxPiece);
        lineEditLieuDelivrance->setObjectName(QString::fromUtf8("lineEditLieuDelivrance"));
        lineEditLieuDelivrance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditLieuDelivrance->setReadOnly(true);

        verticalLayout_3->addWidget(lineEditLieuDelivrance);

        lineEditAgentDelivreur = new QLineEdit(groupBoxPiece);
        lineEditAgentDelivreur->setObjectName(QString::fromUtf8("lineEditAgentDelivreur"));
        lineEditAgentDelivreur->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditAgentDelivreur->setReadOnly(true);

        verticalLayout_3->addWidget(lineEditAgentDelivreur);


        gridLayout_3->addLayout(verticalLayout_3, 0, 1, 1, 1);


        gridLayout_6->addWidget(groupBoxPiece, 0, 1, 2, 1);

        groupBoxCategorie = new QGroupBox(groupBoxInfosClients);
        groupBoxCategorie->setObjectName(QString::fromUtf8("groupBoxCategorie"));
        groupBoxCategorie->setMaximumSize(QSize(327, 16777215));
        gridLayout_2 = new QGridLayout(groupBoxCategorie);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBoxCategorie);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEditTypeDeClient = new QLineEdit(groupBoxCategorie);
        lineEditTypeDeClient->setObjectName(QString::fromUtf8("lineEditTypeDeClient"));
        lineEditTypeDeClient->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTypeDeClient->setReadOnly(true);

        gridLayout_2->addWidget(lineEditTypeDeClient, 0, 1, 1, 1);

        label_4 = new QLabel(groupBoxCategorie);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        lineEditProfile = new QLineEdit(groupBoxCategorie);
        lineEditProfile->setObjectName(QString::fromUtf8("lineEditProfile"));
        lineEditProfile->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditProfile->setReadOnly(true);

        gridLayout_2->addWidget(lineEditProfile, 1, 1, 1, 1);


        gridLayout_6->addWidget(groupBoxCategorie, 0, 2, 1, 1);

        groupBoxInfosSupp = new QGroupBox(groupBoxInfosClients);
        groupBoxInfosSupp->setObjectName(QString::fromUtf8("groupBoxInfosSupp"));
        groupBoxInfosSupp->setMaximumSize(QSize(327, 16777215));
        gridLayout_4 = new QGridLayout(groupBoxInfosSupp);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_18 = new QLabel(groupBoxInfosSupp);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_18);

        spinBoxNbEnfants = new QSpinBox(groupBoxInfosSupp);
        spinBoxNbEnfants->setObjectName(QString::fromUtf8("spinBoxNbEnfants"));
        spinBoxNbEnfants->setReadOnly(true);
        spinBoxNbEnfants->setMaximum(100);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBoxNbEnfants);


        gridLayout_4->addLayout(formLayout_3, 0, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_19 = new QLabel(groupBoxInfosSupp);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_19);

        lineEditDestinationExacte = new QLineEdit(groupBoxInfosSupp);
        lineEditDestinationExacte->setObjectName(QString::fromUtf8("lineEditDestinationExacte"));
        lineEditDestinationExacte->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDestinationExacte->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEditDestinationExacte);


        gridLayout_4->addLayout(formLayout_2, 1, 0, 1, 1);


        gridLayout_6->addWidget(groupBoxInfosSupp, 1, 2, 1, 1);


        gridLayout_5->addWidget(groupBoxInfosClients, 1, 0, 1, 1);

        btn_fermer = new QPushButton(BDCardex);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_5->addWidget(btn_fermer, 2, 0, 1, 1);


        retranslateUi(BDCardex);

        QMetaObject::connectSlotsByName(BDCardex);
    } // setupUi

    void retranslateUi(QDialog *BDCardex)
    {
        BDCardex->setWindowTitle(QApplication::translate("BDCardex", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDCardex", "Clients", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDCardex", "Nom :", 0, QApplication::UnicodeUTF8));
        checkBoxMasculin->setText(QApplication::translate("BDCardex", "Masculin", 0, QApplication::UnicodeUTF8));
        btn_modifier->setText(QApplication::translate("BDCardex", "Modifier", 0, QApplication::UnicodeUTF8));
        btn_ajouter->setText(QApplication::translate("BDCardex", "Ajouter", 0, QApplication::UnicodeUTF8));
        groupBoxInfosClients->setTitle(QApplication::translate("BDCardex", "Informations sur le client s\303\251lectionn\303\251", 0, QApplication::UnicodeUTF8));
        groupBoxLocations->setTitle(QApplication::translate("BDCardex", "Locations", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetLocations->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BDCardex", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetLocations->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BDCardex", "Facture", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetLocations->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BDCardex", "Chambre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetLocations->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BDCardex", "Date d'arriv\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetLocations->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("BDCardex", "Date de d\303\251part", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetLocations->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("BDCardex", "Dur\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetLocations->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("BDCardex", "Montant total", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetLocations->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("BDCardex", "Montant pay\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetLocations->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("BDCardex", "Montant restant", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetLocations->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("BDCardex", "Matricule agent", 0, QApplication::UnicodeUTF8));
        groupBoxPiece->setTitle(QApplication::translate("BDCardex", "Pi\303\250ce d'identit\303\251 produite", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BDCardex", "Nature:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("BDCardex", "N\302\260 :", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("BDCardex", "D\303\251livr\303\251 le:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("BDCardex", "A :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("BDCardex", "Par :", 0, QApplication::UnicodeUTF8));
        groupBoxCategorie->setTitle(QApplication::translate("BDCardex", "Cat\303\251gorie", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDCardex", "Type de client :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDCardex", "Profile :", 0, QApplication::UnicodeUTF8));
        groupBoxInfosSupp->setTitle(QApplication::translate("BDCardex", "Autres informations", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("BDCardex", "Nb d'enfants accompagnant \303\242ge < 15 ans :", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("BDCardex", "Destination exacte: ", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDCardex", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDCardex: public Ui_BDCardex {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCARDEX_H
