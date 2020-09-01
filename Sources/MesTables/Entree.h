#ifndef ENTREE_H
#define ENTREE_H

#include "MesTables_global.h"

/* classes qt */
#include <QString>
#include <QStringList>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QObject>
#include <QSqlTableModel>
#include <QMessageBox>


/* classes personnalisées */
#include "InfosSurBD.h"

/* définition */

class MESTABLESSHARED_EXPORT Entree
{
public:
    bool operator==(const Entree & e)const;

public:
    Entree();
    ~Entree();

    void actualiser();
    bool enregistrer();
    bool supprimer();
    bool existe()const;
    bool existe(const QVariant & cle)const;
    inline void clear(){m_record.clearValues();};
    inline bool isEmpty(){return m_record.isEmpty();};

    QString requeteEgalite(const QString & libelle, const QVariant & valeur)const;

    int rowOfRecord();
    int tableRowCount();

    void setRecord(const QSqlRecord & r);
    QSqlRecord record()const;

protected:
    // données protégées
    QSqlRecord m_record;
    bool m_recordModifie;
    QStringList m_fieldsName;
    bool m_existeDeja;

    void initialiserTable();
    inline void tableModifiee(bool modifie){m_recordModifie = modifie;};

    // méthodes protégées
    virtual QVariant cle()const =0;
    virtual QString tableName()const =0;
    virtual QString libelleDeCle()const =0;


   QString requeteSupprimerEntree()const;
   QString requeteSupprimerEntreeSansWhere()const;
   bool cleExiste();
   bool cleExiste(const QVariant & cle)const;
   bool ajouter();

   // méthodes définissant chaque constructeur
   void constructeur();
   void constructeur(const QVariant & cle);
   void constructeur(const QSqlRecord & record);
   void constructeur(const Entree & e);

protected:
    static bool estUnNombre(const QVariant & valeur);

};

#endif // ENTREE_H
