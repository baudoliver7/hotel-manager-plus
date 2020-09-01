#ifndef OCCUPATION_H
#define OCCUPATION_H

#include "MesTables_global.h"

/* classes qt */
#include <QDate>
#include <QDateTime>

/* classes personnalisées */
#include "Entree.h"
#include "horloge.h"
#include "chambre.h"
#include "HeureLimite.h"
#include "libererOccup.h"
#include "repasCompletResto.h"
#include "groupe.h"


class chambre;

class MESTABLESSHARED_EXPORT occupation : public Entree
{
public:
    occupation();
    occupation(int numOccup);
    occupation(const QSqlRecord & record);
    occupation(const occupation & oc);
    occupation(const chambre & ch);

    int numOccupation()const;
    int dureeOccupation()const;
    int cout()const;
    int fraisSupplementaire()const;
    int fraisSupPayee()const;
    int enfAccMoinsDe15()const;
    int codeClient()const;
    QString chambreOccupee()const;
    QString destinationExacte()const;
    QDateTime datedSortie()const;
    QDateTime datedEntree()const;
    int payee()const;
    int reste()const;
    int resteFraisSup()const;
    bool terminee()const;
    QString facture()const;
    int idGroupe()const;
    int fraisRestoNonPayes()const;
    int fraisResto()const;
    int fraisRestoPayes()const;
    int fraisBarNonPayes()const;
    int fraisBar()const;
    int fraisBarPayes()const;
    int idProfileClient()const;
    QList<QSqlRecord> repasConsoNonPayes_record()const;
    QList<QSqlRecord> repasConso_record()const;
    QList<QSqlRecord> barConsoNonPayes_record()const;
    QList<QSqlRecord> barConso_record()const;

    inline QString numOccupName()const{return m_fieldsName.at(Occupation::Id::NumOccup);};
    inline QString dureeOccupName()const{return m_fieldsName.at(Occupation::Id::DureeOccup);};
    inline QString identiteChName()const{return m_fieldsName.at(Occupation::Id::IdentifiantCh);};
    inline QString coutName()const{return m_fieldsName.at(Occupation::Id::Cout);};
    inline QString dateOccupName()const{return m_fieldsName.at(Occupation::Id::DateOccupation);};
    inline QString termineeName()const{return m_fieldsName.at(Occupation::Id::Terminee);};
    inline QString codeClientName()const{return m_fieldsName.at(Occupation::Id::CodeClient);};
    inline QString fraisSupName()const{return m_fieldsName.at(Occupation::Id::FraisSup);};
    inline QString fraisSupPayeName()const{return m_fieldsName.at(Occupation::Id::FraisSupPaye);};
    inline QString destinationExacteName()const{return m_fieldsName.at(Occupation::Id::DestinationExacte);};
    inline QString enfAccMoinsDe15Name()const{return m_fieldsName.at(Occupation::Id::EnfAccMoinsDe15);};
    inline QString payeeName()const{return m_fieldsName.at(Occupation::Id::Payee);};
    inline QString factureName()const{return m_fieldsName.at(Occupation::Id::Facture);};
    inline QString idGroupeName()const{return m_fieldsName.at(Occupation::Id::IdGroupe);};
    inline QString idProfileClientName()const{return m_fieldsName.at(Occupation::Id::IdProfileClient);};


    void setDureeOccupation(int nbJours);
    void setDatedEntree(QDateTime date);
    void setChambreOccupee(QString identifiant);
    void setCout(int cout);
    void setPayee(int cout);
    void setTerminer(bool terminee);
    void setFraisSupplementaire(int somme);
    void setFraisSupPayee(int somme);
    void setEnfAccMoinsDe15(int nb);
    void setCodeClient(int code);
    void setDestinationExacte(QString lieu);
    void setFacture(QString facture);
    void setIdGroupe(int id);
    void setIdProfileClient(int id);

    //fonctions spécialisées
    bool estEnCours()const;
    bool estReglee()const;
    bool fraisSupSontRegles()const;
    bool estUnGroupe()const;
    int reglerMontantTotal(int & montant);
    int restituerMontantTotal(int & montant);

    bool enregistrer();

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> occupation_records(QDate debut, QDate fin);
    static QList<QSqlRecord> occupation_records_a_terme(QDate debut, QDate fin);
    static QList<QSqlRecord> occupation_records_a_terme(QDate debut, QDate fin, QString matricule);
    static QList<QSqlRecord> occupationsEnCours();
    static QList<QSqlRecord> occupationsEnCours(int idTypeDeChambre);
};

#endif // OCCUPATION_H
