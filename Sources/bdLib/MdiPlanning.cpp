#include "MdiPlanning.h"
#include "ui_MdiPlanning.h"

#define ID_TAB_FACTURES_DE_CE_JOUR 2
#define ID_TAB_FACTURES_NON_REGLEES 3
#define ID_TAB_ACTIVITES 4

MdiPlanning::MdiPlanning(BDD *db, const agent &ag, Horloge *horloge, QWidget *parent, bool showPlanningsOnly, bool planningsReadOnly) :
    QWidget(parent),
    ui(new Ui::MdiPlanning)
{
    ui->setupUi(this);

    m_planningsReadOnly = planningsReadOnly;
    m_showPlanningsOnly = showPlanningsOnly;

    m_db = db;
    m_op = new Operation(this, 0);
    m_op->setParentWidget(parent);

    m_horloge = horloge;
    m_fermer = false;        

    m_affichage = false;
    m_agent = new agent(ag);
    chargerChambresDispo();

    initPlanningReservation();
    initPlanningOccupation();

    initialiserTableauActivites();
    initialiserTableau();
    initialiserTableauDeCeJour();        

    connect(m_piloteDePlanningReserv, SIGNAL(occupationEnregistree(occupation)), m_piloteDePlanningOccup, SLOT(showOccupation(occupation)));
    connect(m_piloteDePlanningReserv, SIGNAL(reservationEnregistree(reservation)), m_piloteDePlanningOccup, SLOT(showSigneReservation(reservation)));
    connect(m_piloteDePlanningOccup, SIGNAL(occupationEnregistree(occupation)), m_piloteDePlanningReserv, SLOT(showSigneOccupation(occupation)));

    connect(m_piloteDePlanningReserv, SIGNAL(rendreChambresIndispo(QDate,QDate,QString)), m_piloteDePlanningOccup, SLOT(showChambresIndispo(QDate,QDate,QString)));
    connect(m_piloteDePlanningReserv, SIGNAL(rendreChambresDispo(QDate,QDate,QString)), m_piloteDePlanningOccup, SLOT(showChambresDispo(QDate,QDate,QString)));

    actualiserFenetre();

    m_piloteDePlanningReserv->rafraichirPlanningReserv();
    m_piloteDePlanningOccup->rafraichirPlanningOccup();

    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(verifierHeureFinOccupation()));

    m_bdWaiting = new BDWaiting(this);
}

MdiPlanning::~MdiPlanning()
{
    delete ui;

    delete m_piloteDePlanningReserv;
    delete m_piloteDePlanningOccup;
    delete m_agent;

    // detruire le modèle de la table des activités si elle est affichée
    if(!m_showPlanningsOnly)
        delete m_modelActivites;

    delete m_op;
    delete m_bdWaiting;
}

void MdiPlanning::changeEvent(QEvent *e)
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

void MdiPlanning::closeEvent(QCloseEvent * e)
{
    if(m_planningsReadOnly)
    {
        /* Ne pas avertir avant ferméture en lecture seule */
        QWidget::closeEvent(e);
        emit closed();
        e->accept();
    }else
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
}

void MdiPlanning::afficherLocations()
{
    m_piloteDePlanningReserv->clearReservations();
    m_piloteDePlanningReserv->showOccupations();
}

void MdiPlanning::actualiserFenetre(QList<occupation> l)
{
    foreach(occupation oc, l)
    {
        m_piloteDePlanningOccup->showOccupation(oc);
    }

    actualiserFenetre();
}

void MdiPlanning::afficherReservations()
{
    m_piloteDePlanningReserv->clearOccupations();
    m_piloteDePlanningReserv->showReservations();
}

void MdiPlanning::afficherMixte()
{
    m_piloteDePlanningReserv->rafraichirPlanning();
}

