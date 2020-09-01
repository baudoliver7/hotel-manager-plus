#include "bdconfigtaux.h"
#include "ui_bdconfigtaux.h"

BDConfigTaux::BDConfigTaux(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDConfigTaux)
{
    ui->setupUi(this);
    afficherTaux();
}

BDConfigTaux::~BDConfigTaux()
{
    delete ui;
}

void BDConfigTaux::changeEvent(QEvent *e)
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

void BDConfigTaux::afficherTaux()
{
    taux ttva(taux::TVA);
    taux ttt(taux::TT);

    ui->doubleSpinBoxTTVA->setValue(ttva.valeur());
    ui->doubleSpinBoxTTT->setValue(ttt.valeur());
}

void BDConfigTaux::on_buttonBox_accepted()
{
    taux ttva(taux::TVA);
    ttva.setValeur(ui->doubleSpinBoxTTVA->value());
    ttva.enregistrer();

    taux ttt(taux::TT);
    ttt.setValeur(ui->doubleSpinBoxTTT->value());
    ttt.enregistrer();
}
