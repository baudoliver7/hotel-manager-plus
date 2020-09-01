#include "typeDeClient.h"

typeDeClient::typeDeClient()
{
    constructeur();
}

typeDeClient::typeDeClient(const QSqlRecord &record)
{
    constructeur(record);
}

typeDeClient::typeDeClient(const typeDeClient & s)
{
    constructeur(s);
}

typeDeClient::typeDeClient(int id)
{
    constructeur(id);
}

QString typeDeClient::type()const
{
    return m_record.value(TypeDeClient::Id::Type).toString();
}

int typeDeClient::idTypeDeClient()const
{
    return m_record.value(TypeDeClient::Id::IdTypeDeClient).toInt();
}

bool typeDeClient::disponible()const
{
    return m_record.value(TypeDeClient::Id::Disponible).toBool();
}

QVariant typeDeClient::cle() const
{
    return idTypeDeClient();
}

QString typeDeClient::libelleDeCle() const
{
    return m_record.fieldName(TypeDeClient::Id::IdTypeDeClient);
}

QString typeDeClient::tableName() const
{
    return TypeDeClient::Libelle;
}

void typeDeClient::setType(QString type)
{
    m_record.setValue(TypeDeClient::Id::Type, type);
    tableModifiee(true);
}

void typeDeClient::setDisponible(bool disponible)
{
    m_record.setValue(TypeDeClient::Id::Disponible, disponible);
    tableModifiee(true);
}

QStringList typeDeClient::typesDisponibles(bool disponible)
{
    typeDeClient t;
    QString condition = QObject::tr("%1 = %2")
                        .arg(t.disponibleName())
                        .arg(disponible);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(TypeDeClient::Libelle, condition);

    QStringList l;
    foreach(QSqlRecord r, records)
    {
        typeDeClient t1(r);
        l << t1.type();
    }

    return l;
}

QList<typeDeClient> typeDeClient::typeDeClientDisponibles(bool disponible)
{
    typeDeClient t;
    QString condition = QObject::tr("%1 = %2")
                        .arg(t.disponibleName())
                        .arg(disponible);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(TypeDeClient::Libelle, condition);

    QList<typeDeClient> l;
    foreach(QSqlRecord r, records)
    {
        typeDeClient t1(r);
        l << t1;
    }

    return l;
}
