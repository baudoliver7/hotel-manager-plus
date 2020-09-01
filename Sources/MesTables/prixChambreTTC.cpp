#include "prixChambreTTC.h"

prixChambreTTC::prixChambreTTC()
{
    constructeur();
}

prixChambreTTC::prixChambreTTC(const QSqlRecord &record)
{
    constructeur(record);
}

prixChambreTTC::prixChambreTTC(const prixChambreTTC & t)
{
    constructeur(t);
}

prixChambreTTC::prixChambreTTC(int idPrixTTC)
{
    constructeur(idPrixTTC);
}

prixChambreTTC::prixChambreTTC(int idTypeDeChambre, int idProfile)
{
    constructeur();
    QString condition = QObject::tr("%1 = %2 AND %3 = %4")
                        .arg(idTypeChambreName())
                        .arg(idTypeDeChambre)
                        .arg(idProfileName())
                        .arg(idProfile);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(tableName(), condition);

    if(!records.isEmpty())
       m_record = records.first();
}

int prixChambreTTC::idPrixChambreTTC()const
{
    return m_record.value(PrixChambreTTC::Id::IdPrixChambreTTC).toInt();
}

int prixChambreTTC::idProfile()const
{
    return m_record.value(PrixChambreTTC::Id::IdProfile).toInt();
}

int prixChambreTTC::prixTTC()const
{
    return m_record.value(PrixChambreTTC::Id::PrixTTC).toInt();
}

int prixChambreTTC::idTypeChambre()const
{
    return m_record.value(PrixChambreTTC::Id::IdTypeChambre).toInt();
}

int prixChambreTTC::tva()const
{
    float ttva = taux(taux::TVA).valeur();
    return QString::number(prixTTC() * ttva / (1 + ttva), 'f', 0).toInt();
}

void prixChambreTTC::setIdProfile(int id)
{
    m_record.setValue(PrixChambreTTC::Id::IdProfile, id);
    tableModifiee(true);
}

void prixChambreTTC::setIdTypeChambre(int id)
{
    m_record.setValue(PrixChambreTTC::Id::IdTypeChambre, id);
    tableModifiee(true);
}

void prixChambreTTC::setPrixTTC(int prix)
{
    m_record.setValue(PrixChambreTTC::Id::PrixTTC, prix);
    tableModifiee(true);
}

QVariant prixChambreTTC::cle() const
{
    return idPrixChambreTTC();
}

QString prixChambreTTC::libelleDeCle() const
{
    return m_record.fieldName(PrixChambreTTC::Id::IdPrixChambreTTC);
}

QString prixChambreTTC::tableName() const
{
    return PrixChambreTTC::Libelle;
}
