#include "BDFacturerUnGroupe.h"
#include "ui_BDFacturerUnGroupe.h"

BDFacturerUnGroupe::BDFacturerUnGroupe(QSqlDatabase *db, const agent &ag, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDFacturerUnGroupe)
{
    ui->setupUi(this);

    m_db = db;
    ui->btn_ok->setEnabled(false);
    ui->btn_details->setEnabled(false);
    ui->btn_detailsResto->setEnabled(false);

    m_agent = ag;
    initialiser();
    chargerModeDePayement();

    connect(ui->rb_regler, SIGNAL(toggled(bool)), this, SLOT(setLimitesSommeAPayer()));
    ui->rb_regler->setChecked(true);
}

BDFacturerUnGroupe::~BDFacturerUnGroupe()
{
    delete ui;
}

void BDFacturerUnGroupe::changeEvent(QEvent *e)
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

void BDFacturerUnGroupe::on_btn_groupe_clicked()
{
    BDRechercherUnGroupe * bd = new BDRechercherUnGroupe(false, this);
    bd->setWindowTitle("Rechercher un groupe");

    if(bd->exec() == QDialog::Accepted)
    {
        m_groupe = bd->groupeSelectionne();
        afficherGroupe(m_groupe);
    }

    delete bd;
}

void BDFacturerUnGroupe::on_btn_details_clicked()
{
    BDFormulaireClientSimple bd(m_client, true, this);
    bd.setWindowTitle("Rechercher un groupe");

    bd.exec();
}

void BDFacturerUnGroupe::afficherGroupe(const groupe & gr)
{
    ui->lineEditGroupe->setText(gr.libelle());

    // afficher respo
    m_client = client(gr.idResponsable());
    ui->lineEditResponsable->setText(m_client.nomComplet());
    ui->btn_details->setEnabled(true);
    ui->btn_detailsResto->setEnabled(gr.existe());

    // frais de location
    ui->lineEditFraisDeLocation->setText(QString::number(gr.fraisLocation()));

    // frais de restauration
    int frais_resto = gr.fraisRestoTotal();

    ui->lineEditFraisDeRestauration->setText(QString::number(frais_resto));

    // frais de bar
    int frais_bar = gr.fraisBarTotal();

    ui->lineEditFraisDeBar->setText(QString::number(frais_bar));

    // frais sup
    ui->lineEditPenaliteRetard->setText(QString::number(gr.fraisSup()));

    // total à payer
    int totalAPayer = gr.coutTotalGlobal();
    ui->lineEditTotalAPayer->setText(QString::number(totalAPayer));

    // somme payée
    int sommePayee = gr.sommePayeeGlobale();
    ui->lineEditMontantPaye->setText(QString::number(sommePayee));

    // somme restante
    int sommeRestante = totalAPayer - sommePayee;
    ui->lineEditMontantRestant->setText(QString::number(sommeRestante));

    // afficher les limites du versement
    setLimitesSommeAPayer();
}

void BDFacturerUnGroupe::chargerModeDePayement()
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

void BDFacturerUnGroupe::initialiser()
{
    ui->lineEditFraisDeLocation->setText(QString::number(0));
    ui->lineEditFraisDeRestauration->setText(QString::number(0));
    ui->lineEditPenaliteRetard->setText(QString::number(0));
    ui->lineEditTotalAPayer->setText(QString::number(0));
    ui->lineEditMontantPaye->setText(QString::number(0));
    ui->lineEditMontantRestant->setText(QString::number(0));

    ui->spinBoxMontantAVerser->setMaximum(0);
    ui->spinBoxMontantAVerser->setMinimum(0);
}

void BDFacturerUnGroupe::on_lineEditFraisDeRestauration_textChanged(QString text)
{

}

void BDFacturerUnGroupe::on_btn_annuler_clicked()
{
    reject();
}

void BDFacturerUnGroupe::on_btn_ok_clicked()
{
    if(ui->rb_regler->isChecked())
        enregistrerReglement();
    else
        enregistrerRestitution();

    accept();
}

void BDFacturerUnGroupe::on_spinBoxMontantAVerser_valueChanged(int value)
{
    ui->btn_ok->setEnabled(value != 0);
}

void BDFacturerUnGroupe::on_btn_payerTout_clicked()
{
    ui->spinBoxMontantAVerser->setValue(ui->spinBoxMontantAVerser->maximum());
}

void BDFacturerUnGroupe::on_btn_detailsResto_clicked()
{
    factureRestoGroupe * facture = new factureRestoGroupe(m_groupe);

    // impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    QPrintDialog printDialog(&printer, this);

    // éventuelle pensée
    if(printDialog.exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);

        // print, fitting the viewport contents into a full page
        facture->view()->render(&painter);
    }

    delete facture;
}

