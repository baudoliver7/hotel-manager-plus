#include "DialogRechercherUnClient.h"
#include "ui_DialogRechercherUnClient.h"

DialogRechercherUnClient::DialogRechercherUnClient(agent *recepteur, QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogRechercherUnClient)
{
    ui->setupUi(this);

    m_recepteur = recepteur;
    numOccupationAModifier.clear();
    montantsAregler.clear();

    m_clientEnCours = new client();
    ui->btn_OK->setEnabled(false);
    ui->comboBoxAction->setEnabled(false);
    ui->btn_appliquer->setEnabled(false);

    initialiserTableau();

    ui->Masculin->setChecked(true);
    ui->rb_enEspeces->setChecked(true);
    rafraichirTableau();

    detailler(FERMERDETAILS);
    connect(ui->Masculin, SIGNAL(clicked()), this, SLOT(rafraichirTableau()));
    connect(ui->Feminin, SIGNAL(clicked()), this, SLOT(rafraichirTableau()));
    connect(ui->tableViewClients->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this
            , SLOT(chargerLocations(QModelIndex)));
    connect(ui->tableWidget->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this
            , SLOT(updateEtatLineEditMR(QModelIndex)));

    chargerLocations(QModelIndex());
}

DialogRechercherUnClient::~DialogRechercherUnClient()
{
    delete ui;
    delete m_clientEnCours;
}

void DialogRechercherUnClient::changeEvent(QEvent *e)
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

bool DialogRechercherUnClient::estUnHomme()
{
    return ui->Masculin->isChecked();
}

void DialogRechercherUnClient::afficherClients(QString debutNom, bool sexe)
{
//    QStringList fieldsNames = InfosSurBD::fieldsNames(m_clients);
//
//    QString requete;
//
//    requete = tr("%1 = %2")
//              .arg(fieldsNames.at(Client::Id::Homme))
//              .arg(QString::number(sexe));
//
//    if(!debutNom.isEmpty())
//    {
//        requete = tr("%1 AND %2 LIKE '%3%'")
//                             .arg(requete)
//                             .arg(fieldsNames.at(Client::Id::Nom))
//                             .arg(debutNom);
//    }
//
//    client cl; occupation oc; recevoirOccup rc;
//    if(ui->rb_clientsCrediteurs->isChecked())
//    {
//        requete = tr("%1 AND %2 IN (SELECT %3 FROM %4 WHERE %5 IN (SELECT %6 FROM %7 WHERE %8 = %9 AND %10 > %11))")
//                  .arg(requete)
//                  .arg(cl.codeDuClientName())
//                  .arg(rc.codeDeClientName())
//                  .arg(rc.tableName())
//                  .arg(rc.numOccupName())
//                  .arg(oc.numOccupName())
//                  .arg(Occupation::Libelle)
//                  .arg(oc.annuleeName())
//                  .arg(false)
//                  .arg(oc.coutName())
//                  .arg(oc.payeeName());
//    }
//
//    m_clients->setFilter(requete);
//    m_clients->select();
}

void DialogRechercherUnClient::on_btn_OK_clicked()
{
    accept();
}

void DialogRechercherUnClient::updateEtatDesWidgets(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_OK->setEnabled(true);
        ui->comboBoxAction->setEnabled(true);
    }else
    {
        ui->btn_OK->setEnabled(false);
        ui->comboBoxAction->setEnabled(false);
    }
}

void DialogRechercherUnClient::on_lineEditNom_textChanged(QString)
{
    rafraichirTableau();
}

void DialogRechercherUnClient::initialiserTableau()
{
    initialiserModel();
    ui->tableViewClients->setModel(m_clients);

    connect(ui->tableViewClients->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(updateEtatDesWidgets(QModelIndex)));

    ui->tableViewClients->setColumnHidden(Client::Id::CodeClient, true);
    ui->tableViewClients->setColumnHidden(Client::Id::Homme, true);
    ui->tableViewClients->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnHidden(7, true);
}

void DialogRechercherUnClient::initialiserModel()
{
    m_clients = new QSqlTableModel(this);
    m_clients->setTable(Client::Libelle);
    m_clients->setSort(Client::Id::CodeClient, Qt::AscendingOrder);

    m_clients->setHeaderData(Client::Id::Prenoms, Qt::Horizontal, tr("Prénom(s)"));
    m_clients->setHeaderData(Client::Id::Cel, Qt::Horizontal, tr("Cel"));
    m_clients->setHeaderData(Client::Id::Tel, Qt::Horizontal, tr("Tel"));
    m_clients->setHeaderData(Client::Id::Email, Qt::Horizontal, tr("E-mail"));
    m_clients->setHeaderData(Client::Id::BP, Qt::Horizontal, tr("Boîte postale"));
}

