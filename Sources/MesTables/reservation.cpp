#include "reservation.h"

reservation::reservation()
{
    constructeur();
}

reservation::reservation(int numReserv)
{
    constructeur(numReserv);
}

reservation::reservation(const QSqlRecord &record)
{
    constructeur(record);
}

reservation::reservation(const reservation &rv)
{
    constructeur(rv);
}

int reservation::numReservation()const
{
    return m_record.value(Reservation::Id::NumReserv).toInt();
}

QDateTime reservation::dateDeDemande()const
{
    return m_record.value(Reservation::Id::DateDeDemande).toDateTime();
}

int reservation::dureeOccupation()const
{
    return m_record.value(Reservation::Id::DureeOccup).toInt();
}

QDateTime reservation::datedEntree()const
{
    QDateTime date(m_record.value(Reservation::Id::DateOccup).toDate());
    date.setTime(HeureLimite(1).heureFinOccupation());
    return date;
}

QDateTime reservation::datedSortie()const
{
    QDateTime date(datedEntree().addDays(dureeOccupation()));
    date.setTime(HeureLimite(1).heureFinOccupation());

    return date;
}

int reservation::cout()const
{
    return m_record.value(Reservation::Id::Cout).toInt();
}

int reservation::avance()const
{
    return m_record.value(Reservation::Id::Avance).toInt();
}

int reservation::codeClient()const
{
    return m_record.value(Reservation::Id::CodeClient).toInt();
}

int reservation::idGroupe()const
{
    return m_record.value(Reservation::Id::IdGroupe).toInt();
}

int reservation::idProfileClient()const
{
    return m_record.value(Reservation::Id::IdProfileClient).toInt();
}

int reservation::reste()const
{
    return (cout() - avance());
}

void reservation::setDateDeDemande(QDateTime datetime)
{
    m_record.setValue(Reservation::Id::DateDeDemande, datetime);
    tableModifiee(true);
}

void reservation::setDureeOccupation(int nbJours)
{
    m_record.setValue(Reservation::Id::DureeOccup, nbJours);
    tableModifiee(true);
}

void reservation::setDatedEntree(QDateTime time)
{
    m_record.setValue(Reservation::Id::DateOccup, time);
    tableModifiee(true);
}

void reservation::setCout(int cout)
{
    m_record.setValue(Reservation::Id::Cout, cout);
    tableModifiee(true);
}

void reservation::setAvance(int avance)
{
    m_record.setValue(Reservation::Id::Avance, avance);
    tableModifiee(true);
}

void reservation::setCodeClient(int code)
{
    m_record.setValue(Reservation::Id::CodeClient, code);
    tableModifiee(true);
}

void reservation::setIdGroupe(int id)
{
    m_record.setValue(Reservation::Id::IdGroupe, id);
    tableModifiee(true);
}

void reservation::setIdProfileClient(int id)
{
    m_record.setValue(Reservation::Id::IdProfileClient, id);
    tableModifiee(true);
}

QVariant reservation::cle() const
{
    return numReservation();
}

QString reservation::libelleDeCle() const
{
    return m_record.fieldName(Reservation::Id::NumReserv);
}

QString reservation::tableName() const
{
    return Reservation::Libelle;
}

QList<QSqlRecord> reservation::reservation_records(QDate debut, QDate fin)
{
    reservation rv;
    QString condition = QObject::tr("DATE(%1) BETWEEN '%2' AND '%3'")
                        .arg(rv.dateOccupationName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate));

    return InfosSurBD::enregistrements(Reservation::Libelle, condition);
}

QList<QSqlRecord> reservation::reservation_records_en_cours()
{
    QString termineeName = InfosSurBD::fieldsNames(ChambreReservee::Libelle).at(ChambreReservee::Id::Terminee);
    reservation rv;
    QString condition = QObject::tr("%1 IN (SELECT %1 FROM %2 WHERE %3 = %4)")
                        .arg(rv.numReservName())
                        .arg(ChambreReservee::Libelle)
                        .arg(termineeName)
                        .arg(false);

    return InfosSurBD::enregistrements(Reservation::Libelle, condition);
}
