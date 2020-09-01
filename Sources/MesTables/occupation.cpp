#include "occupation.h"
#include "factureInitial.h"

occupation::occupation()
{
    constructeur();
}

occupation::occupation(int numOccup)
{
    constructeur(numOccup);
}

occupation::occupation(const QSqlRecord &record)
{
    constructeur(record);
}

occupation::occupation(const occupation &oc)
{
    constructeur(oc);
}

occupation::occupation(const chambre &ch)
{
    constructeur();
    QString condition = QObject::tr("%1 = '%2' AND %3 = %4").arg(identiteChName()).arg(ch.identifiant()).arg(termineeName()).arg(false);
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Occupation::Libelle, condition);

    if(!records.isEmpty())
    {
        m_record = records.first();
    }
}

int occupation::numOccupation()const
{
    return m_record.value(Occupation::Id::NumOccup).toInt();
}

int occupation::dureeOccupation()const
{
    return m_record.value(Occupation::Id::DureeOccup).toInt();
}

int occupation::cout()const
{
    return m_record.value(Occupation::Id::Cout).toInt();
}

int occupation::fraisSupplementaire()const
{
    return m_record.value(Occupation::Id::FraisSup).toInt();
}

int occupation::fraisSupPayee()const
{
    return m_record.value(Occupation::Id::FraisSupPaye).toInt();
}

int occupation::enfAccMoinsDe15()const
{
    return m_record.value(Occupation::Id::EnfAccMoinsDe15).toInt();
}

int occupation::codeClient()const
{
    return m_record.value(Occupation::Id::CodeClient).toInt();
}

void occupation::setCout(int cout)
{
    m_record.setValue(Occupation::Id::Cout, cout);
    tableModifiee(true);
}

void occupation::setPayee(int cout)
{
    m_record.setValue(Occupation::Id::Payee, cout);
    tableModifiee(true);
}

void occupation::setTerminer(bool terminee)
{
    m_record.setValue(Occupation::Id::Terminee,terminee);
    tableModifiee(true);
}

void occupation::setFraisSupplementaire(int somme)
{
    m_record.setValue(Occupation::Id::FraisSup, somme);
    tableModifiee(true);
}

void occupation::setFraisSupPayee(int somme)
{
    m_record.setValue(Occupation::Id::FraisSupPaye, somme);
    tableModifiee(true);
}

void occupation::setEnfAccMoinsDe15(int nb)
{
    m_record.setValue(Occupation::Id::EnfAccMoinsDe15, nb);
    tableModifiee(true);
}

void occupation::setCodeClient(int code)
{
    m_record.setValue(Occupation::Id::CodeClient, code);
    tableModifiee(true);
}

QString occupation::chambreOccupee()const
{
    return m_record.value(Occupation::Id::IdentifiantCh).toString();
}

QString occupation::destinationExacte()const
{
    return m_record.value(Occupation::Id::DestinationExacte).toString();
}

QDateTime occupation::datedEntree()const
{
    return m_record.value(Occupation::Id::DateOccupation).toDateTime();
}

int occupation::payee()const
{
    return m_record.value(Occupation::Id::Payee).toInt();
}

int occupation::reste()const
{
    int r = cout() - payee();
    if(r <= 0)
        return 0;

    return r;
}

int occupation::resteFraisSup()const
{
    int r = fraisSupplementaire() - fraisSupPayee();
    if(r <= 0)
        return 0;

    return r;
}

bool occupation::terminee()const
{
    return m_record.value(Occupation::Id::Terminee).toBool();
}

int occupation::idGroupe()const
{
    return m_record.value(Occupation::Id::IdGroupe).toInt();
}

int occupation::idProfileClient()const
{
    return m_record.value(Occupation::Id::IdProfileClient).toInt();
}

int occupation::fraisRestoNonPayes()const
{
    QList<QSqlRecord> records;
    records = repasConsoNonPayes_record();

    int montantNonRegle = 0;
    foreach(QSqlRecord r, records)
    {
        repasCompletResto rpr(r);
        montantNonRegle += rpr.reste();
    }

    return montantNonRegle;
}

