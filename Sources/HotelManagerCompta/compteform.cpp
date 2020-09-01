#include "compteform.h"
#include "ui_compteform.h"

CompteForm::CompteForm(BDD *db, int numCompte, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompteForm)
{
    ui->setupUi(this);
    m_db = db;
    m_numeroCompte = numCompte;

    initialiserTableau();

    // sélectionner la période d'aujourd'hui
    QString now = Horloge::currentDate().toString(Qt::SystemLocaleLongDate);
    ui->lineEditDebut->setText(now);
    ui->lineEditFin->setText(now);

    // afficher les opérations d'aujourd'hui
    ui->rb_periode2->setChecked(true);

    connect(ui->tableView->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this
            , SLOT(preparerEtLancerRowIsValid(QModelIndex)));

    ui->btn_afficherOp->setEnabled(false);
}

CompteForm::~CompteForm()
{
    delete ui;
    delete m_operationsMdodel;
}

void CompteForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void CompteForm::closeEvent(QCloseEvent *e)
{
    QWidget::closeEvent(e);
    emit opened(false);
}

void CompteForm::on_btn_debut_clicked()
{
    DialogCalendar bd(this);
    bd.setWindowTitle("Date de début");
    if(bd.exec()== QDialog::Accepted)
    {
        ui->lineEditDebut->setText(bd.dateSeclectionnee().toString(Qt::SystemLocaleLongDate));

        // si fin est vide
        if(ui->lineEditFin->text().isEmpty())
            ui->lineEditFin->setText(ui->lineEditDebut->text());

        // si debut > fin
        if(bd.dateSeclectionnee() > QDate::fromString(ui->lineEditFin->text(), Qt::SystemLocaleLongDate))
        {
            ui->lineEditFin->setText(ui->lineEditDebut->text());  // ramener fin à début
        }

        chargerOperations(ui->lineEditDebut->text(), ui->lineEditFin->text());
    }
}

void CompteForm::on_btn_fin_clicked()
{
    DialogCalendar bd(this);
    bd.setWindowTitle("Date de début");
    if(bd.exec()== QDialog::Accepted)
    {
        if(bd.dateSeclectionnee() < QDate::fromString(ui->lineEditDebut->text(), Qt::SystemLocaleLongDate))
        {
            ui->lineEditFin->setText(ui->lineEditDebut->text()); // ramener fin à début
        }else
        {
            ui->lineEditFin->setText(bd.dateSeclectionnee().toString(Qt::SystemLocaleLongDate));
        }

        chargerOperations(ui->lineEditDebut->text(), ui->lineEditFin->text());
    }
}

void CompteForm::on_rb_periode1_clicked()
{
    setPeriode2Enabled(false);
}

void CompteForm::on_rb_periode2_clicked()
{
    setPeriode2Enabled(true);
}

void CompteForm::setPeriode2Enabled(bool enabled)
{
    ui->btn_debut->setEnabled(enabled);
    ui->lineEditDebut->setEnabled(enabled);

    ui->btn_fin->setEnabled(enabled);
    ui->lineEditFin->setEnabled(enabled);
}

void CompteForm::on_rb_periode1_toggled(bool checked)
{
    if(checked)
    {
        // afficher toutes les opérations
        chargerOperations();
    }
}

void CompteForm::on_rb_periode2_toggled(bool checked)
{
    if(checked)
    {
        // afficher sur une période
        chargerOperations(ui->lineEditDebut->text(), ui->lineEditFin->text());
    }
}

void CompteForm::chargerOperations()
{
    if(ui->rb_periode1->isChecked())
    {
        QDate now = Horloge::currentDate();
        int year = now.year();

        QDate dateDebut(year, 1, 1);
        QDate dateFin(year, 12, 31);

        operationsComptables opc;
        m_operationsMdodel->setFilter(tr("%1 = %2 AND %3 = %4 AND (%5 BETWEEN '%6' AND '%7')")
                                      .arg(opc.numCptName())
                                      .arg(m_numeroCompte)
                                      .arg(opc.supprimeName())
                                      .arg(false)
                                      .arg(opc.dateName())
                                      .arg(dateDebut.toString(Qt::ISODate))
                                      .arg(dateFin.toString(Qt::ISODate)));
        m_operationsMdodel->select();
        ui->tableView->resizeColumnToContents(OperationsComptables::Id::Description);

        double debit = operationsComptables::debitAnnuel(m_numeroCompte, year);
        double credit = operationsComptables::creditAnnuel(m_numeroCompte, year);
        double solde = credit - debit;

        ui->lineEditDebit->setText(MesTables::doubleToAllMoney(debit));
        ui->lineEditCredit->setText(MesTables::doubleToAllMoney(credit));
        ui->lineEditSolde->setText(MesTables::doubleToAllMoney(solde));

    }else
    {
        chargerOperations(ui->lineEditDebut->text(), ui->lineEditFin->text());
    }

}

