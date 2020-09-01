#include "recevoirOccup.h"

recevoirOccup::recevoirOccup()
{
    constructeur();
}

recevoirOccup::recevoirOccup(const QSqlRecord &record)
{
    constructeur(record);
}

recevoirOccup::recevoirOccup(const recevoirOccup & rc)
{
    constructeur(rc);
}

recevoirOccup::recevoirOccup(int NumRecevoir)
{
    constructeur(NumRecevoir);
}

QString recevoirOccup::matriculeRecepteur()const
{
    return m_record.value(RecevoirOccup::Id::MatriculeRecepteur).toString();
}

QDateTime recevoirOccup::date()const
{
    return m_record.value(RecevoirOccup::Id::Date).toDateTime();
}

int recevoirOccup::codeClient()const
{
    return m_record.value(RecevoirOccup::Id::CodeClient).toInt();
}

int recevoirOccup::numOccup()const
{
    return m_record.value(RecevoirOccup::Id::NumOccupation).toInt();
}

int recevoirOccup::numRecevoir()const
{
    return m_record.value(RecevoirOccup::Id::NumRecevoir).toInt();
}

void recevoirOccup::setCodeClient(int code)
{
    m_record.setValue(RecevoirOccup::Id::CodeClient, code);
    tableModifiee(true);
}

void recevoirOccup::setNumOccup(int num)
{
    m_record.setValue(RecevoirOccup::Id::NumOccupation, num);
    tableModifiee(true);
}

void recevoirOccup::setDate(QDateTime dateTime)
{
    m_record.setValue(RecevoirOccup::Id::Date, dateTime);
    tableModifiee(true);
}

void recevoirOccup::setMatriculeRecepteur(QString matricule)
{
    m_record.setValue(RecevoirOccup::Id::MatriculeRecepteur, matricule);
    tableModifiee(true);
}

QVariant recevoirOccup::cle() const
{
    return numRecevoir();
}

QString recevoirOccup::libelleDeCle() const
{
    return m_record.fieldName(RecevoirOccup::Id::NumRecevoir);
}

QString recevoirOccup::tableName() const
{
    return RecevoirOccup::Libelle;
}

recevoirOccup recevoirOccup::selectionner(int numOccup)
{
    QString condition = QObject::tr("%1 = %2").arg(recevoirOccup().numOccupName())
                                             .arg(numOccup);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(RecevoirOccup::Libelle, condition);

    if(!records.isEmpty())
    {
        return recevoirOccup(records.first());
    }else
    {
        return recevoirOccup();
    }
}