int occupation::fraisResto()const
{
    QList<QSqlRecord> records;
    records = repasConso_record();

    int montantNonRegle = 0;
    foreach(QSqlRecord r, records)
    {
        repasCompletResto rpr(r);
        montantNonRegle += rpr.totalAPayer();
    }

    return montantNonRegle;
}

int occupation::fraisRestoPayes()const
{
    QList<QSqlRecord> records;
    records = repasConso_record();

    int montantNonRegle = 0;
    foreach(QSqlRecord r, records)
    {
        repasCompletResto rpr(r);
        montantNonRegle += rpr.montantTotalEncaisse();
    }

    return montantNonRegle;
}

int occupation::fraisBarNonPayes()const
{
    QList<QSqlRecord> records;
    records = barConsoNonPayes_record();

    int montantNonRegle = 0;
    foreach(QSqlRecord r, records)
    {
        repasCompletResto rpr(r);
        montantNonRegle += rpr.reste();
    }

    return montantNonRegle;
}

int occupation::fraisBar()const
{
    QList<QSqlRecord> records;
    records = barConso_record();

    int montantNonRegle = 0;
    foreach(QSqlRecord r, records)
    {
        repasCompletResto rpr(r);
        montantNonRegle += rpr.totalAPayer();
    }

    return montantNonRegle;
}

int occupation::fraisBarPayes()const
{
    QList<QSqlRecord> records;
    records = barConso_record();

    int montantNonRegle = 0;
    foreach(QSqlRecord r, records)
    {
        repasCompletResto rpr(r);
        montantNonRegle += rpr.montantTotalEncaisse();
    }

    return montantNonRegle;
}

QList<QSqlRecord> occupation::repasConsoNonPayes_record()const
{
    QSqlTableModel model;
    model.setTable(RepasCompletResto::Libelle);
    model.setSort(RepasCompletResto::Id::DateArrivee, Qt::AscendingOrder);

    repasCompletResto rcr;
    QString condition2 = QString("%1 = %2 AND %3 < %4")
                         .arg(rcr.numOccupationName())
                         .arg(numOccupation())
                         .arg(rcr.montantTotalEncaisseName())
                         .arg(rcr.totalAPayerName());

    model.setFilter(condition2);
    model.select();

    QList<QSqlRecord> records;

    QString fi = factureInitial(factureInitial::IdRestaurant).initial();
    for(int i = 0; i < model.rowCount(); i++)
    {
        // prendre uniquement que les factures du restaurant - reconnaissance par l'initial dans le libellé
        repasCompletResto rcr1(model.record(i));
        if(rcr1.facture().contains(fi))
            records << model.record(i);

        if(i + 1 == model.rowCount())
        {
            model.fetchMore();
        }
    }

    return records;
}

QList<QSqlRecord> occupation::repasConso_record()const
{
    QSqlTableModel model;
    model.setTable(RepasCompletResto::Libelle);
    model.setSort(RepasCompletResto::Id::DateArrivee, Qt::AscendingOrder);

    repasCompletResto rcr;    
    QString condition2 = QString("%1 = %2")
                         .arg(rcr.numOccupationName())
                         .arg(numOccupation());

    model.setFilter(condition2);
    model.select();

    QList<QSqlRecord> records;

    QString fi = factureInitial(factureInitial::IdRestaurant).initial();
    for(int i = 0; i < model.rowCount(); i++)
    {        
        // prendre uniquement que les factures du restaurant - reconnaissance par l'initial dans le libellé
        repasCompletResto rcr1(model.record(i));
        if(rcr1.facture().contains(fi))
            records << model.record(i);

        if(i + 1 == model.rowCount())
        {
            model.fetchMore();
        }
    }

    return records;
}

