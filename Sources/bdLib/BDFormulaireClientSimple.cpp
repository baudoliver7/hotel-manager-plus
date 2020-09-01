#include "BDFormulaireClientSimple.h"
#include "ui_BDFormulaireClientSimple.h"

BDFormulaireClientSimple::BDFormulaireClientSimple(const client &cl, bool readOnly, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDFormulaireClientSimple)
{
    ui->setupUi(this);

    m_readOnly = readOnly;

    ui->btn_ok->setVisible(!readOnly);
    ui->btn_ok->setEnabled(false);

    if(readOnly)
        ui->btn_annuler->setText("Fermer");

    ui->lineEditDomicile->setReadOnly(m_readOnly);
    ui->lineEditLieuDeNaiss->setReadOnly(m_readOnly);
    ui->lineEditMere->setReadOnly(m_readOnly);
    ui->lineEditNationalite->setReadOnly(m_readOnly);
    ui->lineEditNom->setReadOnly(m_readOnly);
    ui->lineEditPere->setReadOnly(m_readOnly);
    ui->lineEditPrenom->setReadOnly(m_readOnly);
    ui->lineEditProfession->setReadOnly(m_readOnly);

    ui->dateEditDateDeNaiss->setReadOnly(m_readOnly);

    ui->rb_feminin->setDisabled(m_readOnly);
    ui->rb_masculin->setDisabled(m_readOnly);

    m_client = cl;
    afficherClient(m_client);

    connect(ui->lineEditNom, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnOK()));
    connect(ui->lineEditPrenom, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnOK()));
    connect(ui->lineEditContacts, SIGNAL(textChanged(QString)), this, SLOT(updateEtatBtnOK()));

    updateEtatBtnOK();
}

BDFormulaireClientSimple::~BDFormulaireClientSimple()
{
    delete ui;
}

void BDFormulaireClientSimple::changeEvent(QEvent *e)
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

void BDFormulaireClientSimple::on_btn_ok_clicked()
{
    if(!m_readOnly)
    {
        // récupérer les infos
        m_client.setNom(ui->lineEditNom->text());
        m_client.setPrenoms(ui->lineEditPrenom->text());
        m_client.setDateDeNaissance(ui->dateEditDateDeNaiss->date());
        m_client.setLieuDeNaissance(ui->lineEditLieuDeNaiss->text());
        m_client.setPere(ui->lineEditPere->text());
        m_client.setMere(ui->lineEditMere->text());
        m_client.setProfession(ui->lineEditProfession->text());
        m_client.setDomicileHabituel(ui->lineEditDomicile->text());
        m_client.setContacts(ui->lineEditContacts->text());
        m_client.setNationalite(ui->lineEditNationalite->text());
        m_client.setHomme(ui->rb_masculin->isChecked());
    }

    accept();
}

void BDFormulaireClientSimple::on_btn_annuler_clicked()
{
    reject();
}

void BDFormulaireClientSimple::afficherClient(const client &cl)
{
    // infos sur le client
    ui->lineEditNom->setText(cl.nom());
    ui->lineEditPrenom->setText(cl.prenoms());
    ui->dateEditDateDeNaiss->setDate(cl.dateDeNaissance());
    ui->lineEditLieuDeNaiss->setText(cl.lieuDeNaissance());
    ui->lineEditPere->setText(cl.pere());
    ui->lineEditMere->setText(cl.mere());
    ui->lineEditProfession->setText(cl.profession());
    ui->lineEditDomicile->setText(cl.domicileHabituel());
    ui->lineEditContacts->setText(cl.contacts());
    ui->lineEditNationalite->setText(cl.nationalite());
    ui->rb_masculin->setChecked(cl.homme());
    ui->rb_feminin->setChecked(!cl.homme());
}

void BDFormulaireClientSimple::on_btn_calendrier_clicked()
{
    DialogContact bd(ui->lineEditContacts->text(), this, m_readOnly);
    bd.setWindowTitle("Contacts");

    if(bd.exec() == QDialog::Accepted)
    {
        ui->lineEditContacts->setText(bd.getContact());
    }
}

void BDFormulaireClientSimple::updateEtatBtnOK()
{
    bool disabled = ui->lineEditNom->text().isEmpty() || ui->lineEditPrenom->text().isEmpty()
                    || ui->lineEditContacts->text().isEmpty();

    ui->btn_ok->setDisabled(disabled);
}
