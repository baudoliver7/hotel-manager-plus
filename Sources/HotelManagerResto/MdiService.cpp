#include "MdiService.h"
#include "ui_MdiService.h"

MdiService::MdiService(BDD *db, agent *r, Horloge *h, QString path, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MdiService)
{
    ui->setupUi(this);

    m_db = db;
    m_affichage = false;
    m_fermer = false;
    m_chemin = path;
    m_horloge = h;
    m_agent = r;
    m_parent = parent;

    ui->rb_aujourdhui->setVisible(false);
    ui->rb_periode->setVisible(false);
    ui->splitterDebut->setVisible(false);
    ui->splitterFin->setVisible(false);
    ui->btn_occuper->setEnabled(false);
    ui->btn_details->setEnabled(false);
    ui->btn_cloturer->setEnabled(false);
    ui->btn_imprimerRecu->setEnabled(false);
    ui->btn_imprimerFacture->setEnabled(false);
    ui->btn_supprimerMenu->setEnabled(false);

    ui->treeWidgetConsommations->setColumnHidden(4, true);
    connect(ui->treeWidgetConsommations->selectionModel()
            , SIGNAL(selectionChanged(QItemSelection,QItemSelection))
            , this
            , SLOT(updateBtnEtatSuppMenu()));

    initialiserTableau();
    initialiserTableauActivites();
    initialiserCategorie();

    connect(ui->rb_aujourdhui, SIGNAL(toggled(bool)), this, SLOT(rafraichirTable()));
    connect(ui->rb_periode, SIGNAL(toggled(bool)), this, SLOT(updateEtatGroupPeriode(bool)));
    connect(ui->treeWidgetTablesLibres->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(updateEtatBtnOccuper(QModelIndex)));
    connect(ui->tableWidget->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(updateEtatBtnConso(QModelIndex)));
    connect(ui->tableViewActivites->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(updateEtatBtnImprimerRecu(QModelIndex)));
    connect(ui->tableWidget->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(updateEtatBtnImprimerFacture(QModelIndex)));

    ui->rb_aujourdhui->setChecked(true);
    updateEtatGroupPeriode(false);

    QString dateStr = Horloge::currentDate().addDays(-1).toString(Qt::SystemLocaleLongDate);
    ui->lineEditDebut->setText(dateStr);
    ui->lineEditFin->setText(dateStr);

    ui->btn_supprimer->setEnabled(false);
    ui->btn_enregistrer->setEnabled(false);

    actualiserFenetre();

    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(updateDureeOccupation()));
    connect(m_horloge, SIGNAL(dayOvered()), this, SLOT(actualiserFenetre()));

    m_bdWaiting = new BDWaiting(this);
}

MdiService::~MdiService()
{
    delete ui;

    delete m_modelActivites;
    delete m_modelCategorie;
    delete m_modelMenu;
    delete m_bdWaiting;
}

void MdiService::changeEvent(QEvent *e)
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

void MdiService::closeEvent(QCloseEvent *e)
{
    if(!m_fermer && seDeconnecter())
    {
        QWidget::closeEvent(e);
        emit closed();
        e->accept();
    }else
    {
        if(!m_fermer)
        {
            e->ignore();
        }
    }
}

bool MdiService::seDeconnecter()
{
    bool deconnecte = false;
    QString title = tr("Se déconnecter du compte %1").arg(m_agent->login());
    if(QMessageBox::question(this, title, "Désirez-vous vous déconnecter?"
                             , "Oui", "Non") == 0)
    {
        //updateHeureFin();
        m_agent->setConnecte(false);
        m_agent->setEtatFinConnection(false);
        m_agent->setCodeDeSortie(0);
        m_agent->enregistrer();
        deconnecte = true;
        m_fermer = true;
    }

    return deconnecte;
}

void MdiService::initialiserTableau()
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->setColumnHidden(l_ID, true);
    ui->tableWidget->setColumnHidden(l_MATRICULECAISSIER, true);
}

void MdiService::initialiserCategorie()
{
    QFile file("config.txt");

    m_bar = false;
    if(file.open(QIODevice::ReadOnly))
    {
        // afficher par défaut resto-bar
        QDataStream in(&file);
        QStringList d;
        in >> d;

        m_bar = (bool)d.first().split(" ").last().toInt(); // bar = 0 ou 1
    }    

    if(m_bar)
        setWindowTitle("Bienvenue au service Bar!");
    else
        setWindowTitle("Bienvenue au service Restaurant!");

    initialiserMenu();

    m_modelCategorie = new QSqlTableModel;
    m_modelCategorie->setTable(CategorieMenu::Libelle);
    m_modelCategorie->setSort(CategorieMenu::Id::Libelle, Qt::AscendingOrder);

    categorieMenu cm;
    QString condition;

    if(m_bar)
        condition = tr("%1 = %2 AND %3 = %4").arg(cm.supprimeeName()).arg(false).arg(cm.idTypeCatMenuName()).arg(2);
    else
        condition = tr("%1 = %2").arg(cm.supprimeeName()).arg(false);

    m_modelCategorie->setFilter(condition);

    ui->comboBoxCategorie->setModel(m_modelCategorie);
    ui->comboBoxCategorie->setModelColumn(CategorieMenu::Id::Libelle);

    connect(ui->comboBoxCategorie, SIGNAL(currentIndexChanged(int)), this, SLOT(chargerMenus()));

    chargerCategorie();
}

