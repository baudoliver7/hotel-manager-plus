#ifndef OPERATIONSERVICE_H
#define OPERATIONSERVICE_H

#include "MesTables_global.h"

#include <QDateTime>

#include "Entree.h"

class MESTABLESSHARED_EXPORT operationService : public Entree
{
public:
    operationService();
    operationService(int id);
    operationService(const QSqlRecord & record);
    operationService(const operationService & s);

    void setDate(QDateTime date);
    void setLibelle(QString libelle);
    void setMontantEncaisse(int montant);
    void setRecu(QString recu);
    void setMatriculeAgent(QString matricule);
    void setCloturee(bool cloturee);
    void setIdModeDePayement(int id);
    void setIdTypeOperation(int id);
    void setIdClotureService(int id);
    void setIdTypeRecu(int id);
    void setDepouille(bool depouille);
    void setEstUneEntree(bool entree);    
    void setTableTypeOperation(QString table);

    int idOperationService()const;
    QString libelle()const;
    QString recu()const;
    QString matriculeAgent()const;
    int montantEncaisse()const;
    QDateTime date()const;
    bool cloturee()const;
    int idModeDePayement()const;
    int idTypeOperation()const;
    int idClotureService()const;
    int idTypeRecu()const;
    bool depouille()const;
    bool estUneEntree()const;
    QString tableTypeOperation()const;

    inline QString idOperationServiceName()const{return m_fieldsName.at(OperationService::Id::IdOperationService);};
    inline QString libelleName()const{return m_fieldsName.at(OperationService::Id::Libelle);};
    inline QString recuName()const{return m_fieldsName.at(OperationService::Id::Recu);};
    inline QString matriculeAgentName()const{return m_fieldsName.at(OperationService::Id::MatriculeAgent);};
    inline QString montantEncaisseName()const{return m_fieldsName.at(OperationService::Id::MontantEncaisse);};
    inline QString dateName()const{return m_fieldsName.at(OperationService::Id::Date);};
    inline QString clotureeName()const{return m_fieldsName.at(OperationService::Id::Cloturee);};
    inline QString idModeDePayementName()const{return m_fieldsName.at(OperationService::Id::IdModeDePayement);};
    inline QString idTypeOperationName()const{return m_fieldsName.at(OperationService::Id::IdTypeOperation);};
    inline QString idClotureServiceName()const{return m_fieldsName.at(OperationService::Id::IdClotureService);};
    inline QString idTypeRecuName()const{return m_fieldsName.at(OperationService::Id::IdTypeRecu);};
    inline QString depouilleName()const{return m_fieldsName.at(OperationService::Id::Depouille);};
    inline QString estUneEntreeName()const{return m_fieldsName.at(OperationService::Id::EstUneEntree);};
    inline QString tableOperationName()const{return m_fieldsName.at(OperationService::Id::TableTypeOperation);};

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> os_records(QDate debut, QDate fin, QString matricule, bool cloturee);
    static QList<QSqlRecord> os_records(QString matricule, bool cloturee);
    static bool osExisteEtEstCloturee(int idTypeDuRecu, int idTypeOperation, bool estUnGroupe);
};

#endif // OPERATIONSERVICE_H
