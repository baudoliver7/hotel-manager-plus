/********************************************************************************
** Form generated from reading UI file 'BDChoisirUnClientDeGroupeSimple.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDCHOISIRUNCLIENTDEGROUPESIMPLE_H
#define UI_BDCHOISIRUNCLIENTDEGROUPESIMPLE_H

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
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BDChoisirUnClientDeGroupeSimple
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTreeWidget *treeWidgetGroupesEnCours;
    QGroupBox *groupBoxMembres;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidgetMembres;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_8;
    QFormLayout *formLayout_7;
    QLabel *label_3;
    QLineEdit *lineEditClientSelectionne;
    QPushButton *btn_details;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBoxTypeDeClient;
    QComboBox *comboBoxProfile;
    QFormLayout *formLayout_2;
    QPushButton *btn_choisir;
    QPushButton *btn_fermer;

    void setupUi(QDialog *BDChoisirUnClientDeGroupeSimple)
    {
        if (BDChoisirUnClientDeGroupeSimple->objectName().isEmpty())
            BDChoisirUnClientDeGroupeSimple->setObjectName(QString::fromUtf8("BDChoisirUnClientDeGroupeSimple"));
        BDChoisirUnClientDeGroupeSimple->resize(527, 503);
        gridLayout_4 = new QGridLayout(BDChoisirUnClientDeGroupeSimple);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(BDChoisirUnClientDeGroupeSimple);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeWidgetGroupesEnCours = new QTreeWidget(groupBox);
        treeWidgetGroupesEnCours->setObjectName(QString::fromUtf8("treeWidgetGroupesEnCours"));
        treeWidgetGroupesEnCours->header()->setDefaultSectionSize(170);
        treeWidgetGroupesEnCours->header()->setStretchLastSection(true);

        gridLayout->addWidget(treeWidgetGroupesEnCours, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxMembres = new QGroupBox(BDChoisirUnClientDeGroupeSimple);
        groupBoxMembres->setObjectName(QString::fromUtf8("groupBoxMembres"));
        gridLayout_2 = new QGridLayout(groupBoxMembres);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        treeWidgetMembres = new QTreeWidget(groupBoxMembres);
        treeWidgetMembres->setObjectName(QString::fromUtf8("treeWidgetMembres"));
        treeWidgetMembres->header()->setDefaultSectionSize(170);
        treeWidgetMembres->header()->setStretchLastSection(true);

        gridLayout_2->addWidget(treeWidgetMembres, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBoxMembres, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(BDChoisirUnClientDeGroupeSimple);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        formLayout_8 = new QFormLayout();
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        formLayout_7 = new QFormLayout();
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_3);

        lineEditClientSelectionne = new QLineEdit(groupBox_2);
        lineEditClientSelectionne->setObjectName(QString::fromUtf8("lineEditClientSelectionne"));
        lineEditClientSelectionne->setMinimumSize(QSize(335, 0));
        lineEditClientSelectionne->setMaximumSize(QSize(335, 16777215));
        lineEditClientSelectionne->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditClientSelectionne->setReadOnly(true);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, lineEditClientSelectionne);


        formLayout_8->setLayout(0, QFormLayout::LabelRole, formLayout_7);

        btn_details = new QPushButton(groupBox_2);
        btn_details->setObjectName(QString::fromUtf8("btn_details"));
        btn_details->setMaximumSize(QSize(75, 23));

        formLayout_8->setWidget(0, QFormLayout::FieldRole, btn_details);


        gridLayout_3->addLayout(formLayout_8, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        comboBoxTypeDeClient = new QComboBox(groupBox_2);
        comboBoxTypeDeClient->setObjectName(QString::fromUtf8("comboBoxTypeDeClient"));
        comboBoxTypeDeClient->setMaximumSize(QSize(140, 16777215));

        verticalLayout_2->addWidget(comboBoxTypeDeClient);

        comboBoxProfile = new QComboBox(groupBox_2);
        comboBoxProfile->setObjectName(QString::fromUtf8("comboBoxProfile"));
        comboBoxProfile->setMaximumSize(QSize(140, 16777215));

        verticalLayout_2->addWidget(comboBoxProfile);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);


        gridLayout_3->addLayout(formLayout, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 2, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_2->setContentsMargins(-1, -1, 7, -1);
        btn_choisir = new QPushButton(BDChoisirUnClientDeGroupeSimple);
        btn_choisir->setObjectName(QString::fromUtf8("btn_choisir"));
        btn_choisir->setMaximumSize(QSize(75, 23));
        btn_choisir->setLayoutDirection(Qt::RightToLeft);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, btn_choisir);

        btn_fermer = new QPushButton(BDChoisirUnClientDeGroupeSimple);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, btn_fermer);


        gridLayout_4->addLayout(formLayout_2, 3, 0, 1, 1);


        retranslateUi(BDChoisirUnClientDeGroupeSimple);

        QMetaObject::connectSlotsByName(BDChoisirUnClientDeGroupeSimple);
    } // setupUi

    void retranslateUi(QDialog *BDChoisirUnClientDeGroupeSimple)
    {
        BDChoisirUnClientDeGroupeSimple->setWindowTitle(QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Groupes en cours", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetGroupesEnCours->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Nombre de personnes", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Responsable", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Libell\303\251", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("BDChoisirUnClientDeGroupeSimple", "IdGroupe", 0, QApplication::UnicodeUTF8));
        groupBoxMembres->setTitle(QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Membres du groupe (nb membres)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetMembres->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Log\303\251", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Client", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("BDChoisirUnClientDeGroupeSimple", "IdClient", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Client choisi", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Nom complet :", 0, QApplication::UnicodeUTF8));
        btn_details->setText(QApplication::translate("BDChoisirUnClientDeGroupeSimple", "D\303\251tails", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Type de client :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Profile :", 0, QApplication::UnicodeUTF8));
        btn_choisir->setText(QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Choisir", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("BDChoisirUnClientDeGroupeSimple", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDChoisirUnClientDeGroupeSimple: public Ui_BDChoisirUnClientDeGroupeSimple {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDCHOISIRUNCLIENTDEGROUPESIMPLE_H
