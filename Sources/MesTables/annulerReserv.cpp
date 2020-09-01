#include "annulerReserv.h"

annulerReserv::annulerReserv()
{
    constructeur();
}

annulerReserv::annulerReserv(const QSqlRecord &record)
{
    constructeur(record);
}

annulerReserv::annulerReserv(const annulerReserv & rc)
{
    constructeur(rc);
}

annulerReserv::annulerReserv(int NumAnnuler)
{
    constructeur(NumAnnuler);
}

QString annulerReserv::matriculeRecepteur()const
{
    return m_record.value(AnnulerReserv::Id::MatriculeRecepteur).toString();
}

QDateTime annulerReserv::date()const
{
    return m_record.value(AnnulerReserv::Id::Date).toDateTime();
}

QString annulerReserv::identiteCh()const
{
    return m_record.value(AnnulerReserv::Id::IdentiteCh).toString();
}

int annulerReserv::numReserv()const
{
    return m_record.value(AnnulerReserv::Id::NumReservation).toInt();
}

int annulerReserv::numAnnuler()const
{
    return m_record.value(AnnulerReserv::Id::NumAnnuler).toInt();
}

void annulerReserv::setIdentiteCh(QString identite)
{
    m_record.setValue(AnnulerReserv::Id::IdentiteCh, identite);
    tableModifiee(true);
}

void annulerReserv::setNumReserv(int num)
{
    m_record.setValue(AnnulerReserv::Id::NumReservation, num);
    tableModifiee(true);
}

void annulerReserv::setDate(QDateTime dateTime)
{
    m_record.setValue(AnnulerReserv::Id::Date, dateTime);
    tableModifiee(true);
}

void annulerReserv::setMatriculeRecepteur(QString matricule)
{
    m_record.setValue(AnnulerReserv::Id::MatriculeRecepteur, matricule);
    tableModifiee(true);
}

QVariant annulerReserv::cle() const
{
    return numAnnuler();
}

QString annulerReserv::libelleDeCle() const
{
    return m_record.fieldName(AnnulerReserv::Id::NumAnnuler);
}

QString annulerReserv::tableName() const
{
    return AnnulerReserv::Libelle;
}

annulerReserv annulerReserv::selectionner(int numReserv)
{
    QString condition = QObject::tr("%1 = %2").arg(annulerReserv().numReservName())
                                              .arg(numReserv);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(AnnulerReserv::Libelle, condition);

    if(!records.isEmpty())
    {
        return annulerReserv(records.first());
    }else
    {
        return annulerReserv();
    }
}