void MdiService::initialiserMenu()
{
    m_modelMenu = new QSqlTableModel;
    m_modelMenu->setTable(MenuResto::Libelle);
    m_modelMenu->setSort(MenuResto::Id::LibelleMenu, Qt::AscendingOrder);

    menuResto mr;
    QString condition = tr("%1 = %2").arg(mr.supprimeName()).arg(false);
    m_modelMenu->setFilter(condition);

    ui->comboBoxMenu->setModel(m_modelMenu);
    ui->comboBoxMenu->setModelColumn(MenuResto::Id::LibelleMenu);

    connect(ui->comboBoxMenu, SIGNAL(currentIndexChanged(int)), this, SLOT(afficherPrix()));
}

void MdiService::initialiserTableauActivites()
{
    m_modelActivites = new QSqlRelationalTableModel();
    m_modelActivites->setTable(OperationService::Libelle);

    operationService os;
    QString condition = QObject::tr("%1 = '%2' AND %3 = %4")
                        .arg(os.matriculeAgentName())
                        .arg(m_agent->matricule())
                        .arg(os.clotureeName())
                        .arg(false);

    m_modelActivites->setFilter(condition);

    ui->tableViewActivites->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewActivites->setModel(m_modelActivites);

    ui->tableViewActivites->setColumnHidden(OperationService::Id::IdOperationService, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::Cloturee, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::MatriculeAgent, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::IdTypeOperation, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::IdTypeRecu, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::IdClotureService, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::Depouille, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::EstUneEntree, true);
    ui->tableViewActivites->sortByColumn(OperationService::Id::Date, Qt::AscendingOrder);

    m_modelActivites->setHeaderData(OperationService::Id::Recu, Qt::Horizontal, "Reçu");
    m_modelActivites->setHeaderData(OperationService::Id::Date, Qt::Horizontal, "Date");
    m_modelActivites->setHeaderData(OperationService::Id::Libelle, Qt::Horizontal, "Libellé");
    m_modelActivites->setHeaderData(OperationService::Id::MontantEncaisse, Qt::Horizontal, "Montant encaissé");

    // faire une relation
    modeDePayement mp;
    m_modelActivites->setRelation(OperationService::Id::IdModeDePayement
                                  , QSqlRelation(mp.tableName(), mp.idModeDePayementName(), mp.modeName()));

    m_modelActivites->setHeaderData(OperationService::Id::IdModeDePayement, Qt::Horizontal, "Mode de payement");
}

void MdiService::afficherElement(int row, int column, const QString &value)
{
    QTableWidgetItem * item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(row, column, item);
}

void MdiService::rafraichirTable()
{
    ui->tableWidget->setRowCount(0);

    QDate debut;
    QDate fin;

    QList<QSqlRecord> records;
    if(ui->rb_aujourdhui->isChecked())
    {
        debut = Horloge::currentDate();
        fin = debut;
    }else
    {
        debut = QDate::fromString(ui->lineEditDebut->text(), Qt::SystemLocaleLongDate);
        fin = QDate::fromString(ui->lineEditFin->text(), Qt::SystemLocaleLongDate);
    }

    records << repasCompletResto::repasCompletResto_records_termines(debut, fin, m_agent->matricule(), false);

    double montantEncaisse = 0;
    double montantRestant = 0;
    for(int i = 0; i < records.count(); i++)
    {
        repasCompletResto cr(records.at(i));

        montantRestant += cr.reste();
        montantEncaisse += cr.montantTotalEncaisse();

        client cl(cr.codeClient());

        ui->tableWidget->setRowCount(i+1);

        afficherElement(i, l_ID, QString::number(cr.idRepasCResto()));
        afficherElement(i, l_FACTURE, cr.facture());
        afficherElement(i, l_DATEARRIVEE, cr.dateArrivee().time().toString(Qt::SystemLocaleLongDate));
        afficherElement(i, l_DATEDEPART, cr.dateDepart().time().toString(Qt::SystemLocaleLongDate));
        afficherElement(i, l_DUREE, MesTables::convertirJourHeureMinute(cr.dureeEnMinutes()));
        afficherElement(i, l_TOTALAPAYER, QString::number(cr.totalAPayer()));
        afficherElement(i, l_MONTANTENCAISSE, QString::number(cr.montantTotalEncaisse()));
        afficherElement(i, l_MONTANTRESTANT, QString::number(cr.reste()));
        afficherElement(i, l_MATRICULECAISSIER, cr.matriculeCaissier());

        if(cl.existe())
            afficherElement(i, l_CLIENT, tr("%1 %2").arg(cl.nom()).arg(cl.prenoms()));
        else
            afficherElement(i, l_CLIENT, "Non identifié");
    }

    ui->lineEditMontantEncaisse->setText(MesTables::doubleToAllMoney(montantEncaisse));
    ui->lineEditMontantRestant->setText(MesTables::doubleToAllMoney(montantRestant));
}

void MdiService::updateEtatGroupPeriode(bool enabled)
{
    ui->btn_fin->setEnabled(enabled);
    ui->btn_debut->setEnabled(enabled);
    ui->lineEditDebut->setEnabled(enabled);
    ui->lineEditFin->setEnabled(enabled);
}

void MdiService::on_btn_debut_clicked()
{
    DialogCalendar bd(this);
    bd.setWindowTitle("Date de début");

    if(bd.exec() == QDialog::Accepted)
    {
        if(bd.dateSeclectionnee() <= QDate::fromString(ui->lineEditFin->text(), Qt::SystemLocaleLongDate))
        {
            ui->lineEditDebut->setText(bd.dateSeclectionnee().toString(Qt::SystemLocaleLongDate));
        }else
        {
            ui->lineEditDebut->setText(ui->lineEditFin->text());
        }

        rafraichirTable();
    }
}

