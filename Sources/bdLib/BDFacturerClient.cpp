#include "BDFacturerClient.h"
#include "ui_BDFacturerClient.h"

BDFacturerClient::BDFacturerClient(BDD *db, const agent &ag, int idClient, int idActivite, bool occuper, bool groupe, QWidget *parent):
    QDialog(parent),
    ui(new Ui::BDFacturerClient)
{
    ui->setupUi(this);

    m_db = db;
    ui->btn_details->setVisible(false);
    ui->spinBoxVersement->setEnabled(!groupe);
    ui->btn_maximum_SV->setEnabled(!groupe);
    ui->comboBoxModeDePayement->setEnabled(!groupe);

    m_client = client(idClient);
    m_agent = ag;
    m_occuper = occuper;

    QString identifiant;
    int idProfile;
    if(m_occuper)
    {
        m_occupation = occupation(idActivite);
        identifiant = m_occupation.chambreOccupee();
        idProfile = m_occupation.idProfileClient();
    }
    else
    {
        m_reservation = reservation(idActivite);
        identifiant =  chambreReservee(chambreReservee::chambre_reservee_records(m_reservation.numReservation()).first()).identiteCh();
        idProfile = m_reservation.idProfileClient();
    }

    chambre ch(identifiant);
    m_prixUnitaireNorm = prixChambreTTC(ch.idTypeChambre(), idProfile).prixTTC();

    if(occuper)
    {
        ui->lineEditDureeOccup->setText(QString::number(m_occupation.dureeOccupation()));
        int prixUnitaire = m_occupation.cout() / m_occupation.dureeOccupation();

        ui->spinBoxTarif->setMaximum(m_prixUnitaireNorm);
        ui->spinBoxTarif->setMinimum(0);
        ui->spinBoxTarif->setValue(prixUnitaire);

        ui->lineEditFraisLocation->setText(QString::number(m_occupation.cout()));

        // rechercher les conso terminées et non payés du client 
        m_recordsResto = m_occupation.repasConsoNonPayes_record();
        m_recordsBar = m_occupation.barConsoNonPayes_record();

        int montantRestoNonRegle = m_occupation.fraisRestoNonPayes();
        int montantBarNonRegle = m_occupation.fraisBarNonPayes();

        ui->lineEditFraisResto->setText(QString::number(montantRestoNonRegle));
        ui->lineEditFraisBar->setText(QString::number(montantBarNonRegle));

        ui->spinBoxFraisPenaliteRetard->setMinimum(m_occupation.fraisSupplementaire());
        ui->spinBoxFraisPenaliteRetard->setValue(m_occupation.fraisSupplementaire());

        int totalAPayer = m_occupation.cout() + m_occupation.fraisSupplementaire() + montantRestoNonRegle + montantBarNonRegle;
        ui->lineEditTotalAPayer->setText(QString::number(totalAPayer));

        int sommePayee = m_occupation.fraisSupPayee() + m_occupation.payee();
        ui->lineEditSommePayee->setText(QString::number(sommePayee));
        ui->lineEditResteAPayer->setText(QString::number(totalAPayer - sommePayee));

        if(m_occupation.terminee())
        {
            ui->spinBoxTarif->setReadOnly(true);
        }
    }else
    {
        ui->btn_details->setEnabled(false);

        ui->lineEditDureeOccup->setText(QString::number(m_reservation.dureeOccupation()));
        int prixUnitaire = m_reservation.cout() / m_reservation.dureeOccupation();

        ui->spinBoxTarif->setMaximum(m_prixUnitaireNorm);
        ui->spinBoxTarif->setMinimum(0);
        ui->spinBoxTarif->setValue(prixUnitaire);

        ui->lineEditFraisLocation->setText(QString::number(m_reservation.cout()));

        int montantNonRegle = 0;
        ui->lineEditFraisResto->setText(QString::number(montantNonRegle));
        ui->lineEditFraisBar->setText(QString::number(montantNonRegle));

        ui->spinBoxFraisPenaliteRetard->setMaximum(0);
        ui->spinBoxFraisPenaliteRetard->setMinimum(0);
        ui->spinBoxFraisPenaliteRetard->setValue(0);

        int totalAPayer = m_reservation.cout() + montantNonRegle;
        ui->lineEditTotalAPayer->setText(QString::number(totalAPayer));

        int sommePayee = m_reservation.avance();
        ui->lineEditSommePayee->setText(QString::number(sommePayee));
        ui->lineEditResteAPayer->setText(QString::number(totalAPayer - sommePayee));

        QList<QSqlRecord> records;
        records = chambreReservee::chambre_reservee_records(m_reservation.numReservation());
        if(!records.isEmpty() && chambreReservee(records.first()).terminee())
        {
            ui->spinBoxTarif->setReadOnly(true);
        }
    }

    ui->spinBoxVersement->setValue(0);
    ui->btn_ok->setEnabled(false);

    connect(ui->rb_regler, SIGNAL(toggled(bool)), this, SLOT(setLimitesSommeAPayer()));
    connect(ui->rb_regler, SIGNAL(toggled(bool)), this, SLOT(chargerModeDePayement()));
    ui->rb_regler->setChecked(true);
}

