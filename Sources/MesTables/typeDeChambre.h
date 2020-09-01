#ifndef TYPEDECHAMBRE_H
#define TYPEDECHAMBRE_H

#include "MesTables_global.h"

/* classes qt */
#include <QDate>
#include <QDateTime>
#include <QStringList>

/* classes personnalisées */
#include "Entree.h"

class MESTABLESSHARED_EXPORT typeDeChambre : public Entree
{
public:
    typeDeChambre();
    typeDeChambre(int id);
    typeDeChambre(const QSqlRecord & record);
    typeDeChambre(const typeDeChambre & s);

    void setType(QString type);
    void setDisponible(bool disponible);

    QString type()const;
    int idTypeDeChambre()const;
    bool disponible()const;

    inline QString idTypeDeChambreName()const{return m_fieldsName.at(TypeDeChambre::Id::IdTypeDeChambre);};
    inline QString typeName()const{return m_fieldsName.at(TypeDeChambre::Id::Type);};
    inline QString disponibleName()const{return m_fieldsName.at(TypeDeChambre::Id::Disponible);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QStringList typesDisponibles(bool disponible);
    static QList<typeDeChambre> typeDeChambreDisponibles(bool disponible);
};


#endif // TYPEDECHAMBRE_H
