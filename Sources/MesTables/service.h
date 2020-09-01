#ifndef SERVICE_H
#define SERVICE_H

#include "MesTables_global.h"

/* classes qt */
#include <QDate>
#include <QDateTime>
#include <QStringList>

/* classes personnalisées */
#include "Entree.h"

class MESTABLESSHARED_EXPORT service : public Entree
{
public:
    service();
    service(int NumService);
    service(const QSqlRecord & record);
    service(const service & s);

    void setHeureDebut(QDateTime dateTime);
    void setHeureFin(QDateTime dateTime);
    void setMatriculeAgent(QString matricule);

    QDateTime heureDebut()const;
    QDateTime heureFin()const;
    QString matriculeAgent()const;
    int numService()const;
    int dureeEnMinutes()const; // durée en minutes, y compris en cours

    inline QString heureDebutName()const{return m_fieldsName.at(Service::Id::DateDebut);};
    inline QString heureFinName()const{return m_fieldsName.at(Service::Id::DateFin);};
    inline QString matriculeRecepteurName()const{return m_fieldsName.at(Service::Id::MatriculeAgent);};
    inline QString numServiceName()const{return m_fieldsName.at(Service::Id::NumService);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> service_records(QDate debut, QDate fin);
    static QList<QSqlRecord> service_records(QDate debut, QDate fin, QString matricule);
};


#endif // SERVICE_H
