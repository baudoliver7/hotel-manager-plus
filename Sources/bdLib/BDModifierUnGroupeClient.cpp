#include "BDModifierUnGroupeClient.h"
#include "ui_BDModifierUnGroupeClient.h"

BDModifierUnGroupeClient::BDModifierUnGroupeClient(bool choisirUnClient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDModifierUnGroupeClient)
{
    ui->setupUi(this);

    m_choisirUnClient = choisirUnClient;
    m_idGroupe = 0;

    if(m_choisirUnClient)
    {
        ui->btn_fermer->setText("Annuler");
        ui->btn_choisir->setVisible(true);
    }
    else
    {
        ui->btn_choisir->setVisible(false);
        ui->btn_fermer->setText("Fermer");
    }

    ui->btn_retirer->setEnabled(false);
    ui->btn_choisir->setEnabled(false);
    ui->btn_terminer->setEnabled(false);
    ui->btn_ajouter->setEnabled(false);
    ui->treeWidgetMembres->setColumnHidden(0, true);
    ui->treeWidgetGroupesEnCours->setColumnHidden(0, true);
    ui->groupBoxMembres->setTitle(tr("Membres du groupe (%1)").arg(0));
    chargerGroupesEnCours();

    connect(ui->treeWidgetGroupesEnCours->selectionModel()
            , SIGNAL(selectionChanged(QItemSelection,QItemSelection))
            , this
            , SLOT(chargerMembres()));

    connect(ui->treeWidgetGroupesEnCours->selectionModel()
            , SIGNAL(selectionChanged(QItemSelection,QItemSelection))
            , this
            , SLOT(updateEtatBtnTerminer()));

    connect(ui->treeWidgetGroupesEnCours->selectionModel()
            , SIGNAL(selectionChanged(QItemSelection,QItemSelection))
            , this
            , SLOT(updateEtatBtnAjouter()));

    connect(ui->treeWidgetMembres->selectionModel()
            , SIGNAL(selectionChanged(QItemSelection,QItemSelection))
            , this
            , SLOT(updateEtatBtnRetirer()));

    connect(ui->treeWidgetMembres->selectionModel()
            , SIGNAL(selectionChanged(QItemSelection,QItemSelection))
            , this
            , SLOT(updateEtatBtnChoisir()));
}

BDModifierUnGroupeClient::~BDModifierUnGroupeClient()
{
    delete ui;
}

void BDModifierUnGroupeClient::changeEvent(QEvent *e)
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

void BDModifierUnGroupeClient::chargerGroupesEnCours()
{
    ui->treeWidgetGroupesEnCours->clear();
    m_groupesSelectionnes.clear();
    QString condition = tr("%1 = %2").arg(groupe().termineeName()).arg(false);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Groupe::Libelle, condition);

    foreach(QSqlRecord r, records)
    {
        groupe gr(r);
        client cl(gr.idResponsable());
        QStringList data;
        data << QString::number(gr.idGroupe())
             << gr.libelle()
             << cl.nomComplet()
             << tr("%1 (%2 prévues)").arg(QString::number(gr.nbPersEnregistrees())).arg(gr.nbPersPrevues());

        m_groupesSelectionnes << gr;
        ui->treeWidgetGroupesEnCours->addTopLevelItem(new QTreeWidgetItem(data));
    }
}

