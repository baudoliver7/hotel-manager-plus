#ifndef ANNULEROCCUP_H
#define ANNULEROCCUP_H

#include "MesTables_global.h"

/* classes qt */
#include <QStringList>
#include <QDateTime>

/* classes personnalisées */
#include "InfosSurBD.h"
#include "Entree.h"

class MESTABLESSHARED_EXPORT annulerOccup : public Entree
{
public:
    annulerOccup();
    annulerOccup(int num);
    annulerOccup(const QSqlRecord & record);
    annulerOccup(const annulerOccup & rc);

    void setDate(QDateTime dateTime);
    void setMatriculeRecepteur(QString matricule);
    void setCodeClient(int code);
    void setNumOccup(int num);

    QDateTime date()const;
    QString matriculeRecepteur()const;
    int numAnnuler()const;
    int codeClient()const;
    int numOccup()const;

    inline QString dateName()const{return m_fieldsName.at(AnnulerOccup::Id::Date);};
    inline QString MatriculeRecepteurName()const{return m_fieldsName.at(AnnulerOccup::Id::MatriculeRecepteur);};
    inline QString numAnnulerName()const{return m_fieldsName.at(AnnulerOccup::Id::NumAnnuler);};
    inline QString codeDeClientName()const{return m_fieldsName.at(AnnulerOccup::Id::CodeClient);};
    inline QString numOccupName()const{return m_fieldsName.at(AnnulerOccup::Id::NumOccupation);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

    static annulerOccup selectionner(int numOccup);
};

#endif // ANNULEROCCUP_H
