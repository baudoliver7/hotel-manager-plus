#include "BDExecuterNlleOperation.h"
#include "ui_BDExecuterNlleOperation.h"

BDExecuterNlleOperation::BDExecuterNlleOperation(BDD *db, QString matriculeAgent, QWidget *parent, bool afficher, int numOp) :
    QDialog(parent),
    ui(new Ui::BDExecuterNlleOperation)
{
    ui->setupUi(this);

    m_db = db;
    m_matricule = matriculeAgent;
    initialiserTableau();

    if(afficher)
    {
        ui->groupBoxDate->setVisible(false);
        ui->splitter->setVisible(false);
        ui->btn_executer->setVisible(false);
        ui->lineEditDescription->setReadOnly(true);
        this->afficher(numOp);
    }else
    {
        connect(ui->tableWidgetOperation->selectionModel()
                , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
                , this
                , SLOT(updateEtatBtnSuprEtEditer()));

        updateEtatBtnSuprEtEditer();

        ui->rb_enLive->setChecked(true);
        on_rb_enLive_clicked();

        ui->lineEditDate->setText(Horloge::currentDate().addDays(-1).toString(Qt::SystemLocaleLongDate));
    }
}

BDExecuterNlleOperation::~BDExecuterNlleOperation()
{
    delete ui;

}

void BDExecuterNlleOperation::changeEvent(QEvent *e)
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

void BDExecuterNlleOperation::on_btn_annuler_clicked()
{
    reject();
}

void BDExecuterNlleOperation::on_btn_mvtCrediteur_clicked()
{
    newEditerUnMvt(false, "Créditer un compte");
}

void BDExecuterNlleOperation::on_btn_mvtDebiteur_clicked()
{
    newEditerUnMvt(true, "Débiter un compte");
}

void BDExecuterNlleOperation::newEditerUnMvt(bool debiteur, QString title)
{
    BDEditerUnMvt bd(debiteur, false, this);
    bd.setWindowTitle(title);

    if(bd.exec() == QDialog::Accepted)
    {
        // vérifier qu'un mvt n'a pas eu lieu sur ce compte
        bool existe = false;
        for(int i = 0; i < ui->tableWidgetOperation->rowCount(); i++)
        {
            if(numCpt(i) ==  bd.numCpt())
            {
                existe = true;
                break;
            }
        }

        if(existe)
        {
            QMessageBox::information(this
                                     , tr("Mouvement sur le compte N° %1").arg(bd.numCpt())
                                     , tr("Un mouvement a déjà eu lieu sur le compte N° %1. \n\nVous ne pouvez qu'éditer ce mouvement pour d'éventuelles modifications ou le supprimer.").arg(bd.numCpt()));
            return;
        }

        // afficher dans le tableau
        ajouterUneLigne(bd.numCpt(), bd.libelle(), bd.montant(), bd.debiteur());
    }
}

void BDExecuterNlleOperation::modifierUnMvt(int row)
{
    BDEditerUnMvt bd(debiteur(row), true, this, libelleComplet(row), montant(row));
    bd.setWindowTitle("Editer un mouvement");

    if((bd.exec() == QDialog::Accepted) && bd.modified())
    {
        // afficher dans le tableau
        afficherUneLigne(row, bd.numCpt(), bd.libelle(), bd.montant(), bd.debiteur());
    }
}

