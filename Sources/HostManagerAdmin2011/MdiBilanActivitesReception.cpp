#include "MdiBilanActivitesReceptionception.h"
#include "ui_MdiBilanActivitesReception.h"

MdiBilanActivitesReception::MdiBilanActivitesReception(agent *ag, QString path, Horloge *horloge, serviceEntreprise *service, QDateTime dateDeConnection, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MdiBilanActivitesReception)
{
    ui->setupUi(this);

    m_affichage = false;
    ui->btn_imprimerFacture->setVisible(false);
    ui->btn_detailsRecept->setEnabled(false);
    ui->btn_detailsResto->setEnabled(false);
    ui->btn_details->setEnabled(false);
    ui->frame->setVisible(false);
    ui->btn_actualiser->setVisible(false);
    m_chemin = path;
    m_service = service;
    m_horloge = horloge;
    m_admin = ag;
    m_parent = parent;

    afficherDateDeConnection(dateDeConnection);
    initialiserMessagerie();
    initCloturesReception();
    initCloturesRestauration();
    initPeriode();

    ui->tableWidgetOccup->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetReserv->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetDureeActivites->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetDureeActivitesResto->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetActivitesResto->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetActivitesResto->setColumnHidden(8, true);
    ui->tableWidgetActivitesResto->setColumnHidden(9, true);

    chargerRecepteurs();
    chargerRestaurataires();

    afficherHorloge();
    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(afficherHorloge()));

    connect(ui->tableViewCloturesReception->selectionModel()
           , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
           , this
           , SLOT(updateEtatBtnDetailsClotureRecept(QModelIndex)));

    connect(ui->tableViewCloturesRestauration->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this
            , SLOT(updateEtatBtnDetailsClotureResto(QModelIndex)));

    connect(ui->tableWidgetActivitesResto->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this
            , SLOT(updateEtatBtnDetailsConsoResto(QModelIndex)));

    connect(ui->btn_setPeriode, SIGNAL(clicked()), this, SLOT(setPeriode()));

    m_bdWaiting = new BDWaiting(this);
    rafraichir();
}

MdiBilanActivitesReception::~MdiBilanActivitesReception()
{
    delete ui;
    delete m_bdWaiting;
    //delete m_bdMessagerie;
}

void MdiBilanActivitesReception::lancerLireMsg()
{
    emit lireMsg();
}

void MdiBilanActivitesReception::changeEvent(QEvent *e)
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

void MdiBilanActivitesReception::closeEvent(QCloseEvent *e)
{
    QWidget::closeEvent(e);
    emit closed();

    e->accept();
}

void MdiBilanActivitesReception::chargerRecepteurs()
{
    m_affichage = true;
    QString matriculeEnCours = ui->comboBoxRecepteur->currentText();
    ui->comboBoxRecepteur->clear();

    QStringList recepteurs;

    QString condition = tr("%1 = %2").arg(agent().idServiceName())
                                     .arg(IDRECEPTION);
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Agent::Libelle, condition);

    for(int i = 0; i < records.count(); i++)
    {
        agent r(records.at(i));
        if(r.statut() != agent::EnAttente)
        {
            recepteurs << r.matricule();
        }
    }

    ui->comboBoxRecepteur->addItems(recepteurs);

    if(!matriculeEnCours.isEmpty() && recepteurs.contains(matriculeEnCours))
        ui->comboBoxRecepteur->setCurrentIndex(recepteurs.indexOf(matriculeEnCours));

    m_affichage = false;
}

void MdiBilanActivitesReception::chargerRestaurataires()
{
    m_affichage = true;
    QString matriculeEnCours = ui->comboBoxRestaurataires->currentText();

    ui->comboBoxRestaurataires->clear();
    QStringList restaurataires;

    QString condition = tr("%1 = %2").arg(agent().idServiceName())
                                     .arg(IDRESTAURATION);
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Agent::Libelle, condition);

    for(int i = 0; i < records.count(); i++)
    {
        agent r(records.at(i));
        if(r.statut() != agent::EnAttente)
        {
            restaurataires << r.matricule();
        }
    }

    ui->comboBoxRestaurataires->addItems(restaurataires);
    if(!matriculeEnCours.isEmpty() && restaurataires.contains(matriculeEnCours))
        ui->comboBoxRestaurataires->setCurrentIndex(restaurataires.indexOf(matriculeEnCours));

    m_affichage = false;
}

