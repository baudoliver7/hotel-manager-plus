#include "BDConfigurerTableResto.h"
#include "ui_BDConfigurerTableResto.h"

BDConfigurerTableResto::BDConfigurerTableResto(bool estBar, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDConfigurerTableResto)
{
    ui->setupUi(this);

    m_estBar = estBar;
    m_modified = false;
    ui->btn_ajouter->setEnabled(false);
    ui->btn_supprimer->setEnabled(false);
    ui->btn_appliquer->setEnabled(false);

    initialiserTable();

    chargerTables();

    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateEtatBtnSupprimer(QModelIndex)));
}

BDConfigurerTableResto::~BDConfigurerTableResto()
{
    delete ui;
    delete m_model;
}

void BDConfigurerTableResto::changeEvent(QEvent *e)
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

void BDConfigurerTableResto::on_btn_fermer_clicked()
{
    close();
}

void BDConfigurerTableResto::on_lineEditLibelle_textChanged(QString text)
{
    ui->btn_ajouter->setEnabled(!text.isEmpty());
}

void BDConfigurerTableResto::initialiserTable()
{
    m_model = new QSqlTableModel;
    m_model->setTable(TableResto::Libelle);

    ui->tableView->setModel(m_model);
    ui->tableView->setColumnHidden(TableResto::Id::Occupee, true);
    ui->tableView->setColumnHidden(TableResto::Id::Supprime, true);
    ui->tableView->setColumnHidden(TableResto::Id::IdTableResto, true);
    ui->tableView->setColumnHidden(TableResto::Id::EstBar, true);

    tableResto t;
    QString condition = tr("%1 = %2 AND %3 = %4 AND %5 = %6")
                        .arg(t.occupeeName())
                        .arg(false)
                        .arg(t.supprimeName())
                        .arg(false)
                        .arg(t.estBarName())
                        .arg(m_estBar);

    m_model->setFilter(condition);
}

void BDConfigurerTableResto::chargerTables()
{
    m_model->select();
}

void BDConfigurerTableResto::updateEtatBtnSupprimer(QModelIndex index)
{
    ui->btn_supprimer->setEnabled(index.isValid());
}

void BDConfigurerTableResto::on_tableView_doubleClicked(QModelIndex index)
{
    if(index.isValid())
    {
        m_modified = true;
        ui->btn_appliquer->setEnabled(true);
    }
}

void BDConfigurerTableResto::on_btn_appliquer_clicked()
{
    // enregistrer et recharger
    m_model->submitAll();
    chargerTables();

    m_modified = false;
    ui->btn_appliquer->setEnabled(false);
}

void BDConfigurerTableResto::on_btn_ajouter_clicked()
{
    // enregistrer une nouvelle table
    tableResto t;
    t.setLibelle(ui->lineEditLibelle->text());
    t.setEstBar(m_estBar);
    t.enregistrer();

    chargerTables();
    m_modified = false;
    ui->btn_appliquer->setEnabled(false);

    // initialiser
    ui->lineEditLibelle->setText(QString());
}

void BDConfigurerTableResto::on_btn_supprimer_clicked()
{
    int row = ui->tableView->currentIndex().row();
    QString name = m_model->record(row).value(TableResto::Id::Libelle).toString();

    if(QMessageBox::information(this, "Suppression d'une table"
                                , tr("Vous êtes sur le point de supprimer la table '%1'.\n\nDésirez-vous continuer ?").arg(name)
                                , "Oui", "Abandonner") == 0)
    {
        tableResto t(m_model->record(row));
        t.setSupprime(true);
        t.enregistrer();

        chargerTables();
    }
}
