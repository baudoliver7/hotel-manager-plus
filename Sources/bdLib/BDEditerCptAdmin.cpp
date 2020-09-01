#include "BDEditerCptAdmin.h"
#include "ui_BDEditerCptAdmin.h"

BDEditerCptAdmin::BDEditerCptAdmin(agent *r, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDEditerCptAdmin)
{
    ui->setupUi(this);

    m_fermer = true;
    m_admin = r;
    ui->Monsieur->setChecked(true);
    on_Monsieur_clicked();
    afficherAdmin();

    connect(ui->lineEditConfirmation, SIGNAL(textChanged(QString)), this, SLOT(updateBtnOK()));
    connect(ui->lineEditPassword, SIGNAL(textChanged(QString)), this, SLOT(updateBtnOK()));
    connect(ui->lineEditContact, SIGNAL(textChanged(QString)), this, SLOT(updateBtnOK()));
    connect(ui->lineEditNom, SIGNAL(textChanged(QString)), this, SLOT(updateBtnOK()));
    connect(ui->lineEditPrenom, SIGNAL(textChanged(QString)), this, SLOT(updateBtnOK()));
    connect(ui->lineEditPseudo, SIGNAL(textChanged(QString)), this, SLOT(updateBtnOK()));

    updateBtnOK();
}

BDEditerCptAdmin::~BDEditerCptAdmin()
{
    delete ui;
}

void BDEditerCptAdmin::changeEvent(QEvent *e)
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

void BDEditerCptAdmin::on_btn_contact_clicked()
{
    DialogContact * bdContact = new DialogContact(ui->lineEditContact->text(), this);
    if(bdContact->exec() == QDialog::Accepted)
    {
        ui->lineEditContact->setText(bdContact->getContact());
    }

    delete bdContact;
}

void BDEditerCptAdmin::on_buttonBox_accepted()
{
    QString password = ui->lineEditPassword->text();
    QString confirmation = ui->lineEditConfirmation->text();

    if(password.count() >= 6)
    {
        if(password == confirmation)
        {
            // enregistrer le récepteur
            m_admin->setNom(ui->lineEditNom->text());
            m_admin->setPrenoms(ui->lineEditPrenom->text());

            m_admin->setSexePrecis(m_sexePrecisEnCours);
            m_admin->setLogin(ui->lineEditPseudo->text());
            m_admin->setPassword(ui->lineEditPassword->text());
            m_admin->setContacts(ui->lineEditContact->text());
            m_admin->setResidence(ui->lineEditResidence->text());

            if(m_admin->statut() == agent::EnAttente) // pour l'administrateur pour une nouvelle bd
            {
                // nouvelle ouverture
                QDateTime now = Horloge::currentDateTime();
                m_admin->setStatut(agent::Actif);
                m_admin->setDateActivation(now);
                m_admin->setDateInscription(now);
            }

            m_admin->enregistrer();
            m_fermer = true;
        }else
        {
            m_fermer = false;
            show();
            QMessageBox::warning(this, "Mot de passe", "Les mots de passe entrés sont différents!");
        }

    }else
    {
        m_fermer = false;
        show();
        QMessageBox::warning(this, "Mot de passe", "Vous devez entrer au minimum six (6) caractères!");
    }
}

void BDEditerCptAdmin::afficherAdmin()
{
    // enregistrer le récepteur
    ui->lineEditNom->setText(m_admin->nom());
    ui->lineEditPrenom->setText(m_admin->prenoms());

    if(m_admin->sexePrecis().contains("M."))
    {
        ui->Monsieur->setChecked(true);
    }else
    {
        if(m_admin->sexePrecis().contains("Mme"))
        {
            ui->Madame->setChecked(true);
        }else
        {
            ui->Demoiselle->setChecked(true);
        }
    }

    ui->lineEditResidence->setText(m_admin->residence());
    ui->lineEditPseudo->setText(m_admin->login());
    ui->lineEditPassword->setText(m_admin->password());
    ui->lineEditContact->setText(m_admin->contacts(m_admin->cel(), m_admin->tel(), m_admin->email(), m_admin->bp()));
    ui->lineEditConfirmation->setText(m_admin->password());

    bool enabled = (m_admin->idService() == IDADMINI);

    ui->lineEditResidence->setEnabled(enabled);
    ui->lineEditNom->setEnabled(enabled);
    ui->lineEditPrenom->setEnabled(enabled);
    ui->lineEditContact->setEnabled(enabled);
    ui->Monsieur->setEnabled(enabled);
    ui->Madame->setEnabled(enabled);
    ui->Demoiselle->setEnabled(enabled);
    ui->btn_contact->setEnabled(enabled);
}

void BDEditerCptAdmin::on_Monsieur_clicked()
{
    m_sexePrecisEnCours = agent::listeSexePrecis().at(agent::Monsieur);
}

void BDEditerCptAdmin::on_Madame_clicked()
{
    m_sexePrecisEnCours = agent::listeSexePrecis().at(agent::Madame);
}

void BDEditerCptAdmin::on_Demoiselle_clicked()
{
    m_sexePrecisEnCours = agent::listeSexePrecis().at(agent::Demoiselle);
}

void BDEditerCptAdmin::on_buttonBox_rejected()
{
    m_fermer = true;
}

void BDEditerCptAdmin::updateBtnOK()
{
    bool disabled = ui->lineEditConfirmation->text().isEmpty()
                    || ui->lineEditContact->text().isEmpty()
                    || ui->lineEditPassword->text().isEmpty()
                    || ui->lineEditNom->text().isEmpty()
                    || ui->lineEditPrenom->text().isEmpty()
                    || ui->lineEditPseudo->text().isEmpty();

    ui->buttonBox->buttons().first()->setDisabled(disabled);
}
