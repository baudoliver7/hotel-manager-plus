#ifndef MDIPLANNING_H
#define MDIPLANNING_H

#include "bdLib_global.h"

#include <QWidget>
#include <QSqlRelationalTableModel>
#include <QPainter>
#include <QPaintDevice>
#include <QCloseEvent>
#include <QPrintDialog>
#include <QPrinter>

#include "PiloteDePlanning.h"
#include "MesTables.h"
#include "HeureLimite.h"
#include "DialogCalendar.h"
#include "clotureService.h"
#include "factureHotelIndividu.h"
#include "recu.h"
#include "operation.h"
#include "BDSetPeriode.h"
#include "BDWaiting.h"
#include "bdd.h"

#define ID 0
#define FACTURE 1
#define CLIENT 2
#define CHAMBRE 3
#define DATEARRIVEE 4
#define DATEDEPART 5
#define DUREE 6
#define MONTANTTOTAL 7
#define MONTANTPAYE 8
#define MONTANTRESTANT 9
#define MATRICULEAGENT 10

namespace Ui {
    class MdiPlanning;
}

class BDLIBSHARED_EXPORT MdiPlanning : public QWidget {
    Q_OBJECT
public:
    MdiPlanning(BDD * db, const agent & ag, Horloge * horloge, QWidget *parent = 0, bool showPlanningsOnly = false, bool planningsReadOnly = false);
    ~MdiPlanning();

    bool seDeconnecter();
    void enregisterTout();

signals:
    void afficherPlanningOccup();
    void afficherPlanningReserv();
    void closed();
    void lancer();
    void planningModifie(bool);

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::MdiPlanning *ui;
    bool m_planningOccupModified;
    bool m_planningReservModified;
    PiloteDePlanning * m_piloteDePlanningReserv;
    PiloteDePlanning * m_piloteDePlanningOccup;
    QSqlRelationalTableModel * m_modelActivites;
    BDWaiting * m_bdWaiting;
    QStringList m_chambres_str;
    QList<chambre*> m_chambres;
    agent * m_agent;
    Horloge * m_horloge;
    Operation * m_op;
    bool m_affichage;
    bool m_fermer;
    BDD * m_db;
    bool m_showPlanningsOnly;
    bool m_planningsReadOnly;

    QStringList m_moisDebutRetenus;

    void initPlanningReservation();
    void initPlanningOccupation();
    void initialiserTableauActivites();
    void initialiserTableau();
    void initialiserTableauDeCeJour();
    void afficherElement(int row, int column, const QString &value, bool impaye = true);

public slots:
    void actualiserOngletActif();
    void chargerActivites();

private slots:
    void cloturer();
    void setPeriodeOccup();
    void setPeriodeReserv();
    void setPlanningReservModified(bool);
    void setPlanningOccupModified(bool);
    void verifierHeureFinOccupation();
    void afficerBD();
    void chargerChambresDispo();
    void on_btn_imprimerRecu_clicked();
    void on_btn_imprimerFacture_clicked();
    void on_btn_imprimerFactureDeCeJour_clicked();
    void on_btn_reglerFacture_clicked();
    void chargerFacturesImpayees();
    void chargerFacturesDeCeJour();
    void actualiserFenetre();
    void on_btn_cloturer_clicked();
    void updateEtatBtnImprimerFacture(QModelIndex);
    void updateEtatBtnImprimerFactureDeCeJour(QModelIndex);
    void updateEtatBtnImprimerRecu(QModelIndex);
    void updateEtatBtnCloturer();    
    void afficherLocations();
    void actualiserFenetre(QList<occupation>);
    void afficherReservations();
    void afficherMixte();
    void imprimer(const occupation & oc);
    void imprimer(const operationService & os);
};

#endif // MDIPLANNING_H
