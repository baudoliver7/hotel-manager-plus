#include "dialoggerercompterecepteur.h"
#include "ui_dialoggerercompterecepteur.h"

DialogGererCompteRecepteur::DialogGererCompteRecepteur(agent *ag, QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogGererCompteRecepteur)
{
    ui->setupUi(this);

    m_admini = ag;
    ui->btn_supprimer->setVisible(false);
    ui->btn_initialiserCompte->setVisible(false);
    ui->btn_supprimer->setEnabled(false);
    ui->btn_suspendre_activer->setEnabled(false);
    ui->btn_editer->setEnabled(false);

    initialiserTableau();

    connect(ui->lineEditContacts, SIGNAL(textChanged(QString)), this, SLOT(updateBtnEnregister()));
    connect(ui->lineEditNom, SIGNAL(textChanged(QString)), this, SLOT(updateBtnEnregister()));
    connect(ui->lineEditPrenoms, SIGNAL(textChanged(QString)), this, SLOT(updateBtnEnregister()));
    connect(ui->lineEditResidence, SIGNAL(textChanged(QString)), this, SLOT(updateBtnEnregister()));
    connect(ui->lineEditMatricule, SIGNAL(textChanged(QString)), this, SLOT(updateBtnEnregister()));

    connect(ui->rb_administration, SIGNAL(clicked()), this, SLOT(chargerAgents()));
    connect(ui->rb_restauration, SIGNAL(clicked()), this, SLOT(chargerAgents()));
    connect(ui->comptabilite, SIGNAL(clicked()), this, SLOT(chargerAgents()));
    connect(ui->reception, SIGNAL(clicked()), this, SLOT(chargerAgents()));

    ui->Monsieur->setChecked(true);
    updateBtnEnregister();

    ui->rb_administration->setChecked(true);
    chargerAgents();
}

DialogGererCompteRecepteur::~DialogGererCompteRecepteur()
{
    delete ui;
}

void DialogGererCompteRecepteur::changeEvent(QEvent *e)
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

void DialogGererCompteRecepteur::on_btn_fermer_clicked()
{
    close();
}

void DialogGererCompteRecepteur::afficherUnAgent(int row, const QSqlRecord &record)
{
    QStringList l = enregistrement(record);

    if(!l.isEmpty())
    {
        int rowsCount = ui->tableWidget->rowCount();
        if(row >= rowsCount)
        {
            // on doit ajouter  row - rowsCount + 1 rangée(s)
            ui->tableWidget->setRowCount(row + 1);

        }else
        {
            // la rangée existe déjà. on n'ajoute donc rien.
        }

        for(int header = Statut; header <= Residence; header++)
        {
            afficherUnElement(row, header, l.at(header));
        }
    }
}

void DialogGererCompteRecepteur::afficherUnElement(int row, int column, QString text)
{
    QTableWidgetItem * item = new QTableWidgetItem(text);

    ui->tableWidget->setItem(row, column, item);
}

QStringList DialogGererCompteRecepteur::enregistrement(const QSqlRecord &record)
{
    QStringList l;

    agent r(record);

    l << r.statutToString()
      << r.matricule()
      << r.sexePrecis()
      << r.nom()
      << r.prenoms()
      << r.cel()
      << r.tel()
      << r.email()
      << r.bp()
      << r.residence();

    return l;
}

void DialogGererCompteRecepteur::on_btn_actualiser_clicked()
{
    chargerAgents();
}

