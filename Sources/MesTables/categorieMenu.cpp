#include "categorieMenu.h"

categorieMenu::categorieMenu()
{
    constructeur();
}

categorieMenu::categorieMenu(const QSqlRecord &record)
{
    constructeur(record);
}

categorieMenu::categorieMenu(const categorieMenu & s)
{
    constructeur(s);
}

categorieMenu::categorieMenu(int id)
{
    constructeur(id);
}

QString categorieMenu::libelle()const
{
    return m_record.value(CategorieMenu::Id::Libelle).toString();
}

int categorieMenu::idTypeCatMenu()const
{
    return m_record.value(CategorieMenu::Id::IdTypeCatMenu).toInt();
}

bool categorieMenu::supprimee()const
{
    return m_record.value(CategorieMenu::Id::Supprimee).toBool();
}

int categorieMenu::idCatMenu()const
{
    return m_record.value(CategorieMenu::Id::IdCategorieMenu).toInt();
}

QVariant categorieMenu::cle() const
{
    return idCatMenu();
}

QString categorieMenu::libelleDeCle() const
{
    return m_record.fieldName(CategorieMenu::Id::IdCategorieMenu);
}

QString categorieMenu::tableName() const
{
    return CategorieMenu::Libelle;
}

void categorieMenu::setLibelle(QString libelle)
{
    m_record.setValue(CategorieMenu::Id::Libelle, libelle);
    tableModifiee(true);
}

void categorieMenu::setIdTypeCatMenu(int id)
{
    m_record.setValue(CategorieMenu::Id::IdTypeCatMenu, id);
    tableModifiee(true);
}

void categorieMenu::setSupprimee(bool suppr)
{
    m_record.setValue(CategorieMenu::Id::Supprimee, suppr);
    tableModifiee(true);
}

