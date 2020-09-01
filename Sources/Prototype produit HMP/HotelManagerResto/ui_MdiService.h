/********************************************************************************
** Form generated from reading UI file 'MdiService.ui'
**
** Created: Mon 4. Jun 10:52:39 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDISERVICE_H
#define UI_MDISERVICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MdiService
{
public:
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QLabel *label_heureDeConnection;
    QFrame *frame_2;
    QGridLayout *gridLayout_11;
    QLabel *label_logo;
    QLabel *label_horloge;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *labelEnveloppe;
    QFormLayout *formLayout_5;
    QLabel *labelNbMsgNonLus;
    QPushButton *btn_lire;

    void setupUi(QWidget *MdiService)
    {
        if (MdiService->objectName().isEmpty())
            MdiService->setObjectName(QString::fromUtf8("MdiService"));
        MdiService->resize(927, 356);
        frame_3 = new QFrame(MdiService);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(514, 10, 410, 52));
        frame_3->setMinimumSize(QSize(0, 52));
        frame_3->setMaximumSize(QSize(16777215, 52));
        frame_3->setLayoutDirection(Qt::RightToLeft);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_heureDeConnection = new QLabel(frame_3);
        label_heureDeConnection->setObjectName(QString::fromUtf8("label_heureDeConnection"));

        gridLayout_7->addWidget(label_heureDeConnection, 0, 0, 1, 1);

        frame_2 = new QFrame(MdiService);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 10, 211, 52));
        frame_2->setMinimumSize(QSize(0, 52));
        frame_2->setMaximumSize(QSize(283, 52));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_2);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_logo = new QLabel(frame_2);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setMaximumSize(QSize(38, 32));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label_logo->setScaledContents(true);

        gridLayout_11->addWidget(label_logo, 0, 0, 1, 1);

        label_horloge = new QLabel(frame_2);
        label_horloge->setObjectName(QString::fromUtf8("label_horloge"));

        gridLayout_11->addWidget(label_horloge, 0, 1, 1, 1);

        frame = new QFrame(MdiService);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(227, 10, 281, 52));
        frame->setMinimumSize(QSize(75, 52));
        frame->setMaximumSize(QSize(100000, 52));
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelEnveloppe = new QLabel(frame);
        labelEnveloppe->setObjectName(QString::fromUtf8("labelEnveloppe"));
        labelEnveloppe->setMaximumSize(QSize(50, 23));
        labelEnveloppe->setLayoutDirection(Qt::LeftToRight);
        labelEnveloppe->setPixmap(QPixmap(QString::fromUtf8(":/images/enveloppe.png")));
        labelEnveloppe->setScaledContents(true);
        labelEnveloppe->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelEnveloppe, 0, 0, 1, 1);

        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_5->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelNbMsgNonLus = new QLabel(frame);
        labelNbMsgNonLus->setObjectName(QString::fromUtf8("labelNbMsgNonLus"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, labelNbMsgNonLus);

        btn_lire = new QPushButton(frame);
        btn_lire->setObjectName(QString::fromUtf8("btn_lire"));
        btn_lire->setMaximumSize(QSize(120, 23));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, btn_lire);


        gridLayout->addLayout(formLayout_5, 0, 1, 1, 1);


        retranslateUi(MdiService);

        QMetaObject::connectSlotsByName(MdiService);
    } // setupUi

    void retranslateUi(QWidget *MdiService)
    {
        MdiService->setWindowTitle(QApplication::translate("MdiService", "Form", 0, QApplication::UnicodeUTF8));
        label_heureDeConnection->setText(QApplication::translate("MdiService", "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj", 0, QApplication::UnicodeUTF8));
        label_logo->setText(QString());
        label_horloge->setText(QApplication::translate("MdiService", "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX", 0, QApplication::UnicodeUTF8));
        labelEnveloppe->setText(QString());
        labelNbMsgNonLus->setText(QApplication::translate("MdiService", "TextLabel", 0, QApplication::UnicodeUTF8));
        btn_lire->setText(QApplication::translate("MdiService", "Lire", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MdiService: public Ui_MdiService {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDISERVICE_H
