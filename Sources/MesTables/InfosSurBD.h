#ifndef INFOSSURBD_H
#define INFOSSURBD_H

#include "MesTables_global.h"

#include <QString>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QStringList>
#include <QSqlQuery>
#include <QMessageBox>

namespace Actualiser
{
    const QString Libelle = "actualiser";

    namespace Id
    {
        enum IdDuLibelle
        {
            TableName = 0, Actual = 1
        };
    }
}

namespace Agent
{
    const QString Libelle = "agent";

    namespace Id
    {
        enum IdDuLibelle
        {
            Matricule = 0, Nom = 1, Prenoms = 2, SexePrecis = 3, Login = 4, Password = 5, Residence = 6,
            Cel = 7, Tel = 8, Email = 9, BP = 10, Statut = 11, IdService = 12, DateInscription = 13,
            DateActivation = 14, Connecte = 15, EtatFinConnecte = 16, CodeDeSortie = 17, Activites = 18
        };
    }
}

namespace AnnulerOccup
{
    const QString Libelle = "annuler_occup";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumAnnuler = 0, NumOccupation = 1, MatriculeRecepteur = 2, CodeClient = 3, Date = 4
        };
    }
}

namespace AnnulerReserv
{
    const QString Libelle = "annuler_reserv";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumAnnuler = 0, NumReservation = 1,  IdentiteCh = 2, MatriculeRecepteur = 3, Date = 4
        };
    }
}

namespace Chambre
{
    const QString Libelle = "chambre";

    namespace Id
    {
        enum IdDuLibelle
        {
            Identifiant = 0, HorsService = 1, Occupee = 2, IdTypeChambre = 3, IdEtage = 4
        };
    }
}

namespace ChambreReservee
{
    const QString Libelle = "chambres_reservees";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdChambreReservee = 0, IdentiteCh = 1, Cout = 2, Avance = 3, NumReservation = 4, Terminee = 5
        };
    }
}

namespace Client
{
    const QString Libelle = "client";

    namespace Id
    {
        enum IdDuLibelle
        {
            CodeClient = 0, Nom = 1, Prenoms = 2, Homme = 3, DateDeNaissance = 4, LieuDeNaissance = 5, Pere = 6,
            Mere = 7, Profession = 8, DomicileHabituel = 9, Nationalite = 10, Cel = 11, Tel = 12,
            Email = 13, BP = 14
        };
    }
}

namespace EffectuerReserv
{
    const QString Libelle = "effectuer_reserv";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumEffectuer = 0, NumReservation = 1, IdentiteCh = 2, MatriculeRecepteur = 3, Date = 4
        };
    }
}

namespace EmettreReserv
{
    const QString Libelle = "emettre_reserv";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumEmettre = 0, NumReservation = 1, IdentiteCh = 2, MatriculeRecepteur = 3, Date = 4
        };
    }
}

namespace HeureBD
{
    const QString Libelle = "heure_bd";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumHeure = 0, HeureFinOccupation = 1, TempsDeTol = 2, TempsLocAnnulation = 3, LastHourSys = 4, DebutActivation = 5,
            DureeActivation = 6, DureeRestante = 7, DureeTolerance = 8, Enregistre = 9, ValeurModifiee = 10,
            InstallationID = 11, DebutActivites = 12
        };
    }
}

namespace LibererOccup
{
    const QString Libelle = "liberer_occup";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumLiberer = 0, NumOccupation = 1, MatriculeRecepteur = 2, CodeClient = 3, Date = 4
        };
    }
}

namespace Message
{
    const QString Libelle = "message";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumMsg = 0, Contenu = 1, Expediteur = 2, Destinataire = 3, HeureEnvoi = 4, Lue = 5
        };
    }
}

namespace Occupation
{
     const QString Libelle = "occupation";

     namespace Id
     {
         enum IdDuLibelle
         {
             NumOccup = 0, DateOccupation = 1, DureeOccup = 2, IdentifiantCh = 3, Cout = 4, FraisSup = 5,
             Payee = 6, DestinationExacte = 7, EnfAccMoinsDe15 = 8, CodeClient = 9, Terminee = 10, FraisSupPaye = 11,
             Facture = 12, IdGroupe = 13, IdProfileClient = 14
         };
     }
}

