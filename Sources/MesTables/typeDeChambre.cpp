#include "typeDeChambre.h"

typeDeChambre::typeDeChambre()
{
    constructeur();
}

typeDeChambre::typeDeChambre(const QSqlRecord &record)
{
    constructeur(record);
}

typeDeChambre::typeDeChambre(const typeDeChambre & s)
{
    constructeur(s);
}

typeDeChambre::typeDeChambre(int id)
{
    constructeur(id);
}

QString typeDeChambre::type()const
{
    return m_record.value(TypeDeChambre::Id::Type).toString();
}

int typeDeChambre::idTypeDeChambre()const
{
    return m_record.value(TypeDeChambre::Id::IdTypeDeChambre).toInt();
}

bool typeDeChambre::disponible()const
{
    return m_record.value(TypeDeChambre::Id::Disponible).toBool();
}

QVariant typeDeChambre::cle() const
{
    return idTypeDeChambre();
}

QString typeDeChambre::libelleDeCle() const
{
    return m_record.fieldName(TypeDeChambre::Id::IdTypeDeChambre);
}

QString typeDeChambre::tableName() const
{
    return TypeDeChambre::Libelle;
}

void typeDeChambre::setType(QString type)
{
    m_record.setValue(TypeDeChambre::Id::Type, type);
    tableModifiee(true);
}

void typeDeChambre::setDisponible(bool disponible)
{
    m_record.setValue(TypeDeChambre::Id::Disponible, disponible);
    tableModifiee(true);
}

QStringList typeDeChambre::typesDisponibles(bool disponible)
{
    typeDeChambre t;
    QString condition = QObject::tr("%1 = %2")
                        .arg(t.disponibleName())
                        .arg(disponible);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(TypeDeChambre::Libelle, condition);

    QStringList l;
    foreach(QSqlRecord r, records)
    {
        typeDeChambre t1(r);
        if(t1.disponible())
        {
            l << t1.type();
        }
    }

    return l;
}

QList<typeDeChambre> typeDeChambre::typeDeChambreDisponibles(bool disponible)
{
    typeDeChambre t;
    QString condition = QObject::tr("%1 = %2")
                        .arg(t.disponibleName())
                        .arg(disponible);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(TypeDeChambre::Libelle, condition);

    QList<typeDeChambre> l;
    foreach(QSqlRecord r, records)
    {
        typeDeChambre t1(r);
        if(t1.disponible())
        {
            l << t1;
        }
    }

    return l;
}
