#include "libererOccup.h"

libererOccup::libererOccup()
{
    constructeur();
}

libererOccup::libererOccup(const QSqlRecord &record)
{
    constructeur(record);
}

libererOccup::libererOccup(const libererOccup & rc)
{
    constructeur(rc);
}

libererOccup::libererOccup(int NumLiberer)
{
    constructeur(NumLiberer);
}

QString libererOccup::matriculeRecepteur()const
{
    return m_record.value(LibererOccup::Id::MatriculeRecepteur).toString();
}

QDateTime libererOccup::date()const
{
    return m_record.value(LibererOccup::Id::Date).toDateTime();
}

int libererOccup::codeClient()const
{
    return m_record.value(LibererOccup::Id::CodeClient).toInt();
}

int libererOccup::numOccup()const
{
    return m_record.value(LibererOccup::Id::NumOccupation).toInt();
}

int libererOccup::numLiberer()const
{
    return m_record.value(LibererOccup::Id::NumLiberer).toInt();
}

void libererOccup::setCodeClient(int code)
{
    m_record.setValue(LibererOccup::Id::CodeClient, code);
    tableModifiee(true);
}

void libererOccup::setNumOccup(int num)
{
    m_record.setValue(LibererOccup::Id::NumOccupation, num);
    tableModifiee(true);
}

void libererOccup::setDate(QDateTime dateTime)
{
    m_record.setValue(LibererOccup::Id::Date, dateTime);
    tableModifiee(true);
}

void libererOccup::setMatriculeRecepteur(QString matricule)
{
    m_record.setValue(LibererOccup::Id::MatriculeRecepteur, matricule);
    tableModifiee(true);
}

QVariant libererOccup::cle() const
{
    return numLiberer();
}

QString libererOccup::libelleDeCle() const
{
    return m_record.fieldName(LibererOccup::Id::NumLiberer);
}

QString libererOccup::tableName() const
{
    return LibererOccup::Libelle;
}

libererOccup libererOccup::selectionner(int numOccup)
{
    QString condition = QObject::tr("%1 = %2").arg(libererOccup().numOccupName())
                                             .arg(numOccup);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(LibererOccup::Libelle, condition);

    if(!records.isEmpty())
    {
        return libererOccup(records.first());
    }else
    {
        return libererOccup();
    }
}
