#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(BDD *db, Horloge *h, QSplashScreen *splash, QString path, int idService, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_db = db;
    m_fermer = true;
    ui->actionPlanning_complet->setVisible(false);
    ui->actionFen_tre_visuelle->setVisible(false);
    ui->actionEnvoyer_et_ou_recevoir_des_messages->setVisible(false);
    ui->frameMessagerie->setVisible(false);

    ui->actionRechercherUneOccupation->setVisible(false);
    ui->actionRechercherUneReservation->setVisible(false);
    ui->actionAfficher_locations->setEnabled(false);
    ui->actionAfficher_r_servations->setEnabled(false);
    ui->actionAfficher_r_servations_locations->setEnabled(false);

    m_connecte = false;
    m_serviceEntreprise = new serviceEntreprise(idService);
    m_chemin = path;
    m_splash = splash;
    ui->actionAjuster_Heure_Date->setVisible(false);
    m_gestionClientele = 0;
    m_horloge = h;
    m_utilisateur = 0;

    ui->frame->setVisible(false);
    ui->actionEnvoyer_et_ou_recevoir_des_messages->setEnabled(false);

    ui->actionEnregistrer_passe->setVisible(false);
    ui->actionRechercherUnClient->setVisible(false);

    setEnableActionsCompteRecepteur(false);
    setWindowTitlePlusEtatConnexion(false);

    m_bdWaiting = new BDWaiting(this);

    //connect(m_horloge, SIGNAL(fiveSecsOvered()), this, SLOT(updateActivitesAgent()));
    afficherFormConnexion();
}

void MainWindow::warningDBState()
{
    bool connected = false;
    bool fermerApp = false;
    do
    {
        if(QMessageBox::information(0
                                     , "Problème de connexion"
                                     , "La connexion à la base de données a été interrompue. \n\n"
                                     ,"Reconnecter", "Quitter l'application") == 0)
        {
            if(m_db->open())
            {
                connected = true;
            }else
            {
                QMessageBox::warning(0, "Echec de connexion", QObject::tr("Impossible de se connecter à la base de données: %1").arg(m_db->lastError().text()));
            }
        }else
        {
            fermerApp = true;
            m_horloge->quitApp();
        }
    }while(!connected && !fermerApp);

    if(connected)
    {
        m_horloge->restartHorloge();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    if(m_gestionClientele) delete m_gestionClientele;
    delete m_serviceEntreprise;

    delete m_bdWaiting;
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
    bool accepter;
      if(m_fermer)
      {
          accepter = true;
      }else
      {
          on_actionSeDeconnecter_triggered();
          if(m_fermer)
          {
              accepter = true;
          }else
          {
              accepter = false;
          }
      }

      if(accepter)
      {
          QMainWindow::closeEvent(e);
          e->accept();
      }else
      {
          e->ignore();
      }
}

void MainWindow::lancerFenetre()
{
    this->showMaximized();
    if(m_splash)
        m_splash->finish(this);
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
    afficherFormConnexion();
}

void MainWindow::setEnableActionsCompteRecepteur(bool enabled)
{
    ui->actionEnregistrer_passe->setEnabled(enabled);
    ui->actionActualiser_la_fen_tre->setEnabled(enabled);
    ui->actionEditer_votre_compte->setEnabled(enabled);
    ui->actionActiver_un_nouveau_compte->setEnabled(!enabled);
    ui->actionSeConnecter->setEnabled(!enabled);
    ui->actionActiver_son_de_compagnon->setEnabled(enabled);
    ui->actionRechercherUnClient->setEnabled(enabled);
    ui->actionRechercherUneReservation->setEnabled(enabled);
    ui->actionRechercherUneOccupation->setEnabled(enabled);
    ui->actionTaches_du_service_en_cours->setEnabled(enabled);
    ui->actionSeDeconnecter->setEnabled(enabled);

    ui->actionPlanning_complet->setEnabled(enabled);
    ui->actionFen_tre_visuelle->setEnabled(enabled);

    ui->frame->setVisible(enabled);
    //ui->frameMessagerie->setVisible(enabled);
    ui->actionEnvoyer_et_ou_recevoir_des_messages->setEnabled(enabled);

    ui->actionCreer_Un_compte_client->setEnabled(enabled);
    ui->actionCreer_Un_groupe_de_client->setEnabled(enabled);
    ui->actionDebiterUnCompteClient->setEnabled(enabled);
    ui->actionFacturer_un_groupe_de_client->setEnabled(enabled);
    ui->actionAjouter_un_client_un_groupe->setEnabled(enabled);
    ui->actionRechercher_un_groupe_de_client->setEnabled(enabled);
    ui->actionEditer_le_cardex->setEnabled(enabled);

    ui->actionEnregistrer_tout->setEnabled(false);
}

void MainWindow::setWindowTitlePlusEtatConnexion(bool connecte)
{
    QString title;
    if(connecte)
    {
        title = QString(TITLE).arg(m_serviceEntreprise->nom()).arg("connecté");
    }else
    {
        title = QString(TITLE).arg(m_serviceEntreprise->nom()).arg("déconnecté");
    }

    setWindowTitle(title);
}

void MainWindow::on_actionSeDeconnecter_triggered()
{
    if(activeMdiPlanning() && activeMdiPlanning()->seDeconnecter())
    {
        deconnecter();
    }
}

void MainWindow::initialiserService()
{
    m_service = new service();
    m_service->setHeureDebut(Horloge::currentDateTime());
    m_service->setMatriculeAgent(m_utilisateur->matricule());
    m_service->setHeureFin(Horloge::currentDateTime());
    m_service->enregistrer();

    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(updateHeureFin()));
    connect(m_horloge, SIGNAL(connexionIsBroken()), this, SLOT(warningDBState()));    
}