QList<QSqlRecord> occupation::barConso_record()const
{
    QSqlTableModel model;
    model.setTable(RepasCompletResto::Libelle);
    model.setSort(RepasCompletResto::Id::DateArrivee, Qt::AscendingOrder);

    repasCompletResto rcr;
    QString condition2 = QString("%1 = %2")
                         .arg(rcr.numOccupationName())
                         .arg(numOccupation());

    model.setFilter(condition2);
    model.select();

    QList<QSqlRecord> records;

    QString fi = factureInitial(factureInitial::IdBar).initial();
    for(int i = 0; i < model.rowCount(); i++)
    {
        // prendre uniquement que les factures du restaurant - reconnaissance par l'initial dans le libellé
        repasCompletResto rcr1(model.record(i));
        if(rcr1.facture().contains(fi))
            records << model.record(i);

        if(i + 1 == model.rowCount())
        {
            model.fetchMore();
        }
    }

    return records;
}

QList<QSqlRecord> occupation::barConsoNonPayes_record()const
{
    QSqlTableModel model;
    model.setTable(RepasCompletResto::Libelle);
    model.setSort(RepasCompletResto::Id::DateArrivee, Qt::AscendingOrder);

    repasCompletResto rcr;
    QString condition2 = QString("%1 = %2 AND %3 < %4")
                         .arg(rcr.numOccupationName())
                         .arg(numOccupation())
                         .arg(rcr.montantTotalEncaisseName())
                         .arg(rcr.totalAPayerName());

    model.setFilter(condition2);
    model.select();

    QList<QSqlRecord> records;

    QString fi = factureInitial(factureInitial::IdBar).initial();
    for(int i = 0; i < model.rowCount(); i++)
    {
        // prendre uniquement que les factures du restaurant - reconnaissance par l'initial dans le libellé
        repasCompletResto rcr1(model.record(i));
        if(rcr1.facture().contains(fi))
            records << model.record(i);

        if(i + 1 == model.rowCount())
        {
            model.fetchMore();
        }
    }

    return records;
}

QString occupation::facture()const
{
    return m_record.value(Occupation::Id::Facture).toString();
}

QDateTime occupation::datedSortie()const
{
    QDateTime date = datedEntree().addDays(dureeOccupation());
    date.setTime(HeureLimite(1).heureFinOccupation());

    return date;
}

void occupation::setDureeOccupation(int nbJours)
{
    m_record.setValue(Occupation::Id::DureeOccup, nbJours);
    tableModifiee(true);
}

void occupation::setDatedEntree(QDateTime date)
{
    m_record.setValue(Occupation::Id::DateOccupation, date);
    tableModifiee(true);
}

void occupation::setChambreOccupee(QString identifiant)
{
    m_record.setValue(Occupation::Id::IdentifiantCh, identifiant);
    tableModifiee(true);
}

void occupation::setDestinationExacte(QString lieu)
{
    m_record.setValue(Occupation::Id::DestinationExacte, lieu);
    tableModifiee(true);
}

void occupation::setFacture(QString facture)
{
    m_record.setValue(Occupation::Id::Facture, facture);
    tableModifiee(true);
}

void occupation::setIdGroupe(int id)
{
    m_record.setValue(Occupation::Id::IdGroupe, id);
    tableModifiee(true);
}

void occupation::setIdProfileClient(int id)
{
    m_record.setValue(Occupation::Id::IdProfileClient, id);
    tableModifiee(true);
}

QVariant occupation::cle() const
{
    return numOccupation();
}

QString occupation::libelleDeCle() const
{
    return m_record.fieldName(Occupation::Id::NumOccup);
}

QString occupation::tableName() const
{
    return Occupation::Libelle;
}

// fonctions spécialisées
bool occupation::estEnCours()const
{
    return !terminee();
}

bool occupation::estReglee()const
{
    return (reste() == 0 && resteFraisSup() == 0 && fraisRestoNonPayes() == 0);
}

bool occupation::fraisSupSontRegles()const
{
    return (resteFraisSup() == 0);
}

QList<QSqlRecord> occupation::occupation_records(QDate debut, QDate fin)
{
    QString condition = QObject::tr("DATE(%1) BETWEEN '%2' AND '%3'")
                        .arg(occupation().dateOccupName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate));

    return InfosSurBD::enregistrements(Occupation::Libelle, condition);
}

