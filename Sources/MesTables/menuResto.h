#ifndef MENURESTO_H
#define MENURESTO_H

#include "MesTables_global.h"

/* classes qt */
#include <QStringList>

/* classes personnalisées */
#include "Entree.h"

class MESTABLESSHARED_EXPORT menuResto : public Entree
{
public:
    menuResto();
    menuResto(int idMenu);
    menuResto(const QSqlRecord & record);
    menuResto(const menuResto & s);

    void setLibelle(QString libelle);
    void setPrix(int prix);
    void setIdCatMenu(int id);
    void setSupprime(bool supprime);

    int idMenuResto()const;
    QString libelle()const;
    int prix()const;
    int idCatMenu()const;
    bool supprime()const;

    inline QString idMenuRestoName()const{return m_fieldsName.at(MenuResto::Id::IdMenuResto);};
    inline QString libelleName()const{return m_fieldsName.at(MenuResto::Id::LibelleMenu);};
    inline QString prixName()const{return m_fieldsName.at(MenuResto::Id::Prix);};
    inline QString idCatMenuName()const{return m_fieldsName.at(MenuResto::Id::IdCatMenu);};
    inline QString supprimeName()const{return m_fieldsName.at(MenuResto::Id::Supprime);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // MENURESTO_H