void MdiPlanning::initialiserTableauActivites()
{
    if(m_showPlanningsOnly)
    {
        ui->tabWidget->removeTab(ID_TAB_ACTIVITES);
        return;
    }

    ui->btn_cloturer->setEnabled(false);
    ui->btn_imprimerRecu->setEnabled(false);

    m_modelActivites = new QSqlRelationalTableModel();
    m_modelActivites->setTable(OperationService::Libelle);
    m_modelActivites->sort(OperationService::Id::Date, Qt::AscendingOrder);

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
    ui->tableViewActivites->setColumnHidden(OperationService::Id::IdClotureService, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::IdTypeRecu, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::Depouille, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::EstUneEntree, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::TableTypeOperation, true);

    m_modelActivites->setHeaderData(OperationService::Id::Recu, Qt::Horizontal, "Reçu");
    m_modelActivites->setHeaderData(OperationService::Id::Date, Qt::Horizontal, "Date");
    m_modelActivites->setHeaderData(OperationService::Id::Libelle, Qt::Horizontal, "Libellé");
    m_modelActivites->setHeaderData(OperationService::Id::MontantEncaisse, Qt::Horizontal, "Montant encaissé");

    // faire une relation
    modeDePayement mp;
    m_modelActivites->setRelation(OperationService::Id::IdModeDePayement
                                  , QSqlRelation(mp.tableName(), mp.idModeDePayementName(), mp.modeName()));

    m_modelActivites->setHeaderData(OperationService::Id::IdModeDePayement, Qt::Horizontal, "Mode de payement");
    
    connect(ui->tableViewActivites->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(updateEtatBtnImprimerRecu(QModelIndex)));
}

void MdiPlanning::initPlanningReservation()
{
    m_piloteDePlanningReserv = new PiloteDePlanning(m_db, *m_agent, ui->tableWidgetPlanning
                                              , m_chambres, PiloteDePlanning::PlanningDeReservation, this, m_planningsReadOnly);

    connect(m_piloteDePlanningReserv, SIGNAL(typeOperation(QString)), m_op, SLOT(setLibelle(QString)));
    connect(m_piloteDePlanningReserv, SIGNAL(dataATraiter(int)), m_op, SLOT(setMaximum(int)));
    connect(m_piloteDePlanningReserv, SIGNAL(opElt()), m_op, SLOT(perform()));

    m_piloteDePlanningReserv->initTable();

    connect(this, SIGNAL(afficherPlanningReserv()), m_piloteDePlanningReserv, SLOT(show()));

    ui->lineEditDateDebut->setText(m_piloteDePlanningReserv->dateDebut().toString(Qt::SystemLocaleLongDate));
    ui->lineEditDateFin->setText(m_piloteDePlanningReserv->dateFin().toString(Qt::SystemLocaleLongDate));

    ui->lineEditDuree->setText(MesTables::convertirAnMoisSemaineJour(m_piloteDePlanningReserv->dateDebut().daysTo(m_piloteDePlanningReserv->dateFin())));
    connect(m_horloge, SIGNAL(dayOvered()), m_piloteDePlanningReserv, SLOT(show()));
    connect(m_piloteDePlanningReserv, SIGNAL(planningModifie(bool)), this, SLOT(setPlanningReservModified(bool)));
    connect(ui->btn_setPeriodeReserv, SIGNAL(clicked()), this, SLOT(setPeriodeReserv()));

    m_planningReservModified = false;
}

