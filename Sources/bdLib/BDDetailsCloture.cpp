#include "BDDetailsCloture.h"
#include "ui_BDDetailsCloture.h"

BDDetailsCloture::BDDetailsCloture(int idCloture, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDDetailsCloture)
{
    ui->setupUi(this);

    m_idCloture = idCloture;
    initialiserTableauActivites();
    chargerActivites();
}

BDDetailsCloture::~BDDetailsCloture()
{
    delete ui;
    delete m_modelActivites;
}

void BDDetailsCloture::changeEvent(QEvent *e)
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

void BDDetailsCloture::on_btn_fermer_clicked()
{
    close();
}

void BDDetailsCloture::chargerActivites()
{
    m_modelActivites->select();
    ui->tableViewActivites->resizeColumnToContents(OperationService::Id::Libelle);
}

void BDDetailsCloture::initialiserTableauActivites()
{
    m_modelActivites = new QSqlRelationalTableModel();
    m_modelActivites->setTable(OperationService::Libelle);

    operationService os;
    QString condition = QObject::tr("%1 = %2")
                        .arg(os.idClotureServiceName())
                        .arg(m_idCloture);

    m_modelActivites->setFilter(condition);

    ui->tableViewActivites->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewActivites->setModel(m_modelActivites);

    ui->tableViewActivites->setColumnHidden(OperationService::Id::IdOperationService, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::Cloturee, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::MatriculeAgent, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::IdTypeOperation, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::IdTypeRecu, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::IdClotureService, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::Depouille, true);
    ui->tableViewActivites->setColumnHidden(OperationService::Id::EstUneEntree, true);
    ui->tableViewActivites->sortByColumn(OperationService::Id::Date, Qt::AscendingOrder);

    m_modelActivites->setHeaderData(OperationService::Id::Recu, Qt::Horizontal, "Reçu");
    m_modelActivites->setHeaderData(OperationService::Id::Date, Qt::Horizontal, "Date");
    m_modelActivites->setHeaderData(OperationService::Id::Libelle, Qt::Horizontal, "Libellé");
    m_modelActivites->setHeaderData(OperationService::Id::MontantEncaisse, Qt::Horizontal, "Montant encaissé");

    // faire une relation
    modeDePayement mp;
    m_modelActivites->setRelation(OperationService::Id::IdModeDePayement
                                  , QSqlRelation(mp.tableName(), mp.idModeDePayementName(), mp.modeName()));

    m_modelActivites->setHeaderData(OperationService::Id::IdModeDePayement, Qt::Horizontal, "Mode de payement");
}
