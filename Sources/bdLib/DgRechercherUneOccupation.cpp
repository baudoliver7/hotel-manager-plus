#include "DgRechercherUneOccupation.h"
#include "ui_DgRechercherUneOccupation.h"

DgRechercherUneOccupation::DgRechercherUneOccupation(agent *ag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DgRechercherUneOccupation)
{

    ui->setupUi(this);
    ui->btn_liberer->setEnabled(false);
    ui->btn_supprimer->setEnabled(false);
    ui->btn_imprimerRecu->setEnabled(false);

    ui->btn_enregistrer->setEnabled(false);
    ui->btn_enregistrerResto->setEnabled(false);
    ui->btn_enregistrerFraisSup->setEnabled(false);

    m_nbOccupArretee = 0;
    m_recepteur = ag;
    initialiserTypeDeChambre();
    initialiserTable();

    ui->lineEditDebut->setText(Horloge::currentDate().addDays(-1).toString(Qt::SystemLocaleLongDate));
    ui->lineEditFin->setText(ui->lineEditDebut->text());

    connect(ui->lineEditDebut, SIGNAL(textChanged(QString)), this, SLOT(rafraichirTable()));
    connect(ui->lineEditFin, SIGNAL(textChanged(QString)), this, SLOT(rafraichirTable()));
    connect(ui->rb_locationEnCours, SIGNAL(toggled(bool)), this, SLOT(rafraichirTable()));
    connect(ui->rb_periode, SIGNAL(toggled(bool)), this, SLOT(rafraichirTable()));

    connect(ui->rb_periode, SIGNAL(toggled(bool)), this, SLOT(updatePeriode()));
    connect(ui->rb_locationEnCours, SIGNAL(toggled(bool)), this, SLOT(updatePeriode()));

    connect(ui->spinBoxMontantRegl, SIGNAL(valueChanged(int)), this, SLOT(updateEtatBtnEnregistrer()));
    connect(ui->spinBoxRestaurationMR, SIGNAL(valueChanged(int)), this, SLOT(updateEtatBtnEnregistrerResto()));
    connect(ui->spinBoxFraisSupMR, SIGNAL(valueChanged(int)), this, SLOT(updateEtatBtnEnregistrerFraisSup()));


    ui->rb_locationEnCours->setChecked(true); // il ne l'était pas

    ui->rb_payementLoc->setChecked(true);
    ui->rb_payementFraisSup->setChecked(true);
    ui->rb_payementResto->setChecked(true);

    afficherFraisSupplementaire(QModelIndex());
    afficherMontantReglementLoc(QModelIndex());
    afficherMontantReglementFraisSup(QModelIndex());
    afficherMontantReglementResto(QModelIndex());
}

DgRechercherUneOccupation::~DgRechercherUneOccupation()
{
    delete ui;
}

void DgRechercherUneOccupation::changeEvent(QEvent *e)
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

void DgRechercherUneOccupation::on_btn_liberer_clicked()
{
    liberer();
}

void DgRechercherUneOccupation::on_btn_annuler_clicked()
{
    close();
}

void DgRechercherUneOccupation::initialiserTypeDeChambre()
{
    m_typesDeChambreDispo << typeDeChambre::typeDeChambreDisponibles(true);
    m_typesDeChambreStrDispo << typeDeChambre::typesDisponibles(true);

    ui->typesDeChambre->addItems(m_typesDeChambreStrDispo);

    connect(ui->typesDeChambre, SIGNAL(currentIndexChanged(int)), this, SLOT(rafraichirTable()));
}