void CompteForm::chargerOperations(QString debut, QString fin)
{
    debut = QDate::fromString(debut, Qt::SystemLocaleLongDate).toString(Qt::ISODate);
    fin = QDate::fromString(fin, Qt::SystemLocaleLongDate).toString(Qt::ISODate);

    operationsComptables opc;
    QString condition = QObject::tr("%1 = %2 AND (DATE(%3) BETWEEN '%4' AND '%5') AND %6 = %7")
                        .arg(opc.numCptName())
                        .arg(m_numeroCompte)
                        .arg(operationsComptables().dateName())
                        .arg(debut)
                        .arg(fin)
                        .arg(opc.supprimeName())
                        .arg(false);

    m_operationsMdodel->setFilter(condition);
    m_operationsMdodel->select();
    ui->tableView->resizeColumnToContents(OperationsComptables::Id::Description);

    QDate deb = QDate::fromString(debut, Qt::ISODate);
    QDate fi = QDate::fromString(fin, Qt::ISODate);
    double debit = operationsComptables::debit(m_numeroCompte, deb, fi);
    double credit = operationsComptables::credit(m_numeroCompte, deb, fi);

    ui->lineEditDebit->setText(MesTables::doubleToAllMoney(debit));
    ui->lineEditCredit->setText(MesTables::doubleToAllMoney(credit));
    ui->lineEditSolde->setText(MesTables::doubleToAllMoney(debit - credit));
}

void CompteForm::initialiserTableau()
{
    // initialisation du model
    m_operationsMdodel = new QSqlTableModel();
    m_operationsMdodel->setTable(OperationsComptables::Libelle);
    m_operationsMdodel->sort(OperationsComptables::Id::Date, Qt::AscendingOrder);
    m_operationsMdodel->setHeaderData(OperationsComptables::Id::NumeroOpc, Qt::Horizontal, tr("N° de l'opération"));
    m_operationsMdodel->setHeaderData(OperationsComptables::Id::Date, Qt::Horizontal, tr("Date"));
    m_operationsMdodel->setHeaderData(OperationsComptables::Id::Description, Qt::Horizontal, tr("Description de l'opération"));
    m_operationsMdodel->setHeaderData(OperationsComptables::Id::Debit, Qt::Horizontal, tr("Débit"));
    m_operationsMdodel->setHeaderData(OperationsComptables::Id::Credit, Qt::Horizontal, tr("Crédit"));
    m_operationsMdodel->setHeaderData(OperationsComptables::Id::MatriculeAgent, Qt::Horizontal, tr("Matricule de l'agent"));

    // initialisation du tableau
    ui->tableView->setModel(m_operationsMdodel);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(OperationsComptables::Id::IdOpc, true);
    ui->tableView->setColumnHidden(OperationsComptables::Id::NumeroCpt, true);
    ui->tableView->setColumnHidden(OperationsComptables::Id::EnDiffere, true);
    ui->tableView->setColumnHidden(OperationsComptables::Id::Supprime, true);
}

int CompteForm::numeroOperationCourante()const
{
    int currentRow = ui->tableView->currentIndex().row();

    operationsComptables opc(m_operationsMdodel->record(currentRow));
    return opc.numOperation();
}

void CompteForm::supprimerOperationCourante()
{
    int numOp = numeroOperationCourante();

    if(QMessageBox::question(this
                             , "Supprimer une opération"
                             , tr("Désirez-vous supprimer l'ensemble des mouvements enregistrés sous le nom d'opération N° %1?").arg(numOp)
                             , "Oui"
                             , "Non") == 0)
    {
        m_db->transaction();
        bool submitAll = true;
        submitAll = submitAll && MesTables::supprimerUneOperationComptable(numOp);

        if(submitAll)
        {
            m_db->commit();
            QMessageBox::information(this, "Supprimer une opération", "La suppression s'est déroulée avec succès!");
        }else
        {
            m_db->rollback();
        }
    }
}

void CompteForm::preparerEtLancerRowIsValid(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_afficherOp->setEnabled(true);
        emit currentRowIsValid(true);
    }else
    {
        ui->btn_afficherOp->setEnabled(false);
        emit currentRowIsValid(false);
    }
}

void CompteForm::on_btn_afficherOp_clicked()
{
    int currentRow = ui->tableView->currentIndex().row();
    int numOp = operationsComptables(m_operationsMdodel->record(currentRow)).numOperation();

    BDExecuterNlleOperation bd(m_db, "COMPTA", this, true, numOp);
    bd.setWindowTitle(tr("Affichage complet de l'opération N° %1").arg(numOp));
    bd.exec();
}
