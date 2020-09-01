#include "BDNomDuServeur.h"
#include "ui_BDNomDuServeur.h"

BDNomDuServeur::BDNomDuServeur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDNomDuServeur)
{
    ui->setupUi(this);
}

BDNomDuServeur::~BDNomDuServeur()
{
    delete ui;
}

void BDNomDuServeur::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QString BDNomDuServeur::nomDuServeur()const
{
    return ui->lineEditNomDuServeur->text();
}
