#ifndef OPERATIONSCOMPTABLES_H
#define OPERATIONSCOMPTABLES_H

#include "MesTables_global.h"

#include "Entree.h"
#include "horloge.h"
#include <QDate>

class MESTABLESSHARED_EXPORT operationsComptables: public Entree
{
public:
    operationsComptables();
    operationsComptables(int idOpc);
    operationsComptables(const QSqlRecord & record);
    operationsComptables(const operationsComptables & opc);

    int idOpc()const;
    int numOperation()const;
    QDate date()const;
    QString description()const;
    QString matriculeAgent()const;
    int debit()const;
    int credit()const;
    int numeroCpt()const;
    bool supprime()const;
    bool enDiffere()const;

    inline QString idOpcName()const{return m_fieldsName.at(OperationsComptables::Id::IdOpc);};
    inline QString numOperationName()const{return m_fieldsName.at(OperationsComptables::Id::NumeroOpc);};
    inline QString dateName()const{return m_fieldsName.at(OperationsComptables::Id::Date);};
    inline QString descriptionName()const{return m_fieldsName.at(OperationsComptables::Id::Description);};
    inline QString debitName()const{return m_fieldsName.at(OperationsComptables::Id::Debit);};
    inline QString creditName()const{return m_fieldsName.at(OperationsComptables::Id::Credit);};
    inline QString numCptName()const{return m_fieldsName.at(OperationsComptables::Id::NumeroCpt);};
    inline QString enDiffereName()const{return m_fieldsName.at(OperationsComptables::Id::EnDiffere);};
    inline QString supprimeName()const{return m_fieldsName.at(OperationsComptables::Id::Supprime);};
    inline QString matriculeAgentName()const{return m_fieldsName.at(OperationsComptables::Id::MatriculeAgent);};

    void setNumOperation(int numOpc);
    void setDate(QDate date);
    void setDescription(QString description);
    void setDebit(int debit);
    void setCredit(int credit);
    void setNumeroCpt(int num);
    void setSupprime(bool supprime);
    void setEnDiffere(bool enDiffere);
    void setMatriculeAgent(QString matricule);

    //fonctions spécialisées


    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> opc_records(int numCpt, QDate debut, QDate fin);
    static int debit(int numCpt, QDate debut, QDate fin);
    static int credit(int numCpt, QDate debut, QDate fin);
    static int debitAnnuel(int numCpt, int year);
    static int creditAnnuel(int numCpt, int year);
    static operationsComptables lastOperation();
    static QList<QSqlRecord> operationsComptables_record(int numeroOp);
    static int numeroLastOperation();
};

#endif // OPERATIONSCOMPTABLES_H
