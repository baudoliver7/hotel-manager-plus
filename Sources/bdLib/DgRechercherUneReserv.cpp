#include "DgRechercherUneReserv.h"
#include "ui_DgRechercherUneReserv.h"

DgRechercherUneReserv::DgRechercherUneReserv(agent *ag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DgRechercherUneReserv)
{
    ui->setupUi(this);

    m_nbReservAnnulee = 0;
    m_recepteur = ag;
    ui->btn_executer->setEnabled(false);
    ui->btn_supprimer->setEnabled(false);

    initialiserTypeDeChambre();
    initialiserTable();

    connect(ui->btn_annuler, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btn_executer, SIGNAL(clicked()), this, SLOT(executer()));
    connect(ui->btn_supprimer, SIGNAL(clicked()), this, SLOT(supprimer()));
    connect(ui->Aujourd_hui, SIGNAL(toggled(bool)), this, SLOT(rafraichirTable()));
    connect(ui->typesDeChambre, SIGNAL(currentIndexChanged(int)), this, SLOT(rafraichirTable()));

    ui->Aujourd_hui->setChecked(true); // il n'était pas coché
}

DgRechercherUneReserv::~DgRechercherUneReserv()
{
    delete ui;
}

void DgRechercherUneReserv::changeEvent(QEvent *e)
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

void DgRechercherUneReserv::initialiserTypeDeChambre()
{
    m_typesDeChambresDispo << typeDeChambre::typeDeChambreDisponibles(true);
    m_typesDeChambresStrDispo << typeDeChambre::typesDisponibles(true);

    ui->typesDeChambre->addItems(m_typesDeChambresStrDispo);

    connect(ui->typesDeChambre, SIGNAL(currentIndexChanged(int)), this, SLOT(rafraichirTable()));
}

void DgRechercherUneReserv::rafraichirTable()
{
    ui->tableWidget->setRowCount(0);

    QList<QSqlRecord> chambresReservees;
    int index = ui->typesDeChambre->currentIndex();
    chambresReservees << chambreReservee::chambresReserveesEnCours(m_typesDeChambresDispo.at(index).idTypeDeChambre());

    int j = 0;
    for(int i = 0; i < chambresReservees.count(); i++)
    {
        chambreReservee rv(chambresReservees.at(i));
        reservation reserv(rv.numReservation());

        if(ui->Aujourd_hui->isChecked() && reserv.datedEntree().date()!= Horloge::currentDate()) // rv pour aujourdui
        {
            // ne rien faire
        }else
        {
            ui->tableWidget->setRowCount(j + 1);
            afficherElement(j, NUMERO_RESERV, QString::number(rv.numReservation()));
            afficherElement(j, CHAMBRE, rv.identiteCh());
            afficherElement(j, DATE_DE_DEMANDE, reserv.dateDeDemande().toString(Qt::SystemLocaleLongDate));
            afficherElement(j, DATE_OCCUPATION, reserv.datedEntree().toString(Qt::SystemLocaleLongDate));
            afficherElement(j, DUREE_EN_JOURS, MesTables::convertirAnMoisSemaineJour(reserv.dureeOccupation()));
            afficherElement(j, DATE_SORTIE, reserv.datedSortie().toString(Qt::SystemLocaleLongDate));
            afficherElement(j, PRIXTOTAL, QString::number(rv.cout()));
            afficherElement(j, AVANCE, QString::number(rv.avance()));
            afficherElement(j, MONTANTRESTANT, QString::number(rv.reste()));

            client cl(reserv.codeClient());
            QString nomComplet = tr("%1 %2").arg(cl.nom()).arg(cl.prenoms());
            afficherElement(j, BENEFICIAIRE, nomComplet);
            j++;
        }
    }
}

void DgRechercherUneReserv::afficherElement(int row, int column, const QString &value)
{
    QTableWidgetItem * item = new QTableWidgetItem(value);
    item->setTextAlignment(Qt::AlignCenter);

    ui->tableWidget->setItem(row, column, item);
}

