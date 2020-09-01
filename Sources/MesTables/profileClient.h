#ifndef PROFILECLIENT_H
#define PROFILECLIENT_H

#include "MesTables_global.h"

/* classes qt */
#include <QDate>
#include <QDateTime>
#include <QStringList>

/* classes personnalisées */
#include "Entree.h"

class MESTABLESSHARED_EXPORT profileClient : public Entree
{
public:
    profileClient();
    profileClient(int id);
    profileClient(const QSqlRecord & record);
    profileClient(const profileClient & s);

    void setProfile(QString profile);
    void setDisponible(bool disponible);
    void setIdTypeClient(int id);

    QString profile()const;
    int idProfile()const;
    bool disponible()const;
    int idTypeClient()const;

    inline QString profileName()const{return m_fieldsName.at(ProfileClient::Id::Profile);};
    inline QString idProfileName()const{return m_fieldsName.at(ProfileClient::Id::IdProfile);};
    inline QString disponibleName()const{return m_fieldsName.at(ProfileClient::Id::Disponible);};
    inline QString idTypeClientName()const{return m_fieldsName.at(ProfileClient::Id::IdTypeClient);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QStringList profilesDisponibles(bool disponible);
    static QStringList profilesDisponibles(bool disponible, int idTypeClient);
    static QList<profileClient> profilesClientDisponibles(bool disponible);
    static QList<profileClient> profilesClientDisponibles(bool disponible, int idTypeClient);

};


#endif // PROFILECLIENT_H