void DialogGererCompteRecepteur::on_btn_supprimer_clicked()
{
    if(QMessageBox::question(this, "Suppression d'un récepteur", "Voulez-vous supprimer le récepteur sélectionné?\n\n Cette action pourrait entraîner la suppression de toutes ses activités.",
                             QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Ok)
    {
        int row = ui->tableWidget->currentRow();
        QString matricule = ui->tableWidget->item(row, Matricule)->text();

        agent r(matricule);
        r.supprimer();

        chargerAgents();
    }
}

void DialogGererCompteRecepteur::miseAjourEtatBtnSupprimer(QModelIndex index)
{
    if(index.isValid())
    {
        if(ui->reception->isChecked())
        {
            ui->btn_supprimer->setEnabled(true);
        }
    }else
    {
        ui->btn_supprimer->setEnabled(false);
    }
}

void DialogGererCompteRecepteur::initialiserTableau()
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->tableWidget->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(miseAjourEtatBtnSupprimer(QModelIndex)));
    connect(ui->tableWidget->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(miseAjourEtatBtnSuspendu_Actif(QModelIndex)));
    connect(ui->tableWidget->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(miseAjourEtatBtnEditer(QModelIndex)));
}

void DialogGererCompteRecepteur::on_btn_suspendre_activer_clicked()
{
    int row = ui->tableWidget->currentRow();
    QString matricule = ui->tableWidget->item(row, Matricule)->text();

    agent r(matricule);

    if(r.statut() == agent::Suspendu || r.statut() == agent::EnAttente)
    {
        r.setStatut(agent::Actif);
        r.enregistrer();
    }else
    {
        // il est actif. vérifier qu'il n'est pas en cours d'utilisation
        if(!r.connecte())
        {
            r.setStatut(agent::Suspendu);
            r.enregistrer();
        }else
        {
            QMessageBox::information(this, "Suspension d'un agent", tr("L'agent de matricule %1 est présentement connecté! \n\n Veuillez l'avertir par un message puis réessayer.").arg(r.matricule()));
            return;
        }
    }

    chargerAgents();
}

void DialogGererCompteRecepteur::miseAjourEtatBtnSuspendu_Actif(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_suspendre_activer->setEnabled(currentAgent()->matricule() != QString("ADMIN"));

        if(ui->comptabilite->isChecked())
        {
            ui->btn_initialiserCompte->setEnabled(true);
        }
    }else
    {
        ui->btn_suspendre_activer->setEnabled(false);
        ui->btn_initialiserCompte->setEnabled(false);
    }
}

void DialogGererCompteRecepteur::miseAjourEtatBtnEditer(QModelIndex index)
{
    if(index.isValid())
    {
        if(currentIdService() == IDADMINISTRATION)
        {
            ui->btn_editer->setEnabled(false);
        }else
        {
            ui->btn_editer->setEnabled(true);
        }
    }else
    {
        ui->btn_editer->setEnabled(false);
    }
}

void DialogGererCompteRecepteur::updateBtnEnregister()
{
    bool disabled = ui->lineEditContacts->text().isEmpty()
                    || ui->lineEditMatricule->text().isEmpty()
                    || ui->lineEditNom->text().isEmpty()
                    || ui->lineEditPrenoms->text().isEmpty()
                    || ui->lineEditResidence->text().isEmpty();

    ui->btn_enregistrer->setDisabled(disabled);
}

void DialogGererCompteRecepteur::on_btn_enregistrer_clicked()
{   
    agent r(ui->lineEditMatricule->text());

    if(ui->btn_enregistrer->text() == QString("Modifier"))
    {
        r.setNom(ui->lineEditNom->text());
        r.setPrenoms(ui->lineEditPrenoms->text());
        r.setContacts(ui->lineEditContacts->text());
        r.setSexePrecis(m_sexePrecisEnCours);
        r.setResidence(ui->lineEditResidence->text());
    }else
    {
        // enregistrer un nouveau agent
        if(!r.existe()) // vérifier l'unicité du matricule
        {
            r.setMatricule(ui->lineEditMatricule->text());
            r.setNom(ui->lineEditNom->text());
            r.setPrenoms(ui->lineEditPrenoms->text());
            r.setContacts(ui->lineEditContacts->text());
            r.setSexePrecis(m_sexePrecisEnCours);
            r.setStatut(agent::EnAttente);
            r.setResidence(ui->lineEditResidence->text());
            r.setDateInscription(Horloge::currentDateTime()); // l'activation vient plutard
            r.setIdService(currentIdService());
        }else
        {
            QMessageBox::information(this, "Unicité du matricule", "Ce matricule existe déjà!\n\n Veuillez entrer un autre matricule.");
            return;
        }
    }

    r.enregistrer();
    on_btn_initialiser_clicked();

    chargerAgents();
}

