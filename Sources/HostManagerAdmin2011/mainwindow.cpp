#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(BDD * db, Horloge *h, QSplashScreen *splash, QString path, int idService, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_db = db;
    m_admin = 0;
    m_chemin = path;
    m_splash = splash;
    m_fermer = true;
    m_horloge = h;
    m_service = new serviceEntreprise(idService);
    ui->actionEcrire_et_recevoir_des_messages->setVisible(false);

    initialiserProgressBar();

    ui->actionAjusterDateHeure->setVisible(false);
    ui->actionSe_connecter_au_service_R_ception->setVisible(false);

    updateEtatsActions(false);

    m_bilanEnCours = false;
    setWindowTitle(tr(TITLE).arg(m_service->nom()).arg("déconnecté"));

    //connect(m_horloge, SIGNAL(fiveSecsOvered()), this, SLOT(updateActivitesAgent()));    
    connect(m_horloge, SIGNAL(connexionIsBroken()), this, SLOT(warningDBState()));

    m_bdWaiting = new BDWaiting(this);

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
    delete m_admin; m_admin = 0;
    delete m_service;
    delete m_bdWaiting;
}

void MainWindow::lancerFenetre()
{
    showMaximized();

    if(m_splash)
    m_splash->finish(this);

    //QTimer::singleShot(500, this, SLOT(nouveauCompteAdmin()));
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

void MainWindow::on_actionConfigurer_les_chambres_triggered()
{
    ui->actionConfigurer_les_chambres->setEnabled(false);
    m_bdWaiting->show();

    QTimer::singleShot(5, this, SLOT(configurerChambres()));
}

void MainWindow::on_actionGererDesComptesRecepteur_triggered()
{
    DialogGererCompteRecepteur * dialog = new DialogGererCompteRecepteur(m_admin, this);
    dialog->setWindowTitle("Gérer les comptes");
    dialog->exec();

    delete dialog;
}

void MainWindow::on_actionChanger_password_triggered()
{
    BDEditerCptAdmin * bdCptAdmin = new BDEditerCptAdmin(m_admin, this);
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

MdiBilanActivitesReception * MainWindow::mdiBilanActivitesReceptionEnCours()
{
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList())
    {
        MdiBilanActivitesReception * mdiChild = qobject_cast<MdiBilanActivitesReception *>(window->widget());
        if(mdiChild) return mdiChild;
    }

    return 0;
}

MdiPlanning * MainWindow::mdiPlanningEnCours()
{
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList())
    {
        MdiPlanning * mdiChild = qobject_cast<MdiPlanning *>(window->widget());
        if(mdiChild) return mdiChild;
    }

    return 0;
}

QMdiSubWindow * MainWindow::windowOfMdiBilanActivitesReceptionEnCours()
{
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList())
    {
        MdiBilanActivitesReception * mdiChild = qobject_cast<MdiBilanActivitesReception *>(window->widget());
        if(mdiChild) return window;
    }

    return 0;
}

QMdiSubWindow * MainWindow::windowOfMdiPlanningEnCours()
{
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList())
    {
        MdiPlanning * mdiChild = qobject_cast<MdiPlanning *>(window->widget());
        if(mdiChild) return window;
    }

    return 0;
}

void MainWindow::on_actionBilanActivitesReception_triggered()
{
    if(mdiBilanActivitesReceptionEnCours())
    {
        ui->mdiArea->setActiveSubWindow(windowOfMdiBilanActivitesReceptionEnCours());
        return;
    }

    ui->actionBilanActivitesReception->setEnabled(false);
    MdiBilanActivitesReception * mdi = new MdiBilanActivitesReception(m_admin, m_chemin, m_horloge, m_service, m_dateDeConnection, this);
    mdi->setWindowTitle(tr("Bienvenue au service %1!").arg(m_service->nom()));
    ui->mdiArea->addSubWindow(mdi);
    //ui->actionBilanActivitesReception->setEnabled(false);
    ui->actionEcrire_et_recevoir_des_messages->setEnabled(true);
    m_bilanEnCours = true;

    connect(mdi, SIGNAL(closed()), this, SLOT(closeBilan()));
    //connect(ui->actionEcrire_et_recevoir_des_messages, SIGNAL(triggered(bool)), mdi->bdMessagerie(), SLOT(show()));
    connect(mdi, SIGNAL(debuterTraitement()), this, SLOT(debuterProgressBar()));
    connect(mdi, SIGNAL(terminerTraitement()), this, SLOT(terminerProgressBar()));
    connect(mdi, SIGNAL(updateProgressBar(int)), m_progressBar, SLOT(setValue(int)));

    mdi->showMaximized();

    ui->actionBilanActivitesReception->setEnabled(true);
}

