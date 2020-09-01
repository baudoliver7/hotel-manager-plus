#include "chambreReservee.h"

chambreReservee::chambreReservee()
{
    constructeur();
}

chambreReservee::chambreReservee(int id)
{
    constructeur(id);
}

chambreReservee::chambreReservee(const QSqlRecord &record)
{
    constructeur(record);
}

chambreReservee::chambreReservee(const chambreReservee &rv)
{
    constructeur(rv);
}

chambreReservee::chambreReservee(int numReserv, QString ch)
{
    constructeur();

    QString condition = QObject::tr("%1 = %2 AND %3 = '%4'")
                        .arg(numReservName())
                        .arg(numReserv)
                        .arg(identiteChName())
                        .arg(ch);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(tableName(), condition);

    if(!records.isEmpty())
    {
        m_record = records.first();
    }
}

int chambreReservee::numReservation()const
{
    return m_record.value(ChambreReservee::Id::NumReservation).toInt();
}

QString chambreReservee::identiteCh()const
{
    return m_record.value(ChambreReservee::Id::IdentiteCh).toString();
}

int chambreReservee::cout()const
{
    return m_record.value(ChambreReservee::Id::Cout).toInt();
}

int chambreReservee::avance()const
{
    return m_record.value(ChambreReservee::Id::Avance).toInt();
}

int chambreReservee::reste()const
{
    return (cout() - avance());
}

bool chambreReservee::terminee()const
{
    return m_record.value(ChambreReservee::Id::Terminee).toBool();
}

int chambreReservee::idChambreReservee()const
{
    return m_record.value(ChambreReservee::Id::IdChambreReservee).toInt();
}

void chambreReservee::setIdentiteCh(QString identite)
{
    m_record.setValue(ChambreReservee::Id::IdentiteCh, identite);
    tableModifiee(true);
}

void chambreReservee::setTerminer(bool ter)
{
    m_record.setValue(ChambreReservee::Id::Terminee, ter);
    tableModifiee(true);
}

void chambreReservee::setCout(int cout)
{
    m_record.setValue(ChambreReservee::Id::Cout, cout);
    tableModifiee(true);
}

void chambreReservee::setAvance(int avance)
{
    m_record.setValue(ChambreReservee::Id::Avance, avance);
    tableModifiee(true);
}

void chambreReservee::setNumReservation(int id)
{
    m_record.setValue(ChambreReservee::Id::NumReservation, id);
    tableModifiee(true);
}

QVariant chambreReservee::cle() const
{
    return idChambreReservee();
}

QString chambreReservee::libelleDeCle() const
{
    return m_record.fieldName(ChambreReservee::Id::IdChambreReservee);
}

QString chambreReservee::tableName() const
{
    return ChambreReservee::Libelle;
}

// fonctions spéciales
bool chambreReservee::estEnCours()const
{
    return !terminee();
}

bool chambreReservee::estReglee()const
{
    return (reste() == 0);
}

bool chambreReservee::annulee()const
{
    return annulerReserv::selectionner(numReservation()).existe();
}

bool chambreReservee::executee()const
{
    return effectuerReserv::selectionner(numReservation()).existe();
}

QList<QSqlRecord> chambreReservee::chambresReserveesEnCours(int idTypeDeChambre)
{
    chambreReservee ch;
    QString condition = QObject::tr("%1 = %2")
                        .arg(ch.termineeName())
                        .arg(false);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ch.tableName(), condition);

    QList<QSqlRecord> records1;
    foreach(QSqlRecord r, records)
    {
        chambreReservee chr(r);
        chambre ch(chr.identiteCh());

        if(ch.idTypeChambre() == idTypeDeChambre)
        {
            records1 << r;
        }
    }

    return records1;
}

QList<QSqlRecord> chambreReservee::chambresReserveesEnCours()
{
    chambreReservee oc;
    QString condition = QObject::tr("%1 = %2")
                        .arg(oc.termineeName())
                        .arg(false);

    return InfosSurBD::enregistrements(ChambreReservee::Libelle, condition);
}

QList<QSqlRecord> chambreReservee::chambre_reservee_records(int numReservation)
{
    chambreReservee oc;
    QString condition = QObject::tr("%1 = %2")
                        .arg(oc.numReservName())
                        .arg(numReservation);

    return InfosSurBD::enregistrements(ChambreReservee::Libelle, condition);
}
