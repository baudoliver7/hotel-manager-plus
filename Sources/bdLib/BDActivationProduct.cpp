#include "BDActivationProduct.h"
#include "ui_BDActivationProduct.h"

BDActivationProduct::BDActivationProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDActivationProduct)
{
    ui->setupUi(this);
}

BDActivationProduct::~BDActivationProduct()
{
    delete ui;
}

void BDActivationProduct::changeEvent(QEvent *e)
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