void BDModifierUnGroupeClient::chargerMembres()
{
    ui->treeWidgetMembres->clear();
    m_clientsSelectionnes.clear();

    if(ui->treeWidgetGroupesEnCours->selectedItems().isEmpty())
    {
        // titre du groupe
        ui->groupBoxMembres->setTitle(tr("Membres du groupe (%1)").arg(0));
        return;
    }

    groupeLiaison grl;
    QString condition = tr("%1 = %2")
                        .arg(grl.idGroupeName())
                        .arg(currentIdGroupe());

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(GroupeLiaison::Libelle, condition);

    foreach(QSqlRecord r, records)
    {
        groupeLiaison grl(r);
        client cl(grl.codeClient());

        occupation oc;
        QString condition1 = tr("%1 = %2 AND %3 = %4")
                             .arg(oc.codeClientName())
                             .arg(cl.codeDuClient())
                             .arg(oc.idGroupeName())
                             .arg(grl.idGroupe());

        QList<QSqlRecord> records1;
        records1 << InfosSurBD::enregistrements(Occupation::Libelle, condition1);

        QString estLoge = "Non";
        if(!records1.isEmpty())
        {
            occupation oc1(records1.first());

            if(oc1.terminee())
                estLoge = "Logé et terminé";
            else
                estLoge = "Oui";
        }

        QStringList data;
        data << QString::number(cl.codeDuClient())
             << cl.nomComplet()
             << estLoge;

        m_clientsSelectionnes << cl;
        ui->treeWidgetMembres->addTopLevelItem(new QTreeWidgetItem(data));
    }

    // titre du groupe
    groupe gr(currentIdGroupe());
    ui->groupBoxMembres->setTitle(tr("Membres du groupe de %1 (%2)")
                                  .arg(gr.libelle())
                                  .arg(m_clientsSelectionnes.count()));
}

int BDModifierUnGroupeClient::currentIdGroupe()
{
    int row = ui->treeWidgetGroupesEnCours->currentIndex().row();
    int idGroupe = ui->treeWidgetGroupesEnCours->topLevelItem(row)->text(0).toInt();
    return idGroupe;
}

int BDModifierUnGroupeClient::currentIdClient()
{
    int row = ui->treeWidgetMembres->currentIndex().row();
    int idClient = ui->treeWidgetMembres->topLevelItem(row)->text(0).toInt();
    return idClient;
}

void BDModifierUnGroupeClient::updateEtatBtnRetirer()
{
    QModelIndex index = ui->treeWidgetMembres->currentIndex();

    if(index.isValid() && !ui->treeWidgetGroupesEnCours->selectedItems().isEmpty())
    {
        int row = index.row();
        int currentRowGroup = ui->treeWidgetGroupesEnCours->currentIndex().row();
        if(m_clientsSelectionnes.at(row).codeDuClient() == m_groupesSelectionnes.at(currentRowGroup).idResponsable())
        {
            // on ne supprime pas le responsable
            ui->btn_retirer->setEnabled(false);
        }else
        {
            // voir s'il n'est pas logé
            bool estLoge = ui->treeWidgetMembres->topLevelItem(row)->text(2) == "Oui";
            ui->btn_retirer->setEnabled(!estLoge);
        }
    }else
    {
        ui->btn_retirer->setEnabled(false);
    }
}

void BDModifierUnGroupeClient::updateEtatBtnChoisir()
{
    QModelIndex index = ui->treeWidgetMembres->currentIndex();

    if(index.isValid())
    {
        ui->btn_choisir->setEnabled(true);
    }else
    {
        ui->btn_choisir->setEnabled(false);
    }
}

void BDModifierUnGroupeClient::updateEtatBtnTerminer()
{
    QModelIndex index = ui->treeWidgetGroupesEnCours->currentIndex();

    ui->btn_terminer->setEnabled(index.isValid());
}

void BDModifierUnGroupeClient::updateEtatBtnAjouter()
{
    QModelIndex index = ui->treeWidgetGroupesEnCours->currentIndex();

    ui->btn_ajouter->setEnabled(index.isValid());
}

void BDModifierUnGroupeClient::on_btn_retirer_clicked()
{
    int row = ui->treeWidgetGroupesEnCours->currentIndex().row();
    QString libelleGroup = ui->treeWidgetGroupesEnCours->topLevelItem(row)->text(LIBELLE);

    int row1 = ui->treeWidgetMembres->currentIndex().row();
    QString nomClient = ui->treeWidgetMembres->topLevelItem(row1)->text(1);

    if(QMessageBox::information(this
                                , "Retirer un client d'un groupe"
                                , tr("Vous êtes sur le point de retirer le client %1 du groupe %2. \n\nDésirez-vous continuer ?")
                                  .arg(nomClient)
                                  .arg(libelleGroup)
                                , "Oui"
                                , "Non") == 0)
    {
        groupeLiaison grl(currentIdClient(), currentIdGroupe());
        grl.supprimer();

        actualiserCurrentGroupe();
    }

}

