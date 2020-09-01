#include "factureInitial.h"

factureInitial::factureInitial()
{
    constructeur();
}

factureInitial::factureInitial(const QSqlRecord &record)
{
    constructeur(record);
}

factureInitial::factureInitial(const factureInitial & s)
{
    constructeur(s);
}

factureInitial::factureInitial(int id)
{
    constructeur(id);
}

QVariant factureInitial::cle() const
{
    return idFactureInitial();
}

QString factureInitial::libelleDeCle() const
{
    return m_record.fieldName(FactureInitial::Id::IdFactureInitial);
}

QString factureInitial::tableName() const
{
    return FactureInitial::Libelle;
}

void factureInitial::setTypeDeFacture(QString type)
{
    m_record.setValue(FactureInitial::Id::TypeDeFacture, type);
    tableModifiee(true);
}

void factureInitial::setIdService(int idService)
{
    m_record.setValue(FactureInitial::Id::IdService, idService);
    tableModifiee(true);
}

void factureInitial::setInitial(QString initial)
{
    m_record.setValue(FactureInitial::Id::Initial, initial);
    tableModifiee(true);
}

void factureInitial::setNumero(int num)
{
    m_record.setValue(FactureInitial::Id::Numero, num);
    tableModifiee(true);
}

int factureInitial::idFactureInitial()const
{
     return m_record.value(FactureInitial::Id::IdFactureInitial).toInt();
}

int factureInitial::numero()const
{
     return m_record.value(FactureInitial::Id::Numero).toInt();
}

int factureInitial::idService()const
{
    return m_record.value(FactureInitial::Id::IdService).toInt();
}

QString factureInitial::typeDeFacture()const
{
    return m_record.value(FactureInitial::Id::TypeDeFacture).toString();
}

QString factureInitial::initial()const
{
    return m_record.value(FactureInitial::Id::Initial).toString();
}

