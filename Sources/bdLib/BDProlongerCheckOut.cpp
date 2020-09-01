#include "BDProlongerCheckOut.h"
#include "ui_BDProlongerCheckOut.h"

BDProlongerCheckOut::BDProlongerCheckOut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDProlongerCheckOut)
{
    ui->setupUi(this);

    ui->btn_ok->setEnabled(false);
}

BDProlongerCheckOut::~BDProlongerCheckOut()
{
    delete ui;
}

void BDProlongerCheckOut::changeEvent(QEvent *e)
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

void BDProlongerCheckOut::on_btn_annuler_clicked()
{
    reject();
}

void BDProlongerCheckOut::on_btn_ok_clicked()
{
    accept();
}

int BDProlongerCheckOut::nbDeJoursAAjouter()const
{
    return ui->spinBox->value();
}

void BDProlongerCheckOut::on_spinBox_valueChanged(int value)
{
    ui->btn_ok->setEnabled(value != 0);
}