void DgRechercherUneReserv::initialiserTable()
{
    connect(ui->tableWidget->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(updateEtatBtnsWidget(QModelIndex)));

    ui->tableWidget->setColumnHidden(NUMERO_RESERV, true);
    ui->tableWidget->sortItems(CHAMBRE, Qt::AscendingOrder);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DgRechercherUneReserv::updateEtatBtnsWidget(QModelIndex index)
{
    if(index.isValid())
    {
        if(reservationPeutEtreExecuter(index.row()))
        {
            ui->btn_executer->setEnabled(true);
        }

        ui->btn_supprimer->setEnabled(true);
    }else
    {
        ui->btn_executer->setEnabled(false);
        ui->btn_supprimer->setEnabled(false);
    }
}

void DgRechercherUneReserv::supprimer()
{
    configServiceCompta csc_avance(configServiceCompta::AvanceRecept);
    configServiceCompta csc_client(configServiceCompta::ClientRecept);

    if((csc_client.compteAssocie() == 0)||(csc_avance.compteAssocie() == 0))
    {
        QMessageBox::information(this
                                 , "Echec d'enregistrement"
                                 , "Les comptes concernés par l'opération ne sont pas disponibles.\n\n Contactez le service comptable pour la configuration de ces comptes.");
        return;
    }

    int currentRow = ui->tableWidget->currentRow();
    int numReserv = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

    chambreReservee rv(numReserv);

    if(QMessageBox::question(this, tr("Réservation de la chambre %1").arg(rv.identiteCh())
                             , "Désirez-vous annuler la réservation en cours?", "Oui", "Non") == 0)
    {
        reservation reserv(rv.numReservation());
        if(MesTables::annulerReservation(reserv, *m_recepteur, Horloge::currentDateTime(), rv.identiteCh()))
        {
            if(rv.avance() != 0)
            {
                // exécuter une opération comptable pour restituer dans le cas d'une avance
                // une partie ou la totalité de la somme au client
//                BDRestituerAuClient bd(rv.avance(), true, this);
//                bd.setWindowTitle("Somme à restituer au client");
//
//                bd.exec();

                QList<int> numCpts, montants;
                QList<bool> debiteurs;

                // transférer l'avance du compte avance au compte client
                numCpts << csc_avance.compteAssocie() << csc_client.compteAssocie();
                debiteurs << false << true;
                montants << rv.avance() << rv.avance();

                QString description = tr("Transfert d'avance de location (%1)").arg(rv.identiteCh());

                // effectuer l'enregistrement de l'opération comptable
                if(!MesTables::enregistrerUneOperationComptable(Horloge::currentDate()
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
//
//                if(bd.sommeARestituer() != rv.avance()) // si on restitue une partie de l'avance
//                {
//                    // repartir l'avance sur le compte de restitution et le compte location
//                    int montantDeRevient = rv.avance() - bd.sommeARestituer();
//
//                    if(rv.reglementBancaire())
//                    {
//                        numCpts.clear(); debiteurs.clear(); montants.clear();
//                        numCpts << csc_banque.compteAssocie() << csc_caisse.compteAssocie() << csc_location.compteAssocie();
//                        debiteurs << true << false << false;
//                        montants << rv.avance() << bd.sommeARestituer() << montantDeRevient;
//
//                        description = tr("Annulation de réservation (%1)").arg(rv.chambreReservee());
//
//                        // effectuer l'enregistrement de l'opération comptable
//                        if(!MesTables::enregistrerUneOperationComptable( Horloge::currentDate()
//                                                                        ,numCpts
//                                                                        , description
//                                                                        , debiteurs
//                                                                        , montants
//                                                                        , m_recepteur->matricule()
//                                                                        , false))
//                        {
//                            QMessageBox::warning(this, "Erreur d'enregistrement", "Toute l'opération n'a pas pu être effectuée!");
//                            return;
//                        }
//                    }else
//                    {
//                        // avance préalablement versée en espèce
//                        numCpts.clear(); debiteurs.clear(); montants.clear();
//                        numCpts << csc_location.compteAssocie() << csc_caisse.compteAssocie();
//                        debiteurs << false << true;
//                        montants << montantDeRevient << montantDeRevient;
//
//                        description = tr("Annulation de réservation (%1)").arg(rv.chambreReservee());
//
//                        // effectuer l'enregistrement de l'opération comptable
//                        if(!MesTables::enregistrerUneOperationComptable( Horloge::currentDate()
//                                                                        ,numCpts
//                                                                        , description
//                                                                        , debiteurs
//                                                                        , montants
//                                                                        , m_recepteur->matricule()
//                                                                        , false))
//                        {
//                            QMessageBox::warning(this, "Erreur d'enregistrement", "Toute l'opération n'a pas pu être effectuée!");
//                            return;
//                        }
//                    }
//                }
            }

            ui->tableWidget->removeRow(currentRow);
            m_nbReservAnnulee++;
            emit bdModifie();
        }else
        {
            QMessageBox::warning(this, "Erreur d'annulation", tr("Une erreur s'est signalée lors de l'annulation de la réservation de la chambre %1!").arg(rv.identiteCh()));
        }
    }
}

void DgRechercherUneReserv::executer()
{
    int currentRow = ui->tableWidget->currentRow();
    int numReserv = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

    chambreReservee rv(numReserv);

    emit remplirOccupation(rv);

    close();
}

bool DgRechercherUneReserv::reservationPeutEtreExecuter(int row)
{
    int numReserv = ui->tableWidget->item(row, NUMERO_RESERV)->text().toInt();

    chambreReservee rv(numReserv);
    reservation reserv(rv.numReservation());
    return (rv.estEnCours() && reserv.datedEntree().date()== Horloge::currentDate());
    return true;
}
