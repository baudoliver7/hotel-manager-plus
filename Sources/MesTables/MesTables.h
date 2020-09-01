#ifndef MESTABLES_H
#define MESTABLES_H

#include <QString>
#include <QStringList>
#include <QFile>
#include <QDataStream>
#include <QNetworkInterface>

#include "MesTables_global.h"
#include "occupation.h"
#include "reservation.h"
#include "chambre.h"
#include "HeureLimite.h"
#include "recevoirOccup.h"
#include "emettreReserv.h"
#include "annulerReserv.h"
#include "effectuerReserv.h"
#include "agent.h"
#include "libererOccup.h"
#include "actualiser.h"
#include "operationsComptables.h"
#include "annulerOccup.h"
#include "typeDeChambre.h"
#include "typeDeClient.h"
#include "chambreReservee.h"
#include "prixChambreTTC.h"
#include "annulerReserv.h"
#include "recuInitial.h"
#include "operationService.h"
#include "repasCompletResto.h"
#include "factureInitial.h"
#include "operationCompteClient.h"
#include "compteClient.h"

#define DUREE_ILLIMITEE "Illimitée"

class MESTABLESSHARED_EXPORT MesTables {
public:
    enum TypeMoney
    {
        FCFA = 1
    };

    MesTables();

    static QStringList selectionnerChambresEnService(int idTypeDeChambre);

    static QStringList selectionnerChambresDisponibles(int idTypeDeChambre, occupation occ);
    static QStringList selectionnerChambresDisponibles(int idTypeDeChambre, reservation rv);
    static QStringList selectionnerChambresDisponibles(reservation rv);
    static QStringList selectionnerChambresDisponibles(QDate debut, QDate fin);
    static QStringList selectionnerChambresDisponibles(QDate debut, QDate fin, QStringList chambres);
    static QStringList selectionnerChambresDisponibles(int idTypeDeChambre);
    static QStringList selectionnerChambresDisponibles();

    static QStringList selectionnerChambresLibres(int idTypeDeChambre);
    static QStringList selectionnerChambresOccupees(int idTypeDeChambre);
    static QStringList selectionnerChambresOccupees();
    static QStringList selectionnerChambres(int idTypeDeChambre);
    static QStringList selectionnerChambres(bool disponible, bool enEnService);
    static QStringList selectionnerChambres();

    static QStringList selectionnerChambresOccupees(int idTypeDeChambre, QDate dateArrivee);
    static QStringList selectionnerChambresReservees(int idTypeDeChambre, QDate dateArrivee);
    static QStringList selectionnerChambresDisponibles(int idTypeDeChambre, QDate dateArrivee);

    static bool enregistrerOccupation(client & cl, occupation & oc, agent ag);
    static bool enregistrerReservation(client & cl, reservation & rv, QStringList chambres, agent ag);

    static bool arreterOccupation(chambre & ch, agent ag, QDateTime time);
    static bool annulerOccupation(chambre & ch, agent ag, QDateTime time);
    static bool annulerReservation(reservation & reserv, agent ag, QDateTime time, QString ch);
    static bool effectuerReservation(reservation & reserv, agent ag, QDateTime time, occupation & oc, QString ch);

    static QString convertirAnMoisSemaineJour(int nbJours);
    static QString convertirJourHeureMinute(int minute);
    static QString convertirHeureMinute(int minute);

    static QString crypter(QString text);
    static QString decrypter(QString code);

    static bool activationEstValide(QString appName, QString id, QString fileName);
    static QString contenuDuFichierActivation(QString fileName);
    static bool enregistrerActivation(QString fileName, QStringList parametres);

    static bool enregistrerUneOperationComptable(QDate date, QList<int> numCpts, QString description, QList<bool> debiteurs, QList<int> montants, QString matricule, bool EnDiffere = false);
    static bool supprimerUneOperationComptable(int numeroOp);

    static bool enregistrerUneOperationService(  const agent & ag
                                               , recuInitial::IdRecu id
                                               , QDateTime now
                                               , int montant
                                               , QString libelle
                                               , int idModeDePayement
                                               , int idTypeOperation
                                               , QString tableNameOperation
                                               , bool estUneEntree = true);

    static int faireUnMouvementCompteClient(   const agent & ag
                                             , QDateTime date
                                             , int idCompteClient
                                             , QString libelle
                                             , int montant
                                             , bool debit
                                             , bool & operationReussie);

    static double tva(double value, float tauxTVA, float tauxTotal);
    static double tt(double value, float tauxTT, float tauxTotal);
    static double doubleToMoney(double value, TypeMoney type = FCFA);
    static QString moneyToString(double value, TypeMoney type = FCFA);
    static QString doubleToAllMoney(double value);
    template<class T1, class T2>
    static bool seChevauchent(T1 t1, T2 t2);
};

template<class T1, class T2>
bool MesTables::seChevauchent(T1 t1, T2 t2)
{
    return !((t1.datedEntree() >= t2.datedSortie())||(t1.datedSortie() <= t2.datedEntree()));
}

#endif // MESTABLES_H