void MdiBilanActivitesReception::on_comboBoxRecepteur_currentIndexChanged(QString matricule)
{
    if(matricule.isEmpty())
        return;

    if(!m_affichage)
    {
        rafraichirRecept();
    }
}

void MdiBilanActivitesReception::on_comboBoxRestaurataires_currentIndexChanged(QString matricule)
{
    if(matricule.isEmpty())
        return;

    if(!m_affichage)
    {
        rafraichirResto();
    }
}

void MdiBilanActivitesReception::rafraichir()
{
    emit debuterTraitement();

    /* calculer l'intervalle entre les deux périodes */
    int nbJours = m_dateDebut.daysTo(m_dateFin) + 1;
    ui->duree->setText(convertirAnMoisSemaineJour(nbJours));

    // afficher réception
    QString matricule1 = ui->comboBoxRecepteur->currentText();
    chargerCloturesReception(matricule1);
    emit updateProgressBar(20);

    chargerActivites(matricule1);

    emit updateProgressBar(60);
    chargerDureeActivites(matricule1);

    // afficher restauration
    QString matricule2 = ui->comboBoxRestaurataires->currentText();
    chargerActivitesResto(matricule2);

    emit updateProgressBar(80);
    chargerCloturesRestauration(matricule2);

    emit updateProgressBar(90);
    chargerDureeActivitesResto(matricule2);

    emit terminerTraitement();

    m_bdWaiting->close();
}

void MdiBilanActivitesReception::chargerActivites(QString matricule)
{
    ui->tableWidgetOccup->setRowCount(0);
    ui->tableWidgetReserv->setRowCount(0);
    m_chiffredAffaires = 0;
    m_avances = 0;
    m_nbAnomaliesLoc = 0;

    chargerActivitesReserv(matricule);
    chargerActivitesOccup(matricule);

    ui->labelNbOccup->setText(tr(" %1 location(s)").arg(ui->tableWidgetOccup->rowCount()));
    ui->labelNbReserv->setText(tr(" %1 réservation(s)").arg(ui->tableWidgetReserv->rowCount()));
    ui->lineEditChAff->setText(MesTables::doubleToAllMoney(m_chiffredAffaires));
    ui->lineEditAvances->setText(MesTables::doubleToAllMoney(m_avances));

    if(m_nbAnomaliesLoc == 0)
    {
        ui->labelNbAnomalies->setText(QString());
    }else
    {
        ui->labelNbAnomalies->setText(tr("%1 anomalie(s)").arg(m_nbAnomaliesLoc));
    }
}

void MdiBilanActivitesReception::chargerDureeActivites(QString matricule)
{
    ui->tableWidgetDureeActivites->setRowCount(0);
    int duree = 0;

    // durée totale
    QList<QSqlRecord> services;
    services << service::service_records(m_dateDebut, m_dateFin, matricule);

    if(!services.isEmpty())
    {
        for(int i = 0; i < services.count(); i++)
        {
            service s(services.at(i));
            ajouterService(s);
            duree += s.dureeEnMinutes();
        }
    }

    ui->lineEditDureeTotale->setText(MesTables::convertirHeureMinute(duree));
}

void MdiBilanActivitesReception::chargerDureeActivitesResto(QString matricule)
{
    ui->tableWidgetDureeActivitesResto->setRowCount(0);
    int duree = 0;

    // durée totale
    QList<QSqlRecord> services;
    services << service::service_records(m_dateDebut, m_dateFin, matricule);

    if(!services.isEmpty())
    {
        for(int row = 0; row < services.count(); row++)
        {
            ui->tableWidgetDureeActivitesResto->setRowCount(row + 1);
            service s(services.at(row));

            QStringList data;
            data << s.heureDebut().toString(Qt::SystemLocaleDate)
                 << s.heureFin().toString(Qt::SystemLocaleDate)
                 << MesTables::convertirHeureMinute(s.dureeEnMinutes());

            for(int col = 0; col < data.count(); col++)
            {
                QTableWidgetItem * item = new QTableWidgetItem(data.at(col));
                item->setTextAlignment(Qt::AlignCenter);

                ui->tableWidgetDureeActivitesResto->setItem(row, col, item);
            }

            duree += s.dureeEnMinutes();
        }
    }

    ui->lineEditDureeTotaleResto->setText(MesTables::convertirHeureMinute(duree));
}

