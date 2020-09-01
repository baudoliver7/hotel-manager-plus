#include "BDDebiterUnCompteClient.h"
#include "ui_BDDebiterUnCompteClient.h"

BDDebiterUnCompteClient::BDDebiterUnCompteClient(BDD *db, const agent &ag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDDebiterUnCompteClient)
{
    ui->setupUi(this);

    m_db = db;
    m_agent = ag;

    connect(ui->treeWidgetComptesExistants->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this
            , SLOT(updateEtatGroupeDebiterCompte(QModelIndex)));

    connect(ui->spinBoxMontantVerse
            , SIGNAL(valueChanged(int))
            , this
            , SLOT(updateEtatBtnDebiter(int)));

    chargerModeDePayement();
    updateEtatGroupeDebiterCompte(QModelIndex());
    updateEtatBtnDebiter(0);

    ui->treeWidgetComptesExistants->setColumnHidden(NUM, true);

    connect(ui->rb_debiter, SIGNAL(toggled(bool)), this, SLOT(updateLibelleBtnDebiter()));
    connect(ui->rb_debiter, SIGNAL(toggled(bool)), this, SLOT(setLimitesMontantVerse()));
    ui->rb_debiter->setChecked(true);
}

BDDebiterUnCompteClient::~BDDebiterUnCompteClient()
{
    delete ui;
}

void BDDebiterUnCompteClient::changeEvent(QEvent *e)
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

void BDDebiterUnCompteClient::on_btn_identifier_clicked()
{
    BDIdentifierClientHotelSimple bd(this);
    bd.setWindowTitle("Identifier le client");

    if(bd.exec() == QDialog::Accepted)
    {
        m_client = bd.clientSelectionne();
        ui->lineEditClient->setText(m_client.nomComplet());
        chargerComptesExistants();
    }
}

void BDDebiterUnCompteClient::chargerComptesExistants()
{
    ui->treeWidgetComptesExistants->clear();

    QString condition = tr("%1 = %2").arg(compteClient().codeClientName()).arg(m_client.codeDuClient());

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(CompteClient::Libelle, condition);

    foreach(QSqlRecord r, records)
    {
        compteClient cc(r);
        QStringList data;
        data << QString::number(cc.idCompteClient());
        data << cc.libelle();
        data << QString::number(cc.solde());
        ui->treeWidgetComptesExistants->addTopLevelItem(new QTreeWidgetItem(data));
    }
}

void BDDebiterUnCompteClient::updateEtatGroupeDebiterCompte(QModelIndex index)
{
    if(index.isValid())
    {
        ui->groupBoxDebiterCompte->setEnabled(true);
    }else
    {
        ui->groupBoxDebiterCompte->setEnabled(false);
        initialiserGroupeDebiter();
    }
}

void BDDebiterUnCompteClient::chargerModeDePayement()
{
    ui->comboBoxModeDePaye->clear();

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ModeDePayement::Libelle);

    QStringList modes;
    foreach(QSqlRecord r, records)
    {
        modeDePayement mp(r);
        modes << mp.mode();
    }

    // supprimer compte client
    modes.removeLast();

    ui->comboBoxModeDePaye->addItems(modes);
}


void BDDebiterUnCompteClient::on_btn_fermer_clicked()
{
    close();
}

void BDDebiterUnCompteClient::on_btn_debiter_clicked()
{
    QString title;
    QString message;

    if(ui->rb_crediter->isChecked())
    {
        title = "Dépôt sur un compte client";
        message = tr("Vous êtes sur le point de verser une somme de %1 sur le compte %2.\n\nDésirez-vous continuer ?")
                  .arg(ui->spinBoxMontantVerse->value())
                  .arg(currentLibelle());
    }else
    {
        title = "Retrait sur un compte client";
        message = tr("Vous êtes sur le point de retirer une somme de %1 sur le compte %2.\n\nDésirez-vous continuer ?")
                  .arg(ui->spinBoxMontantVerse->value())
                  .arg(currentLibelle());
    }

    if(QMessageBox::information(this
                             , title
                             , message
                             , "Oui"
                             , "Non") == 0)
    {
        m_db->transaction();
        bool submitAll = true;

        QDateTime now = Horloge::currentDateTime();

        // faire un mouvement
        compteClient cc = compteClient(currentIdCompteClient());

        int idOperation = MesTables::faireUnMouvementCompteClient(    m_agent
                                                                      , now
                                                                      , cc.idCompteClient()
                                                                      , title
                                                                      , ui->spinBoxMontantVerse->value()
                                                                      , ui->rb_debiter->isChecked()
                                                                      , submitAll);

        // faire un récu
        submitAll = submitAll && MesTables::enregistrerUneOperationService(  m_agent
                                                                              , recuInitial::IdDepotSurCompteClient
                                                                              , now
                                                                              , ui->spinBoxMontantVerse->value()
                                                                              , title
                                                                              , ui->comboBoxModeDePaye->currentIndex() + 1
                                                                              , idOperation
                                                                              , operationCompteClient().tableName()
                                                                              , ui->rb_debiter->isChecked()); // pour retracer l'opération

        if(submitAll)
        {
            m_db->commit();
            chargerComptesExistants();
            updateEtatGroupeDebiterCompte(QModelIndex());
        }else
            m_db->rollback();

    }

}

void BDDebiterUnCompteClient::updateEtatBtnDebiter(int montant)
{
    ui->btn_debiter->setEnabled(montant != 0);
}

QString BDDebiterUnCompteClient::currentLibelle()
{
    int row = ui->treeWidgetComptesExistants->currentIndex().row();
    return ui->treeWidgetComptesExistants->topLevelItem(row)->text(LIBELLE);
}

int BDDebiterUnCompteClient::currentSolde()
{
    int row = ui->treeWidgetComptesExistants->currentIndex().row();
    return ui->treeWidgetComptesExistants->topLevelItem(row)->text(SOLDE).toInt();
}

int BDDebiterUnCompteClient::currentIdCompteClient()
{
    int row = ui->treeWidgetComptesExistants->currentIndex().row();
    return ui->treeWidgetComptesExistants->topLevelItem(row)->text(NUM).toInt();
}

void BDDebiterUnCompteClient::initialiserGroupeDebiter()
{
    ui->spinBoxMontantVerse->setValue(0);
    ui->comboBoxModeDePaye->setCurrentIndex(0);
}

void BDDebiterUnCompteClient::updateLibelleBtnDebiter()
{
    if(ui->rb_debiter->isChecked())
    {
        ui->btn_debiter->setText("Débiter");
    }else
    {
        ui->btn_debiter->setText("Créditer");
    }
}

void BDDebiterUnCompteClient::setLimitesMontantVerse()
{
    ui->spinBoxMontantVerse->setMinimum(0);

    if(ui->rb_crediter->isChecked())
    {
        ui->spinBoxMontantVerse->setMaximum(currentSolde());
    }else
    {
        ui->spinBoxMontantVerse->setMaximum(100000000);
    }

    ui->spinBoxMontantVerse->setValue(0);
}