void MdiService::on_btn_fin_clicked()
{
    DialogCalendar bd(this);
    bd.setWindowTitle("Date de fin");

    if(bd.exec() == QDialog::Accepted)
    {
        if(bd.dateSeclectionnee() >= QDate::fromString(ui->lineEditDebut->text(), Qt::SystemLocaleLongDate))
        {
            ui->lineEditFin->setText(bd.dateSeclectionnee().toString(Qt::SystemLocaleLongDate));
        }else
        {
            ui->lineEditFin->setText(ui->lineEditDebut->text());
        }

        rafraichirTable();
    }
}

void MdiService::on_comboBoxMenu_currentIndexChanged(QString text)
{
    if(text.isEmpty())
    {
        ui->btn_ajouter->setEnabled(false);
        return;
    }else
    {
        ui->btn_ajouter->setEnabled(true);
    }

    if(!m_affichage)
    {
        // afficher prix
        int pu = menuResto(currentIdMenu()).prix();
        ui->spinBoxPrixUnitaire->setMaximum(pu);
        ui->spinBoxPrixUnitaire->setValue(pu);

        if(ui->checkBoxModifierPrix->isChecked())
        {
            ui->spinBoxPrixUnitaire->setMinimum(0);
        }else
        {
            ui->spinBoxPrixUnitaire->setMinimum(pu);
        }

        ui->spinBoxQuantite->setValue(1);
    }
}

void MdiService::chargerMenus()
{
    m_affichage = true;

    int row = ui->comboBoxCategorie->currentIndex();
    int idCatMenu = m_modelCategorie->record(row).value(CategorieMenu::Id::IdCategorieMenu).toInt();

    menuResto mr1;
    QString condition = tr("%1 = %2 AND %3 = %4")
                        .arg(mr1.idCatMenuName())
                        .arg(idCatMenu)
                        .arg(mr1.supprimeName())
                        .arg(false);

    m_modelMenu->setFilter(condition);
    m_modelMenu->select();

    m_affichage = false;
}

void MdiService::chargerCategorie()
{
    categorieMenu cm;
    QString condition;

    if(m_bar)
        condition = tr("%1 = %2 AND %3 = %4").arg(cm.supprimeeName()).arg(false).arg(cm.idTypeCatMenuName()).arg(2);
    else
        condition = tr("%1 = %2").arg(cm.supprimeeName()).arg(false);

    m_modelCategorie->setFilter(condition);
    m_modelCategorie->select();
}

void MdiService::actualiserFenetre()
{
    m_affichage = true;
    chargerMenus();
    afficherPrix();
    rafraichirTable();
    chargerTables();
    chargerActivites();

    QString table;
    if(ui->treeWidgetTablesOccupees->topLevelItemCount() != 0)
        table = ui->treeWidgetTablesOccupees->topLevelItem(0)->text(0);

    afficherTableauDeBord(table);
    m_affichage = false;
}

void MdiService::on_spinBoxPrixUnitaire_valueChanged(int pu)
{
    if(!m_affichage)
    {
        ui->lineEditPrixTotal->setText(QString::number(pu * ui->spinBoxQuantite->value()));
    }
}

void MdiService::on_spinBoxQuantite_valueChanged(int nb)
{
    if(!m_affichage)
    {
        ui->lineEditPrixTotal->setText(QString::number(ui->spinBoxPrixUnitaire->value() * nb));
    }
}

void MdiService::afficherPrix()
{
    m_affichage = true;
    // afficher prix
    int pu = 0;
    if(ui->comboBoxMenu->currentIndex() >= 0)
    {
        pu = menuResto(currentIdMenu()).prix();
    }

    ui->spinBoxPrixUnitaire->setMaximum(pu);
    ui->spinBoxPrixUnitaire->setValue(pu);

    if(ui->checkBoxModifierPrix->isChecked())
    {
        ui->spinBoxPrixUnitaire->setMinimum(0);
    }else
    {
        ui->spinBoxPrixUnitaire->setMinimum(pu);
    }

    ui->lineEditPrixTotal->setText(QString::number(pu * ui->spinBoxQuantite->value()));
    m_affichage = false;
}

void MdiService::on_checkBoxModifierPrix_toggled(bool checked)
{
    if(checked)
    {
        ui->spinBoxPrixUnitaire->setMinimum(0);
    }else
    {
        if(ui->comboBoxMenu->currentText().isEmpty())
            ui->spinBoxPrixUnitaire->setMinimum(0);
        else
            ui->spinBoxPrixUnitaire->setMinimum(ui->spinBoxPrixUnitaire->maximum());
    }
}

void MdiService::afficherConsosChoisies()
{
    ui->listWidget->clear();

    int somme = 0;
    foreach(consoResto mr, m_consos_resto_choisies)
    {
        somme += mr.coutTotal();
        QString name = tr("%1 %2").arg(mr.nbMenu()).arg(menuResto(mr.idMenu()).libelle());
        ui->listWidget->addItem(new QListWidgetItem(name));
    }

    ui->labelCumul->setText(tr("Montant cumulé = %1").arg(somme));
    ui->btn_enregistrer->setEnabled(!m_consos_resto_choisies.isEmpty());
}

void MdiService::on_btn_supprimer_clicked()
{
    int row = ui->listWidget->currentRow();
    m_consos_resto_choisies.removeAt(row);
    ui->listWidget->takeItem(row);

    int somme = 0;
    foreach(consoResto mr, m_consos_resto_choisies)
    {
        somme += mr.coutTotal();
    }

    ui->labelCumul->setText(tr("Montant cumulé = %1").arg(somme));
    ui->btn_enregistrer->setEnabled(!m_consos_resto_choisies.isEmpty());
}