void DgRechercherUneOccupation::rafraichirTable()
{
    ui->tableWidget->setRowCount(0);

    if(m_typesDeChambreDispo.isEmpty())
    {
        return;
    }

    int index = ui->typesDeChambre->currentIndex();
    int idTypeDeChambre = m_typesDeChambreDispo.at(index).idTypeDeChambre();
    QList<QSqlRecord> occupations;
    if(ui->rb_locationEnCours->isChecked())
    {
        occupations << occupation::occupationsEnCours(idTypeDeChambre);
    }else
    {
        QList<QSqlRecord> occupations1;
        occupations1 << occupation::occupation_records(QDate::fromString(ui->lineEditDebut->text(), Qt::SystemLocaleLongDate)
                                                      , QDate::fromString(ui->lineEditFin->text(), Qt::SystemLocaleLongDate));

        foreach(QSqlRecord r, occupations1)
        {
            occupation oc(r);
            chambre ch(oc.chambreOccupee());

            if(ch.idTypeChambre() == idTypeDeChambre)
            {
                occupations << r;
            }
        }
    }

    for(int i = 0; i < occupations.count(); i++)
    {
        occupation oc(occupations.at(i));
        recevoirOccup ro(oc.numOccupation());

        ui->tableWidget->setRowCount(i+1);
        afficherElement(i, NUMERO_RESERV, QString::number(oc.numOccupation()));
        afficherElement(i, CHAMBRE, oc.chambreOccupee());
        afficherElement(i, DATE_ENTREE, oc.datedEntree().toString(Qt::SystemLocaleLongDate));
        afficherElement(i, DUREE_EN_JOURS, QString::number(oc.dureeOccupation()));
        afficherElement(i, DATE_SORTIE, oc.datedSortie().toString(Qt::SystemLocaleLongDate));
        afficherElement(i, PRIXTOTAL, QString::number(oc.cout()));
        afficherElement(i, MONTANTVERSE, QString::number(oc.payee()));
        afficherElement(i, MONTANTRESTANT, QString::number(oc.reste()));

        client cl(ro.codeClient());
        QString nomComplet = tr("%1 %2").arg(cl.nom()).arg(cl.prenoms());
        afficherElement(i, OCCUPANT, nomComplet);
    }
}

void DgRechercherUneOccupation::afficherElement(int row, int column, const QString &value)
{
    QTableWidgetItem * item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(row, column, item);
}

