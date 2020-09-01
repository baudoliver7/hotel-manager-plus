#include "BDChoixConfigServiceCompta.h"
#include "ui_BDChoixConfigServiceCompta.h"

BDChoixConfigServiceCompta::BDChoixConfigServiceCompta(int compteAssocie, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDChoixConfigServiceCompta)
{
    ui->setupUi(this);

    chargerComptes();

    if(compteAssocie != 0)
    {
        ui->comboBoxCompteAssocie->setCurrentIndex(m_numCpts.indexOf(compteAssocie));
    }
}

BDChoixConfigServiceCompta::~BDChoixConfigServiceCompta()
{
    delete ui;
}

void BDChoixConfigServiceCompta::changeEvent(QEvent *e)
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

void BDChoixConfigServiceCompta::on_btn_annuler_clicked()
{
    reject();
}

void BDChoixConfigServiceCompta::on_btn_ok_clicked()
{
    accept();
}

void BDChoixConfigServiceCompta::chargerComptes()
{
    QList<QSqlRecord> records;
    records << planComptable::pc_records(true);

    QStringList comptes;
    foreach(QSqlRecord r, records)
    {
        planComptable pc(r);
        comptes << pc.libellePersoComplet();
        m_numCpts << pc.numCpt();
    }

    comptes.sort();

    ui->comboBoxCompteAssocie->clear();

    ui->comboBoxCompteAssocie->addItems(comptes);
}

int BDChoixConfigServiceCompta::compteAssocie()
{
    return QString(ui->comboBoxCompteAssocie->currentText().split(" ").first()).toInt();
}

