#ifndef MODEDEPAYEMENT_H
#define MODEDEPAYEMENT_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT modeDePayement : public Entree
{
public:
    enum TypeMode
    {
        Cash = 1, Cheque = 2, CarteDeCredit = 3, CompteClient = 4
    };

public:
    modeDePayement();
    modeDePayement(int id);
    modeDePayement(QString mode);
    modeDePayement(const QSqlRecord & record);
    modeDePayement(const modeDePayement & s);

    void setMode(QString mode);

    QString mode()const;
    int idModeDePayement()const;

    inline QString idModeDePayementName()const{return m_fieldsName.at(ModeDePayement::Id::IdModeDePayement);};
    inline QString modeName()const{return m_fieldsName.at(ModeDePayement::Id::Mode);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QStringList chargerModeDePayement();
    static QStringList chargerModeDePayementSansCompteClient();
};

#endif // MODEDEPAYEMENT_H
