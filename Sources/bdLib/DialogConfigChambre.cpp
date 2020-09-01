#include "DialogConfigChambre.h"
#include "ui_DialogConfigChambre.h"

DialogConfigChambre::DialogConfigChambre(QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogConfigChambre)
{
    ui->setupUi(this);

    ui->btn_modifier->setVisible(false);

    initialiserTypeDeChambre();
    initialiserChambres();
    initialiserTypeDeClient();
    initialiserProfiles();

    connect(ui->tableViewChambres->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateEtatBtnOfTypeDeCh(QModelIndex)));

    connect(ui->tableViewChambres->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateLibelleBtnMettreHS()));

    chargerTypesDeChambre();
    chargerTypeDeClient();

    connect(ui->checkBoxTypeChDispo, SIGNAL(clicked(bool)), this, SLOT(setTypeDeChDispo(bool)));

    connect(ui->btn_ajouter, SIGNAL(clicked()), this, SLOT(ajouterUneChambre()));
    connect(ui->btn_modifier, SIGNAL(clicked()), this, SLOT(modifierUneChambre()));
    connect(ui->btn_supprimer, SIGNAL(clicked()), this, SLOT(supprimerUneChambre()));
    connect(ui->btn_mettreHS, SIGNAL(clicked()), this, SLOT(mettreHorService()));
    connect(ui->btn_appliquer, SIGNAL(clicked()), this, SLOT(enregistrerTarifs()));

    connect(ui->btn_ajouterUnTypeChambre, SIGNAL(clicked()), this, SLOT(ajouterUnTypeDeCh()));
    connect(ui->btn_ajouterUnTypeClient, SIGNAL(clicked()), this, SLOT(ajouterUnTypeDeClient()));
    connect(ui->btn_ajouterUnTypeProfile, SIGNAL(clicked()), this, SLOT(ajouterUnProfile()));
    connect(ui->tableWidgetTarifsChambres, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(updateEtatBtnAppliquer()));

    updateEtatBtnOfTypeDeCh(QModelIndex());
    construireTableauTarifs();
}

DialogConfigChambre::~DialogConfigChambre()
{
    delete ui;

    delete m_modelChambres;
    delete m_modelTypeDeCh;
    delete m_modelTypeDeClient;
    delete m_modelProfiles;
}

void DialogConfigChambre::changeEvent(QEvent *e)
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

void DialogConfigChambre::on_btn_fermer_clicked()
{
    close();
}

void DialogConfigChambre::initialiserTypeDeChambre()
{
    m_modelTypeDeCh = new QSqlTableModel;
    m_modelTypeDeCh->setTable(TypeDeChambre::Libelle);
    m_modelTypeDeCh->setSort(TypeDeChambre::Id::Type, Qt::AscendingOrder);

    ui->comboBoxTypeChambre->setModel(m_modelTypeDeCh);
    ui->comboBoxTypeChambre->setModelColumn(TypeDeChambre::Id::Type);

    connect(ui->comboBoxTypeChambre, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateCheckBoxDispoTypeDeCh()));
    connect(ui->comboBoxTypeChambre, SIGNAL(currentIndexChanged(QString)), this, SLOT(chargerChambres()));
}

void DialogConfigChambre::initialiserTypeDeClient()
{
    m_modelTypeDeClient = new QSqlTableModel;
    m_modelTypeDeClient->setTable(TypeDeClient::Libelle);
    m_modelTypeDeClient->setSort(TypeDeClient::Id::Type, Qt::AscendingOrder);

    ui->comboBoxTypeClient->setModel(m_modelTypeDeClient);
    ui->comboBoxTypeClient->setModelColumn(TypeDeClient::Id::Type);
}

void DialogConfigChambre::chargerTypesDeChambre()
{
    m_modelTypeDeCh->select();
}

void DialogConfigChambre::updateCheckBoxDispoTypeDeCh()
{
    int currentRow = ui->comboBoxTypeChambre->currentIndex();

    if(currentRow >= 0)
    {
        ui->checkBoxTypeChDispo->setEnabled(true);

        QSqlRecord record = m_modelTypeDeCh->record(currentRow);
        typeDeChambre t(record);

        ui->checkBoxTypeChDispo->setChecked(t.disponible());

        ui->btn_ajouter->setEnabled(t.disponible());
    }else
    {
        ui->checkBoxTypeChDispo->setEnabled(false);
        ui->btn_ajouter->setEnabled(false);
    }
}

