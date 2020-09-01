#include "FormConnexion.h"
#include "ui_FormConnexion.h"

FormConnexion::FormConnexion(serviceEntreprise *service, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormConnexion)
{
    ui->setupUi(this);
    m_agent = 0;
    m_service = service;

    // logo de l'application
    switch(service->idSe())
    {
        case 1 : // Administration
            ui->labelLogo->setPixmap(QPixmap(":/images/Logo_a2.png"));
            break;
        case 2 : // Comptabilité
            ui->labelLogo->setPixmap(QPixmap(":/images/Logo_c2.png"));
            break;
        case 3 : // Réception
            ui->labelLogo->setPixmap(QPixmap(":/images/Logo_r2.png"));
            break;

        default: // Restauration
            ui->labelLogo->setPixmap(QPixmap(":/images/Logo_rs2.png"));
            break;
    }

    connect(ui->btn_valider, SIGNAL(clicked()), this, SLOT(valider()));
}

FormConnexion::~FormConnexion()
{
    delete ui;
    if(m_agent) delete m_agent;
}

void FormConnexion::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QString FormConnexion::login()
{
   return ui->lineEditPseudo->text();
}

QString FormConnexion::password()
{
    return ui->lineEditPassword->text();
}

void FormConnexion::valider()
{
    agent r;

    QString condition = tr("%2 = '%3' AND %4 = '%5' AND %6 = %7")
                        .arg(r.loginName()).arg(login().replace("'", "''"))
                        .arg(r.passwordName()).arg(password().replace("'", "''"))
                        .arg(r.idServiceName())
                        .arg(m_service->idSe());

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(r.tableName(), condition);

    if(!records.isEmpty())
    {

        agent ag(records.first());
        if(ag.statut() == agent::Actif) // compte actif
        {
            //deconnecterTousLesComptesInactifs(); // tester la connection de tous les agents pour mettre à jour les agents connectés
                                                // utile pour la messagerie

//            ag.actualiser();
//            if(!ag.connecte())
//            {
//                // l'agent n'est pas encore connecté alors le connecté
//                ag.setConnecte(true);
//                ag.setEtatFinConnection(true); // mauvais
//                ag.enregistrer();
//
//                m_agent = new agent(ag);
//                accept();
//            }else
//            {
//                // l'agent est déjà connecté
//                QMessageBox::information(this, "Etat de compte", "Ce compte est en cours d'utilisation.\n\nVous ne pouvez pas ouvrir plusieurs fois le même compte!");
//                ui->lineEditLogin->setText(QString());
//                ui->lineEditPassword->setText(QString());
//
//                // enregistrer dans une base de données essai d'intrusion
//            }

            // l'agent n'est pas encore connecté alors le connecté
            ag.setConnecte(true);
            ag.setEtatFinConnection(true); // mauvais
            ag.enregistrer();

            m_agent = new agent(ag);
            emit accepted();
        }else
        {
            if(ag.statut() == agent::Suspendu) // compte suspendu
            {
                QMessageBox::information(this, "Compte suspendu", "Votre compte est actuellement suspendu! \n \n Veuillez contacter votre administrateur afin de le réactiver.");
                ui->lineEditPassword->setText(QString());
                ui->lineEditPseudo->setText(QString());
            }else                                   // compte en attente
            {
                QMessageBox::information(this, "Compte en attente", "Votre compte est actuellement en attente! \n \n Veuillez l'activer dans le sous-menu < Activer un nouveau compte >.");
                ui->lineEditPassword->setText(QString());
                ui->lineEditPseudo->setText(QString());
            }
        }

    }else                                           // compte inexistant
    {
        QMessageBox::information(this, "Compte inexistant", "Le pseudo ou mot de passe est incorrect!");
        ui->lineEditPassword->setText(QString());
        ui->lineEditPseudo->setText(QString());
    }
}

void FormConnexion::deconnecterTousLesComptesInactifs()
{
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Agent::Libelle);

    QList<agent> agentsConnectes;
    QList<bool> activites_agentsConnectes;
    foreach(QSqlRecord r, records)
    {
        agent ag(r);
        if(ag.connecte())
        {
            agentsConnectes << ag;
            activites_agentsConnectes << ag.activites();
        }
    }

    if(!agentsConnectes.isEmpty())
    {
        // tester la connection
        BDWait().wait(5500);
        for(int i = 0; i < agentsConnectes.count(); i++)
        {
            agent ag1(agentsConnectes.at(i));
            ag1.actualiser();
            if(ag1.activites() == activites_agentsConnectes.at(i))
            {
                // fausse connection
                ag1.setConnecte(false);
                ag1.setEtatFinConnection(false);
                ag1.enregistrer();
            }
        }
    }
}
