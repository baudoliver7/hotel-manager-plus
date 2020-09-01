#include "BDCardex.h"
#include "ui_BDCardex.h"

BDCardex::BDCardex(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDCardex)
{
    ui->setupUi(this);

    m_bdWaiting = new BDWaiting(this);

    m_affichage = false;
    ui->btn_modifier->setEnabled(false);

    initialiserTableau();
    initialiserTableauLocations();

    connect(ui->lineEditClientConnu, SIGNAL(textChanged(QString)), this, SLOT(chargerClientsRecherches()));

    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateEtatBtnModifier(QModelIndex)));

    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(selectionnerClient(QModelIndex)));

    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(afficherLocations()));

    connect(ui->tableWidgetLocations->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(selectionnerLocation(QModelIndex)));

    connect(ui->tableWidgetLocations->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(chargerAutresInfos()));

    ui->checkBoxMasculin->setChecked(true);

    chargerClientsRecherches();
    updateEtatAutresInfos(false);
}

BDCardex::~BDCardex()
{
    delete ui;

    delete m_model;
    delete m_bdWaiting;
}

void BDCardex::changeEvent(QEvent *e)
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

void BDCardex::chargerClientsRecherches()
{
    QString nomDebut = ui->lineEditClientConnu->text();

    QString condition;
    if(!nomDebut.isEmpty())
    {
        client cl;
        condition = tr("%1 = %2 AND %3 LIKE '%4%'")
                                .arg(cl.hommeName())
                                .arg(ui->checkBoxMasculin->isChecked())
                                .arg(cl.nomName())
                                .arg(nomDebut);
    }else
    {
        client cl;
        condition = tr("%1 = %2").arg(cl.codeDuClientName())
                                .arg(-1);
    }


    m_model->setFilter(condition);
    m_model->select();

    ui->tableView->resizeColumnsToContents();
}

void BDCardex::initialiserTableau()
{
    m_model = new QSqlTableModel();
    m_model->setTable(Client::Libelle);
    ui->tableView->setModel(m_model);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(Client::Id::CodeClient, true);
    ui->tableView->setColumnHidden(Client::Id::Homme, true);

    m_model->setHeaderData(Client::Id::Prenoms, Qt::Horizontal, "Prénom(s)");
    m_model->setHeaderData(Client::Id::DateDeNaissance, Qt::Horizontal, "Date de naissance");
    m_model->setHeaderData(Client::Id::LieuDeNaissance, Qt::Horizontal, "Lieu de naissance");
    m_model->setHeaderData(Client::Id::Pere, Qt::Horizontal, "Père");
    m_model->setHeaderData(Client::Id::Mere, Qt::Horizontal, "Mère");
    m_model->setHeaderData(Client::Id::DomicileHabituel, Qt::Horizontal, "Domicile habituel");
    m_model->setHeaderData(Client::Id::Nationalite, Qt::Horizontal, "Nationalité");
    m_model->setHeaderData(Client::Id::Cel, Qt::Horizontal, "Cel");
    m_model->setHeaderData(Client::Id::Tel, Qt::Horizontal, "Tel");
    m_model->setHeaderData(Client::Id::Email, Qt::Horizontal, "Adresse mail");
    m_model->setHeaderData(Client::Id::BP, Qt::Horizontal, "Boîte postale");
}

void BDCardex::on_btn_ajouter_clicked()
{
    client cl;
    cl.setHomme(true);
    BDFormulaireClientSimple bd(cl, false, this);
    bd.setWindowTitle("Identifier un client");

    if(bd.exec() == QDialog::Accepted)
    {
        client cl(bd.clientRenseigne());
        cl.enregistrer();

        chargerClientsRecherches();
    }
}

void BDCardex::on_btn_fermer_clicked()
{
    close();
}

void BDCardex::selectionnerClient(QModelIndex index)
{
    QString title;

    if(index.isValid())
    {
        int row = index.row();

        client cl(m_model->record(row));
        m_clientSelectionne = cl;

        title = tr("Informations sur le client %1").arg(m_clientSelectionne.nomComplet());
    }else
    {
        m_clientSelectionne = client();
        title = tr("Informations sur le client sélectionné");
    }

    ui->groupBoxInfosClients->setTitle(title);
}

void BDCardex::selectionnerLocation(QModelIndex index)
{
    if(index.isValid())
    {
        int row = index.row();

        m_occupSelectionnee = occupation(ui->tableWidgetLocations->item(row, ID)->text().toInt());

    }else
    {
        m_occupSelectionnee = occupation();
    }

    updateEtatAutresInfos(index.isValid());
}

