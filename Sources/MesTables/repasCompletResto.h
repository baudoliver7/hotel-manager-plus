#ifndef REPASCOMPLETRESTO_H
#define REPASCOMPLETRESTO_H

#include "MesTables_global.h"

#include <QDateTime>

#include "Entree.h"
#include "consoResto.h"
#include "menuResto.h"

class MESTABLESSHARED_EXPORT repasCompletResto : public Entree
{
public:
    repasCompletResto();
    repasCompletResto(int id);
    repasCompletResto(QString facture);
    repasCompletResto(const QSqlRecord & record);
    repasCompletResto(const repasCompletResto & s);

    void setCodeClient(int code);
    void setDateDepart(QDateTime date);
    void setDateArrivee(QDateTime date);
    void setDureeEnMinutes(int minutes);
    void setTotalAPayer(int somme);
    void setIdTableResto(int id);
    void setMatriculeCaissier(QString matricule);
    void setFacture(QString numero);
    void setMontantTotalEncaisse(int montant);
    void setFactureMiseAJour(bool miseAjour);
    void setNumOccupation(int num);

    int idRepasCResto()const;
    int codeClient()const;
    QDateTime dateDepart()const;
    QDateTime dateArrivee()const;
    int dureeEnMinutes()const;
    int totalAPayer()const;
    int idTableResto()const;
    QString matriculeCaissier()const;
    QString facture()const;
    int montantTotalEncaisse()const;
    bool factureMiseAJour()const;
    int reste()const;
    int numOccupation()const;
    int totalAPayerSanSRemise()const;

    QList<QSqlRecord> conso_resto_records()const;    

    inline QString idRepasCRestoName()const{return m_fieldsName.at(RepasCompletResto::Id::IdRepasCResto);};
    inline QString codeClientName()const{return m_fieldsName.at(RepasCompletResto::Id::CodeClient);};
    inline QString dateDepartName()const{return m_fieldsName.at(RepasCompletResto::Id::DateDepart);};
    inline QString dateArriveeName()const{return m_fieldsName.at(RepasCompletResto::Id::DateArrivee);};
    inline QString dureeEnMinutesName()const{return m_fieldsName.at(RepasCompletResto::Id::DureeEnMinutes);};
    inline QString totalAPayerName()const{return m_fieldsName.at(RepasCompletResto::Id::TotalAPayer);};
    inline QString idTableRestoName()const{return m_fieldsName.at(RepasCompletResto::Id::IdTableResto);};
    inline QString matriculeCaissierName()const{return m_fieldsName.at(RepasCompletResto::Id::MatriculeCaissier);};
    inline QString factureName()const{return m_fieldsName.at(RepasCompletResto::Id::Facture);};
    inline QString montantTotalEncaisseName()const{return m_fieldsName.at(RepasCompletResto::Id::MontantTotalEncaisse);};
    inline QString factureMiseAJourName()const{return m_fieldsName.at(RepasCompletResto::Id::FactureMiseAJour);};
    inline QString numOccupationName()const{return m_fieldsName.at(RepasCompletResto::Id::NumOccupation);};

    // fonctions spécialisées
    int reglerMontantTotal(int & montant);    
    int restituerMontantTotal(int & montant);

    // définition des méthodes virtuelles pures
    QVariant cle() const;
    QString libelleDeCle()const;
    QString tableName()const; // fin

public:
    static QList<QSqlRecord> repasCompletResto_records(QDate debut, QDate fin);
    static QList<QSqlRecord> repasCompletResto_records_termines(QDate debut, QDate fin);
    static QList<QSqlRecord> repasCompletResto_records_termines(QDate debut, QDate fin, QString matricule);

    static QList<QSqlRecord> repasCompletResto_records(QDate debut, QDate fin, bool factureMiseAJour);
    static QList<QSqlRecord> repasCompletResto_records_termines(QDate debut, QDate fin, bool factureMiseAJour);
    static QList<QSqlRecord> repasCompletResto_records_termines(QDate debut, QDate fin, QString matricule, bool factureMiseAJour);

    static repasCompletResto selectionnerRepasCResto(int idTableResto);
};

#endif // REPASCOMPLETRESTO_H
