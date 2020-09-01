#include "clotureService.h"

clotureService::clotureService()
{
    constructeur();
}

clotureService::clotureService(const QSqlRecord &record)
{
    constructeur(record);
}

clotureService::clotureService(const clotureService & s)
{
    constructeur(s);
}

clotureService::clotureService(int id)
{
    constructeur(id);
}

clotureService::clotureService(QString matricule, QDate date)
{
    constructeur();

    QString condition = QObject::tr("%1 = '%2' AND %3 = '%4'")
                        .arg(matriculeName())
                        .arg(matricule)
                        .arg(dateName())
                        .arg(date.toString(Qt::ISODate));

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(tableName(), condition);

    if(!records.isEmpty())
    {
        m_record = records.first();
    }
}

int clotureService::idClotureService()const
{
    return m_record.value(ClotureService::Id::IdClotureService).toInt();
}

QDate clotureService::date()const
{
    return m_record.value(ClotureService::Id::Date).toDate();
}

int clotureService::montantEncaisse()const
{
    return m_record.value(ClotureService::Id::MontantEncaisse).toInt();
}

int clotureService::montantRestant()const
{
    return m_record.value(ClotureService::Id::MontantRestant).toInt();
}

int clotureService::montantRetire()const
{
    return m_record.value(ClotureService::Id::MontantRetire).toInt();
}

int clotureService::reglementEspece()const
{
    return m_record.value(ClotureService::Id::ReglementEspece).toInt();
}

int clotureService::reglementCheque()const
{
    return m_record.value(ClotureService::Id::ReglementCheque).toInt();
}

int clotureService::reglementCarteDeCredit()const
{
    return m_record.value(ClotureService::Id::ReglementCarteDeCredit).toInt();
}

int clotureService::reglementCompteClient()const
{
    return m_record.value(ClotureService::Id::ReglementCompteClient).toInt();
}

bool clotureService::depouille()const
{
    return m_record.value(ClotureService::Id::Depouille).toBool();
}

int clotureService::depotSurCompteClient()const
{
    return m_record.value(ClotureService::Id::DepotSurCompteClient).toInt();
}


QString clotureService::matriculeAgent()const
{
    return m_record.value(ClotureService::Id::MatriculeAgent).toString();
}

QVariant clotureService::cle() const
{
    return idClotureService();
}

QString clotureService::libelleDeCle() const
{
    return m_record.fieldName(ClotureService::Id::IdClotureService);
}

QString clotureService::tableName() const
{
    return ClotureService::Libelle;
}

void clotureService::setDate(QDate date)
{
    m_record.setValue(ClotureService::Id::Date, date);
    tableModifiee(true);
}

void clotureService::setMatriculeAgent(QString matricule)
{
    m_record.setValue(ClotureService::Id::MatriculeAgent, matricule);
    tableModifiee(true);
}

void clotureService::setDepotSurCompteClient(int depot)
{
    m_record.setValue(ClotureService::Id::DepotSurCompteClient, depot);
    tableModifiee(true);
}

void clotureService::setReglementCompteClient(int montant)
{
    m_record.setValue(ClotureService::Id::ReglementCompteClient, montant);
    tableModifiee(true);
}

void clotureService::setDepouille(bool depouille)
{
    m_record.setValue(ClotureService::Id::Depouille, depouille);
    tableModifiee(true);
}

void clotureService::setMontantEncaisse(int montant)
{
    m_record.setValue(ClotureService::Id::MontantEncaisse, montant);
    tableModifiee(true);
}

void clotureService::setMontantRestant(int montant)
{
    m_record.setValue(ClotureService::Id::MontantRestant, montant);
    tableModifiee(true);
}

void clotureService::setMontantRetire(int montant)
{
    m_record.setValue(ClotureService::Id::MontantRetire, montant);
    tableModifiee(true);
}

void clotureService::setReglementCarteDeCredit(int montant)
{
    m_record.setValue(ClotureService::Id::ReglementCarteDeCredit, montant);
    tableModifiee(true);
}

void clotureService::setReglementCheque(int montant)
{
    m_record.setValue(ClotureService::Id::ReglementCheque, montant);
    tableModifiee(true);
}

void clotureService::setReglementEspece(int montant)
{
    m_record.setValue(ClotureService::Id::ReglementEspece, montant);
    tableModifiee(true);
}