void MainWindow::closeBilan()
{            
    m_fermer = true;
}

void MainWindow::on_actionSe_connecter_triggered()
{
    afficherFormConnexion();
}

void MainWindow::on_actionSe_d_connecter_triggered()
{
    if(QMessageBox::question(this, "Déconnexion", "Désirez-vous vous déconnecter?", "Oui", "Non") == 0)
    {
        ui->mdiArea->closeAllSubWindows();
        m_admin->setConnecte(false);
        m_admin->setEtatFinConnection(false);
        m_admin->setCodeDeSortie(0);
        m_admin->enregistrer();
        updateEtatsActions(false);

        m_fermer = true;
        setWindowTitle(tr(TITLE).arg(m_service->nom()).arg("déconnecté"));
        delete m_admin; m_admin = 0;

        afficherFormConnexion();
    }
}

void MainWindow::nouveauCompteAdmin()
{
    m_admin = new agent("ADMIN");
    if(m_admin->statut() == agent::EnAttente)
    {
        on_actionChanger_password_triggered();
    }else
    {
        ui->menuFichier->setEnabled(true);
    }

    delete m_admin; m_admin = 0;
}

void MainWindow::on_actionConfigurer_heures_de_sortie_triggered()
{
    BDConfigHeureSortie * bdConfig = new BDConfigHeureSortie(this);
    bdConfig->setWindowTitle("Heures limites");
    bdConfig->exec();

    delete bdConfig;
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
    ui->actionSe_d_connecter->setEnabled(connecte);
    ui->actionBilanActivitesReception->setEnabled(connecte);
    ui->actionLa_r_ception->setEnabled(connecte);
    ui->actionActualiser->setEnabled(connecte);
    ui->actionConfigurer_taux_des_taxes->setEnabled(connecte);

    ui->actionChanger_password->setEnabled(connecte);
    ui->actionConfigurer_les_chambres->setEnabled(connecte);
    ui->actionConfigurer_type_de_client->setEnabled(connecte);
    ui->actionConfigurer_heures_de_sortie->setEnabled(connecte);
    ui->actionGererDesComptesRecepteur->setEnabled(connecte);
    ui->actionHistorique_des_bilans_journaliers->setEnabled(connecte);

    ui->actionObserver_la_tr_sorerie->setEnabled(connecte);
    ui->actionEcrire_et_recevoir_des_messages->setEnabled(connecte);
    ui->actionInformations_g_n_rales->setEnabled(connecte);
    ui->actionConfigurer_le_menu_du_restaurant->setEnabled(connecte);

    ui->actionActiver_son_compte->setEnabled(!connecte);
    ui->actionRenseigner_les_informations_sur_votre_h_tel->setEnabled(connecte);
    ui->actionVisualiser_le_cardex->setEnabled(connecte);
}

agent * MainWindow::utilisateur()
{
    return m_admin;
}

void MainWindow::updateActivitesAgent()
{
    if(m_admin)
    {
        m_admin->setConnecte(true);
        m_admin->setEtatFinConnection(true);

        if(m_admin->activites())
        {
            m_admin->setActivites(false);
        }else
        {
            m_admin->setActivites(true);
        }

        m_admin->enregistrer();
    }
}