void DialogRechercherUnClient::on_btn_Annuler_clicked()
{
    reject();
}

QSqlRecord DialogRechercherUnClient::clientChoisi()
{
    return m_clients->record(ui->tableViewClients->currentIndex().row());
}

bool DialogRechercherUnClient::occuperUneChambre()
{
    // vrai pour occuper et faux pour réserver
    return (ui->comboBoxAction->currentIndex() == 0);
}

void DialogRechercherUnClient::rafraichirTableau()
{
    afficherClients(ui->lineEditNom->text(), estUnHomme());
}


void DialogRechercherUnClient::on_btn_details_clicked()
{
    detailler(ui->btn_details->text());
}

void DialogRechercherUnClient::detailler(QString textButton)
{
    if(textButton == QString(OUVRIRDETAILS))
    {
        ui->groupBoxDetails->setVisible(true);
        ui->btn_details->setText(FERMERDETAILS); // est maintenant détaillée

        chargerLocations(ui->tableViewClients->currentIndex()); // on peut donc charger
    }else
    {
        ui->groupBoxDetails->setVisible(false);
        chargerLocations(QModelIndex());
        ui->btn_details->setText(OUVRIRDETAILS);
    }
}

void DialogRechercherUnClient::chargerLocations(QModelIndex index)
{
//    if(estDetaillee())
//    {
//        ui->tableWidget->setRowCount(0);
//
//        if(index.isValid())
//        {
//            int row = ui->tableViewClients->currentIndex().row();
//            m_clientEnCours->setCode(m_clients->record(row).value(0).toInt());
//
//            QList<QSqlRecord> records;
//            records << m_clientEnCours->occupations_records();
//
//            foreach(QSqlRecord r, records)
//            {
//                if(!occupation(r).annulee())
//                {
//                    ajouterUneLocation(r);
//                }
//            }
//
//            if(m_clientEnCours->estEnRegle())
//            {
//                ui->tableWidget->setColumnHidden(5, true);
//                ui->tableWidget->setColumnHidden(6, true);
//            }else
//            {
//                ui->tableWidget->setColumnHidden(5, false);
//                ui->tableWidget->setColumnHidden(6, false);
//            }
//
//            int nbNR = m_clientEnCours->occupationsNonPayees_records().count();
//            ui->groupBoxDetails->setTitle(tr("Locations faites par le client sélectionné (%1 non réglée(s))").arg(nbNR));
//        }else
//        {
//            ui->groupBoxDetails->setTitle(tr("Locations faites par le client sélectionné (%1 non réglée(s))").arg(0));
//            ui->spinBoxMR->setEnabled(false);
//        }
//    }
}

void DialogRechercherUnClient::ajouterUneLocation(QSqlRecord occupation_record)
{
    occupation oc(occupation_record);
    recevoirOccup rc = recevoirOccup::selectionner(oc.numOccupation());
    libererOccup li = libererOccup::selectionner(oc.numOccupation());

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row + 1);

    ajouterUnElt(row, 0, oc.chambreOccupee());
    ajouterUnElt(row, 1, rc.date().toString(Qt::SystemLocaleLongDate));
    ajouterUnElt(row, 2, li.date().toString(Qt::SystemLocaleLongDate));
    ajouterUnElt(row, 3, MesTables::convertirAnMoisSemaineJour(oc.dureeOccupation()));
    ajouterUnElt(row, 4, QString::number(oc.cout()));
    ajouterUnElt(row, 5, QString::number(oc.payee()));
    ajouterUnElt(row, 6, QString::number(oc.reste()));
    ajouterUnElt(row, 7, QString::number(oc.numOccupation()));
}

void DialogRechercherUnClient::ajouterUnElt(int row, int col, QString valeur)
{
    QTableWidgetItem * item = new QTableWidgetItem(valeur);
    item->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(row, col, item);
}

bool DialogRechercherUnClient::estDetaillee()
{
    return (ui->btn_details->text() == FERMERDETAILS);
}

void DialogRechercherUnClient::updateEtatLineEditMR(QModelIndex index)
{
//    if(index.isValid())
//    {
//        if(!m_clientEnCours->estEnRegle())
//        {
//            occupation oc = currentLocation();
//            if(oc.estReglee())
//            {
//                ui->spinBoxMR->setDisabled(true);
//            }else
//            {
//                ui->spinBoxMR->setDisabled(false);
//                ui->spinBoxMR->setMinimum(0);
//                ui->spinBoxMR->setMaximum(oc.reste());
//
//                int numOccup = ui->tableWidget->item(index.row(), 7)->text().toInt();
//                if(numOccupationAModifier.contains(numOccup))
//                {
//                    int i = numOccupationAModifier.indexOf(numOccup);
//                    ui->spinBoxMR->setValue(montantsAregler.at(i));
//                }else
//                {
//                    ui->spinBoxMR->setValue(0);
//                }
//            }
//        }else
//        {
//            ui->spinBoxMR->setEnabled(false);
//        }
//    }else
//    {
//        ui->spinBoxMR->setEnabled(false);
//    }
}

