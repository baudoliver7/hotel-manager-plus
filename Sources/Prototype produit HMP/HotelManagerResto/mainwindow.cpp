#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Horloge *h, QSplashScreen *splash, QString path, int idService, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_agent = 0;
    m_chemin = path;
    m_splash = splash;
    m_fermer = true;
    m_horloge = h;
    m_service = new serviceEntreprise(idService);

    ui->actionSe_connecter_au_service_R_ception->setVisible(false);
    ui->actionEcrire_et_recevoir_des_messages->setEnabled(false);

    updateEtatsActions(false);

    m_bilanEnCours = false;
    m_connectReceptEnCours = false;
    setWindowTitle(tr(TITLE).arg(m_service->nom()).arg("déconnecté"));

    connect(m_horloge, SIGNAL(fiveSecsOvered()), this, SLOT(updateActivitesAgent()));
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
    DialogConnexion * bdConnexion = new DialogConnexion(m_service, this);
    bdConnexion->setWindowTitle(tr("Se connecter au service %1").arg(m_service->nom()));

    if(bdConnexion->exec() == QDialog::Accepted)
    {
        m_agent = new agent(bdConnexion->utilisateur());

        updateEtatsActions(true);
        newMdiService();
        m_fermer = false;
        setWindowTitle(tr(TITLE).arg(m_service->nom()).arg("connecté"));
    }

    delete bdConnexion;
}

void MainWindow::on_actionSe_d_connecter_triggered()
{
    if(activeMdiService() && activeMdiService()->seDeconnecter())
    {
        fermerMdiService();
        m_agent->setConnecte(false);
        m_agent->setEtatFinConnection(false);
        m_agent->setCodeDeSortie(0);
        m_agent->enregistrer();
        updateEtatsActions(false);

        m_fermer = true;
        setWindowTitle(tr(TITLE).arg(m_service->nom()).arg("déconnecté"));
        delete m_agent; m_agent = 0;
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

    ui->actionSe_d_connecter->setEnabled(connecte);
    ui->actionChanger_password->setEnabled(connecte);
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
    MdiService* mdi = new MdiService(m_agent, m_horloge, m_chemin, this);
    mdi->setWindowTitle(tr("Bienvenue au service %1!").arg(m_service->nom()));
    ui->mdiArea->addSubWindow(mdi);

    ui->actionEcrire_et_recevoir_des_messages->setEnabled(true);

    connect(mdi, SIGNAL(closed()), this, SLOT(on_actionSe_d_connecter_triggered()));
    connect(ui->actionEcrire_et_recevoir_des_messages, SIGNAL(triggered(bool)), mdi->bdMessagerie(), SLOT(show()));

    mdi->showMaximized();
    return mdi;
}

void MainWindow::fermerMdiService()
{
    ui->mdiArea->closeAllSubWindows();
    ui->actionEcrire_et_recevoir_des_messages->setEnabled(false);
}