void DialogGererCompteRecepteur::initialiser()
{
    ui->lineEditContacts->setText(QString());
    ui->lineEditMatricule->setText(QString());
    ui->lineEditNom->setText(QString());
    ui->lineEditPrenoms->setText(QString());
    ui->lineEditResidence->setText(QString());

    ui->Monsieur->setChecked(true);
}

void DialogGererCompteRecepteur::on_btn_initialiser_clicked()
{
    ui->btn_enregistrer->setText("Enregistrer");
    ui->lineEditMatricule->setEnabled(true);

    initialiser();
}

void DialogGererCompteRecepteur::on_Monsieur_toggled(bool checked)
{
    m_sexePrecisEnCours = agent::listeSexePrecis().at(agent::Monsieur);
}

void DialogGererCompteRecepteur::on_Madame_toggled(bool checked)
{
    m_sexePrecisEnCours = agent::listeSexePrecis().at(agent::Madame);
}

void DialogGererCompteRecepteur::on_Demoiselle_toggled(bool checked)
{
    m_sexePrecisEnCours = agent::listeSexePrecis().at(agent::Demoiselle);
}

void DialogGererCompteRecepteur::on_btn_contacts_clicked()
{
    DialogContact * bdContacts = new DialogContact(ui->lineEditContacts->text(), this);
    if(bdContacts->exec() == QDialog::Accepted
       && !bdContacts->estVide())
    {
        ui->lineEditContacts->setText(bdContacts->getContact());
    }

    delete bdContacts;
}

void DialogGererCompteRecepteur::on_btn_editer_clicked()
{
    // déterminer agent
    int row = ui->tableWidget->currentRow();
    QString matricule = ui->tableWidget->item(row, 1)->text();
    agent ag(matricule);

    // afficher dans la zone d'édition
    ui->lineEditMatricule->setText(matricule);
    ui->lineEditMatricule->setEnabled(false);

    ui->lineEditNom->setText(ag.nom());
    ui->lineEditPrenoms->setText(ag.prenoms());
    ui->lineEditContacts->setText(ag.contacts(ag.cel(), ag.tel(), ag.email(), ag.bp()));
    ui->lineEditResidence->setText(ag.residence());

    if(ag.sexePrecis() == QString("M."))
    {
        ui->Monsieur->setChecked(true);
    }else
    {
        if(ag.sexePrecis() == QString("Mme"))
        {
            ui->Madame->setChecked(true);
        }else
        {
            ui->Demoiselle->setChecked(true);
        }
    }

    ui->btn_enregistrer->setText("Modifier");
}

void DialogGererCompteRecepteur::chargerAgents()
{
    agent ag;
    ui->tableWidget->setRowCount(0);

    QString condition = tr("%1 = %2")
                        .arg(ag.idServiceName())
                        .arg(currentIdService());

    QList<QSqlRecord> records = InfosSurBD::enregistrements(Agent::Libelle, condition);

    for(int row = 0; row < records.count(); row++)
    {
        afficherUnAgent(row, records.at(row));
    }
}

agent * DialogGererCompteRecepteur::currentAgent()
{
    int currentRow = ui->tableWidget->currentRow();
    if(currentRow >= 0)
    {
       return new agent(ui->tableWidget->item(currentRow, MATRICULE)->text());
    }

    return 0;
}

int DialogGererCompteRecepteur::currentIdService()
{
    int idService;
    if(ui->rb_administration->isChecked())
    {
        idService = 1;
    }else
    {
        if(ui->comptabilite->isChecked())
        {
            idService = 2;
        }else
        {
            if(ui->reception->isChecked())
            {
                idService = 3;
            }else
            {
                idService = 4;
            }
        }
    }

    return idService;
}
