#include "BDConfigComptaRecept.h"
#include "ui_BDConfigComptaRecept.h"

BDConfigComptaRecept::BDConfigComptaRecept(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDConfigComptaRecept)
{
    ui->setupUi(this);
}

BDConfigComptaRecept::~BDConfigComptaRecept()
{
    delete ui;
}

void BDConfigComptaRecept::changeEvent(QEvent *e)
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