QList<QSqlRecord> occupation::occupation_records_a_terme(QDate debut, QDate fin, QString matricule)
{
    occupation occ;
    libererOccup li;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND %4 IN (SELECT %5 FROM %6 WHERE %7 = '%8')")
                        .arg(occ.dateOccupName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(occ.numOccupName())
                        .arg(li.numOccupName())
                        .arg(li.tableName())
                        .arg(li.matriculeRecepteurName())
                        .arg(matricule);

    return InfosSurBD::enregistrements(occ.tableName(), condition);
}

QList<QSqlRecord> occupation::occupation_records_a_terme(QDate debut, QDate fin)
{
    occupation occ;
    libererOccup li;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') AND %4 IN (SELECT %5 FROM %6")
                        .arg(occ.dateOccupName())
                        .arg(debut.toString(Qt::ISODate))
                        .arg(fin.toString(Qt::ISODate))
                        .arg(occ.numOccupName())
                        .arg(li.numOccupName())
                        .arg(li.tableName());

    return InfosSurBD::enregistrements(occ.tableName(), condition);
}

QList<QSqlRecord> occupation::occupationsEnCours()
{
    occupation oc;
    QString condition = QObject::tr("%1 = %2")
                        .arg(oc.termineeName())
                        .arg(false);

    return InfosSurBD::enregistrements(Occupation::Libelle, condition);
}

QList<QSqlRecord> occupation::occupationsEnCours(int idTypeDeChambre)
{
    occupation oc;
    QString condition = QObject::tr("%1 = %2")
                        .arg(oc.termineeName())
                        .arg(false);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Occupation::Libelle, condition);

    QList<QSqlRecord> records1;
    foreach(QSqlRecord r, records)
    {
        occupation oc(r);
        chambre ch(oc.chambreOccupee());
        if(ch.idTypeChambre() == idTypeDeChambre)
        {
            records1 << r;
        }
    }

    return records1;
}

bool occupation::estUnGroupe()const
{
    return idGroupe() > 0;
}

int occupation::reglerMontantTotal(int & montantVerse)
{
    int montantOccup = 0;
    // on commence par les frais de location
    if(reste() > 0 && reste() <= montantVerse)
    {
        montantVerse -= reste();
        montantOccup += reste();
        setPayee(cout());
    }else
    {
        if(reste() > montantVerse)
        {
            setPayee(payee() + montantVerse);
            montantOccup += montantVerse;
            montantVerse = 0;
        }
    }

    if(resteFraisSup() > 0 && resteFraisSup() <= montantVerse)
    {
        montantVerse -= resteFraisSup();
        montantOccup += resteFraisSup();
        setFraisSupPayee(fraisSupplementaire());
    }else
    {
        if(resteFraisSup() > montantVerse)
        {
            setFraisSupPayee(fraisSupPayee() + montantVerse);
            montantOccup += montantVerse;
            montantVerse = 0;
        }
    }

    return montantOccup;
}

int occupation::restituerMontantTotal(int & montantVerse)
{
    int montantOccup = 0;

    // on commence par les frais supplémentaires
    if(fraisSupPayee() > 0 && fraisSupPayee() <= montantVerse)
    {
        montantVerse -= fraisSupPayee();
        montantOccup += fraisSupPayee();
        setFraisSupPayee(0);
    }else
    {
        if(fraisSupPayee() > montantVerse)
        {
            setFraisSupPayee(fraisSupPayee() - montantVerse);
            montantOccup += montantVerse;
            montantVerse = 0;
        }
    }

    if(payee() > 0 && payee() <= montantVerse)
    {
        montantVerse -= payee();
        montantOccup += payee();
        setPayee(0);
    }else
    {
        if(payee() > montantVerse)
        {
            setPayee(payee() - montantVerse);
            montantOccup += montantVerse;
            montantVerse = 0;
        }
    }

    return montantOccup; // montant restitué
}

bool occupation::enregistrer()
{
    bool enregistre = Entree::enregistrer();

    if(estUnGroupe() && enregistre)
    {
        groupe gr(idGroupe());
        gr.actualiser();
    }

    return enregistre;
}