void MdiService::initialiser()
{
    m_consos_resto_choisies.clear();

    if(ui->comboBoxCategorie->count() > 0)
    {
        ui->comboBoxCategorie->setCurrentIndex(0);
    }

    ui->spinBoxQuantite->setValue(1);
    ui->listWidget->clear();
    ui->labelCumul->setText(tr("Montant cumulé = %1").arg(0));
    ui->checkBoxModifierPrix->setChecked(false);

    ui->btn_enregistrer->setEnabled(false);
}

void MdiService::on_btn_initialiser_clicked()
{
    initialiser();
}

void MdiService::on_listWidget_itemPressed(QListWidgetItem* item)
{
    ui->btn_supprimer->setEnabled(true);
}

void MdiService::on_listWidget_currentRowChanged(int currentRow)
{
    ui->btn_supprimer->setEnabled(currentRow >= 0);
}

void MdiService::on_btn_ajouter_clicked()
{
    consoResto cr;
    cr.setIdMenu(currentIdMenu());
    cr.setCoutTotal(ui->lineEditPrixTotal->text().toInt());
    cr.setNbMenu(ui->spinBoxQuantite->value());
    cr.setIdRepasCResto(0); // à revoir

    m_consos_resto_choisies << cr;

    afficherConsosChoisies();
}

void MdiService::chargerTables()
{
    ui->treeWidgetTablesLibres->clear();
    ui->treeWidgetTablesOccupees->clear();

    tableResto tre;
    QString condition = tr("%1 = %2 AND %3 = %4")
                        .arg(tre.supprimeName())
                        .arg(false)
                        .arg(tre.estBarName())
                        .arg(m_bar); // tables non supprimées

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(TableResto::Libelle, condition);

    foreach(QSqlRecord r, records)
    {
        tableResto t(r);

        if(t.occupee())
        {
            ui->treeWidgetTablesOccupees->addTopLevelItem(new QTreeWidgetItem(QStringList(t.libelle())));
        }else
        {
            ui->treeWidgetTablesLibres->addTopLevelItem(new QTreeWidgetItem(QStringList(t.libelle())));
        }
    }
}

void MdiService::chargerActivites()
{
    m_modelActivites->select();
    ui->tableViewActivites->resizeColumnToContents(OperationService::Id::Libelle);

    double somme = 0;
    double sommeRetiree = 0;
    for(int i = 0; i < m_modelActivites->rowCount(); i++)
    {
        QSqlRecord record = m_modelActivites->record(i);
        operationService os(record);

        if(os.estUneEntree())
            somme += os.montantEncaisse();
        else
            sommeRetiree += os.montantEncaisse();
    }

    ui->lineEditMontantTotalEncaisse->setText(MesTables::doubleToAllMoney(somme));
    ui->lineEditMontantTotalRetire->setText(MesTables::doubleToAllMoney(sommeRetiree));

    updateEtatBtnCloturer();
}

void MdiService::on_btn_occuper_clicked()
{
    tableResto t = strToTable(ui->treeWidgetTablesLibres->currentItem()->text(0));
    t.setOccupee(true);

    t.enregistrer();
    chargerTables();

    // préparer le tableau de bord du client
    QDateTime now = Horloge::currentDateTime();

    repasCompletResto rcr;
    rcr.setCodeClient(0); // client inconnu
    rcr.setDateArrivee(now);
    rcr.setDateDepart(QDateTime());
    rcr.setDureeEnMinutes(0);
    rcr.setFacture(QString()); // pas de facture
    rcr.setIdTableResto(t.idTableResto());
    rcr.setMatriculeCaissier(m_agent->matricule());
    rcr.setTotalAPayer(0); // aucune commande faite
    rcr.setMontantTotalEncaisse(0);// pas encore
    rcr.setFactureMiseAJour(false);

    rcr.enregistrer();

    afficherTableauDeBord(t.libelle());
}