BDFacturerClient::~BDFacturerClient()
{
    delete ui;
}

void BDFacturerClient::changeEvent(QEvent *e)
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

void BDFacturerClient::on_btn_ok_clicked()
{
    m_db->transaction();
    bool submitAll;

    if(m_occuper)
    {
        submitAll = enregistrerFacturationOccup();
    }else
    {
        submitAll = enregistrerFacturactionReserv();
    }

    if(submitAll)
        m_db->commit();
    else
        m_db->rollback();

    accept();
}

void BDFacturerClient::on_btn_annuler_clicked()
{
    reject();
}

void BDFacturerClient::chargerModeDePayement()
{
    // charger compte du client
    QList<QSqlRecord> records = compteClient::compteClient_records(m_client.codeDuClient());

    QStringList comptes;
    foreach(QSqlRecord r, records)
    {
        compteClient cc(r);
        comptes << cc.libelle();
        m_comptesDuClient << cc;
    }

    ui->comboBoxCompteClient->addItems(comptes);

    ui->comboBoxModeDePayement->clear();
    if(comptes.isEmpty() || ui->rb_restituer->isChecked())
        ui->comboBoxModeDePayement->addItems(modeDePayement::chargerModeDePayementSansCompteClient());
    else
        ui->comboBoxModeDePayement->addItems(modeDePayement::chargerModeDePayement());
}

void BDFacturerClient::on_btn_appliquerTarifNorm_clicked()
{
    if(m_prixUnitaireNorm != ui->spinBoxTarif->value())
    {
        ui->spinBoxTarif->setValue(m_prixUnitaireNorm); // lancement auto des slots liés
    }else
    {
        on_spinBoxTarif_valueChanged(m_prixUnitaireNorm); // lancement manuel du slot
    }
}

void BDFacturerClient::on_spinBoxTarif_valueChanged(int prixUnitaire)
{
    ui->btn_ok->setEnabled(true);
    int fraisLocation = prixUnitaire * ui->lineEditDureeOccup->text().toInt();
    int fraisSup = ui->spinBoxFraisPenaliteRetard->value();
    int fraisResto = ui->lineEditFraisResto->text().toInt();

    int totalAPayer = fraisLocation + fraisSup + fraisResto;
    int reste = totalAPayer - ui->lineEditSommePayee->text().toInt();

    ui->lineEditFraisLocation->setText(QString::number(fraisLocation));
    ui->lineEditResteAPayer->setText(QString::number(reste));

    if(reste >= 0)
        ui->spinBoxVersement->setMaximum(reste);
    else
        ui->spinBoxVersement->setMaximum(0);
}

void BDFacturerClient::on_lineEditFraisResto_textChanged(QString text)
{
    ui->btn_details->setEnabled(text.toInt() > 0);
}

void BDFacturerClient::on_spinBoxFraisPenaliteRetard_valueChanged(int penalite)
{
    ui->btn_ok->setEnabled(true);
    int fraisLocation = ui->lineEditFraisLocation->text().toInt();
    int fraisResto = ui->lineEditFraisResto->text().toInt();

    int totalAPayer = fraisLocation + penalite + fraisResto;
    int reste = totalAPayer - ui->lineEditSommePayee->text().toInt();

    ui->lineEditFraisLocation->setText(QString::number(fraisLocation));
    ui->lineEditResteAPayer->setText(QString::number(reste));

    if(reste >= 0)
        ui->spinBoxVersement->setMaximum(reste);
    else
        ui->spinBoxVersement->setMaximum(0);
}

int BDFacturerClient::coutTotalLocation()const
{
    if(m_occuper)
    {
        return m_occupation.cout();
    }else
    {
        return m_reservation.cout();
    }
}

