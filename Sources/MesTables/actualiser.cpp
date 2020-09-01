#include "actualiser.h"

actualiser::actualiser()
{
    constructeur();
}

actualiser::actualiser(const QSqlRecord &record)
{
    constructeur(record);
}

actualiser::actualiser(const actualiser & s)
{
    constructeur(s);
}

actualiser::actualiser(QString table)
{
    constructeur(table);
}

QString actualiser::table()const
{
    return m_record.value(Actualiser::Id::TableName).toString();
}

QVariant actualiser::cle() const
{
    return table();
}

QString actualiser::libelleDeCle() const
{
    return m_record.fieldName(Actualiser::Id::TableName);
}

QString actualiser::tableName() const
{
    return Actualiser::Libelle;
}

void actualiser::setTable(QString table)
{
    m_record.setValue(Actualiser::Id::TableName, table);
    tableModifiee(true);
}

void actualiser::setActual(bool actual)
{
    m_record.setValue(Actualiser::Id::Actual, actual);
    tableModifiee(true);
}

bool actualiser::actual()const
{
     return m_record.value(Actualiser::Id::Actual).toBool();
}

