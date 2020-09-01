#include "BDReglerFacture.h"
#include "ui_BDReglerFacture.h"

BDReglerFacture::BDReglerFacture(BDD *db, const agent &ag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDReglerFacture)
{
    ui->setupUi(this);

    m_db = db;
    m_modified = false;
    m_agent = new agent(ag);
    m_client = new client();

    ui->rb_nonPayees->setChecked(true);
    ui->btn_regler->setEnabled(false);

    chargerFactures();
    ui->comboBoxModeDePayement->addItems(modeDePayement::chargerModeDePayementSansCompteClient());

    connect(ui->lineEditNomEntier, SIGNAL(textChanged(QString)), this, SLOT(chargerFactures()));
    connect(ui->rb_payees, SIGNAL(toggled(bool)), this, SLOT(chargerFactures()));

    connect(ui->treeWidgetFactures->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this
            , SLOT(afficherReglement(QModelIndex)));

    connect(ui->spinBoxMontantEncaisse, SIGNAL(valueChanged(int)), this, SLOT(updateEtatBtnRegler(int)));

    afficherReglement(QModelIndex());
}

BDReglerFacture::~BDReglerFacture()
{
    delete ui;
    delete m_agent;
    delete m_client;
}

void BDReglerFacture::changeEvent(QEvent *e)
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

void BDReglerFacture::on_btn_fermer_clicked()
{
    close();
}

void BDReglerFacture::chargerModeDePayement()
{
    ui->comboBoxModeDePayement->clear();

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ModeDePayement::Libelle);

    QStringList modes;
    foreach(QSqlRecord r, records)
    {
        modeDePayement mp(r);
        modes << mp.mode();
    }

    ui->comboBoxModeDePayement->addItems(modes);
}

void BDReglerFacture::chargerFactures()
{
    ui->treeWidgetFactures->clear();

    if(!m_client->existe())
        return;

    repasCompletResto rcr;
    QString condition;

    if(ui->rb_nonPayees->isChecked())
    {
        condition = tr("%1 = %2 AND %3 = %4 AND %5 is NOT NULL AND %6 < %7")
                            .arg(rcr.codeClientName())
                            .arg(m_client->codeDuClient())
                            .arg(rcr.factureMiseAJourName())
                            .arg(false)
                            .arg(rcr.dateDepartName())
                            .arg(rcr.montantTotalEncaisseName())
                            .arg(rcr.totalAPayerName());
    }else
    {
        condition = tr("%1 = %2 AND %3 = %4 AND %5 is NOT NULL AND %6 = %7")
                            .arg(rcr.codeClientName())
                            .arg(m_client->codeDuClient())
                            .arg(rcr.factureMiseAJourName())
                            .arg(false)
                            .arg(rcr.dateDepartName())
                            .arg(rcr.montantTotalEncaisseName())
                            .arg(rcr.totalAPayerName());
    }

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(rcr.tableName(), condition);

    // afficher
    foreach(QSqlRecord r, records)
    {
        repasCompletResto rcr1(r);
        QStringList data;

        data << rcr1.facture()
             << QString::number(rcr1.totalAPayer())
             << QString::number(rcr1.montantTotalEncaisse())
             << QString::number(rcr1.reste());

        ui->treeWidgetFactures->addTopLevelItem(new QTreeWidgetItem(data));
    }

    ui->treeWidgetFactures->clearSelection();
}

void BDReglerFacture::afficherReglement(QModelIndex index)
{
    if(index.isValid() && ui->rb_nonPayees->isChecked())
    {
        ui->groupBoxReglement->setEnabled(true);
        repasCompletResto rcr(currentFacture());
        ui->groupBoxReglement->setTitle(tr("Réglement de la facture %1").arg(rcr.facture()));
        ui->lineEditMontantARegler->setText(QString::number(rcr.reste()));
        ui->spinBoxMontantEncaisse->setMaximum(rcr.reste());
        ui->spinBoxMontantEncaisse->setMinimum(0);
        ui->spinBoxMontantEncaisse->setValue(0);
        m_rcr = rcr;
    }else
    {
        m_rcr.clear();
        ui->groupBoxReglement->setEnabled(false);
        ui->spinBoxMontantEncaisse->setValue(0);
        ui->lineEditMontantARegler->setText(QString::number(0));
        ui->comboBoxModeDePayement->setCurrentIndex(0);
        ui->groupBoxReglement->setTitle("Réglement");
    }
}

