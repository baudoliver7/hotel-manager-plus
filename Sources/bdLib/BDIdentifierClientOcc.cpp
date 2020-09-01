#include "BDIdentifierClientOcc.h"
#include "ui_BDIdentifierClientOcc.h"

BDIdentifierClientOcc::BDIdentifierClientOcc(const occupation &occ, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDIdentifierClientOcc)
{
    ui->setupUi(this);

    m_affichage = false;
    m_occup = occ;
    ui->btn_details->setEnabled(false);
    ui->groupBoxCategorie->setEnabled(false);
    ui->groupBoxInfosSupp->setEnabled(false);
    ui->groupBoxPiece->setEnabled(false);
    ui->btn_ok->setEnabled(false);
    ui->btn_choisir->setEnabled(false);

    initialiserTableau();
    initialiserClientSelectionne();

    connect(ui->rb_clientConnu, SIGNAL(toggled(bool)), this, SLOT(updateEtatChampsClientConnu(bool)));
    connect(ui->rb_clientInconnu, SIGNAL(toggled(bool)), this, SLOT(updateEtatChampsClientInconnu(bool)));

    connect(ui->rb_clientConnu, SIGNAL(toggled(bool)), this, SLOT(initialiserClientSelectionne()));
    connect(ui->rb_clientInconnu, SIGNAL(toggled(bool)), this, SLOT(initialiserClientSelectionne()));

    connect(ui->lineEditClientConnu, SIGNAL(textChanged(QString)), this, SLOT(chargerClientConnu()));

    connect(ui->lineEditClientSelectionne, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnDetails()));
    connect(ui->lineEditClientSelectionne, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnOK()));
    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateEtatBtnChoisir(QModelIndex)));

    ui->rb_clientInconnu->setChecked(true);
    chargerClientConnu();
    updateEtatChampsClientConnu(false);

    // afficher types de client
    QList<typeDeClient> types_de_clients = typeDeClient::typeDeClientDisponibles(true);
    QStringList types_de_clients_str;
    foreach(typeDeClient t, types_de_clients)
    {
        m_id_types_client << t.idTypeDeClient();
        types_de_clients_str << t.type();
    }

    ui->comboBoxTypeDeClient->addItems(types_de_clients_str);
    updateEtatBtnOK();
}

BDIdentifierClientOcc::~BDIdentifierClientOcc()
{
    delete ui;

    delete m_model;
}

void BDIdentifierClientOcc::changeEvent(QEvent *e)
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

void BDIdentifierClientOcc::on_btn_identifier_clicked()
{
    client cl;
    cl.setHomme(true);
    BDFormulaireClientSimple bd(cl, false, this);
    bd.setWindowTitle("Identifier un client");

    if(bd.exec() == QDialog::Accepted)
    {
        client cl(bd.clientRenseigne());
        cl.enregistrer();

        m_clientSelectionne = cl;

        ui->lineEditClientSelectionne->setText(cl.nomComplet());
    }
}

void BDIdentifierClientOcc::on_btn_details_clicked()
{
    BDFormulaireClientSimple bd(m_clientSelectionne, true, this);
    bd.setWindowTitle("Identifier un client");

    bd.exec();
}

void BDIdentifierClientOcc::chargerClientConnu()
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
}

void BDIdentifierClientOcc::initialiserTableau()
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

void BDIdentifierClientOcc::updateEtatBtnDetails()
{
    bool disabled = ui->lineEditClientSelectionne->text().isEmpty();

    ui->btn_details->setDisabled(disabled);
    ui->groupBoxCategorie->setDisabled(disabled);
    ui->groupBoxInfosSupp->setDisabled(disabled);
    ui->groupBoxPiece->setDisabled(disabled);
}

void BDIdentifierClientOcc::updateEtatChampsClientConnu(bool enabled)
{
    ui->lineEditClientConnu->setEnabled(enabled);
    ui->checkBoxMasculin->setEnabled(enabled);
    ui->tableView->setEnabled(enabled);
    ui->btn_choisir->setEnabled(enabled);    
    ui->btn_identifier->setEnabled(!enabled);
}