void MainWindow::on_actionActiver_son_compte_triggered()
{
    BDActiverNvCpte * bdActiverNvCpte = new BDActiverNvCpte(m_service->idSe(), this);
    bdActiverNvCpte->setWindowTitle("Activer un nouveau compte");

    do
    {
        bdActiverNvCpte->exec();
    }while(!bdActiverNvCpte->fermer());

    delete bdActiverNvCpte;
}

void MainWindow::on_actionRenseigner_les_informations_sur_votre_h_tel_triggered()
{
    BDInfosHotels * bd = new BDInfosHotels(this);
    bd->setWindowTitle("Informations sur votre hôtel");

    bd->exec();
    delete bd;
}

void MainWindow::on_actionConfigurer_le_menu_du_restaurant_triggered()
{
    BDConfigurerMenuResto * bd = new BDConfigurerMenuResto(this);
    bd->setWindowTitle("Configurer le menu du restaurant");

    bd->exec();

    delete bd;
}

void MainWindow::initialiserProgressBar()
{
    m_progressBar = new QProgressBar;
    m_progressBar->setFixedSize(200, 15);
    m_progressBar->setRange(0, 100);
    ui->statusBar->addWidget(m_progressBar);
    m_progressBar->setVisible(false);
}

void MainWindow::debuterProgressBar()
{
    m_progressBar->setVisible(true);
    m_progressBar->setValue(0);
}

void MainWindow::terminerProgressBar()
{
    m_progressBar->setValue(100);
    m_progressBar->setVisible(false);
}

void MainWindow::updateProgressBar()
{
    if(m_progressBar->isVisible())
    {
        m_progressBar->setValue(m_progressBar->value() + 10);
    }
}

void MainWindow::on_actionVisualiser_le_cardex_triggered()
{
    BDCardex * bd = new BDCardex(this);

    bd->setWindowTitle("Visualiser le cardex");
    bd->exec();

    delete bd;
}

void MainWindow::configurerChambres()
{
    DialogConfigChambre * dialog = new DialogConfigChambre(this);
    dialog->setWindowTitle("Configurer les chambres et les profiles client");
    m_bdWaiting->close();

    dialog->exec();
    delete dialog;

    ui->actionConfigurer_les_chambres->setEnabled(true);
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
    m_admin = new agent(activeMdiFormConnexion()->utilisateur());
    fermerFormConnexion();

    updateEtatsActions(true);

    m_dateDeConnection = Horloge::currentDateTime();
    on_actionBilanActivitesReception_triggered();
    m_fermer = false;
    setWindowTitle(tr(TITLE).arg(m_service->nom()).arg("connecté"));
}

void MainWindow::on_actionConfigurer_taux_des_taxes_triggered()
{
    BDConfigTaux bd(this);

    bd.exec();
}

void MainWindow::on_actionLa_r_ception_triggered()
{    
    if(mdiPlanningEnCours())
    {
        ui->mdiArea->setActiveSubWindow(windowOfMdiPlanningEnCours());
        return;
    }

    ui->actionLa_r_ception->setEnabled(false);
    MdiPlanning * mdi = new MdiPlanning(m_db, *m_admin, m_horloge, this, true, true);
    mdi->setWindowTitle(tr("Visualiser la réception"));
    ui->mdiArea->addSubWindow(mdi);            

    mdi->showMaximized();   

    ui->actionLa_r_ception->setEnabled(true);
}

void MainWindow::on_actionActualiser_triggered()
{
    if(!mdiBilanActivitesReceptionEnCours() && !mdiPlanningEnCours()) // si une fenetre n'est pas ouverte
        return;

    ui->actionActualiser->setEnabled(false);
    m_bdWaiting->show(); // waiting...
    QTimer::singleShot(5, this, SLOT(actualiserFenetre()));
}

void MainWindow::actualiserFenetre()
{
    if(mdiBilanActivitesReceptionEnCours())
    {
        mdiBilanActivitesReceptionEnCours()->actualiserOngletActif();
    }else
    {
        if(mdiPlanningEnCours())
        {
            mdiPlanningEnCours()->actualiserOngletActif();
        }
    }

    m_bdWaiting->close();
    ui->actionActualiser->setEnabled(true);
}