void MdiBilanActivitesReception::chargerActivitesReserv(QString matricule)
{
    QString condition = QObject::tr("DATE(%1) BETWEEN '%2' AND '%3'")
                        .arg(reservation().dateDeDemandeName())
                        .arg(m_dateDebut.toString(Qt::ISODate))
                        .arg(m_dateFin.toString(Qt::ISODate));

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Reservation::Libelle, condition);

    for(int i = 0; i < records.count(); i++)
    {
         reservation rv(records.at(i));
         emettreReserv em(emettreReserv::selectionner(rv.numReservation()));
         if(em.matriculeRecepteur() == matricule)
         {
             QList<QSqlRecord> records1;
             records1 << chambreReservee::chambre_reservee_records(rv.numReservation());

             foreach(QSqlRecord r, records1)
             {
                 chambreReservee chr(r);
                 effectuerReserv eff(effectuerReserv::selectionner(rv.numReservation()));

                 ajouterReservation(chr, eff.existe());
             }

             m_avances += rv.avance();
         }
    }
}

void MdiBilanActivitesReception::chargerActivitesOccup(QString matricule)
{    
    QList<QSqlRecord> records;
    records << occupation::occupation_records_a_terme(m_dateDebut, m_dateFin, matricule);

    foreach(QSqlRecord r, records)
    {
        occupation oc(r);
        ajouterOccupation(oc);
        m_chiffredAffaires += oc.payee();
    }
}

void MdiBilanActivitesReception::ajouterReservation(chambreReservee rv, bool effectuee)
{
    reservation rv1(rv.numReservation());
    client cl(rv1.codeClient());

    QString effectueeStr;
    if(effectuee)
    {
        effectueeStr = "Oui";
    }else
    {
        effectueeStr = "Non";
    }

    QStringList donnees;
    donnees << cl.nom() + " " + cl.prenoms()
            << rv1.dateDeDemande().toString(Qt::SystemLocaleLongDate)
            << rv1.datedEntree().toString(Qt::SystemLocaleLongDate)
            << MesTables::convertirAnMoisSemaineJour(rv1.dureeOccupation())
            << rv.identiteCh()
            << effectueeStr;

    int row = ui->tableWidgetReserv->rowCount();
    ui->tableWidgetReserv->setRowCount(row + 1);
    for(int i = CLIENT_RV; i <= EXECUTEE; i++)
    {
        ajouterEltReserv(row, i, donnees.at(i));
    }
}

void MdiBilanActivitesReception::ajouterOccupation(occupation oc)
{
    libererOccup li = libererOccup::selectionner(oc.numOccupation());
    client cl(li.codeClient());
    QStringList donnees;
    donnees << cl.nom() + " " + cl.prenoms()
            << oc.datedEntree().toString(Qt::SystemLocaleLongDate)
            << li.date().toString(Qt::SystemLocaleLongDate)
            << MesTables::convertirAnMoisSemaineJour(oc.dureeOccupation())
            << oc.chambreOccupee();

    bool rouge = false;
    if(oc.datedEntree().daysTo(li.date()) > oc.dureeOccupation())
    {
        m_nbAnomaliesLoc++;
        rouge = true;
    }

    int row = ui->tableWidgetOccup->rowCount();
    ui->tableWidgetOccup->setRowCount(row + 1);
    for(int i = CLIENT_OC; i <= CHAMBRE_OC; i++)
    {
        ajouterEltOccup(row, i, donnees.at(i), rouge);
    }
}

void MdiBilanActivitesReception::ajouterEltReserv(int row, int column, QString valeur)
{
    QTableWidgetItem * item = new QTableWidgetItem(valeur);
    item->setTextAlignment(Qt::AlignCenter);

    ui->tableWidgetReserv->setItem(row, column, item);
}

void MdiBilanActivitesReception::ajouterEltOccup(int row, int column, QString valeur, bool rouge)
{
    QTableWidgetItem * item = new QTableWidgetItem(valeur);
    item->setTextAlignment(Qt::AlignCenter);
    if(rouge)
    {
        item->setBackground(QBrush(Qt::red));
    }

    ui->tableWidgetOccup->setItem(row, column, item);
}