void DialogRechercherUnClient::on_btn_appliquer_clicked()
{
    configServiceCompta * csc_client = new configServiceCompta(configServiceCompta::ClientRecept);
    configServiceCompta * csc_depot;

    if(ui->rb_compteBancaire->isChecked())
        csc_depot = new configServiceCompta(configServiceCompta::Banque);
    else
        csc_depot = new configServiceCompta(configServiceCompta::CaisseRecept);

    if((csc_client->compteAssocie() == 0)||(csc_depot->compteAssocie() == 0))
    {
        QMessageBox::information(this
                                 , "Echec d'enregistrement"
                                 , "Les comptes concernés par l'opération ne sont pas disponibles.\n\n Contactez le service comptable pour la configuration de ces comptes.");
        return;
    }

    ui->btn_appliquer->setEnabled(false);

    QString message("Vous êtes sur le point d'enregistrer un règlement partiel de location de :");
    for(int i = 0; i < numOccupationAModifier.count(); i++)
    {
        occupation oc(numOccupationAModifier.at(i));
        client cl(recevoirOccup::selectionner(oc.numOccupation()).codeClient());
        QString nomComplet = QString(cl.nom() + " " + cl.prenoms());
        message.append(tr("\n\n - la chambre %1 par le client %2 - Montant de règlement = %3;")
                       .arg(oc.chambreOccupee())
                       .arg(nomComplet)
                       .arg(montantsAregler.at(i)));
    }

    if(QMessageBox::question(this, "Enregistrer un règlement partiel", message
                          , "Oui", "Non") == 0)
    {
        QDateTime now = Horloge::currentDateTime();
        for(int i = 0; i < numOccupationAModifier.count(); i++)
        {
            occupation oc(numOccupationAModifier.at(i));
            oc.setPayee(oc.payee() + montantsAregler.at(i));
            oc.enregistrer();

            // opération entre compte location et compte caisse
            QList<int> numCpts, montants;
            QList<bool> debiteurs;

            numCpts << csc_client->compteAssocie() << csc_depot->compteAssocie();
            debiteurs << false << true;
            montants << montantsAregler.at(i) << montantsAregler.at(i);

            QString description = tr("Règlement partiel de location (%1)").arg(oc.chambreOccupee());

            // effectuer l'enregistrement de l'opération comptable
            if(!MesTables::enregistrerUneOperationComptable(  now.date()
                                                            , numCpts
                                                            , description
                                                            , debiteurs
                                                            , montants
                                                            , m_recepteur->matricule()
                                                            , false))
            {
                QMessageBox::warning(this, "Erreur d'enregistrement", "Toute l'opération n'a pas pu être effectuée!");
                return;
            }
        }

        numOccupationAModifier.clear();
        montantsAregler.clear();

        chargerLocations(ui->tableViewClients->currentIndex());
    }

    delete csc_client;
    delete csc_depot;
}

void DialogRechercherUnClient::on_spinBoxMR_valueChanged(int value)
{
    int row = ui->tableWidget->currentIndex().row();
    int numOccup = ui->tableWidget->item(row, 7)->text().toInt();
    int position = numOccupationAModifier.indexOf(numOccup);

    if(value == 0)
    {
        // supprimer les infos sur la location précédemment modifiée si elles existent
        if(numOccupationAModifier.contains(numOccup))
        {
            numOccupationAModifier.removeAt(position);
            montantsAregler.removeAt(position);
        }

        if(numOccupationAModifier.isEmpty())
            ui->btn_appliquer->setEnabled(false);
    }else
    {
        if(numOccupationAModifier.contains(numOccup))
        {
            montantsAregler.replace(position, value);
        }else
        {
            numOccupationAModifier << numOccup;
            montantsAregler << value;
        }

        ui->btn_appliquer->setEnabled(true);
    }
}

occupation DialogRechercherUnClient::currentLocation()
{
    int row = ui->tableWidget->currentIndex().row();
    return occupation(ui->tableWidget->item(row, 7)->text().toInt());
}

void DialogRechercherUnClient::on_rb_clientsCrediteurs_clicked()
{
    afficherClients(ui->lineEditNom->text(), ui->Masculin->isChecked());
}