void MdiService::on_btn_terminer_clicked()
{
    QDateTime now = Horloge::currentDateTime();

    tableResto t(strToTable(ui->groupBoxTable->title()));

    QString message;
    if(ui->spinBoxEncaissement->value() == 0)
    {
        message = tr("Désirez-vous mettre fin à l'occupation de la %1 ? \n\nMontant total = %2\nMontant versé = %3")
                                  .arg(t.libelle()).arg(MesTables::moneyToString(ui->labelTotalAPayer->text().toInt())).arg(MesTables::moneyToString(ui->spinBoxEncaissement->value()));
    }else
    {
        message =  tr("Désirez-vous mettre fin à l'occupation de la %1 ? \n\nMontant total = %2\nMontant versé = %3\nMode de payement : %4")
                                  .arg(t.libelle()).arg(MesTables::moneyToString(ui->labelTotalAPayer->text().toInt())).arg(MesTables::moneyToString(ui->spinBoxEncaissement->value())).arg(ui->comboBoxModeDePaye->currentText());
    }

    if(QMessageBox::question(this
                          , "Terminer une occupation"
                          , message
                          , "Oui", "Non") == 0)
    {
        m_db->transaction();
        bool submitAll = true;

        repasCompletResto rcr = repasCompletResto::selectionnerRepasCResto(t.idTableResto());

        if(rcr.totalAPayer() == 0)
        {
            // supprimer
            rcr.supprimer();
        }else
        {
            int montantEncaisse = ui->spinBoxEncaissement->value();

            // enregistrer un repas complet
            rcr.setDateDepart(now);
            rcr.setMontantTotalEncaisse(rcr.montantTotalEncaisse() + montantEncaisse);
            submitAll = submitAll && rcr.enregistrer();

            if(montantEncaisse != 0)
            {                
                QString libelle;                

                if(m_bar)
                {
                    libelle = QString("Réglement de la facture de bar %1").arg(rcr.facture());

                    // faire un réçu
                    submitAll = submitAll && MesTables::enregistrerUneOperationService(*m_agent
                                                                                      , recuInitial::IdBar
                                                                                      , now
                                                                                      , montantEncaisse
                                                                                      , libelle
                                                                                      , ui->comboBoxModeDePaye->currentIndex() + 1                                                                                      
                                                                                      , rcr.idRepasCResto()
                                                                                      , rcr.tableName());
                }
                else
                {
                    libelle = QString("Réglement de la facture de restauration %1").arg(rcr.facture());

                    // faire un réçu
                    submitAll = submitAll && MesTables::enregistrerUneOperationService(*m_agent
                                                                                      , recuInitial::IdRestauration
                                                                                      , now
                                                                                      , montantEncaisse
                                                                                      , libelle
                                                                                      , ui->comboBoxModeDePaye->currentIndex() + 1
                                                                                      , rcr.idRepasCResto()
                                                                                      , rcr.tableName());
                }

                int index = ui->comboBoxCompteClient->currentIndex();
                if(ui->comboBoxModeDePaye->currentIndex() + 1 == modeDePayement::CompteClient)
                {
                    // débiter le compte client
                    MesTables::faireUnMouvementCompteClient(  *m_agent
                                                            , now
                                                            , m_comptesClients.at(index).idCompteClient()
                                                            , libelle
                                                            , montantEncaisse
                                                            , true
                                                            , submitAll);
                }
            }
        }

        t.setOccupee(false);
        submitAll = submitAll && t.enregistrer();

        if(submitAll)
        {
            m_db->commit();
            m_clientEnCours.clear();
            actualiserFenetre();
        }else
            m_db->rollback();
    }
}

void MdiService::updateEtatBtnOccuper(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_occuper->setEnabled(true);
    }else
    {
        ui->btn_occuper->setEnabled(false);
    }
}

void MdiService::afficherTableauDeBord(QString table)
{
    ui->treeWidgetConsommations->clear();
    ui->comboBoxCompteClient->clear();
    ui->comboBoxModeDePaye->clear();

    tableResto t = strToTable(table);

    if(t.existe() && t.occupee())
    {
        ui->groupBoxTable->setTitle(t.libelle());

        repasCompletResto rcr1 = repasCompletResto::selectionnerRepasCResto(t.idTableResto());
        client cl(rcr1.codeClient());
        m_clientEnCours = cl;

        ui->labelDateArrivee->setText(rcr1.dateArrivee().toString(Qt::SystemLocaleLongDate));
        ui->labelTotalAPayer->setText(QString::number(rcr1.totalAPayer()));

        ui->labelResteAPayer->setText(QString::number(rcr1.reste()));
        ui->labelMontantEncaisse->setText(QString::number(rcr1.montantTotalEncaisse()));

        if(cl.existe())
        {
            ui->labelClient->setText(cl.nomComplet());

            // charger compte du client
            QList<QSqlRecord> records = compteClient::compteClient_records(cl.codeDuClient());

            QStringList comptes;
            foreach(QSqlRecord r, records)
            {
                compteClient cc(r);
                comptes << cc.libelle();
                m_comptesClients << cc;
            }

            ui->comboBoxCompteClient->addItems(comptes);

            if(comptes.isEmpty())
            {
                ui->comboBoxModeDePaye->addItems(modeDePayement::chargerModeDePayementSansCompteClient());
            }else
            {
                ui->comboBoxModeDePaye->addItems(modeDePayement::chargerModeDePayement());
            }

            ui->btn_imprimer_tab_bord->setDisabled(rcr1.facture().isEmpty());

            ui->spinBoxEncaissement->setMaximum(rcr1.reste());
            ui->spinBoxEncaissement->setValue(0);
            ui->spinBoxEncaissement->setMinimum(0);
        }
        else
        {
            ui->labelClient->setText("Non identifié");

            // client inconnu donc pas de crédit
            ui->spinBoxEncaissement->setMaximum(rcr1.reste());
            ui->spinBoxEncaissement->setValue(rcr1.reste());
            ui->spinBoxEncaissement->setMinimum(rcr1.reste());
            ui->comboBoxModeDePaye->addItems(modeDePayement::chargerModeDePayementSansCompteClient());

            ui->comboBoxCompteClient->clear();
        }

        // afficher les consommations
        afficherConsommations(rcr1.idRepasCResto());

        // afficher la durée à jour
        updateDureeOccupation();

        // update état groupe box enreg et table
        ui->groupBoxEnreg->setEnabled(true);
        ui->groupBoxEnreg->setTitle(tr("Exécuter une commande pour la %1").arg(t.libelle()));
        ui->groupBoxTable->setEnabled(true);
    }else
    {
        ui->groupBoxTable->setEnabled(false);
        ui->groupBoxTable->setTitle("Aucune table");
        ui->groupBoxEnreg->setEnabled(false);
        ui->groupBoxEnreg->setTitle(QString("Exécuter une commande"));
        ui->labelClient->setText("Non identifié");
        ui->labelDateArrivee->setText(QDateTime().toString(Qt::ISODate));
        ui->labelDureeOccupation->setText("0 minute");
        ui->labelMontantEncaisse->setText("0");
        ui->labelResteAPayer->setText("0");
        ui->labelTotalAPayer->setText("0");
        ui->spinBoxEncaissement->setValue(0);
        ui->comboBoxModeDePaye->clear();
        m_comptesClients.clear();
    }
}

