#include "profileClient.h"

profileClient::profileClient()
{
    constructeur();
}

profileClient::profileClient(const QSqlRecord &record)
{
    constructeur(record);
}

profileClient::profileClient(const profileClient & s)
{
    constructeur(s);
}

profileClient::profileClient(int id)
{
    constructeur(id);
}

QString profileClient::profile()const
{
    return m_record.value(ProfileClient::Id::Profile).toString();
}

int profileClient::idProfile()const
{
    return m_record.value(ProfileClient::Id::IdProfile).toInt();
}

bool profileClient::disponible()const
{
    return m_record.value(ProfileClient::Id::Disponible).toBool();
}

int profileClient::idTypeClient()const
{
    return m_record.value(ProfileClient::Id::IdTypeClient).toInt();
}

QVariant profileClient::cle() const
{
    return idProfile();
}

QString profileClient::libelleDeCle() const
{
    return m_record.fieldName(ProfileClient::Id::IdProfile);
}

QString profileClient::tableName() const
{
    return ProfileClient::Libelle;
}

void profileClient::setProfile(QString profile)
{
    m_record.setValue(ProfileClient::Id::Profile, profile);
    tableModifiee(true);
}

void profileClient::setDisponible(bool disponible)
{
    m_record.setValue(ProfileClient::Id::Disponible, disponible);
    tableModifiee(true);
}

void profileClient::setIdTypeClient(int id)
{
    m_record.setValue(ProfileClient::Id::IdTypeClient, id);
    tableModifiee(true);
}

QStringList profileClient::profilesDisponibles(bool disponible)
{
    profileClient t;
    QString condition = QObject::tr("%1 = %2")
                        .arg(t.disponibleName())
                        .arg(disponible);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ProfileClient::Libelle, condition);

    QStringList l;
    foreach(QSqlRecord r, records)
    {
        profileClient t1(r);
        l << t1.profile();
    }

    return l;
}

QStringList profileClient::profilesDisponibles(bool disponible, int idTypeClient)
{
    profileClient t;
    QString condition = QObject::tr("%1 = %2 AND %3 = %4")
                        .arg(t.disponibleName())
                        .arg(disponible)
                        .arg(t.idTypeClientName())
                        .arg(idTypeClient);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ProfileClient::Libelle, condition);

    QStringList l;
    foreach(QSqlRecord r, records)
    {
        profileClient t1(r);
        l << t1.profile();
    }

    return l;
}

QList<profileClient> profileClient::profilesClientDisponibles(bool disponible)
{
    profileClient t;
    QString condition = QObject::tr("%1 = %2")
                        .arg(t.disponibleName())
                        .arg(disponible);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ProfileClient::Libelle, condition);

    QList<profileClient> l;
    foreach(QSqlRecord r, records)
    {
        profileClient t1(r);
        l << t1;
    }

    return l;
}

QList<profileClient> profileClient::profilesClientDisponibles(bool disponible, int idTypeClient)
{
    profileClient t;
    QString condition = QObject::tr("%1 = %2 AND %3 = %4")
                        .arg(t.disponibleName())
                        .arg(disponible)
                        .arg(t.idTypeClientName())
                        .arg(idTypeClient);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(ProfileClient::Libelle, condition);

    QList<profileClient> l;
    foreach(QSqlRecord r, records)
    {
        profileClient t1(r);
        l << t1;
    }

    return l;
}