void MdiPlanning::initPlanningOccupation()
{
    m_piloteDePlanningOccup = new PiloteDePlanning(m_db, *m_agent, ui->tableWidgetPlanningOccup
                                              , m_chambres, PiloteDePlanning::PlanningDOccupation, this, m_planningsReadOnly);

    connect(m_piloteDePlanningOccup, SIGNAL(typeOperation(QString)), m_op, SLOT(setLibelle(QString)));
    connect(m_piloteDePlanningOccup, SIGNAL(dataATraiter(int)), m_op, SLOT(setMaximum(int)));
    connect(m_piloteDePlanningOccup, SIGNAL(opElt()), m_op, SLOT(perform()));

    m_piloteDePlanningOccup->initTable();

    connect(this, SIGNAL(afficherPlanningOccup()), m_piloteDePlanningOccup, SLOT(show()));
    connect(m_piloteDePlanningOccup, SIGNAL(rendreChambresIndispo(QDate,QDate,QString)), m_piloteDePlanningReserv, SLOT(showChambresIndispo(QDate,QDate,QString)));
    connect(m_piloteDePlanningOccup, SIGNAL(rendreChambresDispo(QDate,QDate,QString)), m_piloteDePlanningReserv, SLOT(showChambresDispo(QDate,QDate,QString)));
    connect(m_piloteDePlanningOccup, SIGNAL(imprimerOccupation(occupation)), this, SLOT(imprimer(occupation)));

    ui->lineEditDateDebutOccup->setText(m_piloteDePlanningOccup->dateDebut().toString(Qt::SystemLocaleLongDate));
    ui->lineEditDateFinOccup->setText(m_piloteDePlanningOccup->dateFin().toString(Qt::SystemLocaleLongDate));

    ui->lineEditDureeOccup->setText(MesTables::convertirAnMoisSemaineJour(m_piloteDePlanningOccup->dateDebut().daysTo(m_piloteDePlanningOccup->dateFin())));
    connect(m_horloge, SIGNAL(dayOvered()), m_piloteDePlanningOccup, SLOT(show()));
    connect(m_piloteDePlanningOccup, SIGNAL(planningModifie(bool)), this, SLOT(setPlanningOccupModified(bool)));
    connect(ui->btn_setPeriodeOccup, SIGNAL(clicked()), this, SLOT(setPeriodeOccup()));

    m_planningOccupModified = false;
}

void MdiPlanning::chargerActivites()
{
    m_modelActivites->select();
    ui->tableViewActivites->resizeColumnToContents(OperationService::Id::Libelle);

    double sommeEncaissee = 0;
    double sommeRetiree = 0;
    for(int i = 0; i < m_modelActivites->rowCount(); i++)
    {
        QSqlRecord record = m_modelActivites->record(i);
        operationService os(record);

        if(os.estUneEntree())
            sommeEncaissee += os.montantEncaisse();
        else
            sommeRetiree += os.montantEncaisse();
    }

    ui->lineEditMontantTotalEncaisse->setText(MesTables::doubleToAllMoney(sommeEncaissee));
    ui->lineEditMontantTotalRetire->setText(MesTables::doubleToAllMoney(sommeRetiree));

    updateEtatBtnCloturer();
}

void MdiPlanning::updateEtatBtnCloturer()
{
    ui->btn_cloturer->setEnabled(m_modelActivites->rowCount() != 0);
}

void MdiPlanning::updateEtatBtnImprimerFacture(QModelIndex index)
{
    ui->btn_imprimerFacture->setEnabled(index.isValid());
    ui->btn_reglerFacture->setEnabled(index.isValid());
}

void MdiPlanning::updateEtatBtnImprimerRecu(QModelIndex index)
{
    ui->btn_imprimerRecu->setEnabled(index.isValid());
}

void MdiPlanning::on_btn_cloturer_clicked()
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

void MdiPlanning::actualiserFenetre()
{
    if(m_showPlanningsOnly)
        return;

    chargerActivites();
    chargerFacturesImpayees();
    chargerFacturesDeCeJour();
}

