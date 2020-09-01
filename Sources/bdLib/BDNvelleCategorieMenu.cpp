#include "BDNvelleCategorieMenu.h"
#include "ui_BDNvelleCategorieMenu.h"

BDNvelleCategorieMenu::BDNvelleCategorieMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDNvelleCategorieMenu)
{
    ui->setupUi(this);
}

BDNvelleCategorieMenu::~BDNvelleCategorieMenu()
{
    delete ui;
}

void BDNvelleCategorieMenu::changeEvent(QEvent *e)
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

QString BDNvelleCategorieMenu::libelle()const
{
    return ui->lineEditLibelle->text();
}

void BDNvelleCategorieMenu::on_btn_ok_clicked()
{
    if(ui->lineEditLibelle->text().isEmpty())
    {
        QMessageBox::information(this, "Catégorie de menu", "Vous ne pouvez pas enregistrer une catégorie vide!");
        return;
    }

    accept();
}

void BDNvelleCategorieMenu::on_btn_annuler_clicked()
{
    reject();
}

bool BDNvelleCategorieMenu::plat()const
{
    return ui->rb_plat->isChecked();
}
