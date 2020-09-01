#ifndef TYPECATEGORIEMENU_H
#define TYPECATEGORIEMENU_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT typeCategorieMenu : public Entree
{
public:
    typeCategorieMenu();
    typeCategorieMenu(int id);
    typeCategorieMenu(const QSqlRecord & record);
    typeCategorieMenu(const typeCategorieMenu & s);

    void setLibelle(QString libelle);

    int idTypeCatMenu()const;
    QString libelle()const;

    inline QString idTypeCatMenuName()const{return m_fieldsName.at(TypeCategorieMenu::Id::IdTypeCatMenu);};
    inline QString libelleName()const{return m_fieldsName.at(TypeCategorieMenu::Id::Libelle);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // TYPECATEGORIEMENU_H