void BDFacturerUnGroupe::setLimitesSommeAPayer()
{
    ui->spinBoxMontantAVerser->setMinimum(0);

    if(ui->rb_regler->isChecked())
    {
        // régler
        int reste = ui->lineEditTotalAPayer->text().toInt() - ui->lineEditMontantPaye->text().toInt();
        if(reste > 0)
            ui->spinBoxMontantAVerser->setMaximum(reste);
        else
            ui->spinBoxMontantAVerser->setMaximum(0);

        ui->spinBoxMontantAVerser->setValue(0);
    }else
    {
        // restitution
        ui->spinBoxMontantAVerser->setMaximum(ui->lineEditMontantPaye->text().toInt());
        ui->spinBoxMontantAVerser->setValue(0);
    }
}

bool BDFacturerUnGroupe::enregistrerRestitution()
{
    bool submitAll = true;
    QDateTime now = Horloge::currentDateTime();

    int montantVerse = ui->spinBoxMontantAVerser->value();

    if(montantVerse > 0)
    {
        m_db->transaction();        

        QList<QSqlRecord> occupation_records;
        occupation_records << m_groupe.occupations_des_membres_records();

        // enregistrer les factures et recus
        if(m_groupe.sommePayeeGlobale() > 0)
        {
            int surplus = m_groupe.avanceActu();
            if(surplus > 0) // s'il reste encore de l'avance
            {
                // on restitue une avance
                int montantAv = 0;
                if(surplus > 0 && surplus <= montantVerse)
                {
                    montantVerse -= surplus;
                    montantAv = surplus;
                    m_groupe.setAvanceActu(0);
                }else
                {
                    if(surplus > montantVerse)
                    {
                        m_groupe.setAvanceActu(surplus - montantVerse);
                        montantAv = montantVerse;
                        montantVerse = 0;
                    }
                }

                m_groupe.setAvance(m_groupe.avance() - montantAv); // on met à jour l'avance inchangée
                submitAll = submitAll && m_groupe.enregistrer();

                // faire un réçu de restitution d'avance sur location de groupe
                submitAll = submitAll && MesTables::enregistrerUneOperationService(  m_agent
                                                                                     , recuInitial::IdRestitutionAvanceLocation
                                                                                     , now
                                                                                     , montantAv
                                                                                     , QString("Restitution d'avance sur location (groupe %1)").arg(m_groupe.libelle())
                                                                                     , ui->comboBoxModeDePaye->currentIndex() + 1
                                                                                     , m_groupe.idGroupe()
                                                                                     , groupe().tableName()
                                                                                     , false);

            }

            if(montantVerse > 0)
            {
                int montantOccupTotal = 0;
                foreach(QSqlRecord r, occupation_records)
                {
                    if(montantVerse <= 0) break;

                    occupation oc(r);

                    // faire les différents réçus
                    if(oc.payee() + oc.fraisSupPayee() > 0) // frais location
                    {
                        montantOccupTotal += oc.restituerMontantTotal(montantVerse);
                        submitAll = submitAll && oc.enregistrer();
                    }

                    m_occupations << oc;
                }

                // faire un réçu de location du groupe
                submitAll = submitAll && MesTables::enregistrerUneOperationService(  m_agent
                                                                                     , recuInitial::IdRestitutionLocation
                                                                                     , now
                                                                                     , montantOccupTotal
                                                                                     , QString("Restitution de montant de location (groupe %1)").arg(m_groupe.libelle())
                                                                                     , ui->comboBoxModeDePaye->currentIndex() + 1
                                                                                     , m_groupe.idGroupe()
                                                                                     , groupe().tableName()
                                                                                     , false);
            }
        }

        // régler les frais de restauration
        if(montantVerse > 0)
        {
            int montantRestoTotal = 0;
            foreach(QSqlRecord r, occupation_records)
            {
                if(montantVerse <= 0) break;

                occupation oc(r);
                QList<QSqlRecord> rcr_records;
                rcr_records = oc.repasConsoNonPayes_record();
                foreach(QSqlRecord r1, rcr_records)
                {
                    if(montantVerse <= 0) break;

                    repasCompletResto rcr(r1);
                    if(rcr.montantTotalEncaisse() > 0)
                    {
                        montantRestoTotal += rcr.restituerMontantTotal(montantVerse);
                        submitAll = submitAll && rcr.enregistrer();
                    }
                }
            }

            // faire réçu du groupe à la restauration
            submitAll = submitAll && MesTables::enregistrerUneOperationService(  m_agent
                                                                                 , recuInitial::IdRestitutionRestauration
                                                                                 , now
                                                                                 , montantRestoTotal
                                                                                 , QString("Restitution de montant de restauration (groupe %1)").arg(m_groupe.libelle())
                                                                                 , ui->comboBoxModeDePaye->currentIndex() + 1
                                                                                 , m_groupe.idGroupe()
                                                                                 , groupe().tableName());
        }

        if(submitAll)
        {
            m_groupe.actualiser(); // actualiser le groupe
            m_db->commit();
        }else
        {
            m_db->rollback();
        }
    }

    return submitAll;
}

