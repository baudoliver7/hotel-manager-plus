#include "serviceEntreprise.h"

serviceEntreprise::serviceEntreprise()
{
    constructeur();
}

serviceEntreprise::serviceEntreprise(const QSqlRecord &record)
{
    constructeur(record);
}

serviceEntreprise::serviceEntreprise(const serviceEntreprise & s)
{
    constructeur(s);
}

serviceEntreprise::serviceEntreprise(int idSe)
{
    constructeur(idSe);
}

QString serviceEntreprise::nom()const
{
    return m_record.value(ServiceEntreprise::Id::Nom).toString();
}

QVariant serviceEntreprise::cle() const
{
    return idSe();
}

QString serviceEntreprise::libelleDeCle() const
{
    return m_record.fieldName(ServiceEntreprise::Id::Id_se);
}

QString serviceEntreprise::tableName() const
{
    return ServiceEntreprise::Libelle;
}

void serviceEntreprise::setNom(QString nom)
{
    m_record.setValue(ServiceEntreprise::Id::Nom, nom);
    tableModifiee(true);
}

int serviceEntreprise::idSe()const
{
    return m_record.value(ServiceEntreprise::Id::Id_se).toInt();
}