void MdiPlanning::chargerFacturesImpayees()
{
    ui->tableWidgetFactures->setRowCount(0);

    occupation oc1;
    libererOccup li;
    QString condition = tr("(%1 > %2 OR %3 > %4) AND (%5 = %6 OR %7 IN (SELECT %8 FROM %9))")
                        .arg(oc1.coutName())
                        .arg(oc1.payeeName())
                        .arg(oc1.fraisSupName())
                        .arg(oc1.fraisSupPayeName())
                        .arg(oc1.termineeName())
                        .arg(false)
                        .arg(oc1.numOccupName())
                        .arg(li.numOccupName())
                        .arg(li.tableName());

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Occupation::Libelle, condition);

    double montantRestant = 0;
    for(int i = 0; i < records.count(); i++)
    {
        occupation oc(records.at(i));

        montantRestant += oc.reste() + oc.resteFraisSup();

        client cl(oc.codeClient());

        ui->tableWidgetFactures->setRowCount(i+1);

        afficherElement(i, ID, QString::number(oc.numOccupation()));
        afficherElement(i, FACTURE, oc.facture());
        afficherElement(i, DATEARRIVEE, oc.datedEntree().toString(Qt::SystemLocaleDate));

        QDateTime datedSortie = oc.datedSortie();
        if(oc.terminee())
            datedSortie = libererOccup::selectionner(oc.numOccupation()).date();

        afficherElement(i, CHAMBRE, oc.chambreOccupee());
        afficherElement(i, DATEDEPART, datedSortie.toString(Qt::SystemLocaleDate));
        afficherElement(i, DUREE, MesTables::convertirAnMoisSemaineJour(oc.dureeOccupation()));
        afficherElement(i, MONTANTTOTAL, QString::number(oc.cout() + oc.fraisSupplementaire()));
        afficherElement(i, MONTANTPAYE, QString::number(oc.payee() + oc.fraisSupPayee()));
        afficherElement(i, MONTANTRESTANT, QString::number(oc.reste() + oc.resteFraisSup()));
        afficherElement(i, MATRICULEAGENT, recevoirOccup::selectionner(oc.numOccupation()).matriculeRecepteur());

        afficherElement(i, CLIENT, cl.nomComplet());
    }

    ui->lineEditMontantRestant->setText(MesTables::doubleToAllMoney(montantRestant));
}

void MdiPlanning::chargerFacturesDeCeJour()
{
    ui->tableWidgetFacturesDeJour->setRowCount(0);

    QDate now = Horloge::currentDate();

    QList<QSqlRecord> records;
    records << occupation::occupation_records(now, now);

    double montantRestant = 0;
    double montantEncaisse = 0;
    for(int i = 0; i < records.count(); i++)
    {
        occupation oc(records.at(i));

        if(recevoirOccup::selectionner(oc.numOccupation()).matriculeRecepteur() != m_agent->matricule()
            || oc.terminee())
            continue;

        montantEncaisse += oc.payee() + oc.fraisSupPayee();
        montantRestant += oc.reste() + oc.resteFraisSup();

        client cl(oc.codeClient());

        ui->tableWidgetFacturesDeJour->setRowCount(i+1);

        afficherElement(i, ID, QString::number(oc.numOccupation()), false);
        afficherElement(i, FACTURE, oc.facture(), false);
        afficherElement(i, DATEARRIVEE, oc.datedEntree().time().toString(Qt::ISODate), false);

        QDateTime datedSortie = oc.datedSortie();
        if(oc.terminee())
            datedSortie = libererOccup::selectionner(oc.numOccupation()).date();

        afficherElement(i, CHAMBRE, oc.chambreOccupee(), false);
        afficherElement(i, DATEDEPART, datedSortie.toString(Qt::SystemLocaleDate), false);
        afficherElement(i, DUREE, MesTables::convertirAnMoisSemaineJour(oc.dureeOccupation()), false);
        afficherElement(i, MONTANTTOTAL, QString::number(oc.cout() + oc.fraisSupplementaire()), false);
        afficherElement(i, MONTANTPAYE, QString::number(oc.payee() + oc.fraisSupPayee()), false);
        afficherElement(i, MONTANTRESTANT, QString::number(oc.reste() + oc.resteFraisSup()), false);
        afficherElement(i, MATRICULEAGENT, recevoirOccup::selectionner(oc.numOccupation()).matriculeRecepteur(), false);

        afficherElement(i, CLIENT, cl.nomComplet(), false);
    }

    ui->lineEditMontantEncaisse->setText(MesTables::doubleToAllMoney(montantEncaisse));
    ui->lineEditMontantRestantDeCeJour->setText(MesTables::doubleToAllMoney(montantRestant));
}

void MdiPlanning::afficherElement(int row, int column, const QString &value, bool impayee)
{
    QTableWidgetItem * item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);

    if(impayee)
        ui->tableWidgetFactures->setItem(row, column, item);
    else
        ui->tableWidgetFacturesDeJour->setItem(row, column,item);
}

