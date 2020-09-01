/********************************************************************************
** Form generated from reading UI file 'DialogRechercherUnClient.ui'
**
** Created: Tue 27. Sep 14:51:02 2011
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
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogRechercherUnClient
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *Masculin;
    QRadioButton *Feminin;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditNom;
    QTableView *tableViewClients;
    QSplitter *splitter_2;
    QLabel *label_2;
    QComboBox *comboBoxAction;
    QSplitter *splitter;
    QPushButton *btn_OK;
    QPushButton *btn_Annuler;

    void setupUi(QDialog *DialogRechercherUnClient)
    {
        if (DialogRechercherUnClient->objectName().isEmpty())
            DialogRechercherUnClient->setObjectName(QString::fromUtf8("DialogRechercherUnClient"));
        DialogRechercherUnClient->resize(600, 373);
        gridLayout_2 = new QGridLayout(DialogRechercherUnClient);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
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


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DialogRechercherUnClient);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditNom = new QLineEdit(DialogRechercherUnClient);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));

        horizontalLayout->addWidget(lineEditNom);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        tableViewClients = new QTableView(DialogRechercherUnClient);
        tableViewClients->setObjectName(QString::fromUtf8("tableViewClients"));
        tableViewClients->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewClients->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout_2->addWidget(tableViewClients, 1, 0, 1, 3);

        splitter_2 = new QSplitter(DialogRechercherUnClient);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(37, 16777215));
        splitter_2->addWidget(label_2);
        comboBoxAction = new QComboBox(splitter_2);
        comboBoxAction->setObjectName(QString::fromUtf8("comboBoxAction"));
        comboBoxAction->setMaximumSize(QSize(140, 16777215));
        comboBoxAction->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        splitter_2->addWidget(comboBoxAction);

        gridLayout_2->addWidget(splitter_2, 2, 0, 1, 2);

        splitter = new QSplitter(DialogRechercherUnClient);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        btn_OK = new QPushButton(splitter);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));
        btn_OK->setMaximumSize(QSize(95, 23));
        splitter->addWidget(btn_OK);
        btn_Annuler = new QPushButton(splitter);
        btn_Annuler->setObjectName(QString::fromUtf8("btn_Annuler"));
        btn_Annuler->setMaximumSize(QSize(95, 23));
        splitter->addWidget(btn_Annuler);

        gridLayout_2->addWidget(splitter, 2, 2, 1, 1);


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
        label_2->setText(QApplication::translate("DialogRechercherUnClient", "Action :", 0, QApplication::UnicodeUTF8));
        comboBoxAction->clear();
        comboBoxAction->insertItems(0, QStringList()
         << QApplication::translate("DialogRechercherUnClient", "occuper une chambre", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogRechercherUnClient", "r\303\251server une chambre", 0, QApplication::UnicodeUTF8)
        );
        btn_OK->setText(QApplication::translate("DialogRechercherUnClient", "Ex\303\251cuter action", 0, QApplication::UnicodeUTF8));
        btn_Annuler->setText(QApplication::translate("DialogRechercherUnClient", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogRechercherUnClient: public Ui_DialogRechercherUnClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRECHERCHERUNCLIENT_H
