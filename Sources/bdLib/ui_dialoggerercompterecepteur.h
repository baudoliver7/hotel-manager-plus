/********************************************************************************
** Form generated from reading UI file 'dialoggerercompterecepteur.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGERERCOMPTERECEPTEUR_H
#define UI_DIALOGGERERCOMPTERECEPTEUR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogGererCompteRecepteur
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *rb_administration;
    QRadioButton *comptabilite;
    QRadioButton *reception;
    QRadioButton *rb_restauration;
    QGroupBox *groupBoxNvRecept;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditMatricule;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditNom;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEditResidence;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditPrenoms;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEditContacts;
    QToolButton *btn_contacts;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QRadioButton *Monsieur;
    QRadioButton *Madame;
    QRadioButton *Demoiselle;
    QFormLayout *formLayout;
    QPushButton *btn_enregistrer;
    QPushButton *btn_initialiser;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QSplitter *splitter;
    QPushButton *btn_initialiserCompte;
    QPushButton *btn_supprimer;
    QPushButton *btn_editer;
    QPushButton *btn_suspendre_activer;
    QPushButton *btn_actualiser;
    QPushButton *btn_fermer;

    void setupUi(QDialog *DialogGererCompteRecepteur)
    {
        if (DialogGererCompteRecepteur->objectName().isEmpty())
            DialogGererCompteRecepteur->setObjectName(QString::fromUtf8("DialogGererCompteRecepteur"));
        DialogGererCompteRecepteur->resize(736, 520);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        DialogGererCompteRecepteur->setWindowIcon(icon);
        gridLayout_5 = new QGridLayout(DialogGererCompteRecepteur);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox = new QGroupBox(DialogGererCompteRecepteur);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 52));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        rb_administration = new QRadioButton(groupBox);
        rb_administration->setObjectName(QString::fromUtf8("rb_administration"));

        horizontalLayout_8->addWidget(rb_administration);

        comptabilite = new QRadioButton(groupBox);
        comptabilite->setObjectName(QString::fromUtf8("comptabilite"));

        horizontalLayout_8->addWidget(comptabilite);

        reception = new QRadioButton(groupBox);
        reception->setObjectName(QString::fromUtf8("reception"));

        horizontalLayout_8->addWidget(reception);

        rb_restauration = new QRadioButton(groupBox);
        rb_restauration->setObjectName(QString::fromUtf8("rb_restauration"));

        horizontalLayout_8->addWidget(rb_restauration);


        gridLayout_4->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxNvRecept = new QGroupBox(DialogGererCompteRecepteur);
        groupBoxNvRecept->setObjectName(QString::fromUtf8("groupBoxNvRecept"));
        gridLayout_2 = new QGridLayout(groupBoxNvRecept);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBoxNvRecept);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditMatricule = new QLineEdit(groupBoxNvRecept);
        lineEditMatricule->setObjectName(QString::fromUtf8("lineEditMatricule"));

        horizontalLayout->addWidget(lineEditMatricule);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBoxNvRecept);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditNom = new QLineEdit(groupBoxNvRecept);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));

        horizontalLayout_3->addWidget(lineEditNom);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupBoxNvRecept);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEditResidence = new QLineEdit(groupBoxNvRecept);
        lineEditResidence->setObjectName(QString::fromUtf8("lineEditResidence"));

        horizontalLayout_6->addWidget(lineEditResidence);


        gridLayout_2->addLayout(horizontalLayout_6, 1, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBoxNvRecept);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditPrenoms = new QLineEdit(groupBoxNvRecept);
        lineEditPrenoms->setObjectName(QString::fromUtf8("lineEditPrenoms"));

        horizontalLayout_4->addWidget(lineEditPrenoms);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBoxNvRecept);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEditContacts = new QLineEdit(groupBoxNvRecept);
        lineEditContacts->setObjectName(QString::fromUtf8("lineEditContacts"));
        lineEditContacts->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditContacts->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEditContacts);


        gridLayout_2->addLayout(horizontalLayout_5, 2, 2, 1, 1);

        btn_contacts = new QToolButton(groupBoxNvRecept);
        btn_contacts->setObjectName(QString::fromUtf8("btn_contacts"));

        gridLayout_2->addWidget(btn_contacts, 2, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBoxNvRecept);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        Monsieur = new QRadioButton(groupBoxNvRecept);
        Monsieur->setObjectName(QString::fromUtf8("Monsieur"));

        horizontalLayout_2->addWidget(Monsieur);

        Madame = new QRadioButton(groupBoxNvRecept);
        Madame->setObjectName(QString::fromUtf8("Madame"));

        horizontalLayout_2->addWidget(Madame);

        Demoiselle = new QRadioButton(groupBoxNvRecept);
        Demoiselle->setObjectName(QString::fromUtf8("Demoiselle"));

        horizontalLayout_2->addWidget(Demoiselle);


        gridLayout_2->addLayout(horizontalLayout_2, 3, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setHorizontalSpacing(3);
        formLayout->setContentsMargins(-1, -1, 4, -1);
        btn_enregistrer = new QPushButton(groupBoxNvRecept);
        btn_enregistrer->setObjectName(QString::fromUtf8("btn_enregistrer"));
        btn_enregistrer->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_enregistrer);

        btn_initialiser = new QPushButton(groupBoxNvRecept);
        btn_initialiser->setObjectName(QString::fromUtf8("btn_initialiser"));
        btn_initialiser->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_initialiser);


        gridLayout_2->addLayout(formLayout, 4, 2, 1, 1);


        gridLayout_5->addWidget(groupBoxNvRecept, 1, 0, 1, 2);

        groupBox_2 = new QGroupBox(DialogGererCompteRecepteur);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget = new QTabWidget(groupBox_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
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
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        splitter = new QSplitter(tab);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setLayoutDirection(Qt::RightToLeft);
        splitter->setOrientation(Qt::Horizontal);
        btn_initialiserCompte = new QPushButton(splitter);
        btn_initialiserCompte->setObjectName(QString::fromUtf8("btn_initialiserCompte"));
        btn_initialiserCompte->setMaximumSize(QSize(79, 23));
        btn_initialiserCompte->setLayoutDirection(Qt::RightToLeft);
        splitter->addWidget(btn_initialiserCompte);
        btn_supprimer = new QPushButton(splitter);
        btn_supprimer->setObjectName(QString::fromUtf8("btn_supprimer"));
        btn_supprimer->setMaximumSize(QSize(79, 23));
        btn_supprimer->setLayoutDirection(Qt::RightToLeft);
        splitter->addWidget(btn_supprimer);
        btn_editer = new QPushButton(splitter);
        btn_editer->setObjectName(QString::fromUtf8("btn_editer"));
        btn_editer->setMaximumSize(QSize(79, 23));
        btn_editer->setLayoutDirection(Qt::RightToLeft);
        splitter->addWidget(btn_editer);
        btn_suspendre_activer = new QPushButton(splitter);
        btn_suspendre_activer->setObjectName(QString::fromUtf8("btn_suspendre_activer"));
        btn_suspendre_activer->setMaximumSize(QSize(97, 23));
        btn_suspendre_activer->setLayoutDirection(Qt::RightToLeft);
        splitter->addWidget(btn_suspendre_activer);
        btn_actualiser = new QPushButton(splitter);
        btn_actualiser->setObjectName(QString::fromUtf8("btn_actualiser"));
        btn_actualiser->setMaximumSize(QSize(79, 23));
        btn_actualiser->setLayoutDirection(Qt::RightToLeft);
        splitter->addWidget(btn_actualiser);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_3->addWidget(tabWidget, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 2, 0, 1, 2);

        btn_fermer = new QPushButton(DialogGererCompteRecepteur);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_5->addWidget(btn_fermer, 3, 1, 1, 1);


        retranslateUi(DialogGererCompteRecepteur);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogGererCompteRecepteur);
    } // setupUi

    void retranslateUi(QDialog *DialogGererCompteRecepteur)
    {
        DialogGererCompteRecepteur->setWindowTitle(QApplication::translate("DialogGererCompteRecepteur", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogGererCompteRecepteur", "Service ", 0, QApplication::UnicodeUTF8));
        rb_administration->setText(QApplication::translate("DialogGererCompteRecepteur", "Administration", 0, QApplication::UnicodeUTF8));
        comptabilite->setText(QApplication::translate("DialogGererCompteRecepteur", "Comptabilit\303\251", 0, QApplication::UnicodeUTF8));
        reception->setText(QApplication::translate("DialogGererCompteRecepteur", "R\303\251ception", 0, QApplication::UnicodeUTF8));
        rb_restauration->setText(QApplication::translate("DialogGererCompteRecepteur", "Restauration", 0, QApplication::UnicodeUTF8));
        groupBoxNvRecept->setTitle(QApplication::translate("DialogGererCompteRecepteur", "Enregistrer un compte", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogGererCompteRecepteur", "Matricule:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogGererCompteRecepteur", "Nom:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DialogGererCompteRecepteur", "R\303\251sidence:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogGererCompteRecepteur", "Pr\303\251nom(s):", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogGererCompteRecepteur", "Contacts:", 0, QApplication::UnicodeUTF8));
        btn_contacts->setText(QApplication::translate("DialogGererCompteRecepteur", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogGererCompteRecepteur", "Sexe pr\303\251cis:", 0, QApplication::UnicodeUTF8));
        Monsieur->setText(QApplication::translate("DialogGererCompteRecepteur", "M.", 0, QApplication::UnicodeUTF8));
        Madame->setText(QApplication::translate("DialogGererCompteRecepteur", "Mme", 0, QApplication::UnicodeUTF8));
        Demoiselle->setText(QApplication::translate("DialogGererCompteRecepteur", "Mlle", 0, QApplication::UnicodeUTF8));
        btn_enregistrer->setText(QApplication::translate("DialogGererCompteRecepteur", "Enregistrer", 0, QApplication::UnicodeUTF8));
        btn_initialiser->setText(QApplication::translate("DialogGererCompteRecepteur", "Initialiser", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DialogGererCompteRecepteur", "Comptes du service s\303\251lectionn\303\251", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DialogGererCompteRecepteur", "Statut", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DialogGererCompteRecepteur", "Matricule", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DialogGererCompteRecepteur", "Sexe pr\303\251cis", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DialogGererCompteRecepteur", "Nom", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DialogGererCompteRecepteur", "Pr\303\251noms", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("DialogGererCompteRecepteur", "Cel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("DialogGererCompteRecepteur", "Tel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("DialogGererCompteRecepteur", "E-mail", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("DialogGererCompteRecepteur", "Bo\303\256te postale", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("DialogGererCompteRecepteur", "R\303\251sidence", 0, QApplication::UnicodeUTF8));
        btn_initialiserCompte->setText(QApplication::translate("DialogGererCompteRecepteur", "Initialiser", 0, QApplication::UnicodeUTF8));
        btn_supprimer->setText(QApplication::translate("DialogGererCompteRecepteur", "Supprimer", 0, QApplication::UnicodeUTF8));
        btn_editer->setText(QApplication::translate("DialogGererCompteRecepteur", "Editer", 0, QApplication::UnicodeUTF8));
        btn_suspendre_activer->setText(QApplication::translate("DialogGererCompteRecepteur", "Suspendre/Activer", 0, QApplication::UnicodeUTF8));
        btn_actualiser->setText(QApplication::translate("DialogGererCompteRecepteur", "Actualiser", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DialogGererCompteRecepteur", "Comptes", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("DialogGererCompteRecepteur", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogGererCompteRecepteur: public Ui_DialogGererCompteRecepteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGERERCOMPTERECEPTEUR_H
