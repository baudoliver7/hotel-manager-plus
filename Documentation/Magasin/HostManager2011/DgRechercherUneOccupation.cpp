#include "DgRechercherUneOccupation.h"
#include "ui_DgRechercherUneOccupation.h"

DgRechercherUneOccupation::DgRechercherUneOccupation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DgRechercherUneOccupation)
{

    ui->setupUi(this);
    ui->btn_liberer->setEnabled(false);

    initialiserTypeDeChambre();
    initialiserTable();

    rafraichirTable();
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
    ui->typesDeChambre->addItems(initialDeChambre::tousLesTypes());

    connect(ui->typesDeChambre, SIGNAL(currentIndexChanged(int)), this, SLOT(rafraichirTable()));
}

void DgRechercherUneOccupation::rafraichirTable()
{
    ui->tableWidget->setRowCount(0);

    QList<QSqlRecord> occupations;
    occupations << occupation::occupationsEnCours(ui->typesDeChambre->currentText());

    for(int i = 0; i < occupations.count(); i++)
    {
        occupation oc(occupations.at(i));

        ui->tableWidget->setRowCount(i+1);
        afficherElement(i, NUMERO_RESERV, QString::number(oc.numOccupation()));
        afficherElement(i, CHAMBRE, oc.chambreOccupee());
        afficherElement(i, DATE_ENTREE, oc.datedEntree().toString(Qt::SystemLocaleLongDate));
        afficherElement(i, DUREE_EN_JOURS, QString::number(oc.dureeOccupation()));
        afficherElement(i, DATE_SORTIE, oc.datedSortie().toString(Qt::SystemLocaleLongDate));

        client cl(oc.codeOccupant());
        QString nomComplet = tr("%1 %2").arg(cl.nom()).arg(cl.prenoms());
        afficherElement(i, OCCUPANT, nomComplet);
    }
}

void DgRechercherUneOccupation::afficherElement(int row, int column, const QString &value)
{
    QTableWidgetItem * item = new QTableWidgetItem(value);

    ui->tableWidget->setItem(row, column, item);
}

void DgRechercherUneOccupation::initialiserTable()
{
    connect(ui->tableWidget->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(updateEtatBtnLiberer(QModelIndex)));

    ui->tableWidget->setColumnHidden(NUMERO_RESERV, true);
    ui->tableWidget->sortItems(CHAMBRE, Qt::AscendingOrder);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DgRechercherUneOccupation::updateEtatBtnLiberer(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_liberer->setEnabled(true);
    }else
    {
        ui->btn_liberer->setEnabled(false);
    }
}

void DgRechercherUneOccupation::liberer()
{
    int currentRow = ui->tableWidget->currentRow();
    int numOccupation = ui->tableWidget->item(currentRow, NUMERO_RESERV)->text().toInt();

    occupation oc(numOccupation);

    if(QMessageBox::question(this, tr("Libérer la chambre %1").arg(oc.chambreOccupee()),
                             "Désirez-vous mettre fin à l'occupation en cours?", "Oui", "Non")==0)
    {
        oc.setDateFinOccupation(QDateTime::currentDateTime());
        oc.enregistrer();

        ui->tableWidget->removeRow(currentRow);
    }
}
