#include "BDCompteResultat.h"
#include "ui_BDCompteResultat.h"

BDCompteResultat::BDCompteResultat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDCompteResultat)
{
    ui->setupUi(this);
}

BDCompteResultat::~BDCompteResultat()
{
    delete ui;
}

void BDCompteResultat::changeEvent(QEvent *e)
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
