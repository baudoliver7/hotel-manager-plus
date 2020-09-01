#include "tableResto.h"

tableResto::tableResto()
{
    constructeur();
}
tableResto::tableResto(QString libelle)
{
    constructeur();

    QString condition = QObject::tr("%1 = '%2'").arg(libelleName()).arg(libelle);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(tableName(), condition);

    if(!records.isEmpty())
    {
        m_record = records.first();
    }
}

tableResto::tableResto(const QSqlRecord &record)
{
    constructeur(record);
}

tableResto::tableResto(const tableResto & s)
{
    constructeur(s);
}

tableResto::tableResto(int id)
{
    constructeur(id);
}

QString tableResto::libelle()const
{
    return m_record.value(TableResto::Id::Libelle).toString();
}

int tableResto::idTableResto()const
{
    return m_record.value(TableResto::Id::IdTableResto).toInt();
}

bool tableResto::occupee()const
{
    return m_record.value(TableResto::Id::Occupee).toBool();
}

bool tableResto::supprime()const
{
    return m_record.value(TableResto::Id::Supprime).toBool();
}

bool tableResto::estBar()const
{
    return m_record.value(TableResto::Id::EstBar).toBool();
}

QVariant tableResto::cle() const
{
    return idTableResto();
}

QString tableResto::libelleDeCle() const
{
    return m_record.fieldName(TableResto::Id::IdTableResto);
}

QString tableResto::tableName() const
{
    return TableResto::Libelle;
}

void tableResto::setLibelle(QString libelle)
{
    m_record.setValue(TableResto::Id::Libelle, libelle);
    tableModifiee(true);
}

void tableResto::setOccupee(bool occupee)
{
    m_record.setValue(TableResto::Id::Occupee, occupee);
    tableModifiee(true);
}

void tableResto::setSupprime(bool supprime)
{
    m_record.setValue(TableResto::Id::Supprime, supprime);
    tableModifiee(true);
}

void tableResto::setEstBar(bool bar)
{
    m_record.setValue(TableResto::Id::EstBar, bar);
    tableModifiee(true);
}