void BDExecuterNlleOperation::initialiserTableau()
{
    ui->tableWidgetOperation->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void BDExecuterNlleOperation::afficherUnElt(int row, int col, QString value)
{
    QTableWidgetItem * item = new QTableWidgetItem(value);

    item->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetOperation->setItem(row, col, item);
}

void BDExecuterNlleOperation::afficherUneLigne(int row, int numCpt, QString libelle, int montant, bool debiter)
{
    if(debiter)
    {
        afficherUnElt(row, 0, QString::number(numCpt));
        afficherUnElt(row, 3, QString::number(montant));
        afficherUnElt(row, 4, QString::number(0));
    }else
    {
        afficherUnElt(row, 1, QString::number(numCpt));
        afficherUnElt(row, 4, QString::number(montant));
        afficherUnElt(row, 3, QString::number(0));
    }

    afficherUnElt(row, 2, libelle); 
}

void BDExecuterNlleOperation::ajouterUneLigne(int numCpt, QString libelle, int montant, bool debiter)
{
    int row = ui->tableWidgetOperation->rowCount();
    ui->tableWidgetOperation->setRowCount(row + 1);

    afficherUneLigne(row, numCpt, libelle, montant, debiter);
}

void BDExecuterNlleOperation::supprimerUneLigne(int row)
{
    ui->tableWidgetOperation->removeRow(row);
}

void BDExecuterNlleOperation::on_btn_supprimerMvt_clicked()
{
    int row = ui->tableWidgetOperation->currentRow();

    if(QMessageBox::information(this
                             , "Supprimer un mouvement"
                             , tr("Désirez-vous supprimer le mouvement en cours sur le compte N° %1 ?").arg(numCpt(row))
                             , "Oui"
                             , "Non") == 0)
    {
        supprimerUneLigne(row);
    }
}

void BDExecuterNlleOperation::on_btn_editer_clicked()
{
    int row =  ui->tableWidgetOperation->currentRow();

    modifierUnMvt(row);
}

int BDExecuterNlleOperation::montant(int row)
{
    if(debiteur(row))
        return ui->tableWidgetOperation->item(row, 3)->text().toInt();
    else
        return ui->tableWidgetOperation->item(row, 4)->text().toInt();
}

int BDExecuterNlleOperation::numCpt(int row)
{
    if(debiteur(row))
        return ui->tableWidgetOperation->item(row, 0)->text().toInt();
    else
        return ui->tableWidgetOperation->item(row, 1)->text().toInt();
}

bool BDExecuterNlleOperation::debiteur(int row)
{
    if(ui->tableWidgetOperation->item(row, 0)) // pointeur existe
        return true;
    else
        return false;
}

void BDExecuterNlleOperation::updateEtatBtnSuprEtEditer()
{
    if(ui->tableWidgetOperation->currentIndex().isValid())
    {
        ui->btn_editer->setEnabled(true);
        ui->btn_supprimerMvt->setEnabled(true);
    }else
    {
        ui->btn_editer->setEnabled(false);
        ui->btn_supprimerMvt->setEnabled(false);
    }
}

QString BDExecuterNlleOperation::libelle(int row)
{
    return ui->tableWidgetOperation->item(row, 2)->text();
}

QString BDExecuterNlleOperation::libelleComplet(int row)
{
    return tr("%1 %2").arg(numCpt(row)).arg(libelle(row));
}

void BDExecuterNlleOperation::on_btn_executer_clicked()
{
    // vérifier qu'au moins deux mouvements ont été effectués
    if(ui->tableWidgetOperation->rowCount() < 2)
    {
        QMessageBox::information(this
                                 , "Erreur de comptabilité"
                                 , "L'opération doit se faire au moins entre deux (2) comptes!");
        return;
    }

    // vérifier que debit = credit
    int debit = 0;
    int credit = 0;

    for(int i = 0; i < ui->tableWidgetOperation->rowCount(); i++)
    {
        debit += ui->tableWidgetOperation->item(i, 3)->text().toInt();
        credit += ui->tableWidgetOperation->item(i, 4)->text().toInt();
    }

    if(debit != credit)
    {
        QMessageBox::information(this
                                 , "Erreur de comptabilité"
                                 , tr("Le débit total doit être égal au crédit total! \n\n Débit total actuel = %1 \n\n Crédit total actuel = %2").arg(debit).arg(credit));
        return;
    }

    m_db->transaction();
    bool submitAll = true;

    // enregistrement des mouvements
    QList<int> numCpts;
    QList<int> montants;
    QList<bool> debiteurs;

    for(int i = 0; i < ui->tableWidgetOperation->rowCount(); i++)
    {
        numCpts << numCpt(i);
        debiteurs << debiteur(i);
        montants << montant(i);
    }

    QDate date;
    if(ui->rb_enLive->isChecked())
        date = Horloge::currentDate();
    else
    {
        date = QDate::fromString(ui->lineEditDate->text(), Qt::SystemLocaleLongDate);
    }

    if(!MesTables::enregistrerUneOperationComptable( date
                                                    ,numCpts
                                                    , ui->lineEditDescription->text()
                                                    , debiteurs
                                                    , montants
                                                    , m_matricule
                                                    , ui->rb_enDiffere->isChecked()))
    {
        QMessageBox::warning(this, "Erreur d'enregistrement", "Toute l'opération n'a pas pu être effectuée!");
        submitAll = false;

        m_db->rollback();
        return;
    }

    m_db->commit();
    QMessageBox::information(this, "Exécution de l'opération paramétrée", "L'exécution de l'opération s'est déroulée avec succès!");

    accept();
}

void BDExecuterNlleOperation::on_rb_enLive_clicked()
{
    ui->lineEditDate->setEnabled(false);
    ui->btn_calendrier->setEnabled(false);
}

void BDExecuterNlleOperation::on_rb_enDiffere_clicked()
{
    ui->lineEditDate->setEnabled(true);
    ui->btn_calendrier->setEnabled(true);
}

void BDExecuterNlleOperation::on_btn_calendrier_clicked()
{
    DialogCalendar bd(this);
    bd.setWindowTitle("Date d'enregistrement");

    if((bd.exec() == QDialog::Accepted))
    {
        if((bd.dateSeclectionnee() < Horloge::currentDate()))
        {
           ui->lineEditDate->setText(bd.dateSeclectionnee().toString(Qt::SystemLocaleLongDate));
        }else
        {
            QMessageBox::information(this, "Date érronée", "Cette date est érronée pour ce champ! \n\n Sélectionnez une date passée.");
        }
    }
}

void BDExecuterNlleOperation::afficher(int numOp)
{
    QList<QSqlRecord> records;
    records << operationsComptables::operationsComptables_record(numOp);

    QString description = operationsComptables(records.first()).description();
    ui->lineEditDescription->setText(description);

    QList<operationsComptables> opCredits;
    foreach(QSqlRecord r, records)
    {
        operationsComptables op(r);
        if(op.debit() != 0)
        {
            ajouterUneLigne(op.numeroCpt(), planComptable(op.numeroCpt()).libellePerso(), op.debit(), true);
        }else
        {
            opCredits << op;
        }
    }

    for(int i = 0; i < opCredits.count(); i++)
    {
        operationsComptables op = opCredits.at(i);
        ajouterUneLigne(op.numeroCpt(), planComptable(op.numeroCpt()).libelle(), op.credit(), false);
    }
}