void BDCardex::chargerLocations()
{
    ui->tableWidgetLocations->setRowCount(0);

    libererOccup li;
    occupation oc1;
    QString condition = tr("%1 = %2 AND %3 IN (SELECT %4 FROM %5)")
                        .arg(oc1.codeClientName()).arg(m_clientSelectionne.codeDuClient())
                        .arg(oc1.numOccupName()).arg(li.numOccupName()).arg(li.tableName());

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Occupation::Libelle, condition);

    int montantRestant = 0;
    int montantEncaisse = 0;
    int nbLocationsNonReglees = 0;
    for(int i = 0; i < records.count(); i++)
    {
        occupation oc(records.at(i));

        montantEncaisse += oc.payee() + oc.fraisSupPayee();
        montantRestant += oc.reste() + oc.resteFraisSup();

        if(oc.reste() + oc.resteFraisSup() > 0)
            nbLocationsNonReglees++;

        ui->tableWidgetLocations->setRowCount(i+1);

        afficherElement(i, ID, QString::number(oc.numOccupation()));
        afficherElement(i, FACTURE, oc.facture());
        afficherElement(i, DATEARRIVEE, oc.datedEntree().toString(Qt::SystemLocaleDate));

        QDateTime datedSortie = oc.datedSortie();
        if(oc.terminee())
            datedSortie = libererOccup::selectionner(oc.numOccupation()).date();

        afficherElement(i, CHAMBRE, oc.chambreOccupee());
        afficherElement(i, DATEDEPART, datedSortie.toString(Qt::SystemLocaleDate));
        afficherElement(i, DUREE, MesTables::convertirAnMoisSemaineJour(oc.dureeOccupation()));
        afficherElement(i, MONTANTTOTAL, QString::number(oc.cout() + oc.fraisSupplementaire()));
        afficherElement(i, MONTANTPAYE, QString::number(oc.payee() + oc.fraisSupPayee()));
        afficherElement(i, MONTANTRESTANT, QString::number(oc.reste() + oc.resteFraisSup()));
        afficherElement(i, MATRICULEAGENT, recevoirOccup::selectionner(oc.numOccupation()).matriculeRecepteur());
    }

    QString title;

    int nbLocations = records.count();
    if(nbLocations <= 1)
    {
        title = tr("%1 location (%2 non réglée)").arg(nbLocations).arg(nbLocationsNonReglees);
    }else
    {
        if(nbLocationsNonReglees <= 1)
        {
            title = tr("%1 locations (%2 non réglée)").arg(nbLocations).arg(nbLocationsNonReglees);
        }else
        {
            title = tr("%1 locations (%2 non réglées)").arg(nbLocations).arg(nbLocationsNonReglees);
        }
    }

    ui->groupBoxLocations->setTitle(title);

    m_bdWaiting->close();
}

void BDCardex::afficherElement(int row, int column, const QString &value)
{
    QTableWidgetItem * item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);

    ui->tableWidgetLocations->setItem(row, column,item);
}

void BDCardex::initialiserTableauLocations()
{
    ui->tableWidgetLocations->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidgetLocations->setColumnHidden(ID, true);
    ui->tableWidgetLocations->setColumnHidden(MATRICULEAGENT, true);
}

void BDCardex::chargerAutresInfos()
{
    ui->spinBoxNbEnfants->setValue(m_occupSelectionnee.enfAccMoinsDe15());
    ui->lineEditDestinationExacte->setText(m_occupSelectionnee.destinationExacte());

    profileClient p(m_occupSelectionnee.idProfileClient());
    ui->lineEditProfile->setText(p.profile());
    ui->lineEditTypeDeClient->setText(typeDeClient(p.idTypeClient()).type());

    pieceIdentiteClient pic = pieceIdentiteClient::selectionnerPieceDuClient(m_occupSelectionnee.numOccupation());

    // pièces
    ui->lineEditNumero->setText(pic.numero());
    ui->lineEditNature->setText(pic.nature());
    ui->lineEditLieuDelivrance->setText(pic.lieuDelivrance());
    ui->dateEditDateDelivrance->setDate(pic.dateDelivrance());
    ui->lineEditAgentDelivreur->setText(pic.agentDelivreur());
}

void BDCardex::updateEtatAutresInfos(bool enabled)
{
    ui->groupBoxPiece->setEnabled(enabled);
    ui->groupBoxInfosSupp->setEnabled(enabled);
    ui->groupBoxCategorie->setEnabled(enabled);
}

void BDCardex::on_btn_modifier_clicked()
{
    BDFormulaireClientSimple bd(m_clientSelectionne, false, this);
    bd.setWindowTitle("Modifier le client");

    if(bd.exec() == QDialog::Accepted)
    {
        m_clientSelectionne = bd.clientRenseigne();
        m_clientSelectionne.enregistrer();

        chargerClientsRecherches();
    }
}

void BDCardex::updateEtatBtnModifier(QModelIndex index)
{
    ui->btn_modifier->setEnabled(index.isValid());
}

void BDCardex::afficherLocations()
{
    m_bdWaiting->show();
    QTimer::singleShot(5, this, SLOT(chargerLocations()));
}
