#include "MdiServiceComptable.h"
#include "ui_MdiServiceComptable.h"

MdiServiceComptable::MdiServiceComptable(BDD *db, agent *r, Horloge *h, QString path, QWidget *parent):
    QWidget(parent),
    ui(new Ui::MdiServiceComptable)
{
    ui->setupUi(this);

    m_db = db;
    m_chemin = path;

    m_parent = parent;
    m_fermer = false;
    m_horloge = h;
    m_comptable = r;
    m_afficherMesComptesEnArbre = false;
    ui->frame_4->setVisible(false);

    initArbreComptes();

    // charger mes comptes
    chargerMesComptes();

    initialiserBDMessage();
    afficherHorloge();
    afficherDateDeConnection();

    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(afficherHorloge()));
    //connect(m_horloge, SIGNAL(fiveSecsOvered()), this, SLOT(actualiserFenetre()));

    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(testerCurrentRowIsValid()));
}

MdiServiceComptable::~MdiServiceComptable()
{
    delete ui;
    //m_bdMessagerie->close();
    //delete m_bdMessagerie;
}

void MdiServiceComptable::changeEvent(QEvent *e)
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

void MdiServiceComptable::closeEvent(QCloseEvent * e)
{
    if(seDeconnecter())
    {
        QWidget::closeEvent(e);
        e->accept();
    }
    else {
        e->ignore();
    }
}

bool MdiServiceComptable::seDeconnecter()
{
    if(!m_fermer)
    {
        QString title = tr("Se déconnecter du compte %1").arg(m_comptable->login());
        if(QMessageBox::question(this, title, "Désirez-vous vous déconnecter?"
                                 , "Oui", "Non") == 0)
        {
            m_comptable->setConnecte(false);
            m_comptable->setEtatFinConnection(false);
            m_comptable->setCodeDeSortie(0);
            m_comptable->enregistrer();
            m_fermer = true;
            emit closed();
        }

        return m_fermer;
    }

    return true;
}

void MdiServiceComptable::lancerLireMsg()
{
    emit lireMsg();
}

void MdiServiceComptable::lancerOPCModified()
{
    emit opcModified();
}

void MdiServiceComptable::actualiserFenetre()
{
    actualiser at(OperationsComptables::Libelle);
    if(at.actual())
    {
        at.setActual(false);
        at.enregistrer();

        // actualiser la fenêtre
        emit opcModified();
    }
}

void MdiServiceComptable::initArbreComptes()
{
    ui->treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
    m_actionRenommer = new QAction("Renommer", 0);
    ui->treeWidget->addAction(m_actionRenommer);

    connect(ui->treeWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionRenommer(QModelIndex)));
    connect(m_actionRenommer, SIGNAL(triggered()), this, SLOT(editerLibelleDeCompte()));
}

void MdiServiceComptable::initialiserBDMessage()
{
//    m_bdMessagerie = new BDMessagerie(m_comptable
//                                      , m_horloge
//                                      , m_chemin
//                                      , ui->btn_lire
//                                      , ui->labelEnveloppe
//                                      , ui->labelNbMsgNonLus
//                                      , m_parent);
//
//    m_bdMessagerie->setWindowModality(Qt::NonModal);
//    m_bdMessagerie->setWindowTitle("Envoyez et/ou recevoir des messages");
//
//
//    connect(this, SIGNAL(lireMsg()), m_bdMessagerie, SLOT(show()));
}

void MdiServiceComptable::afficherHorloge()
{
    QTime now = Horloge::currentTime();
    QStringList heure;
    heure = now.toString(Qt::ISODate).split(":");

    ui->label_horloge->setText(tr("Heure du serveur: %1 h %2 min").arg(heure.first()).arg(heure.at(1)));
}

void MdiServiceComptable::afficherDateDeConnection()
{
    QString message = tr("Vous êtes connecté depuis le %1").arg(Horloge::currentDateTime().toString(Qt::SystemLocaleLongDate));
    ui->label_heureDeConnection->setText(message);
}

void MdiServiceComptable::updateEtatActionRenommer(QModelIndex index)
{
    int numero = QString(ui->treeWidget->currentItem()->text(0).split(" ").first()).toInt();

    planComptable pc(numero);
    m_actionRenommer->setEnabled(pc.utilise());
}

