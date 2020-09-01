#ifndef SERVICEENTREPRISE_H
#define SERVICEENTREPRISE_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT serviceEntreprise : public Entree
{
public:
    serviceEntreprise();
    serviceEntreprise(int idSe);
    serviceEntreprise(const QSqlRecord & record);
    serviceEntreprise(const serviceEntreprise & s);

    void setNom(QString nom);

    int idSe()const;
    QString nom()const;

    inline QString idSeName()const{return m_fieldsName.at(ServiceEntreprise::Id::Id_se);};
    inline QString nomName()const{return m_fieldsName.at(ServiceEntreprise::Id::Nom);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // SERVICEENTREPRISE_H