bool BDFacturerUnGroupe::enregistrerReglement()
{
    bool submitAll = true;
    QDateTime now = Horloge::currentDateTime();

    int montantVerse = ui->spinBoxMontantAVerser->value();

    if(montantVerse > 0)
    {
        m_db->transaction();        

        QList<QSqlRecord> occupation_records;
        occupation_records << m_groupe.occupations_des_membres_records();

        // enregistrer les factures et recus
        if(m_groupe.resteFraisLocation() != 0 || m_groupe.resteFraisSup() != 0)
        {
            int montantOccupTotal = 0;
            foreach(QSqlRecord r, occupation_records)
            {
                occupation oc(r);

                // faire les différents réçus
                if(!oc.estReglee() || !oc.fraisSupSontRegles()) // frais location
                {
                    montantOccupTotal += oc.reglerMontantTotal(montantVerse);
                    submitAll = submitAll && oc.enregistrer();
                    if(!submitAll) break;
                }

                m_occupations << oc;
            }

            // faire un réçu de location du groupe
            if(montantOccupTotal > 0 && submitAll)
            {
                submitAll = submitAll && MesTables::enregistrerUneOperationService(  m_agent
                                                                                     , recuInitial::IdLocation
                                                                                     , now
                                                                                     , montantOccupTotal
                                                                                     , QString("Réglement de facture de location (groupe %1)").arg(m_groupe.libelle())
                                                                                     , ui->comboBoxModeDePaye->currentIndex() + 1
                                                                                     , m_groupe.idGroupe()
                                                                                     , groupe().tableName());
            }
        }

        // régler les frais de restauration
        if(montantVerse > 0 && submitAll)
        {
            int montantRestoTotal = 0;
            foreach(QSqlRecord r, occupation_records)
            {
                occupation oc(r);
                QList<QSqlRecord> rcr_records;
                rcr_records = oc.repasConsoNonPayes_record();
                foreach(QSqlRecord r1, rcr_records)
                {
                    repasCompletResto rcr(r1);
                    montantRestoTotal += rcr.reglerMontantTotal(montantVerse);
                    submitAll = submitAll && rcr.enregistrer();
                }
            }

            // faire réçu du groupe à la restauration
            submitAll = submitAll && MesTables::enregistrerUneOperationService(  m_agent
                                                                                 , recuInitial::IdRestauration
                                                                                 , now
                                                                                 , montantRestoTotal
                                                                                 , QString("Réglement de la facture de restauration (groupe %1)").arg(m_groupe.libelle())
                                                                                 , ui->comboBoxModeDePaye->currentIndex() + 1
                                                                                 , m_groupe.idGroupe()
                                                                                 , groupe().tableName());
        }

        // régler les frais de bar
        if(montantVerse > 0 && submitAll)
        {
            int montantBarTotal = 0;
            foreach(QSqlRecord r, occupation_records)
            {
                occupation oc(r);
                QList<QSqlRecord> rcr_records;
                rcr_records = oc.barConsoNonPayes_record();
                foreach(QSqlRecord r1, rcr_records)
                {
                    repasCompletResto rcr(r1);
                    montantBarTotal += rcr.reglerMontantTotal(montantVerse);
                    submitAll = submitAll && rcr.enregistrer();
                }
            }

            // faire réçu du groupe du bar
            submitAll = submitAll && MesTables::enregistrerUneOperationService(  m_agent
                                                                                 , recuInitial::IdBar
                                                                                 , now
                                                                                 , montantBarTotal
                                                                                 , QString("Réglement de la facture de bar (groupe %1)").arg(m_groupe.libelle())
                                                                                 , ui->comboBoxModeDePaye->currentIndex() + 1
                                                                                 , m_groupe.idGroupe()
                                                                                 , groupe().tableName());
        }

        if(submitAll)
        {
            m_groupe.actualiser(); // actualiser le groupe
            m_db->commit();
        }else
        {
            m_db->rollback();
        }
    }

    return submitAll;
}

void BDFacturerUnGroupe::on_btn_detailsBar_clicked()
{
    factureBarGroupe * facture = new factureBarGroupe(m_groupe);

    // impression
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    QPrintDialog printDialog(&printer, this);

    // éventuelle pensée
    if(printDialog.exec() == QDialog::Accepted)
    {
        QPainter painter(&printer);

        // print, fitting the viewport contents into a full page
        facture->view()->render(&painter);
    }

    delete facture;
}
