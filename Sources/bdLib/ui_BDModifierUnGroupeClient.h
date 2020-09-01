/********************************************************************************
** Form generated from reading UI file 'BDModifierUnGroupeClient.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDMODIFIERUNGROUPECLIENT_H
#define UI_BDMODIFIERUNGROUPECLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_BDModifierUnGroupeClient
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidgetGroupesEnCours;
    QPushButton *btn_terminer;
    QGroupBox *groupBoxMembres;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidgetMembres;
    QFormLayout *formLayout;
    QPushButton *btn_ajouter;
    QPushButton *btn_retirer;
    QFormLayout *formLayout_2;
    QPushButton *btn_choisir;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDModifierUnGroupeClient)
    {
        if (BDModifierUnGroupeClient->objectName().isEmpty())
            BDModifierUnGroupeClient->setObjectName(QString::fromUtf8("BDModifierUnGroupeClient"));
        BDModifierUnGroupeClient->resize(557, 525);
        gridLayout_3 = new QGridLayout(BDModifierUnGroupeClient);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(BDModifierUnGroupeClient);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeWidgetGroupesEnCours = new QTreeWidget(groupBox);
        treeWidgetGroupesEnCours->setObjectName(QString::fromUtf8("treeWidgetGroupesEnCours"));
        treeWidgetGroupesEnCours->header()->setDefaultSectionSize(170);
        treeWidgetGroupesEnCours->header()->setStretchLastSection(false);

        gridLayout->addWidget(treeWidgetGroupesEnCours, 0, 0, 1, 1);

        btn_terminer = new QPushButton(groupBox);
        btn_terminer->setObjectName(QString::fromUtf8("btn_terminer"));
        btn_terminer->setMaximumSize(QSize(75, 16777215));
        btn_terminer->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(btn_terminer, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxMembres = new QGroupBox(BDModifierUnGroupeClient);
        groupBoxMembres->setObjectName(QString::fromUtf8("groupBoxMembres"));
        gridLayout_2 = new QGridLayout(groupBoxMembres);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        treeWidgetMembres = new QTreeWidget(groupBoxMembres);
        treeWidgetMembres->setObjectName(QString::fromUtf8("treeWidgetMembres"));
        treeWidgetMembres->header()->setDefaultSectionSize(170);
        treeWidgetMembres->header()->setStretchLastSection(false);

        gridLayout_2->addWidget(treeWidgetMembres, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 10, -1);
        btn_ajouter = new QPushButton(groupBoxMembres);
        btn_ajouter->setObjectName(QString::fromUtf8("btn_ajouter"));
        btn_ajouter->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_ajouter);

        btn_retirer = new QPushButton(groupBoxMembres);
        btn_retirer->setObjectName(QString::fromUtf8("btn_retirer"));
        btn_retirer->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_retirer);


        gridLayout_2->addLayout(formLayout, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxMembres, 1, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_2->setContentsMargins(-1, -1, 7, -1);
        btn_choisir = new QPushButton(BDModifierUnGroupeClient);
        btn_choisir->setObjectName(QString::fromUtf8("btn_choisir"));
        btn_choisir->setMaximumSize(QSize(75, 23));
        btn_choisir->setLayoutDirection(Qt::RightToLeft);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, btn_choisir);

        btn_fermer = new QPushButton(BDModifierUnGroupeClient);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_fermer);


        gridLayout_3->addLayout(formLayout_2, 2, 0, 1, 1);


        retranslateUi(BDModifierUnGroupeClient);

        QMetaObject::connectSlotsByName(BDModifierUnGroupeClient);
    } // setupUi

    void retranslateUi(QDialog *BDModifierUnGroupeClient)
    {
        BDModifierUnGroupeClient->setWindowTitle(QApplication::translate("BDModifierUnGroupeClient", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDModifierUnGroupeClient", "Groupes en cours", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetGroupesEnCours->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("BDModifierUnGroupeClient", "Nb pers enreg", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("BDModifierUnGroupeClient", "Responsable", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("BDModifierUnGroupeClient", "Libell\303\251", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("BDModifierUnGroupeClient", "IdGroupe", 0, QApplication::UnicodeUTF8));
        btn_terminer->setText(QApplication::translate("BDModifierUnGroupeClient", "Terminer", 0, QApplication::UnicodeUTF8));
        groupBoxMembres->setTitle(QApplication::translate("BDModifierUnGroupeClient", "Membres du groupe (nb membres)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetMembres->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("BDModifierUnGroupeClient", "Log\303\251", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("BDModifierUnGroupeClient", "Client", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("BDModifierUnGroupeClient", "IdClient", 0, QApplication::UnicodeUTF8));
        btn_ajouter->setText(QApplication::translate("BDModifierUnGroupeClient", "Ajouter", 0, QApplication::UnicodeUTF8));
        btn_retirer->setText(QApplication::translate("BDModifierUnGroupeClient", "Retirer", 0, QApplication::UnicodeUTF8));
        btn_choisir->setText(QApplication::translate("BDModifierUnGroupeClient", "Choisir", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDModifierUnGroupeClient", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDModifierUnGroupeClient: public Ui_BDModifierUnGroupeClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDMODIFIERUNGROUPECLIENT_H
