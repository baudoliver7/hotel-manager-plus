#include "BDEditerClotures.h"
#include "ui_BDEditerClotures.h"

BDEditerClotures::BDEditerClotures(BDD *db, const agent &ag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDEditerClotures)
{
    ui->setupUi(this);

    m_db = db;
    m_modified = false;
    m_agent = ag;
    m_tauxTVA = taux(taux::TVA).valeur() * 100;
    m_tauxTT = taux(taux::TT).valeur() * 100;

    ui->btn_depouilleEntier->setEnabled(false);
    ui->btn_operation_depouillee->setEnabled(false);
    ui->groupBoxDetails->setEnabled(false);
    ui->groupBoxCritere->setEnabled(false);
    ui->rb_nonDepouilleeDetails->setChecked(true);

    initialiserClotures();
    initialiserOperations();
    initialiserGroupeCritere();
    initialiserComptes();

    connect(ui->rb_nonDepouillee, SIGNAL(toggled(bool)), this, SLOT(chargerClotures()));
    connect(ui->tableViewClotures->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateEtatBtnDepouillerEntier(QModelIndex)));

    connect(ui->tableViewClotures->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateEtatGroupeDetails(QModelIndex)));

    connect(ui->tableViewClotures->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(chargerOperations()));

    connect(ui->tableViewDetailsCloture->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateEtatGroupeCritere(QModelIndex)));

    connect(ui->tableViewDetailsCloture->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateEtatBtnDepouillerOp(QModelIndex)));

    connect(ui->rb_nonDepouilleeDetails, SIGNAL(toggled(bool)), this, SLOT(chargerOperations()));

    connect(ui->rb_vente, SIGNAL(toggled(bool)), this, SLOT(updateEtatGroupeVenteEtLocation(bool)));

    ui->rb_nonDepouillee->setChecked(true);
    ui->rb_vente->setChecked(true);

//    // opération particuliere
//    clotureService cs(14);
//
//    operationService os;
//    QString condition = tr("%1 = %2").arg(os.idClotureServiceName()).arg(cs.idClotureService());
//
//    QList<QSqlRecord> records;
//    records = InfosSurBD::enregistrements(os.tableName(), condition);
//
//    foreach(QSqlRecord r, records)
//    {
//        operationService os1(r);
//        os1.setCloturee(false);
//        os1.setIdClotureService(0);
//        os1.enregistrer();
//    }
//
//    cs.supprimer();
}

BDEditerClotures::~BDEditerClotures()
{
    delete ui;
    delete m_modelClotures;
    delete m_modelOperations;
}

void BDEditerClotures::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void BDEditerClotures::initialiserClotures()
{
    m_modelClotures = new QSqlTableModel;
    m_modelClotures->setTable(ClotureService::Libelle);

    ui->tableViewClotures->setModel(m_modelClotures);

    ui->tableViewClotures->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableViewClotures->setColumnHidden(ClotureService::Id::Depouille, true);

    // renommer les colonnes
    m_modelClotures->setHeaderData(ClotureService::Id::IdClotureService, Qt::Horizontal, tr("N° de la clôture"));
    m_modelClotures->setHeaderData(ClotureService::Id::Date, Qt::Horizontal, tr("Date"));
    m_modelClotures->setHeaderData(ClotureService::Id::DepotSurCompteClient, Qt::Horizontal, tr("Dépôt sur compte client"));
    m_modelClotures->setHeaderData(ClotureService::Id::MontantEncaisse, Qt::Horizontal, tr("Montant encaissé"));
    m_modelClotures->setHeaderData(ClotureService::Id::MontantRestant, Qt::Horizontal, tr("Montant restant"));
    m_modelClotures->setHeaderData(ClotureService::Id::ReglementEspece, Qt::Horizontal, tr("En espèce"));
    m_modelClotures->setHeaderData(ClotureService::Id::ReglementCheque, Qt::Horizontal, tr("Par chèque"));
    m_modelClotures->setHeaderData(ClotureService::Id::ReglementCarteDeCredit, Qt::Horizontal, tr("Par carte bancaire"));
    m_modelClotures->setHeaderData(ClotureService::Id::ReglementCompteClient, Qt::Horizontal, tr("Par compte client"));
    m_modelClotures->setHeaderData(ClotureService::Id::MatriculeAgent, Qt::Horizontal, tr("Matricule de l'agent"));
    m_modelClotures->setHeaderData(ClotureService::Id::MontantRetire, Qt::Horizontal, tr("Montant retiré"));
}

void BDEditerClotures::initialiserOperations()
{
    m_modelOperations = new QSqlRelationalTableModel();
    m_modelOperations->setTable(OperationService::Libelle);

    operationService os;
    QString condition = QObject::tr("%1 = '%2' AND %3 = %4")
                        .arg(os.matriculeAgentName())
                        .arg(m_agent.matricule())
                        .arg(os.clotureeName())
                        .arg(false);

    m_modelOperations->setFilter(condition);

    ui->tableViewDetailsCloture->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewDetailsCloture->setModel(m_modelOperations);

    ui->tableViewDetailsCloture->setColumnHidden(OperationService::Id::IdOperationService, true);
    ui->tableViewDetailsCloture->setColumnHidden(OperationService::Id::Cloturee, true);
    ui->tableViewDetailsCloture->setColumnHidden(OperationService::Id::MatriculeAgent, true);
    ui->tableViewDetailsCloture->setColumnHidden(OperationService::Id::IdTypeOperation, true);
    ui->tableViewDetailsCloture->setColumnHidden(OperationService::Id::IdTypeRecu, true);
    ui->tableViewDetailsCloture->setColumnHidden(OperationService::Id::IdClotureService, true);
    ui->tableViewDetailsCloture->setColumnHidden(OperationService::Id::Depouille, true);
    ui->tableViewDetailsCloture->setColumnHidden(OperationService::Id::EstUneEntree, true);
    ui->tableViewDetailsCloture->sortByColumn(OperationService::Id::Date, Qt::AscendingOrder);

    m_modelOperations->setHeaderData(OperationService::Id::Recu, Qt::Horizontal, "Reçu");
    m_modelOperations->setHeaderData(OperationService::Id::Date, Qt::Horizontal, "Date");
    m_modelOperations->setHeaderData(OperationService::Id::Libelle, Qt::Horizontal, "Libellé");
    m_modelOperations->setHeaderData(OperationService::Id::MontantEncaisse, Qt::Horizontal, "Montant encaissé");

    // faire une relation
    modeDePayement mp;
    m_modelOperations->setRelation(OperationService::Id::IdModeDePayement
                                  , QSqlRelation(mp.tableName(), mp.idModeDePayementName(), mp.modeName()));

    m_modelOperations->setHeaderData(OperationService::Id::IdModeDePayement, Qt::Horizontal, "Mode de payement");

    ui->tableViewDetailsCloture->resizeColumnsToContents();
}

void BDEditerClotures::chargerClotures()
{
    QString condition = tr("%1 = %2")
                        .arg(clotureService().depouilleName())
                        .arg(ui->rb_depouillee->isChecked());

    m_modelClotures->setFilter(condition);
    m_modelClotures->select();

    ui->tableViewClotures->resizeColumnsToContents();
}

void BDEditerClotures::on_btn_fermer_clicked()
{
    close();
}

void BDEditerClotures::on_btn_depouilleEntier_clicked()
{
    int row = ui->tableViewClotures->currentIndex().row();
    QSqlRecord record = m_modelClotures->record(row);
    clotureService cs(record);

    if(QMessageBox::information(this, "Dépouiller entièrement une clôture"
                                , tr("Désirez-vous déclarer la clôture N° %1 entièrement dépouillée?").arg(cs.idClotureService()), "Oui", "Non") == 0)
    {
        operationService os;
        QString condition = tr("%1 = %2 AND %3 = %4")
                            .arg(os.idClotureServiceName())
                            .arg(cs.idClotureService())
                            .arg(os.depouilleName())
                            .arg(false);

        // vérifier que la clôture est entièrement dépouillée
        QList<QSqlRecord> records;
        records = InfosSurBD::enregistrements(OperationService::Libelle, condition);

        if(!records.isEmpty())
        {
            QMessageBox::information(this, "Echec de l'opération"
                                     , "Certaines opérations de la clôture ne sont pas encore dépouillées! \n\nFaites-en le dépouillement puis réessayez.");
            return;
        }

        // déclarer dépouillée
        cs.setDepouille(true);
        cs.enregistrer();

        chargerClotures();
    }    
}

void BDEditerClotures::updateEtatBtnDepouillerEntier(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_depouilleEntier->setEnabled(ui->rb_nonDepouillee->isChecked());
    }else
    {
        ui->btn_depouilleEntier->setEnabled(false);
    }
}

void BDEditerClotures::updateEtatBtnDepouillerOp(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_operation_depouillee->setEnabled(ui->rb_nonDepouilleeDetails->isChecked());
    }else
    {
        ui->btn_operation_depouillee->setEnabled(false);
    }
}

void BDEditerClotures::updateEtatGroupeDetails(QModelIndex index)
{
    ui->groupBoxDetails->setEnabled(index.isValid());
}

void BDEditerClotures::chargerOperations()
{
    if(ui->groupBoxDetails->isEnabled())
    {
        int row = ui->tableViewClotures->currentIndex().row();
        QSqlRecord record = m_modelClotures->record(row);
        clotureService cs(record);

        // charger
        operationService os;
        QString condition = tr("%1 = %2 AND %3 = %4")
                            .arg(os.depouilleName())
                            .arg(ui->rb_depouilleDetails->isChecked())
                            .arg(os.idClotureServiceName())
                            .arg(cs.idClotureService());

        m_modelOperations->setFilter(condition);
        m_modelOperations->select();

        ui->tableViewDetailsCloture->resizeColumnToContents(OperationService::Id::Libelle);
    }
}

void BDEditerClotures::updateEtatGroupeCritere(QModelIndex index)
{
    if(ui->rb_nonDepouilleeDetails->isChecked())
        ui->groupBoxCritere->setEnabled(index.isValid());
    else
        ui->groupBoxCritere->setEnabled(false);

    initialiserGroupeCritere();
}

void BDEditerClotures::updateEtatGroupeVenteEtLocation(bool enabled)
{
    ui->checkBoxAppliquerTVA->setEnabled(enabled);
    ui->doubleSpinBox->setEnabled(enabled);
    ui->checkBoxAppliquerTT->setEnabled(enabled);
    ui->doubleSpinBoxTT->setEnabled(enabled);
}

void BDEditerClotures::initialiserGroupeCritere()
{
    ui->rb_vente->setChecked(true);
    ui->doubleSpinBox->setValue(m_tauxTVA);
    ui->doubleSpinBoxTT->setValue(m_tauxTT);

    ui->checkBoxAppliquerTVA->setChecked(true);
    ui->checkBoxAppliquerTT->setChecked(true);
}

void BDEditerClotures::initialiserComptes()
{
    m_comptesStr.clear();

    QList<QSqlRecord> records = planComptable::pc_records(true);

    foreach(QSqlRecord r, records)
    {
        planComptable pc(r);
        m_comptesStr << pc.libellePersoComplet();
    }

    ui->comboBoxRessource->clear();
    ui->comboBoxRessource->addItems(m_comptesStr);
}

