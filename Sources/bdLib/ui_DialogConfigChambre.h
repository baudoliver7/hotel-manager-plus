/********************************************************************************
** Form generated from reading UI file 'DialogConfigChambre.ui'
**
** Created: Sun 27. Oct 20:00:17 2013
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogConfigChambre
{
public:
    QGridLayout *gridLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxTypeChambre;
    QCheckBox *checkBoxTypeChDispo;
    QPushButton *btn_ajouterUnTypeChambre;
    QLabel *labelNbChambres;
    QTableView *tableViewChambres;
    QSplitter *splitter;
    QPushButton *btn_supprimer;
    QPushButton *btn_mettreHS;
    QPushButton *btn_modifier;
    QPushButton *btn_ajouter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxTypeClient;
    QPushButton *btn_ajouterUnTypeClient;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBoxProfileClient;
    QPushButton *btn_ajouterUnTypeProfile;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QTableWidget *tableWidgetTarifsChambres;
    QPushButton *btn_appliquer;
    QPushButton *btn_fermer;

    void setupUi(QDialog *DialogConfigChambre)
    {
        if (DialogConfigChambre->objectName().isEmpty())
            DialogConfigChambre->setObjectName(QString::fromUtf8("DialogConfigChambre"));
        DialogConfigChambre->resize(1041, 585);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        DialogConfigChambre->setWindowIcon(icon);
        gridLayout_6 = new QGridLayout(DialogConfigChambre);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tabWidget = new QTabWidget(DialogConfigChambre);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(400, 16777215));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBoxTypeChambre = new QComboBox(groupBox_3);
        comboBoxTypeChambre->setObjectName(QString::fromUtf8("comboBoxTypeChambre"));
        comboBoxTypeChambre->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(comboBoxTypeChambre);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        checkBoxTypeChDispo = new QCheckBox(groupBox_3);
        checkBoxTypeChDispo->setObjectName(QString::fromUtf8("checkBoxTypeChDispo"));
        checkBoxTypeChDispo->setMaximumSize(QSize(110, 23));

        gridLayout->addWidget(checkBoxTypeChDispo, 0, 1, 1, 1);

        btn_ajouterUnTypeChambre = new QPushButton(groupBox_3);
        btn_ajouterUnTypeChambre->setObjectName(QString::fromUtf8("btn_ajouterUnTypeChambre"));
        btn_ajouterUnTypeChambre->setMinimumSize(QSize(90, 0));
        btn_ajouterUnTypeChambre->setMaximumSize(QSize(95, 16777215));

        gridLayout->addWidget(btn_ajouterUnTypeChambre, 0, 2, 1, 1);

        labelNbChambres = new QLabel(groupBox_3);
        labelNbChambres->setObjectName(QString::fromUtf8("labelNbChambres"));

        gridLayout->addWidget(labelNbChambres, 1, 0, 1, 2);

        tableViewChambres = new QTableView(groupBox_3);
        tableViewChambres->setObjectName(QString::fromUtf8("tableViewChambres"));
        tableViewChambres->setMinimumSize(QSize(240, 0));
        tableViewChambres->setMaximumSize(QSize(16777215, 16777215));
        tableViewChambres->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewChambres->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewChambres->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewChambres->horizontalHeader()->setMinimumSectionSize(110);
        tableViewChambres->horizontalHeader()->setStretchLastSection(true);
        tableViewChambres->verticalHeader()->setCascadingSectionResizes(true);
        tableViewChambres->verticalHeader()->setDefaultSectionSize(21);

        gridLayout->addWidget(tableViewChambres, 2, 0, 1, 3);

        splitter = new QSplitter(groupBox_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setLayoutDirection(Qt::RightToLeft);
        splitter->setOrientation(Qt::Horizontal);
        btn_supprimer = new QPushButton(splitter);
        btn_supprimer->setObjectName(QString::fromUtf8("btn_supprimer"));
        btn_supprimer->setMaximumSize(QSize(75, 23));
        btn_supprimer->setLayoutDirection(Qt::RightToLeft);
        splitter->addWidget(btn_supprimer);
        btn_mettreHS = new QPushButton(splitter);
        btn_mettreHS->setObjectName(QString::fromUtf8("btn_mettreHS"));
        btn_mettreHS->setMaximumSize(QSize(100, 23));
        btn_mettreHS->setLayoutDirection(Qt::LeftToRight);
        splitter->addWidget(btn_mettreHS);
        btn_modifier = new QPushButton(splitter);
        btn_modifier->setObjectName(QString::fromUtf8("btn_modifier"));
        btn_modifier->setMaximumSize(QSize(75, 23));
        btn_modifier->setLayoutDirection(Qt::LeftToRight);
        splitter->addWidget(btn_modifier);
        btn_ajouter = new QPushButton(splitter);
        btn_ajouter->setObjectName(QString::fromUtf8("btn_ajouter"));
        btn_ajouter->setMaximumSize(QSize(75, 23));
        btn_ajouter->setLayoutDirection(Qt::LeftToRight);
        splitter->addWidget(btn_ajouter);

        gridLayout->addWidget(splitter, 3, 0, 1, 3);


        gridLayout_2->addWidget(groupBox_3, 0, 0, 2, 1);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(355, 0));
        groupBox->setMaximumSize(QSize(425, 111));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBoxTypeClient = new QComboBox(groupBox);
        comboBoxTypeClient->setObjectName(QString::fromUtf8("comboBoxTypeClient"));
        comboBoxTypeClient->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_2->addWidget(comboBoxTypeClient);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        btn_ajouterUnTypeClient = new QPushButton(groupBox);
        btn_ajouterUnTypeClient->setObjectName(QString::fromUtf8("btn_ajouterUnTypeClient"));
        btn_ajouterUnTypeClient->setMinimumSize(QSize(90, 0));
        btn_ajouterUnTypeClient->setMaximumSize(QSize(95, 16777215));

        gridLayout_3->addWidget(btn_ajouterUnTypeClient, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBoxProfileClient = new QComboBox(groupBox);
        comboBoxProfileClient->setObjectName(QString::fromUtf8("comboBoxProfileClient"));
        comboBoxProfileClient->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_3->addWidget(comboBoxProfileClient);


        gridLayout_3->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        btn_ajouterUnTypeProfile = new QPushButton(groupBox);
        btn_ajouterUnTypeProfile->setObjectName(QString::fromUtf8("btn_ajouterUnTypeProfile"));
        btn_ajouterUnTypeProfile->setMinimumSize(QSize(90, 0));
        btn_ajouterUnTypeProfile->setMaximumSize(QSize(95, 16777215));

        gridLayout_3->addWidget(btn_ajouterUnTypeProfile, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tableWidgetTarifsChambres = new QTableWidget(groupBox_4);
        if (tableWidgetTarifsChambres->columnCount() < 1)
            tableWidgetTarifsChambres->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetTarifsChambres->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidgetTarifsChambres->rowCount() < 1)
            tableWidgetTarifsChambres->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetTarifsChambres->setVerticalHeaderItem(0, __qtablewidgetitem1);
        tableWidgetTarifsChambres->setObjectName(QString::fromUtf8("tableWidgetTarifsChambres"));
        tableWidgetTarifsChambres->verticalHeader()->setDefaultSectionSize(20);

        gridLayout_5->addWidget(tableWidgetTarifsChambres, 0, 0, 1, 1);

        btn_appliquer = new QPushButton(groupBox_4);
        btn_appliquer->setObjectName(QString::fromUtf8("btn_appliquer"));
        btn_appliquer->setMaximumSize(QSize(75, 23));
        btn_appliquer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_5->addWidget(btn_appliquer, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_6->addWidget(tabWidget, 0, 0, 1, 1);

        btn_fermer = new QPushButton(DialogConfigChambre);
        btn_fermer->setObjectName(QString::fromUtf8("btn_fermer"));
        btn_fermer->setMaximumSize(QSize(75, 23));
        btn_fermer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_6->addWidget(btn_fermer, 1, 0, 1, 1);


        retranslateUi(DialogConfigChambre);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogConfigChambre);
    } // setupUi

    void retranslateUi(QDialog *DialogConfigChambre)
    {
        DialogConfigChambre->setWindowTitle(QApplication::translate("DialogConfigChambre", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("DialogConfigChambre", "Chambres", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogConfigChambre", "Type de chambre :", 0, QApplication::UnicodeUTF8));
        checkBoxTypeChDispo->setText(QApplication::translate("DialogConfigChambre", "disponible", 0, QApplication::UnicodeUTF8));
        btn_ajouterUnTypeChambre->setText(QApplication::translate("DialogConfigChambre", "Ajouter un type", 0, QApplication::UnicodeUTF8));
        labelNbChambres->setText(QApplication::translate("DialogConfigChambre", "00 chambres", 0, QApplication::UnicodeUTF8));
        btn_supprimer->setText(QApplication::translate("DialogConfigChambre", "Supprimer", 0, QApplication::UnicodeUTF8));
        btn_mettreHS->setText(QApplication::translate("DialogConfigChambre", "Mettre HS", 0, QApplication::UnicodeUTF8));
        btn_modifier->setText(QApplication::translate("DialogConfigChambre", "Modifiier", 0, QApplication::UnicodeUTF8));
        btn_ajouter->setText(QApplication::translate("DialogConfigChambre", "Ajouter", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogConfigChambre", "Configurer les types de client", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogConfigChambre", "Type de client :", 0, QApplication::UnicodeUTF8));
        btn_ajouterUnTypeClient->setText(QApplication::translate("DialogConfigChambre", "Ajouter un type", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogConfigChambre", "Profile de client :", 0, QApplication::UnicodeUTF8));
        btn_ajouterUnTypeProfile->setText(QApplication::translate("DialogConfigChambre", "Ajouter un profile", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("DialogConfigChambre", "Tarifs des chambres", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetTarifsChambres->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DialogConfigChambre", "Chambre ventil\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetTarifsChambres->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("DialogConfigChambre", "Adolescent", 0, QApplication::UnicodeUTF8));
        btn_appliquer->setText(QApplication::translate("DialogConfigChambre", "Appliquer", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DialogConfigChambre", "Caract\303\251ristiques", 0, QApplication::UnicodeUTF8));
        btn_fermer->setText(QApplication::translate("DialogConfigChambre", "Fermer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogConfigChambre: public Ui_DialogConfigChambre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONFIGCHAMBRE_H
