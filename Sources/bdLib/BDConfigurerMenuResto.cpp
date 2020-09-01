#include "BDConfigurerMenuResto.h"
#include "ui_BDConfigurerMenuResto.h"

BDConfigurerMenuResto::BDConfigurerMenuResto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDConfigurerMenuResto)
{
    ui->setupUi(this);

    ui->btn_supprimer->setEnabled(false);
    ui->btn_ajouter->setEnabled(false);

    initialiserTable();
    initialiserCategorie();
}

BDConfigurerMenuResto::~BDConfigurerMenuResto()
{
    delete ui;
    delete m_modelCategorie;
}

void BDConfigurerMenuResto::changeEvent(QEvent *e)
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

void BDConfigurerMenuResto::on_lineEditLibelle_textChanged(QString value)
{
    ui->btn_ajouter->setEnabled(!value.isEmpty()&& ui->spinBoxPrixUnitaire->value() != 0
                                && ui->comboBoxCategorie->count() != 0);
}

void BDConfigurerMenuResto::on_spinBoxPrixUnitaire_valueChanged(int value)
{
    ui->btn_ajouter->setEnabled(value!=0 && !ui->lineEditLibelle->text().isEmpty()
                                && ui->comboBoxCategorie->count() != 0);
}

void BDConfigurerMenuResto::initialiserTable()
{
    m_model = new QSqlTableModel;
    m_model->setTable(MenuResto::Libelle);

    ui->tableViewMenu->setModel(m_model);
    ui->tableViewMenu->setColumnHidden(MenuResto::Id::IdCatMenu, true);
    ui->tableViewMenu->setColumnHidden(MenuResto::Id::Supprime, true);
    ui->tableViewMenu->setColumnHidden(MenuResto::Id::IdMenuResto, true);
    ui->tableViewMenu->setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_model->setHeaderData(MenuResto::Id::LibelleMenu, Qt::Horizontal, tr("Libellé"));
    m_model->setHeaderData(MenuResto::Id::Prix, Qt::Horizontal, tr("Prix unitaire"));

    connect(ui->tableViewMenu->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this
            , SLOT(updateEtatBtnSupprimer(QModelIndex)));
}

void BDConfigurerMenuResto::initialiserCategorie()
{
    m_modelCategorie = new QSqlTableModel;
    m_modelCategorie->setTable(CategorieMenu::Libelle);
    m_modelCategorie->setSort(CategorieMenu::Id::Libelle, Qt::AscendingOrder);

    categorieMenu cm;
    QString condition = tr("%1 = %2").arg(cm.supprimeeName()).arg(false);
    m_modelCategorie->setFilter(condition);

    ui->comboBoxCategorie->setModel(m_modelCategorie);
    ui->comboBoxCategorie->setModelColumn(CategorieMenu::Id::Libelle);

    connect(ui->comboBoxCategorie, SIGNAL(currentIndexChanged(int)), this, SLOT(chargerMenus()));

    chargerCategorie();
}

void BDConfigurerMenuResto::chargerMenus()
{
    menuResto mr;
    QString condition = tr("%1 = %2 AND %3 = %4")
                        .arg(mr.idCatMenuName())
                        .arg(currentCategorie())
                        .arg(mr.supprimeName())
                        .arg(false);

    m_model->setFilter(condition);
    m_model->select();

    ui->tableViewMenu->resizeColumnToContents(MenuResto::Id::LibelleMenu);
}

void BDConfigurerMenuResto::chargerCategorie()
{
    m_modelCategorie->select();
}

void BDConfigurerMenuResto::on_btn_ajouter_clicked()
{
    menuResto mr;
    mr.setLibelle(ui->lineEditLibelle->text());
    mr.setPrix(ui->spinBoxPrixUnitaire->value());
    mr.setIdCatMenu(currentCategorie());

    if(QMessageBox::information(this
                                , "Ajouter un menu"
                                , tr("Vous êtes sur le point d'ajouter le menu '%1'. \n\nDésirez-vous continuer ?").arg(mr.libelle())
                                , "Oui", "Non") == 0)
    {
        mr.enregistrer();
        ui->lineEditLibelle->setText(QString());
        ui->spinBoxPrixUnitaire->setValue(0);

        chargerMenus();
    }
}

void BDConfigurerMenuResto::on_btn_supprimer_clicked()
{
    int row = ui->tableViewMenu->currentIndex().row();
    QSqlRecord record = m_model->record(row);

    menuResto mr(record);

    if(QMessageBox::question(this
                             , "Supprimer un menu"
                             , tr("Désirez-vous supprimer le menu '%1' ?").arg(mr.libelle())
                             , "Oui", "Non") == 0)
    {
        mr.setSupprime(true);
        mr.enregistrer();

        chargerMenus();
    }
}

void BDConfigurerMenuResto::updateEtatBtnSupprimer(QModelIndex index)
{
    ui->btn_supprimer->setEnabled(index.isValid());
}

void BDConfigurerMenuResto::on_btn_fermer_clicked()
{
    close();
}

void BDConfigurerMenuResto::on_btn_nvelleCategorie_clicked()
{
    BDNvelleCategorieMenu bd(this);
    bd.setWindowTitle("Nouvelle catégorie");

    if(bd.exec() == QDialog::Accepted)
    {
        // enregistrer la nvelle catégorie
        categorieMenu cm;
        cm.setLibelle(bd.libelle());
        if(bd.plat())
            cm.setIdTypeCatMenu(1);
        else
            cm.setIdTypeCatMenu(2);

        cm.enregistrer();

        chargerCategorie();
    }
}

int BDConfigurerMenuResto::currentCategorie()
{
    int row = ui->comboBoxCategorie->currentIndex();

    if(row < 0)
        return 0;

    int idCatMenu = m_modelCategorie->record(row).value(CategorieMenu::Id::IdCategorieMenu).toInt();

    return idCatMenu;
}

void BDConfigurerMenuResto::on_comboBoxCategorie_currentIndexChanged(int index)
{
    ui->btn_ajouter->setEnabled(ui->spinBoxPrixUnitaire->value() != 0
                                && !ui->lineEditLibelle->text().isEmpty()
                                && ui->comboBoxCategorie->count() != 0);
}
