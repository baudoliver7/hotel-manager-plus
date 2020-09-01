#ifndef PILOTEDEPLANNING_H
#define PILOTEDEPLANNING_H

#include "bdLib_global.h"

#include <QTableWidget>
#include <QLabel>
#include <QDate>
#include <QBrush>
#include <QColor>
#include <QMessageBox>
#include <QAction>
#include <QPoint>

#include "horloge.h"
#include "occupation.h"
#include "recevoirOccup.h"
#include "libererOccup.h"
#include "client.h"
#include "reservation.h"
#include "chambreReservee.h"
#include "BDFormulaireClientHotelSimple.h"
#include "BDIdentifierClientHotel.h"
#include "BDProlongerCheckOut.h"
#include "BDFacturerClient.h"
#include "BDModifierUnGroupeClient.h"
#include "BDIdentifierClientOcc.h"
#include "BDFormulaireClientSimple.h"
#include "BDFormulaireClient.h"
#include "BDChoisirUnClientDeGroupe.h"
#include "BDChoisirUnClientDeGroupeSimple.h"
#include "etage.h"
#include "BDWaiting.h"
#include "bdd.h"

#define DISPONIBLE "Disponible"
#define OCCUPEE "Occupée"
#define RESERVEE "Reservée"

#define EN_NETTOYAGE "En nettoyage"
#define A_NETTOYER "A nettoyer"
#define RETARD "Retard"

#define IDDISPONIBLE 0
#define IDOCCUPEE 1
#define IDRESERVEE 2
#define IDVIDE 3

class BDLIBSHARED_EXPORT PiloteDePlanning : public QObject
{
    Q_OBJECT

public:
    enum TypePlanning
    {
        PlanningDeReservation = 0, PlanningDOccupation = 1, PlanningMixte = 2
    };

    enum Etat
    {
        Occupee = 0, OccupeeConso = 1, Reservee = 2, ReserveeConso = 3, Disponible = 4, Action = 5
    };

    enum TypeAction
    {
        Location = 1, Reservation = 2, Liberation = 3, Indisponibilite = 4
    };

    enum Role
    {
        IdTypeReservation = 0, IdClient = 1, TotalAPayer = 2, ResteAPayer = 3, Nom = 4, Disponible_r = 5,
        Occupee_r = 6, Reservee_r = 7, HeureEntree = 8, HeureDeSortie = 9, Modifiee = 10, Creee = 11,
        ColEntree = 12, ColSortie = 13, Entree = 14, Sortie = 15, Intermediaire = 16, NomComplet = 17,
        SortieDiffusee = 18, Groupe_r = 19, Executee = 20, IdPieceIdentite = 21, IdProfileClient = 22,
        NbEnfAccMoinsDe15 = 23, DestinationExacte = 24
    };

public:
    PiloteDePlanning(BDD * db, const agent & ag, QTableWidget * tableWidget, QList<chambre*> chambres, TypePlanning type, QWidget * parent = 0, bool planningsReadOnly = false);
    ~PiloteDePlanning();

    void enregisterTout();
    void showReservation(const reservation & rv, bool AvecCondition = true);
    void clearOccupation(const occupation & oc);
    void clearReservation(const reservation & rv);
    void clearEspace(int row, int colDeb, int colFin);
    void showOccupations(int colDeb, int colFin);
    void showReservations(int colDeb, int colFin);
    void showAllReservations(int colDeb, int colFin);
    void clearOccupations();
    void clearReservations();
    void showOccupations();
    void showReservations(); // montre toutes les réservations non annulées
    void showAllReservations(); // montre toutes les réservations

    void showDisponibilite(QDate date, int nb);
    void showNbOccupee(QDate date, int nb);
    void showNbReservee(QDate date, int nb);

    void setColorOccupee(QColor color);
    void setColorOccupeeConso(QColor color);
    void setColorReservee(QColor color);
    void setColorReserveeConso(QColor color);
    void setColorDisponible(QColor color);
    void setColorAction(QColor color);

    QString moisDebutLongName()const;
    QString moisFinLongName()const;
    int annee()const;

    QDate dateDebut()const;
    QDate dateFin()const;

