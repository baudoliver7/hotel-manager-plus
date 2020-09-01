#include "etage.h"

etage::etage()
{
    constructeur();
}

etage::etage(const QSqlRecord &record)
{
    constructeur(record);
}

etage::etage(const etage & s)
{
    constructeur(s);
}

etage::etage(int id)
{
    constructeur(id);
}

int etage::idEtage()const
{
    return m_record.value(Etage::Id::IdEtage).toInt();
}

QString etage::niveau()const
{
    return m_record.value(Etage::Id::Niveau).toString();
}

QVariant etage::cle() const
{
    return idEtage();
}

QString etage::libelleDeCle() const
{
    return m_record.fieldName(Etage::Id::IdEtage);
}

QString etage::tableName() const
{
    return Etage::Libelle;
}

void etage::setNiveau(QString niveau)
{
    m_record.setValue(Etage::Id::Niveau, niveau);
    tableModifiee(true);
}

QList<QSqlRecord> etage::etage_records()
{
    return InfosSurBD::enregistrements(Etage::Libelle);
}

QStringList etage::niveaux()
{
    QList<QSqlRecord> records;
    records = etage_records();

    QStringList niveaux_l;
    foreach(QSqlRecord r, records)
    {
        niveaux_l << etage(r).niveau();
    }

    return niveaux_l;
}
