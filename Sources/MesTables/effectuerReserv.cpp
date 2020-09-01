#include "effectuerReserv.h"

effectuerReserv::effectuerReserv()
{
    constructeur();
}

effectuerReserv::effectuerReserv(const QSqlRecord &record)
{
    constructeur(record);
}

effectuerReserv::effectuerReserv(const effectuerReserv & rc)
{
    constructeur(rc);
}

effectuerReserv::effectuerReserv(int NumRecevoir)
{
    constructeur(NumRecevoir);
}

QString effectuerReserv::matriculeRecepteur()const
{
    return m_record.value(EffectuerReserv::Id::MatriculeRecepteur).toString();
}

QDateTime effectuerReserv::date()const
{
    return m_record.value(EffectuerReserv::Id::Date).toDateTime();
}

QString effectuerReserv::identiteCh()const
{
    return m_record.value(EffectuerReserv::Id::IdentiteCh).toString();
}

int effectuerReserv::numReserv()const
{
    return m_record.value(EffectuerReserv::Id::NumReservation).toInt();
}

int effectuerReserv::numEffectuer()const
{
    return m_record.value(EffectuerReserv::Id::NumEffectuer).toInt();
}

void effectuerReserv::setIdentiteCh(QString identite)
{
    m_record.setValue(EffectuerReserv::Id::IdentiteCh, identite);
    tableModifiee(true);
}

void effectuerReserv::setNumReserv(int num)
{
    m_record.setValue(EffectuerReserv::Id::NumReservation, num);
    tableModifiee(true);
}

void effectuerReserv::setDate(QDateTime dateTime)
{
    m_record.setValue(EffectuerReserv::Id::Date, dateTime);
    tableModifiee(true);
}

void effectuerReserv::setMatriculeRecepteur(QString matricule)
{
    m_record.setValue(EffectuerReserv::Id::MatriculeRecepteur, matricule);
    tableModifiee(true);
}

QVariant effectuerReserv::cle() const
{
    return numEffectuer();
}

QString effectuerReserv::libelleDeCle() const
{
    return m_record.fieldName(EffectuerReserv::Id::NumEffectuer);
}

QString effectuerReserv::tableName() const
{
    return EffectuerReserv::Libelle;
}

effectuerReserv effectuerReserv::selectionner(int numReserv)
{
    QString condition = QObject::tr("%1 = %2").arg(effectuerReserv().numReservName())
                                              .arg(numReserv);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(EffectuerReserv::Libelle, condition);

    if(!records.isEmpty())
    {
        return effectuerReserv(records.first());
    }else
    {
        return effectuerReserv();
    }
}
