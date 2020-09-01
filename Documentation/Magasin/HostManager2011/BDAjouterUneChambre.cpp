#include "BDAjouterUneChambree.h"
#include "ui_BDAjouterUneChambre.h"

BDAjouterUneChambre::BDAjouterUneChambre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDAjouterUneChambre)
{
    ui->setupUi(this);

    setWindowModality(Qt::WindowModal);
    setWindowTitle(NomDuWidget::BDAjouterUneChambre);

    initialiserComboBoxInitial();
    ui->comboBoxTypeDeCh->setCurrentIndex(Chambre::ChambreVentilee);
    on_comboBoxTypeDeCh_currentIndexChanged(Chambre::ChambreVentilee);
}

BDAjouterUneChambre::~BDAjouterUneChambre()
{
    delete ui;
}

void BDAjouterUneChambre::changeEvent(QEvent *e)
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

void BDAjouterUneChambre::closeEvent(QCloseEvent * e)
{

}

void BDAjouterUneChambre::chargerInitial(QString typeDeChambre)
{
    m_model->setFilter(trouverInitiauxPourCeTypeDeChambre(typeDeChambre));
    m_model->select();
}

void BDAjouterUneChambre::initialiserModel()
{
    m_model = new QSqlTableModel(this);
    m_model->setTable(InitialDeChambre::Libelle);
    m_model->setSort(InitialDeChambre::Id::Initial, Qt::AscendingOrder);
}

void BDAjouterUneChambre::initialiserComboBoxInitial()
{
    initialiserModel();
    ui->comboBoxInitial->setModel(m_model);
}

void BDAjouterUneChambre::on_comboBoxTypeDeCh_currentIndexChanged(int index)
{
    QString  typeDeChambre = Chambre::typeDeChambre(Chambre::Type(index));
    chargerInitial(typeDeChambre);
}

QString BDAjouterUneChambre::trouverInitiauxPourCeTypeDeChambre(QString typeDeChambre)
{
    return QString(m_model->record().fieldName(InitialDeChambre::Id::TypeDeChambre) +  "='" + typeDeChambre + "'");
}

void BDAjouterUneChambre::on_btn_nouveauInitial_clicked()
{
    this->initialiserBDNouveauInitial();
    this->m_bdNouveauInitial->exec();

    if(this->m_bdNouveauInitial->accepte())
    {
        if(ui->comboBoxTypeDeCh->currentText() == m_bdNouveauInitial->typeDeChambre())
        {
            chargerInitial(this->m_bdNouveauInitial->typeDeChambre());
        }
        delete this->m_bdNouveauInitial;
    }
}

void BDAjouterUneChambre::initialiserBDNouveauInitial()
{
    this->m_bdNouveauInitial = new BDNouveauInitial(this);
}

QString BDAjouterUneChambre::initial()
{
    return ui->comboBoxInitial->currentText();
}

int BDAjouterUneChambre::numero()
{
    return ui->spinBoxNumero->value();
}

QString BDAjouterUneChambre::identifiant()
{
    return this->initial() + QString::number(this->numero());
}

int BDAjouterUneChambre::idTypeDeChambre()
{
    return ui->comboBoxTypeDeCh->currentIndex();
}




