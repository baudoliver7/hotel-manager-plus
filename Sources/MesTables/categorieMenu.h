#ifndef CATEGORIEMENU_H
#define CATEGORIEMENU_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT categorieMenu : public Entree
{
public:
    categorieMenu();
    categorieMenu(int id);
    categorieMenu(const QSqlRecord & record);
    categorieMenu(const categorieMenu & s);

    void setLibelle(QString libelle);
    void setIdTypeCatMenu(int id);
    void setSupprimee(bool suppr);

    int idCatMenu()const;
    QString libelle()const;
    int idTypeCatMenu()const;
    bool supprimee()const;

    inline QString idCatMenuName()const{return m_fieldsName.at(CategorieMenu::Id::IdCategorieMenu);};
    inline QString libelleName()const{return m_fieldsName.at(CategorieMenu::Id::Libelle);};
    inline QString idTypeCatMenuName()const{return m_fieldsName.at(CategorieMenu::Id::IdTypeCatMenu);};
    inline QString supprimeeName()const{return m_fieldsName.at(CategorieMenu::Id::Supprimee);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const;
};

#endif // CATEGORIEMENU_H