void BDEditerClotures::on_btn_depouiller_clicked()
{
    // vérifier compte tva collectée
    configServiceCompta csc_tvaCollectee(configServiceCompta::TVACollecteeCompta);
    configServiceCompta csc_tt(configServiceCompta::TaxeTouristique);
    if(csc_tvaCollectee.compteAssocie() == 0  || csc_tt.compteAssocie() == 0)
    {
        QMessageBox::warning(this
                             , "Configurer les comptes taxes"
                             , "Les comptes taxes ne sont pas entièrement configurés! \n\nVous pouvez les configurer dans le menu 'configurer -> La comptabilité des services'.");
        return;
    }

    int row = ui->tableViewDetailsCloture->currentIndex().row();
    QSqlRecord record = m_modelOperations->record(row);
    operationService os(record);

    if(QMessageBox::information(this
                             , "Dépouiller une opération"
                             , tr("Vous êtes sur le point de dépouiller l'opération liée au réçu %1. \n\nDésirez-vous continuer ?").arg(os.recu())
                             , "Oui", "Non") == 0)
    {
        m_db->transaction();
        bool submitAll = true;

        // dépouiller
        float totalTaux = (m_tauxTT + m_tauxTVA) / 100.0;
        QDate now = Horloge::currentDate();
        QList<int> numCpts;
        QList<int> montants;
        QList<bool> debiteurs;


        if(ui->rb_depotSurCompteClient->isChecked()
            || (ui->rb_vente->isChecked() && !ui->checkBoxAppliquerTVA->isChecked()))
        {
            numCpts << ui->comboBoxRessource->currentText().split(" ").first().toInt()
                    << ui->comboBoxEmploi->currentText().split(" ").first().toInt();
            debiteurs << false << true;
            montants << os.montantEncaisse() << os.montantEncaisse();
        }else
        {
            int taxeTotal = 0;
            numCpts << ui->comboBoxRessource->currentText().split(" ").first().toInt();

            debiteurs << false;
            montants << os.montantEncaisse();

            if(ui->checkBoxAppliquerTVA->isChecked())
            {
                numCpts << csc_tvaCollectee.compteAssocie();// compte tva
                debiteurs << true;

                int tva = (int)MesTables::tva(os.montantEncaisse(), m_tauxTVA / 100.0, totalTaux);
                montants << tva;

                taxeTotal += tva;
            }

            if(ui->checkBoxAppliquerTT->isChecked())
            {
                numCpts << csc_tt.compteAssocie();// compte tt
                debiteurs << true;

                int tt = (int)MesTables::tt(os.montantEncaisse(), m_tauxTT / 100.0, totalTaux);
                montants << tt;

                taxeTotal += tt;
            }

            numCpts << ui->comboBoxEmploi->currentText().split(" ").first().toInt();// compte emploi
            debiteurs << true;
            montants << os.montantEncaisse() - taxeTotal;
        }


        if(!MesTables::enregistrerUneOperationComptable ( now
                                                        , numCpts
                                                        , os.libelle()
                                                        , debiteurs
                                                        , montants
                                                        , m_agent.matricule()
                                                        , false))
        {
            QMessageBox::warning(this, "Erreur d'enregistrement", "Toute l'opération n'a pas pu être effectuée!");
            submitAll = false;
            m_db->rollback();
            return;
        }

        os.setDepouille(true);
        submitAll = submitAll && os.enregistrer();

        if(submitAll)
        {
            m_db->commit();
            m_modified = true;
            chargerOperations();
        }else
            m_db->rollback();
    }
}

void BDEditerClotures::on_comboBoxRessource_currentIndexChanged(int index)
{
    if(ui->comboBoxRessource->count() <= 1)
    {
        ui->btn_depouiller->setEnabled(false);
        return;
    }

    ui->btn_depouiller->setEnabled(true);

    QStringList m_compteStr1 = m_comptesStr;
    m_compteStr1.removeAt(index);

    ui->comboBoxEmploi->clear();
    ui->comboBoxEmploi->addItems(m_compteStr1);
}

void BDEditerClotures::on_btn_faireUneOperation_clicked()
{
    BDExecuterNlleOperation * bd = new BDExecuterNlleOperation(m_db, m_agent.matricule(), this);
    bd->setWindowTitle("Exécuter une nouvelle opération");

    if(bd->exec() == QDialog::Accepted)
    {
        m_modified = true;
    }
}

bool BDEditerClotures::isModified()
{
    return m_modified;
}

void BDEditerClotures::on_btn_operation_depouillee_clicked()
{
    int row = ui->tableViewDetailsCloture->currentIndex().row();
    QSqlRecord record = m_modelOperations->record(row);
    operationService os(record);

    if(QMessageBox::information(this, "Dépouiller une opération"
                                , tr("Désirez-vous déclarer l'opération N° %1 dépouillée?").arg(os.recu()), "Oui", "Non") == 0)
    {
        // déclarer dépouillée
        os.setDepouille(true);
        os.enregistrer();

        chargerOperations();
    }
}
