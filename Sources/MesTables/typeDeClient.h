#ifndef TYPEDECLIENT_H
#define TYPEDECLIENT_H

#include "MesTables_global.h"

/* classes qt */
#include <QDate>
#include <QDateTime>
#include <QStringList>

/* classes personnalisées */
#include "Entree.h"

class MESTABLESSHARED_EXPORT typeDeClient : public Entree
{
public:
    typeDeClient();
    typeDeClient(int id);
    typeDeClient(const QSqlRecord & record);
    typeDeClient(const typeDeClient & s);

    void setType(QString type);
    void setDisponible(bool disponible);

    QString type()const;
    int idTypeDeClient()const;
    bool disponible()const;

    inline QString idTypeDeClientName()const{return m_fieldsName.at(TypeDeClient::Id::IdTypeDeClient);};
    inline QString typeName()const{return m_fieldsName.at(TypeDeClient::Id::Type);};
    inline QString disponibleName()const{return m_fieldsName.at(TypeDeClient::Id::Disponible);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QStringList typesDisponibles(bool disponible);
    static QList<typeDeClient> typeDeClientDisponibles(bool disponible);
};


#endif // TYPEDECLIENT_H
