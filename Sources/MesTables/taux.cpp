#include "taux.h"

taux::taux()
{
    constructeur();
}

taux::taux(const QSqlRecord &record)
{
    constructeur(record);
}

taux::taux(const taux & s)
{
    constructeur(s);
}

taux::taux(int id)
{
    constructeur(id);
}

QString taux::nom()const
{
    return m_record.value(Taux::Id::Nom).toString();
}

float taux::valeur()const
{
    return m_record.value(Taux::Id::Valeur).toFloat();
}

int taux::idTaux()const
{
    return m_record.value(Taux::Id::IdTaux).toInt();
}

QVariant taux::cle() const
{
    return idTaux();
}

QString taux::libelleDeCle() const
{
    return m_record.fieldName(Taux::Id::IdTaux);
}

QString taux::tableName() const
{
    return Taux::Libelle;
}

void taux::setNom(QString nom)
{
    m_record.setValue(Taux::Id::Nom, nom);
    tableModifiee(true);
}

void taux::setValeur(float valeur)
{
    m_record.setValue(Taux::Id::Valeur, valeur);
    tableModifiee(true);
}