void MainWindow::updateHeureFin()
{
    if(m_service)
    {
        m_service->setHeureFin(Horloge::currentDateTime());
        m_service->enregistrer();
    }
}

void MainWindow::terminerService()
{
    updateHeureFin();
    delete m_service; m_service = 0;
}

void MainWindow::newMdiPlanningSimplifie()
{
//    MdiServiceReception * mdiServiceReception = new MdiServiceReception(m_utilisateur, m_horloge, m_chemin, this);
//    mdiServiceReception->setWindowTitle("Bienvenue au service Réception!");
//    ui->mdiArea->addSubWindow(mdiServiceReception);
//
//    mdiServiceReception->showMaximized();
//
//    ui->actionActiver_son_de_compagnon->setChecked(mdiServiceReception->compagnonFidele()->volumeMuted());
}

void MainWindow::newMdiPlanningComplet()
{
    MdiPlanning * mdi = new MdiPlanning(m_db, *m_utilisateur, m_horloge, this);
    mdi->setWindowTitle("Bienvenue au service Réception!");
    ui->mdiArea->addSubWindow(mdi);

    connect(ui->actionAfficher_locations, SIGNAL(triggered(bool)), mdi, SLOT(afficherLocations()));
    connect(ui->actionAfficher_r_servations, SIGNAL(triggered(bool)), mdi, SLOT(afficherReservations()));
    connect(ui->actionAfficher_r_servations_locations, SIGNAL(triggered(bool)), mdi, SLOT(afficherMixte()));
    connect(this, SIGNAL(groupeFacture(QList<occupation>)), mdi, SLOT(actualiserFenetre(QList<occupation>)));
    connect(mdi, SIGNAL(closed()), this, SLOT(deconnecter()));
    connect(mdi, SIGNAL(planningModifie(bool)), ui->actionEnregistrer_tout, SLOT(setEnabled(bool)));

    ui->actionAfficher_locations->setEnabled(true);
    ui->actionAfficher_r_servations->setEnabled(true);
    ui->actionAfficher_r_servations_locations->setEnabled(true);

    mdi->showMaximized();
}

void MainWindow::fermerPlanningSimplifie()
{
    ui->mdiArea->closeAllSubWindows();
}

FormConnexion * MainWindow::activeMdiFormConnexion()
{
    if(ui->mdiArea->activeSubWindow())
        return qobject_cast<FormConnexion *>(ui->mdiArea->activeSubWindow()->widget());

    return 0;
}