namespace RecevoirOccup
{
    const QString Libelle = "recevoir_occup";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumRecevoir = 0, NumOccupation = 1, MatriculeRecepteur = 2, CodeClient = 3, Date = 4
        };
    }
}

namespace Reservation
{
    const QString Libelle = "reservation";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumReserv = 0, DateDeDemande = 1, DateOccup = 2, DureeOccup = 3, Cout = 4, Avance = 5, CodeClient = 6,
            IdGroupe = 7, IdProfileClient = 8
        };
    }
}

namespace Service
{
    const QString Libelle = "heures_activites";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumService = 0, DateDebut = 1, DateFin = 2, MatriculeAgent = 3
        };
    }
}

namespace OperationsComptables
{
    const QString Libelle = "operations_comptable";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdOpc = 0, NumeroOpc = 1, Date = 2, Description = 3, Credit = 4, Debit = 5, NumeroCpt = 6, EnDiffere = 7, Supprime = 8, MatriculeAgent = 9
        };
    }
}

namespace PlanComptable
{
    const QString Libelle = "plan_comptable_syscohada";

    namespace Id
    {
        enum IdDuLibelle
        {
            NumeroCpt = 0, Libelle = 1, LibellePerso = 2, Classe = 3, Utilise = 4
        };
    }
}

namespace ServiceEntreprise
{
    const QString Libelle = "service_entreprise";

    namespace Id
    {
        enum IdDuLibelle
        {
            Id_se = 0, Nom = 1
        };
    }
}

namespace ConfigServiceCompta
{
    const QString Libelle = "config_service_compta";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdCsc = 0, Action = 1, CompteAssocie = 2, IdSe = 3
        };
    }
}

namespace InfosHotel
{
    const QString Libelle = "infos_hotel";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdInfosHotel = 0, Nom = 1, SituationGeo = 2, NumeroTel = 3, NumeroCel = 4, Email = 5,
            BP = 6, SiteWeb = 7, Logo = 8, Ville = 9, NumRecu = 10
        };
    }
}

namespace PieceIdentiteClient
{
    const QString Libelle = "piece_identite_client";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdPieceIdentiteClient = 0, Nature = 1, Numero = 2, DateDelivrance = 3, LieuDelivrance = 4, AgentDelivreur = 5,
            CodeClient = 6, DateReception = 7, NumOccupation = 8
        };
    }
}

namespace PrixChambreTTC
{
    const QString Libelle = "prix_chambre_ttc";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdPrixChambreTTC = 0, IdProfile = 1, IdTypeChambre = 2, PrixTTC = 3
        };
    }
}

namespace ProfileClient
{
    const QString Libelle = "profiles_client";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdProfile = 0, Profile = 1, Disponible = 2, IdTypeClient = 3
        };
    }
}

namespace Taux
{
    const QString Libelle = "taux";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdTaux = 0, Nom = 1, Valeur = 2
        };
    }
}

namespace TypeDeClient
{
    const QString Libelle = "types_de_client";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdTypeDeClient = 0, Type = 1, Disponible = 2
        };
    }
}

namespace TypeDeChambre
{
    const QString Libelle = "types_de_chambre";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdTypeDeChambre = 0, Type = 1, Disponible = 2
        };
    }
}

namespace MenuResto
{
    const QString Libelle = "menu_resto";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdMenuResto = 0, LibelleMenu = 1, Prix = 2, IdCatMenu = 3, Supprime = 4
        };
    }
}

namespace ConsoResto
{
    const QString Libelle = "conso_resto";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdConsoResto = 0, IdMenu = 1, NbMenu = 2, CoutTotal = 3, IdRestoCResto = 4
        };
    }
}

namespace FactureInitial
{
    const QString Libelle = "facture_initial";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdFactureInitial = 0, IdService = 1, TypeDeFacture = 2, Initial = 3, Numero = 4
        };
    }
}

