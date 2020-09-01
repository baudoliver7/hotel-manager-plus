#include "DialogConfigChambre.h"
#include "ui_DialogConfigChambre.h"

DialogConfigChambre::DialogConfigChambre(QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogConfigChambre)
{
    ui->setupUi(this);

    ui->btn_modifier->setEnabled(false);
    ui->btn_supprimer->setEnabled(false);

    this->m_modifie = false;

    this->chargerDansModelChambresDuType(ui->comboBoxTypeTarif->currentText());
    this->chargerTarifsDuType(ui->comboBoxTypeTarif->currentText());
}

DialogConfigChambre::~DialogConfigChambre()
{
    delete ui;
}

void DialogConfigChambre::changeEvent(QEvent *e)
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

void DialogConfigChambre::closeEvent(QCloseEvent *)
{
    // désactiver supprimer et modifier avant la ferméture
    ui->tableView->setCurrentIndex(m_model->index(-1,-1));
}

void DialogConfigChambre::on_btn_fermer_clicked()
{
    this->close();
}

void DialogConfigChambre::afficherToutesLesChambres()
{
    chargerDonneesDansModel();
}

void DialogConfigChambre::initialiserModel()
{
    this->m_model = new QSqlRelationalTableModel(this);
    m_model->setTable(chambre::Libelle);

    // créer une relation
    QSqlTableModel * modelInitialDeChambre = new QSqlTableModel(this);
    modelInitialDeChambre->setTable(InitialDeChambre::Libelle);

    QString typeDeChambre = modelInitialDeChambre->headerData(InitialDeChambre::Id::TypeDeChambre,Qt::Horizontal).toString();
    QString Initial = modelInitialDeChambre->headerData(InitialDeChambre::Id::Initial, Qt::Horizontal).toString();

    m_model->setRelation(chambre::Id::Initial,QSqlRelation(InitialDeChambre::Libelle, Initial, typeDeChambre));

    m_model->setSort(chambre::Id::Identifiant, Qt::AscendingOrder);
    m_model->setHeaderData(chambre::Id::Identifiant, Qt::Horizontal, chambre::Entete::Identifiant);
    m_model->setHeaderData(chambre::Id::Initial, Qt::Horizontal, InitialDeChambre::Entete::TypeDeChambre);

    afficherToutesLesChambres();
}

void DialogConfigChambre::initialiserTableau()
{
    this->initialiserModel();
    ui->tableView->setModel(m_model);

    connect(ui->tableView->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(updateEtatBtnSupprEtModif(QModelIndex)));

    ui->tableView->resizeColumnsToContents();
    ui->tableView->setColumnHidden(chambre::Id::Numero,true);
}

void DialogConfigChambre::chargerDonneesDansModel()
{
    m_model->select();
}

void DialogConfigChambre::on_btn_ajouter_clicked()
{
    this->initialiserBDAjouterUneChambre();
    m_bdAjouterUneChambre->showNormal();
}

void DialogConfigChambre::validerAjout()
{  
    if((this->m_bdAjouterUneChambre->initial() != QString()))
    {
        if(!identifiantExisteDeja(this->m_bdAjouterUneChambre->identifiant()))
        {
            this->enregistrerChambre();
            afficherToutesLesChambres();
            ui->comboBoxTypeTarif->setCurrentIndex(m_bdAjouterUneChambre->idTypeDeChambre());
        }else
        {
            QMessageBox::information(this, "Existence de la chambre", "Cette chambre existe déjà!");
            this->m_bdAjouterUneChambre->showNormal();
        }

    }else
    {
        QMessageBox::information(this, "Identifiant incomplet", "Vous devez fournir un initial!");
        this->m_bdAjouterUneChambre->showNormal();
    }
}