void MdiService::afficherConsommations(int idRepasCResto)
{
    ui->treeWidgetConsommations->clear();

    QList<QSqlRecord> records;
    records << consoResto::consoResto_records(idRepasCResto);

    foreach(QSqlRecord r, records)
    {
        consoResto cr(r);
        menuResto mr(cr.idMenu());

        QStringList l;
        l << mr.libelle()
          << QString::number(cr.coutTotal() / cr.nbMenu())
          << QString::number(cr.nbMenu())
          << QString::number(cr.coutTotal())
          << QString::number(cr.idConsoResto());

        ui->treeWidgetConsommations->addTopLevelItem(new QTreeWidgetItem(l));
    }

    ui->btn_imprimer_tab_bord->setEnabled(!records.isEmpty());
}

void MdiService::updateDureeOccupation()
{
    int count = ui->treeWidgetTablesOccupees->topLevelItemCount();
    for(int i = 0; i < count; i++)
    {
        tableResto t = strToTable(ui->treeWidgetTablesOccupees->topLevelItem(i)->text(0));
        repasCompletResto rcr = repasCompletResto::selectionnerRepasCResto(t.idTableResto());

        int duree = rcr.dateArrivee().secsTo(Horloge::currentDateTime()) / 60;

        rcr.setDureeEnMinutes(duree);
        rcr.enregistrer();

        if(t.libelle() == ui->groupBoxTable->title())
        {
            ui->labelDureeOccupation->setText(MesTables::convertirJourHeureMinute(rcr.dureeEnMinutes()));
        }
    }
}

void MdiService::on_btn_enregistrer_clicked()
{
    tableResto t = strToTable(ui->groupBoxTable->title());
    repasCompletResto rcr = repasCompletResto::selectionnerRepasCResto(t.idTableResto());

    int somme = 0;
    menuResto mr;
    foreach(consoResto c, m_consos_resto_choisies)
    {
        // recherche dans la bd
        QString condition = tr("%1 = %2 AND %3 = %4 AND %5 IN (SELECT %6 FROM %7 WHERE %8 = %9)")
                            .arg(c.idMenuName()).arg(c.idMenu())
                            .arg(c.idRepasCRestoName()).arg(rcr.idRepasCResto())
                            .arg(c.idMenuName()).arg(mr.idMenuRestoName()).arg(mr.tableName())
                            .arg(mr.prixName()).arg(c.coutTotal()/c.nbMenu()); // si même menu au même prix

        QList<QSqlRecord> records;
        records = InfosSurBD::enregistrements(c.tableName(), condition);

        if(records.isEmpty())
        {
            // nouveau menu ou même menu pas au même prix
            c.setIdRepasCResto(rcr.idRepasCResto());
            c.enregistrer();
        }else
        {
            // même menu au même prix. on ajoute la quantité et le montant
            consoResto cr(records.first());
            cr.setNbMenu(cr.nbMenu() + c.nbMenu());
            cr.setCoutTotal(cr.coutTotal() + c.coutTotal());
            cr.enregistrer();
        }

        somme += c.coutTotal();
    }

    rcr.setTotalAPayer(rcr.totalAPayer() + somme);

    // déterminer le numéro de la facture si ce n'est pas déjà fait
    if(rcr.facture().isEmpty())
    {
        factureInitial fi;

        if(m_bar)
            fi = factureInitial(factureInitial::IdBar);
        else
            fi = factureInitial(factureInitial::IdRestaurant);

        int numero = fi.numero() + 1;

        rcr.setFacture(fi.initial() + QString::number(numero));
        fi.setNumero(numero);
        fi.enregistrer();
    }

    rcr.enregistrer();

    // afficher l'onglet tableau de bord
    ui->tabWidget->setCurrentIndex(ONGLET_TABLEAUDEBORD);
    afficherTableauDeBord(t.libelle());

    initialiser();
}

void MdiService::on_treeWidgetTablesOccupees_doubleClicked(QModelIndex index)
{
    if(index.isValid())
    {
        afficherTableauDeBord(ui->treeWidgetTablesOccupees->topLevelItem(index.row())->text(0));
    }
}

void MdiService::updateEtatBtnConso(QModelIndex index)
{
    ui->btn_details->setEnabled(index.isValid());
}

void MdiService::on_btn_details_clicked()
{
    repasCompletResto rcr(currentIdRepasCResto());

    BDDetailsRepas bd(rcr.idRepasCResto(), this);
    bd.setWindowTitle(tr("Facture %1").arg(rcr.facture()));
    bd.exec();
}

int MdiService::currentIdRepasCResto()
{
    int row = ui->tableWidget->currentRow();

    return ui->tableWidget->item(row, l_ID)->text().toInt();
}

void MdiService::on_btn_identifierClient_clicked()
{
    BDIdentifierClientResto * bd = new BDIdentifierClientResto(false, this);
    bd->setWindowTitle("Identifier le client");

    if(bd->exec() == QDialog::Accepted)
    {
        m_clientEnCours = bd->clientSelectionne();
        ui->labelClient->setText(m_clientEnCours.nomComplet());

        tableResto t = strToTable(ui->groupBoxTable->title());
        repasCompletResto rcr1 = repasCompletResto::selectionnerRepasCResto(t.idTableResto());
        rcr1.setCodeClient(m_clientEnCours.codeDuClient());

        if(bd->clientEnTantQueLocataire())
        {
            rcr1.setNumOccupation(bd->numOccupClientLocataire());
        }

        rcr1.enregistrer();

        afficherTableauDeBord(t.libelle());
    }

    delete bd;
}

