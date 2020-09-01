#include "configServiceCompta.h"

configServiceCompta::configServiceCompta()
{
    constructeur();
}

configServiceCompta::configServiceCompta(const QSqlRecord &record)
{
    constructeur(record);
}

configServiceCompta::configServiceCompta(const configServiceCompta & rc)
{
    constructeur(rc);
}

configServiceCompta::configServiceCompta(int idCsc)
{
    constructeur(idCsc);
}

int configServiceCompta::idCsc()const
{
    return m_record.value(ConfigServiceCompta::Id::IdCsc).toInt();
}

QString configServiceCompta::action()const
{
    return m_record.value(ConfigServiceCompta::Id::Action).toString();
}

int configServiceCompta::compteAssocie()const
{
    return m_record.value(ConfigServiceCompta::Id::CompteAssocie).toInt();
}

int configServiceCompta::idSe()const
{
    return m_record.value(ConfigServiceCompta::Id::IdSe).toInt();
}

void configServiceCompta::setIdSe(int numero)
{
    m_record.setValue(ConfigServiceCompta::Id::IdSe, numero);
    tableModifiee(true);
}

void configServiceCompta::setCompteAssocie(int numero)
{
    m_record.setValue(ConfigServiceCompta::Id::CompteAssocie, numero);
    tableModifiee(true);
}

void configServiceCompta::setAction(QString ot)
{
    m_record.setValue(ConfigServiceCompta::Id::Action, ot);
    tableModifiee(true);
}

QVariant configServiceCompta::cle() const
{
    return idCsc();
}

QString configServiceCompta::libelleDeCle() const
{
    return m_record.fieldName(ConfigServiceCompta::Id::IdCsc);
}

QString configServiceCompta::tableName() const
{
    return ConfigServiceCompta::Libelle;
}
