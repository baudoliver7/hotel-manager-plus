/********************************************************************************
** Form generated from reading UI file 'BDMessagerie.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDMESSAGERIE_H
#define UI_BDMESSAGERIE_H

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
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BDMessagerie
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextEdit *msgEcrits;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxPseudo;
    QFormLayout *formLayout;
    QPushButton *btn_initialiser;
    QPushButton *btn_envoyer;
    QGroupBox *groupBoxMessage;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTextEdit *msgNonLus;
    QPushButton *btn_effacerMsgRecus;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QTextEdit *historique;
    QPushButton *btn_effacer;

    void setupUi(QDialog *BDMessagerie)
    {
        if (BDMessagerie->objectName().isEmpty())
            BDMessagerie->setObjectName(QString::fromUtf8("BDMessagerie"));
        BDMessagerie->setWindowModality(Qt::WindowModal);
        BDMessagerie->resize(419, 401);
        BDMessagerie->setMinimumSize(QSize(419, 401));
        BDMessagerie->setMaximumSize(QSize(419, 401));
        gridLayout_4 = new QGridLayout(BDMessagerie);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(BDMessagerie);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 111));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        msgEcrits = new QTextEdit(groupBox);
        msgEcrits->setObjectName(QString::fromUtf8("msgEcrits"));
        QFont font;
        font.setPointSize(10);
        msgEcrits->setFont(font);

        gridLayout->addWidget(msgEcrits, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBoxPseudo = new QComboBox(groupBox);
        comboBoxPseudo->setObjectName(QString::fromUtf8("comboBoxPseudo"));

        horizontalLayout->addWidget(comboBoxPseudo);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout->setContentsMargins(-1, -1, 6, -1);
        btn_initialiser = new QPushButton(groupBox);
        btn_initialiser->setObjectName(QString::fromUtf8("btn_initialiser"));
        btn_initialiser->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_initialiser);

        btn_envoyer = new QPushButton(groupBox);
        btn_envoyer->setObjectName(QString::fromUtf8("btn_envoyer"));
        btn_envoyer->setMaximumSize(QSize(75, 23));

        formLayout->setWidget(0, QFormLayout::FieldRole, btn_envoyer);


        gridLayout->addLayout(formLayout, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxMessage = new QGroupBox(BDMessagerie);
        groupBoxMessage->setObjectName(QString::fromUtf8("groupBoxMessage"));
        gridLayout_3 = new QGridLayout(groupBoxMessage);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget = new QTabWidget(groupBoxMessage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        msgNonLus = new QTextEdit(tab);
        msgNonLus->setObjectName(QString::fromUtf8("msgNonLus"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        msgNonLus->setFont(font1);
        msgNonLus->setReadOnly(true);

        gridLayout_2->addWidget(msgNonLus, 0, 0, 1, 1);

        btn_effacerMsgRecus = new QPushButton(tab);
        btn_effacerMsgRecus->setObjectName(QString::fromUtf8("btn_effacerMsgRecus"));
        btn_effacerMsgRecus->setMaximumSize(QSize(75, 23));
        btn_effacerMsgRecus->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(btn_effacerMsgRecus, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        historique = new QTextEdit(tab_2);
        historique->setObjectName(QString::fromUtf8("historique"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(10);
        historique->setFont(font2);
        historique->setReadOnly(true);

        gridLayout_5->addWidget(historique, 0, 0, 1, 1);

        btn_effacer = new QPushButton(tab_2);
        btn_effacer->setObjectName(QString::fromUtf8("btn_effacer"));
        btn_effacer->setMaximumSize(QSize(75, 23));
        btn_effacer->setLayoutDirection(Qt::RightToLeft);

        gridLayout_5->addWidget(btn_effacer, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBoxMessage, 1, 0, 1, 1);


        retranslateUi(BDMessagerie);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BDMessagerie);
    } // setupUi

    void retranslateUi(QDialog *BDMessagerie)
    {
        BDMessagerie->setWindowTitle(QApplication::translate("BDMessagerie", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDMessagerie", "Ecrire un message (255 caract\303\250res au maximum)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BDMessagerie", "Destinataire:", 0, QApplication::UnicodeUTF8));
        btn_initialiser->setText(QApplication::translate("BDMessagerie", "Effacer", 0, QApplication::UnicodeUTF8));
        btn_envoyer->setText(QApplication::translate("BDMessagerie", "Envoyer", 0, QApplication::UnicodeUTF8));
        groupBoxMessage->setTitle(QApplication::translate("BDMessagerie", "Messages", 0, QApplication::UnicodeUTF8));
        btn_effacerMsgRecus->setText(QApplication::translate("BDMessagerie", "Effacer", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("BDMessagerie", "Messages re\303\247us", 0, QApplication::UnicodeUTF8));
        btn_effacer->setText(QApplication::translate("BDMessagerie", "Effacer", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("BDMessagerie", "Messages envoy\303\251s", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDMessagerie: public Ui_BDMessagerie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDMESSAGERIE_H