void DgRechercherUneOccupation::initialiserTable()
{
    connect(ui->tableWidget->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(updateEtatBtnLiberer(QModelIndex)));

    connect(ui->tableWidget->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(afficherMontantReglementLoc(QModelIndex)));

    connect(ui->tableWidget->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(afficherFraisSupplementaire(QModelIndex)));

    connect(ui->tableWidget->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(afficherMontantReglementResto(QModelIndex)));

    connect(ui->tableWidget->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(afficherMontantReglementFraisSup(QModelIndex)));

    ui->tableWidget->setColumnHidden(NUMERO_RESERV, true);
    ui->tableWidget->sortItems(CHAMBRE, Qt::AscendingOrder);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DgRechercherUneOccupation::updateEtatBtnLiberer(QModelIndex index)
{
    if(index.isValid())
    {
        if(occupation(currentNumOp()).estEnCours())
        {
            ui->btn_liberer->setEnabled(true);
        }else
        {
            ui->btn_liberer->setEnabled(false);
        }

        ui->btn_imprimerRecu->setEnabled(true);

        // on active le bouton "supprimer" à condition qu'on soit dans les 15 minutes de tolérance

        int currentRow = ui->tableWidget->currentRow();
        QString dateStr = ui->tableWidget->item(currentRow, DATE_ENTREE)->text();

        QDateTime datedEntree = QDateTime::fromString(dateStr, Qt::SystemLocaleLongDate);
        QDateTime now = Horloge::currentDateTime();

        HeureLimite hl(1);
        if((datedEntree.date() == now.date())) // le même jour
        {
            if(datedEntree.time().secsTo(now.time()) <= hl.tempsLocAnnulation() * 60) // X minutes
            {
                ui->btn_supprimer->setEnabled(true);
            }else
            {
                ui->btn_supprimer->setEnabled(false);
            }
        }else
        {
            // un jour différent
            if((datedEntree.daysTo(now) <= 1) && (datedEntree.time().secsTo(now.time()) <= hl.tempsLocAnnulation() * 60))
            {
                ui->btn_supprimer->setEnabled(true);
            }else
            {
                ui->btn_supprimer->setEnabled(false);
            }
        }

        // fin activation du bouton "supprimer"
    }else
    {
        ui->btn_liberer->setEnabled(false);
        ui->btn_supprimer->setEnabled(false);
        ui->btn_imprimerRecu->setEnabled(false);
    }
}

void DgRechercherUneOccupation::liberer()
{
    // faire une opération comptable
    configServiceCompta csc_client(configServiceCompta::ClientRecept);
    configServiceCompta csc_penaliteRetard(configServiceCompta::PenaliteRetardRecept);

    if((csc_penaliteRetard.compteAssocie() == 0)||(csc_client.compteAssocie() == 0))
    {
        QMessageBox::information(this
                                 , "Echec d'enregistrement"
                                 , "Les comptes concernés par l'opération ne sont pas disponibles.\n\n Contactez le service comptable pour la configuration de ces comptes.");
        return;
    }

    int currentRow = ui->tableWidget->currentRow();
    int numOccupation = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

    occupation oc(numOccupation);
    chambre ch(oc.chambreOccupee());

    if(QMessageBox::question(this, tr("Libérer la chambre %1").arg(oc.chambreOccupee()),
                             "Désirez-vous mettre fin à la location en cours?", "Oui", "Non")==0)
    {
        QDateTime now = Horloge::currentDateTime();
        if(MesTables::arreterOccupation(ch, *m_recepteur, now))
        {
            if(ui->spinBoxMontantSup->value() != 0)
            {
                // on enregistre les frais supplémentaires seulement
                oc.setFraisSupplementaire(ui->spinBoxMontantSup->value());
                oc.enregistrer();

                if(ui->rb_payementFraisSup->isChecked())
                {
                    if(!oc.fraisSupSontRegles())
                    {
                        QList<int> numCpts, montants;
                        QList<bool> debiteurs;

                        // transférer l'avance du compte avance au compte client
                        numCpts << csc_penaliteRetard.compteAssocie() << csc_client.compteAssocie();
                        debiteurs << false << true;
                        montants << oc.resteFraisSup() << oc.resteFraisSup();

                        QString description = tr("Règlement de pénalité de retard de sortie (%1)").arg(oc.chambreOccupee());

                        // effectuer l'enregistrement de l'opération comptable
                        if(!MesTables::enregistrerUneOperationComptable( now.date()
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
                }
            }
        }

        ui->tableWidget->removeRow(currentRow);
        m_nbOccupArretee++;
        emit bdModifie();
    }
}

void DgRechercherUneOccupation::on_btn_supprimer_clicked()
{
    configServiceCompta csc_location(configServiceCompta::LocationRecept);
    configServiceCompta csc_caisse(configServiceCompta::AvanceRecept);
    configServiceCompta csc_tvaCollectee(configServiceCompta::TVACollecteeCompta);
    configServiceCompta csc_client(configServiceCompta::ClientRecept);

    if((csc_location.compteAssocie() == 0)||(csc_caisse.compteAssocie() == 0)
        ||(csc_tvaCollectee.compteAssocie() == 0)||(csc_client.compteAssocie() == 0))
    {
        QMessageBox::information(this
                                 , "Echec d'enregistrement"
                                 , "Les comptes concernés par l'opération ne sont pas disponibles.\n\n Contactez le service comptable pour la configuration de ces comptes.");
        return;
    }

    int currentRow = ui->tableWidget->currentRow();
    int numOccupation = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

    occupation oc(numOccupation);
    chambre ch(oc.chambreOccupee());

    if(QMessageBox::question(this, tr("Annuler une location"),
                             tr("Désirez-vous annuler la location de la chambre %1?").arg(oc.chambreOccupee()), "Oui", "Non")==0)
    {
        QDateTime dateTime = Horloge::currentDateTime();
        if(MesTables::annulerOccupation(ch, *m_recepteur, dateTime))
        {
//            if(oc.payee() != 0)
//            {
//                BDRestituerAuClient bd(oc.payee(), false, this);
//                bd.setWindowTitle("Somme à restituer au client");
//
//                bd.exec();
//                if(bd.sommeARestituer() != 0)
//                {
//                    // faire une opération comptable
//                    QList<int> numCpts, montants;
//                    QList<bool> debiteurs;
//
//                    // opération entre compte location et compte caisse
//                    numCpts << csc_location.compteAssocie() << csc_caisse.compteAssocie();
//                    debiteurs << true << false;
//                    montants << oc.payee() - bd.sommeARestituer() << oc.payee() - bd.sommeARestituer();
//
//                    QString description = tr("Annulation de location (%1)").arg(oc.chambreOccupee());
//
//                    // effectuer l'enregistrement de l'opération comptable
//                    if(!MesTables::enregistrerUneOperationComptable(Horloge::currentDate()
//                                                                    ,numCpts
//                                                                    , description
//                                                                    , debiteurs
//                                                                    , montants
//                                                                    , m_recepteur->matricule()
//                                                                    , false))
//                    {
//                        QMessageBox::warning(this, "Erreur d'enregistrement", "Toute l'opération n'a pas pu être effectuée!");
//                        return;
//                    }
//                }
//            }

            // faire l'opération comptable inverse
            QList<int> numCpts, montants;
            QList<bool> debiteurs;

            // opération entre compte location et compte caisse
            numCpts << csc_location.compteAssocie() << csc_tvaCollectee.compteAssocie();
            debiteurs << true << true ;
            int coutLocation = oc.cout() * (1 - taux(taux::TVA).valeur());
            montants << coutLocation << oc.payee();

            if(oc.payee() != 0)
            {
                numCpts << csc_caisse.compteAssocie();
                debiteurs << false;
                montants  << oc.payee();
            }

            if(!oc.estReglee())
            {
                numCpts << csc_client.compteAssocie();
                debiteurs << false;
                montants  << oc.reste();
            }

            QString description = tr("Annulation de location (%1)").arg(oc.chambreOccupee());

            // effectuer l'enregistrement de l'opération comptable
            if(!MesTables::enregistrerUneOperationComptable( Horloge::currentDate()
                                                            ,numCpts
                                                            , description
                                                            , debiteurs
                                                            , montants
                                                            , m_recepteur->matricule()
                                                            , false))
            {
                QMessageBox::warning(this, "Erreur d'enregistrement", "Toute l'opération n'a pas pu être effectuée!");
                return;
            }

            // mettre à jour le tableau
            ui->tableWidget->removeRow(currentRow);

            // on avertit de la modification au compagnon fidèle
            emit bdModifie();
        }else
        {
            QMessageBox::information(this, "Echec d'annulation", tr("L'annulation de la location de la chambre %1 a échoué!").arg(ch.identifiant()));
        }
    }
}

void DgRechercherUneOccupation::on_btn_debut_clicked()
{
    DialogCalendar bd(this);
    bd.setWindowTitle("Date de début");

    if(bd.exec() == QDialog::Accepted)
    {
        QDate fin = QDate::fromString(ui->lineEditFin->text(), Qt::SystemLocaleLongDate);

        if(bd.dateSeclectionnee() <= fin)
        {
            ui->lineEditDebut->setText(bd.dateSeclectionnee().toString(Qt::SystemLocaleLongDate));
        }
    }
}

void DgRechercherUneOccupation::on_btn_fin_clicked()
{
    DialogCalendar bd(this);
    bd.setWindowTitle("Date de fin");

    if(bd.exec() == QDialog::Accepted)
    {
        QDate debut = QDate::fromString(ui->lineEditDebut->text(), Qt::SystemLocaleLongDate);

        if(bd.dateSeclectionnee() >= debut)
        {
            ui->lineEditFin->setText(bd.dateSeclectionnee().toString(Qt::SystemLocaleLongDate));
        }
    }
}

void DgRechercherUneOccupation::updatePeriode()
{
    bool enabled = ui->rb_periode->isChecked();
    ui->btn_debut->setEnabled(enabled);
    ui->btn_fin->setEnabled(enabled);
    ui->lineEditDebut->setEnabled(enabled);
    ui->lineEditFin->setEnabled(enabled);
}

void DgRechercherUneOccupation::updateEtatBtnEnregistrer()
{
    ui->btn_enregistrer->setEnabled(ui->spinBoxMontantRegl->value() != 0);
}

void DgRechercherUneOccupation::updateEtatBtnEnregistrerResto()
{
    ui->btn_enregistrerResto->setEnabled(ui->spinBoxRestaurationMR->value() != 0);
}

void DgRechercherUneOccupation::updateEtatBtnEnregistrerFraisSup()
{
    ui->btn_enregistrerFraisSup->setEnabled(ui->spinBoxFraisSupMR->value() != 0);
}

void DgRechercherUneOccupation::afficherMontantReglementLoc(QModelIndex index)
{
    if(index.isValid())
    {
        int currentRow = ui->tableWidget->currentRow();
        int numOccup = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

        occupation oc(numOccup);
        ui->lineEditMontantTotal->setText(QString::number(oc.cout()));
        ui->lineEditMontantRestant->setText(QString::number(oc.reste()));

        ui->spinBoxMontantRegl->setValue(0);
        ui->spinBoxMontantRegl->setMaximum(oc.reste());
        ui->spinBoxMontantRegl->setMinimum(0);

        ui->groupBoxMR->setEnabled(true);
    }else
    {
        ui->groupBoxMR->setEnabled(false);
    }

}

void DgRechercherUneOccupation::afficherMontantReglementFraisSup(QModelIndex index)
{
    if(index.isValid())
    {
        int currentRow = ui->tableWidget->currentRow();
        int numOccup = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

        occupation oc(numOccup);
        ui->lineEditFraisSupRegl->setText(QString::number(oc.fraisSupplementaire()));
        ui->lineEditMontantRestantFraisSupMR->setText(QString::number(oc.resteFraisSup()));

        ui->spinBoxFraisSupMR->setValue(0);
        ui->spinBoxFraisSupMR->setMaximum(oc.resteFraisSup());
        ui->spinBoxFraisSupMR->setMinimum(0);

        if(ui->spinBoxMontantSup->isEnabled())
        {
            afficherFraisSupplementaire(index);
        }

        ui->groupBoxFraisSup->setEnabled(true);
    }else
    {
        ui->groupBoxFraisSup->setEnabled(false);
    }
}

void DgRechercherUneOccupation::afficherMontantReglementResto(QModelIndex index)
{
    if(index.isValid())
    {
        int currentRow = ui->tableWidget->currentRow();
        int numOccup = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

        occupation oc(numOccup);
        int total_resto = 0; //restoHotel::coutTotal(oc.codeClient(), oc.datedEntree().date(), oc.datedSortie().date());
        int som_payee = 0; //restoHotel::sommePayee(oc.codeClient(), oc.datedEntree().date(), oc.datedSortie().date());
        int reste = total_resto - som_payee;
        ui->lineEditRestaurationRegl->setText(QString::number(total_resto));
        ui->lineEditMontantRestantRestoMR->setText(QString::number(reste));

        ui->spinBoxRestaurationMR->setValue(0);
        ui->spinBoxRestaurationMR->setMaximum(reste);
        ui->spinBoxRestaurationMR->setMinimum(0);

        ui->groupBoxRestaurationRegl->setEnabled(true);
    }else
    {
        ui->groupBoxRestaurationRegl->setEnabled(false);
    }
}

void DgRechercherUneOccupation::afficherFraisSupplementaire(QModelIndex index)
{
    // frais sup ici = resto + frais sup loc
    if(index.isValid())
    {
        int currentRow = ui->tableWidget->currentRow();
        int numOccup = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

        occupation oc(numOccup);
        int total_resto = 0;//restoHotel::coutTotal(oc.codeClient(), oc.datedEntree().date(), oc.datedSortie().date());

        ui->lineEditRestauration->setText(QString::number(total_resto));
        ui->spinBoxMontantSup->setEnabled(oc.estEnCours());

        if(oc.estEnCours())
            ui->spinBoxMontantSup->setMinimum(oc.fraisSupplementaire());

        ui->groupBoxFS->setEnabled(true);
    }else
    {
        ui->groupBoxFS->setEnabled(false);
    }
}

int DgRechercherUneOccupation::currentNumOp()
{
    int currentRow = ui->tableWidget->currentRow();

    if(currentRow < 0)
        return 0;
    else
        return ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();
}

void DgRechercherUneOccupation::on_btn_enregistrer_clicked()
{
    // faire une opération comptable
    configServiceCompta csc_caisse(configServiceCompta::CaisseRecept);
    configServiceCompta csc_client(configServiceCompta::ClientRecept);

    if((csc_client.compteAssocie() == 0)||(csc_caisse.compteAssocie() == 0))
    {
        QMessageBox::information(this
                                 , "Echec d'enregistrement"
                                 , "Les comptes concernés par l'opération ne sont pas disponibles.\n\n Contactez le service comptable pour la configuration de ces comptes.");
        return;
    }

    int montantVerse = ui->spinBoxMontantRegl->value();
    occupation oc(currentNumOp());

    if(QMessageBox::question(this, tr("Règlement de location de la chambre %1").arg(oc.chambreOccupee())
                             , tr("Vous êtes sur le point d'enregistrer un montant de %1 pour régler la location de la chambre %2. \n\n Désirez-vous continuer ?").arg(montantVerse).arg(oc.chambreOccupee())
                             , "Oui", "Non") == 0)
    {
        oc.setPayee(montantVerse + oc.payee());
        oc.enregistrer();

        if(ui->rb_payementLoc->isChecked())
        {
            QList<int> numCpts, montants;
            QList<bool> debiteurs;

            // transférer l'avance du compte avance au compte client
            numCpts << csc_client.compteAssocie() << csc_caisse.compteAssocie();
            debiteurs << false << true;
            montants << montantVerse << montantVerse;

            QString description = tr("Règlement partiel de location (%1)").arg(oc.chambreOccupee());

            // effectuer l'enregistrement de l'opération comptable
            if(!MesTables::enregistrerUneOperationComptable( Horloge::currentDate()
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

        rafraichirTable();
    }

    afficherMontantReglementLoc(ui->tableWidget->currentIndex());
}


void DgRechercherUneOccupation::on_btn_enregistrerResto_clicked()
{
    // faire une opération comptable
    configServiceCompta csc_caisse(configServiceCompta::CaisseRecept);
    configServiceCompta csc_client(configServiceCompta::ClientRecept);

    if((csc_client.compteAssocie() == 0)||(csc_caisse.compteAssocie() == 0))
    {
        QMessageBox::information(this
                                 , "Echec d'enregistrement"
                                 , "Les comptes concernés par l'opération ne sont pas disponibles.\n\n Contactez le service comptable pour la configuration de ces comptes.");
        return;
    }

    int montantVerse = ui->spinBoxRestaurationMR->value();
    occupation oc(currentNumOp());

    if(QMessageBox::question(this, tr("Règlement de consommation au restaurant").arg(oc.chambreOccupee())
                             , tr("Vous êtes sur le point d'enregistrer un montant de %1 pour régler la consommation au restaurant. \n\n Désirez-vous continuer ?").arg(montantVerse)
                             , "Oui", "Non") == 0)
    {
     // on enregistre dans la table consommation resto pour le client
        if(true)
        {
            if(ui->rb_payementResto->isChecked())
            {
                QList<int> numCpts, montants;
                QList<bool> debiteurs;

                // transférer l'avance du compte avance au compte client
                numCpts << csc_client.compteAssocie() << csc_caisse.compteAssocie();
                debiteurs << false << true;
                montants << montantVerse << montantVerse;

                QString description = tr("Règlement de consommation de (%1)").arg(oc.chambreOccupee());

                // effectuer l'enregistrement de l'opération comptable
                if(!MesTables::enregistrerUneOperationComptable( Horloge::currentDate()
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
        }else
        {
            QMessageBox::warning(this, "Erreur d'enregistrement", "Toute l'opération n'a pas pu être effectuée!");
            return;
        }
    }

    afficherMontantReglementResto(ui->tableWidget->currentIndex());
}

void DgRechercherUneOccupation::on_btn_enregistrerFraisSup_clicked()
{
    // faire une opération comptable
    configServiceCompta csc_caisse(configServiceCompta::CaisseRecept);
    configServiceCompta csc_penaliteRetard(configServiceCompta::PenaliteRetardRecept);

    if((csc_penaliteRetard.compteAssocie() == 0)||(csc_caisse.compteAssocie() == 0))
    {
        QMessageBox::information(this
                                 , "Echec d'enregistrement"
                                 , "Les comptes concernés par l'opération ne sont pas disponibles.\n\n Contactez le service comptable pour la configuration de ces comptes.");
        return;
    }

    int montantVerse = ui->spinBoxFraisSupMR->value();
    occupation oc(currentNumOp());

    if(QMessageBox::question(this, tr("Règlement de pénalité de sortie de %1").arg(oc.chambreOccupee())
                             , tr("Vous êtes sur le point d'enregistrer un montant de %1 pour régler la pénalité de sortie de la chambre %2. \n\n Désirez-vous continuer ?").arg(montantVerse).arg(oc.chambreOccupee())
                             , "Oui", "Non") == 0)
    {
        oc.setFraisSupPayee(montantVerse + oc.fraisSupPayee());
        oc.setFraisSupplementaire(ui->lineEditFraisSupRegl->text().toInt());
        oc.enregistrer();

        if(ui->rb_payementFraisSup->isChecked())
        {
            QList<int> numCpts, montants;
            QList<bool> debiteurs;

            // transférer l'avance du compte avance au compte client
            numCpts << csc_penaliteRetard.compteAssocie() << csc_caisse.compteAssocie();
            debiteurs << false << true;
            montants << montantVerse << montantVerse;

            QString description = tr("Règlement de pénalité de retard de sortie (%1)").arg(oc.chambreOccupee());

            // effectuer l'enregistrement de l'opération comptable
            if(!MesTables::enregistrerUneOperationComptable( Horloge::currentDate()
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
    }

    afficherMontantReglementFraisSup(ui->tableWidget->currentIndex());
}

void DgRechercherUneOccupation::on_btn_imprimerRecu_clicked()
{
    occupation oc(currentNumOp());
    client cl(oc.codeClient());

    infosHotel ih(1);
    recuHotel recu(ih.logo());
    recu.setText(recuHotel::NomHotel, ih.nom());
    int numRecu = ih.numRecu() + 1;
    recu.setText(recuHotel::NumFacture, QString::number(numRecu));
    recu.setText(recuHotel::SituationGeo, ih.situationGeo());
    recu.setText(recuHotel::Adresse, ih.bp());
    recu.setText(recuHotel::Tel, ih.numeroTel());
    recu.setText(recuHotel::FaitA, tr("Fait à %1 le %2").arg(ih.ville()).arg(Horloge::currentDate().toString(Qt::SystemLocaleLongDate)));
    recu.setText(recuHotel::MatriculeAgent, m_recepteur->matricule());
    recu.setText(recuHotel::NomAgent, tr("%1 %2").arg(m_recepteur->nom()).arg(m_recepteur->prenoms()));
    recu.setText(recuHotel::Profession, cl.profession());
    recu.setText(recuHotel::NomClient, tr("%1 %2").arg(cl.nom()).arg(cl.prenoms()));
    recu.setText(recuHotel::TypeDeChambre, ui->typesDeChambre->currentText());
    recu.setText(recuHotel::IdentifiantDeChambre, oc.chambreOccupee());
    recu.setText(recuHotel::PrixDuJour, QString::number((float)oc.cout() / oc.dureeOccupation()));

    QString duree;
    if(oc.dureeOccupation() == 1)
        duree = "1 jour";
    else
        duree = tr("%1 %2").arg(oc.dureeOccupation()).arg("jours");

    recu.setText(recuHotel::DureeDeLocation, duree);
    recu.setText(recuHotel::LocationAPayer, QString::number(oc.cout()));
    recu.setText(recuHotel::RestaurantAPayer, ui->lineEditRestaurationRegl->text());
    recu.setText(recuHotel::PenaliteAPayer, ui->lineEditFraisSupRegl->text());

    int total = oc.cout() + oc.fraisSupplementaire()
                + ui->lineEditRestaurationRegl->text().toInt();

    recu.setText(recuHotel::TotalAPayer, QString::number(total));
    int restoPaye = (ui->lineEditRestaurationRegl->text().toInt()
                     - ui->lineEditMontantRestantRestoMR->text().toInt());
    int totalPaye = oc.payee() + oc.fraisSupPayee()
                    + restoPaye;

    recu.setText(recuHotel::TotalPaye, QString::number(totalPaye));
    recu.setText(recuHotel::PenalitePaye, QString::number(oc.fraisSupPayee()));
    recu.setText(recuHotel::RestaurantPaye, QString::number(restoPaye));
    recu.setText(recuHotel::LocationPayee, QString::number(oc.payee()));
    recu.setText(recuHotel::ResteAPayer, tr("%1 %2").arg(total - totalPaye).arg("F CFA"));

    // impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    QPrintDialog printDialog(&printer, this);
    // éventuelle pensée
    if(printDialog.exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);

        // print, fitting the viewport contents into a full page
        recu.view()->render(&painter);

        // impression finie. on enregistre donc le numéro de la facture
        ih.setNumRecu(numRecu);
        ih.enregistrer();
    }
}

void DgRechercherUneOccupation::on_spinBoxMontantSup_valueChanged(int value)
{
    if(ui->groupBoxFS->isEnabled())
    {
        if(value == 0)
        {
            ui->spinBoxFraisSupMR->setMinimum(0);
            ui->spinBoxFraisSupMR->setMaximum(0);
            ui->btn_enregistrerFraisSup->setEnabled(false);
            return;
        }

        occupation oc(currentNumOp());
        int montantRestant = value - oc.fraisSupPayee();
        ui->lineEditFraisSupRegl->setText(QString::number(value));
        ui->lineEditMontantRestantFraisSupMR->setText(QString::number(montantRestant));
        ui->spinBoxFraisSupMR->setMinimum(0);
        ui->spinBoxFraisSupMR->setMaximum(montantRestant);

        ui->btn_enregistrerFraisSup->setEnabled(ui->spinBoxFraisSupMR->value() != 0);
    }
}