void MdiServiceComptable::on_treeWidget_doubleClicked(QModelIndex index)
{
    int numero = QString(ui->treeWidget->currentItem()->text(0).split(" ").first()).toInt();

    planComptable pc(numero);
    if(pc.utilise())
    {
        // vérifier que la fenêtre existe
        for(int i = 0; i < ui->mdiArea->subWindowList().count(); i++)
        {
            CompteForm * mdicf = qobject_cast<CompteForm *>(ui->mdiArea->subWindowList().at(i)->widget());
            if(mdicf->windowTitle() == pc.libellePersoComplet())
            {
                // fenetre existe
                mdicf->showMaximized();
                return;
            }
        }

        // afficher une forme
        CompteForm * mdi = new CompteForm(m_db, numero, this);
        mdi->setWindowTitle(pc.libellePersoComplet());
        ui->mdiArea->addSubWindow(mdi);

        connect(this, SIGNAL(opcModified()), mdi, SLOT(chargerOperations()));
        connect(mdi, SIGNAL(currentRowIsValid(bool)), this, SLOT(lancerCurrentRowIsValid(bool)));
        connect(mdi, SIGNAL(opened(bool)), this, SLOT(lancerCurrentRowIsValid(bool)));

        mdi->showMaximized();
    }
}

void MdiServiceComptable::chargerMesComptes()
{
    ui->treeWidget->clear();

    if(m_afficherMesComptesEnArbre)
    {
        for(int i = 0; i < 9; i++) // construction des classes (niveau 1)
        {
            int classe = i + 1;
            QTreeWidgetItem * item = new QTreeWidgetItem(QStringList(tr("Classe %1").arg(classe)));
            ui->treeWidget->insertTopLevelItem(i, item);

            // construction des comptes créés au niveau 2
            QList<QSqlRecord> records;
            records << planComptable::pc_records(classe, true, 2);

            foreach(QSqlRecord r, records)
            {
                QTreeWidgetItem * item1 = new QTreeWidgetItem(QStringList(planComptable(r).libellePersoComplet()));
                item->addChild(item1);
            }

            // construction des comptes créés du niveau 3 à 4
            for(int j = 3; j < 5; j++)
            {
                QList<QSqlRecord> records1;
                records1 << planComptable::pc_records(classe, true, j);

                foreach(QSqlRecord r, records1)
                {
                    planComptable p(r);
                    QTreeWidgetItem * parentDirect = ajouterParent(p.numCpt(), item);
                    QTreeWidgetItem * item2 = new QTreeWidgetItem(QStringList(p.libellePersoComplet()));
                    parentDirect->addChild(item2);
                }
            }
        }
    }else
    {
        QList<QSqlRecord> records;
        records << planComptable::pc_records(true);

        for(int i = 0; i < records.count(); i++)
        {
            planComptable p(records.at(i));
            QTreeWidgetItem * item = new QTreeWidgetItem(QStringList(p.libellePersoComplet()));
            ui->treeWidget->insertTopLevelItem(i, item);
        }
    }
}

QTreeWidgetItem * MdiServiceComptable::ajouterParent(int numCptEnfant, QTreeWidgetItem *itemTopLevel)
{
    QList<QSqlRecord> allParents;
    allParents << planComptable::pc_all_parents_records(false, numCptEnfant); // ils sont non créés

    if(allParents.isEmpty())
        return 0; // ne possède pas de compte parent

    QTreeWidgetItem * parentDirect = 0;
    // ordre de allParents : du père aux arrières
    foreach(QSqlRecord parent, allParents)
    {
        planComptable pc(parent);
        QTreeWidgetItem * item = new QTreeWidgetItem(QStringList(pc.libelleComplet()));

        if(!parentDirect)
            parentDirect = item;
        else
        {
            // c'est le grand-père
            itemTopLevel->addChild(item);
            item->addChild(parentDirect);

        }
    }

    if(allParents.count() == 1)
        itemTopLevel->addChild(parentDirect);        

    return parentDirect;
}

CompteForm * MdiServiceComptable::activeCompteForm()
{
    if(ui->mdiArea->activeSubWindow())
        return qobject_cast<CompteForm *>(ui->mdiArea->activeSubWindow()->widget());

    return 0;
}

void MdiServiceComptable::lancerCurrentRowIsValid(bool valid)
{
     emit currentRowIsValid(valid);
}

void MdiServiceComptable::supprimerOPC()
{
    if(activeCompteForm())
    {
        activeCompteForm()->supprimerOperationCourante();
        emit opcModified();
    }
}

void MdiServiceComptable::setAfficherMesComptesEnArbre(bool afficher)
{
    if(afficher != m_afficherMesComptesEnArbre)
    {
        m_afficherMesComptesEnArbre = afficher;
        chargerMesComptes();
    }
}

void MdiServiceComptable::testerCurrentRowIsValid()
{
    if(activeCompteForm())
    {
        lancerCurrentRowIsValid(activeCompteForm()->numeroOperationCourante() != 0);
    }else
    {
        lancerCurrentRowIsValid(false);
    }
}

void MdiServiceComptable::editerLibelleDeCompte()
{
    int numero = QString(ui->treeWidget->currentItem()->text(0).split(" ").first()).toInt();
    planComptable p(numero);

    BDRenommerCompte bd(p, this);
    bd.setWindowTitle(tr("Renommer le compte N° %1").arg(p.numCpt()));

    if(bd.exec() == QDialog::Accepted)
    {
        chargerMesComptes();
    }
}
