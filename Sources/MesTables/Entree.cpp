#include "Entree.h"

bool Entree::operator==(const Entree & e)const
{
    return (cle().toString() == e.cle().toString());
}

Entree::Entree()
{
//    m_record = record();
//    m_fieldsName.clear();
//    tableModifiee(false);
}

void Entree::constructeur()
{
    //initialiserTable();

    QSqlTableModel modelTable;
    modelTable.setTable(tableName());
    m_record = modelTable.record();
    m_fieldsName = InfosSurBD::fieldsNames(tableName());

    tableModifiee(false);
}

void Entree::constructeur(const QVariant &cle)
{
    //initialiserTable();
    QSqlTableModel modelTable;
    modelTable.setTable(tableName());
    m_record = modelTable.record();
    m_fieldsName = InfosSurBD::fieldsNames(tableName());

    if(existe(cle))
    {
        modelTable.setFilter(requeteEgalite(libelleDeCle(), cle));
        modelTable.select();

        m_record = modelTable.record(0);
    }

    tableModifiee(false);
}

void Entree::constructeur(const QSqlRecord &record)
{
    //initialiserTable();
    m_fieldsName =  InfosSurBD::fieldsNames(tableName());
    m_record = record;

    tableModifiee(false);
}

void Entree::constructeur(const Entree &e)
{
    //initialiserTable();
    m_record = e.m_record;
    m_recordModifie = e.m_recordModifie;
    m_fieldsName.clear();
    m_fieldsName << e.m_fieldsName;
}

void Entree::initialiserTable()
{
//    m_modelTable = new QSqlTableModel();
//    m_modelTable->setTable(tableName());
//    m_record = m_modelTable->record();
//    m_fieldsName << InfosSurBD::fieldsNames(m_modelTable);
}

QString Entree::requeteEgalite(const QString &libelle, const QVariant & valeur) const
{
    if(estUnNombre(valeur)) // si valeur est un entier
    {
        return QObject::tr("%1 = %2").arg(libelle).arg(valeur.toInt());
    }else
    {
        // valeur est une chaine de caractère
        return QObject::tr("%1 = '%2'").arg(libelle).arg(valeur.toString());
    }
}

QString Entree::requeteSupprimerEntree()const
{
    if(estUnNombre(cle()))
        return QObject::tr("DELETE * FROM %1 WHERE %2 = %3").arg(tableName()).arg(libelleDeCle()).arg(cle().toInt());
    else
        return QObject::tr("DELETE * FROM %1 WHERE %2 = '%3'").arg(tableName()).arg(libelleDeCle()).arg(cle().toString());
}

QString Entree::requeteSupprimerEntreeSansWhere()const
{
    if(estUnNombre(cle()))
        return QObject::tr("%2 = %3").arg(libelleDeCle()).arg(cle().toInt());
    else
        return QObject::tr("%2 = '%3'").arg(libelleDeCle()).arg(cle().toString());
}

bool Entree::ajouter()
{
    QSqlTableModel modelTable;
    modelTable.setTable(tableName()); // pour tout afficher
    modelTable.insertRecord(-2, m_record);

    m_record = InfosSurBD::enregistrements(tableName()).last(); // nécessaire dans le cas d'une clé automatique
    tableModifiee(false);
    return true;
}

bool Entree::enregistrer()
{
    bool modifEffectuee = false;

    if(!existe())
    {
         modifEffectuee = ajouter();
    }else
    {
        if(m_recordModifie)
        {
            QSqlTableModel modelTable;
            modelTable.setTable(tableName()); // pour tout afficher
            modelTable.setFilter(requeteEgalite(libelleDeCle(), cle()));
            modelTable.select();

            /* modelTable possède un seul enregistrement,
              celui correspondant à la clé */

            if(modelTable.setRecord(0, m_record))
            {
                modifEffectuee = modelTable.submitAll();
                m_record = modelTable.record(0);
            }else
            {
                modifEffectuee = false;
            }
        }
    }

    tableModifiee(!modifEffectuee);
    return modifEffectuee;
}

bool Entree::supprimer()
{
    if(existe())
    {
        QSqlTableModel modelTable;
        modelTable.setTable(tableName()); // pour tout afficher
        modelTable.setFilter(requeteEgalite(libelleDeCle(), cle()));
        modelTable.select();

        /* modelTable possède un seul enregistrement,
          celui correspondant à la clé */

        modelTable.removeRow(0);
        if(modelTable.submitAll())
        {
            m_record = modelTable.record();
            return true;
        }
    }

    return false;
}

bool Entree::existe()const
{
    return existe(cle());
}

bool Entree::existe(const QVariant &cle)const
{
    return cleExiste(cle);
}

bool Entree::cleExiste()
{
    return cleExiste(cle());
}

bool Entree::cleExiste(const QVariant & cle)const
{
    QSqlTableModel modelTable;
    modelTable.setTable(tableName()); // pour tout afficher
    modelTable.setFilter(requeteEgalite(libelleDeCle(), cle));
    modelTable.select();

    return (modelTable.rowCount() != 0);
}

bool Entree::estUnNombre(const QVariant &valeur)
{
    bool ok;
    valeur.toFloat(&ok);

    return ok;
}

int Entree::rowOfRecord()
{
    QSqlTableModel model;
    model.setTable(tableName());

    model.select();
    QStringList cles;

    for(int i = 0; i < model.rowCount(); i++)
    {
        cles << model.record(i).value(0).toString();
        if(i + 1 == model.rowCount())
        {
            model.fetchMore();
        }
    }

    return cles.indexOf(cle().toString());
}

int Entree::tableRowCount()
{
    QSqlTableModel model;
    model.setTable(tableName());

    model.select();
    QStringList cles;

    for(int i = 0; i < model.rowCount(); i++)
    {
        cles << model.record(i).value(0).toString();
        if(i + 1 == model.rowCount())
        {
            model.fetchMore();
        }
    }

    return cles.count();
}

void Entree::actualiser()
{
    if(existe())
    {
        QSqlTableModel modelTable;
        modelTable.setTable(tableName()); // pour tout afficher
        modelTable.setFilter(requeteEgalite(libelleDeCle(), cle()));
        modelTable.select();

        m_record = modelTable.record(0);
    }
}

void Entree::setRecord(const QSqlRecord &r)
{
    m_record = r;
    tableModifiee(true);
}

QSqlRecord Entree::record() const
{
    return m_record;
}

Entree::~Entree()
{

}
