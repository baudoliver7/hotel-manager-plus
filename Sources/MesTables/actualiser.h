#ifndef ACTUALISER_H
#define ACTUALISER_H

#include "MesTables_global.h"

/* classes qt */
#include <QDate>
#include <QDateTime>
#include <QStringList>

/* classes personnalisées */
#include "Entree.h"

class MESTABLESSHARED_EXPORT actualiser : public Entree
{
public:
    actualiser();
    actualiser(QString Table);
    actualiser(const QSqlRecord & record);
    actualiser(const actualiser & s);

    void setTable(QString table);
    void setActual(bool actual);

    QString table()const;
    bool actual()const;

    inline QString actualiserName()const{return m_fieldsName.at(Actualiser::Id::Actual);};
    inline QString tableNameName()const{return m_fieldsName.at(Actualiser::Id::TableName);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // ACTUALISER_H
