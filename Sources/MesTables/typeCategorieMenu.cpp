#include "typeCategorieMenu.h"

typeCategorieMenu::typeCategorieMenu()
{
    constructeur();
}

typeCategorieMenu::typeCategorieMenu(const QSqlRecord &record)
{
    constructeur(record);
}

typeCategorieMenu::typeCategorieMenu(const typeCategorieMenu & s)
{
    constructeur(s);
}

typeCategorieMenu::typeCategorieMenu(int id)
{
    constructeur(id);
}

QString typeCategorieMenu::libelle()const
{
    return m_record.value(TypeCategorieMenu::Id::Libelle).toString();
}

int typeCategorieMenu::idTypeCatMenu()const
{
    return m_record.value(TypeCategorieMenu::Id::IdTypeCatMenu).toInt();
}

QVariant typeCategorieMenu::cle() const
{
    return idTypeCatMenu();
}

QString typeCategorieMenu::libelleDeCle() const
{
    return m_record.fieldName(TypeCategorieMenu::Id::IdTypeCatMenu);
}

QString typeCategorieMenu::tableName() const
{
    return TypeCategorieMenu::Libelle;
}

void typeCategorieMenu::setLibelle(QString libelle)
{
    m_record.setValue(TypeCategorieMenu::Id::Libelle, libelle);
    tableModifiee(true);
}
