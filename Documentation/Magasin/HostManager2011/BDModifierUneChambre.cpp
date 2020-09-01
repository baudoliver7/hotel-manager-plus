#include "BDModifierUneChambre.h"
#include "ui_BDModifierUneChambre.h"

BDModifierUneChambre::BDModifierUneChambre(QSqlRecord record, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDModifierUneChambre)
{
    ui->setupUi(this);

    setWindowTitle(NomDuWidget::BDModifierUneChambre);
    setWindowModality(Qt::WindowModal);

    initialiserComboBoxInitial();

    afficherChambre(record);
}

BDModifierUneChambre::~BDModifierUneChambre()
{
    delete ui;
}

void BDModifierUneChambre::changeEvent(QEvent *e)
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

void BDModifierUneChambre::chargerInitial(QString typeDeChambre)
{
    if(Chambre::typeDeChambre(typeDeChambre)!=Chambre::AucunType)
    {
        m_model->setFilter(trouverInitiauxPourCeTypeDeChambre(typeDeChambre));
        m_model->select();
    }
}

void BDModifierUneChambre::initialiserModel()
{
    m_model = new QSqlTableModel(this);
    m_model->setTable(InitialDeChambre::Libelle);
    m_model->setSort(InitialDeChambre::Id::Initial, Qt::AscendingOrder);
}

void BDModifierUneChambre::initialiserComboBoxInitial()
{
    initialiserModel();
    ui->comboBoxInitial->setModel(m_model);
}

void BDModifierUneChambre::on_comboBoxTypeDeCh_currentIndexChanged(int index)
{
    QString  typeDeChambre = Chambre::typeDeChambre(Chambre::Type(index));
    chargerInitial(typeDeChambre);
}

QString BDModifierUneChambre::trouverInitiauxPourCeTypeDeChambre(QString typeDeChambre)
{
    QString LibelleDeTypeDeChambre = m_model->headerData(InitialDeChambre::Id::TypeDeChambre, Qt::Horizontal).toString();
    return QString(LibelleDeTypeDeChambre + "='" + typeDeChambre + "'");
}

void BDModifierUneChambre::on_btn_nouveauInitial_clicked()
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

void BDModifierUneChambre::initialiserBDNouveauInitial()
{
    this->m_bdNouveauInitial = new BDNouveauInitial(this);
}

QString BDModifierUneChambre::initial()
{
    return ui->comboBoxInitial->currentText();
}

int BDModifierUneChambre::numero()
{
    return ui->spinBoxNumero->value();
}

QString BDModifierUneChambre::identifiant()
{
    return this->initial() + QString::number(this->numero());
}

int BDModifierUneChambre::idTypeDeChambre()
{
    return ui->comboBoxTypeDeCh->currentIndex();
}

QString BDModifierUneChambre::typeDeChambre()
{
    return ui->comboBoxTypeDeCh->currentText();
}

void BDModifierUneChambre::afficherChambre(QSqlRecord record)
{
    QString typeDeCh = record.value(chambre::Id::Initial).toString();

    // spécifier le type de chambre
    ui->comboBoxTypeDeCh->setCurrentIndex((int)Chambre::typeDeChambre(typeDeCh));

    // spécifier l'initial
    this->on_comboBoxTypeDeCh_currentIndexChanged((int)Chambre::typeDeChambre(typeDeCh));

    // afficher numero
    ui->spinBoxNumero->setValue(record.value(chambre::Id::Numero).toInt());
}
