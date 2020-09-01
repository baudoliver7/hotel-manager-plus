#include "BDAutresSorties.h"
#include "ui_BDAutresSorties.h"

BDAutresSorties::BDAutresSorties(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDAutresSorties)
{
    ui->setupUi(this);
    ui->lineEditDescription->clear();
}

BDAutresSorties::~BDAutresSorties()
{
    delete ui;
}

void BDAutresSorties::changeEvent(QEvent *e)
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

void BDAutresSorties::on_buttonBox_accepted()
{

}

QString BDAutresSorties::description()const
{
    return ui->lineEditDescription->text();
}

void BDAutresSorties::on_lineEditDescription_textChanged(QString text)
{
    ui->buttonBox->buttons().first()->setDisabled(text.isEmpty());
}