int BDFacturerClient::resteLocation()const
{
    if(m_occuper)
    {
        return m_occupation.reste();
    }else
    {
        return m_reservation.reste();
    }
}

void BDFacturerClient::on_comboBoxModeDePayement_currentIndexChanged(int index)
{
    bool enabled = (index + 1 == modeDePayement::CompteClient);
    ui->comboBoxCompteClient->setEnabled(enabled);
    ui->lineEditSolde->setEnabled(enabled);

    if(enabled)
    {
        chargerComptesDuClient();
    }
    else
    {
        setLimitesSommeAPayer();
    }
}

void BDFacturerClient::chargerComptesDuClient()
{
    m_comptesDuClient.clear();
    ui->comboBoxCompteClient->clear();

    QList<QSqlRecord> records;
    records = compteClient::compteClient_records(m_client.codeDuClient());

    QStringList comptes;
    foreach(QSqlRecord r, records)
    {
        compteClient cc(r);
        comptes << cc.libelle();
        m_comptesDuClient << cc;
    }

    ui->comboBoxCompteClient->addItems(comptes);
}


void BDFacturerClient::on_comboBoxCompteClient_currentIndexChanged(int index)
{
    int solde = 0;
    int maximum = 0;
    if(ui->comboBoxCompteClient->count() == 0)
    {
        solde = 0;
        maximum = 0;
    }else
    {
        solde = m_comptesDuClient.at(index).solde();
        int sommeRestante = ui->lineEditResteAPayer->text().toInt();
        if(solde < sommeRestante)
        {
            maximum = solde;
        }else
        {
            maximum = sommeRestante;
        }
    }

    ui->lineEditSolde->setText(QString::number(solde));

    if(maximum > 0)
        ui->spinBoxVersement->setMaximum(maximum);
    else
        ui->spinBoxVersement->setMaximum(0);

    ui->spinBoxVersement->setValue(maximum);
}

void BDFacturerClient::on_spinBoxVersement_valueChanged(int )
{
    ui->btn_ok->setEnabled(true);
}

void BDFacturerClient::on_btn_maximum_SV_clicked()
{
    ui->spinBoxVersement->setValue(ui->spinBoxVersement->maximum());
}

void BDFacturerClient::setLimitesSommeAPayer()
{
    ui->spinBoxVersement->setMinimum(0);

    if(ui->rb_regler->isChecked())
    {
        // régler
        int reste = ui->lineEditTotalAPayer->text().toInt() - ui->lineEditSommePayee->text().toInt();
        if(reste > 0)
            ui->spinBoxVersement->setMaximum(reste);
        else
            ui->spinBoxVersement->setMaximum(0);

        ui->spinBoxVersement->setValue(0);
    }else
    {
        // restitution
        ui->spinBoxVersement->setMaximum(ui->lineEditSommePayee->text().toInt());
        ui->spinBoxVersement->setValue(0);
    }
}

bool BDFacturerClient::enregistrerFacturationOccup()
{
    if(ui->rb_regler->isChecked())
    {
        return enregistrerReglementOccup();
    }else
    {
        return enregistrerRestitutionOccup();
    }
}

bool BDFacturerClient::enregistrerFacturactionReserv()
{
    if(ui->rb_regler->isChecked())
    {
        return enregistrerReglementReserv();
    }else
    {
        return enregistrerRestitutionReserv();
    }
}

