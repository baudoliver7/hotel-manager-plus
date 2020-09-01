#include "emettreReserv.h"

emettreReserv::emettreReserv()
{
    constructeur();
}

emettreReserv::emettreReserv(const QSqlRecord &record)
{
    constructeur(record);
}

emettreReserv::emettreReserv(const emettreReserv & rc)
{
    constructeur(rc);
}

emettreReserv::emettreReserv(int NumEmettre)
{
    constructeur(NumEmettre);
}

QString emettreReserv::matriculeRecepteur()const
{
    return m_record.value(EmettreReserv::Id::MatriculeRecepteur).toString();
}

QString emettreReserv::identiteCh()const
{
    return m_record.value(EmettreReserv::Id::IdentiteCh).toString();
}

QDateTime emettreReserv::date()const
{
    return m_record.value(EmettreReserv::Id::Date).toDateTime();
}

int emettreReserv::numReserv()const
{
    return m_record.value(EmettreReserv::Id::NumReservation).toInt();
}

int emettreReserv::numEmettre()const
{
    return m_record.value(EmettreReserv::Id::NumEmettre).toInt();
}

void emettreReserv::setIdentiteCh(QString identite)
{
    m_record.setValue(EmettreReserv::Id::IdentiteCh, identite);
    tableModifiee(true);
}

void emettreReserv::setNumReserv(int num)
{
    m_record.setValue(EmettreReserv::Id::NumReservation, num);
    tableModifiee(true);
}

void emettreReserv::setDate(QDateTime dateTime)
{
    m_record.setValue(EmettreReserv::Id::Date, dateTime);
    tableModifiee(true);
}

void emettreReserv::setMatriculeRecepteur(QString matricule)
{
    m_record.setValue(EmettreReserv::Id::MatriculeRecepteur, matricule);
    tableModifiee(true);
}

QVariant emettreReserv::cle() const
{
    return numEmettre();
}

QString emettreReserv::libelleDeCle() const
{
    return m_record.fieldName(EmettreReserv::Id::NumEmettre);
}

QString emettreReserv::tableName() const
{
    return EmettreReserv::Libelle;
}

emettreReserv emettreReserv::selectionner(int numReserv)
{
    QString condition = QObject::tr("%1 = %2").arg(emettreReserv().numReservName())
                                              .arg(numReserv);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(EmettreReserv::Libelle, condition);

    if(!records.isEmpty())
    {
        return emettreReserv(records.first());
    }else
    {
        return emettreReserv();
    }
}