namespace TableResto
{
    const QString Libelle = "table_resto";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdTableResto = 0, Libelle = 1, Occupee = 2, Supprime = 3, EstBar = 4
        };
    }
}

namespace RepasCompletResto
{
    const QString Libelle = "repas_complet_resto";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdRepasCResto = 0, CodeClient = 1, DateArrivee = 2, DateDepart = 3, DureeEnMinutes = 4,
            TotalAPayer = 5, MontantTotalEncaisse = 6, IdTableResto = 7, MatriculeCaissier = 8,
            Facture = 9, FactureMiseAJour = 10, NumOccupation = 11
        };
    }
}

namespace OperationService
{
    const QString Libelle = "operations_service";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdOperationService = 0, Recu = 1, Date = 2, Libelle = 3, MontantEncaisse = 4, MatriculeAgent = 5,
            Cloturee = 6, IdModeDePayement = 7, IdTypeOperation = 8, IdClotureService = 9, IdTypeRecu = 10,
            Depouille = 11, EstUneEntree = 12, TableTypeOperation = 13
        };                
    }
}

namespace ClotureService
{
    const QString Libelle = "clotures_service";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdClotureService = 0, Date = 1, DepotSurCompteClient = 2, MontantEncaisse = 3, MontantRetire = 4,
            MontantRestant = 5,
            ReglementEspece = 6, ReglementCheque = 7, ReglementCarteDeCredit = 8, ReglementCompteClient = 9,
            MatriculeAgent = 10, Depouille = 11
        };
    }
}

namespace ModeDePayement
{
    const QString Libelle = "mode_de_payement";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdModeDePayement = 0, Mode = 1
        };
    }
}

namespace RecuInitial
{
    const QString Libelle = "recu_initial";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdRecuInitial = 0, IdService = 1, TypeDeRecu = 2, Initial = 3, Numero = 4
        };
    }
}

namespace Groupe
{
    const QString Libelle = "groupe";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdGroupe = 0, Libelle = 1, IdResponsable = 2, NbPersonnesEnreg = 3, Avance = 4, FraisLocation = 5,
            FraisLocationPayee = 6, FraisSup = 7, FraisSupPayee = 8, DateDeDemande = 9, DateOccupation = 10,
            DureeOccupation = 11, Provenance = 12, MatriculeAgent = 13, Terminee = 14, Facture = 15,
            NumeroTel = 16, NumeroCel = 17, Email = 18, BoitePostale = 19, IdProfileClient = 20,
            NbPersonnesPrevues = 21, IdTypeDeChambreMaj = 22, AvanceActu = 23
        };
    }
}

namespace GroupeLiaison
{
    const QString Libelle = "groupe_liaison";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdGroupeLiaison = 0, IdGroupe = 1, CodeClient = 2
        };
    }
}

namespace CompteClient
{
    const QString Libelle = "comptes_client";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdCompteClient = 0, Libelle = 1, CodeClient = 2, Solde = 3
        };
    }
}

namespace OperationCompteClient
{
    const QString Libelle = "operations_compte_client";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdOpCompteClient = 0, Date = 1, Libelle = 2, Credit = 3, Debit = 4, Solde = 5,
            IdCompteClient = 6, MatriculeAgent = 7
        };
    }
}

namespace Etage
{
    const QString Libelle = "etage";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdEtage = 0, Niveau = 1
        };
    }
}

namespace CategorieMenu
{
    const QString Libelle = "categorie_menu";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdCategorieMenu = 0, Libelle = 1, IdTypeCatMenu = 2, Supprimee = 3
        };
    }
}

namespace TypeCategorieMenu
{
    const QString Libelle = "type_categorie_menu";

    namespace Id
    {
        enum IdDuLibelle
        {
            IdTypeCatMenu = 0, Libelle = 1
        };
    }
}


class MESTABLESSHARED_EXPORT InfosSurBD
{
public:
    static QStringList fieldsNames(const QSqlTableModel * model);
    static QStringList fieldsNames(QString tableName);
    static QList<QSqlRecord> enregistrements(QString tableName, QString conditionDeSelection);
    static QList<QSqlRecord> enregistrements(QString tableName);
};

#endif // INFOSSURBD_H
