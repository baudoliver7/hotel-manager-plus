#ifndef MDISERVICECOMPTABLE_H
#define MDISERVICECOMPTABLE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QString>
#include <QCloseEvent>
#include <QTimer>
#include <QTreeWidgetItem>
#include <QMdiSubWindow>

#include "InfosSurBD.h"
#include "BDMessagerie.h"
#include "horloge.h"
#include "agent.h"
#include "actualiser.h"
#include "MesTables.h"
#include "compteform.h"
#include "PlanComptable.h"
#include "BDRenommerCompte.h"


#define DEBUT_DU_MOIS "Report de la caisse"
#define APPNAME "HMP's product win32"

namespace Ui {
    class MdiServiceComptable;
}

class MdiServiceComptable : public QWidget {
    Q_OBJECT
public:
    MdiServiceComptable(BDD * db, agent * r, Horloge * h, QString path, QWidget *parent = 0);
    ~MdiServiceComptable();

    bool seDeconnecter();
    void lancerLireMsg();
    void lancerOPCModified();
    void supprimerOPC();
    void setAfficherMesComptesEnArbre(bool afficher);

public slots:
    void lancerCurrentRowIsValid(bool);

signals:
    void closed();
    void lireMsg();
    void opcModified();
    void currentRowIsValid(bool);

public slots:
    void chargerMesComptes();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::MdiServiceComptable *ui;
    Horloge * m_horloge;
    agent * m_comptable;
    QWidget * m_parent;
    bool m_fermer;
    BDMessagerie * m_bdMessagerie;
    QAction * m_actionRenommer;
    BDD * m_db;
    QString m_chemin;
    bool m_afficherMesComptesEnArbre;

    void initArbreComptes();
    void initialiserBDMessage();
    void afficherDateDeConnection();
    QTreeWidgetItem * ajouterParent(int numCptEnfant, QTreeWidgetItem * itemTopLevel); // ajoute tous les comptes parents dans l'arbre
    CompteForm * activeCompteForm();

private slots:
    void editerLibelleDeCompte();
    void updateEtatActionRenommer(QModelIndex);
    void on_treeWidget_doubleClicked(QModelIndex index);
    void afficherHorloge();
    void actualiserFenetre();
    void testerCurrentRowIsValid();
};

#endif // MDISERVICECOMPTABLE_H