void BDIdentifierClientOcc::updateEtatChampsClientInconnu(bool enabled)
{
    ui->btn_identifier->setEnabled(enabled);
}

void BDIdentifierClientOcc::initialiserClientSelectionne()
{
    m_clientSelectionne.clear();
    ui->lineEditClientSelectionne->setText(QString());
}

void BDIdentifierClientOcc::updateEtatBtnOK()
{
    ui->btn_ok->setDisabled(ui->lineEditClientSelectionne->text().isEmpty());
}

void BDIdentifierClientOcc::on_btn_ok_clicked()
{
    QDate now = Horloge::currentDate();

    // renseigner code du client de l'occupation
    m_occup.setCodeClient(m_clientSelectionne.codeDuClient());

    // renseigner profile du client sélectionné
    m_occup.setIdProfileClient(m_id_profiles_client.at(ui->comboBoxProfile->currentIndex()));
    m_occup.setEnfAccMoinsDe15(ui->spinBoxNbEnfants->value());
    m_occup.setDestinationExacte(ui->lineEditDestinationExacte->text());

    // renseigner pièce du client
    pieceIdentiteClient pic;
    pic.setNature(ui->lineEditNature->text());
    pic.setNumero(ui->lineEditNumero->text());
    pic.setDateDelivrance(ui->dateEditDateDelivrance->date());
    pic.setDateReception(now);
    pic.setAgentDelivreur(ui->lineEditAgentDelivreur->text());
    pic.setCodeClient(m_clientSelectionne.codeDuClient());
    pic.setLieuDelivrance(ui->lineEditLieuDelivrance->text());
    pic.setNumOccupation(m_occup.numOccupation());

    m_pic = pic;

    accept();
}

void BDIdentifierClientOcc::on_btn_annuler_clicked()
{
    reject();
}

void BDIdentifierClientOcc::updateEtatBtnChoisir(QModelIndex index)
{
    ui->btn_choisir->setEnabled(index.isValid());
}

void BDIdentifierClientOcc::on_btn_choisir_clicked()
{
    int row = ui->tableView->currentIndex().row();

    client cl(m_model->record(row));
    ui->lineEditClientSelectionne->setText(cl.nomComplet());

    m_clientSelectionne = cl;
}

void BDIdentifierClientOcc::afficherCategorie(int idProfileClient)
{
    if(m_id_types_client.isEmpty())
        return;

    m_affichage = true;
    profileClient p(idProfileClient);

    // afficher type de client
    typeDeClient t(p.idTypeClient());
    int indexT = 0;
    if(m_id_types_client.contains(t.idTypeDeClient()))
        indexT = m_id_types_client.indexOf(t.idTypeDeClient());

    ui->comboBoxTypeDeClient->setCurrentIndex(indexT);

    // afficher profile
    chargerProfile(t.idTypeDeClient());

    int indexProfile = 0;
    if(m_id_profiles_client.contains(p.idProfile()))
        indexProfile = m_id_profiles_client.indexOf(p.idProfile());

    ui->comboBoxProfile->setCurrentIndex(indexProfile);
    m_affichage = false;
}

void BDIdentifierClientOcc::chargerProfile(int idTC)
{
    QList<profileClient> profiles_client;
    profiles_client << profileClient::profilesClientDisponibles(true, idTC);

    QStringList profiles_client_str;

    m_id_profiles_client.clear();
    foreach(profileClient p, profiles_client)
    {
        m_id_profiles_client << p.idProfile();
        profiles_client_str << p.profile();
    }

    ui->comboBoxProfile->clear();
    ui->comboBoxProfile->addItems(profiles_client_str);
}

void BDIdentifierClientOcc::on_comboBoxTypeDeClient_currentIndexChanged(int index)
{
    if(index < 0)
        return;

    if(!m_affichage)
    {
        // afficher profile
        typeDeClient t(m_id_types_client.at(index));

        chargerProfile(t.idTypeDeClient());
    }
}