bool BDFacturerClient::enregistrerReglementOccup()
{
    bool submitAll = true;

    // enregistrement
    QString libelleCompteClient; // libellé pour une éventuel transaction sur le compte client
    QDateTime now = Horloge::currentDateTime();
    int montantVerse = ui->spinBoxVersement->value();

    libelleCompteClient = QString("Réglement de la facture de location %1").arg(m_occupation.facture());
    m_occupation.setCout(ui->lineEditFraisLocation->text().toInt());
    m_occupation.setFraisSupplementaire(ui->spinBoxFraisPenaliteRetard->value());

    if(montantVerse > 0)
    {
        // faire les différents réçus
        if(!m_occupation.estReglee() || !m_occupation.fraisSupSontRegles()) // frais location
        {
            int montantOccup = m_occupation.reglerMontantTotal(montantVerse);

            // faire un réçu pour la réception
            submitAll = submitAll && MesTables::enregistrerUneOperationService(  m_agent
                                                                                  , recuInitial::IdLocation
                                                                                  , now
                                                                                  , montantOccup
                                                                                  , QString("Réglement de la facture de location %1").arg(m_occupation.facture())
                                                                                  , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                                  , m_occupation.numOccupation()
                                                                                  , occupation().tableName());
        }

        // exécuter pour le restaurant
        if(montantVerse > 0)
        {
            int i = -1;
            do
            {
                i++;
                repasCompletResto rcr(m_recordsResto.at(i));
                int montantResto = rcr.reglerMontantTotal(montantVerse);

                // faire réçu
                submitAll = submitAll && MesTables::enregistrerUneOperationService(m_agent
                                                                                  , recuInitial::IdRestauration
                                                                                  , now
                                                                                  , montantResto
                                                                                  , QString("Réglement de la facture de restauration %1").arg(rcr.facture())
                                                                                  , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                                  , rcr.idRepasCResto()
                                                                                  , repasCompletResto().tableName());

                submitAll = submitAll && rcr.enregistrer();
            }while(montantVerse > 0);
        }

        // exécuter pour le bar
        if(montantVerse > 0)
        {
            int i = -1;
            do
            {
                i++;
                repasCompletResto rcr(m_recordsBar.at(i));
                int montantBar = rcr.reglerMontantTotal(montantVerse);

                // faire réçu
                submitAll = submitAll && MesTables::enregistrerUneOperationService(m_agent
                                                                                  , recuInitial::IdBar
                                                                                  , now
                                                                                  , montantBar
                                                                                  , QString("Réglement de la facture de bar %1").arg(rcr.facture())
                                                                                  , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                                  , rcr.idRepasCResto()
                                                                                  , repasCompletResto().tableName());

                submitAll = submitAll && rcr.enregistrer();
            }while(montantVerse > 0);
        }
    }

    submitAll = submitAll && m_occupation.enregistrer();

    montantVerse = ui->spinBoxVersement->value();
    int currentIndex = ui->comboBoxCompteClient->currentIndex();
    if((ui->comboBoxModeDePayement->currentIndex() + 1 == modeDePayement::CompteClient)
        && (montantVerse != 0))
    {
        // débiter le compte client
        submitAll = submitAll && MesTables::faireUnMouvementCompteClient(m_agent
                                                                        , now
                                                                        , m_comptesDuClient.at(currentIndex).idCompteClient()
                                                                        , libelleCompteClient
                                                                        , montantVerse
                                                                        , true
                                                                        , submitAll);
    }

    return submitAll;
}

bool BDFacturerClient::enregistrerRestitutionOccup()
{
    bool submitAll = true;

    // enregistrement
    QDateTime now = Horloge::currentDateTime();
    int montantVerse = ui->spinBoxVersement->value();

    m_occupation.setCout(ui->lineEditFraisLocation->text().toInt());
    m_occupation.setFraisSupplementaire(ui->spinBoxFraisPenaliteRetard->value());

    if(montantVerse > 0)
    {
        // faire les différents réçus
        if(m_occupation.payee() + m_occupation.fraisSupPayee() > 0) // frais location
        {
            int montantOccup = m_occupation.restituerMontantTotal(montantVerse);

            // faire un réçu pour la réception
            submitAll = submitAll && MesTables::enregistrerUneOperationService(   m_agent
                                                                                  , recuInitial::IdRestitutionLocation
                                                                                  , now
                                                                                  , montantOccup
                                                                                  , QString("Restitution de montant de location (facture %1)").arg(m_occupation.facture())
                                                                                  , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                                  , m_occupation.numOccupation()
                                                                                  , occupation().tableName()
                                                                                  , false);
        }

        // exécuter pour le restaurant
        if(montantVerse > 0 && !m_recordsResto.isEmpty())
        {
            int i = -1;
            do
            {
                i++;
                repasCompletResto rcr(m_recordsResto.at(i));
                int montantResto = rcr.restituerMontantTotal(montantVerse);

                // faire réçu
                submitAll = submitAll && MesTables::enregistrerUneOperationService( m_agent
                                                                                  , recuInitial::IdRestitutionRestauration
                                                                                  , now
                                                                                  , montantResto
                                                                                  , QString("Restitution de montant de restauration (facture %1)").arg(rcr.facture())
                                                                                  , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                                  , rcr.idRepasCResto()
                                                                                  , repasCompletResto().tableName()
                                                                                  , false);

                submitAll = submitAll && rcr.enregistrer();
            }while(montantVerse > 0);
        }

        // exécuter pour le bar
        if(montantVerse > 0 && !m_recordsBar.isEmpty())
        {
            int i = -1;
            do
            {
                i++;
                repasCompletResto rcr(m_recordsBar.at(i));
                int montantBar = rcr.restituerMontantTotal(montantVerse);

                // faire réçu
                submitAll = submitAll && MesTables::enregistrerUneOperationService( m_agent
                                                                                  , recuInitial::IdRestitutionBar
                                                                                  , now
                                                                                  , montantBar
                                                                                  , QString("Restitution de montant de bar (facture %1)").arg(rcr.facture())
                                                                                  , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                                  , rcr.idRepasCResto()
                                                                                  , false);

                submitAll = submitAll && rcr.enregistrer();
            }while(montantVerse > 0);
        }
    }

    submitAll = submitAll && m_occupation.enregistrer();

    return submitAll;
}

