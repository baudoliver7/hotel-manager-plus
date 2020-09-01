#ifndef RESERVATION_H
#define RESERVATION_H

#include "MesTables_global.h"

/* classes qt */
#include <QDate>
#include <QDateTime>

/* classes personnalisées */
#include "Entree.h"
#include "horloge.h"
#include "HeureLimite.h"

class MESTABLESSHARED_EXPORT reservation : public Entree
{
public:
    reservation();
    reservation(int numReserv);
    reservation(const QSqlRecord & record);
    reservation(const reservation & rv);

    int numReservation()const;
    QDateTime dateDeDemande()const;
    int dureeOccupation()const;
    QDateTime datedEntree()const;
    QDateTime datedSortie()const;
    int cout()const;
    int avance()const;
    int reste()const;
    int codeClient()const;
    int idGroupe()const;
    int idProfileClient()const;

    inline QString numReservName()const{return m_fieldsName.at(Reservation::Id::NumReserv);};
    inline QString dateDeDemandeName()const{return m_fieldsName.at(Reservation::Id::DateDeDemande);};
    inline QString dureeOccupName()const{return m_fieldsName.at(Reservation::Id::DureeOccup);};
    inline QString dateOccupationName()const{return m_fieldsName.at(Reservation::Id::DateOccup);};
    inline QString coutName()const{return m_fieldsName.at(Reservation::Id::Cout);};
    inline QString avanceName()const{return m_fieldsName.at(Reservation::Id::Avance);};
    inline QString codeClientName()const{return m_fieldsName.at(Reservation::Id::CodeClient);};
    inline QString idGroupeName()const{return m_fieldsName.at(Reservation::Id::IdGroupe);};
    inline QString idProfileClientName()const{return m_fieldsName.at(Reservation::Id::IdProfileClient);};

    void setDateDeDemande(QDateTime datetime);
    void setDureeOccupation(int nbJours);
    void setDatedEntree(QDateTime date);
    void setCout(int cout);
    void setAvance(int avance);
    void setCodeClient(int code);
    void setIdGroupe(int id);
    void setIdProfileClient(int id);

    // fonctions spéciales

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> reservation_records(QDate debut, QDate fin);
    static QList<QSqlRecord> reservation_records_en_cours();

};

#endif // RESERVATION_H
