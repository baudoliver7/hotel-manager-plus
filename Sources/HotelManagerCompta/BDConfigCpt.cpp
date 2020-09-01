#include "BDConfigCpt.h"
#include "ui_BDConfigCpt.h"

BDConfigCpt::BDConfigCpt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDConfigCpt)
{
    ui->setupUi(this);

    m_modifie = false;
    ui->rb_cpt_existant->setChecked(true);
    on_rb_cpt_existant_clicked();
}

BDConfigCpt::~BDConfigCpt()
{
    delete ui;
}

void BDConfigCpt::changeEvent(QEvent *e)
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

void BDConfigCpt::on_btn_fermer_clicked()
{
    close();
}
void BDConfigCpt::on_rb_cpt_existant_clicked()
{
    // rechercher les comptes selon les critères spécifiés
    chargerMesComptes(true);
}

void BDConfigCpt::on_rb_cpt_a_creer_clicked()
{
    // rechercher les comptes selon les critères spécifiés
    chargerMesComptes(false);
}

void BDConfigCpt::chargerMesComptes(bool utilises)
{
    setEnabled(false);
    QList<QSqlRecord> records;
    records << planComptable::pc_records(ui->comboBoxClasse->currentText().toInt()
                                         , utilises
                                         , ui->comboBoxNbChiffre->currentText().toInt());

    QStringList libelles;
    foreach(QSqlRecord record, records)
    {
        planComptable p(record);
        libelles << QObject::tr("%1 %2").arg(p.numCpt()).arg(p.libelle());
    }

    ui->comboBoxLibelle->clear();
    ui->comboBoxLibelle->addItems(libelles);

    // mettre à jour l'état des boutons et radios
    if(ui->comboBoxLibelle->currentText().isEmpty())
    {
        ui->btn_creer->setEnabled(false);
        ui->btn_supprimer->setEnabled(false);
    }else
    {
        ui->btn_creer->setEnabled(ui->rb_cpt_a_creer->isChecked());
        ui->btn_supprimer->setEnabled(ui->rb_cpt_existant->isChecked());
    }
    setEnabled(true);
}

void BDConfigCpt::on_comboBoxClasse_currentIndexChanged(QString )
{
    chargerMesComptes(ui->rb_cpt_existant->isChecked());
}

void BDConfigCpt::on_comboBoxNbChiffre_currentIndexChanged(QString )
{
    chargerMesComptes(ui->rb_cpt_existant->isChecked());
}

void BDConfigCpt::on_btn_creer_clicked()
{
    int classe = ui->comboBoxClasse->currentText().toInt();
    int numero = QString(ui->comboBoxLibelle->currentText().split(" ").first()).toInt();
    QString numCptName = InfosSurBD::fieldsNames(OperationsComptables::Libelle).at(OperationsComptables::Id::NumeroCpt);

    bool test1Positif = false;

    // examinons tous les parents possibles (au plus 1 utilisé)
    QList<QSqlRecord> parents;
    parents << planComptable::pc_all_parents_records(true, numero);

    if(!parents.isEmpty())
    {
        if(QMessageBox::information(this
                                 , "Création d'un compte"
                                 , "Ce compte possède déjà un compte parent créé. Cette opération supprimera le compte parent et transférera toutes les données éventuelles dans le compte en cours de création. \n\n Désirez-vous continuer ? "
                                 , "Abandonner", "Continuer") == 1)
        {
            // transfert des données
            planComptable parent(parents.first());

            QList<QSqlRecord> operations;
            operations << InfosSurBD::enregistrements(OperationsComptables::Libelle, tr("%1 = %2").arg(numCptName).arg(parent.numCpt()));
            foreach(QSqlRecord operation, operations)
            {
                operationsComptables op(operation);
                op.setNumeroCpt(numero);
                op.enregistrer();
            }

            // supprimer le compte parent
            parent.setUtilise(false);
            parent.enregistrer();

            test1Positif = true;
        }else
        {
            return;
        }
    }

    if(!test1Positif) // car les deux tests ne peuvent être positifs
    {
        // examinons tous les enfants possibles
        QList<QSqlRecord> enfants;
        enfants << planComptable::pc_all_childs_records(classe, true, numero);

        if(!enfants.isEmpty())
        {
            // il existe un ou plusieurs sous-comptes.
            // avertir qu'il existe au moins un sous-compte et
            // proposer de transférer toutes les données éventuelles dans le compte parent.
            if(QMessageBox::information(this
                                     , "Création d'un compte"
                                     , "Ce compte possède déjà un ou plusieurs sous-comptes créés. Cette opération supprimera tous les sous-comptes et transférera toutes les données éventuelles dans le compte en cours de création. \n\n Désirez-vous continuer ? "
                                     , "Abandonner", "Continuer") == 1)
            {
                // transfert des données
                foreach(QSqlRecord es, enfants)
                {
                    planComptable enfant(es);

                    QList<QSqlRecord> operations;
                    operations << InfosSurBD::enregistrements(OperationsComptables::Libelle, tr("%1 = %2").arg(numCptName).arg(enfant.numCpt()));
                    foreach(QSqlRecord operation, operations)
                    {
                        operationsComptables op(operation);
                        op.setNumeroCpt(numero);
                        op.enregistrer();
                    }

                    // supprimer le compte enfant
                    enfant.setUtilise(false);
                    enfant.enregistrer();
                }
            }else
            {
                return;
            }
        }
    }

    // activer le compte
    planComptable p(numero);
    p.setUtilise(true);
    p.enregistrer();

    m_modifie = true;
    chargerMesComptes(false);
}

void BDConfigCpt::on_btn_supprimer_clicked()
{
    int numero = QString(ui->comboBoxLibelle->currentText().split(" ").first()).toInt();
    planComptable p(numero);

    QString condition = tr("%1 = %2")
                        .arg(operationsComptables().numCptName())
                        .arg(numero);

    if(!InfosSurBD::enregistrements(OperationsComptables::Libelle, condition).isEmpty())
    {
        QMessageBox::information(this
                                 , "Suppression d'un compte"
                                 , tr("Le compte N° %1 ne peut être supprimé car il contient actuellement des enregistrements. \n\n Veuillez d'abord sauvegarder ou supprimer ces données.").arg(numero));
        return;
    }

    p.setUtilise(false);
    p.enregistrer();

    // supprimer le compte dans les comptes associés aux services
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ConfigServiceCompta::Libelle, tr("%1 = %2")
                                                                         .arg(configServiceCompta().compteAssocieName())
                                                                         .arg(p.numCpt()));

    foreach(QSqlRecord r, records)
    {
        configServiceCompta cfc(r);
        cfc.setCompteAssocie(0);
    }

    m_modifie = true;
    chargerMesComptes(true);
}
