#include "BDModifierUneChambre.h"
#include "ui_BDModifierUneChambre.h"

BDModifierUneChambre::BDModifierUneChambre(QSqlRecord record, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDModifierUneChambre)
{
    ui->setupUi(this);

    chambre ch(record);
    m_ancienIdentifiant = ch.identifiant();
    setWindowTitle(tr("Modifier %1").arg(m_ancienIdentifiant));
    setWindowModality(Qt::WindowModal);

    m_typeDeChambre = QString();//ch.typeStr();
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

QString BDModifierUneChambre::ancienIdentifiant()
{
    return m_ancienIdentifiant;
}

void BDModifierUneChambre::afficherChambre(QSqlRecord record)
{
//    chambre ch(record);
//
//    for(int i = 0; i < ui->comboBoxInitial->count(); i++)
//    {
//        if(ch.initial() == ui->comboBoxInitial->itemText(i))
//        {
//            ui->comboBoxInitial->setCurrentIndex(i);
//        }
//    }
//
//    // afficher numero
//    ui->spinBoxNumero->setValue(ch.numero());
}