void MdiService::on_btn_cloturer_clicked()
{
    if(QMessageBox::information(this
                             , "Clôturer le service en cours"
                             , "Vous êtes sur le point de clôturer le service en cours. \n\n Désirez-vous continuer ?"
                             , "Oui"
                             , "Non") == 0)
    {
        m_bdWaiting->show();
        QTimer::singleShot(5, this, SLOT(cloturer()));
    }
}

void MdiService::updateEtatBtnCloturer()
{
    ui->btn_cloturer->setEnabled(m_modelActivites->rowCount() != 0);
}

void MdiService::chargerModeDePayement()
{
    ui->comboBoxModeDePaye->clear();

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ModeDePayement::Libelle);

    QStringList modes;
    foreach(QSqlRecord r, records)
    {
        modeDePayement mr(r);
        modes << mr.mode();
    }

    ui->comboBoxModeDePaye->addItems(modes);
}

void MdiService::updateEtatBtnImprimerRecu(QModelIndex index)
{
    ui->btn_imprimerRecu->setEnabled(index.isValid());
}

void MdiService::updateEtatBtnImprimerFacture(QModelIndex index)
{
    ui->btn_imprimerFacture->setEnabled(index.isValid());
}

void MdiService::on_btn_imprimer_tab_bord_clicked()
{
    tableResto t = strToTable(ui->groupBoxTable->title());
    repasCompletResto rcr = repasCompletResto::selectionnerRepasCResto(t.idTableResto());

    factureRestoIndividu * facture = new factureRestoIndividu(rcr);

    // impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A5);
    QPrintDialog printDialog(&printer, this);

    // éventuelle pensée
    if(printDialog.exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);

        // print, fitting the viewport contents into a full page
        facture->view()->render(&painter);
    }

    delete facture;
}

void MdiService::on_comboBoxModeDePaye_currentIndexChanged(int index)
{
    if(index + 1 == modeDePayement::CompteClient)
    {
        // compte client
        if(ui->comboBoxCompteClient->count() > 0)
        {
            ui->comboBoxCompteClient->setEnabled(true);
            ui->lineEditSolde->setEnabled(true);
        }else
        {
            ui->comboBoxCompteClient->setEnabled(false);
            ui->lineEditSolde->setEnabled(false);
        }
    }else
    {
        int sommeRestante = ui->labelResteAPayer->text().toInt();
        ui->spinBoxEncaissement->setMaximum(sommeRestante);

        ui->comboBoxCompteClient->setEnabled(false);
        ui->lineEditSolde->setEnabled(false);
    }
}

void MdiService::on_comboBoxCompteClient_currentIndexChanged(int index)
{
    int sommeRestante = ui->labelResteAPayer->text().toInt();

    if(index < 0)
    {
        ui->spinBoxEncaissement->setMaximum(sommeRestante);
        ui->lineEditSolde->setText(QString::number(0));
    }else
    {
        int solde = m_comptesClients.at(index).solde();
        ui->lineEditSolde->setText(QString::number(solde));

        if(sommeRestante > solde)
        {
            ui->spinBoxEncaissement->setMaximum(solde);
        }else
        {
            ui->spinBoxEncaissement->setMaximum(sommeRestante);
        }
    }
}

void MdiService::on_btn_imprimerFacture_clicked()
{
    int idRC = currentIdRepasCResto();
    repasCompletResto rcr(idRC);
    factureRestoIndividu * facture = new factureRestoIndividu(rcr);

    // impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A5);
    QPrintDialog printDialog(&printer, this);

    // éventuelle pensée
    if(printDialog.exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);

        // print, fitting the viewport contents into a full page
        facture->view()->render(&painter);
    }

    delete facture;
}

void MdiService::on_btn_imprimerRecu_clicked()
{
    int row = ui->tableViewActivites->currentIndex().row();
    QSqlRecord record = m_modelActivites->record(row);

    operationService os(record);
    os.actualiser();
    recu * facture = new recu(os);

    // impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    QPrintDialog printDialog(&printer, this);

    // éventuelle pensée
    if(printDialog.exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);

        // print, fitting the viewport contents into a full page
        facture->view()->render(&painter);
    }

    delete facture;
}

void MdiService::on_btn_supprimerMenu_clicked()
{
    int row = ui->treeWidgetConsommations->currentIndex().row();
    int idConsoRepas = ui->treeWidgetConsommations->topLevelItem(row)->text(4).toInt();

    // supprimer conso
    consoResto cr(idConsoRepas);

    if(QMessageBox::information(this
                             , "Supprimer un menu"
                             , tr("Désirez-vous supprimer le menu commandé <%1>?").arg(menuResto(cr.idMenu()).libelle())
                             , "Oui", "Non") == 0)
    {
        // retirer le montant du repas global
        repasCompletResto rcr(cr.idRepasCResto());
        rcr.setTotalAPayer(rcr.totalAPayer() - cr.coutTotal());
        rcr.enregistrer();

        // supprimer la consommation
        cr.supprimer();

        // actualiser onglet
        afficherTableauDeBord(ui->groupBoxTable->title());
    }


}

void MdiService::updateBtnEtatSuppMenu()
{
    ui->btn_supprimerMenu->setEnabled(!ui->treeWidgetConsommations->selectedItems().isEmpty());
}

