#include "menuResto.h"

menuResto::menuResto()
{
    constructeur();
}

menuResto::menuResto(const QSqlRecord &record)
{
    constructeur(record);
}

menuResto::menuResto(const menuResto & s)
{
    constructeur(s);
}

menuResto::menuResto(int idMenu)
{
    constructeur(idMenu);
}

QString menuResto::libelle()const
{
    return m_record.value(MenuResto::Id::LibelleMenu).toString();
}

int menuResto::prix()const
{
    return m_record.value(MenuResto::Id::Prix).toInt();
}

int menuResto::idCatMenu()const
{
    return m_record.value(MenuResto::Id::IdCatMenu).toInt();
}

bool menuResto::supprime()const
{
    return m_record.value(MenuResto::Id::Supprime).toBool();
}

int menuResto::idMenuResto()const
{
    return m_record.value(MenuResto::Id::IdMenuResto).toInt();
}

QVariant menuResto::cle() const
{
    return idMenuResto();
}

QString menuResto::libelleDeCle() const
{
    return m_record.fieldName(MenuResto::Id::IdMenuResto);
}

QString menuResto::tableName() const
{
    return MenuResto::Libelle;
}

void menuResto::setLibelle(QString libelle)
{
    m_record.setValue(MenuResto::Id::LibelleMenu, libelle);
    tableModifiee(true);
}

void menuResto::setPrix(int prix)
{
    m_record.setValue(MenuResto::Id::Prix, prix);
    tableModifiee(true);
}

void menuResto::setIdCatMenu(int id)
{
    m_record.setValue(MenuResto::Id::IdCatMenu, id);
    tableModifiee(true);
}

void menuResto::setSupprime(bool supprime)
{
    m_record.setValue(MenuResto::Id::Supprime, supprime);
    tableModifiee(true);
}

