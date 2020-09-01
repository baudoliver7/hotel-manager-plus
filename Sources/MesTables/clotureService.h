#ifndef CLOTURESERVICE_H
#define CLOTURESERVICE_H

#include "MesTables_global.h"

#include <QDateTime>

#include "Entree.h"

class MESTABLESSHARED_EXPORT clotureService : public Entree
{
public:
    clotureService();
    clotureService(int id);
    clotureService(QString matricule, QDate date);
    clotureService(const QSqlRecord & record);
    clotureService(const clotureService & s);

    void setDate(QDate date);
    void setMontantEncaisse(int montant);
    void setMontantRestant(int montant);
    void setMontantRetire(int montant);
    void setReglementCheque(int montant);
    void setReglementEspece(int montant);
    void setReglementCarteDeCredit(int montant);
    void setMatriculeAgent(QString matricule);
    void setDepotSurCompteClient(int depot);
    void setReglementCompteClient(int montant);
    void setDepouille(bool depouille);

    int idClotureService()const;
    QDate date()const;
    int montantEncaisse()const;
    int montantRestant()const;
    int reglementCheque()const;
    int reglementEspece()const;
    int reglementCarteDeCredit()const;
    QString matriculeAgent()const;
    int depotSurCompteClient()const;
    int reglementCompteClient()const;
    bool depouille()const;
    int montantRetire()const;

    inline QString idClotureServiceName()const{return m_fieldsName.at(ClotureService::Id::IdClotureService);};
    inline QString dateName()const{return m_fieldsName.at(ClotureService::Id::Date);};
    inline QString matriculeName()const{return m_fieldsName.at(ClotureService::Id::MatriculeAgent);};
    inline QString depotSurCompteClientName()const{return m_fieldsName.at(ClotureService::Id::DepotSurCompteClient);};
    inline QString montantEncaisseName()const{return m_fieldsName.at(ClotureService::Id::MontantEncaisse);};
    inline QString montantRestantName()const{return m_fieldsName.at(ClotureService::Id::MontantRestant);};
    inline QString reglementChequeName()const{return m_fieldsName.at(ClotureService::Id::ReglementCheque);};
    inline QString reglementEspeceName()const{return m_fieldsName.at(ClotureService::Id::ReglementEspece);};
    inline QString reglementCarteDeCreditName()const{return m_fieldsName.at(ClotureService::Id::ReglementCarteDeCredit);};
    inline QString reglementCompteClientName()const{return m_fieldsName.at(ClotureService::Id::ReglementCompteClient);};
    inline QString depouilleName()const{return m_fieldsName.at(ClotureService::Id::Depouille);};
    inline QString montantRetireName()const{return m_fieldsName.at(ClotureService::Id::MontantRetire);};


    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin
};

#endif // CLOTURESERVICE_H