void DialogConfigChambre::validerModification()
{
    if((this->m_bdModifierUneChambre->initial() != QString()))
    {
        if(!this->identifiantExisteDeja(m_bdModifierUneChambre->identifiant()))
        {
            this->modifierChambre(ui->tableView->currentIndex().row());
            afficherToutesLesChambres();
            ui->comboBoxTypeTarif->setCurrentIndex(m_bdModifierUneChambre->idTypeDeChambre());
        }else
        {
            QMessageBox::information(this, "Existence de la chambre", "Cette chambre existe déjà!");
            this->m_bdModifierUneChambre->showNormal();
        }
    }else
    {
        QMessageBox::information(this, "Identifiant incomplet", "Vous devez fournir un initial!");
        this->m_bdModifierUneChambre->showNormal();
    }
}

void DialogConfigChambre::initialiserBDAjouterUneChambre()
{
    this->m_bdAjouterUneChambre = new BDAjouterUneChambre(this);
    connect(m_bdAjouterUneChambre, SIGNAL(accepted()), this, SLOT(validerAjout()));
}

void DialogConfigChambre::initialiserBDModifierUneChambre()
{
    QSqlRecord record = m_model->record(ui->tableView->currentIndex().row());

    this->m_bdModifierUneChambre = new BDModifierUneChambre(record, this);
    connect(m_bdModifierUneChambre, SIGNAL(accepted()), this, SLOT(validerModification()));
}

bool DialogConfigChambre::identifiantExisteDeja(QString identifiant)
{
    QSqlTableModel model;
    model.setTable(chambre::Libelle);
    model.setFilter( model.record().fieldName(chambre::Id::Identifiant)+ "= '" + identifiant + "'");
    model.select();

    return (model.rowCount()!=0);
}


void DialogConfigChambre::on_tableView_clicked(QModelIndex index)
{
//        if(index.isValid())
//        {
//            ui->btn_supprimer->setEnabled(true);
//            ui->btn_modifier->setEnabled(true);
//        }else
//        {
//            ui->btn_supprimer->setEnabled(false);
//            ui->btn_modifier->setEnabled(false);
//        }
}

void DialogConfigChambre::on_tableView_activated(QModelIndex index)
{


}

void DialogConfigChambre::on_tableView_viewportEntered()
{

}

void DialogConfigChambre::on_btn_supprimer_clicked()
{
    if(QMessageBox::question(this, "Confirmation de suppression","Voulez-vous vraiment supprimer la chambre selectionnée ?",
                             QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Ok)
    {
        m_model->removeRow(ui->tableView->currentIndex().row());
    }
}

void DialogConfigChambre::updateEtatBtnSupprEtModif(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_supprimer->setEnabled(true);
        ui->btn_modifier->setEnabled(true);
    }else
    {
        ui->btn_supprimer->setEnabled(false);
        ui->btn_modifier->setEnabled(false);
    }
}


void DialogConfigChambre::on_btn_modifier_clicked()
{
    this->initialiserBDModifierUneChambre();
    this->m_bdModifierUneChambre->showNormal();
}

bool DialogConfigChambre::identifiantExisteDejaModif(QString identifiant)
{

    QSqlTableModel model;
    model.setTable(chambre::Libelle);
    model.setFilter( model.record().fieldName(chambre::Id::Identifiant)+ "= '" + identifiant + "'");
    model.select();

    if(model.rowCount() == 0)
    {
        return false;
    }else
    {
        // il ya un seul enregistrement
        for(int i = 0; i < m_model->rowCount() ; i++)
        {
            if(identifiant == m_model->record(i).value(chambre::Id::Identifiant).toString())
            {
                if(i != ui->tableView->currentIndex().row())
                {
                    return true;
                }
            }
        }

        return false;
    }
}

void DialogConfigChambre::chargerDansModelChambresDuType(QString typeDeChambre)
{
    this->initialiserTableau();
    m_model->setFilter(m_model->record().fieldName(chambre::Id::Initial) + "='" + typeDeChambre + "'");
    m_model->select();
}