void DialogConfigChambre::initialiserChambres()
{
    m_modelChambres = new QSqlRelationalTableModel;
    m_modelChambres->setTable(Chambre::Libelle);
    m_modelChambres->setSort(Chambre::Id::Identifiant, Qt::AscendingOrder);

    m_modelChambres->setHeaderData(Chambre::Id::Identifiant, Qt::Horizontal, "Identifiant");
    m_modelChambres->setHeaderData(Chambre::Id::HorsService, Qt::Horizontal, "Hors service");
    m_modelChambres->setHeaderData(Chambre::Id::IdEtage, Qt::Horizontal, "Niveau");

    etage e;
    m_modelChambres->setRelation(Chambre::Id::IdEtage, QSqlRelation(e.tableName(), e.idEtageName(), e.niveauName()));

    ui->tableViewChambres->setModel(m_modelChambres);
    ui->tableViewChambres->setColumnHidden(Chambre::Id::Occupee, true);
    ui->tableViewChambres->setColumnHidden(Chambre::Id::IdTypeChambre, true);
}

void DialogConfigChambre::chargerChambres()
{
    chambre ch;
    QString condition;
    
    if(ui->checkBoxTypeChDispo->isChecked())
    {
        condition = condition = tr("%1 = %2")
                                .arg(ch.idTypeChambreName()).arg(currentIdTypeDeCh());
    }else
    {
        condition = condition = tr("%1 = %2")
                                .arg(ch.idTypeChambreName()).arg(-1);
    }

    m_modelChambres->setFilter(condition);
    m_modelChambres->select();
    
    ui->labelNbChambres->setText(QString("%1 chambre(s)").arg(m_modelChambres->rowCount()));
}

int DialogConfigChambre::currentIdTypeDeCh()
{
    int currentRow = ui->comboBoxTypeChambre->currentIndex();

    if(currentRow < 0)
        return -1;

    QSqlRecord record = m_modelTypeDeCh->record(currentRow);
    typeDeChambre t(record);

    return t.idTypeDeChambre();
}

int DialogConfigChambre::currentIdTypeDeClient()
{
    int currentRow = ui->comboBoxTypeClient->currentIndex();

    if(currentRow < 0)
        return -1;

    QSqlRecord record = m_modelTypeDeClient->record(currentRow);
    typeDeClient t(record);

    return t.idTypeDeClient();
}

void DialogConfigChambre::setTypeDeChDispo(bool disponible)
{
    // on suppose qu'on a un type de chambre valide

    if(!disponible) // si on souhaite rendre le type indiponible
    {
        // vérifier qu'aucune chambre n'est occupée ou réservée
        chambre ch;
        chambreReservee chr;
        QString condition = tr("%1 = %2 AND (%3 = %4 OR %5 IN (SELECT %6 FROM %7 WHERE %8 = %9))")
                            .arg(ch.idTypeChambreName()).arg(currentIdTypeDeCh())
                            .arg(ch.occupeeName()).arg(true)
                            .arg(ch.identifiantName())
                            .arg(chr.identiteChName())
                            .arg(chr.tableName())
                            .arg(chr.termineeName())
                            .arg(false);

        bool uneChEstUtilisee = InfosSurBD::enregistrements(ch.tableName(), condition).count() != 0;

        if(uneChEstUtilisee)
        {
            QMessageBox::information(this, "Rendre un type indisponible", "Impossible de rendre ce type de chambre indisponible car une de ces chambres est actuellement utilisée.");
            ui->checkBoxTypeChDispo->setChecked(true); // remettre disponible
            return;
        }
    }// on peut modifier aisément maintenant

    // modifier la table des types de chambre
    int currentRow = ui->comboBoxTypeChambre->currentIndex();
    QSqlRecord record = m_modelTypeDeCh->record(currentRow);

    typeDeChambre t(record);
    t.setDisponible(disponible);
    t.enregistrer();

    m_modelTypeDeCh->setRecord(currentRow, t.record());

    // mettre à jour état de check-box type de chambre
    updateCheckBoxDispoTypeDeCh();

    // recharger les chambres
    chargerChambres();

    // recharger les tarifications
}