QString MdiBilanActivitesReception::convertirAnMoisSemaineJour(int nbJours)
{
    QString dureeStr;

    if(nbJours /360 > 0)
    {
        int annee = nbJours / 360;
        if(annee == 1)
        {
            dureeStr = "1 année";
        }else
        {
            dureeStr = tr("%1 années").arg(annee);
        }

        nbJours %= 360;
    }

    if(nbJours / 30 > 0)
    {
        int mois = nbJours / 30;
        dureeStr.append(tr(" %1 mois").arg(mois));

        nbJours %= 30;
    }

    if(nbJours / 7 > 0)
    {
        int semaine = nbJours / 7;
        if(semaine == 1)
        {
            dureeStr.append(" 1 semaine");
        }else
        {
            dureeStr.append(tr(" %1 semaines").arg(semaine));
        }

        nbJours %= 7;
    }

    if(nbJours != 0)
    {
        if(nbJours == 1)
        {
            dureeStr.append(" 1 jour");
        }else
        {
            dureeStr.append(tr(" %1 jours").arg(nbJours));
        }
    }

    return dureeStr;
}

QString MdiBilanActivitesReception::convertirHeureMinute(int minute)
{
    QString duree;

    if(minute / 1440 > 0)
    {
        int jour = minute / 1440;
        if(jour == 1)
        {
            duree.append("1 jour");
        }else
        {
            duree.append(tr("%1 jours").arg(jour));
        }

        minute = minute % 1440;
    }

    if(minute / 60 > 0)
    {
        int heure = minute / 60;
        if(heure == 1)
        {
            duree.append(" 1 heure");
        }else
        {
            duree.append(tr(" %1 heures").arg(heure));
        }

        minute = minute % 60;
    }

    if(minute <= 1)
    {
        duree.append(tr(" %1 minute").arg(minute));
    }else
    {
        duree.append(tr(" %1 minutes").arg(minute));
    }

    return duree;
}

void MdiBilanActivitesReception::ajouterService(service s)
{
    QStringList donnees;
    donnees << s.heureDebut().toString(Qt::SystemLocaleLongDate)
            << s.heureFin().toString(Qt::SystemLocaleLongDate)
            << MesTables::convertirHeureMinute(s.dureeEnMinutes());

    int row = ui->tableWidgetDureeActivites->rowCount();
    ui->tableWidgetDureeActivites->setRowCount(row + 1);
    for(int i = DEBUT_SER; i <= DUREE_SER; i++)
    {
        ajouterEltService(row, i, donnees.at(i));
    }
}

void MdiBilanActivitesReception::ajouterEltService(int row, int column, QString valeur)
{
    QTableWidgetItem * item = new QTableWidgetItem(valeur);
    item->setTextAlignment(Qt::AlignCenter);

    ui->tableWidgetDureeActivites->setItem(row, column, item);
}

void MdiBilanActivitesReception::rafraichirRecept()
{
    emit debuterTraitement();

    /* calculer l'intervalle entre les deux périodes */
    int nbJours = m_dateDebut.daysTo(m_dateFin) + 1;
    ui->duree->setText(convertirAnMoisSemaineJour(nbJours));

    QString matricule = ui->comboBoxRecepteur->currentText();
    chargerCloturesReception(matricule);
    emit updateProgressBar(30);

    chargerActivites(matricule);

    emit updateProgressBar(60);
    chargerDureeActivites(matricule);

    emit terminerTraitement();
}

void MdiBilanActivitesReception::rafraichirResto()
{
    emit debuterTraitement();

    QString matricule = ui->comboBoxRestaurataires->currentText();
    chargerActivitesResto(matricule);

    emit updateProgressBar(30);
    chargerCloturesRestauration(matricule);

    emit updateProgressBar(60);
    chargerDureeActivitesResto(matricule);

    emit terminerTraitement();
}

void MdiBilanActivitesReception::on_btn_actualiser_clicked()
{
    ui->btn_actualiser->setEnabled(false);
    m_bdWaiting->show();

    QTimer::singleShot(5, this, SLOT(actualiserOngletActif()));
}

void MdiBilanActivitesReception::on_btn_lire_clicked()
{
    emit lireMsg();
}

void MdiBilanActivitesReception::afficherHorloge()
{
    QTime now = Horloge::currentTime();
    QStringList heure;
    heure = now.toString(Qt::ISODate).split(":");

    ui->label_horloge->setText(tr("Heure du serveur: %1 h %2 min").arg(heure.first()).arg(heure.at(1)));
}

