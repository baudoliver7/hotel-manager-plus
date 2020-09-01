#include "BDEditerUnMvt.h"
#include "ui_BDEditerUnMvt.h"

BDEditerUnMvt::BDEditerUnMvt(bool debiteur, bool editer, QWidget *parent, QString libelleComplet, int montant) :
    QDialog(parent),
    ui(new Ui::BDEditerUnMvt)
{
    ui->setupUi(this);

    m_debiteur = debiteur;

    if(m_debiteur)
        ui->labelMontant->setText("Montant à débiter :");
    else
        ui->labelMontant->setText("Montant à créditer :");

    // charger les comptes
    chargerMesComptes();

    if(editer)
    {
        int index = m_libellesComplets.indexOf(libelleComplet);
        ui->comboBoxLibelleCpt->setCurrentIndex(index);

        ui->comboBoxLibelleCpt->setEnabled(false);       
        ui->spinBoxMontant->setValue(montant);
        m_modified = false;
    }

    updateEtatsBtn();
}

BDEditerUnMvt::~BDEditerUnMvt()
{
    delete ui;
}

void BDEditerUnMvt::changeEvent(QEvent *e)
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

void BDEditerUnMvt::updateEtatsBtn()
{
    if((ui->spinBoxMontant->value() == 0) || ui->comboBoxLibelleCpt->currentText().isEmpty())
    {
        ui->btn_ok->setEnabled(false);
    }else
    {
        ui->btn_ok->setEnabled(true);
    }
}

void BDEditerUnMvt::chargerMesComptes()
{
    m_libellesComplets.clear();

    QList<QSqlRecord> records;
    records << planComptable::pc_records(true);

    foreach(QSqlRecord r, records)
    {
        m_libellesComplets << planComptable(r).libellePersoComplet();
    }

    m_libellesComplets.sort();

    ui->comboBoxLibelleCpt->addItems(m_libellesComplets);
}

void BDEditerUnMvt::on_spinBoxMontant_valueChanged(QString )
{
    m_modified = true;
    updateEtatsBtn();
}

void BDEditerUnMvt::on_btn_annuler_clicked()
{
    reject();
}

void BDEditerUnMvt::on_btn_ok_clicked()
{
    accept();
}

int BDEditerUnMvt::numCpt()
{
   return QString(ui->comboBoxLibelleCpt->currentText().split(" ").first()).toInt();
}

int BDEditerUnMvt::montant()
{
    return ui->spinBoxMontant->value();
}

bool BDEditerUnMvt::debiteur()
{
    return m_debiteur;
}

QString BDEditerUnMvt::libelle()
{
    planComptable pc(numCpt());

    return pc.libelle();
}

void BDEditerUnMvt::on_comboBoxLibelleCpt_currentIndexChanged(QString )
{
    updateEtatsBtn();
}

bool BDEditerUnMvt::modified()
{
    return m_modified;
}
