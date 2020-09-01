#include "BDNouveauInitial.h"
#include "ui_BDNouveauInitial.h"

BDNouveauInitial::BDNouveauInitial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDNouveauInitial)
{
    ui->setupUi(this);

    setWindowModality(Qt::WindowModal);
    setWindowTitle(NomDuWidget::BDNouveauInitial);

    this->m_accepted = false;
}

BDNouveauInitial::~BDNouveauInitial()
{
    delete ui;
}

void BDNouveauInitial::changeEvent(QEvent *e)
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

bool BDNouveauInitial::initialExisteDeja(QString initial)
{
    QSqlTableModel model;
    model.setTable(InitialDeChambre::Libelle);

    model.setFilter(model.record().fieldName(InitialDeChambre::Id::Initial) + "='" + initial + "'");
    model.select();

    return (model.rowCount() != 0);
}


void BDNouveauInitial::on_btn_OK_clicked()
{
    if(ui->lineEditInitial->text() != QString())
    {
        if(!this->initialExisteDeja(ui->lineEditInitial->text()))
        {
            this->enregistrerInitial();
            m_accepted = true;
            close();
        }else
        {
            QMessageBox::information(this, "Existence de l'initial", "Cet initial existe déjà!");
        }
    }else
    {
        QMessageBox::information(this, "Initial vide", "Vous devez fournir un initial non vide!");
    }
}

void BDNouveauInitial::enregistrerInitial()
{
    QSqlTableModel model;
    model.setTable(InitialDeChambre::Libelle);

    int i = model.rowCount();
    model.insertRows(i, 1);
    model.setData(model.index(i,InitialDeChambre::Id::Initial),ui->lineEditInitial->text());
    model.setData(model.index(i,InitialDeChambre::Id::TypeDeChambre), ui->comboBoxTypeDeCh->currentText());
    model.submitAll();
}

void BDNouveauInitial::on_btn_Annuler_clicked()
{
    m_accepted = false;
    close();
}

QString BDNouveauInitial::typeDeChambre()
{
    return ui->comboBoxTypeDeCh->currentText();
}
