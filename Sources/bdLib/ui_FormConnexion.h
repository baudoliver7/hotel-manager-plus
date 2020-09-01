/********************************************************************************
** Form generated from reading UI file 'FormConnexion.ui'
**
** Created: Sun 27. Oct 20:00:19 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCONNEXION_H
#define UI_FORMCONNEXION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormConnexion
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *labelLogo;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEditPseudo;
    QLabel *label_3;
    QLineEdit *lineEditPassword;
    QPushButton *btn_valider;
    QLabel *label_4;

    void setupUi(QWidget *FormConnexion)
    {
        if (FormConnexion->objectName().isEmpty())
            FormConnexion->setObjectName(QString::fromUtf8("FormConnexion"));
        FormConnexion->resize(629, 563);
        FormConnexion->setAutoFillBackground(false);
        FormConnexion->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(FormConnexion);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(FormConnexion);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(377, 401));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        labelLogo = new QLabel(frame);
        labelLogo->setObjectName(QString::fromUtf8("labelLogo"));
        labelLogo->setMaximumSize(QSize(351, 261));
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        labelLogo->setScaledContents(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelLogo);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(236, 95));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEditPseudo = new QLineEdit(frame_2);
        lineEditPseudo->setObjectName(QString::fromUtf8("lineEditPseudo"));

        gridLayout->addWidget(lineEditPseudo, 0, 1, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEditPassword = new QLineEdit(frame_2);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditPassword, 1, 1, 1, 1);

        btn_valider = new QPushButton(frame_2);
        btn_valider->setObjectName(QString::fromUtf8("btn_valider"));
        btn_valider->setMaximumSize(QSize(75, 23));
        btn_valider->setLayoutDirection(Qt::RightToLeft);
        btn_valider->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(btn_valider, 2, 1, 1, 1);


        formLayout->setWidget(1, QFormLayout::LabelRole, frame_2);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(305, 16));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(FormConnexion);

        QMetaObject::connectSlotsByName(FormConnexion);
    } // setupUi

    void retranslateUi(QWidget *FormConnexion)
    {
        FormConnexion->setWindowTitle(QApplication::translate("FormConnexion", "Form", 0, QApplication::UnicodeUTF8));
        labelLogo->setText(QString());
        label_2->setText(QApplication::translate("FormConnexion", "Pseudo :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("FormConnexion", "Mote de passe :", 0, QApplication::UnicodeUTF8));
        btn_valider->setText(QApplication::translate("FormConnexion", "Valider", 0, QApplication::UnicodeUTF8));
        btn_valider->setShortcut(QApplication::translate("FormConnexion", "Return", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FormConnexion", "Copyright (c) 2011 - 2013 OURA Olivier B., tous droits r\303\251serv\303\251s", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FormConnexion: public Ui_FormConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCONNEXION_H