bool BDFacturerClient::enregistrerReglementReserv()
{
    bool submitAll = true;

    // enregistrement
    QString libelleCompteClient; // libellé pour une éventuel transaction sur le compte client
    QDateTime now = Horloge::currentDateTime();
    int montantVerse = ui->spinBoxVersement->value();

    // faire pour réservation. c'est avance
    m_reservation.setCout(ui->lineEditFraisLocation->text().toInt());
    chambreReservee chr(chambreReservee::chambre_reservee_records(m_reservation.numReservation()).first());
    chr.setCout(m_reservation.cout());

    libelleCompteClient = tr("Avance sur location de la chambre (%1)").arg(chr.identiteCh());
    if(montantVerse != 0)
    {
        // le montant est obligatoirement inférieur au cout de location
        m_reservation.setAvance(montantVerse + m_reservation.avance());

        // de même pour les chambres réservées. c'est un seul
        chr.setAvance(m_reservation.avance());

        // faire un réçu
        submitAll = submitAll && MesTables::enregistrerUneOperationService(m_agent
                                                                          , recuInitial::IdReservation
                                                                          , now
                                                                          , montantVerse
                                                                          , QString("Avance sur location de la chambre %1").arg(chr.identiteCh())
                                                                          , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                          , m_reservation.numReservation()
                                                                          , reservation().tableName());
    }

    submitAll = submitAll && chr.enregistrer();
    submitAll = submitAll && m_reservation.enregistrer();

    montantVerse = ui->spinBoxVersement->value();
    int currentIndex = ui->comboBoxCompteClient->currentIndex();
    if((ui->comboBoxModeDePayement->currentIndex() + 1 == modeDePayement::CompteClient)
        && (montantVerse != 0))
    {
        // débiter le compte client
        submitAll = submitAll && MesTables::faireUnMouvementCompteClient(m_agent
                                                                        , now
                                                                        , m_comptesDuClient.at(currentIndex).idCompteClient()
                                                                        , libelleCompteClient
                                                                        , montantVerse
                                                                        , true
                                                                        , submitAll);
    }

    return submitAll;
}

bool BDFacturerClient::enregistrerRestitutionReserv()
{
    bool submitAll = true;

    // enregistrement
    QDateTime now = Horloge::currentDateTime();
    int montantVerse = ui->spinBoxVersement->value();

    m_reservation.setCout(ui->lineEditFraisLocation->text().toInt());
    chambreReservee chr(chambreReservee::chambre_reservee_records(m_reservation.numReservation()).first());
    chr.setCout(m_reservation.cout());

    if(montantVerse > 0)
    {
        // le montant est obligatoirement inférieur à l'avance
        m_reservation.setAvance(m_reservation.avance() - montantVerse);

        // de même pour les chambres réservées. c'est un seul
        chr.setAvance(m_reservation.avance());

        // faire un réçu
        submitAll = submitAll && MesTables::enregistrerUneOperationService(m_agent
                                                                          , recuInitial::IdRestitutionAvanceLocation
                                                                          , now
                                                                          , montantVerse
                                                                          , QString("Restitution d'avance sur location de la chambre %1").arg(chr.identiteCh())
                                                                          , ui->comboBoxModeDePayement->currentIndex() + 1
                                                                          , m_reservation.numReservation()
                                                                          , false);
    }

    submitAll = submitAll && chr.enregistrer();
    submitAll = submitAll && m_reservation.enregistrer();

    return submitAll;
}
