#ifndef RECEVOIROCCUP_H
#define RECEVOIROCCUP_H

#include "MesTables_global.h"

/* classes qt */
#include <QStringList>
#include <QDateTime>

/* classes personnalisées */
#include "InfosSurBD.h"
#include "Entree.h"

class MESTABLESSHARED_EXPORT recevoirOccup : public Entree
{
public:
    recevoirOccup();
    recevoirOccup(int NumNecevoirOccup);
    recevoirOccup(const QSqlRecord & record);
    recevoirOccup(const recevoirOccup & rc);

    void setDate(QDateTime dateTime);
    void setMatriculeRecepteur(QString matricule);
    void setCodeClient(int code);
    void setNumOccup(int num);

    QDateTime date()const;
    QString matriculeRecepteur()const;
    int numRecevoir()const;
    int codeClient()const;
    int numOccup()const;

    inline QString dateName()const{return m_fieldsName.at(RecevoirOccup::Id::Date);};
    inline QString matriculeRecepteurName()const{return m_fieldsName.at(RecevoirOccup::Id::MatriculeRecepteur);};
    inline QString numRecevoirName()const{return m_fieldsName.at(RecevoirOccup::Id::NumRecevoir);};
    inline QString codeDeClientName()const{return m_fieldsName.at(RecevoirOccup::Id::CodeClient);};
    inline QString numOccupName()const{return m_fieldsName.at(RecevoirOccup::Id::NumOccupation);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

    static recevoirOccup selectionner(int numOccup);
};

#endif // RECEVOIROCCUP_H