void MdiPlanning::initialiserTableau()
{
    if(m_showPlanningsOnly)
    {
        ui->tabWidget->removeTab(ID_TAB_FACTURES_NON_REGLEES);
        return;
    }

    ui->btn_imprimerFacture->setEnabled(false);
    ui->btn_reglerFacture->setEnabled(false);

    ui->tableWidgetFactures->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidgetFactures->setColumnHidden(ID, true);

    connect(ui->tableWidgetFactures->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(updateEtatBtnImprimerFacture(QModelIndex)));
}

void MdiPlanning::initialiserTableauDeCeJour()
{
    if(m_showPlanningsOnly)
    {
        ui->tabWidget->removeTab(ID_TAB_FACTURES_DE_CE_JOUR);
        return;
    }

    ui->btn_imprimerFactureDeCeJour->setEnabled(false);

    ui->tableWidgetFacturesDeJour->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidgetFacturesDeJour->setColumnHidden(ID, true);
    ui->tableWidgetFacturesDeJour->setColumnHidden(MATRICULEAGENT, true);

    connect(ui->tableWidgetFacturesDeJour->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(updateEtatBtnImprimerFactureDeCeJour(QModelIndex)));
    connect(m_horloge, SIGNAL(dayOvered()), this, SLOT(chargerFacturesDeCeJour()));
}

void MdiPlanning::on_btn_reglerFacture_clicked()
{
    int currentRow = ui->tableWidgetFactures->currentRow();
    int numOccup = ui->tableWidgetFactures->item(currentRow, ID)->text().toInt();
    occupation oc(numOccup);

    BDFacturerClient bd(m_db, *m_agent, oc.codeClient(), oc.numOccupation(), true, oc.idGroupe() > 0, this);
    bd.setWindowTitle(tr("Régler la facture %1").arg(oc.facture()));
    if(bd.exec() == QDialog::Accepted)
    {
        // actualiser l'occupation sur le planning si la période est sélectionnée
        if(oc.datedEntree().date() >= m_piloteDePlanningOccup->dateDebut()
            && oc.datedEntree().date() <= m_piloteDePlanningOccup->dateFin())
        {
            oc.actualiser();
            m_piloteDePlanningOccup->showOccupation(oc);
        }

        actualiserFenetre();
    }
}

bool MdiPlanning::seDeconnecter()
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

void MdiPlanning::actualiserOngletActif()
{
    int idOnglet = ui->tabWidget->currentIndex();

    switch(idOnglet)
    {
    case 0:
        m_piloteDePlanningReserv->rafraichirReservationsEnCours();
        break;
    case 1:
        m_piloteDePlanningOccup->rafraichirLocationsEnCours();
        break;
    case 2:
        chargerFacturesDeCeJour();
        break;
    case 3:
        chargerFacturesImpayees();
        break;
    default:
        chargerActivites();
    }
}

