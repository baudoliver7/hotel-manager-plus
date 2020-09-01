#include "BDFormulaireClientHotelSimple.h"
#include "ui_BDFormulaireClientHotelSimple.h"

BDFormulaireClientHotelSimple::BDFormulaireClientHotelSimple(const client &cl, int idProfile, bool readOnly, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDFormulaireClientHotelSimple)
{
    ui->setupUi(this);

    m_readOnly = readOnly;

    ui->btn_ok->setVisible(!m_readOnly);
    ui->btn_ok->setEnabled(false);

    if(m_readOnly)
        ui->btn_annuler->setText("Fermer");

    ui->comboBoxProfile->setDisabled(m_readOnly);
    ui->comboBoxTypeDeClient->setDisabled(m_readOnly);

    ui->lineEditDomicile->setReadOnly(m_readOnly);
    ui->lineEditLieuDeNaiss->setReadOnly(m_readOnly);
    ui->lineEditMere->setReadOnly(m_readOnly);
    ui->lineEditNationalite->setReadOnly(m_readOnly);
    ui->lineEditNom->setReadOnly(m_readOnly);
    ui->lineEditPere->setReadOnly(m_readOnly);
    ui->lineEditPrenom->setReadOnly(m_readOnly);
    ui->lineEditProfession->setReadOnly(m_readOnly);

    ui->dateEditDateDeNaiss->setReadOnly(m_readOnly);

    ui->rb_feminin->setDisabled(m_readOnly);
    ui->rb_masculin->setDisabled(m_readOnly);

    m_affichage = false;
    m_client = cl;
    m_idProfileClient = idProfile;

    initialiserCategorie();
    afficherClient(m_client, idProfile);

    connect(ui->lineEditNom, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnOK()));
    connect(ui->lineEditPrenom, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnOK()));
    connect(ui->lineEditContacts, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnOK()));

    updateEtatBtnOK();
}

BDFormulaireClientHotelSimple::~BDFormulaireClientHotelSimple()
{
    delete ui;
}

void BDFormulaireClientHotelSimple::changeEvent(QEvent *e)
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

void BDFormulaireClientHotelSimple::on_btn_ok_clicked()
{
    if(!m_readOnly)
    {
        // récupérer les infos
        m_client.setNom(ui->lineEditNom->text());
        m_client.setPrenoms(ui->lineEditPrenom->text());
        m_client.setDateDeNaissance(ui->dateEditDateDeNaiss->date());
        m_client.setLieuDeNaissance(ui->lineEditLieuDeNaiss->text());
        m_client.setPere(ui->lineEditPere->text());
        m_client.setMere(ui->lineEditMere->text());
        m_client.setProfession(ui->lineEditProfession->text());
        m_client.setDomicileHabituel(ui->lineEditDomicile->text());
        m_client.setContacts(ui->lineEditContacts->text());
        m_client.setNationalite(ui->lineEditNationalite->text());
        m_client.setHomme(ui->rb_masculin->isChecked());

        int id = 0;
        if(!m_profilesEnCours.isEmpty())
            id = m_profilesEnCours.at(ui->comboBoxProfile->currentIndex()).idProfile();

        m_idProfileClient = id;

        m_client.enregistrer();
    }

    accept();
}

void BDFormulaireClientHotelSimple::on_btn_annuler_clicked()
{
    reject();
}

void BDFormulaireClientHotelSimple::afficherClient(const client &cl, int idProfile)
{
    // infos sur le client
    ui->lineEditNom->setText(cl.nom());
    ui->lineEditPrenom->setText(cl.prenoms());
    ui->dateEditDateDeNaiss->setDate(cl.dateDeNaissance());
    ui->lineEditLieuDeNaiss->setText(cl.lieuDeNaissance());
    ui->lineEditPere->setText(cl.pere());
    ui->lineEditMere->setText(cl.mere());
    ui->lineEditProfession->setText(cl.profession());
    ui->lineEditDomicile->setText(cl.domicileHabituel());
    ui->lineEditContacts->setText(cl.contacts());
    ui->lineEditNationalite->setText(cl.nationalite());
    ui->rb_masculin->setChecked(cl.homme());
    ui->rb_feminin->setChecked(!cl.homme());

    // Catégorie
    profileClient profile(idProfile);
    if(profile.existe())
    {
        typeDeClient t(profile.idTypeClient());
        ui->comboBoxTypeDeClient->setCurrentIndex(m_typesDeClientEnCours.indexOf(t));
        chargerLesProfiles(t);

        ui->comboBoxProfile->setCurrentIndex(m_profilesEnCours.indexOf(profile));
    }
}

void BDFormulaireClientHotelSimple::initialiserCategorie()
{
    m_affichage = true;
    ui->comboBoxProfile->clear();
    ui->comboBoxTypeDeClient->clear();
    m_affichage = false;

    chargerLesTypesClients();

    if(!m_typesDeClientEnCours.isEmpty())
        chargerLesProfiles(m_typesDeClientEnCours.first());

    m_affichage = false;
}

void BDFormulaireClientHotelSimple::on_comboBoxTypeDeClient_currentIndexChanged(int index)
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

void BDFormulaireClientHotelSimple::chargerLesTypesClients()
{
    m_affichage = true;

    m_typesDeClientEnCours.clear();
    m_typesDeClientStrEnCours.clear();
    ui->comboBoxTypeDeClient->clear();

    m_typesDeClientEnCours = typeDeClient::typeDeClientDisponibles(true);
    m_typesDeClientStrEnCours = typeDeClient::typesDisponibles(true);
    ui->comboBoxTypeDeClient->addItems(m_typesDeClientStrEnCours);

    m_affichage = false;
}

void BDFormulaireClientHotelSimple::chargerLesProfiles(const typeDeClient &t)
{
    m_affichage = true;

    ui->comboBoxProfile->clear();
    m_profilesEnCours.clear();
    m_profilesStrEnCours.clear();

    int idTypeDeClient = t.idTypeDeClient();
    m_profilesEnCours = profileClient::profilesClientDisponibles(true, idTypeDeClient);
    m_profilesStrEnCours = profileClient::profilesDisponibles(true, idTypeDeClient);

    ui->comboBoxProfile->addItems(m_profilesStrEnCours);

    m_affichage = false;
}

void BDFormulaireClientHotelSimple::on_btn_calendrier_clicked()
{
    DialogContact bd(ui->lineEditContacts->text(), this, m_readOnly);
    bd.setWindowTitle("Contacts");

    if(bd.exec() == QDialog::Accepted)
    {
        ui->lineEditContacts->setText(bd.getContact());
    }
}

void BDFormulaireClientHotelSimple::updateEtatBtnOK()
{
    bool disabled = ui->lineEditNom->text().isEmpty() || ui->lineEditPrenom->text().isEmpty()
                    || ui->lineEditContacts->text().isEmpty();

    ui->btn_ok->setDisabled(disabled);
}
