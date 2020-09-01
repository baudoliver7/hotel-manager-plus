/********************************************************************************
** Form generated from reading UI file 'BDConfigurerMenuResto.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCONFIGURERMENURESTO_H
#define UI_BDCONFIGURERMENURESTO_H

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
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_BDConfigurerMenuResto
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QComboBox *comboBoxCategorie;
    QPushButton *btn_nvelleCategorie;
    QLabel *label;
    QLineEdit *lineEditLibelle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBoxPrixUnitaire;
    QPushButton *btn_ajouter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableView *tableViewMenu;
    QPushButton *btn_supprimer;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDConfigurerMenuResto)
    {
        if (BDConfigurerMenuResto->objectName().isEmpty())
            BDConfigurerMenuResto->setObjectName(QString::fromUtf8("BDConfigurerMenuResto"));
        BDConfigurerMenuResto->resize(469, 484);
        gridLayout_2 = new QGridLayout(BDConfigurerMenuResto);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(BDConfigurerMenuResto);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        comboBoxCategorie = new QComboBox(BDConfigurerMenuResto);
        comboBoxCategorie->setObjectName(QString::fromUtf8("comboBoxCategorie"));
        comboBoxCategorie->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_2->addWidget(comboBoxCategorie, 0, 1, 1, 2);

        btn_nvelleCategorie = new QPushButton(BDConfigurerMenuResto);
        btn_nvelleCategorie->setObjectName(QString::fromUtf8("btn_nvelleCategorie"));
        btn_nvelleCategorie->setMaximumSize(QSize(111, 23));

        gridLayout_2->addWidget(btn_nvelleCategorie, 0, 3, 1, 1);

        label = new QLabel(BDConfigurerMenuResto);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        lineEditLibelle = new QLineEdit(BDConfigurerMenuResto);
        lineEditLibelle->setObjectName(QString::fromUtf8("lineEditLibelle"));

        gridLayout_2->addWidget(lineEditLibelle, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(BDConfigurerMenuResto);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBoxPrixUnitaire = new QSpinBox(BDConfigurerMenuResto);
        spinBoxPrixUnitaire->setObjectName(QString::fromUtf8("spinBoxPrixUnitaire"));
        spinBoxPrixUnitaire->setMaximum(100000000);
        spinBoxPrixUnitaire->setSingleStep(1000);

        horizontalLayout_2->addWidget(spinBoxPrixUnitaire);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 2, 1, 2);

        btn_ajouter = new QPushButton(BDConfigurerMenuResto);
        btn_ajouter->setObjectName(QString::fromUtf8("btn_ajouter"));
        btn_ajouter->setMaximumSize(QSize(75, 23));

        gridLayout_2->addWidget(btn_ajouter, 1, 4, 1, 1);

        groupBox = new QGroupBox(BDConfigurerMenuResto);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableViewMenu = new QTableView(groupBox);
        tableViewMenu->setObjectName(QString::fromUtf8("tableViewMenu"));
        tableViewMenu->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewMenu->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewMenu->horizontalHeader()->setCascadingSectionResizes(true);
        tableViewMenu->horizontalHeader()->setDefaultSectionSize(200);
        tableViewMenu->horizontalHeader()->setHighlightSections(true);
        tableViewMenu->horizontalHeader()->setStretchLastSection(false);
        tableViewMenu->verticalHeader()->setDefaultSectionSize(25);

        gridLayout->addWidget(tableViewMenu, 0, 0, 1, 1);

        btn_supprimer = new QPushButton(groupBox);
        btn_supprimer->setObjectName(QString::fromUtf8("btn_supprimer"));
        btn_supprimer->setMaximumSize(QSize(75, 23));
        btn_supprimer->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(btn_supprimer, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 5);

        btn_fermer = new QPushButton(BDConfigurerMenuResto);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));

        gridLayout_2->addWidget(btn_fermer, 3, 4, 1, 1);


        retranslateUi(BDConfigurerMenuResto);

        QMetaObject::connectSlotsByName(BDConfigurerMenuResto);
    } // setupUi

    void retranslateUi(QDialog *BDConfigurerMenuResto)
    {
        BDConfigurerMenuResto->setWindowTitle(QApplication::translate("BDConfigurerMenuResto", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDConfigurerMenuResto", "Cat\303\251gorie :", 0, QApplication::UnicodeUTF8));
        btn_nvelleCategorie->setText(QApplication::translate("BDConfigurerMenuResto", "Nouvelle cat\303\251gorie", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDConfigurerMenuResto", "Libell\303\251 :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDConfigurerMenuResto", "Prix unitaire :", 0, QApplication::UnicodeUTF8));
        btn_ajouter->setText(QApplication::translate("BDConfigurerMenuResto", "Ajouter", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDConfigurerMenuResto", "Menus", 0, QApplication::UnicodeUTF8));
        btn_supprimer->setText(QApplication::translate("BDConfigurerMenuResto", "Supprimer", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDConfigurerMenuResto", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDConfigurerMenuResto: public Ui_BDConfigurerMenuResto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCONFIGURERMENURESTO_H
