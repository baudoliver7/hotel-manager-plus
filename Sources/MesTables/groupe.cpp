#include "groupe.h"

groupe::groupe()
{
    constructeur();
}

groupe::groupe(const QSqlRecord &record)
{
    constructeur(record);
}

groupe::groupe(const groupe & s)
{
    constructeur(s);
}

groupe::groupe(int id)
{
    constructeur(id);
}

int groupe::idGroupe()const
{
    return m_record.value(Groupe::Id::IdGroupe).toInt();
}

int groupe::idResponsable()const
{
    return m_record.value(Groupe::Id::IdResponsable).toInt();
}

QString groupe::libelle()const
{
    return m_record.value(Groupe::Id::Libelle).toString();
}

int groupe::nbPersEnregistrees()const
{
    return m_record.value(Groupe::Id::NbPersonnesEnreg).toInt();
}

QString groupe::provenance()const
{
    return m_record.value(Groupe::Id::Provenance).toString();
}

QString groupe::matriculeAgent()const
{
    return m_record.value(Groupe::Id::MatriculeAgent).toString();
}

bool groupe::terminee()const
{
    return m_record.value(Groupe::Id::Terminee).toBool();
}

QString groupe::facture()const
{
    return m_record.value(Groupe::Id::Facture).toString();
}

QString groupe::bp()const
{
    return m_record.value(Groupe::Id::BoitePostale).toString();
}

QString groupe::tel()const
{
    return m_record.value(Groupe::Id::NumeroTel).toString();
}

QString groupe::email()const
{
    return m_record.value(Groupe::Id::Email).toString();
}

QString groupe::cel()const
{
    return m_record.value(Groupe::Id::NumeroCel).toString();
}

int groupe::nbPersPrevues()const
{
    return m_record.value(Groupe::Id::NbPersonnesPrevues).toInt();
}

int groupe::idProfileClient()const
{
    return m_record.value(Groupe::Id::IdProfileClient).toInt();
}

int groupe::idTypeDeChambreMaj()const
{
    return m_record.value(Groupe::Id::IdTypeDeChambreMaj).toInt();
}

int groupe::avanceActu()const
{
    return m_record.value(Groupe::Id::AvanceActu).toInt();
}

QDateTime groupe::dateDemande()const
{
    return m_record.value(Groupe::Id::DateDeDemande).toDateTime();
}

QDateTime groupe::dateOccupation()const
{
    return m_record.value(Groupe::Id::DateOccupation).toDateTime();
}

int groupe::dureeOccupation()const
{
    return m_record.value(Groupe::Id::DureeOccupation).toInt();
}

int groupe::avance()const
{
    return m_record.value(Groupe::Id::Avance).toInt();
}

int groupe::fraisRestoNonPayes()const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    for(int i = 0; i < records.count(); i++)
    {
        frais += occupation(records.at(i)).fraisRestoNonPayes();
    }

    return frais;
}

int groupe::fraisBarNonPayes()const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    for(int i = 0; i < records.count(); i++)
    {
        frais += occupation(records.at(i)).fraisBarNonPayes();
    }

    return frais;
}

int groupe::fraisRestoTotal()const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    for(int i = 0; i < records.count(); i++)
    {
        frais += occupation(records.at(i)).fraisResto();
    }

    return frais;
}

int groupe::fraisRestoTotalSansRemise()const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    foreach(QSqlRecord r, records)
    {
        occupation oc(r);
        QList<QSqlRecord> records1;
        records1 = oc.repasConso_record();

        foreach(QSqlRecord r1, records1)
        {
            repasCompletResto rcr(r1);

            QList<QSqlRecord> records2;
            records2 = rcr.conso_resto_records();

            foreach(QSqlRecord r2, records2)
            {
                consoResto cr(r2);
                int prixUnitaire = menuResto(cr.idMenu()).prix();
                frais += cr.nbMenu() * prixUnitaire;
            }
        }
    }

    return frais;
}

int groupe::fraisRestoPayes()const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    for(int i = 0; i < records.count(); i++)
    {
        frais += occupation(records.at(i)).fraisRestoPayes();
    }

    return frais;
}

int groupe::fraisRestoNonPayesSansRemise()const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    foreach(QSqlRecord r, records)
    {
        occupation oc(r);
        QList<QSqlRecord> records1;
        records1 = oc.repasConsoNonPayes_record();

        foreach(QSqlRecord r1, records1)
        {
            repasCompletResto rcr(r1);

            QList<QSqlRecord> records2;
            records2 = rcr.conso_resto_records();

            foreach(QSqlRecord r2, records2)
            {
                consoResto cr(r2);
                int prixUnitaire = menuResto(cr.idMenu()).prix();
                frais += cr.nbMenu() * prixUnitaire;
            }
        }
    }

    return frais;
}

int groupe::fraisBarTotal()const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    for(int i = 0; i < records.count(); i++)
    {
        frais += occupation(records.at(i)).fraisBar();
    }

    return frais;
}

int groupe::fraisBarTotalSansRemise()const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    foreach(QSqlRecord r, records)
    {
        occupation oc(r);
        QList<QSqlRecord> records1;
        records1 = oc.barConso_record();

        foreach(QSqlRecord r1, records1)
        {
            repasCompletResto rcr(r1);

            QList<QSqlRecord> records2;
            records2 = rcr.conso_resto_records();

            foreach(QSqlRecord r2, records2)
            {
                consoResto cr(r2);
                int prixUnitaire = menuResto(cr.idMenu()).prix();
                frais += cr.nbMenu() * prixUnitaire;
            }
        }
    }

    return frais;
}

int groupe::fraisBarPayes()const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    for(int i = 0; i < records.count(); i++)
    {
        frais += occupation(records.at(i)).fraisBarPayes();
    }

    return frais;
}

int groupe::fraisBarNonPayesSansRemise()const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    foreach(QSqlRecord r, records)
    {
        occupation oc(r);
        QList<QSqlRecord> records1;
        records1 = oc.barConsoNonPayes_record();

        foreach(QSqlRecord r1, records1)
        {
            repasCompletResto rcr(r1);

            QList<QSqlRecord> records2;
            records2 = rcr.conso_resto_records();

            foreach(QSqlRecord r2, records2)
            {
                consoResto cr(r2);
                int prixUnitaire = menuResto(cr.idMenu()).prix();
                frais += cr.nbMenu() * prixUnitaire;
            }
        }
    }

    return frais;
}


QList<QSqlRecord> groupe::occupations_des_membres_records()const
{
    QSqlTableModel model;
    model.setTable(Occupation::Libelle);
    model.setSort(Occupation::Id::DateOccupation, Qt::AscendingOrder);

    occupation oc;
    QString condition2 = QString("%1 = %2")
                         .arg(oc.idGroupeName())
                         .arg(idGroupe());

    model.setFilter(condition2);
    model.select();

    QList<QSqlRecord> records;

    for(int i = 0; i < model.rowCount(); i++)
    {
        records << model.record(i);

        if(i + 1 == model.rowCount())
        {
            model.fetchMore();
        }
    }

    return records;
}

void groupe::actualiser()
{
    Entree::actualiser();

    if(existe())
    {
        QList<QSqlRecord> records;
        records << occupations_des_membres_records();

        // actualiser montant total
        int montantTotalLocation = 0;
        int montantTotalFraisSup = 0;
        int montantLocationPaye = 0;
        int montantFraisSupPaye = 0;
        bool termine = true;

        if(records.isEmpty() && !terminee())
            termine = false;

        foreach(QSqlRecord r, records)
        {
            occupation oc(r);
            montantTotalLocation += oc.cout();
            montantTotalFraisSup += oc.fraisSupplementaire();
            montantLocationPaye += oc.payee();
            montantFraisSupPaye += oc.fraisSupPayee();

            if(!oc.terminee())
                termine = false;
        }

        setFraisLocation(montantTotalLocation);
        setFraisSup(montantTotalFraisSup);
        setFraisLocationPayee(montantLocationPaye);
        setFraisSupPayee(montantFraisSupPaye);

        int nbPersonnes = groupeLiaison::groupe_liaison_records(idGroupe()).count();
        setNbPersEnregistrees(nbPersonnes);
        setTerminee(termine);

        enregistrer();
    }
}

int groupe::fraisLocation()const
{
    return m_record.value(Groupe::Id::FraisLocation).toInt();
}

int groupe::fraisLocationSansRemise() const
{
    QList<QSqlRecord> records;
    records = occupations_des_membres_records();

    int frais = 0;
    foreach(QSqlRecord r, records)
    {
        occupation oc(r);
        chambre ch(oc.chambreOccupee());

        int prixUnitaireNorm = prixChambreTTC(ch.idTypeChambre(), oc.idProfileClient()).prixTTC();

        frais += prixUnitaireNorm * oc.dureeOccupation();
    }

    return frais;
}

int groupe::fraisLocationPayee()const
{
    return m_record.value(Groupe::Id::FraisLocationPayee).toInt();
}

int groupe::fraisSup()const
{
    return m_record.value(Groupe::Id::FraisSup).toInt();
}

int groupe::fraisSupPayee()const
{
    return m_record.value(Groupe::Id::FraisSupPayee).toInt();
}

QVariant groupe::cle() const
{
    return idGroupe();
}

QString groupe::libelleDeCle() const
{
    return m_record.fieldName(Groupe::Id::IdGroupe);
}

QString groupe::tableName() const
{
    return Groupe::Libelle;
}

void groupe::setIdResponsable(int id)
{
    m_record.setValue(Groupe::Id::IdResponsable, id);
    tableModifiee(true);
}

void groupe::setLibelle(QString libelle)
{
    m_record.setValue(Groupe::Id::Libelle, libelle);
    tableModifiee(true);
}

void groupe::setNbPersEnregistrees(int nb)
{
    m_record.setValue(Groupe::Id::NbPersonnesEnreg, nb);
    tableModifiee(true);
}

