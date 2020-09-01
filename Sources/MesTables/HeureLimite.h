#ifndef HEURELIMITE_H
#define HEURELIMITE_H

#include "MesTables_global.h"

#include <QTime>
#include <QDateTime>

#include "Entree.h"

class MESTABLESSHARED_EXPORT HeureLimite : public Entree
{
public:
    HeureLimite();
    HeureLimite(int numHeure);
    HeureLimite(const QSqlRecord & record);
    HeureLimite(const HeureLimite & s);

    void setHeureFinOccupation(QTime time);
    void setTempsTolerance(int minutes);
    void setLastHourSyst(QDateTime hourSyst);
    void setDebutActivation(QDateTime debut);
    void setDureeActivation(int duree);
    void setUtilEnregistrer(bool enregistrer);
    void setDureeRestante(int duree);
    void setDureeTolerance(int duree);
    void setValeurModifiee(int valeur);
    void setIID(long iid);
    void setTempsLocAnnulation(int nbMinutes);
    void setDebutActivites(QDateTime date);

    int numHeure()const;
    QTime heureFinOccupation()const;
    int tempsTolerance()const;
    QDateTime lastHourSyst()const;
    QDateTime debutActivation()const;
    int dureeActivation()const;
    QDateTime finActivation()const;
    bool utilEnregistre()const;
    int dureeRestante()const;
    int dureeTolerance()const;
    int valeurModifiee()const;
    long IID()const;
    int tempsLocAnnulation()const;
    QDateTime debutActivites()const;

    inline QString numHeureName()const{return m_fieldsName.at(HeureBD::Id::NumHeure);};
    inline QString heureFinOccupName()const{return m_fieldsName.at(HeureBD::Id::HeureFinOccupation);};
    inline QString tempsDeTolName()const{return m_fieldsName.at(HeureBD::Id::TempsDeTol);};
    inline QString lastHourSystName()const{return m_fieldsName.at(HeureBD::Id::LastHourSys);};
    inline QString debutActivitesName()const{return m_fieldsName.at(HeureBD::Id::DebutActivites);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QDateTime currentHourSyst();
};

#endif // HEURELIMITE_H
