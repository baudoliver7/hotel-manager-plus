#include "DialogRechercherUnClient.h"
#include "ui_DialogRechercherUnClient.h"

DialogRechercherUnClient::DialogRechercherUnClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRechercherUnClient)
{
    ui->setupUi(this);

    ui->btn_OK->setEnabled(false);
    ui->comboBoxAction->setEnabled(false);

    initialiserTableau();

    ui->Masculin->setChecked(true);
    rafraichirTableau();

    connect(ui->Masculin, SIGNAL(clicked()), this, SLOT(rafraichirTableau()));
    connect(ui->Feminin, SIGNAL(clicked()), this, SLOT(rafraichirTableau()));
}

DialogRechercherUnClient::~DialogRechercherUnClient()
{
    delete ui;
}

void DialogRechercherUnClient::changeEvent(QEvent *e)
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

bool DialogRechercherUnClient::estUnHomme()
{
    return ui->Masculin->isChecked();
}

void DialogRechercherUnClient::afficherClients(QString debutNom, bool sexe)
{
    QStringList fieldsNames = InfosSurBD::fieldsNames(m_clients);

    QString requete;

    requete = tr("%1 = %2")
              .arg(fieldsNames.at(Client::Id::Homme))
              .arg(QString::number(sexe));

    if(!debutNom.isEmpty())
    {
        requete = tr("%1 AND %2 LIKE '%3%'")
                             .arg(requete)
                             .arg(fieldsNames.at(Client::Id::Nom))
                             .arg(debutNom);
    }

    m_clients->setFilter(requete);
    m_clients->select();
}

void DialogRechercherUnClient::on_btn_OK_clicked()
{
    accept();
}

void DialogRechercherUnClient::updateEtatDesWidgets(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_OK->setEnabled(true);
        ui->comboBoxAction->setEnabled(true);
    }else
    {
        ui->btn_OK->setEnabled(false);
        ui->comboBoxAction->setEnabled(false);
    }
}

void DialogRechercherUnClient::on_lineEditNom_textChanged(QString)
{
    rafraichirTableau();
}

void DialogRechercherUnClient::initialiserTableau()
{
    initialiserModel();
    ui->tableViewClients->setModel(m_clients);

    connect(ui->tableViewClients->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(updateEtatDesWidgets(QModelIndex)));

    ui->tableViewClients->setColumnHidden(Client::Id::CodeClient, true);
    ui->tableViewClients->setColumnHidden(Client::Id::Homme, true);
    ui->tableViewClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DialogRechercherUnClient::initialiserModel()
{
    m_clients = new QSqlTableModel(this);
    m_clients->setTable(Client::Libelle);
    m_clients->setSort(Client::Id::CodeClient, Qt::AscendingOrder);
}

void DialogRechercherUnClient::on_btn_Annuler_clicked()
{
    reject();
}

QSqlRecord DialogRechercherUnClient::clientChoisi()
{
    return m_clients->record(ui->tableViewClients->currentIndex().row());
}

bool DialogRechercherUnClient::occuperUneChambre()
{
    // vrai pour occuper et faux pour réserver
    return (ui->comboBoxAction->currentIndex() == 0);
}

void DialogRechercherUnClient::rafraichirTableau()
{
    afficherClients(ui->lineEditNom->text(), estUnHomme());
}

