#include "BDActiverNvCpte.h"
#include "ui_BDActiverNvCpte.h"

BDActiverNvCpte::BDActiverNvCpte(int idService, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDActiverNvCpte)
{
    ui->setupUi(this);

    m_fermer = true;
    m_matriculeValide = false;
    m_recepteur = 0;
    m_idService = idService;

    connect(ui->lineEditConfirmation, SIGNAL(textChanged(QString)), this, SLOT(updateBtnOK()));
    connect(ui->lineEditLogin, SIGNAL(textChanged(QString)), this, SLOT(updateBtnOK()));
    connect(ui->lineEditMatricule, SIGNAL(textChanged(QString)), this, SLOT(updateBtnOK()));

    ui->labelValide->setText("Invalide!");
    updateBtnOK();

}

BDActiverNvCpte::~BDActiverNvCpte()
{
    delete ui;
    if(m_recepteur) delete m_recepteur;
}

void BDActiverNvCpte::changeEvent(QEvent *e)
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

void BDActiverNvCpte::on_lineEditMatricule_textChanged(QString matricule)
{
    agent r(matricule);
    if(r.existe() && (r.statut() == agent::EnAttente) && (matricule != "ADMIN"))
    {
        // on a un nouveau récepteur
        ui->buttonBox->buttons().first()->setEnabled(true);
        ui->labelValide->setText("Valide!"); m_matriculeValide = true;
        updateBtnOK();

    }else
    {
        ui->labelValide->setText("Invalide!"); m_matriculeValide = false;
        ui->buttonBox->buttons().first()->setEnabled(false);
    }
}

void BDActiverNvCpte::updateBtnOK()
{
    bool disabbled = ui->lineEditConfirmation->text().isEmpty()
                     || ui->lineEditLogin->text().isEmpty()
                     || ui->lineEditMatricule->text().isEmpty()
                     || !m_matriculeValide;

    ui->buttonBox->buttons().first()->setDisabled(disabbled);
}

void BDActiverNvCpte::on_buttonBox_accepted()
{
    bool pseudoExiste = !InfosSurBD::enregistrements(Agent::Libelle, tr("%1 = '%2'").arg(agent().loginName()).arg(ui->lineEditLogin->text())).isEmpty();

    if((ui->lineEditConfirmation->text() == ui->Password->text()) && (!pseudoExiste
        || (pseudoExiste && (m_idService == COMPTABILITE))))
    {
        agent r(ui->lineEditMatricule->text());
        r.setDateActivation(Horloge::currentDateTime());
        r.setStatut(agent::Actif);
        r.setLogin(ui->lineEditLogin->text());
        r.setPassword(ui->Password->text());

        r.enregistrer();
        m_recepteur = new agent(r);
        m_fermer = true;

        QMessageBox::information(this, "Activation d'un compte", "L'activation de votre compte s'est déroulée avec succès!\n\n Veuillez-vous connecter pour vous assurer que vous avez bien mémorisé votre pseudo et votre mot de passe.");
    }else
    {
        m_fermer = false;
        show();

        if(pseudoExiste && (m_idService != COMPTABILITE))
        {
            QMessageBox::warning(this, "Pseudonyme", "Ce pseudo est déjà utilisé! \n \n Veuillez entrer un autre pseudonyme!");
        }else
        {
            QMessageBox::warning(this, "Mots de passe différents", "Les mots de passe entrés sont différents!");
            ui->lineEditConfirmation->setText(QString());
            ui->Password->setText(QString());
        }
    }
}

void BDActiverNvCpte::on_buttonBox_rejected()
{
    m_fermer = true;
}
