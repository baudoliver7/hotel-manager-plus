#include "DgRechercherUneReserv.h"
#include "ui_DgRechercherUneReserv.h"

DgRechercherUneReserv::DgRechercherUneReserv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DgRechercherUneReserv)
{
    ui->setupUi(this);

    ui->btn_executer->setEnabled(false);
    ui->btn_supprimer
            ->setEnabled(false);

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
    ui->typesDeChambre->addItems(initialDeChambre::tousLesTypes());

    connect(ui->typesDeChambre, SIGNAL(currentIndexChanged(int)), this, SLOT(rafraichirTable()));
}

void DgRechercherUneReserv::rafraichirTable()
{
    ui->tableWidget->setRowCount(0);

    QList<QSqlRecord> reservations;
    reservations << reservation::reservationsEnCours(ui->typesDeChambre->currentText());

    for(int i = 0; i < reservations.count(); i++)
    {
        reservation rv(reservations.at(i));

        if(ui->Aujourd_hui->isChecked() && rv.datedEntree()!=QDate::currentDate()) // rv pour aujourdui
        {
            // ne rien faire
        }else
        {
            ui->tableWidget->setRowCount(i+1);
            afficherElement(i, NUMERO_RESERV, QString::number(rv.numReservation()));
            afficherElement(i, CHAMBRE, rv.chambreReservee());
            afficherElement(i, DATE_DE_DEMANDE, rv.dateDeDemande().toString(Qt::SystemLocaleLongDate));
            afficherElement(i, DATE_OCCUPATION, rv.datedEntree().toString(Qt::SystemLocaleLongDate));
            afficherElement(i, DUREE_EN_JOURS, QString::number(rv.dureeOccupation()));
            afficherElement(i, DATE_SORTIE, rv.datedSortie().toString(Qt::SystemLocaleLongDate));

            client cl(rv.codeReservant());
            QString nomComplet = tr("%1 %2").arg(cl.nom()).arg(cl.prenoms());
            afficherElement(i, BENEFICIAIRE, nomComplet);
        }
    }
}

void DgRechercherUneReserv::afficherElement(int row, int column, const QString &value)
{
    QTableWidgetItem * item = new QTableWidgetItem(value);

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
    int currentRow = ui->tableWidget->currentRow();
    int numReserv = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

    reservation rv(numReserv);

    if(QMessageBox::question(this, tr("Réservation de la chambre %1").arg(rv.chambreReservee())
                             , "Désirez-vous annuler la réservation en cours?", "Oui", "Non") == 0)
    {
        rv.setAnnuler(true);
        rv.enregistrer();

        ui->tableWidget->removeRow(currentRow);
    }
}

void DgRechercherUneReserv::executer()
{
    int currentRow = ui->tableWidget->currentRow();
    int numReserv = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

    reservation rv(numReserv);

    emit remplirOccupation(rv);

    close();
}

bool DgRechercherUneReserv::reservationPeutEtreExecuter(int row)
{
    int numReserv = ui->tableWidget->item(row, NUMERO_RESERV)->text().toInt();

    reservation rv(numReserv);
    return (!rv.annulee() && rv.datedEntree()== QDate::currentDate());
}