void BDReglerFacture::on_btn_identifier_clicked()
{
    BDIdentifierClientResto * bd = new BDIdentifierClientResto(true, this);
    bd->setWindowTitle("Rechercher le client");

    if(bd->exec() == QDialog::Accepted)
    {
        *m_client = bd->clientSelectionne();
        ui->lineEditNomEntier->setText(m_client->nomComplet());

        ui->comboBoxCompteClient->clear();
        m_comptesClient.clear();

        // charger compte du client
        QList<QSqlRecord> records = compteClient::compteClient_records(m_client->codeDuClient());

        QStringList comptes;
        foreach(QSqlRecord r, records)
        {
            compteClient cc(r);
            comptes << cc.libelle();
            m_comptesClient << cc;
        }

        ui->comboBoxCompteClient->addItems(comptes);

        ui->comboBoxModeDePayement->clear();
        if(comptes.isEmpty())
            ui->comboBoxModeDePayement->addItems(modeDePayement::chargerModeDePayementSansCompteClient());
        else
            ui->comboBoxModeDePayement->addItems(modeDePayement::chargerModeDePayement());
    }

    delete bd;
}

void BDReglerFacture::on_btn_regler_clicked()
{
    QDateTime now = Horloge::currentDateTime();
    int montantEncaisse = ui->spinBoxMontantEncaisse->value();

    if(QMessageBox::information(this, "Régler une facture"
                             , tr("Vous êtes sur le point de régler de %1 la facture %2.\n\n Désirez-vous continuer ?")
                             .arg(montantEncaisse)
                             .arg(currentFacture())
                             , "Oui"
                             , "Non") == 0)
    {
        m_db->transaction();
        bool submitAll = true;

        repasCompletResto rcr(currentFacture());

        // actualiser le montant encaissé de la facture
        rcr.setMontantTotalEncaisse(rcr.montantTotalEncaisse() + montantEncaisse);
        submitAll = submitAll && rcr.enregistrer();

        QString libelle = tr("Réglement de la facture de restauration %1").arg(rcr.facture());

        // faire un réçu
        submitAll = submitAll && MesTables::enregistrerUneOperationService(*m_agent
                                                                          , recuInitial::IdRestauration
                                                                          , now
                                                                          , montantEncaisse
                                                                          , libelle
                                                                          , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                          , rcr.idRepasCResto()
                                                                          , repasCompletResto().tableName());

        int index = ui->comboBoxCompteClient->currentIndex();
        if(ui->comboBoxModeDePayement->currentIndex() + 1 == modeDePayement::CompteClient)
        {
            // débiter le compte client
            MesTables::faireUnMouvementCompteClient(  *m_agent
                                                    , now
                                                    , m_comptesClient.at(index).idCompteClient()
                                                    , libelle
                                                    , montantEncaisse
                                                    , true
                                                    , submitAll);
        }

        if(submitAll)
        {
            m_db->commit();
            // actualiser factures
            chargerFactures();

            m_modified = true;
        }else
        {
            m_db->rollback();
        }
    }
}

QString BDReglerFacture::currentFacture()
{
    int row = ui->treeWidgetFactures->currentIndex().row();
    return ui->treeWidgetFactures->topLevelItem(row)->text(0);
}

void BDReglerFacture::updateEtatBtnRegler(int value)
{
    ui->btn_regler->setEnabled(value != 0);
}

void BDReglerFacture::on_comboBoxModeDePayement_currentIndexChanged(int index)
{
    if(index < 0)
        return;

    if(index + 1 == modeDePayement::CompteClient)
    {
        if(ui->comboBoxCompteClient->count() > 0)
        {
            ui->comboBoxCompteClient->setEnabled(true);
            ui->lineEditSolde->setEnabled(true);

            on_comboBoxCompteClient_currentIndexChanged(0);
        }else
        {
            ui->comboBoxCompteClient->setEnabled(false);
            ui->lineEditSolde->setEnabled(false);
        }
    }else
    {
        int sommeRestant = ui->lineEditMontantARegler->text().toInt();
        ui->spinBoxMontantEncaisse->setMaximum(sommeRestant);

        ui->comboBoxCompteClient->setEnabled(false);
        ui->lineEditSolde->setEnabled(false);
    }
}

void BDReglerFacture::on_comboBoxCompteClient_currentIndexChanged(int index)
{
    if(index <0)
    {
        ui->lineEditSolde->setText(QString());
        return;
    }

    int sommeRestant = ui->lineEditMontantARegler->text().toInt();
    int solde = m_comptesClient.at(index).solde();

    if(sommeRestant > solde)
    {
        ui->spinBoxMontantEncaisse->setMaximum(solde);
    }else
    {
        ui->spinBoxMontantEncaisse->setMaximum(sommeRestant);
    }

    ui->lineEditSolde->setText(QString::number(solde));
}
