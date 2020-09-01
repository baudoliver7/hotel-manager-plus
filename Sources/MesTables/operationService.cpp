#include "operationService.h"

operationService::operationService()
{
    constructeur();
}

operationService::operationService(const QSqlRecord &record)
{
    constructeur(record);
}

operationService::operationService(const operationService & s)
{
    constructeur(s);
}

operationService::operationService(int id)
{
    constructeur(id);
}

QString operationService::libelle()const
{
    return m_record.value(OperationService::Id::Libelle).toString();
}

int operationService::idOperationService()const
{
    return m_record.value(OperationService::Id::IdOperationService).toInt();
}

QString operationService::recu()const
{
    return m_record.value(OperationService::Id::Recu).toString();
}

QDateTime operationService::date()const
{
    return m_record.value(OperationService::Id::Date).toDateTime();
}

int operationService::montantEncaisse()const
{
    return m_record.value(OperationService::Id::MontantEncaisse).toInt();
}

QString operationService::matriculeAgent()const
{
    return m_record.value(OperationService::Id::MatriculeAgent).toString();
}

bool operationService::cloturee()const
{
    return m_record.value(OperationService::Id::Cloturee).toBool();
}

int operationService::idModeDePayement()const
{
    return m_record.value(OperationService::Id::IdModeDePayement).toInt();
}

int operationService::idTypeOperation()const
{
    return m_record.value(OperationService::Id::IdTypeOperation).toInt();
}

int operationService::idClotureService()const
{
    return m_record.value(OperationService::Id::IdClotureService).toInt();
}

int operationService::idTypeRecu()const
{
    return m_record.value(OperationService::Id::IdTypeRecu).toInt();
}

bool operationService::depouille()const
{
    return m_record.value(OperationService::Id::Depouille).toBool();
}

bool operationService::estUneEntree()const
{
    return m_record.value(OperationService::Id::EstUneEntree).toBool();
}

QVariant operationService::cle() const
{
    return idOperationService();
}

QString operationService::libelleDeCle() const
{
    return m_record.fieldName(OperationService::Id::IdOperationService);
}

QString operationService::tableTypeOperation() const
{
    return m_record.fieldName(OperationService::Id::TableTypeOperation);
}

QString operationService::tableName() const
{
    return OperationService::Libelle;
}

void operationService::setRecu(QString recu)
{
    m_record.setValue(OperationService::Id::Recu, recu);
    tableModifiee(true);
}

void operationService::setDate(QDateTime date)
{
    m_record.setValue(OperationService::Id::Date, date);
    tableModifiee(true);
}

void operationService::setLibelle(QString libelle)
{
    m_record.setValue(OperationService::Id::Libelle, libelle);
    tableModifiee(true);
}

void operationService::setMatriculeAgent(QString matricule)
{
    m_record.setValue(OperationService::Id::MatriculeAgent, matricule);
    tableModifiee(true);
}

void operationService::setMontantEncaisse(int montant)
{
    m_record.setValue(OperationService::Id::MontantEncaisse, montant);
    tableModifiee(true);
}

void operationService::setCloturee(bool cloturee)
{
    m_record.setValue(OperationService::Id::Cloturee, cloturee);
    tableModifiee(true);
}

void operationService::setIdModeDePayement(int id)
{
    m_record.setValue(OperationService::Id::IdModeDePayement, id);
    tableModifiee(true);
}

void operationService::setIdTypeOperation(int id)
{
    m_record.setValue(OperationService::Id::IdTypeOperation, id);
    tableModifiee(true);
}

void operationService::setIdClotureService(int id)
{
    m_record.setValue(OperationService::Id::IdClotureService, id);
    tableModifiee(true);
}

void operationService::setIdTypeRecu(int id)
{
    m_record.setValue(OperationService::Id::IdTypeRecu, id);
    tableModifiee(true);
}

void operationService::setDepouille(bool depouille)
{
    m_record.setValue(OperationService::Id::Depouille, depouille);
    tableModifiee(true);
}

void operationService::setTableTypeOperation(QString type)
{
    m_record.setValue(OperationService::Id::TableTypeOperation, type);
    tableModifiee(true);
}

void operationService::setEstUneEntree(bool entree)
{
    m_record.setValue(OperationService::Id::EstUneEntree, entree);
    tableModifiee(true);
}

QList<QSqlRecord> operationService::os_records(QDate debut, QDate fin, QString matricule, bool cloturee)
{
    operationService os;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND %4 = '%5' AND %6 = %7")
                        .arg(os.dateName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(os.matriculeAgentName())
                        .arg(matricule)
                        .arg(os.clotureeName())
                        .arg(cloturee);

    return InfosSurBD::enregistrements(os.tableName(), condition);
}

QList<QSqlRecord> operationService::os_records(QString matricule, bool cloturee)
{
    operationService os;
    QString condition = QObject::tr("%1 = '%2' AND %3 = %4")
                        .arg(os.matriculeAgentName())
                        .arg(matricule)
                        .arg(os.clotureeName())
                        .arg(cloturee);

    return InfosSurBD::enregistrements(os.tableName(), condition);
}

bool operationService::osExisteEtEstCloturee(int idTypeDuRecu, int idTypeOperation, bool estUnGroupe)
{
    operationService os;
    QString condition = QObject::tr("%1 = %2 AND %3 = %4 AND %5 = %6")
                        .arg(os.idTypeRecuName())
                        .arg(idTypeDuRecu)
                        .arg(os.idTypeOperationName())
                        .arg(idTypeOperation)
                        .arg(os.clotureeName())
                        .arg(true);


    QList<QSqlRecord> records;
    records = InfosSurBD::enregistrements(os.tableName(), condition);

    if(records.isEmpty())
        return false;

    bool existe = false;

    if(estUnGroupe)
    {
        foreach(QSqlRecord r, records)
        {
            operationService os1(r);
            if(os1.libelle().contains("groupe"))
            {
                existe = true;
                break;
            }
        }
    }else
    {
        // n'est pas un groupe
        foreach(QSqlRecord r, records)
        {
            operationService os1(r);
            if(!os1.libelle().contains("groupe"))
            {
                existe = true;
                break;
            }
        }
    }

    return existe;
}