    void initTable();

signals:
    void factureModifiee();
    void occupationEnregistree(occupation oc);
    void reservationEnregistree(reservation rv);
    void rendreChambresIndispo(QDate debut, QDate fin, QString ch);
    void imprimerOccupation(occupation oc);
    void rendreChambresDispo(QDate debut, QDate fin, QString ch);
    void opElt();
    void dataATraiter(int nb);
    void typeOperation(QString libelle);
    void planningModifie(bool);

public slots:
    void rafraichirReservationsEnCours();
    void rafraichirLocationsEnCours();
    void showOccupation(const occupation & oc);
    void setDebutMois(QString longName);
    void setFinMois(QString longName);
    void setJourDebut(QDate date);
    void setJourFin(QDate date);
    void setAnnee(int annee);
    void setAnnee(QString annee);
    void show();
    void showOccupationsComplet();
    void showReservationsComplet();
    void showSigneReservations();
    void showSigneReservation(reservation rv);
    void showSigneOccupation(occupation oc);
    void showSigneOccupations();
    void rafraichirPlanning();
    void rafraichirPlanningOccup();
    void rafraichirPlanningReserv();
    void rafraichirPlanning(int colDebut, int colFin);
    void rafraichirPlanningOccup(int colDebut, int colFin);
    void rafraichirPlanningReserv(int colDebut, int colFin);
    void showChambresIndispo(QDate debut, QDate fin, QString ch);
    void showChambresDispo(QDate debut, QDate fin, QString ch);

private:
    BDD * m_db;
    QTableWidget * m_tableWidget;
    QWidget * m_parent;
    agent * m_agent;
    QDate m_date_debut;
    QDate m_date_fin;
    QDate m_date_fin_precedent;
    QDate m_date_debut_precedent;
    QStringList m_chambres_str;
    QList<chambre*> m_chambres;
    QList<QTableWidgetItem *> m_itemsADeplacer;
    QList<QPoint> m_nouveauxChecksIn;
    int m_rowOfCheckIn;
    int m_colOfCheckIn;
    QColor m_colorOfCheckIn;
    bool m_moisAjoute;
    bool m_planningRecree;
    int m_colDebMoisAjoute;
    int m_colFinMoisAjoute;
    TypePlanning m_typePlanning;
    bool m_occupNonIdentifiee;
    bool m_estHorsZoneChambre;
    bool m_planningsReadOnly;

    QAction * m_actionCheckIn;
    QAction * m_actionCheckOut;
    QAction * m_actionConfirmerSortie;
    QAction * m_actionIdentifierClient;
    QAction * m_actionAnnulerReserv;
    QAction * m_actionFacturerClient;
    QAction * m_actionDebuterDeplacement;
    QAction * m_actionTerminerDeplacement;
    QAction * m_actionDebuterNettoyage;
    QAction * m_actionTerminerNettoyage;
    QAction * m_actionANettoyer;
    QAction * m_actionNouveauCheckOut;
    QAction * m_actionReserver;
    QAction * m_actionVoirDetailsSurClient;
    QAction * m_actionEnregistrer;
    QAction * m_actionOccuper;
    QAction * m_actionImprimerFacture;
    QAction * m_actionImprimerRecu;
    QAction * m_actionExecuterReserv;
    QAction * m_actionLierAUnGroupe;

    QColor m_colorOccupee;
    QColor m_colorOccupeeConso;
    QColor m_colorReservee;
    QColor m_colorReserveeConso;
    QColor m_colorDisponible;
    QColor m_colorAction;

    bool dayIsIn(QDate date);

    void showCell(int row, int column, int value);
    void showCell(int row, int column, QString value, QStringList data, QColor color, QIcon icon = QIcon());
    void showCell(int row, int column, QTableWidgetItem * item);

    void showEspaceReserve(int row, int colDeb, int colFin, bool actualiserInfosGene = true);

    void showCell(int row, int column, QString value, Etat etat, QStringList data);

    void initCelluleCh(int row, int column);
    void initCelluleEntete(int row, int column);

    void initialiserCouleurs();
    void initialiserCellules();
    void initialiserCellules(int colDeb, int colFin);
    void initialiserActions();

    void showHeaderVertical();
    void showHeaderHorizontal();
    void dimensionnerHeaderHorizontal();

    QColor colorOfEtat(Etat etat)const;
    Etat etatOfColor(const QColor & color);
    bool itemIsTheFirst(const QTableWidgetItem * item);