void DialogConfigChambre::updateEtatBtnOfTypeDeCh(QModelIndex index)
{
    bool enabled = index.isValid();

    ui->btn_supprimer->setEnabled(enabled);
    ui->btn_modifier->setEnabled(enabled);
    ui->btn_mettreHS->setEnabled(enabled);
}

void DialogConfigChambre::ajouterUneChambre()
{
    BDAjouterUneChambre * bd = new BDAjouterUneChambre(currentIdTypeDeCh(), this);
    bd->setWindowTitle("Ajouter une chambre");

    if(bd->exec() == QDialog::Accepted)
    {
        chargerChambres();
    }

    delete bd;
}

void DialogConfigChambre::modifierUneChambre()
{

}

void DialogConfigChambre::mettreHorService()
{
    chambre ch(currentIdentiteCh());
    ch.setHorsService(!ch.horsService());
    ch.enregistrer();

    chargerChambres();
}

void DialogConfigChambre::supprimerUneChambre()
{
    if(QMessageBox::question(this, "Suppression d'une chambre","Voulez-vous vraiment supprimer la chambre selectionnée ?",
                             "Oui", "Non") == 0)
        {
            chambre ch(currentIdentiteCh());

            chambreReservee chr;
            bool chUtilisee = InfosSurBD::enregistrements(ChambreReservee::Libelle,
                                        tr("%1 = '%2'").arg(chr.identiteChName()).arg(ch.identifiant())).count() != 0;

            occupation oc;
            chUtilisee = chUtilisee || InfosSurBD::enregistrements(Occupation::Libelle,
                                                tr("%1 = '%2'").arg(oc.identiteChName()).arg(ch.identifiant())).count() != 0;

            if(!chUtilisee)
            {
                ch.supprimer();
                chargerChambres();
            }else
            {
                QMessageBox::information(this, "Echec de suppression", "Impossible de supprimer la chambre sélectionnée car elle est déjà utilisée!");
            }
        }
}

QString DialogConfigChambre::currentIdentiteCh()
{
    int currentRow = ui->tableViewChambres->currentIndex().row();
    QSqlRecord record = m_modelChambres->record(currentRow);
    chambre ch(record);

    return ch.identifiant();
}

void DialogConfigChambre::updateLibelleBtnMettreHS()
{
    int currentRow = ui->tableViewChambres->currentIndex().row();

    if(currentRow < 0)
        return;

    QSqlRecord record = m_modelChambres->record(currentRow);
    chambre ch(record);

    if(ch.horsService())
    {
        ui->btn_mettreHS->setText("Mettre en service");
    }else
    {
        ui->btn_mettreHS->setText("Mettre HS");
    }
}

void DialogConfigChambre::ajouterUnTypeDeCh()
{
    BDNouveauTypeDeChambre * bd = new BDNouveauTypeDeChambre(TYPEDECHAMBRE, this);
    bd->setWindowTitle("Ajouter un type de chambre");

    if(bd->exec() == QDialog::Accepted)
    {
        m_modelTypeDeCh->select();
        construireTableauTarifs();
    }

    delete bd;
}

void DialogConfigChambre::chargerProfiles()
{
    profileClient p;
    QString condition = tr("%1 = %2").arg(p.idTypeClientName()).arg(currentIdTypeDeClient());

    m_modelProfiles->setFilter(condition);
    m_modelProfiles->select();
}

void DialogConfigChambre::chargerTypeDeClient()
{
    m_modelTypeDeClient->select();
}

void DialogConfigChambre::initialiserProfiles()
{
    m_modelProfiles = new QSqlTableModel;
    m_modelProfiles->setTable(ProfileClient::Libelle);
    m_modelProfiles->setSort(ProfileClient::Id::Profile, Qt::AscendingOrder);

    ui->comboBoxProfileClient->setModel(m_modelProfiles);
    ui->comboBoxProfileClient->setModelColumn(ProfileClient::Id::Profile);

    connect(ui->comboBoxTypeClient, SIGNAL(currentIndexChanged(QString)), this, SLOT(chargerProfiles()));
}