int MdiService::currentIdMenu()
{
    int row = ui->comboBoxMenu->currentIndex();

    if(row >= 0)
        return m_modelMenu->record(row).value(MenuResto::Id::IdMenuResto).toInt();
    else
        return 0;
}

int MdiService::currentIdCategorie()
{
    int row = ui->comboBoxCategorie->currentIndex();

    if(row >= 0)
        return m_modelCategorie->record(row).value(CategorieMenu::Id::IdCategorieMenu).toInt();
    else
        return 0;
}

tableResto MdiService::strToTable(const QString &table)
{
    tableResto t1;
    QString nomTable = table;
    nomTable.replace("'", "''");
    QString condition = tr("%1 = '%2' AND %3 = %4")
                        .arg(t1.libelleName())
                        .arg(nomTable)
                        .arg(t1.estBarName())
                        .arg(m_bar);

    if(InfosSurBD::enregistrements(TableResto::Libelle, condition).isEmpty())
         return tableResto();

    QSqlRecord record;
    record = InfosSurBD::enregistrements(TableResto::Libelle, condition).first();
    return tableResto(record);
}

void MdiService::setConfigModule(bool bar)
{
    m_bar = bar;

    if(m_bar)
        setWindowTitle("Bienvenue au service Bar!");
    else
        setWindowTitle("Bienvenue au service Restaurant!");

    chargerCategorie();
    actualiserFenetre();
}

void MdiService::cloturer()
{
    m_db->transaction();
    bool submitAll = true;

    // enregistrer une cloture
    QDate now = Horloge::currentDate();

    clotureService cs(m_agent->matricule(), now); // sélectionner la cloture de l'agent
    cs.setDate(now);
    cs.setMatriculeAgent(m_agent->matricule());
    submitAll = submitAll && cs.enregistrer();

    int montantEncaisse = 0;
    int montantRestant = 0;
    int montantEspece = 0;
    int montantCheque = 0;
    int montantCarteDeCredit = 0;
    int montantCompteClient = 0;
    int depotCompteClient = 0;
    int montantRetire = 0;

    QList<QSqlRecord> records;
    records << operationService::os_records(m_agent->matricule(), false);

    QList<int> idRepasCRestos;
    for(int i = 0; i < records.count(); i++)
    {
        operationService os(records.at(i));

        if(os.estUneEntree())
            montantEncaisse += os.montantEncaisse();
        else
            montantRetire += os.montantEncaisse();

        switch(os.idModeDePayement())
        {
            case modeDePayement::Cash: // espèce
                montantEspece += os.montantEncaisse();
                break;
            case modeDePayement::Cheque: // chèque
                montantCheque += os.montantEncaisse();
                break;
        case modeDePayement::CompteClient: // compte client
                montantCompteClient += os.montantEncaisse();
                break;
            default:
                // carte de crédit
                montantCarteDeCredit += os.montantEncaisse();
        }

        if((os.idTypeRecu() == recuInitial::IdRestauration) && !idRepasCRestos.contains(os.idTypeOperation()))
        {
            // si l'opération n'a jamais été clôturée
            if(!operationService::osExisteEtEstCloturee(os.idTypeRecu(), os.idTypeOperation(), false))
            {
                // comptabiliser montant restant uniquement
                repasCompletResto rcr(os.idTypeOperation());
                montantRestant += rcr.reste();
            }
        }

        if(os.idTypeRecu() == recuInitial::IdDepotSurCompteClient)
        {
            depotCompteClient += os.montantEncaisse();
        }

        idRepasCRestos << os.idTypeOperation();

        os.setCloturee(true);
        os.setIdClotureService(cs.idClotureService());
        submitAll = submitAll && os.enregistrer();
    }

    cs.setMontantEncaisse(montantEncaisse + cs.montantEncaisse());
    cs.setMontantRestant(montantRestant + cs.montantRestant());
    cs.setMontantRetire(montantRetire + cs.montantRetire());
    cs.setReglementEspece(montantEspece + cs.reglementEspece());
    cs.setReglementCheque(montantCheque + cs.reglementCheque());
    cs.setReglementCarteDeCredit(montantCarteDeCredit + cs.reglementCarteDeCredit());
    cs.setReglementCompteClient(montantCompteClient + cs.reglementCompteClient());
    cs.setDepotSurCompteClient(depotCompteClient + cs.depotSurCompteClient());
    cs.setDepouille(false);
    submitAll = submitAll && cs.enregistrer();

    if(submitAll)
    {
        m_db->commit();
        actualiserFenetre();
    }else
        m_db->rollback();

    m_bdWaiting->close();
}

void MdiService::actualiserConsoDeCeJour()
{
    m_affichage = true;
    rafraichirTable();
    m_affichage = false;
}

void MdiService::actualiserActivites()
{
    m_affichage = true;
    chargerActivites();
    m_affichage = false;
}

void MdiService::actualiserTableauDeBord()
{
    m_affichage = true;
    chargerTables();

    QString table;
    if(ui->treeWidgetTablesOccupees->topLevelItemCount() != 0)
        table = ui->treeWidgetTablesOccupees->topLevelItem(0)->text(0);

    afficherTableauDeBord(table);
    m_affichage = false;
}

void MdiService::actualiserOngletActif()
{
    switch(ui->tabWidget->currentIndex())
    {
        case 0 :
            actualiserConsoDeCeJour();
            break;
        case 1:
            actualiserActivites();
            break;
        default:
            actualiserTableauDeBord();
            break;
    }
}
