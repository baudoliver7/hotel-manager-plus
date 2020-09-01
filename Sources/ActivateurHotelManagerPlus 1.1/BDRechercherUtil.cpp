#include "BDRechercherUtil.h"
#include "ui_BDRechercherUtil.h"

BDRechercherUtil::BDRechercherUtil(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDRechercherUtil)
{
    ui->setupUi(this);

    m_db = db;
    ui->btn_choisir->setEnabled(false);

    initialiserModel();

    connect(ui->tableViewUtilisateurs->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this
            , SLOT(updateBtnChoisir(QModelIndex)));

    connect(ui->Masculin, SIGNAL(toggled(bool)), this, SLOT(chargerUtilisateurs()));
    connect(ui->lineEditNom, SIGNAL(textChanged(QString)), this, SLOT(chargerUtilisateurs()));

    chargerUtilisateurs();
}

BDRechercherUtil::~BDRechercherUtil()
{
    delete ui;
    delete m_model;
}

void BDRechercherUtil::changeEvent(QEvent *e)
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

void BDRechercherUtil::initialiserModel()
{
    m_model = new QSqlTableModel(0, m_db);
    m_model->setTable("Utilisateurs");

    ui->tableViewUtilisateurs->setModel(m_model);
    ui->tableViewUtilisateurs->setColumnHidden(0, true);
}


void BDRechercherUtil::on_btn_choisir_clicked()
{
    int row = ui->tableViewUtilisateurs->currentIndex().row();
    m_record = m_model->record(row);

    accept();
}

void BDRechercherUtil::on_btn_Annuler_clicked()
{
    reject();
}

void BDRechercherUtil::chargerUtilisateurs()
{
    QString requete;

    requete = tr("%1 = %2")
              .arg("Homme")
              .arg(QString::number(ui->Masculin->isChecked()));

    QString debutNom = ui->lineEditNom->text();
    if(!debutNom.isEmpty())
    {
        requete = tr("%1 AND %2 LIKE '%3%'")
                             .arg(requete)
                             .arg("Nom")
                             .arg(debutNom);
    }

    m_model->setFilter(requete);
    m_model->select();
}

void BDRechercherUtil::updateBtnChoisir(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_choisir->setEnabled(true);
    }else
    {
        ui->btn_choisir->setEnabled(false);
    }
}
