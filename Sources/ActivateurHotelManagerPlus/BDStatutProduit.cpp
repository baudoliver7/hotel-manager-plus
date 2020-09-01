#include "BDStatutProduit.h"
#include "ui_BDStatutProduit.h"

BDStatutProduit::BDStatutProduit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDStatutProduit)
{
    ui->setupUi(this);
    on_comboBoxNomProduit_currentIndexChanged(QString());
}

BDStatutProduit::~BDStatutProduit()
{
    delete ui;
}

void BDStatutProduit::changeEvent(QEvent *e)
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

void BDStatutProduit::on_btn_fermer_clicked()
{
    close();
}

void BDStatutProduit::on_btn_supprimer_clicked()
{
    QSettings settings(QSettings::SystemScope, APPNAME, m_productName);

    settings.clear();
}

void BDStatutProduit::on_comboBoxNomProduit_currentIndexChanged(QString )
{
    int indexProduit = ui->comboBoxNomProduit->currentIndex();

    switch(indexProduit)
    {
    case 0:
        m_productName = "HMPA";
        break;
    case 1:
        m_productName = "HMPC";
        break;
    default:
        m_productName = "HMPR";
    }

    // afficher les paramètres
    QSettings settings(QSettings::SystemScope, APPNAME, m_productName);

    if(settings.value(APPNAME).toString() != m_productName)
    {
        ui->labelReponse->setText("Non");
        ui->lineEditIID->setEnabled(false);
        ui->lineEditKey->setEnabled(false);
        ui->btn_supprimer->setEnabled(false);
    }else
    {
        ui->lineEditIID->setEnabled(true);
        ui->lineEditKey->setEnabled(true);
        ui->btn_supprimer->setEnabled(true);

        ui->labelReponse->setText("Oui");

        ui->lineEditIID->setText(settings.value(INSTALLATIONID).toString());
        ui->lineEditKey->setText(settings.value(KEY).toString());
    }
}