void MdiBilanActivitesReception::initialiserMessagerie()
{
//    m_bdMessagerie = new BDMessagerie( m_admin
//                                      , m_horloge
//                                      , m_chemin
//                                      , ui->btn_lire
//                                      , ui->labelEnveloppe
//                                      , ui->labelNbMsgNonLus
//                                      , m_parent);
//
//    m_bdMessagerie->setWindowModality(Qt::NonModal);
//    m_bdMessagerie->setWindowTitle("Envoyez et/ou recevoir des messages");
}

void MdiBilanActivitesReception::afficherDateDeConnection(QDateTime date)
{
    QString message = tr("Vous êtes connecté depuis le %1").arg(date.toString(Qt::SystemLocaleLongDate));
    ui->label_heureDeConnection->setText(message);
}

void MdiBilanActivitesReception::initCloturesReception()
{
    m_modelCloturesRecept = new QSqlTableModel;
    m_modelCloturesRecept->setTable(ClotureService::Libelle);

    ui->tableViewCloturesReception->setModel(m_modelCloturesRecept);
    ui->tableViewCloturesReception->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // cacher des colonnes
    ui->tableViewCloturesReception->setColumnHidden(ClotureService::Id::IdClotureService, true);
    ui->tableViewCloturesReception->setColumnHidden(ClotureService::Id::MatriculeAgent, true);
    ui->tableViewCloturesReception->setColumnHidden(ClotureService::Id::Depouille, true);

    // renommer les colonnes
    m_modelCloturesRecept->setHeaderData(ClotureService::Id::Date, Qt::Horizontal, tr("Date"));
    m_modelCloturesRecept->setHeaderData(ClotureService::Id::DepotSurCompteClient, Qt::Horizontal, tr("Dépôt sur compte client"));
    m_modelCloturesRecept->setHeaderData(ClotureService::Id::MontantEncaisse, Qt::Horizontal, tr("Montant encaissé"));
    m_modelCloturesRecept->setHeaderData(ClotureService::Id::MontantRestant, Qt::Horizontal, tr("Montant restant"));
    m_modelCloturesRecept->setHeaderData(ClotureService::Id::ReglementEspece, Qt::Horizontal, tr("En espèce"));
    m_modelCloturesRecept->setHeaderData(ClotureService::Id::ReglementCheque, Qt::Horizontal, tr("Par chèque"));
    m_modelCloturesRecept->setHeaderData(ClotureService::Id::ReglementCarteDeCredit, Qt::Horizontal, tr("Par carte bancaire"));
    m_modelCloturesRecept->setHeaderData(ClotureService::Id::ReglementCompteClient, Qt::Horizontal, tr("Par compte client"));
    m_modelCloturesRecept->setHeaderData(ClotureService::Id::MontantRetire, Qt::Horizontal, tr("Montant retiré"));
}

void MdiBilanActivitesReception::initCloturesRestauration()
{
    m_modelCloturesResto = new QSqlTableModel;
    m_modelCloturesResto->setTable(ClotureService::Libelle);

    ui->tableViewCloturesRestauration->setModel(m_modelCloturesResto);
    ui->tableViewCloturesRestauration->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // cacher des colonnes
    ui->tableViewCloturesRestauration->setColumnHidden(ClotureService::Id::IdClotureService, true);
    ui->tableViewCloturesRestauration->setColumnHidden(ClotureService::Id::MatriculeAgent, true);
    ui->tableViewCloturesRestauration->setColumnHidden(ClotureService::Id::Depouille, true);

    // renommer les colonnes
    m_modelCloturesResto->setHeaderData(ClotureService::Id::Date, Qt::Horizontal, tr("Date"));
    m_modelCloturesResto->setHeaderData(ClotureService::Id::DepotSurCompteClient, Qt::Horizontal, tr("Dépôt sur compte client"));
    m_modelCloturesResto->setHeaderData(ClotureService::Id::MontantEncaisse, Qt::Horizontal, tr("Montant encaissé"));
    m_modelCloturesResto->setHeaderData(ClotureService::Id::MontantRestant, Qt::Horizontal, tr("Montant restant"));
    m_modelCloturesResto->setHeaderData(ClotureService::Id::ReglementEspece, Qt::Horizontal, tr("En espèce"));
    m_modelCloturesResto->setHeaderData(ClotureService::Id::ReglementCheque, Qt::Horizontal, tr("Par chèque"));
    m_modelCloturesResto->setHeaderData(ClotureService::Id::ReglementCarteDeCredit, Qt::Horizontal, tr("Par carte bancaire"));
    m_modelCloturesResto->setHeaderData(ClotureService::Id::ReglementCompteClient, Qt::Horizontal, tr("Par compte client"));
    m_modelCloturesResto->setHeaderData(ClotureService::Id::MontantRetire, Qt::Horizontal, tr("Montant retiré"));
}

