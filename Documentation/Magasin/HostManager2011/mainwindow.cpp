#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_gestionClientele = 0;

    setEnableActionsCompteRecepteur(false);
    setWindowTitlePlusEtatConnexion(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(m_gestionClientele) delete m_gestionClientele;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent * e)
{
    if(!ui->mdiArea->subWindowList().isEmpty())
    {
        if(!activeMdiServiceReception()->seDeconnecter())
        {
            e->ignore();
            return;
        }

        delete m_utilisateur;
    }
}

bool MainWindow::seConnecterAuServiceReception()
{
    bool connecte = false;
    DialogConnexion * bdConnexion = new DialogConnexion(this);

    if(bdConnexion->exec() == DialogConnexion::Accepted)
    {
        connecte = true;
        m_utilisateur = new recepteur(bdConnexion->utilisateur());

        // actualiser le titre de la fenetre
        setWindowTitlePlusEtatConnexion(true);

        // activer etat actions compte récepteur
        setEnableActionsCompteRecepteur(true);

        afficherUneNouvelleMdiServiceReception();

        // enregistrer le début du service en cours
        m_service = new service();
        m_service->setHeureDebut(QDateTime::currentDateTime());
        m_service->setMatriculeRecepteur(m_utilisateur->matricule());
        m_service->enregistrer();
    }

    delete bdConnexion;

    return connecte;
}

bool MainWindow::seConnecterALaBDGestionDeLaClientele()
{
//    m_gestionClientele = new BDD("QODBC");
//    QString nomDeBDD = "DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access};DBQ=../data/Gestion de la clientèle.accdb";
//    return m_gestionClientele->seConnecter(nomDeBDD);

    m_gestionClientele = new BDD("QODBC");
    m_gestionClientele->setDatabaseName("clientele");
    m_gestionClientele->setHostName("localhost");
    m_gestionClientele->setUserName("root");
    m_gestionClientele->setPort(3306);

    if(!m_gestionClientele->open())
    {
        QMessageBox::warning(this, "Erreur de connection", tr("Impossible de se connecter à la base de données: %1").arg(m_gestionClientele->lastError().text()));
        return false;
    }

    return true;
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionSeConnecter_triggered()
{
    seConnecterAuServiceReception();
}

void MainWindow::setEnableActionsCompteRecepteur(bool enabled)
{
    ui->actionSeConnecter->setEnabled(!enabled);
    ui->actionActiver_son_de_compagnon->setEnabled(enabled);
    ui->actionRechercherUnClient->setEnabled(enabled);
    ui->actionRechercherUneReservation->setEnabled(enabled);
    ui->actionRechercherUneOccupation->setEnabled(enabled);
    ui->actionTaches_du_service_en_cours->setEnabled(enabled);
    ui->actionSeDeconnecter->setEnabled(enabled);
}

void MainWindow::setWindowTitlePlusEtatConnexion(bool connecte)
{
    QString title = "Hotel Manager 2012 - Réception ";
    if(connecte)
    {
        title.append("[Statut: connecté]");
    }else
    {
        title.append("[Statut: déconnecté]");
    }

    setWindowTitle(title);
}

void MainWindow::on_actionSeDeconnecter_triggered()
{
    fermerMdiServiceReception();
}

void MainWindow::afficherUneNouvelleMdiServiceReception()
{
    MdiServiceReception * mdiServiceReception = new MdiServiceReception(m_utilisateur,this);
    mdiServiceReception->setWindowTitle("Bienvenue au service Réception!");
    ui->mdiArea->addSubWindow(mdiServiceReception);

    connect(mdiServiceReception, SIGNAL(closed()), this, SLOT(etablirEtat_Deconnection()));
    connect(this, SIGNAL(remplirOccuper(client)), mdiServiceReception, SLOT(remplirOccuperUneChambre(client)));
    connect(this, SIGNAL(remplirReserver(client)), mdiServiceReception, SLOT(remplirReserverUneChambre(client)));
    mdiServiceReception->showMaximized();

    ui->actionActiver_son_de_compagnon->setChecked(mdiServiceReception->compagnonFidele()->volumeMuted());
}

void MainWindow::fermerMdiServiceReception()
{
    ui->mdiArea->closeAllSubWindows();
    m_service->setHeureFin(QDateTime::currentDateTime());
    m_service->enregistrer();
}

MdiServiceReception * MainWindow::activeMdiServiceReception()
{
    if(ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiServiceReception *>(ui->mdiArea->activeSubWindow()->widget());

    return 0;
}

void MainWindow::etablirEtat_Connection()
{
    setEnableActionsCompteRecepteur(true);
    setWindowTitlePlusEtatConnexion(true);
}

void MainWindow::etablirEtat_Deconnection()
{
    setEnableActionsCompteRecepteur(false);
    setWindowTitlePlusEtatConnexion(false);

    delete m_utilisateur;
}

void MainWindow::on_actionRechercherUnClient_triggered()
{
    rechercherUnClient();
}

void MainWindow::rechercherUnClient()
{
    DialogRechercherUnClient * dbRechercherUnClient = new DialogRechercherUnClient(this);

    if(dbRechercherUnClient->exec())
    {
        client cl(dbRechercherUnClient->clientChoisi());
        if(dbRechercherUnClient->occuperUneChambre())
        {
            emit remplirOccuper(cl);
        }else
        {
            emit remplirReserver(cl);
        }
    }

    delete dbRechercherUnClient;
}

void MainWindow::on_actionRechercherUneOccupation_triggered()
{
    DgRechercherUneOccupation * dgRechUneOccup = new DgRechercherUneOccupation(this);
    dgRechUneOccup->exec();
    delete dgRechUneOccup;
}

void MainWindow::on_actionRechercherUneReservation_triggered()
{
    DgRechercherUneReserv * dgRechUneReserv = new DgRechercherUneReserv(this);

    connect(dgRechUneReserv, SIGNAL(remplirOccupation(reservation)), activeMdiServiceReception(), SLOT(remplirOccuperUneChambre(reservation)));
    dgRechUneReserv->exec();

    delete dgRechUneReserv;
}

void MainWindow::on_actionActiver_son_de_compagnon_triggered(bool checked)
{
    activeMdiServiceReception()->compagnonFidele()->setMuteVolume(checked);

    QFile file("options.txt");
    if(file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream out(&file);
        out << "Mute = " << QString::number(checked);

        file.close();
    }        
}