void MdiPlanning::imprimer(const occupation & oc)
{
    factureHotelIndividu * facture = new factureHotelIndividu(oc);

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

void MdiPlanning::imprimer(const operationService &os)
{
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

void MdiPlanning::updateEtatBtnImprimerFactureDeCeJour(QModelIndex index)
{
    ui->btn_imprimerFactureDeCeJour->setEnabled(index.isValid());
}

void MdiPlanning::on_btn_imprimerFactureDeCeJour_clicked()
{
    int row = ui->tableWidgetFacturesDeJour->currentRow();
    int numOccup = ui->tableWidgetFacturesDeJour->item(row, 0)->text().toInt();

    occupation oc(numOccup);
    imprimer(oc);
}

void MdiPlanning::on_btn_imprimerFacture_clicked()
{
    int row = ui->tableWidgetFactures->currentRow();
    int numOccup = ui->tableWidgetFactures->item(row, 0)->text().toInt();

    occupation oc(numOccup);
    imprimer(oc);
}

void MdiPlanning::on_btn_imprimerRecu_clicked()
{
    int row = ui->tableViewActivites->currentIndex().row();
    QSqlRecord record = m_modelActivites->record(row);

    operationService os(record);
    os.actualiser(); // recharger pour avoir les bonnes valeurs
    imprimer(os);
}

void MdiPlanning::chargerChambresDispo()
{
    m_chambres_str.clear();
    m_chambres.clear();

    QSqlTableModel * model = new QSqlTableModel;
    model->setTable(Chambre::Libelle);
    model->sort(Chambre::Id::IdEtage, Qt::AscendingOrder);

    chambre ch;
    QString condition = tr("%1 = %2").arg(ch.horsServiceName()).arg(false);
    model->setFilter(condition);
    model->select();

    for(int i = 0; i < model->rowCount(); i++)
    {
        m_chambres_str << model->record(i).value(Chambre::Id::Identifiant).toString();
        m_chambres << new chambre(model->record(i));
    }
}

void MdiPlanning::afficerBD()
{
    QMessageBox::information(this, "infos", "Heure de sortie arrivée!");
}

void MdiPlanning::verifierHeureFinOccupation()
{
    QTime now = Horloge::currentTime();
    now.setHMS(now.hour(), now.minute(), 0, 0);

    HeureLimite hl(1);
    QTime heureFinOccup = hl.heureFinOccupation().addSecs(hl.tempsTolerance() * 60);
    heureFinOccup.setHMS(heureFinOccup.hour(), heureFinOccup.minute(), 0, 0);

    if(now == heureFinOccup)
    {
        m_piloteDePlanningOccup->rafraichirLocationsEnCours();
    }
}

void MdiPlanning::enregisterTout()
{
    m_piloteDePlanningReserv->enregisterTout();
    m_piloteDePlanningOccup->enregisterTout();
}

void MdiPlanning::setPlanningOccupModified(bool modified)
{
    m_planningOccupModified = modified;

    if(m_planningOccupModified || m_planningReservModified)
        emit planningModifie(true);
    else
        emit planningModifie(false);
}

void MdiPlanning::setPlanningReservModified(bool modified)
{
    m_planningReservModified = modified;

    if(m_planningOccupModified || m_planningReservModified)
        emit planningModifie(true);
    else
        emit planningModifie(false);
}

void MdiPlanning::setPeriodeReserv()
{
    BDSetPeriode * bd = new BDSetPeriode(m_piloteDePlanningReserv->dateDebut(), m_piloteDePlanningReserv->dateFin(), this);
    bd->setWindowTitle("Sélectionner une période");

    if((bd->exec() == QDialog::Accepted) && bd->isModified())
    {
        // il doit avoir un écart d'au moins 2 semaines
        if(bd->dateDebut().daysTo(bd->dateFin()) >= 15)
        {
            m_piloteDePlanningReserv->setJourDebut(bd->dateDebut());
            m_piloteDePlanningReserv->setJourFin(bd->dateFin());
            ui->lineEditDuree->setText(MesTables::convertirAnMoisSemaineJour(m_piloteDePlanningReserv->dateDebut().daysTo(m_piloteDePlanningReserv->dateFin())));
            ui->lineEditDateFin->setText(m_piloteDePlanningReserv->dateFin().toString(Qt::SystemLocaleLongDate));
            ui->lineEditDateDebut->setText(m_piloteDePlanningReserv->dateDebut().toString(Qt::SystemLocaleLongDate));

            emit afficherPlanningReserv();
        }else
        {
            QMessageBox::information(this, "Sélectionner une période", "Les deux dates doivent avoir un écart d'au moins 15 jours!");
        }
    }

    delete bd;
}

void MdiPlanning::setPeriodeOccup()
{
    BDSetPeriode * bd = new BDSetPeriode(m_piloteDePlanningOccup->dateDebut(), m_piloteDePlanningOccup->dateFin(), this);
    bd->setWindowTitle("Sélectionner une période");

    if((bd->exec() == QDialog::Accepted) && bd->isModified())
    {
        // il doit avoir un écart d'au moins 2 semaines
        if(bd->dateDebut().daysTo(bd->dateFin()) >= 15)
        {
            m_piloteDePlanningOccup->setJourDebut(bd->dateDebut());
            m_piloteDePlanningOccup->setJourFin(bd->dateFin());
            ui->lineEditDureeOccup->setText(MesTables::convertirAnMoisSemaineJour(m_piloteDePlanningOccup->dateDebut().daysTo(m_piloteDePlanningOccup->dateFin())));
            ui->lineEditDateFinOccup->setText(m_piloteDePlanningOccup->dateFin().toString(Qt::SystemLocaleLongDate));
            ui->lineEditDateDebutOccup->setText(m_piloteDePlanningOccup->dateDebut().toString(Qt::SystemLocaleLongDate));

            emit afficherPlanningOccup();
        }else
        {
            QMessageBox::information(this, "Sélectionner une période", "Les deux dates doivent avoir un écart d'au moins 15 jours!");
        }
    }

    delete bd;
}

void MdiPlanning::cloturer()
{
    m_db->transaction();

    bool submitAll = true;

    // enregistrer une cloture
    QDate now = Horloge::currentDate();

    clotureService cs(m_agent->matricule(), now);  // sélectionner la cloture de l'agent
    cs.setDate(now);
    cs.setMatriculeAgent(m_agent->matricule());
    submitAll = submitAll && cs.enregistrer();

    int montantEncaisse = 0;
    int montantRestant = 0;
    int montantRetire = 0;
    int montantEspece = 0;
    int montantCheque = 0;
    int montantCarteDeCredit = 0;
    int montantCompteClient = 0;
    int depotCompteClient = 0;

    QList<QSqlRecord> records;
    records << operationService::os_records(m_agent->matricule(), false);

    QList<int> idOccupations;
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
            case modeDePayement::CarteDeCredit: // carte de crédit
                montantCarteDeCredit += os.montantEncaisse();
                break;
            default:
                // compte client
                montantCompteClient += os.montantEncaisse();
        }

        if((os.idTypeRecu() == recuInitial::IdLocation) && !idOccupations.contains(os.idTypeOperation()))
        {
            // on comptabilise le montant à crédit côté réception uniquement seulement
            if(os.libelle().contains("groupe")
                // si l'opération n'a jamais été clôturée
                && !operationService::osExisteEtEstCloturee(os.idTypeRecu(), os.idTypeOperation(), true))
            {
                groupe gp(os.idTypeOperation());
                montantRestant += gp.resteFraisLocation() + gp.resteFraisSup();
            }else
            {
                // si l'opération n'a jamais été clôturée
                if(!operationService::osExisteEtEstCloturee(os.idTypeRecu(), os.idTypeOperation(), false))
                {
                    occupation oc(os.idTypeOperation());
                    montantRestant += oc.reste() + oc.resteFraisSup();
                }
            }
        }

        if(os.idTypeRecu() == recuInitial::IdDepotSurCompteClient)
        {
            depotCompteClient += os.montantEncaisse();
        }

        idOccupations << os.idTypeOperation();

        os.setCloturee(true);
        os.setIdClotureService(cs.idClotureService());
        submitAll = submitAll && os.enregistrer();
    }

    cs.setMontantEncaisse(montantEncaisse + cs.montantEncaisse());
    cs.setMontantRetire(montantRetire + cs.montantRetire());
    cs.setMontantRestant(montantRestant + cs.montantRestant());
    cs.setReglementEspece(montantEspece + cs.reglementEspece());
    cs.setReglementCheque(montantCheque + cs.reglementCheque());
    cs.setReglementCarteDeCredit(montantCarteDeCredit + cs.reglementCarteDeCredit());
    cs.setDepotSurCompteClient(cs.depotSurCompteClient() + depotCompteClient);
    cs.setReglementCompteClient(cs.reglementCompteClient() + montantCompteClient);
    cs.setDepouille(false);
    submitAll = submitAll && cs.enregistrer();

    if(submitAll)
    {
        m_db->commit();
        actualiserFenetre();
    }else
    {
        m_db->rollback();
    }

    m_bdWaiting->close();
}