void MdiBilanActivitesReception::chargerCloturesReception(QString matricule)
{
    clotureService cs;
    QString condition = tr("%1 = '%2' AND %3 BETWEEN '%4' AND '%5'")
                        .arg(cs.matriculeName())
                        .arg(matricule)
                        .arg(cs.dateName())
                        .arg(m_dateDebut.toString(Qt::ISODate))
                        .arg(m_dateFin.toString(Qt::ISODate));

    m_modelCloturesRecept->setFilter(condition);
    m_modelCloturesRecept->select();

    double montantEncaisse = 0;
    double montantRestant = 0;
    double montantRetire = 0;

    for(int row = 0; row < m_modelCloturesRecept->rowCount(); row++)
    {
        clotureService cs1(m_modelCloturesRecept->record(row));

        montantEncaisse += cs1.montantEncaisse();
        montantRestant += cs1.montantRestant();
        montantRetire += cs1.montantRetire();
    }

    ui->lineEditEncaisseClotureRecept->setText(MesTables::doubleToAllMoney(montantEncaisse));
    ui->lineEditRestantClotureRecept->setText(MesTables::doubleToAllMoney(montantRestant));
    ui->lineEditRetireClotureRecept->setText(MesTables::doubleToAllMoney(montantRetire));
}

void MdiBilanActivitesReception::chargerCloturesRestauration(QString matricule)
{
    clotureService cs;
    QString condition = tr("%1 = '%2' AND %3 BETWEEN '%4' AND '%5'")
                        .arg(cs.matriculeName())
                        .arg(matricule)
                        .arg(cs.dateName())
                        .arg(m_dateDebut.toString(Qt::ISODate))
                        .arg(m_dateFin.toString(Qt::ISODate));

    m_modelCloturesResto->setFilter(condition);
    m_modelCloturesResto->select();

    double montantEncaisse = 0;
    double montantRestant = 0;
    double montantRetire = 0;
    for(int row = 0; row < m_modelCloturesResto->rowCount(); row++)
    {
        clotureService cs1(m_modelCloturesResto->record(row));

        montantEncaisse += cs1.montantEncaisse();
        montantRestant += cs1.montantRestant();
        montantRetire += cs1.montantRetire();
    }

    ui->lineEditEncaisseCloture->setText(MesTables::doubleToAllMoney(montantEncaisse));
    ui->lineEditClotureRestant->setText(MesTables::doubleToAllMoney(montantRestant));
    ui->lineEditClotureRetire->setText(MesTables::doubleToAllMoney(montantRetire));
}

void MdiBilanActivitesReception::chargerActivitesResto(QString matricule)
{
    ui->tableWidgetActivitesResto->setRowCount(0);

    repasCompletResto rcr;
    QString condition = tr("%1 = '%2' AND (DATE(%3) BETWEEN '%4' AND '%5') AND %6 is NOT NULL")
                        .arg(rcr.matriculeCaissierName())
                        .arg(matricule)
                        .arg(rcr.dateArriveeName())
                        .arg(m_dateDebut.toString(Qt::ISODate))
                        .arg(m_dateFin.toString(Qt::ISODate))
                        .arg(rcr.dateDepartName()); // terminée

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(RepasCompletResto::Libelle, condition);

    double montantEncaisse = 0;
    double montantRestant = 0;
    QStringList rangee;
    for(int row = 0; row < records.count(); row++)
    {
        rangee.clear();
        ui->tableWidgetActivitesResto->setRowCount(row + 1);
        repasCompletResto rcr1(records.at(row));

        rangee << rcr1.facture();
        QString nomComplet = "Non identifié";
        client cl(rcr1.codeClient());
        if(cl.existe())
            nomComplet = cl.nomComplet();

        rangee << nomComplet
               << rcr1.dateArrivee().toString(Qt::SystemLocaleDate)
               << rcr1.dateDepart().toString(Qt::SystemLocaleDate)
               << MesTables::convertirHeureMinute(rcr1.dureeEnMinutes())
               << QString::number(rcr1.totalAPayer())
               << QString::number(rcr1.montantTotalEncaisse())
               << QString::number(rcr1.reste())
               << rcr1.matriculeCaissier()
               << QString::number(rcr1.idRepasCResto());

        for(int col = 0; col < rangee.count(); col++)
        {
            QTableWidgetItem * item = new QTableWidgetItem(rangee.at(col));
            item->setTextAlignment(Qt::AlignCenter);

            ui->tableWidgetActivitesResto->setItem(row, col, item);
        }

        montantEncaisse += rcr1.montantTotalEncaisse();
        montantRestant += rcr1.reste();
    }

    ui->lineEditEncaisseActivite->setText(MesTables::doubleToAllMoney(montantEncaisse));
    ui->lineEditRestantActivite->setText(MesTables::doubleToAllMoney(montantRestant));
}

