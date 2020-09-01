#include "BDIdentifierClientHotelSimple.h"
#include "ui_BDIdentifierClientHotelSimple.h"

BDIdentifierClientHotelSimple::BDIdentifierClientHotelSimple(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDIdentifierClientHotelSimple)
{
    ui->setupUi(this);

    m_affichage = false;
    ui->btn_details->setEnabled(false);
    ui->btn_ok->setEnabled(false);
    ui->btn_choisir->setEnabled(false);

    initialiserTableau();
    initialiserClientSelectionne();

    connect(ui->rb_clientConnu, SIGNAL(toggled(bool)), this, SLOT(updateEtatChampsClientConnu(bool)));
    connect(ui->rb_clientInconnu, SIGNAL(toggled(bool)), this, SLOT(updateEtatChampsClientInconnu(bool)));

    connect(ui->rb_clientConnu, SIGNAL(toggled(bool)), this, SLOT(initialiserClientSelectionne()));
    connect(ui->rb_clientInconnu, SIGNAL(toggled(bool)), this, SLOT(initialiserClientSelectionne()));

    connect(ui->lineEditClientConnu, SIGNAL(textChanged(QString)), this, SLOT(chargerClientConnu()));

    connect(ui->lineEditClientSelectionne, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnDetails()));
    connect(ui->lineEditClientSelectionne, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnOK()));
    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateEtatBtnChoisir(QModelIndex)));

    ui->rb_clientInconnu->setChecked(true);
    chargerClientConnu();
    updateEtatChampsClientConnu(false);

    updateEtatBtnOK();
}

BDIdentifierClientHotelSimple::~BDIdentifierClientHotelSimple()
{
    delete ui;

    delete m_model;
}

void BDIdentifierClientHotelSimple::changeEvent(QEvent *e)
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

void BDIdentifierClientHotelSimple::on_btn_identifier_clicked()
{
    client cl;
    cl.setHomme(true);
    BDFormulaireClientSimple bd(cl, false, this);
    bd.setWindowTitle("Identifier un client");

    if(bd.exec() == QDialog::Accepted)
    {
        client cl(bd.clientRenseigne());
        cl.enregistrer();

        m_clientSelectionne = cl;

        ui->lineEditClientSelectionne->setText(cl.nomComplet());
    }
}

void BDIdentifierClientHotelSimple::on_btn_details_clicked()
{
    QList<QSqlRecord> records;
    records << pieceIdentiteClient::pic_records(m_clientSelectionne.codeDuClient());

    pieceIdentiteClient p;
    if(!records.isEmpty())
        p = pieceIdentiteClient(records.first());

    BDFormulaireClientSimple bd(m_clientSelectionne, true, this);
    bd.setWindowTitle("Identifier un client");

    bd.exec();
}

void BDIdentifierClientHotelSimple::chargerClientConnu()
{
    QString nomDebut = ui->lineEditClientConnu->text();

    QString condition;
    if(!nomDebut.isEmpty())
    {
        client cl;
        condition = tr("%1 = %2 AND %3 LIKE '%4%'")
                                .arg(cl.hommeName())
                                .arg(ui->checkBoxMasculin->isChecked())
                                .arg(cl.nomName())
                                .arg(nomDebut);
    }else
    {
        client cl;
        condition = tr("%1 = %2").arg(cl.codeDuClientName())
                                .arg(-1);
    }


    m_model->setFilter(condition);
    m_model->select();
}

void BDIdentifierClientHotelSimple::initialiserTableau()
{
    m_model = new QSqlTableModel();
    m_model->setTable(Client::Libelle);
    ui->tableView->setModel(m_model);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setColumnHidden(Client::Id::CodeClient, true);
    ui->tableView->setColumnHidden(Client::Id::Homme, true);

    m_model->setHeaderData(Client::Id::Prenoms, Qt::Horizontal, "Prénom(s)");
    m_model->setHeaderData(Client::Id::DateDeNaissance, Qt::Horizontal, "Date de naissance");
    m_model->setHeaderData(Client::Id::LieuDeNaissance, Qt::Horizontal, "Lieu de naissance");
    m_model->setHeaderData(Client::Id::Pere, Qt::Horizontal, "Père");
    m_model->setHeaderData(Client::Id::Mere, Qt::Horizontal, "Mère");
    m_model->setHeaderData(Client::Id::DomicileHabituel, Qt::Horizontal, "Domicile habituel");
    m_model->setHeaderData(Client::Id::Nationalite, Qt::Horizontal, "Nationalité");
    m_model->setHeaderData(Client::Id::Cel, Qt::Horizontal, "Cel");
    m_model->setHeaderData(Client::Id::Tel, Qt::Horizontal, "Tel");
    m_model->setHeaderData(Client::Id::Email, Qt::Horizontal, "Adresse mail");
    m_model->setHeaderData(Client::Id::BP, Qt::Horizontal, "Boîte postale");
}

void BDIdentifierClientHotelSimple::updateEtatBtnDetails()
{
    bool disabled = ui->lineEditClientSelectionne->text().isEmpty();

    ui->btn_details->setDisabled(disabled);
}

void BDIdentifierClientHotelSimple::updateEtatChampsClientConnu(bool enabled)
{
    ui->lineEditClientConnu->setEnabled(enabled);
    ui->checkBoxMasculin->setEnabled(enabled);
    ui->tableView->setEnabled(enabled);
    ui->btn_choisir->setEnabled(enabled);    
    ui->btn_identifier->setEnabled(!enabled);
}

void BDIdentifierClientHotelSimple::updateEtatChampsClientInconnu(bool enabled)
{
    ui->btn_identifier->setEnabled(enabled);
}

void BDIdentifierClientHotelSimple::initialiserClientSelectionne()
{
    m_clientSelectionne.clear();
    ui->lineEditClientSelectionne->setText(QString());
}

void BDIdentifierClientHotelSimple::updateEtatBtnOK()
{
    ui->btn_ok->setDisabled(ui->lineEditClientSelectionne->text().isEmpty());
}

void BDIdentifierClientHotelSimple::on_btn_ok_clicked()
{
    // enregistrer profile du client sélectionné
    accept();
}

void BDIdentifierClientHotelSimple::on_btn_annuler_clicked()
{
    reject();
}

void BDIdentifierClientHotelSimple::updateEtatBtnChoisir(QModelIndex index)
{
    ui->btn_choisir->setEnabled(index.isValid());
}

void BDIdentifierClientHotelSimple::on_btn_choisir_clicked()
{
    int row = ui->tableView->currentIndex().row();

    client cl(m_model->record(row));
    ui->lineEditClientSelectionne->setText(cl.nomComplet());

    m_clientSelectionne = cl;
}


