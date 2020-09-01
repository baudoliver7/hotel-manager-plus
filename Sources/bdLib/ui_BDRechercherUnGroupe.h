/********************************************************************************
** Form generated from reading UI file 'BDRechercherUnGroupe.ui'
**
** Created: Sun 27. Oct 20:00:18 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDRECHERCHERUNGROUPE_H
#define UI_BDRECHERCHERUNGROUPE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_BDRechercherUnGroupe
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *rb_en_cours;
    QFormLayout *formLayout_2;
    QRadioButton *rb_tout;
    QFormLayout *formLayout;
    QLabel *labelNomGroupe;
    QLineEdit *lineEditNomGroupe;
    QPushButton *btn_rechercherGroupe;
    QTreeWidget *treeWidgetGroupes;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *btn_imprimerHotel;
    QPushButton *btn_imprimerBar;
    QPushButton *btn_imprimerResto;
    QPushButton *btn_contacts;
    QFormLayout *formLayout_3;
    QPushButton *btn_choisir;
    QPushButton *btn_annuler;

    void setupUi(QDialog *BDRechercherUnGroupe)
    {
        if (BDRechercherUnGroupe->objectName().isEmpty())
            BDRechercherUnGroupe->setObjectName(QString::fromUtf8("BDRechercherUnGroupe"));
        BDRechercherUnGroupe->resize(835, 334);
        gridLayout_3 = new QGridLayout(BDRechercherUnGroupe);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(BDRechercherUnGroupe);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rb_en_cours = new QRadioButton(groupBox);
        rb_en_cours->setObjectName(QString::fromUtf8("rb_en_cours"));

        gridLayout_2->addWidget(rb_en_cours, 0, 0, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        rb_tout = new QRadioButton(groupBox);
        rb_tout->setObjectName(QString::fromUtf8("rb_tout"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rb_tout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelNomGroupe = new QLabel(groupBox);
        labelNomGroupe->setObjectName(QString::fromUtf8("labelNomGroupe"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNomGroupe);

        lineEditNomGroupe = new QLineEdit(groupBox);
        lineEditNomGroupe->setObjectName(QString::fromUtf8("lineEditNomGroupe"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditNomGroupe);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, formLayout);


        gridLayout_2->addLayout(formLayout_2, 0, 1, 1, 1);

        btn_rechercherGroupe = new QPushButton(groupBox);
        btn_rechercherGroupe->setObjectName(QString::fromUtf8("btn_rechercherGroupe"));
        btn_rechercherGroupe->setMaximumSize(QSize(50, 23));

        gridLayout_2->addWidget(btn_rechercherGroupe, 0, 2, 1, 1);

        treeWidgetGroupes = new QTreeWidget(groupBox);
        treeWidgetGroupes->setObjectName(QString::fromUtf8("treeWidgetGroupes"));
        treeWidgetGroupes->header()->setDefaultSectionSize(130);
        treeWidgetGroupes->header()->setStretchLastSection(false);

        gridLayout_2->addWidget(treeWidgetGroupes, 1, 0, 1, 3);

        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(500, 16777215));
        frame->setLayoutDirection(Qt::RightToLeft);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_imprimerHotel = new QPushButton(frame);
        btn_imprimerHotel->setObjectName(QString::fromUtf8("btn_imprimerHotel"));
        btn_imprimerHotel->setMinimumSize(QSize(130, 0));
        btn_imprimerHotel->setMaximumSize(QSize(130, 23));

        gridLayout->addWidget(btn_imprimerHotel, 0, 0, 1, 1);

        btn_imprimerBar = new QPushButton(frame);
        btn_imprimerBar->setObjectName(QString::fromUtf8("btn_imprimerBar"));
        btn_imprimerBar->setMinimumSize(QSize(130, 0));
        btn_imprimerBar->setMaximumSize(QSize(130, 23));

        gridLayout->addWidget(btn_imprimerBar, 0, 1, 1, 1);

        btn_imprimerResto = new QPushButton(frame);
        btn_imprimerResto->setObjectName(QString::fromUtf8("btn_imprimerResto"));
        btn_imprimerResto->setMinimumSize(QSize(130, 0));
        btn_imprimerResto->setMaximumSize(QSize(130, 23));

        gridLayout->addWidget(btn_imprimerResto, 0, 2, 1, 1);

        btn_contacts = new QPushButton(frame);
        btn_contacts->setObjectName(QString::fromUtf8("btn_contacts"));
        btn_contacts->setMaximumSize(QSize(75, 23));

        gridLayout->addWidget(btn_contacts, 0, 3, 1, 1);


        gridLayout_2->addWidget(frame, 2, 1, 1, 2);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        formLayout_3->setContentsMargins(-1, -1, 7, -1);
        btn_choisir = new QPushButton(BDRechercherUnGroupe);
        btn_choisir->setObjectName(QString::fromUtf8("btn_choisir"));
        btn_choisir->setMaximumSize(QSize(75, 23));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, btn_choisir);

        btn_annuler = new QPushButton(BDRechercherUnGroupe);
        btn_annuler->setObjectName(QString::fromUtf8("btn_annuler"));
        btn_annuler->setMaximumSize(QSize(75, 23));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, btn_annuler);


        gridLayout_3->addLayout(formLayout_3, 1, 0, 1, 1);


        retranslateUi(BDRechercherUnGroupe);

        QMetaObject::connectSlotsByName(BDRechercherUnGroupe);
    } // setupUi

    void retranslateUi(QDialog *BDRechercherUnGroupe)
    {
        BDRechercherUnGroupe->setWindowTitle(QApplication::translate("BDRechercherUnGroupe", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BDRechercherUnGroupe", "Groupes", 0, QApplication::UnicodeUTF8));
        rb_en_cours->setText(QApplication::translate("BDRechercherUnGroupe", "En cours", 0, QApplication::UnicodeUTF8));
        rb_tout->setText(QApplication::translate("BDRechercherUnGroupe", "Recherche sp\303\251cifique  :", 0, QApplication::UnicodeUTF8));
        labelNomGroupe->setText(QApplication::translate("BDRechercherUnGroupe", "Nom du groupe :", 0, QApplication::UnicodeUTF8));
        btn_rechercherGroupe->setText(QApplication::translate("BDRechercherUnGroupe", "OK", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetGroupes->headerItem();
        ___qtreewidgetitem->setText(12, QApplication::translate("BDRechercherUnGroupe", "Montant restant", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(11, QApplication::translate("BDRechercherUnGroupe", "Montant pay\303\251", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(10, QApplication::translate("BDRechercherUnGroupe", "Montant total", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(9, QApplication::translate("BDRechercherUnGroupe", "Avance", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(8, QApplication::translate("BDRechercherUnGroupe", "Dur\303\251e", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(7, QApplication::translate("BDRechercherUnGroupe", "Date d'arriv\303\251e", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(6, QApplication::translate("BDRechercherUnGroupe", "Type de chambre maj", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(5, QApplication::translate("BDRechercherUnGroupe", "Nb pers enregistr\303\251es", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("BDRechercherUnGroupe", "Nb pers pr\303\251vues", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("BDRechercherUnGroupe", "Type de client", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("BDRechercherUnGroupe", "Responsable", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("BDRechercherUnGroupe", "Groupe", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("BDRechercherUnGroupe", "IdGroupe", 0, QApplication::UnicodeUTF8));
        btn_imprimerHotel->setText(QApplication::translate("BDRechercherUnGroupe", "Imprimer facture h\303\264tel", 0, QApplication::UnicodeUTF8));
        btn_imprimerBar->setText(QApplication::translate("BDRechercherUnGroupe", "Imprimer facture Bar", 0, QApplication::UnicodeUTF8));
        btn_imprimerResto->setText(QApplication::translate("BDRechercherUnGroupe", "Imprimer facture Resto", 0, QApplication::UnicodeUTF8));
        btn_contacts->setText(QApplication::translate("BDRechercherUnGroupe", "Voir contacts", 0, QApplication::UnicodeUTF8));
        btn_choisir->setText(QApplication::translate("BDRechercherUnGroupe", "Choisir", 0, QApplication::UnicodeUTF8));
        btn_annuler->setText(QApplication::translate("BDRechercherUnGroupe", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BDRechercherUnGroupe: public Ui_BDRechercherUnGroupe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDRECHERCHERUNGROUPE_H
