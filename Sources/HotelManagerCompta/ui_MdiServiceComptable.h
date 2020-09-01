/********************************************************************************
** Form generated from reading UI file 'MdiServiceComptable.ui'
**
** Created: Fri 25. Jan 23:18:57 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDISERVICECOMPTABLE_H
#define UI_MDISERVICECOMPTABLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMdiArea>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MdiServiceComptable
{
public:
    QLabel *label;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QFormLayout *formLayout;
    QLabel *label_logo;
    QLabel *label_horloge;
    QFrame *frame_4;
    QFormLayout *formLayout_2;
    QLabel *labelEnveloppe;
    QFormLayout *formLayout_5;
    QLabel *labelNbMsgNonLus;
    QPushButton *btn_lire;
    QFrame *frame_3;
    QFormLayout *formLayout_3;
    QLabel *label_heureDeConnection;
    QSplitter *splitter;
    QTreeWidget *treeWidget;
    QMdiArea *mdiArea;

    void setupUi(QWidget *MdiServiceComptable)
    {
        if (MdiServiceComptable->objectName().isEmpty())
            MdiServiceComptable->setObjectName(QString::fromUtf8("MdiServiceComptable"));
        MdiServiceComptable->resize(932, 637);
        label = new QLabel(MdiServiceComptable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(469, 361, 16, 16));
        gridLayout_2 = new QGridLayout(MdiServiceComptable);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(0);
        frame = new QFrame(MdiServiceComptable);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 52));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 9, 0);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setMaximumSize(QSize(16777215, 52));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_2);
        formLayout->setContentsMargins(0, 0, 0, 0);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_logo = new QLabel(frame_2);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setMaximumSize(QSize(38, 32));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_logo->setScaledContents(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_logo);

        label_horloge = new QLabel(frame_2);
        label_horloge->setObjectName(QString::fromUtf8("label_horloge"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_horloge);


        gridLayout->addWidget(frame_2, 0, 0, 1, 1);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(75, 0));
        frame_4->setMaximumSize(QSize(100000, 52));
        frame_4->setLayoutDirection(Qt::LeftToRight);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frame_4);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignCenter);
        formLayout_2->setFormAlignment(Qt::AlignCenter);
        labelEnveloppe = new QLabel(frame_4);
        labelEnveloppe->setObjectName(QString::fromUtf8("labelEnveloppe"));
        labelEnveloppe->setMinimumSize(QSize(50, 23));
        labelEnveloppe->setMaximumSize(QSize(50, 23));
        labelEnveloppe->setLayoutDirection(Qt::LeftToRight);
        labelEnveloppe->setPixmap(QPixmap(QString::fromUtf8(":/images/enveloppe.png")));
        labelEnveloppe->setScaledContents(true);
        labelEnveloppe->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelEnveloppe);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_5->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelNbMsgNonLus = new QLabel(frame_4);
        labelNbMsgNonLus->setObjectName(QString::fromUtf8("labelNbMsgNonLus"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, labelNbMsgNonLus);

        btn_lire = new QPushButton(frame_4);
        btn_lire->setObjectName(QString::fromUtf8("btn_lire"));
        btn_lire->setMaximumSize(QSize(120, 23));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, btn_lire);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, formLayout_5);


        gridLayout->addWidget(frame_4, 0, 1, 1, 1);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(0, 0));
        frame_3->setMaximumSize(QSize(16777215, 52));
        frame_3->setLayoutDirection(Qt::LeftToRight);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        formLayout_3 = new QFormLayout(frame_3);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_heureDeConnection = new QLabel(frame_3);
        label_heureDeConnection->setObjectName(QString::fromUtf8("label_heureDeConnection"));
        label_heureDeConnection->setLayoutDirection(Qt::LeftToRight);
        label_heureDeConnection->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_heureDeConnection);


        gridLayout->addWidget(frame_3, 0, 2, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        splitter = new QSplitter(MdiServiceComptable);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeWidget = new QTreeWidget(splitter);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMaximumSize(QSize(283, 16777215));
        splitter->addWidget(treeWidget);
        mdiArea = new QMdiArea(splitter);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        splitter->addWidget(mdiArea);

        gridLayout_2->addWidget(splitter, 1, 0, 1, 1);


        retranslateUi(MdiServiceComptable);

        QMetaObject::connectSlotsByName(MdiServiceComptable);
    } // setupUi

    void retranslateUi(QWidget *MdiServiceComptable)
    {
        MdiServiceComptable->setWindowTitle(QApplication::translate("MdiServiceComptable", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_logo->setText(QString());
        label_horloge->setText(QApplication::translate("MdiServiceComptable", "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, QApplication::UnicodeUTF8));
        labelEnveloppe->setText(QString());
        labelNbMsgNonLus->setText(QApplication::translate("MdiServiceComptable", "TextLabel", 0, QApplication::UnicodeUTF8));
        btn_lire->setText(QApplication::translate("MdiServiceComptable", "Lire", 0, QApplication::UnicodeUTF8));
        label_heureDeConnection->setText(QApplication::translate("MdiServiceComptable", "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MdiServiceComptable", "Mes comptes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MdiServiceComptable: public Ui_MdiServiceComptable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDISERVICECOMPTABLE_H
