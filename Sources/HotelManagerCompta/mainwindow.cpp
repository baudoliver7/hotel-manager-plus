#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(BDD *db, Horloge *h, QSplashScreen *splash, QString path, int idService, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_db = db;
    m_chemin = path;
    m_splash = splash;
    m_comptable = 0;
    m_horloge = h;
    m_service = new serviceEntreprise(idService);
    setWindowTitle(tr(TITLE).arg("déconnecté"));
    setEnabledEtatActions(false);
    ui->actionD_terminer_le_compte_r_sultat->setVisible(false);
    ui->actionEnvoyer_et_ou_recevoir_des_messages->setVisible(false);

    //connect(m_horloge, SIGNAL(fiveSecsOvered()), this, SLOT(updateActivitesAgent()));
    connect(m_horloge, SIGNAL(connexionIsBroken()), this, SLOT(warningDBState()));

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
    if(m_comptable) delete m_comptable;
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
    if(activeMdiServiceComptable())
    {
        if(activeMdiServiceComptable()->seDeconnecter())
        {
            fermerMdiServiceComptable();
            QWidget::closeEvent(e);
            e->accept();
        }else
        {
            e->ignore();
        }
    }else
    {
        e->accept();
    }
}

void MainWindow::newMdiServiceComptable()
{
    MdiServiceComptable * mdi = new MdiServiceComptable(m_db, m_comptable, m_horloge, m_chemin, this);
    mdi->setWindowTitle("Service comptabilité");
    ui->mdiArea->addSubWindow(mdi);

    connect(mdi, SIGNAL(closed()), this, SLOT(fermerMdiServiceComptable()));
    connect(mdi, SIGNAL(currentRowIsValid(bool)), ui->actionSupprimer_une_op_ration, SLOT(setEnabled(bool)));

    mdi->showMaximized();
    m_mdi = mdi;

    m_mdi->lancerCurrentRowIsValid(false); // iniber à l'ouverture
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionSe_connecter_triggered()
{
    afficherFormConnexion();
}

void MainWindow::on_actionSe_d_connecter_triggered()
{
    if(activeMdiServiceComptable() && activeMdiServiceComptable()->seDeconnecter())
    {
         fermerMdiServiceComptable();
         afficherFormConnexion();
    }
}

MdiServiceComptable * MainWindow::activeMdiServiceComptable()
{
    if(ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiServiceComptable *>(ui->mdiArea->activeSubWindow()->widget());

    return 0;
}

void MainWindow::setEnabledEtatActions(bool ouvert)
{
    ui->actionActiver_un_nouveau_compte->setEnabled(!ouvert);
    ui->actionEditer_votre_compte->setEnabled(ouvert);
    ui->actionSe_d_connecter->setEnabled(ouvert);
    ui->actionEnvoyer_et_ou_recevoir_des_messages->setEnabled(ouvert);
    ui->actionConfigurer_les_comptes->setEnabled(ouvert);
    ui->actionUne_operation->setEnabled(ouvert);
    ui->actionLa_comptabilit_des_services->setEnabled(ouvert);
    ui->actionMes_comptes_en_arbre->setEnabled(ouvert);
    ui->actionMes_comptes_uniquement->setEnabled(ouvert);
    ui->actionSupprimer_une_op_ration->setEnabled(false);

    ui->actionSe_connecter->setEnabled(!ouvert);
    ui->actionEditer_les_cl_tures->setEnabled(ouvert);
}

void MainWindow::fermerMdiServiceComptable()
{
     ui->mdiArea->closeAllSubWindows();
     setWindowTitle(tr(TITLE).arg("déconnecté"));
     setEnabledEtatActions(false);
     delete m_comptable; m_comptable = 0;
}

void MainWindow::on_actionEditer_votre_compte_triggered()
{
    BDEditerCptAdmin * bdCptAdmin = new BDEditerCptAdmin(m_comptable, this);
    bdCptAdmin->setWindowTitle("Votre compte");

    bool accepte = false;
    do
    {
        accepte = (bdCptAdmin->exec() == QDialog::Accepted);
    }while(!bdCptAdmin->fermer());

    delete bdCptAdmin;
}

void MainWindow::on_actionActiver_un_nouveau_compte_triggered()
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

void MainWindow::on_actionA_propos_de_Hotel_Manager_triggered()
{
    BDApropos * bdPropos = new BDApropos(this);
    bdPropos->exec();

    delete bdPropos;
}

void MainWindow::on_actionEnvoyer_et_ou_recevoir_des_messages_triggered()
{
    m_mdi->lancerLireMsg();
}

void MainWindow::on_actionAide_en_ligne_triggered()
{

}

agent * MainWindow::utilisateur()
{
    return m_comptable;
}

void MainWindow::updateActivitesAgent()
{
    if(m_comptable)
    {
        m_comptable->setConnecte(true);
        m_comptable->setEtatFinConnection(true);

        if(m_comptable->activites())
        {
            m_comptable->setActivites(false);
        }else
        {
            m_comptable->setActivites(true);
        }

        m_comptable->enregistrer();
    }
}

void MainWindow::on_actionConfigurer_les_comptes_triggered()
{
    BDConfigCpt bd(this);
    bd.setWindowTitle("Configurer les comptes");

    bd.exec();

    // actualiser l'affichage des comptes créés
    if(bd.modified())
    {
        m_mdi->chargerMesComptes();
    }
}

void MainWindow::on_actionUne_operation_triggered()
{
    BDExecuterNlleOperation * bd = new BDExecuterNlleOperation(m_db, m_comptable->matricule(), this);
    bd->setWindowTitle("Exécuter une nouvelle opération");

    if(bd->exec() == QDialog::Accepted)
    {
        // actualiser toutes les fenêtres
        activeMdiServiceComptable()->lancerOPCModified();
    }
}

void MainWindow::on_actionSupprimer_une_op_ration_triggered()
{
    MdiServiceComptable * mdi = activeMdiServiceComptable();
    mdi->supprimerOPC();
}

void MainWindow::on_actionLa_comptabilit_des_services_triggered()
{
    BDConfigComptaService bd(this);
    bd.setWindowTitle("Configurer la comptabilité des services");

    bd.exec();
}

void MainWindow::on_actionMes_comptes_en_arbre_triggered()
{
    bool checked = ui->actionMes_comptes_en_arbre->isChecked();
    ui->actionMes_comptes_en_arbre->setChecked(checked);
    ui->actionMes_comptes_uniquement->setChecked(!checked);

    activeMdiServiceComptable()->setAfficherMesComptesEnArbre(checked);
}

void MainWindow::on_actionMes_comptes_uniquement_triggered()
{
    bool checked = ui->actionMes_comptes_uniquement->isChecked();
    ui->actionMes_comptes_uniquement->setChecked(checked);
    ui->actionMes_comptes_en_arbre->setChecked(!checked);

    activeMdiServiceComptable()->setAfficherMesComptesEnArbre(!checked);
}

void MainWindow::on_actionD_terminer_le_compte_r_sultat_triggered()
{
    BDCompteResultat bd(this);
    bd.setWindowTitle("Obtenir un compte de résultats");

    bd.exec();
}

void MainWindow::on_actionEditer_les_cl_tures_triggered()
{
    BDEditerClotures * bd = new BDEditerClotures(m_db, *m_comptable, this);
    bd->setWindowTitle("Editer les clôtures");

    bd->exec();
    if(bd->isModified())
    {
        // actualiser toutes les fenêtres
        activeMdiServiceComptable()->lancerOPCModified();
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
    m_comptable = new agent(activeMdiFormConnexion()->utilisateur());
    fermerFormConnexion();

    setWindowTitle(tr(TITLE).arg("connecté"));
    newMdiServiceComptable();
    setEnabledEtatActions(true);
}