void groupe::setFraisLocationPayee(int cout)
{
    m_record.setValue(Groupe::Id::FraisLocationPayee, cout);
    tableModifiee(true);
}

void groupe::setFraisLocation(int cout)
{
    m_record.setValue(Groupe::Id::FraisLocation, cout);
    tableModifiee(true);
}

void groupe::setFraisSup(int montant)
{
    m_record.setValue(Groupe::Id::FraisSup, montant);
    tableModifiee(true);
}

void groupe::setFraisSupPayee(int montant)
{
    m_record.setValue(Groupe::Id::FraisSupPayee, montant);
    tableModifiee(true);
}

void groupe::setFacture(QString facture)
{
    m_record.setValue(Groupe::Id::Facture, facture);
    tableModifiee(true);
}

void groupe::setAvance(int avance)
{
    m_record.setValue(Groupe::Id::Avance, avance);
    tableModifiee(true);
}

void groupe::setIdProfileClient(int id)
{
    m_record.setValue(Groupe::Id::IdProfileClient, id);
    tableModifiee(true);
}

void groupe::setTel(QString tel)
{
    m_record.setValue(Groupe::Id::NumeroTel, tel);
    tableModifiee(true);
}

void groupe::setCel(QString cel)
{
    m_record.setValue(Groupe::Id::NumeroCel, cel);
    tableModifiee(true);
}

void groupe::setBP(QString bp)
{
    m_record.setValue(Groupe::Id::BoitePostale, bp);
    tableModifiee(true);
}

void groupe::setEmail(QString email)
{
    m_record.setValue(Groupe::Id::Email, email);
    tableModifiee(true);
}

void groupe::setNbPersPrevues(int nb)
{
    m_record.setValue(Groupe::Id::NbPersonnesPrevues, nb);
    tableModifiee(true);
}

void groupe::setProvenance(QString provenance)
{
    m_record.setValue(Groupe::Id::Provenance, provenance);
    tableModifiee(true);
}

void groupe::setMatriculeAgent(QString matricule)
{
    m_record.setValue(Groupe::Id::MatriculeAgent, matricule);
    tableModifiee(true);
}

void groupe::setTerminee(bool terminee)
{
    m_record.setValue(Groupe::Id::Terminee, terminee);
    tableModifiee(true);
}

void groupe::setDateDemande(QDateTime date)
{
    m_record.setValue(Groupe::Id::DateDeDemande, date);
    tableModifiee(true);
}

void groupe::setDateOccupation(QDateTime date)
{
    m_record.setValue(Groupe::Id::DateOccupation, date);
    tableModifiee(true);
}

void groupe::setDureeOccupation(int duree)
{
    m_record.setValue(Groupe::Id::DureeOccupation, duree);
    tableModifiee(true);
}

int groupe::resteFraisLocation()const
{
    int r = fraisLocation() - fraisLocationPayee();
    if(r <= 0)
        return 0;

    return r;
}

int groupe::resteFraisSup()const
{
    int r = fraisSup() - fraisSupPayee();
    if(r <= 0)
        return 0;

    return r;
}

int groupe::coutTotalLocation()const
{
    return fraisLocation() + fraisSup();
}

int groupe::coutTotalPaye()const
{
    return fraisLocationPayee() + fraisSupPayee();
}

int groupe::coutTotalRestant()const
{
    return coutTotalLocation() - coutTotalPaye();
}

QString groupe::contacts(QString cel, QString tel, QString email, QString bp)
{
    return (cel+ "|"
            +tel+"|"
            +email+"|"
            +bp);
}

QStringList groupe::listeDeContacts(QString contacts)
{
   return contacts.split("|");
}

QString groupe::contacts()const
{
    QString ct =  groupe::contacts(cel(),tel(),email(), bp());

    QString ctVide = groupe::contacts(QString(),QString(),QString(),QString());

    if(ct == ctVide)
        return QString();
    else
        return ct;
}

void groupe::setContacts(QString contacts)
{
    QStringList listeDeContacts = contacts.split("|");
    if(listeDeContacts.first() != contacts)
    {
        setCel(listeDeContacts.at(0));
        setTel(listeDeContacts.at(1));
        setEmail(listeDeContacts.at(2));
        setBP(listeDeContacts.at(3));
        tableModifiee(true);
    }
}

void groupe::setIdTypeDeChambreMaj(int id)
{
    m_record.setValue(Groupe::Id::IdTypeDeChambreMaj, id);
    tableModifiee(true);
}

void groupe::setAvanceActu(int somme)
{
    m_record.setValue(Groupe::Id::AvanceActu, somme);
    tableModifiee(true);
}

int groupe::coutTotalGlobal()const
{
    return fraisLocation() + fraisSup() + fraisRestoTotal() + fraisBarTotal();
}

int groupe::sommePayeeGlobale()const
{
    int payee = coutTotalPaye() + fraisRestoPayes() + fraisBarPayes() + avanceActu(); // location + resto + avance restante
    return payee;
}
