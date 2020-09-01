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
    // rechercher les comptes selon les crit�res sp�cifi�s
    chargerMesComptes(true);
}

void BDConfigCpt::on_rb_cpt_a_creer_clicked()
{
    // rechercher les comptes selon les crit�res sp�cifi�s
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

    // mettre � jour l'�tat des boutons et radios
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

    // examinons tous les parents possibles (au plus 1 utilis�)
    QList<QSqlRecord> parents;
    parents << planComptable::pc_all_parents_records(true, numero);

    if(!parents.isEmpty())
    {
        if(QMessageBox::information(this
                                 , "Cr�ation d'un compte"
                                 , "Ce compte poss�de d�j� un compte parent cr��. Cette op�ration supprimera le compte parent et transf�rera toutes les donn�es �ventuelles dans le compte en cours de cr�ation. \n\n D�sirez-vous continuer ? "
                                 , "Abandonner", "Continuer") == 1)
        {
            // transfert des donn�es
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

    if(!test1Positif) // car les deux tests ne peuvent �tre positifs
    {
        // examinons tous les enfants possibles
        QList<QSqlRecord> enfants;
        enfants << planComptable::pc_all_childs_records(classe, true, numero);

        if(!enfants.isEmpty())
        {
            // il existe un ou plusieurs sous-comptes.
            // avertir qu'il existe au moins un sous-compte et
            // proposer de transf�rer toutes les donn�es �ventuelles dans le compte parent.
            if(QMessageBox::information(this
                                     , "Cr�ation d'un compte"
                                     , "Ce compte poss�de d�j� un ou plusieurs sous-comptes cr��s. Cette op�ration supprimera tous les sous-comptes et transf�rera toutes les donn�es �ventuelles dans le compte en cours de cr�ation. \n\n D�sirez-vous continuer ? "
                                     , "Abandonner", "Continuer") == 1)
            {
                // transfert des donn�es
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
                                 , tr("Le compte N� %1 ne peut �tre supprim� car il contient actuellement des enregistrements. \n\n Veuillez d'abord sauvegarder ou supprimer ces donn�es.").arg(numero));
        return;
    }

    p.setUtilise(false);
    p.enregistrer();

    // supprimer le compte dans les comptes associ�s aux services
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
