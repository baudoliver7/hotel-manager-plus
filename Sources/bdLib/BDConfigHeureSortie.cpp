#include "BDConfigHeureSortie.h"
#include "ui_BDConfigHeureSortie.h"

BDConfigHeureSortie::BDConfigHeureSortie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDConfigHeureSortie)
{
    ui->setupUi(this);
    afficherHeureLimite();
}

BDConfigHeureSortie::~BDConfigHeureSortie()
{
    delete ui;
}

void BDConfigHeureSortie::changeEvent(QEvent *e)
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

void BDConfigHeureSortie::on_buttonBox_accepted()
{
    HeureLimite hl(1);
    hl.setHeureFinOccupation(ui->timeEditSortie->time());
    hl.setTempsTolerance(ui->spinBoxTpsTol->value());
    hl.setTempsLocAnnulation(ui->spinBoxTpsTol_3->value());
    hl.enregistrer();
}

void BDConfigHeureSortie::afficherHeureLimite()
{
    HeureLimite hl(1);
    ui->timeEditSortie->setTime(hl.heureFinOccupation());
    ui->spinBoxTpsTol->setValue(hl.tempsTolerance());
    ui->spinBoxTpsTol_3->setValue(hl.tempsLocAnnulation());
}