MdiPlanning * MainWindow::activeMdiPlanning()
{
    if(ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiPlanning *>(ui->mdiArea->activeSubWindow()->widget());

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
}

void MainWindow::on_actionRechercherUnClient_triggered()
{
    rechercherUnClient();
}

void MainWindow::rechercherUnClient()
{
    DialogRechercherUnClient * dbRechercherUnClient = new DialogRechercherUnClient(m_utilisateur, this);

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
    DgRechercherUneOccupation * dgRechUneOccup = new DgRechercherUneOccupation(m_utilisateur, this);
    dgRechUneOccup->setWindowTitle("Rechercher une location");
    //connect(dgRechUneOccup, SIGNAL(bdModifie()), activeMdiServiceReception(), SLOT(actualiserFenetreBDModifiee()));
    dgRechUneOccup->exec();

//    if(dgRechUneOccup->nbOccupArretee() > 0)
//        emit activeMdiServiceReception()->avertirOccupationArretee(dgRechUneOccup->nbOccupArretee());

    delete dgRechUneOccup;
}

void MainWindow::on_actionRechercherUneReservation_triggered()
{
//    DgRechercherUneReserv * dgRechUneReserv = new DgRechercherUneReserv(m_utilisateur, this);
//
//    connect(dgRechUneReserv, SIGNAL(remplirOccupation(chambreReservee)), activeMdiServiceReception(), SLOT(remplirOccuperUneChambre(chambreReservee)));
//    connect(dgRechUneReserv, SIGNAL(bdModifie()), activeMdiServiceReception(), SLOT(actualiserFenetreBDModifiee()));
//    dgRechUneReserv->exec();
//
////    if(dgRechUneReserv->nbReservAnnulee() > 0)
////        emit activeMdiServiceReception()->avertirReservationAnnulee(dgRechUneReserv->nbReservAnnulee());
//
//    delete dgRechUneReserv;
}

void MainWindow::on_actionActiver_son_de_compagnon_triggered(bool checked)
{
//    activeMdiServiceReception()->compagnonFidele()->setMuteVolume(checked);
//
//    QSettings settings(APPNAME, PRODUCTNAME);
//    settings.setValue(MUTED, checked);
}

void MainWindow::on_actionActiver_un_nouveau_compte_triggered()
{
    BDActiverNvCpte * bdActiverNvCpte = new BDActiverNvCpte(m_serviceEntreprise->idSe()
                                                            , this);
    bdActiverNvCpte->setWindowTitle("Activer un nouveau compte");

    do
    {
        bdActiverNvCpte->exec();
    }while(!bdActiverNvCpte->fermer());

    delete bdActiverNvCpte;
}

void MainWindow::on_actionEditer_votre_compte_triggered()
{
    BDEditerCptAdmin * bdCptAdmin = new BDEditerCptAdmin(m_utilisateur, this);
    bdCptAdmin->setWindowTitle("Votre compte");

    bool accepte = false;
    do
    {
        accepte = (bdCptAdmin->exec() == QDialog::Accepted);
    }while(!bdCptAdmin->fermer());

    delete bdCptAdmin;
}

void MainWindow::on_actionAjuster_Heure_Date_triggered()
{
    /*BDAjusterHeureSyst * bdAjustHD = new BDAjusterHeureSyst(Horloge::currentDate(), Horloge::currentTime(), this);
    bdAjustHD->setWindowTitle("Adjuster la date et l'heure");

    if(bdAjustHD->exec() == QDialog::Accepted)
    {
        m_horloge->setHeure(bdAjustHD->dateTimeSelectionnee());     
    }

    delete bdAjustHD;*/
}

void MainWindow::on_actionA_propos_de_hotel_manger_plus_triggered()
{
    BDApropos * bdPropos = new BDApropos(this);
    bdPropos->exec();

    delete bdPropos;
}

agent * MainWindow::utilisateur()
{
    return m_utilisateur;
}

void MainWindow::updateActivitesAgent()
{
    if(m_utilisateur)
    {
        m_utilisateur->setConnecte(true);
        m_utilisateur->setEtatFinConnection(true);

        if(m_utilisateur->activites())
        {
            m_utilisateur->setActivites(false);
        }else
        {
            m_utilisateur->setActivites(true);
        }

        m_utilisateur->enregistrer();
    }
}

void MainWindow::initialiserMessagerie()
{
//    m_bdMessagerie = new BDMessagerie( m_utilisateur
//                                      , m_horloge
//                                      , m_chemin
//                                      , ui->btn_lire
//                                      , ui->labelEnveloppe
//                                      , ui->labelNbMsgNonLus
//                                      , this);
//
//    m_bdMessagerie->setWindowModality(Qt::NonModal);
//    m_bdMessagerie->setWindowTitle("Envoyez et/ou recevoir des messages");
//
//    ui->actionEnvoyer_et_ou_recevoir_des_messages->setEnabled(true);
//
//    connect(ui->actionEnvoyer_et_ou_recevoir_des_messages, SIGNAL(triggered(bool)), m_bdMessagerie, SLOT(show()));
}

void MainWindow::afficherHorloge()
{
    QTime now = Horloge::currentTime();
    QStringList heure;
    heure = now.toString(Qt::ISODate).split(":");

    ui->label_horloge->setText(tr("Heure du serveur: %1 h %2 min").arg(heure.first()).arg(heure.at(1)));
}

void MainWindow::afficherDateDeConnection()
{
    QString message = tr("Vous êtes connecté depuis le %1").arg(Horloge::currentDateTime().toString(Qt::SystemLocaleLongDate));
    ui->label_heureDeConnection->setText(message);
}

void MainWindow::terminerMessagerie()
{
    //delete m_bdMessagerie;
}

void MainWindow::on_actionCreer_Un_compte_client_triggered()
{
    BDCreerUnCompteClient bd(m_db, *m_utilisateur, this);
    bd.setWindowTitle("Créer un compte client");

    bd.exec();

    activeMdiPlanning()->chargerActivites(); // on peut faire un dépôt
}

void MainWindow::on_actionCreer_Un_groupe_de_client_triggered()
{
    BDCreerUnGroupe bd(m_db, *m_utilisateur, this);
    bd.setWindowTitle("Créer un groupe de client");

    bd.exec();

    activeMdiPlanning()->chargerActivites(); // on peut faire une avance
}

void MainWindow::on_actionDebiterUnCompteClient_triggered()
{
    BDDebiterUnCompteClient bd(m_db, *m_utilisateur, this);
    bd.setWindowTitle("Débiter/créditer un compte client");

    bd.exec();

    activeMdiPlanning()->chargerActivites();
}

void MainWindow::on_actionAjouter_un_client_un_groupe_triggered()
{
    BDModifierUnGroupeClient * bd = new BDModifierUnGroupeClient(false, this);
    bd->setWindowTitle("Ajouter / Retirer un client d'un groupe");

    bd->exec();
    delete bd;
}

void MainWindow::on_actionFacturer_un_groupe_de_client_triggered()
{
    BDFacturerUnGroupe * bd = new BDFacturerUnGroupe(m_db, *m_utilisateur, this);
    bd->setWindowTitle("Facturer un groupe");

    if(bd->exec() == QDialog::Accepted)
    {
        // faire les actions
        emit groupeFacture(bd->occupationsModifiees());
    }
}

void MainWindow::deconnecter()
{
    ui->mdiArea->closeAllSubWindows();
    terminerMessagerie();
    terminerService();
    setEnableActionsCompteRecepteur(false);
    m_fermer = true;

    setWindowTitle(tr(TITLE).arg(m_serviceEntreprise->nom()).arg("déconnecté"));
    delete m_utilisateur; m_utilisateur = 0;

    afficherFormConnexion();
}

void MainWindow::on_actionRechercher_un_groupe_de_client_triggered()
{
    BDRechercherUnGroupe * bd = new BDRechercherUnGroupe(true, this);
    bd->setWindowTitle("Rechercher un groupe");

    bd->exec();

    delete bd;
}

void MainWindow::on_actionEditer_le_cardex_triggered()
{
    BDCardex * bd = new BDCardex(this);
    bd->setWindowTitle("Visualiser le cardex");

    bd->exec();

    delete bd;
}

void MainWindow::on_actionEnregistrer_tout_triggered()
{
    ui->actionActualiser_la_fen_tre->setEnabled(false);
    m_bdWaiting->show(); // waiting...
    QTimer::singleShot(5, this, SLOT(enregistrerTout()));
}

void MainWindow::enregistrerTout()
{
    activeMdiPlanning()->enregisterTout();
    m_bdWaiting->close();
    ui->actionActualiser_la_fen_tre->setEnabled(true);
}

void MainWindow::on_actionActualiser_la_fen_tre_triggered()
{
    ui->actionActualiser_la_fen_tre->setEnabled(false);
    m_bdWaiting->show(); // waiting...
    QTimer::singleShot(5, this, SLOT(actualiserFenetre()));
}

void MainWindow::actualiserFenetre()
{
    activeMdiPlanning()->actualiserOngletActif();
    m_bdWaiting->close();
    ui->actionActualiser_la_fen_tre->setEnabled(true);
}

void MainWindow::afficherFormConnexion()
{
    if(activeMdiFormConnexion())
    {
        activeMdiFormConnexion()->showMaximized();
    }else
    {
        FormConnexion * fc = new FormConnexion(m_serviceEntreprise, this);
        fc->setWindowTitle(tr("Se connecter au service %1").arg(m_serviceEntreprise->nom()));
        fc->setAttribute(Qt::WA_DeleteOnClose, true);

        connect(fc, SIGNAL(accepted()), this, SLOT(seConnecterAuService()));
        ui->mdiArea->addSubWindow(fc);
        fc->showMaximized();
    }
}

void MainWindow::fermerFormConnexion()
{
    if(activeMdiFormConnexion())
        ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::seConnecterAuService()
{
    m_connecte = true;
    m_utilisateur = new agent(activeMdiFormConnexion()->utilisateur());
    fermerFormConnexion();

    // actualiser le titre de la fenetre
    setWindowTitlePlusEtatConnexion(true);

    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(afficherHorloge()));
    afficherHorloge();
    afficherDateDeConnection();

    // activer etat actions compte récepteur
    setEnableActionsCompteRecepteur(true);
    initialiserMessagerie();
    initialiserService();

    newMdiPlanningComplet();

    afficherHorloge();
    afficherDateDeConnection();
    m_fermer = false;
}
