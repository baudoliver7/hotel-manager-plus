/********************************************************************************
** Form generated from reading UI file 'DialogRechercherUnClient.ui'
**
** Created: Sun 27. Oct 20:00:15 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRECHERCHERUNCLIENT_H
#define UI_DIALOGRECHERCHERUNCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogRechercherUnClient
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *Masculin;
    QRadioButton *Feminin;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditNom;
    QRadioButton *rb_clientsCrediteurs;
    QGroupBox *groupBoxListeClients;
    QGridLayout *gridLayout_3;
    QTableView *tableViewClients;
    QGroupBox *groupBoxDetails;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QFormLayout *formLayout_3;
    QLabel *label_3;
    QSpinBox *spinBoxMR;
    QRadioButton *rb_enEspeces;
    QRadioButton *rb_compteBancaire;
    QFormLayout *formLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxAction;
    QPushButton *btn_OK;
    QPushButton *btn_details;
    QFormLayout *formLayout;
    QPushButton *btn_Annuler;
    QPushButton *btn_appliquer;

    void setupUi(QDialog *DialogRechercherUnClient)
    {
        if (DialogRechercherUnClient->objectName().isEmpty())
            DialogRechercherUnClient->setObjectName(QString::fromUtf8("DialogRechercherUnClient"));
        DialogRechercherUnClient->resize(1101, 479);
        gridLayout_4 = new QGridLayout(DialogRechercherUnClient);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(DialogRechercherUnClient);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Masculin = new QRadioButton(groupBox);
        Masculin->setObjectName(QString::fromUtf8("Masculin"));

        gridLayout->addWidget(Masculin, 0, 0, 1, 1);

        Feminin = new QRadioButton(groupBox);
        Feminin->setObjectName(QString::fromUtf8("Feminin"));

        gridLayout->addWidget(Feminin, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DialogRechercherUnClient);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditNom = new QLineEdit(DialogRechercherUnClient);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));

        horizontalLayout->addWidget(lineEditNom);


        gridLayout_4->addLayout(horizontalLayout, 0, 1, 1, 1);

        rb_clientsCrediteurs = new QRadioButton(DialogRechercherUnClient);
        rb_clientsCrediteurs->setObjectName(QString::fromUtf8("rb_clientsCrediteurs"));

        gridLayout_4->addWidget(rb_clientsCrediteurs, 0, 2, 1, 1);

        groupBoxListeClients = new QGroupBox(DialogRechercherUnClient);
        groupBoxListeClients->setObjectName(QString::fromUtf8("groupBoxListeClients"));
        groupBoxListeClients->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_3 = new QGridLayout(groupBoxListeClients);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableViewClients = new QTableView(groupBoxListeClients);
        tableViewClients->setObjectName(QString::fromUtf8("tableViewClients"));
        tableViewClients->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewClients->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewClients->setTextElideMode(Qt::ElideMiddle);
        tableViewClients->horizontalHeader()->setDefaultSectionSize(150);

        gridLayout_3->addWidget(tableViewClients, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBoxListeClients, 1, 0, 1, 3);

        groupBoxDetails = new QGroupBox(DialogRechercherUnClient);
        groupBoxDetails->setObjectName(QString::fromUtf8("groupBoxDetails"));
        groupBoxDetails->setMinimumSize(QSize(461, 0));
        groupBoxDetails->setMaximumSize(QSize(16777215, 291));
        gridLayout_2 = new QGridLayout(groupBoxDetails);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidget = new QTableWidget(groupBoxDetails);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setDefaultSectionSize(210);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_3->setContentsMargins(-1, -1, 7, -1);
        label_3 = new QLabel(groupBoxDetails);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_3);

        spinBoxMR = new QSpinBox(groupBoxDetails);
        spinBoxMR->setObjectName(QString::fromUtf8("spinBoxMR"));
        spinBoxMR->setMaximumSize(QSize(100, 16777215));
        spinBoxMR->setMaximum(1000000000);
        spinBoxMR->setSingleStep(500);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinBoxMR);


        gridLayout_2->addLayout(formLayout_3, 1, 0, 1, 2);

        rb_enEspeces = new QRadioButton(groupBoxDetails);
        rb_enEspeces->setObjectName(QString::fromUtf8("rb_enEspeces"));

        gridLayout_2->addWidget(rb_enEspeces, 2, 0, 1, 1);

        rb_compteBancaire = new QRadioButton(groupBoxDetails);
        rb_compteBancaire->setObjectName(QString::fromUtf8("rb_compteBancaire"));

        gridLayout_2->addWidget(rb_compteBancaire, 2, 1, 1, 1);


        gridLayout_4->addWidget(groupBoxDetails, 1, 3, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DialogRechercherUnClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(37, 16777215));

        horizontalLayout_2->addWidget(label_2);

        comboBoxAction = new QComboBox(DialogRechercherUnClient);
        comboBoxAction->setObjectName(QString::fromUtf8("comboBoxAction"));
        comboBoxAction->setMaximumSize(QSize(140, 16777215));
        comboBoxAction->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_2->addWidget(comboBoxAction);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, horizontalLayout_2);

        btn_OK = new QPushButton(DialogRechercherUnClient);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));
        btn_OK->setMaximumSize(QSize(95, 23));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_OK);


        gridLayout_4->addLayout(formLayout_2, 2, 0, 1, 2);

        btn_details = new QPushButton(DialogRechercherUnClient);
        btn_details->setObjectName(QString::fromUtf8("btn_details"));
        btn_details->setMaximumSize(QSize(75, 23));

        gridLayout_4->addWidget(btn_details, 2, 2, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 9, -1);
        btn_Annuler = new QPushButton(DialogRechercherUnClient);
        btn_Annuler->setObjectName(QString::fromUtf8("btn_Annuler"));
        btn_Annuler->setMaximumSize(QSize(75, 23));
        btn_Annuler->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_Annuler);

        btn_appliquer = new QPushButton(DialogRechercherUnClient);
        btn_appliquer->setObjectName(QString::fromUtf8("btn_appliquer"));
        btn_appliquer->setMaximumSize(QSize(75, 23));
        btn_appliquer->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_appliquer);


        gridLayout_4->addLayout(formLayout, 3, 2, 1, 1);


        retranslateUi(DialogRechercherUnClient);

        QMetaObject::connectSlotsByName(DialogRechercherUnClient);
    } // setupUi

    void retranslateUi(QDialog *DialogRechercherUnClient)
    {
        DialogRechercherUnClient->setWindowTitle(QApplication::translate("DialogRechercherUnClient", "Rechercher un client", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogRechercherUnClient", "Sexe", 0, QApplication::UnicodeUTF8));
        Masculin->setText(QApplication::translate("DialogRechercherUnClient", "Masculin", 0, QApplication::UnicodeUTF8));
        Feminin->setText(QApplication::translate("DialogRechercherUnClient", "F\303\251minin", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogRechercherUnClient", "Nom :", 0, QApplication::UnicodeUTF8));
        rb_clientsCrediteurs->setText(QApplication::translate("DialogRechercherUnClient", "S\303\251lectionner les clients qui doivent", 0, QApplication::UnicodeUTF8));
        groupBoxListeClients->setTitle(QApplication::translate("DialogRechercherUnClient", "Liste de clients", 0, QApplication::UnicodeUTF8));
        groupBoxDetails->setTitle(QApplication::translate("DialogRechercherUnClient", "Locations faites par le client s\303\251lectionn\303\251 (0 non r\303\251gl\303\251e(s))", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DialogRechercherUnClient", "Chambre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DialogRechercherUnClient", "Date d'entr\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DialogRechercherUnClient", "Date de sortie", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DialogRechercherUnClient", "Dur\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DialogRechercherUnClient", "Prix total", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("DialogRechercherUnClient", "Montant pay\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("DialogRechercherUnClient", "Montant restant", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("DialogRechercherUnClient", "NumOccup", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogRechercherUnClient", "Montant de r\303\250glement :", 0, QApplication::UnicodeUTF8));
        rb_enEspeces->setText(QApplication::translate("DialogRechercherUnClient", "en esp\303\250ces", 0, QApplication::UnicodeUTF8));
        rb_compteBancaire->setText(QApplication::translate("DialogRechercherUnClient", "par ch\303\250que", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogRechercherUnClient", "Action :", 0, QApplication::UnicodeUTF8));
        comboBoxAction->clear();
        comboBoxAction->insertItems(0, QStringList()
         << QApplication::translate("DialogRechercherUnClient", "occuper une chambre", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogRechercherUnClient", "r\303\251server une chambre", 0, QApplication::UnicodeUTF8)
        );
        btn_OK->setText(QApplication::translate("DialogRechercherUnClient", "Ex\303\251cuter", 0, QApplication::UnicodeUTF8));
        btn_details->setText(QApplication::translate("DialogRechercherUnClient", "D\303\251tails >>", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("DialogRechercherUnClient", "Fermer", 0, QApplication::UnicodeUTF8));
        btn_appliquer->setText(QApplication::translate("DialogRechercherUnClient", "Appliquer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogRechercherUnClient: public Ui_DialogRechercherUnClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRECHERCHERUNCLIENT_H
