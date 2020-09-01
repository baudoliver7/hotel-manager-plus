#include "BDCreerUnGroupe.h"
#include "ui_BDCreerUnGroupe.h"

BDCreerUnGroupe::BDCreerUnGroupe(BDD *db, const agent &ag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDCreerUnGroupe)
{
    ui->setupUi(this);

    m_db = db;
    m_affichage = true;
    ui->comboBoxModeDePayement->setEnabled(false);
    m_agent = ag;
    updateEtatBtnCreer();
    initialiserCategorie();

    QDate date = Horloge::currentDate();
    ui->lineEditDateEntree->setText(date.toString(Qt::SystemLocaleLongDate));
    m_datedEntree.setDate(date);
    m_datedEntree.setTime(HeureLimite(1).heureFinOccupation());

    chargerTypesDeChambre();

    ui->comboBoxModeDePayement->addItems(modeDePayement::chargerModeDePayementSansCompteClient());
    m_affichage = false;

    afficherPrix();

    ui->lineEditNbChDispo->setText("rechercher...");
}

BDCreerUnGroupe::~BDCreerUnGroupe()
{
    delete ui;
}

void BDCreerUnGroupe::changeEvent(QEvent *e)
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

void BDCreerUnGroupe::on_btn_identifierRespo_clicked()
{
    BDIdentifierClientHotelSimple bd(this);
    bd.setWindowTitle("Identifier le client");

    if(bd.exec() == QDialog::Accepted)
    {
        m_client = bd.clientSelectionne();
        ui->lineEditClient->setText(m_client.nomComplet());

        updateEtatBtnCreer();
    }
}

void BDCreerUnGroupe::updateEtatBtnCreer()
{
    bool enabled = !ui->lineEditClient->text().isEmpty() && !ui->lineEditLibelle->text().isEmpty()
                   && !ui->lineEditDateEntree->text().isEmpty();
    ui->btn_creer->setEnabled(enabled);
}

void BDCreerUnGroupe::on_lineEditLibelle_textChanged(QString )
{
    updateEtatBtnCreer();
}

void BDCreerUnGroupe::on_btn_dateEntree_clicked()
{
    DialogCalendar bd(this);
    bd.setWindowTitle("Date d'entrée");

    if(bd.exec() == QDialog::Accepted)
    {
        if(Horloge::currentDate() > bd.dateSeclectionnee())
        {
            QMessageBox::information(this, "Date d'entrée", "La date sélectionnée est passée! \n\nVeuillez sélectionner une autre date.");
            return;
        }

        ui->lineEditDateEntree->setText(bd.dateSeclectionnee().toString(Qt::SystemLocaleLongDate));
        m_datedEntree.setDate(bd.dateSeclectionnee());
        m_datedEntree.setTime(HeureLimite(1).heureFinOccupation());
    }
}

void BDCreerUnGroupe::on_lineEditDateEntree_textChanged(QString )
{
    updateEtatBtnCreer();

    if(!m_affichage)
    {
       ui->lineEditNbChDispo->setText("rechercher...");
    }
}

void BDCreerUnGroupe::on_btn_creer_clicked()
{
    m_db->transaction();
    bool submitAll = true;

    QDateTime now = Horloge::currentDateTime();

    // enregistrer le groupe
    groupe gr;
    gr.setLibelle(ui->lineEditLibelle->text());
    gr.setIdResponsable(m_client.codeDuClient());
    gr.setDateDemande(now);
    gr.setDateOccupation(m_datedEntree);
    gr.setDureeOccupation(ui->spinBoxDuree->value());
    gr.setMatriculeAgent(m_agent.matricule());
    gr.setNbPersPrevues(ui->spinBoxNbPersPrevues->value());
    gr.setContacts(ui->lineEditContacts->text());
    gr.setNbPersEnregistrees(1); // le responsable

    if(!m_type_de_chambres.isEmpty())
        gr.setIdTypeDeChambreMaj(m_type_de_chambres.at(ui->comboBoxTypeDeChambre->currentIndex()).idTypeDeChambre());

    if(!m_profilesEnCours.isEmpty())
        gr.setIdProfileClient(m_profilesEnCours.at(ui->comboBoxProfile->currentIndex()).idProfile());

    int avance = ui->spinBoxAvance->value();
    if(avance != 0)
    {
        // enregistrer avance
        gr.setAvance(avance);
        gr.setAvanceActu(avance);
    }

    factureInitial fi(factureInitial::IdReception);
    int numero = fi.numero() + 1;
    gr.setFacture(fi.initial() + QString::number(numero));
    fi.setNumero(numero);
    submitAll = submitAll && fi.enregistrer() && gr.enregistrer();

    gr.actualiser();

    // faire une liaison pour le responsable
    groupeLiaison gr_liaison;
    gr_liaison.setCodeClient(m_client.codeDuClient());
    gr_liaison.setIdGroupe(gr.idGroupe());
    submitAll = submitAll && gr_liaison.enregistrer();

    if(avance != 0)
    {
        // faire un réçu pour l'avance
        submitAll = submitAll && MesTables::enregistrerUneOperationService(  m_agent
                                                                              , recuInitial::IdReservation
                                                                              , now
                                                                              , avance
                                                                              , QString("Avance sur location (groupe %1)").arg(gr.facture())
                                                                              , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                              , gr.idGroupe()
                                                                              , groupe().tableName());
    }

    if(submitAll)
        m_db->commit();
    else
        m_db->rollback();

    // accepter
    accept();
}

void BDCreerUnGroupe::on_btn_annuler_clicked()
{
    reject();
}

void BDCreerUnGroupe::on_spinBoxAvance_valueChanged(int value)
{
    ui->comboBoxModeDePayement->setEnabled(value != 0);
}

void BDCreerUnGroupe::on_btn_contact_clicked()
{
    DialogContact bd(ui->lineEditContacts->text(), this, false);
    bd.setWindowTitle("Contacts");

    if(bd.exec() == QDialog::Accepted)
    {
        ui->lineEditContacts->setText(bd.getContact());
    }
}

void BDCreerUnGroupe::initialiserCategorie()
{
    ui->comboBoxProfile->clear();
    ui->comboBoxTypeDeClient->clear();

    chargerLesTypesClients();

    if(!m_typesDeClientEnCours.isEmpty())
        chargerLesProfiles(m_typesDeClientEnCours.first());
}

void BDCreerUnGroupe::on_comboBoxTypeDeClient_currentIndexChanged(int index)
{
    if(!m_affichage)
    {
        if(index < 0)
        {
            ui->comboBoxProfile->clear();
            return;
        }

        chargerLesProfiles(m_typesDeClientEnCours.at(index));
    }
}

void BDCreerUnGroupe::chargerLesTypesClients()
{
    m_typesDeClientEnCours.clear();
    m_typesDeClientStrEnCours.clear();
    ui->comboBoxTypeDeClient->clear();

    m_typesDeClientEnCours = typeDeClient::typeDeClientDisponibles(true);
    m_typesDeClientStrEnCours = typeDeClient::typesDisponibles(true);
    ui->comboBoxTypeDeClient->addItems(m_typesDeClientStrEnCours);
}

void BDCreerUnGroupe::chargerLesProfiles(const typeDeClient &t)
{
    ui->comboBoxProfile->clear();
    m_profilesEnCours.clear();
    m_profilesStrEnCours.clear();

    int idTypeDeClient = t.idTypeDeClient();
    m_profilesEnCours = profileClient::profilesClientDisponibles(true, idTypeDeClient);
    m_profilesStrEnCours = profileClient::profilesDisponibles(true, idTypeDeClient);

    ui->comboBoxProfile->addItems(m_profilesStrEnCours);
}

void BDCreerUnGroupe::chargerTypesDeChambre()
{
    ui->comboBoxTypeDeChambre->clear();
    m_types_de_chambres_str.clear();
    m_type_de_chambres.clear();

    m_type_de_chambres = typeDeChambre::typeDeChambreDisponibles(true);
    m_types_de_chambres_str = typeDeChambre::typesDisponibles(true);

    ui->comboBoxTypeDeChambre->addItems(m_types_de_chambres_str);
}

void BDCreerUnGroupe::on_comboBoxTypeDeChambre_currentIndexChanged(int index)
{
    if(!m_affichage)
    {
       ui->lineEditNbChDispo->setText("rechercher...");
        afficherPrix();
    }
}

void BDCreerUnGroupe::afficherPrix()
{
    if(ui->comboBoxProfile->currentIndex() < 0 || ui->comboBoxTypeDeClient->currentIndex() < 0)
    {
        ui->lineEditPrixUnitaireTTC->setText(QString::number(0));
        ui->lineEditFraisHotelEstime->setText(QString::number(0));
        return;
    }

    typeDeChambre t = m_type_de_chambres.at(ui->comboBoxTypeDeChambre->currentIndex());

    // afficher prix
    profileClient p = m_profilesEnCours.at(ui->comboBoxProfile->currentIndex());

    int prixUnitaire = prixChambreTTC(t.idTypeDeChambre(), p.idProfile()).prixTTC();
    int prixTotal = prixUnitaire * ui->spinBoxDuree->value() * ui->spinBoxNbPersPrevues->value();

    ui->lineEditPrixUnitaireTTC->setText(MesTables::moneyToString(prixUnitaire));
    ui->lineEditFraisHotelEstime->setText(MesTables::moneyToString(prixTotal));
}

void BDCreerUnGroupe::afficherNbChDispo()
{
    if(ui->comboBoxTypeDeClient->currentIndex() < 0)
    {
        ui->lineEditNbChDispo->setText(QString::number(0));
        return;
    }

    typeDeChambre t = m_type_de_chambres.at(ui->comboBoxTypeDeChambre->currentIndex());
    QDate dateArrivee = QDate::fromString(ui->lineEditDateEntree->text(), Qt::SystemLocaleLongDate);

    // afficher nombre de chambre dispo
    QStringList chambres = MesTables::selectionnerChambresEnService(t.idTypeDeChambre());
    for(int i = 0; i < ui->spinBoxDuree->value(); i++)
    {
        QDate date = dateArrivee.addDays(i);
        QStringList chs = MesTables::selectionnerChambresDisponibles(t.idTypeDeChambre(), date);

        foreach(QString ch, chambres)
        {
            if(!chs.contains(ch))
            {
                chambres.removeOne(ch);
            }
        }
    }

    ui->lineEditNbChDispo->setText(QString::number(chambres.count()));
}

void BDCreerUnGroupe::on_comboBoxProfile_currentIndexChanged(int index)
{
    if(!m_affichage)
    {
        afficherPrix();
    }
}

void BDCreerUnGroupe::on_spinBoxNbPersPrevues_valueChanged(int )
{
    if(!m_affichage)
    {
        afficherPrix();
    }
}

void BDCreerUnGroupe::on_spinBoxDuree_valueChanged(int )
{
    if(!m_affichage)
    {
        ui->lineEditNbChDispo->setText("rechercher...");
        afficherPrix();
    }
}

void BDCreerUnGroupe::on_btn_rechercher_clicked()
{
   afficherNbChDispo();
}
