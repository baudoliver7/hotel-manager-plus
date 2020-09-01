#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(BDD *db, Horloge *h, QSplashScreen *splash, QString path, int idService, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_db = db;
    ui->frame->setVisible(false);
    m_agent = 0;
    m_chemin = path;
    m_splash = splash;
    m_fermer = true;
    m_horloge = h;
    m_service = new serviceEntreprise(idService);
    ui->frameMessagerie->setVisible(false);
    ui->actionEcrire_et_recevoir_des_messages->setVisible(false);

    ui->actionSe_connecter_au_service_R_ception->setVisible(false);
    ui->actionEcrire_et_recevoir_des_messages->setEnabled(false);

    updateEtatsActions(false);

    m_bilanEnCours = false;
    m_connectReceptEnCours = false;
    setWindowTitle(tr(TITLE).arg(m_service->nom()).arg("déconnecté"));

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
    delete m_agent; m_agent = 0;
    delete m_service;
}

void MainWindow::lancerFenetre()
{
    showMaximized();

    if(m_splash)
    m_splash->finish(this);
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
          on_actionSe_d_connecter_triggered();
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

void MainWindow::on_actionQuitter_triggered()
{
    // préparatifs de ferméture
    close();
}

void MainWindow::on_actionChanger_password_triggered()
{
    BDEditerCptAdmin * bdCptAdmin = new BDEditerCptAdmin(m_agent, this);
    bdCptAdmin->setWindowTitle("Votre compte");

    bool accepte = false;
    do
    {
        accepte = (bdCptAdmin->exec() == QDialog::Accepted);
    }while(!bdCptAdmin->fermer());

    if(accepte)
    {
        ui->menuFichier->setEnabled(true);
    }
    delete bdCptAdmin;
}

void MainWindow::on_actionSe_connecter_triggered()
{
    afficherFormConnexion();
}

void MainWindow::on_actionSe_d_connecter_triggered()
{
    if(activeMdiService() && activeMdiService()->seDeconnecter())
    {
        deconnecter();
        afficherFormConnexion();
    }
}

void MainWindow::on_actionA_propos_de_Hotel_Manager_Plus_triggered()
{
    BDApropos * bdPropos = new BDApropos(this);
    bdPropos->exec();

    delete bdPropos;
}

void MainWindow::updateEtatsActions(bool connecte)
{
    ui->actionSe_connecter->setEnabled(!connecte);
    ui->actionActiver_son_compte->setEnabled(!connecte);

    ui->actionFacture_non_pay->setEnabled(connecte);
    ui->actionSe_d_connecter->setEnabled(connecte);
    ui->actionChanger_password->setEnabled(connecte);
    ui->actionD_biter_un_compte_client->setEnabled(connecte);
    ui->actionCr_er_un_compte_client->setEnabled(connecte);
    ui->actionConfigurer_mes_tables->setEnabled(connecte);
    ui->actionConfigurer_mon_module->setEnabled(connecte);
    ui->actionActualiser_onglet_actif->setEnabled(connecte);
}

agent * MainWindow::utilisateur()
{
    return m_agent;
}

void MainWindow::updateActivitesAgent()
{
    if(m_agent)
    {
        m_agent->setConnecte(true);
        m_agent->setEtatFinConnection(true);

        if(m_agent->activites())
        {
            m_agent->setActivites(false);
        }else
        {
            m_agent->setActivites(true);
        }

        m_agent->enregistrer();
    }
}

void MainWindow::on_actionActiver_son_compte_triggered()
{
    BDActiverNvCpte * bdActiverNvCpte = new BDActiverNvCpte(m_service->idSe()
                                                            , this);
    bdActiverNvCpte->setWindowTitle("Activer un nouveau compte");

    do
    {
        bdActiverNvCpte->exec();
    }while(!bdActiverNvCpte->fermer());

    delete bdActiverNvCpte;
}

MdiService * MainWindow::activeMdiService()
{
    if(ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiService *>(ui->mdiArea->activeSubWindow()->widget());

    return 0;
}

MdiService*  MainWindow::newMdiService()
{
    MdiService* mdi = new MdiService(m_db, m_agent, m_horloge, m_chemin, this);

    // Le titre de la fenêtre est déjà géré dans son constructeur
    //mdi->setWindowTitle(tr("Bienvenue au service %1!").arg(m_service->nom()));

    ui->mdiArea->addSubWindow(mdi);

    connect(mdi, SIGNAL(closed()), this, SLOT(deconnecter()));
    connect(this, SIGNAL(actualiserMdi()), mdi, SLOT(actualiserFenetre()));
    connect(this, SIGNAL(actualiserTables()), mdi, SLOT(chargerTables()));
    connect(this, SIGNAL(actualiserCategories(bool)), mdi, SLOT(setConfigModule(bool)));
    connect(ui->actionActualiser_onglet_actif, SIGNAL(triggered()), mdi, SLOT(actualiserOngletActif()));

    mdi->showMaximized();
    return mdi;
}

void MainWindow::fermerMdiService()
{
    ui->mdiArea->closeAllSubWindows();
}

void MainWindow::initialiserMessagerie()
{
//    m_bdMessagerie = new BDMessagerie( m_agent
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
//    ui->actionEcrire_et_recevoir_des_messages->setEnabled(true);
//
//    connect(ui->actionEcrire_et_recevoir_des_messages, SIGNAL(triggered(bool)), m_bdMessagerie, SLOT(show()));
//
    ui->frame->setVisible(true);
}

void MainWindow::terminerMessagerie()
{
    ui->frame->setVisible(false);
//    ui->actionEcrire_et_recevoir_des_messages->setEnabled(false);
//
//    delete m_bdMessagerie;
}

void MainWindow::initialiserService()
{
    QDateTime now = Horloge::currentDateTime();

    m_heuresConnections = new service();
    m_heuresConnections->setHeureDebut(now);
    m_heuresConnections->setHeureFin(now);
    m_heuresConnections->setMatriculeAgent(m_agent->matricule());
    m_heuresConnections->enregistrer();

    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(updateHeureFin()));
    connect(m_horloge, SIGNAL(connexionIsBroken()), this, SLOT(warningDBState()));
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

void MainWindow::deconnecter()
{
    fermerMdiService();
    terminerMessagerie();
    terminerService();

    m_agent->setConnecte(false);
    m_agent->setEtatFinConnection(false);
    m_agent->setCodeDeSortie(0);
    m_agent->enregistrer();
    updateEtatsActions(false);

    m_fermer = true;
    setWindowTitle(tr(TITLE).arg(m_service->nom()).arg("déconnecté"));
    delete m_agent; m_agent = 0;
}

void MainWindow::on_actionFacture_non_pay_triggered()
{
    BDReglerFacture * bd = new BDReglerFacture(m_db, *m_agent, this);
    bd->setWindowTitle("Rechercher des factures non payées");

    bd->exec();

    if(bd->modified())
    {
        emit actualiserMdi();
    }

    delete bd;
}

void MainWindow::on_actionCr_er_un_compte_client_triggered()
{
    BDCreerUnCompteClient * bd = new BDCreerUnCompteClient(m_db, *m_agent, this);
    bd->setWindowTitle("Créer un compte client");

    bd->exec();

    delete bd;

    emit actualiserMdi();
}

void MainWindow::on_actionD_biter_un_compte_client_triggered()
{
    BDDebiterUnCompteClient * bd = new BDDebiterUnCompteClient(m_db, *m_agent, this);
    bd->setWindowTitle("Débiter/créditer un compte client");

    bd->exec();

    delete bd;

    emit actualiserMdi();
}

void MainWindow::updateHeureFin()
{
    if(m_heuresConnections)
    {
        m_heuresConnections->setHeureFin(Horloge::currentDateTime());
        m_heuresConnections->enregistrer();
    }
}

void MainWindow::terminerService()
{
    updateHeureFin();
    delete m_heuresConnections; m_heuresConnections = 0;
}

void MainWindow::on_actionConfigurer_mes_tables_triggered()
{
    BDConfigurerTableResto * bd = new BDConfigurerTableResto(activeMdiService()->estBar(), this);
    bd->setWindowTitle("Configurer mes tables");

    bd->exec();

    // actualiser tables libres
    emit actualiserTables();

    delete bd;
}

void MainWindow::on_actionConfigurer_mon_module_triggered()
{
    BDConfigurerModule bd(this);
    bd.setWindowTitle("Configurer mon module");

    if((bd.exec() == QDialog::Accepted) && bd.modified())
    {
        emit actualiserCategories(bd.barEstChoisi());
    }
}

void MainWindow::afficherFormConnexion()
{
    if(activeMdiFormConnexion())
    {
        activeMdiFormConnexion()->showMaximized();
    }else
    {
        FormConnexion * fc = new FormConnexion(m_service, this);
        fc->setWindowTitle(tr("Se connecter au service %1").arg(m_service->nom()));
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

FormConnexion * MainWindow::activeMdiFormConnexion()
{
    if(ui->mdiArea->activeSubWindow())
        return qobject_cast<FormConnexion *>(ui->mdiArea->activeSubWindow()->widget());

    return 0;
}

void MainWindow::seConnecterAuService()
{
    m_agent = new agent(activeMdiFormConnexion()->utilisateur());
    fermerFormConnexion();

    updateEtatsActions(true);
    setWindowTitle(tr(TITLE).arg(m_service->nom()).arg("connecté"));

    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(afficherHorloge()));
    afficherHorloge();
    afficherDateDeConnection();

    initialiserMessagerie();
    initialiserService();

    newMdiService();
    m_fermer = false;
}
