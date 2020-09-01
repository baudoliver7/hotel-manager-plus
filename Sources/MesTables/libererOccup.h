#ifndef LIBEREROCCUP_H
#define LIBEREROCCUP_H

#include "MesTables_global.h"

/* classes qt */
#include <QStringList>
#include <QDateTime>

/* classes personnalisées */
#include "InfosSurBD.h"
#include "Entree.h"

class MESTABLESSHARED_EXPORT libererOccup : public Entree
{
public:
    libererOccup();
    libererOccup(int NumLibererOccup);
    libererOccup(const QSqlRecord & record);
    libererOccup(const libererOccup & rc);

    void setDate(QDateTime dateTime);
    void setMatriculeRecepteur(QString matricule);
    void setCodeClient(int code);
    void setNumOccup(int num);

    QDateTime date()const;
    QString matriculeRecepteur()const;
    int numLiberer()const;
    int codeClient()const;
    int numOccup()const;

    inline QString dateName()const{return m_fieldsName.at(LibererOccup::Id::Date);};
    inline QString matriculeRecepteurName()const{return m_fieldsName.at(LibererOccup::Id::MatriculeRecepteur);};
    inline QString numLibererName()const{return m_fieldsName.at(LibererOccup::Id::NumLiberer);};
    inline QString codeDeClientName()const{return m_fieldsName.at(LibererOccup::Id::CodeClient);};
    inline QString numOccupName()const{return m_fieldsName.at(LibererOccup::Id::NumOccupation);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

    static libererOccup selectionner(int numOccup);
};

#endif // LIBEREROCCUP_H
