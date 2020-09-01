#include "recuInitial.h"

recuInitial::recuInitial()
{
    constructeur();
}

recuInitial::recuInitial(const QSqlRecord &record)
{
    constructeur(record);
}

recuInitial::recuInitial(const recuInitial & s)
{
    constructeur(s);
}

recuInitial::recuInitial(int id)
{
    constructeur(id);
}

QVariant recuInitial::cle() const
{
    return idRecuInitial();
}

QString recuInitial::libelleDeCle() const
{
    return m_record.fieldName(RecuInitial::Id::IdRecuInitial);
}

QString recuInitial::tableName() const
{
    return RecuInitial::Libelle;
}

void recuInitial::setTypeDeRecu(QString type)
{
    m_record.setValue(RecuInitial::Id::TypeDeRecu, type);
    tableModifiee(true);
}

void recuInitial::setIdService(int idService)
{
    m_record.setValue(RecuInitial::Id::IdService, idService);
    tableModifiee(true);
}

void recuInitial::setInitial(QString initial)
{
    m_record.setValue(RecuInitial::Id::Initial, initial);
    tableModifiee(true);
}

void recuInitial::setNumero(int num)
{
    m_record.setValue(RecuInitial::Id::Numero, num);
    tableModifiee(true);
}

int recuInitial::idRecuInitial()const
{
     return m_record.value(RecuInitial::Id::IdRecuInitial).toInt();
}

int recuInitial::numero()const
{
     return m_record.value(RecuInitial::Id::Numero).toInt();
}

int recuInitial::idService()const
{
    return m_record.value(RecuInitial::Id::IdService).toInt();
}

QString recuInitial::typeDeRecu()const
{
    return m_record.value(RecuInitial::Id::TypeDeRecu).toString();
}

QString recuInitial::initial()const
{
    return m_record.value(RecuInitial::Id::Initial).toString();
}
