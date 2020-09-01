#include "BDConfigComptaService.h"
#include "ui_BDConfigComptaService.h"

BDConfigComptaService::BDConfigComptaService(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDConfigComptaService)
{
    ui->setupUi(this);

    initialiserTableau();
    chargerServices();

    connect(ui->tableView->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this
            , SLOT(updateEtatBtnEditer(QModelIndex)));

    updateEtatBtnEditer(QModelIndex());
}

BDConfigComptaService::~BDConfigComptaService()
{
    delete ui;
}

void BDConfigComptaService::changeEvent(QEvent *e)
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

void BDConfigComptaService::on_btn_fermer_clicked()
{
    close();
}

void BDConfigComptaService::chargerServices()
{
    ui->comboBoxServices->clear();

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ServiceEntreprise::Libelle);

    QStringList noms;
    foreach(QSqlRecord r, records)
    {
        serviceEntreprise s(r);
        if(s.idSe() == 2) // id compta
        {
            noms << s.nom();
            m_idSes << s.idSe();
        }
    }

    ui->comboBoxServices->addItems(noms);
}

void BDConfigComptaService::initialiserTableau()
{
    // initialisation du model
    m_confiServiceCompte = new QSqlTableModel();
    m_confiServiceCompte->setTable(ConfigServiceCompta::Libelle);
    m_confiServiceCompte->setHeaderData(ConfigServiceCompta::Id::Action, Qt::Horizontal, tr("Action"));
    m_confiServiceCompte->setHeaderData(ConfigServiceCompta::Id::CompteAssocie, Qt::Horizontal, tr("Compte associé"));

    // initialisation du tableau
    ui->tableView->setModel(m_confiServiceCompte);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(ConfigServiceCompta::Id::IdCsc, true);
    ui->tableView->setColumnHidden(ConfigServiceCompta::Id::IdSe, true);
}

void BDConfigComptaService::chargerConfigServiceCompta()
{
    if(ui->comboBoxServices->currentText().isEmpty())
        return;

    QString condition = tr("%1 = %2")
                        .arg(serviceEntreprise().idSeName())
                        .arg(m_idSes.at(ui->comboBoxServices->currentIndex()));

    m_confiServiceCompte->setFilter(condition);
    m_confiServiceCompte->select();
}


void BDConfigComptaService::on_comboBoxServices_currentIndexChanged(int index)
{
    chargerConfigServiceCompta();
}

void BDConfigComptaService::on_btn_editer_clicked()
{
    int currentRow = ui->tableView->currentIndex().row();
    configServiceCompta csc(m_confiServiceCompte->record(currentRow));
    QString title = csc.action();

    BDChoixConfigServiceCompta bd(csc.compteAssocie(), this);
    bd.setWindowTitle(title);

    if(bd.exec() == QDialog::Accepted)
    {
        csc.setCompteAssocie(bd.compteAssocie());
        csc.enregistrer();

        chargerConfigServiceCompta();
    }
}

void BDConfigComptaService::updateEtatBtnEditer(QModelIndex index)
{
    ui->btn_editer->setEnabled(index.isValid());
}
