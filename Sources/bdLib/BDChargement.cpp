#include "BDChargement.h"
#include "ui_BDChargement.h"

BDChargement::BDChargement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDChargement)
{
    ui->setupUi(this);
}

BDChargement::~BDChargement()
{
    delete ui;
}

void BDChargement::changeEvent(QEvent *e)
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
