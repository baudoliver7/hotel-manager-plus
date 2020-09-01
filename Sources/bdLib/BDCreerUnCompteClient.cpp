#include "BDCreerUnCompteClient.h"
#include "ui_BDCreerUnCompteClient.h"

BDCreerUnCompteClient::BDCreerUnCompteClient(BDD *db, const agent &ag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDCreerUnCompteClient)
{
    ui->setupUi(this);

    m_db = db;
    ui->btn_creer->setEnabled(false);
    ui->comboBoxModeDePayement->setEnabled(false);

    m_agent = ag;

    chargerModeDePayement();
}

BDCreerUnCompteClient::~BDCreerUnCompteClient()
{
    delete ui;
}

void BDCreerUnCompteClient::changeEvent(QEvent *e)
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

void BDCreerUnCompteClient::on_btn_creer_clicked()
{
    compteClient cc; // compte à creer

    // unicité des libellés
    QString condition = tr("%1 = '%2' AND %3 = %4")
                        .arg(cc.libelleName())
                        .arg(ui->lineEditLibelle->text())
                        .arg(cc.codeClientName())
                        .arg(m_client.codeDuClient());

    if(!InfosSurBD::enregistrements(CompteClient::Libelle, condition).isEmpty())
    {
        QMessageBox::information(this, "Existance du compte", "Le libellé du compte à créer existe déjà pour ce client! \n\nEssayer un autre libellé.");
        return;
    }

    m_db->transaction();
    bool submitAll = true;

    // créer le compte
    cc.setCodeClient(m_client.codeDuClient());
    cc.setLibelle(ui->lineEditLibelle->text());

    int solde = ui->spinBoxSolde->value();
    cc.setSolde(0);
    submitAll = submitAll && cc.enregistrer();

    // faire un mouvement
    QDateTime now = Horloge::currentDateTime();
    if(solde != 0)
    {
        // créditer le compte client
        int idOperation = MesTables::faireUnMouvementCompteClient(  m_agent
                                                                    , now
                                                                    , cc.idCompteClient()
                                                                    , QString("Dépôt à la création d'un compte client")
                                                                    , solde
                                                                    , false
                                                                    , submitAll);

        // faire un récu
        submitAll = submitAll && MesTables::enregistrerUneOperationService(  m_agent
                                                                              , recuInitial::IdDepotSurCompteClient
                                                                              , now
                                                                              , solde
                                                                              , QString("dépôt à la création d'un compte client")
                                                                              , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                              , idOperation,
                                                                              operationCompteClient().tableName()); // pour retracer l'opération
    }

    if(submitAll)
    {
        m_db->commit();
        chargerComptesExistants();

        ui->lineEditLibelle->setText(QString());
        ui->spinBoxSolde->setValue(0);
    }else
        m_db->rollback();
}

void BDCreerUnCompteClient::on_btn_annuler_clicked()
{
    close();
}

void BDCreerUnCompteClient::on_btn_client_clicked()
{
    BDIdentifierClientHotelSimple bd(this);
    bd.setWindowTitle("Identifier le client");

    if(bd.exec() == QDialog::Accepted)
    {
        m_client = bd.clientSelectionne();
        ui->lineEditClient->setText(m_client.nomComplet());
        chargerComptesExistants();

        updateEtatBtnCreer();
    }
}

void BDCreerUnCompteClient::updateEtatBtnCreer()
{
    bool enabled = !ui->lineEditClient->text().isEmpty() && !ui->lineEditLibelle->text().isEmpty();
    ui->btn_creer->setEnabled(enabled);
}

void BDCreerUnCompteClient::on_lineEditLibelle_textChanged(QString)
{
    updateEtatBtnCreer();
}

void BDCreerUnCompteClient::chargerComptesExistants()
{
    ui->treeWidgetComptes->clear();

    QString condition = tr("%1 = %2").arg(compteClient().codeClientName()).arg(m_client.codeDuClient());

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(CompteClient::Libelle, condition);

    foreach(QSqlRecord r, records)
    {
        compteClient cc(r);
        QStringList data;
        data << cc.libelle();
        data << QString::number(cc.solde());
        ui->treeWidgetComptes->addTopLevelItem(new QTreeWidgetItem(data));
    }
}

void BDCreerUnCompteClient::on_spinBoxSolde_valueChanged(int value)
{
    ui->comboBoxModeDePayement->setEnabled(value != 0);
}

void BDCreerUnCompteClient::chargerModeDePayement()
{
    ui->comboBoxModeDePayement->clear();

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ModeDePayement::Libelle);

    QStringList modes;
    foreach(QSqlRecord r, records)
    {
        modeDePayement mr(r);
        modes << mr.mode();
    }

    ui->comboBoxModeDePayement->addItems(modes);
}
