#ifndef RECUINITIAL_H
#define RECUINITIAL_H

#include "MesTables_global.h"

#include "Entree.h"

class MESTABLESSHARED_EXPORT recuInitial : public Entree
{
public:
    enum IdRecu
    {
        IdLocation = 1, IdRestauration = 2, IdReservation = 3, IdDepotSurCompteClient = 4,
        IdRestitutionLocation = 5, IdRestitutionAvanceLocation = 6, IdRetraitCompteClient = 7,
        IdRestitutionRestauration = 8, IdBar = 9, IdRestitutionBar = 10
    };

public:
    recuInitial();
    recuInitial(int id);
    recuInitial(const QSqlRecord & record);
    recuInitial(const recuInitial & s);

    void setIdService(int idService);
    void setTypeDeRecu(QString type);
    void setInitial(QString initial);
    void setNumero(int num);

    int idRecuInitial()const;
    int idService()const;
    QString typeDeRecu()const;
    QString initial()const;
    int numero()const;

    inline QString idRecuInitialName()const{return m_fieldsName.at(RecuInitial::Id::IdRecuInitial);};
    inline QString idServiceName()const{return m_fieldsName.at(RecuInitial::Id::IdService);};
    inline QString typeDeRecuName()const{return m_fieldsName.at(RecuInitial::Id::TypeDeRecu);};
    inline QString initialName()const{return m_fieldsName.at(RecuInitial::Id::Initial);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // RECUINITIAL_H
