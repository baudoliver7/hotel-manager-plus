#include "operationsComptables.h"

operationsComptables::operationsComptables()
{
    constructeur();
}

operationsComptables::operationsComptables(int idOpc)
{
    constructeur(idOpc);
}

operationsComptables::operationsComptables(const QSqlRecord &record)
{
    constructeur(record);
}

operationsComptables::operationsComptables(const operationsComptables & opc)
{
    constructeur(opc);
}

int operationsComptables::idOpc()const
{
    return m_record.value(OperationsComptables::Id::IdOpc).toInt();
}

int operationsComptables::numOperation()const
{
    return m_record.value(OperationsComptables::Id::NumeroOpc).toInt();
}

int operationsComptables::debit()const
{
    return m_record.value(OperationsComptables::Id::Debit).toInt();
}

int operationsComptables::credit()const
{
    return m_record.value(OperationsComptables::Id::Credit).toInt();
}

int operationsComptables::numeroCpt()const
{
    return m_record.value(OperationsComptables::Id::NumeroCpt).toInt();
}

bool operationsComptables::supprime()const
{
   return m_record.value(OperationsComptables::Id::Supprime).toBool();
}

bool operationsComptables::enDiffere()const
{
   return m_record.value(OperationsComptables::Id::EnDiffere).toBool();
}

QDate operationsComptables::date()const
{
    return m_record.value(OperationsComptables::Id::Date).toDate();
}

QString operationsComptables::description() const
{
    return m_record.value(OperationsComptables::Id::Description).toString();
}
QString operationsComptables::matriculeAgent() const
{
    return m_record.value(OperationsComptables::Id::MatriculeAgent).toString();
}

void operationsComptables::setDate(QDate date)
{
    m_record.setValue(OperationsComptables::Id::Date, date);
    tableModifiee(true);
}

void operationsComptables::setDescription(QString description)
{
    m_record.setValue(OperationsComptables::Id::Description, description);
    tableModifiee(true);
}

void operationsComptables::setNumOperation(int numOpc)
{
    m_record.setValue(OperationsComptables::Id::NumeroOpc, numOpc);
    tableModifiee(true);
}

void operationsComptables::setSupprime(bool supprime)
{
    m_record.setValue(OperationsComptables::Id::Supprime, supprime);
    tableModifiee(true);
}

void operationsComptables::setEnDiffere(bool enDiffere)
{
    m_record.setValue(OperationsComptables::Id::EnDiffere, enDiffere);
    tableModifiee(true);
}

void operationsComptables::setMatriculeAgent(QString matricule)
{
    m_record.setValue(OperationsComptables::Id::MatriculeAgent, matricule);
    tableModifiee(true);
}

void operationsComptables::setCredit(int credit)
{
    m_record.setValue(OperationsComptables::Id::Credit, credit);
    tableModifiee(true);
}

void operationsComptables::setNumeroCpt(int num)
{
    m_record.setValue(OperationsComptables::Id::NumeroCpt, num);
    tableModifiee(true);
}

void operationsComptables::setDebit(int debit)
{
    m_record.setValue(OperationsComptables::Id::Debit, debit);
    tableModifiee(true);
}

QVariant operationsComptables::cle() const
{
    return idOpc();
}

QString operationsComptables::libelleDeCle() const
{
    return m_record.fieldName(OperationsComptables::Id::IdOpc);
}

QString operationsComptables::tableName() const
{
    return OperationsComptables::Libelle;
}

// fonctions spécialisées

QList<QSqlRecord> operationsComptables::opc_records(int numCpt, QDate debut, QDate fin)
{
    operationsComptables op;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND %4 = %5 AND %6 = %7")
                        .arg(op.dateName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(op.numCptName())
                        .arg(numCpt)
                        .arg(op.supprimeName())
                        .arg(false);

    return InfosSurBD::enregistrements(OperationsComptables::Libelle, condition);
}

int operationsComptables::debit(int numCpt, QDate debut, QDate fin)
{
    QList<QSqlRecord> records;
    records << opc_records(numCpt, debut, fin);

    int somme = 0;
    foreach(QSqlRecord record, records)
    {
        operationsComptables opc(record);
        somme += opc.debit();
    }

    return somme;
}

int operationsComptables::debitAnnuel(int numCpt, int year)
{
    QDate debut(year, 1, 1);
    QDate fin(year, 12, 31);

    return debit(numCpt, debut, fin);
}

int operationsComptables::credit(int numCpt, QDate debut, QDate fin)
{
    QList<QSqlRecord> records;
    records << opc_records(numCpt, debut, fin);

    int somme = 0;
    foreach(QSqlRecord record, records)
    {
        operationsComptables opc(record);
        somme += opc.credit();
    }

    return somme;
}

int operationsComptables::creditAnnuel(int numCpt, int year)
{
    QDate debut(year, 1, 1);
    QDate fin(year, 12, 31);

    return credit(numCpt, debut, fin);
}

operationsComptables operationsComptables::lastOperation()
{
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(OperationsComptables::Libelle);

    if(records.isEmpty())
    {
        // table vide
        return operationsComptables();
    }else
    {
        return operationsComptables(records.last());
    }
}

int operationsComptables::numeroLastOperation()
{
    operationsComptables op = operationsComptables::lastOperation();

    if(op.existe())
    {
        return op.numOperation();
    }else
    {
        return 0;
    }
}

QList<QSqlRecord> operationsComptables::operationsComptables_record(int numeroOp)
{
    operationsComptables op;
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(OperationsComptables::Libelle, QObject::tr("%1 = %2 AND %3 = %4")
                                           .arg(op.numOperationName())
                                           .arg(numeroOp)
                                           .arg(op.supprimeName())
                                           .arg(false));

    return records;
}
