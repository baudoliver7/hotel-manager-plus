#include "repasCompletResto.h"

repasCompletResto::repasCompletResto()
{
    constructeur();
}

repasCompletResto::repasCompletResto(const QSqlRecord &record)
{
    constructeur(record);
}

repasCompletResto::repasCompletResto(const repasCompletResto & s)
{
    constructeur(s);
}

repasCompletResto::repasCompletResto(int id)
{
    constructeur(id);
}

repasCompletResto::repasCompletResto(QString facture)
{
    constructeur();

    QString condition = QObject::tr("%1 = '%2'")
                        .arg(factureName())
                        .arg(facture);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(tableName(), condition);

    if(!records.isEmpty())
        m_record = records.first();
}

int repasCompletResto::idRepasCResto()const
{
    return m_record.value(RepasCompletResto::Id::IdRepasCResto).toInt();
}

int repasCompletResto::codeClient()const
{
    return m_record.value(RepasCompletResto::Id::CodeClient).toInt();
}

int repasCompletResto::totalAPayer()const
{
    return m_record.value(RepasCompletResto::Id::TotalAPayer).toInt();
}

int repasCompletResto::idTableResto()const
{
    return m_record.value(RepasCompletResto::Id::IdTableResto).toInt();
}

int repasCompletResto::dureeEnMinutes()const
{
    return m_record.value(RepasCompletResto::Id::DureeEnMinutes).toInt();
}

QDateTime repasCompletResto::dateArrivee()const
{
    return m_record.value(RepasCompletResto::Id::DateArrivee).toDateTime();
}

QDateTime repasCompletResto::dateDepart()const
{
    return m_record.value(RepasCompletResto::Id::DateDepart).toDateTime();
}

QString repasCompletResto::matriculeCaissier()const
{
    return m_record.value(RepasCompletResto::Id::MatriculeCaissier).toString();
}

QString repasCompletResto::facture()const
{
    return m_record.value(RepasCompletResto::Id::Facture).toString();
}

int repasCompletResto::montantTotalEncaisse()const
{
    return m_record.value(RepasCompletResto::Id::MontantTotalEncaisse).toInt();
}

bool repasCompletResto::factureMiseAJour()const
{
    return m_record.value(RepasCompletResto::Id::FactureMiseAJour).toBool();
}

int repasCompletResto::numOccupation()const
{
    return m_record.value(RepasCompletResto::Id::NumOccupation).toInt();
}

int repasCompletResto::totalAPayerSanSRemise()const
{
    QList<QSqlRecord> records;
    records = conso_resto_records();

    int frais = 0;
    foreach(QSqlRecord r, records)
    {
        consoResto cr(r);
        frais += menuResto(cr.idMenu()).prix() * cr.nbMenu();
    }

    return frais;
}

int repasCompletResto::reste()const
{
    int r = totalAPayer() - montantTotalEncaisse();
    if(r <= 0)
        return 0;

    return r;
}

void repasCompletResto::setIdTableResto(int id)
{
    m_record.setValue(RepasCompletResto::Id::IdTableResto, id);
    tableModifiee(true);
}

void repasCompletResto::setCodeClient(int code)
{
    m_record.setValue(RepasCompletResto::Id::CodeClient, code);
    tableModifiee(true);
}

void repasCompletResto::setDateArrivee(QDateTime date)
{
    m_record.setValue(RepasCompletResto::Id::DateArrivee, date);
    tableModifiee(true);
}

void repasCompletResto::setDateDepart(QDateTime date)
{
    m_record.setValue(RepasCompletResto::Id::DateDepart, date);
    tableModifiee(true);
}

void repasCompletResto::setDureeEnMinutes(int minutes)
{
    m_record.setValue(RepasCompletResto::Id::DureeEnMinutes, minutes);
    tableModifiee(true);
}

void repasCompletResto::setFacture(QString numero)
{
    m_record.setValue(RepasCompletResto::Id::Facture, numero);
    tableModifiee(true);
}

void repasCompletResto::setMontantTotalEncaisse(int montant)
{
    m_record.setValue(RepasCompletResto::Id::MontantTotalEncaisse, montant);
    tableModifiee(true);
}

void repasCompletResto::setFactureMiseAJour(bool miseAjour)
{
    m_record.setValue(RepasCompletResto::Id::FactureMiseAJour, miseAjour);
    tableModifiee(true);
}

void repasCompletResto::setNumOccupation(int num)
{
    m_record.setValue(RepasCompletResto::Id::NumOccupation, num);
    tableModifiee(true);
}

void repasCompletResto::setMatriculeCaissier(QString matricule)
{
    m_record.setValue(RepasCompletResto::Id::MatriculeCaissier, matricule);
    tableModifiee(true);
}

void repasCompletResto::setTotalAPayer(int somme)
{
    m_record.setValue(RepasCompletResto::Id::TotalAPayer, somme);
    tableModifiee(true);
}

