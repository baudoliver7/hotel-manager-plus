/********************************************************************************
** Form generated from reading UI file 'BDApropos.ui'
**
** Created: Sun 27. Oct 20:00:16 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDAPROPOS_H
#define UI_BDAPROPOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_BDApropos
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *textEdit;
    QLabel *label_9;

    void setupUi(QDialog *BDApropos)
    {
        if (BDApropos->objectName().isEmpty())
            BDApropos->setObjectName(QString::fromUtf8("BDApropos"));
        BDApropos->resize(603, 385);
        BDApropos->setMinimumSize(QSize(603, 385));
        BDApropos->setMaximumSize(QSize(603, 385));
        label = new QLabel(BDApropos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-40, 0, 291, 221));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(BDApropos);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 10, 261, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(18);
        font.setBold(false);
        font.setWeight(50);
        label_2->setFont(font);
        label_3 = new QLabel(BDApropos);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 50, 61, 16));
        label_4 = new QLabel(BDApropos);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(240, 80, 181, 16));
        label_5 = new QLabel(BDApropos);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(240, 110, 311, 16));
        label_6 = new QLabel(BDApropos);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(240, 140, 351, 31));
        label_6->setTextFormat(Qt::RichText);
        label_6->setWordWrap(true);
        label_7 = new QLabel(BDApropos);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(240, 170, 351, 31));
        label_7->setTextFormat(Qt::RichText);
        label_7->setWordWrap(true);
        label_8 = new QLabel(BDApropos);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 230, 311, 16));
        textEdit = new QTextEdit(BDApropos);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 250, 581, 101));
        textEdit->setReadOnly(true);
        label_9 = new QLabel(BDApropos);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(240, 190, 351, 31));
        label_9->setTextFormat(Qt::RichText);
        label_9->setWordWrap(true);

        retranslateUi(BDApropos);

        QMetaObject::connectSlotsByName(BDApropos);
    } // setupUi

    void retranslateUi(QDialog *BDApropos)
    {
        BDApropos->setWindowTitle(QApplication::translate("BDApropos", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QApplication::translate("BDApropos", "Hotel Manager Plus", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BDApropos", "Version 1.5", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BDApropos", "Cr\303\251\303\251 le 29 Ao\303\273t 2012 \303\240 20:45:28", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BDApropos", "Copyright (c) 2011-2013 OURA Olivier B., tous droits r\303\251serv\303\251s.", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BDApropos", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Auteur</span><span style=\" font-size:8pt;\"> : M. OURA Olivier B., dipl\303\264m\303\251 d'Etat en Ing\303\251nierie de Conception   de l'Ecole Sup\303\251rieure d'Industrie (ESI, INP-HB Yamoussoukro)                          </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BDApropos", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">E-mail</span><span style=\" font-size:8pt;\"> : baudolivier.oura@gmail.com / baudolivier@yahoo.fr</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BDApropos", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Remerciements \303\240 :</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("BDApropos", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">M. Davy GOSSAN, Enseignant-chercheur \303\240 l'INP-HB</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">M. DOH  Landry, DESS en Logistique</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">M. TIA Deti Prince V., Ing\303\251nieur en Marke"
                        "ting</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">M. NADIO Nadio Jean Apollon, Ing\303\251nieur en Informatique</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">et \303\240 tous ceux qui ont particip\303\251 de pr\303\250s ou de loin \303\240 la conception et \303\240 la r\303\251alisation de ce progiciel.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BDApropos", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">T\303\251l\303\251phone</span><span style=\" font-size:8pt;\"> : +225 44 34 86 57 / +225 61 26 74 00</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDApropos: public Ui_BDApropos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDAPROPOS_H
