#include "BDRestituerAuClient.h"
#include "ui_BDRestituerAuClient.h"

BDRestituerAuClient::BDRestituerAuClient(int somme, bool avance, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDRestituerAuClient)
{
    ui->setupUi(this);

    ui->lineEditAvance->setText(QString::number(somme));
    ui->spinBoxSommeARestituer->setMaximum(somme);
    ui->spinBoxSommeARestituer->setMinimum(0);
    ui->spinBoxSommeARestituer->setValue(0);
    on_spinBoxSommeARestituer_valueChanged(0);

    if(!avance)
        ui->labelSomme->setText("Montant versé :");
}

BDRestituerAuClient::~BDRestituerAuClient()
{
    delete ui;
}

void BDRestituerAuClient::changeEvent(QEvent *e)
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

void BDRestituerAuClient::on_btn_ok_clicked()
{
    accept();
}

void BDRestituerAuClient::on_btn_annuler_clicked()
{
    reject();
}

void BDRestituerAuClient::on_spinBoxSommeARestituer_valueChanged(int value)
{
    ui->btn_ok->setEnabled(value != 0);
}

int BDRestituerAuClient::sommeARestituer()
{
   return ui->spinBoxSommeARestituer->value();
}
