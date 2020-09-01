#ifndef GROUPE_H
#define GROUPE_H

#include "MesTables_global.h"

#include <QDateTime>

#include "Entree.h"
#include "occupation.h"
#include "prixChambreTTC.h"
#include "consoResto.h"
#include "menuResto.h"
#include "groupeLiaison.h"

class MESTABLESSHARED_EXPORT groupe : public Entree
{
public:
    groupe();
    groupe(int id);
    groupe(const QSqlRecord & record);
    groupe(const groupe & s);

    void setLibelle(QString libelle);
    void setIdResponsable(int id);
    void setNbPersEnregistrees(int nb);
    void setFraisLocation(int cout);
    void setFraisLocationPayee(int cout);
    void setProvenance(QString provenance);
    void setMatriculeAgent(QString matricule);
    void setTerminee(bool terminee);
    void setDateDemande(QDateTime date);
    void setDateOccupation(QDateTime date);
    void setDureeOccupation(int duree);
    void setFraisSup(int montant);
    void setFraisSupPayee(int montant);
    void setFacture(QString facture);
    void setAvance(int avance);
    void setTel(QString tel);
    void setCel(QString cel);
    void setEmail(QString email);
    void setBP(QString bp);
    void setNbPersPrevues(int nb);
    void setIdProfileClient(int id);
    void setContacts(QString contacts);
    void setIdTypeDeChambreMaj(int id);
    void setAvanceActu(int somme);

    int idGroupe()const;
    QString libelle()const;
    int idResponsable()const;
    int nbPersEnregistrees()const;
    int fraisLocation()const;
    int fraisLocationSansRemise()const;
    int fraisLocationPayee()const;
    int fraisSup()const;
    int fraisSupPayee()const;
    QString provenance()const;
    QString matriculeAgent()const;
    int dureeOccupation()const;
    QDateTime dateDemande()const;
    QDateTime dateOccupation()const;
    bool terminee()const;
    QString facture()const;
    int avance()const;
    QString tel()const;
    QString cel()const;
    QString bp()const;
    QString email()const;
    int idProfileClient()const;
    int nbPersPrevues()const;
    QString contacts()const;
    int idTypeDeChambreMaj()const;
    int avanceActu()const;

    int fraisRestoTotal()const;
    int fraisRestoTotalSansRemise()const;
    int fraisRestoPayes()const;
    int fraisRestoNonPayes()const;
    int fraisRestoNonPayesSansRemise()const;
    int fraisBarTotal()const;
    int fraisBarTotalSansRemise()const;
    int fraisBarPayes()const;
    int fraisBarNonPayes()const;
    int fraisBarNonPayesSansRemise()const;
    QList<QSqlRecord> occupations_des_membres_records()const;

    int coutTotalGlobal()const;
    int sommePayeeGlobale()const;

    void actualiser();

    inline QString idGroupeName()const{return m_fieldsName.at(Groupe::Id::IdGroupe);};
    inline QString libelleName()const{return m_fieldsName.at(Groupe::Id::Libelle);};
    inline QString idResponsableName()const{return m_fieldsName.at(Groupe::Id::IdResponsable);};
    inline QString nbPersonnesName()const{return m_fieldsName.at(Groupe::Id::NbPersonnesEnreg);};
    inline QString fraisLocationName()const{return m_fieldsName.at(Groupe::Id::FraisLocation);};
    inline QString fraisLocationPayeeName()const{return m_fieldsName.at(Groupe::Id::FraisLocationPayee);};
    inline QString fraisSupName()const{return m_fieldsName.at(Groupe::Id::FraisSup);};
    inline QString fraisSupPayeeName()const{return m_fieldsName.at(Groupe::Id::FraisSupPayee);};
    inline QString provenanceName()const{return m_fieldsName.at(Groupe::Id::Provenance);};
    inline QString matriculeAgentName()const{return m_fieldsName.at(Groupe::Id::MatriculeAgent);};
    inline QString termineeName()const{return m_fieldsName.at(Groupe::Id::Terminee);};
    inline QString dateOccupationName()const{return m_fieldsName.at(Groupe::Id::DateOccupation);};
    inline QString dateDemandeName()const{return m_fieldsName.at(Groupe::Id::DateDeDemande);};
    inline QString dureeOccupationName()const{return m_fieldsName.at(Groupe::Id::DureeOccupation);};
    inline QString factureName()const{return m_fieldsName.at(Groupe::Id::Facture);};
    inline QString avanceName()const{return m_fieldsName.at(Groupe::Id::Avance);};
    inline QString celName()const{return m_fieldsName.at(Groupe::Id::NumeroCel);};
    inline QString telName()const{return m_fieldsName.at(Groupe::Id::NumeroTel);};
    inline QString emailName()const{return m_fieldsName.at(Groupe::Id::Email);};
    inline QString bpName()const{return m_fieldsName.at(Groupe::Id::BoitePostale);};
    inline QString idProfileClientName()const{return m_fieldsName.at(Groupe::Id::IdProfileClient);};
    inline QString nbPersPrevuesName()const{return m_fieldsName.at(Groupe::Id::NbPersonnesPrevues);};
    inline QString idTypeDeChambreMajName()const{return m_fieldsName.at(Groupe::Id::IdTypeDeChambreMaj);};
    inline QString avanceActuName()const{return m_fieldsName.at(Groupe::Id::AvanceActu);};

    // fonctions spécialisées
    int resteFraisLocation()const;
    int resteFraisSup()const;
    int coutTotalLocation()const;
    int coutTotalPaye()const;
    int coutTotalRestant()const;

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
     static QString contacts(QString cel, QString tel, QString email, QString bp);
     static QStringList listeDeContacts(QString contacts);
};

#endif // GROUPE_H
