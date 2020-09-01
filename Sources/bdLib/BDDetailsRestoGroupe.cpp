#include "BDDetailsRestoGroupe.h"
#include "ui_BDDetailsRestoGroupe.h"

BDDetailsRestoGroupe::BDDetailsRestoGroupe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDDetailsRestoGroupe)
{
    ui->setupUi(this);
}

BDDetailsRestoGroupe::~BDDetailsRestoGroupe()
{
    delete ui;
}

void BDDetailsRestoGroupe::changeEvent(QEvent *e)
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