void MdiBilanActivitesReception::on_btn_details_clicked()
{
    int row = ui->tableWidgetActivitesResto->currentIndex().row();
    int idRC = ui->tableWidgetActivitesResto->item(row, 9)->text().toInt();

    BDDetailsRepas * bd = new BDDetailsRepas(idRC, this);
    bd->setWindowTitle("Détails de la consommation");

    bd->exec();

    delete bd;
}

void MdiBilanActivitesReception::on_btn_imprimerFacture_clicked() // imprimer facture resto
{

}

void MdiBilanActivitesReception::on_btn_detailsResto_clicked()
{
    int row = ui->tableViewCloturesRestauration->currentIndex().row();
    QSqlRecord record = m_modelCloturesResto->record(row);
    operationService os(record);
    os.actualiser();

    BDDetailsCloture * bd = new BDDetailsCloture(os.idClotureService(), this);
    bd->setWindowTitle("Détails de clôture");
    bd->exec();

    delete bd;
}

void MdiBilanActivitesReception::on_btn_detailsRecept_clicked()
{
    int row = ui->tableViewCloturesReception->currentIndex().row();
    QSqlRecord record = m_modelCloturesRecept->record(row);
    operationService os(record);
    os.actualiser();

    BDDetailsCloture * bd = new BDDetailsCloture(os.idClotureService(), this);
    bd->setWindowTitle("Détails de clôture");
    bd->exec();

    delete bd;
}

void MdiBilanActivitesReception::updateEtatBtnDetailsClotureRecept(QModelIndex index)
{
    ui->btn_detailsRecept->setEnabled(index.isValid());
}

void MdiBilanActivitesReception::updateEtatBtnDetailsClotureResto(QModelIndex index)
{
    ui->btn_detailsResto->setEnabled(index.isValid());
}

void MdiBilanActivitesReception::updateEtatBtnDetailsConsoResto(QModelIndex index)
{
    ui->btn_details->setEnabled(index.isValid());
}

void MdiBilanActivitesReception::actualiserOngletActif()
{
    ui->btn_actualiser->setEnabled(false);

    if(ui->tabWidgetActivitesDesServices->currentIndex() == 0)
    {

        chargerRecepteurs();
        rafraichirRecept();
    }else
    {
        chargerRestaurataires();
        rafraichirResto();
    }

    ui->btn_actualiser->setEnabled(true);

    m_bdWaiting->close();
    ui->btn_actualiser->setEnabled(true);
}

void MdiBilanActivitesReception::setPeriode()
{
    BDSetPeriode * bd = new BDSetPeriode(m_dateDebut, m_dateFin, this);
    bd->setWindowTitle("Sélectionner une période");

    if((bd->exec() == QDialog::Accepted) && bd->isModified())
    {
        m_bdWaiting->show();
        afficherPeriode(bd->dateDebut(), bd->dateFin());
        QTimer::singleShot(5, this, SLOT(rafraichir()));
    }

    delete bd;
}

void MdiBilanActivitesReception::initPeriode()
{
    QDate date = Horloge::currentDate();
    afficherPeriode(date, date);
}

void MdiBilanActivitesReception::afficherPeriode(QDate debut, QDate fin)
{
    m_dateDebut = debut;
    m_dateFin = fin;

    ui->dateDebut->setText(m_dateDebut.toString(Qt::SystemLocaleLongDate));
    ui->dateFin->setText(m_dateFin.toString(Qt::SystemLocaleLongDate));
}