void DialogConfigChambre::construireTableauTarifs()
{
    ui->tableWidgetTarifsChambres->setRowCount(0);
    ui->tableWidgetTarifsChambres->setColumnCount(0);

    // construire l'entête des colonnes
    int columnCount = m_modelTypeDeCh->rowCount();
    ui->tableWidgetTarifsChambres->setColumnCount(columnCount);

    for(int column = 0; column < columnCount; column++)
    {
        QTableWidgetItem * item = new QTableWidgetItem(typeDeChambre(m_modelTypeDeCh->record(column)).type());
        ui->tableWidgetTarifsChambres->setHorizontalHeaderItem(column, item);
    }

    // construire l'entête des rangées
    m_profile_records = InfosSurBD::enregistrements(ProfileClient::Libelle);
    int rowCount = m_profile_records.count();
    ui->tableWidgetTarifsChambres->setRowCount(rowCount);
    for(int row = 0; row < rowCount; row++)
    {
        QTableWidgetItem * item = new QTableWidgetItem(profileClient(m_profile_records.at(row)).profile());
        ui->tableWidgetTarifsChambres->setVerticalHeaderItem(row, item);
    }

    // afficher les tarifs
    afficherTarifs();
}

void DialogConfigChambre::afficherTarifs()
{
    ui->btn_appliquer->setEnabled(false);

    int columnCount = ui->tableWidgetTarifsChambres->columnCount();
    int rowCount = ui->tableWidgetTarifsChambres->rowCount();

    if(rowCount != 0 && columnCount != 0)
    {
        for(int row = 0; row < rowCount; row++)
        {
            for(int column = 0; column < columnCount; column++)
            {
                typeDeChambre t(m_modelTypeDeCh->record(column));
                profileClient p(m_profile_records.at(row));

                prixChambreTTC prix(  t.idTypeDeChambre()
                                    , p.idProfile());

                int pu = 0;
                if(prix.existe())
                    pu = prix.prixTTC();

                QTableWidgetItem * item = new QTableWidgetItem(QString::number(pu));
                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidgetTarifsChambres->setItem(row, column, item);
            }
        }
    }

    ui->tableWidgetTarifsChambres->resizeColumnsToContents();
}

void DialogConfigChambre::enregistrerTarifs()
{
    ui->btn_appliquer->setEnabled(false);

    int rowCount = ui->tableWidgetTarifsChambres->rowCount();
    int columnCount = ui->tableWidgetTarifsChambres->columnCount();

    if(rowCount != 0 && columnCount != 0)
    {
        for(int row = 0; row < rowCount; row++)
        {
            for(int column = 0; column < columnCount; column++)
            {
                int idTypeDeChambre = typeDeChambre(m_modelTypeDeCh->record(column)).idTypeDeChambre();
                int idProfile = profileClient(m_profile_records.at(row)).idProfile();

                prixChambreTTC prix( idTypeDeChambre
                                    , idProfile);

                int pu = ui->tableWidgetTarifsChambres->item(row, column)->text().toInt();

                if(pu < 0) pu = 0;

                prix.setIdTypeChambre(idTypeDeChambre);
                prix.setIdProfile(idProfile);
                prix.setPrixTTC(pu);
                prix.enregistrer();
            }
        }
    }
}

void DialogConfigChambre::updateEtatBtnAppliquer()
{
    ui->btn_appliquer->setEnabled(true);
}

void DialogConfigChambre::ajouterUnTypeDeClient()
{
    BDNouveauTypeDeChambre * bd = new BDNouveauTypeDeChambre(TYPEDECLIENT, this);
    bd->setWindowTitle("Ajouter un type de client");

    if(bd->exec() == QDialog::Accepted)
    {
        m_modelTypeDeClient->select();
    }

    delete bd;
}

void DialogConfigChambre::ajouterUnProfile()
{
    BDNouveauTypeDeChambre * bd = new BDNouveauTypeDeChambre(PROFILECLIENT, this, currentIdTypeDeClient());
    bd->setWindowTitle("Ajouter un profile");

    if(bd->exec() == QDialog::Accepted)
    {
        m_modelProfiles->select();
        construireTableauTarifs();
    }

    delete bd;
}
