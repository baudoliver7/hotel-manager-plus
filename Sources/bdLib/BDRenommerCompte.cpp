#include "BDRenommerCompte.h"
#include "ui_BDRenommerCompte.h"

BDRenommerCompte::BDRenommerCompte(const planComptable &p, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDRenommerCompte)
{
    ui->setupUi(this);

    m_p = p;

    ui->btn_ok->setEnabled(false);
    connect(ui->lineEditLibellePerso, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnOK()));

    ui->lineEditLibelleComplet->setText(p.libelleComplet());
    ui->lineEditLibellePerso->setText(p.libellePerso());
}

BDRenommerCompte::~BDRenommerCompte()
{
    delete ui;
}

void BDRenommerCompte::changeEvent(QEvent *e)
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

void BDRenommerCompte::on_btn_annuler_clicked()
{
    reject();
}

void BDRenommerCompte::on_btn_ok_clicked()
{
    m_p.setLibellePerso(ui->lineEditLibellePerso->text());
    m_p.enregistrer();

    accept();
}

void BDRenommerCompte::updateEtatBtnOK()
{
    ui->btn_ok->setEnabled(!ui->lineEditLibellePerso->text().isEmpty());
}
