#ifndef TAUX_H
#define TAUX_H

#include "MesTables_global.h"

/* classes qt */
#include <QDate>
#include <QDateTime>
#include <QStringList>

/* classes personnalisées */
#include "Entree.h"

class MESTABLESSHARED_EXPORT taux : public Entree
{
public:
    enum TypeTaux
    {
        TVA = 1, TT = 2
    };

public:
    taux();
    taux(int id);
    taux(const QSqlRecord & record);
    taux(const taux & s);

    void setNom(QString nom);
    void setValeur(float valeur);

    int idTaux()const;
    QString nom()const;
    float valeur()const;

    inline QString nomName()const{return m_fieldsName.at(Taux::Id::Nom);};
    inline QString valeurName()const{return m_fieldsName.at(Taux::Id::Valeur);};
    inline QString idTauxName()const{return m_fieldsName.at(Taux::Id::IdTaux);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};


#endif // TAUX_H
