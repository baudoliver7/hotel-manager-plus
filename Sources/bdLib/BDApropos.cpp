#include "BDApropos.h"
#include "ui_BDApropos.h"

BDApropos::BDApropos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDApropos)
{
    ui->setupUi(this);
    setWindowTitle("A propos de Hotel Manager Plus");
}

BDApropos::~BDApropos()
{
    delete ui;
}

void BDApropos::changeEvent(QEvent *e)
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