QVariant repasCompletResto::cle() const
{
    return idRepasCResto();
}

QString repasCompletResto::libelleDeCle() const
{
    return m_record.fieldName(RepasCompletResto::Id::IdRepasCResto);
}

QString repasCompletResto::tableName() const
{
    return RepasCompletResto::Libelle;
}

QList<QSqlRecord> repasCompletResto::repasCompletResto_records(QDate debut, QDate fin)
{
    repasCompletResto rcr;
    QString condition = QObject::tr("DATE(%1) BETWEEN '%2' AND '%3'")
                        .arg(rcr.dateArriveeName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate));

    return InfosSurBD::enregistrements(RepasCompletResto::Libelle, condition);
}

QList<QSqlRecord> repasCompletResto::repasCompletResto_records_termines(QDate debut, QDate fin)
{
    repasCompletResto rcr;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND %4 is NOT NULL")
                        .arg(rcr.dateArriveeName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(rcr.dateDepartName());

    return InfosSurBD::enregistrements(RepasCompletResto::Libelle, condition);
}

QList<QSqlRecord> repasCompletResto::repasCompletResto_records_termines(QDate debut, QDate fin, QString matricule)
{
    repasCompletResto rcr;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND %4 is NOT NULL AND %5 = '%6'")
                        .arg(rcr.dateArriveeName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(rcr.dateDepartName())
                        .arg(rcr.matriculeCaissierName())
                        .arg(matricule);

    return InfosSurBD::enregistrements(RepasCompletResto::Libelle, condition);
}

QList<QSqlRecord> repasCompletResto::repasCompletResto_records(QDate debut, QDate fin, bool factureMiseAJour)
{
    repasCompletResto rcr;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND %4 = %5")
                        .arg(rcr.dateArriveeName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(rcr.factureMiseAJourName())
                        .arg(factureMiseAJour);

    return InfosSurBD::enregistrements(RepasCompletResto::Libelle, condition);
}

QList<QSqlRecord> repasCompletResto::repasCompletResto_records_termines(QDate debut, QDate fin, bool factureMiseAJour)
{
    repasCompletResto rcr;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND %4 is NOT NULL AND %5 = %6")
                        .arg(rcr.dateArriveeName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(rcr.factureMiseAJourName())
                        .arg(factureMiseAJour);

    return InfosSurBD::enregistrements(RepasCompletResto::Libelle, condition);
}

QList<QSqlRecord> repasCompletResto::repasCompletResto_records_termines(QDate debut, QDate fin, QString matricule, bool factureMiseAJour)
{
    repasCompletResto rcr;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND %4 is NOT NULL AND %5 = '%6' AND %7 = %8")
                        .arg(rcr.dateArriveeName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(rcr.dateDepartName())
                        .arg(rcr.matriculeCaissierName())
                        .arg(matricule)
                        .arg(rcr.factureMiseAJourName())
                        .arg(factureMiseAJour);

    return InfosSurBD::enregistrements(RepasCompletResto::Libelle, condition);
}

repasCompletResto repasCompletResto::selectionnerRepasCResto(int idTableResto)
{
    repasCompletResto rcr;
    QString condition = QObject::tr("%1 = %2 AND %3 is NULL")
                        .arg(rcr.idTableRestoName())
                        .arg(idTableResto)
                        .arg(rcr.dateDepartName());


    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(RepasCompletResto::Libelle, condition);

    if(records.isEmpty())
        return rcr;
    else
        return repasCompletResto(records.first());
}

int repasCompletResto::reglerMontantTotal(int & montantVerse)
{
    int montantResto = 0;
    if(reste() > 0 && reste() <= montantVerse)
    {
        montantVerse -= reste();
        montantResto = reste();
        setMontantTotalEncaisse(montantTotalEncaisse() + reste());
    }else
    {
        if(reste() > montantVerse)
        {
            setMontantTotalEncaisse(montantTotalEncaisse() + montantVerse);
            montantResto = montantVerse;
            montantVerse = 0;
        }
    }

    return montantResto;
}

int repasCompletResto::restituerMontantTotal(int & montantVerse)
{
    int montant = 0;
    if(montantTotalEncaisse() > 0 && montantTotalEncaisse() <= montantVerse)
    {
        montantVerse -= montantTotalEncaisse();
        montant = montantTotalEncaisse();
        setMontantTotalEncaisse(0);
    }else
    {
        if(montantTotalEncaisse() > montantVerse)
        {
            setMontantTotalEncaisse(montantTotalEncaisse() - montantVerse);
            montant = montantVerse;
            montantVerse = 0;
        }
    }

    return montant; // montant restitué
}

QList<QSqlRecord> repasCompletResto::conso_resto_records()const
{
    consoResto cr;
    QString condition  = QString("%1 = %2").arg(cr.idRepasCRestoName()).arg(idRepasCResto());

    return InfosSurBD::enregistrements(cr.tableName(), condition);
}
