#include "BDIdentifierClientResto.h"
#include "ui_BDIdentifierClientResto.h"

BDIdentifierClientResto::BDIdentifierClientResto(bool searchOnly, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDIdentifierClientResto)
{
    ui->setupUi(this);

    m_clientEnTantQueLocataire = false;
    ui->btn_details->setEnabled(false);
    ui->btn_ok->setEnabled(false);
    ui->btn_choisir->setEnabled(false);

    initialiserTableau();
    initialiserClientSelectionne();

    connect(ui->rb_clientConnu, SIGNAL(toggled(bool)), this, SLOT(updateEtatChampsClientConnu(bool)));
    connect(ui->rb_clientInconnu, SIGNAL(toggled(bool)), this, SLOT(updateEtatChampsClientInconnu(bool)));
    connect(ui->rb_clientLocataire, SIGNAL(toggled(bool)), this, SLOT(updateEtatChampsClientLocataire(bool)));

    connect(ui->rb_clientConnu, SIGNAL(toggled(bool)), this, SLOT(initialiserClientSelectionne()));
    connect(ui->rb_clientInconnu, SIGNAL(toggled(bool)), this, SLOT(initialiserClientSelectionne()));
    connect(ui->rb_clientLocataire, SIGNAL(toggled(bool)), this, SLOT(initialiserClientSelectionne()));

    connect(ui->lineEditClientConnu, SIGNAL(textChanged(QString)), this, SLOT(chargerClientConnu()));

    connect(ui->rb_clientLocataire, SIGNAL(clicked()), this, SLOT(chargerChambres()));
    connect(ui->comboBoxChambre, SIGNAL(currentIndexChanged(int)), this, SLOT(afficherClientSelectionne()));
    connect(ui->lineEditClientSelectionne, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnDetails()));
    connect(ui->lineEditClientSelectionne, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnOK()));
    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , this, SLOT(updateEtatBtnChoisir(QModelIndex)));

    if(searchOnly)
    {
        ui->rb_clientConnu->setChecked(true);
        updateEtatChampsClientConnu(true);
        chargerClientConnu();

        ui->rb_clientInconnu->setVisible(false);
        ui->btn_identifier->setVisible(false);
    }else
    {
        ui->rb_clientInconnu->setChecked(true);
        updateEtatChampsClientInconnu(true);
        updateEtatChampsClientConnu(false);
    }

    chargerClientConnu();
    updateEtatChampsClientLocataire(false);
    updateEtatBtnOK();
}

BDIdentifierClientResto::~BDIdentifierClientResto()
{
    delete ui;

    delete m_model;
}

void BDIdentifierClientResto::changeEvent(QEvent *e)
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

void BDIdentifierClientResto::on_btn_identifier_clicked()
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
        m_clientEnTantQueLocataire = false;
    }
}

void BDIdentifierClientResto::on_btn_details_clicked()
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

void BDIdentifierClientResto::chargerClientConnu()
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

void BDIdentifierClientResto::initialiserTableau()
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

void BDIdentifierClientResto::chargerChambres()
{
    QStringList chambres = MesTables::selectionnerChambresOccupees();
    chambres.sort();

    ui->comboBoxChambre->clear();
    ui->comboBoxChambre->addItems(chambres);

    m_chambres = chambres;
}

void BDIdentifierClientResto::afficherClientSelectionne()
{
    if(ui->comboBoxChambre->currentText().isEmpty())
    {
        ui->lineEditClientSelectionne->setText(QString());
        return;
    }

    occupation oc;
    QString condition = tr("%1 = '%2' AND %3 = %4")
                        .arg(oc.identiteChName())
                        .arg(ui->comboBoxChambre->currentText())
                        .arg(oc.termineeName())
                        .arg(false);

    QSqlRecord record = InfosSurBD::enregistrements(Occupation::Libelle, condition).first();
    occupation oc1(record);
    client cl(oc1.codeClient());

    ui->lineEditClientSelectionne->setText(cl.nomComplet());

    m_clientSelectionne = cl;
    m_clientEnTantQueLocataire = true;
    m_numOccupClientLocataire = oc1.numOccupation();
}

void BDIdentifierClientResto::updateEtatBtnDetails()
{
    ui->btn_details->setDisabled(ui->lineEditClientSelectionne->text().isEmpty());
}

void BDIdentifierClientResto::updateEtatChampsClientConnu(bool enabled)
{
    ui->lineEditClientConnu->setEnabled(enabled);
    ui->checkBoxMasculin->setEnabled(enabled);
    ui->tableView->setEnabled(enabled);
    ui->btn_choisir->setEnabled(enabled);    
}

void BDIdentifierClientResto::updateEtatChampsClientInconnu(bool enabled)
{
    ui->btn_identifier->setEnabled(enabled);
}

void BDIdentifierClientResto::updateEtatChampsClientLocataire(bool enabled)
{
    ui->comboBoxChambre->setEnabled(enabled);
}

void BDIdentifierClientResto::initialiserClientSelectionne()
{
    m_clientSelectionne.clear();
    ui->lineEditClientSelectionne->setText(QString());
}

void BDIdentifierClientResto::updateEtatBtnOK()
{
    ui->btn_ok->setDisabled(ui->lineEditClientSelectionne->text().isEmpty());
}

void BDIdentifierClientResto::on_btn_ok_clicked()
{
    accept();
}

void BDIdentifierClientResto::on_btn_annuler_clicked()
{
    reject();
}

void BDIdentifierClientResto::updateEtatBtnChoisir(QModelIndex index)
{
    ui->btn_choisir->setEnabled(index.isValid());
}

void BDIdentifierClientResto::on_btn_choisir_clicked()
{
    int row = ui->tableView->currentIndex().row();

    client cl(m_model->record(row));
    ui->lineEditClientSelectionne->setText(cl.nomComplet());

    m_clientSelectionne = cl;
    m_clientEnTantQueLocataire = false;
}

void BDIdentifierClientResto::on_lineEditRechercherCh_textChanged(QString chAChercher)
{
    if(m_chambres.contains(chAChercher))
    {
        ui->comboBoxChambre->setCurrentIndex(m_chambres.indexOf(chAChercher));
    }
}