    int row(QString chambre);
    int column(QDate date);
    QDate date(int col);
    QString chambreDe(int row);

    bool estDisponible(int row, int column);
    bool estReservee(int row, int column);
    bool estOccupee(int row, int column);
    bool estReserveeConso(int row, int column);
    bool estOccupeeConso(int row, int column);
    bool estEntree(int row, int column);
    bool estSortie(int row, int column);
    int colEntree(int row, int column);
    int colSortie(int row, int column);
    bool clientExiste(int row, int column);

    void setData(int row, int column, int key, int value);
    void setData(int row, int column, int key, QString value);
    void setData(int row, int column, QStringList data);
    void setToolTip(int row, int column, QString text);
    void setTextureNonToutPayee(int row, int column);
    void setTextureToutPayee(int row, int column);
    void setTexture(int row, int column, QBrush brush);
    QBrush getTexture(int row, int column);

    QString toolTip(int row, int column);

    QString data(int row, int column, int key);
    QStringList data(int row, int column);

    void showValue(int row, int column, QString value);

    void initItemDebutOccup(int row, int column);
    void initItemFinOccup(int row, int column);
    void initItemDebutReserv(int row, int column);
    void initItemFinReserv(int row, int column);
    void initItemDispo(int row, int column);
    void initItemIndispo(int row, int column);
    void initItemSigneReserve(int row, int column);
    void initItemSigneOccupe(int row, int col);

    void afficherInfosGenerales(int col);
    void afficherInfosGenerales(int colDeb, int colFin);
    void afficherInfosGenerales();

    void showDisponibilite(int col, int nb);
    void showNbOccupee(int col, int nb);
    void showNbReservee(int col, int nb);
    void setActionsEnabled(bool enabled);

    bool estHorsZoneChambre(int row, int column);
    void adapterLimitesDuPlanning();
    void adapterLimitesDuPlanningOccup();
    void adapterLimitesDuPlanningReserv();

    bool estPlanningMixte();
    bool estPlanningOccup();
    bool estPlanningReserv();

private slots :
    void checkIn();
    void checkIn(int row, int column);
    void checkIn(int row, int column, bool occuper);
    void checkOut();
    void checkOut(int row, int column);
    void voirDetailsSurClient();
    void reserver();
    void occuper();
    void facturerSelection();
    void identifierClient();
    void annulerReservation();
    void debuterDeplacementDeSelection();
    void terminerDeplacementDeSelection();
    void debuterNettoyageDeSelection();
    void terminerNettoyageDeSelection();
    void selectionANettoyer();
    void preparerActions();
    void construirePlanning();
    void arreterLocation();
    void prolongerCheckOut();
    void enregistrer();
    void executerReservation();
    void lierAUnGroupe();
    void imprimerFacture();
    void verifierZoneValide(QModelIndex);
    void updateEtatActionChecks(QModelIndex);
    void updateEtatActionReserverEtOccuper(QModelIndex);
    void updateEtatActionDeposerUnMontant(QModelIndex);
    void updateEtatActionAnnulerReservation(QModelIndex);
    void updateEtatActionDeplacerReservation(QModelIndex);
    void updateEtatActionIdentifierClient(QModelIndex);
    void updateEtatActionVoirDetailsClient(QModelIndex);
    void updateEtatActionDeposerIci(QModelIndex);
    void updateEtatActionConfirmerSortie(QModelIndex);
    void updateEtatActionProlongerCheckOut(QModelIndex);
    void updateEtatActionEnregistrer(QModelIndex);
    void updateEtatActionExecuterReserv(QModelIndex);
    void updateEtatActionLierAUnGroupe(QModelIndex);
    void updateEtatActionImprimerFacture(QModelIndex);
    void updateEtatActionFacturerClient(QModelIndex index);

public:
    static QStringList tousLesMoisLongName();
    static QStringList tousLesMoisShortName();
    static QStringList tousLesJoursLongName();
    static QString moisLongName(int month);
    static QString moisShortName(int month);
    static QString jourLongName(int jour);
    static int moisFromShortName(QString name);
    static int moisFromLongName(QString name);
    static int jourFromLongName(QString name);
};

#endif // PILOTEDEPLANNING_H
