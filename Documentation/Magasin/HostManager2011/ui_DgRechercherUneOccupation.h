/********************************************************************************
** Form generated from reading UI file 'DgRechercherUneOccupation.ui'
**
** Created: Tue 27. Sep 14:35:11 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DGRECHERCHERUNEOCCUPATION_H
#define UI_DGRECHERCHERUNEOCCUPATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DgRechercherUneOccupation
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *typesDeChambre;
    QTableWidget *tableWidget;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *btn_annuler;
    QPushButton *btn_liberer;

    void setupUi(QDialog *DgRechercherUneOccupation)
    {
        if (DgRechercherUneOccupation->objectName().isEmpty())
            DgRechercherUneOccupation->setObjectName(QString::fromUtf8("DgRechercherUneOccupation"));
        DgRechercherUneOccupation->resize(640, 480);
        DgRechercherUneOccupation->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(DgRechercherUneOccupation);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_2 = new QFrame(DgRechercherUneOccupation);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(230, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        typesDeChambre = new QComboBox(frame_2);
        typesDeChambre->setObjectName(QString::fromUtf8("typesDeChambre"));
        typesDeChambre->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_2->addWidget(typesDeChambre, 0, 1, 1, 1);


        verticalLayout->addWidget(frame_2);

        tableWidget = new QTableWidget(DgRechercherUneOccupation);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);

        verticalLayout->addWidget(tableWidget);

        frame = new QFrame(DgRechercherUneOccupation);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(160, 16777215));
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

        btn_liberer = new QPushButton(frame);
        btn_liberer->setObjectName(QString::fromUtf8("btn_liberer"));
        btn_liberer->setMaximumSize(QSize(75, 16777215));
        btn_liberer->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(btn_liberer, 0, 1, 1, 1);


        verticalLayout->addWidget(frame);


        retranslateUi(DgRechercherUneOccupation);

        QMetaObject::connectSlotsByName(DgRechercherUneOccupation);
    } // setupUi

    void retranslateUi(QDialog *DgRechercherUneOccupation)
    {
        DgRechercherUneOccupation->setWindowTitle(QApplication::translate("DgRechercherUneOccupation", "Rechercher une occupation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DgRechercherUneOccupation", "Type de chambre:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DgRechercherUneOccupation", "NumeroReserv", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DgRechercherUneOccupation", "Chambre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DgRechercherUneOccupation", "Date d'entr\303\251e", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DgRechercherUneOccupation", "Dur\303\251e en jours", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DgRechercherUneOccupation", "Date de sortie", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("DgRechercherUneOccupation", "Occupant", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("DgRechercherUneOccupation", "Fermer", 0, QApplication::UnicodeUTF8));
        btn_liberer->setText(QApplication::translate("DgRechercherUneOccupation", "Lib\303\251rer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DgRechercherUneOccupation: public Ui_DgRechercherUneOccupation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DGRECHERCHERUNEOCCUPATION_H