void DialogConfigChambre::on_comboBoxTypeTarif_currentIndexChanged(QString typeDeChambre)
{
    ui->tableView->setCurrentIndex(m_model->index(-1,-1));
    this->chargerDansModelChambresDuType(typeDeChambre);
    this->chargerTarifsDuType(typeDeChambre);
}

void DialogConfigChambre::on_btn_appliquer_clicked()
{
    this->enregistrerTarifsDuType(ui->comboBoxTypeTarif->currentText());
}

void DialogConfigChambre::chargerTarifsDuType(QString typeDeChambre)
{
    QSqlTableModel model;
    model.setTable(Tarif::Libelle);
    model.select();

    model.setFilter(model.record().fieldName(Tarif::Id::TypeDeChambre) + "='" + typeDeChambre + "'");
    model.select();

    if(model.rowCount()!=0)
    {
        QSqlRecord record = model.record(0);
        ui->spinBoxTarifNormal->setValue(record.value(Tarif::Id::PUNormal).toInt());
        ui->spinBoxTarifFidelite->setValue(record.value(Tarif::Id::PUFidelite).toInt());
        ui->spinBoxTarifPriviligie->setValue(record.value(Tarif::Id::PUPrivilegie).toInt());
        ui->btn_appliquer->setEnabled(false);
    }
}

void DialogConfigChambre::enregistrerTarifsDuType(QString typeDeChambre)
{
    QSqlTableModel model;
    model.setTable(Tarif::Libelle);
    model.setFilter(model.record().fieldName(Tarif::Id::TypeDeChambre) + "='" + typeDeChambre + "'");
    model.select();

    QSqlRecord record = model.record(0);
    record.setValue(Tarif::Id::PUNormal, ui->spinBoxTarifNormal->value());
    record.setValue(Tarif::Id::PUPrivilegie, ui->spinBoxTarifPriviligie->value());
    record.setValue(Tarif::Id::PUFidelite, ui->spinBoxTarifFidelite->value());

    model.setRecord(0,record);
    model.submitAll();
    ui->btn_appliquer->setEnabled(false);
    m_modifie = true;
}

void DialogConfigChambre::on_spinBoxTarifNormal_valueChanged(int )
{
    ui->btn_appliquer->setEnabled(true);
}

void DialogConfigChambre::on_spinBoxTarifPriviligie_valueChanged(int )
{
    ui->btn_appliquer->setEnabled(true);
}

void DialogConfigChambre::on_spinBoxTarifFidelite_valueChanged(int )
{
    ui->btn_appliquer->setEnabled(true);
}

void DialogConfigChambre::enregistrerChambre()
{
    // enregistrer dans la bd
    int idAjout = m_model->rowCount();
    m_model->insertRows(idAjout,1); // insérer à la dernière ligne
    m_model->setData(m_model->index(idAjout, chambre::Id::Identifiant), this->m_bdAjouterUneChambre->identifiant());
    m_model->setData(m_model->index(idAjout,chambre::Id::Initial), this->m_bdAjouterUneChambre->initial());
    m_model->setData(m_model->index(idAjout, chambre::Id::Numero), this->m_bdAjouterUneChambre->numero());

    m_model->submitAll();
    m_modifie = true;
}

void DialogConfigChambre::modifierChambre(int currentIndex)
{
    QSqlTableModel model;
    model.setTable(chambre::Libelle);
    model.select();

    QSqlRecord record = model.record(currentIndex);

    // actualiser la bd
    record.setValue(chambre::Id::Identifiant,this->m_bdModifierUneChambre->identifiant());
    record.setValue(chambre::Id::Initial,this->m_bdModifierUneChambre->initial());
    record.setValue(chambre::Id::Numero,this->m_bdModifierUneChambre->numero());

    model.setRecord(currentIndex, record);
    model.submitAll();

    m_modifie = true;
}
