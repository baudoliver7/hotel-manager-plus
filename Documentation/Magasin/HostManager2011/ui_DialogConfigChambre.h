/********************************************************************************
** Form generated from reading UI file 'DialogConfigChambre.ui'
**
** Created: Mon 20. Jun 16:30:34 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONFIGCHAMBRE_H
#define UI_DIALOGCONFIGCHAMBRE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogConfigChambre
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QPushButton *btn_supprimer;
    QPushButton *btn_modifier;
    QPushButton *btn_ajouter;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QPushButton *btn_appliquer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxTypeTarif;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBoxTarifNormal;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBoxTarifPriviligie;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *spinBoxTarifFidelite;
    QPushButton *btn_fermer;

    void setupUi(QDialog *DialogConfigChambre)
    {
        if (DialogConfigChambre->objectName().isEmpty())
            DialogConfigChambre->setObjectName(QString::fromUtf8("DialogConfigChambre"));
        DialogConfigChambre->resize(506, 334);
        tabWidget = new QTabWidget(DialogConfigChambre);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 481, 271));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 201, 191));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setStretchLastSection(true);
        btn_supprimer = new QPushButton(tab);
        btn_supprimer->setObjectName(QString::fromUtf8("btn_supprimer"));
        btn_supprimer->setGeometry(QRect(150, 210, 75, 23));
        btn_modifier = new QPushButton(tab);
        btn_modifier->setObjectName(QString::fromUtf8("btn_modifier"));
        btn_modifier->setGeometry(QRect(230, 210, 75, 23));
        btn_ajouter = new QPushButton(tab);
        btn_ajouter->setObjectName(QString::fromUtf8("btn_ajouter"));
        btn_ajouter->setGeometry(QRect(310, 210, 75, 23));
        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(440, 70, 30, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        btn_appliquer = new QPushButton(tab);
        btn_appliquer->setObjectName(QString::fromUtf8("btn_appliquer"));
        btn_appliquer->setGeometry(QRect(390, 210, 75, 23));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(220, 40, 217, 110));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBoxTypeTarif = new QComboBox(widget);
        comboBoxTypeTarif->setObjectName(QString::fromUtf8("comboBoxTypeTarif"));

        horizontalLayout->addWidget(comboBoxTypeTarif);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBoxTarifNormal = new QSpinBox(widget);
        spinBoxTarifNormal->setObjectName(QString::fromUtf8("spinBoxTarifNormal"));
        spinBoxTarifNormal->setMaximum(10000000);
        spinBoxTarifNormal->setSingleStep(500);

        horizontalLayout_2->addWidget(spinBoxTarifNormal);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBoxTarifPriviligie = new QSpinBox(widget);
        spinBoxTarifPriviligie->setObjectName(QString::fromUtf8("spinBoxTarifPriviligie"));
        spinBoxTarifPriviligie->setMaximum(1000000);
        spinBoxTarifPriviligie->setSingleStep(500);

        horizontalLayout_3->addWidget(spinBoxTarifPriviligie);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        spinBoxTarifFidelite = new QSpinBox(widget);
        spinBoxTarifFidelite->setObjectName(QString::fromUtf8("spinBoxTarifFidelite"));
        spinBoxTarifFidelite->setMaximum(10000000);
        spinBoxTarifFidelite->setSingleStep(500);

        horizontalLayout_4->addWidget(spinBoxTarifFidelite);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout);

        tabWidget->addTab(tab, QString());
        btn_fermer = new QPushButton(DialogConfigChambre);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setGeometry(QRect(400, 300, 75, 23));

        retranslateUi(DialogConfigChambre);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogConfigChambre);
    } // setupUi

    void retranslateUi(QDialog *DialogConfigChambre)
    {
        DialogConfigChambre->setWindowTitle(QApplication::translate("DialogConfigChambre", "Dialog", 0, QApplication::UnicodeUTF8));
        btn_supprimer->setText(QApplication::translate("DialogConfigChambre", "Supprimer", 0, QApplication::UnicodeUTF8));
        btn_modifier->setText(QApplication::translate("DialogConfigChambre", "Modifiier", 0, QApplication::UnicodeUTF8));
        btn_ajouter->setText(QApplication::translate("DialogConfigChambre", "Ajouter", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogConfigChambre", "F CFA", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DialogConfigChambre", "F CFA", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DialogConfigChambre", "F CFA", 0, QApplication::UnicodeUTF8));
        btn_appliquer->setText(QApplication::translate("DialogConfigChambre", "Appliquer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogConfigChambre", "Type de chambre :", 0, QApplication::UnicodeUTF8));
        comboBoxTypeTarif->clear();
        comboBoxTypeTarif->insertItems(0, QStringList()
         << QApplication::translate("DialogConfigChambre", "Chambre ventil\303\251e", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogConfigChambre", "Chambre climatis\303\251e", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DialogConfigChambre", "Suite", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("DialogConfigChambre", "Tarif normal :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogConfigChambre", "Tarif priviligi\303\251 :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogConfigChambre", "Tarif de fid\303\251lit\303\251 :", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DialogConfigChambre", "Caract\303\251ristiques", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("DialogConfigChambre", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogConfigChambre: public Ui_DialogConfigChambre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONFIGCHAMBRE_H
