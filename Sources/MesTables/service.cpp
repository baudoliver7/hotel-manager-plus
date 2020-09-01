#include "service.h"

service::service()
{
    constructeur();
}

service::service(const QSqlRecord &record)
{
    constructeur(record);
}

service::service(const service & s)
{
    constructeur(s);
}

service::service(int NumService)
{
    constructeur(NumService);
}

QString service::matriculeAgent()const
{
    return m_record.value(Service::Id::MatriculeAgent).toString();
}

QDateTime service::heureDebut()const
{
    return m_record.value(Service::Id::DateDebut).toDateTime();
}

QDateTime service::heureFin()const
{
    return m_record.value(Service::Id::DateFin).toDateTime();
}

int service::numService()const
{
    return m_record.value(Service::Id::NumService).toInt();
}

void service::setHeureDebut(QDateTime dateTime)
{
    m_record.setValue(Service::Id::DateDebut, dateTime);
    tableModifiee(true);
}

void service::setHeureFin(QDateTime dateTime)
{
    m_record.setValue(Service::Id::DateFin, dateTime);
    tableModifiee(true);
}

void service::setMatriculeAgent(QString matricule)
{
    m_record.setValue(Service::Id::MatriculeAgent, matricule);
    tableModifiee(true);
}

QVariant service::cle() const
{
    return numService();
}

QString service::libelleDeCle() const
{
    return m_record.fieldName(Service::Id::NumService);
}

QString service::tableName() const
{
    return Service::Libelle;
}

int service::dureeEnMinutes()const
{
    return heureDebut().daysTo(heureFin()) * 24 * 60 + heureDebut().time().secsTo(heureFin().time())/60;
}

QList<QSqlRecord> service::service_records(QDate debut, QDate fin, QString matricule)
{
    service s;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND (DATE(%4) BETWEEN '%2' AND '%3') AND %5 = '%6'")
                        .arg(s.heureDebutName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(s.heureFinName())
                        .arg(s.matriculeRecepteurName())
                        .arg(matricule);

    return InfosSurBD::enregistrements(s.tableName(), condition);
}

QList<QSqlRecord> service::service_records(QDate debut, QDate fin)
{
    service s;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND (DATE(%4) BETWEEN '%2' AND '%3')")
                        .arg(s.heureDebutName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(s.heureFinName());

    return InfosSurBD::enregistrements(s.tableName(), condition);
}
