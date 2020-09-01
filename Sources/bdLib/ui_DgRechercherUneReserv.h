/********************************************************************************
** Form generated from reading UI file 'DgRechercherUneReserv.ui'
**
** Created: Sun 27. Oct 20:00:15 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DGRECHERCHERUNERESERV_H
#define UI_DGRECHERCHERUNERESERV_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DgRechercherUneReserv
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *typesDeChambre;
    QCheckBox *Aujourd_hui;
    QTableWidget *tableWidget;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *btn_annuler;
    QPushButton *btn_supprimer;
    QPushButton *btn_executer;

    void setupUi(QDialog *DgRechercherUneReserv)
    {
        if (DgRechercherUneReserv->objectName().isEmpty())
            DgRechercherUneReserv->setObjectName(QString::fromUtf8("DgRechercherUneReserv"));
        DgRechercherUneReserv->resize(640, 480);
        gridLayout_2 = new QGridLayout(DgRechercherUneReserv);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_2 = new QFrame(DgRechercherUneReserv);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 42));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        typesDeChambre = new QComboBox(frame_2);
        typesDeChambre->setObjectName(QString::fromUtf8("typesDeChambre"));
        typesDeChambre->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(typesDeChambre);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout);


        gridLayout_2->addWidget(frame_2, 0, 0, 1, 1);

        Aujourd_hui = new QCheckBox(DgRechercherUneReserv);
        Aujourd_hui->setObjectName(QString::fromUtf8("Aujourd_hui"));
        Aujourd_hui->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(Aujourd_hui, 1, 0, 1, 1);

        tableWidget = new QTableWidget(DgRechercherUneReserv);
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
        tableWidget->horizontalHeader()->setDefaultSectionSize(200);

        gridLayout_2->addWidget(tableWidget, 2, 0, 1, 1);

        frame = new QFrame(DgRechercherUneReserv);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(250, 16777215));
        frame->setLayoutDirection(Qt::RightToLeft);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_annuler = new QPushButton(frame);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 16777215));
        btn_annuler->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(btn_annuler, 0, 0, 1, 1);

        btn_supprimer = new QPushButton(frame);
        btn_supprimer->setObjectName(QString::fromUtf8("btn_supprimer"));
        btn_supprimer->setMaximumSize(QSize(75, 16777215));
        btn_supprimer->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(btn_supprimer, 0, 1, 1, 1);

        btn_executer = new QPushButton(frame);
        btn_executer->setObjectName(QString::fromUtf8("btn_executer"));
        btn_executer->setMaximumSize(QSize(75, 16777215));
        btn_executer->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(btn_executer, 0, 2, 1, 1);


        gridLayout_2->addWidget(frame, 3, 0, 1, 1);


        retranslateUi(DgRechercherUneReserv);

        QMetaObject::connectSlotsByName(DgRechercherUneReserv);
    } // setupUi

    void retranslateUi(QDialog *DgRechercherUneReserv)
    {
        DgRechercherUneReserv->setWindowTitle(QApplication::translate("DgRechercherUneReserv", "Rechercher une r\303\251servation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DgRechercherUneReserv", "Type de chambre:", 0, QApplication::UnicodeUTF8));
        Aujourd_hui->setText(QApplication::translate("DgRechercherUneReserv", "A ex\303\251cuter aujourd'hui", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DgRechercherUneReserv", "NumeroReserv", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DgRechercherUneReserv", "Chambre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DgRechercherUneReserv", "Date de demande", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DgRechercherUneReserv", "Date d'occupation", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DgRechercherUneReserv", "Dur\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("DgRechercherUneReserv", "Date de sortie", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("DgRechercherUneReserv", "Prix total", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("DgRechercherUneReserv", "Avance", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("DgRechercherUneReserv", "Montant restant", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("DgRechercherUneReserv", "B\303\251n\303\251ficiaire", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("DgRechercherUneReserv", "Fermer", 0, QApplication::UnicodeUTF8));
        btn_supprimer->setText(QApplication::translate("DgRechercherUneReserv", "Annuler", 0, QApplication::UnicodeUTF8));
        btn_executer->setText(QApplication::translate("DgRechercherUneReserv", "Ex\303\251cuter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DgRechercherUneReserv: public Ui_DgRechercherUneReserv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DGRECHERCHERUNERESERV_H