void BDModifierUnGroupeClient::on_btn_ajouter_clicked()
{
    int row = ui->treeWidgetGroupesEnCours->currentIndex().row();
    QString libelleGroup = ui->treeWidgetGroupesEnCours->topLevelItem(row)->text(LIBELLE);

    BDIdentifierClientHotelSimple bd(this);
    bd.setWindowTitle(tr("Ajouter un client au groupe %1").arg(libelleGroup));

    if(bd.exec() == QDialog::Accepted)
    {
        // vérifier que le client sélectionné n'est pas déjà dans la liste
        if(!m_clientsSelectionnes.contains(bd.clientSelectionne()))
        {
            // ajouter
            groupeLiaison grl;
            grl.setCodeClient(bd.clientSelectionne().codeDuClient());
            grl.setIdGroupe(currentIdGroupe());
            grl.enregistrer();

            actualiserCurrentGroupe();
        }else
        {
            QMessageBox::information(this
                                     , "Ajouter un client"
                                     , "Le client sélectionné existe déjà dans la liste du groupe!");
        }
    }
}

void BDModifierUnGroupeClient::on_btn_fermer_clicked()
{
    if(m_choisirUnClient)
        reject();
    else
        close();
}

void BDModifierUnGroupeClient::on_btn_choisir_clicked()
{
    m_clientChoisi = client(currentIdClient());
    m_idGroupe = currentIdGroupe();
    accept();
}

void BDModifierUnGroupeClient::on_btn_terminer_clicked()
{
    groupe gr(currentIdGroupe());

    if(QMessageBox::information(this
                             , "Terminer un groupe"
                             , tr("Désirez-vous terminer le groupe %1 ?").arg(gr.libelle())
                             , "Oui", "Non") == 0)
    {
        bool peutTerminer = true;

        QList<QSqlRecord> records;
        records = gr.occupations_des_membres_records();

        int i = 0;
        while(peutTerminer && (i < records.count()))
        {
            occupation oc(records.at(i));
            if(!oc.terminee())
                peutTerminer = false;
            i++;
        }

        if(peutTerminer)
        {
            reservation rv;
            QString condition = tr("%1 = %2")
                                .arg(rv.idGroupeName())
                                .arg(currentIdGroupe());
            QList<QSqlRecord> records1;
            records1 = InfosSurBD::enregistrements(rv.tableName(), condition);

            i = 0;
            while(peutTerminer && (i < records1.count()))
            {
                reservation rv1(records1.at(i));

                QList<QSqlRecord> records2;
                records2 = chambreReservee::chambre_reservee_records(rv1.numReservation());

                int j = 0;
                while(peutTerminer && (j < records2.count()))
                {
                    chambreReservee chr(records2.at(j));
                    if(!chr.terminee())
                        peutTerminer = false;
                    j++;
                }

                i++;
            }
        }

        if(!peutTerminer)
        {
            QMessageBox::information(this
                                     , "Terminer un groupe"
                                     , "Ce groupe ne peut être terminé car il existe des locations ou des réservations en cours!\n\n Arrêtez-les puis réessayez.");
            return;
        }

        gr.setTerminee(true);
        gr.enregistrer();

        chargerGroupesEnCours();
    }
}

void BDModifierUnGroupeClient::actualiserCurrentGroupe()
{
    // actualiser nb membres
    groupe gr(currentIdGroupe());
    gr.actualiser();
    m_groupesSelectionnes.replace(m_groupesSelectionnes.indexOf(gr), gr);

    int row = ui->treeWidgetGroupesEnCours->currentIndex().row();

    QTreeWidgetItem * topLevelItem = ui->treeWidgetGroupesEnCours->takeTopLevelItem(row);
    topLevelItem->setText(NBPERSONNE, QString::number(gr.nbPersEnregistrees()));
    ui->treeWidgetGroupesEnCours->insertTopLevelItem(row, topLevelItem);

    ui->treeWidgetGroupesEnCours->setCurrentItem(topLevelItem); // affiche aussi les membres
}
