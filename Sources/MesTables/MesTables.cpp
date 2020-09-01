#include "MesTables.h"
#include "horloge.h"

MesTables::MesTables()
{
}

QStringList MesTables::selectionnerChambresDisponibles(int idTypeDeChambre, occupation occ)
{
    QStringList chambres = MesTables::selectionnerChambresDisponibles(idTypeDeChambre);
    foreach(chambre ch, chambres)
    {
        // comparer aux dates des probables réservations sur la chambre
        chambreReservee chr;
        QString condition1 = QObject::tr("%1 = '%2' AND %3 = %4")
                             .arg(chr.identiteChName())
                             .arg(ch.identifiant())
                             .arg(chr.termineeName())
                             .arg(false);

        QList<QSqlRecord> records1;
        records1 << InfosSurBD::enregistrements(ChambreReservee::Libelle, condition1);
        foreach(QSqlRecord r1, records1)
        {
            chambreReservee chr1(r1);
            reservation rv(chr1.numReservation());

            if(occ.datedSortie().date() > rv.datedEntree().date()) // chevauche la réservation
            {
                chambres.removeOne(ch.identifiant());
            }
        }
    }

    return chambres;
}

QStringList MesTables::selectionnerChambresDisponibles(int idTypeDeChambre, reservation rv)
{
    QStringList chambres = selectionnerChambresDisponibles(idTypeDeChambre);

    occupation oc;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') OR (ADDDATE(%1, %4) BETWEEN '%2' AND '%3') AND %5 = %6")
                        .arg(oc.dateOccupName())
                        .arg(rv.datedEntree().date().toString(Qt::ISODate))
                        .arg(rv.datedSortie().date().toString(Qt::ISODate))
                        .arg(oc.dureeOccupName())
                        .arg(oc.termineeName())
                        .arg(false);

    QList<QSqlRecord> records_occupation;
    records_occupation << InfosSurBD::enregistrements(oc.tableName(), condition);

    foreach(QSqlRecord r, records_occupation)
    {
        chambres.removeOne(chambre(r).identifiant());
    }

    QString condition1 = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') OR (ADDDATE(%1, %4) BETWEEN '%2' AND '%3')")
                        .arg(rv.dateOccupationName())
                        .arg(rv.datedEntree().date().toString(Qt::ISODate))
                        .arg(rv.datedSortie().date().toString(Qt::ISODate))
                        .arg(rv.dureeOccupName());

    QList<QSqlRecord> records_reservation;
    records_reservation << InfosSurBD::enregistrements(rv.tableName(), condition1);

    foreach(QSqlRecord r, records_reservation)
    {
        reservation rv1(r);
        chambreReservee chr;
        QList<QSqlRecord> records;
        records << InfosSurBD::enregistrements(ChambreReservee::Libelle, QObject::tr("%1 = %2 AND %3 = %4")
                                               .arg(chr.numReservName())
                                               .arg(rv1.numReservation())
                                               .arg(chr.termineeName())
                                               .arg(false));

        foreach(QSqlRecord r, records)
        {
            chambres.removeOne(chambre(r).identifiant());
        }
    }

    return chambres;
}

QStringList MesTables::selectionnerChambresDisponibles(reservation rv)
{
    QStringList chambres = selectionnerChambresDisponibles();

    occupation oc;
    QString condition = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') OR (ADDDATE(%1, %4) BETWEEN '%2' AND '%3')")
                        .arg(oc.dateOccupName())
                        .arg(rv.datedEntree().date().toString(Qt::ISODate))
                        .arg(rv.datedSortie().date().toString(Qt::ISODate))
                        .arg(oc.dureeOccupName());

    QList<QSqlRecord> records_occupation;
    records_occupation << InfosSurBD::enregistrements(oc.tableName(), condition);

    foreach(QSqlRecord r, records_occupation)
    {
        chambres.removeOne(chambre(r).identifiant());
    }

    QString condition1 = QObject::tr("(DATE(%1) BETWEEN '%2' AND '%3') OR (ADDDATE(%1, %4) BETWEEN '%2' AND '%3')")
                        .arg(rv.dateOccupationName())
                        .arg(rv.datedEntree().date().toString(Qt::ISODate))
                        .arg(rv.datedSortie().date().toString(Qt::ISODate))
                        .arg(rv.dureeOccupName());

    QList<QSqlRecord> records_reservation;
    records_reservation << InfosSurBD::enregistrements(rv.tableName(), condition1);

    foreach(QSqlRecord r, records_reservation)
    {
        reservation rv1(r);
        chambreReservee chr;
        QList<QSqlRecord> records;
        records << InfosSurBD::enregistrements(ChambreReservee::Libelle, QObject::tr("%1 = %2 AND %3 = %4")
                                               .arg(chr.numReservName())
                                               .arg(rv1.numReservation())
                                               .arg(chr.termineeName())
                                               .arg(false));

        foreach(QSqlRecord r, records)
        {
            chambres.removeOne(chambre(r).identifiant());
        }
    }

    return chambres;
}

QStringList MesTables::selectionnerChambresDisponibles(QDate debut, QDate fin)
{
    // traiter le cas où les dates ne sont pas valides
    return selectionnerChambres();
}

QStringList MesTables::selectionnerChambresDisponibles(QDate debut, QDate fin, QStringList chambres)
{
    // traiter le cas où les dates ne sont pas valides
    return chambres;
}

QStringList MesTables::selectionnerChambresDisponibles(int idTypeDeChambre)
{
    chambre ch;
    typeDeChambre t;
    QString condition1 = QObject::tr("%1 = %2")
                        .arg(ch.idTypeChambreName())
                        .arg(idTypeDeChambre);

    QString condition = QObject::tr("%1 = %2 AND %3 IN (SELECT %4 FROM %5 WHERE %6 = %7) AND %8")
                        .arg(ch.horsServiceName())
                        .arg(false)
                        .arg(ch.idTypeChambreName()) // voir si son type est disponible
                        .arg(t.idTypeDeChambreName())
                        .arg(t.tableName())
                        .arg(t.disponibleName())
                        .arg(true)
                        .arg(condition1);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Chambre::Libelle, condition);

    QStringList identifiants;  // voir si son type est disponible
    foreach(QSqlRecord r, records)
    {
        chambre ch(r);
        identifiants << ch.identifiant();
    }

    return identifiants;
}

QStringList MesTables::selectionnerChambresDisponibles()
{
    chambre ch;
    typeDeChambre t;
    QString condition = QObject::tr("%1 = %2 AND %3 IN (SELECT %4 FROM %5 WHERE %6 = %7)")
                        .arg(ch.horsServiceName())
                        .arg(false)
                        .arg(ch.idTypeChambreName()) // voir si son type est disponible
                        .arg(t.idTypeDeChambreName())
                        .arg(t.tableName())
                        .arg(t.disponibleName())
                        .arg(true);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Chambre::Libelle, condition);

    QStringList identifiants;  // voir si son type est disponible
    foreach(QSqlRecord r, records)
    {
        chambre ch(r);
        identifiants << ch.identifiant();
    }

    return identifiants;
}

QStringList MesTables::selectionnerChambresOccupees(int idTypeDeChambre)
{
    chambre ch;
    typeDeChambre t;
    QString condition1 = QObject::tr("%1 = %2")
                        .arg(ch.idTypeChambreName())
                        .arg(idTypeDeChambre);

    QString condition = QObject::tr("%1 = %2 AND %3 = %4 AND %5 IN (SELECT %6 FROM %7 WHERE %8 = %9) AND %10")
                        .arg(ch.horsServiceName())
                        .arg(false)
                        .arg(ch.occupeeName())
                        .arg(true)
                        .arg(ch.idTypeChambreName()) // voir si son type est disponible
                        .arg(t.idTypeDeChambreName())
                        .arg(t.tableName())
                        .arg(t.disponibleName())
                        .arg(true)
                        .arg(condition1);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Chambre::Libelle, condition);

    QStringList identifiants;  // voir si son type est disponible
    foreach(QSqlRecord r, records)
    {
        chambre ch(r);
        identifiants << ch.identifiant();
    }

    return identifiants;
}

QStringList MesTables::selectionnerChambresOccupees()
{
    chambre ch;
    typeDeChambre t;
    QString condition = QObject::tr("%1 = %2 AND %3 = %4 AND %5 IN (SELECT %6 FROM %7 WHERE %8 = %9)")
                        .arg(ch.horsServiceName())
                        .arg(false)
                        .arg(ch.occupeeName())
                        .arg(true)
                        .arg(ch.idTypeChambreName()) // voir si son type est disponible
                        .arg(t.idTypeDeChambreName())
                        .arg(t.tableName())
                        .arg(t.disponibleName())
                        .arg(true);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Chambre::Libelle, condition);

    QStringList identifiants;  // voir si son type est disponible
    foreach(QSqlRecord r, records)
    {
        chambre ch(r);
        identifiants << ch.identifiant();
    }

    return identifiants;
}

QStringList MesTables::selectionnerChambres(int idTypeDeChambre)
{
    QString condition = QObject::tr("%1 = %2")
                        .arg(chambre().idTypeChambreName())
                        .arg(idTypeDeChambre);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Chambre::Libelle, condition);

    QStringList identifiants;
    foreach(QSqlRecord r, records)
    {
        chambre ch(r);
        identifiants << ch.identifiant();
    }

    return identifiants;
}

QStringList MesTables::selectionnerChambres(bool disponible, bool enEnService)
{
    chambre ch;
    QString condition = QObject::tr("%1 = %2")
                        .arg(ch.horsServiceName())
                        .arg(!enEnService);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Chambre::Libelle, condition);

    QStringList identifiants;
    foreach(QSqlRecord r, records)
    {
        chambre ch(r);
        typeDeClient t(ch.idTypeChambre());
        if(t.disponible() == disponible)
        {
            identifiants << ch.identifiant();
        }
    }

    return identifiants;
}

QStringList MesTables::selectionnerChambres()
{
    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Chambre::Libelle);

    QStringList identifiants;
    foreach(QSqlRecord r, records)
    {
        chambre ch(r);
        identifiants << ch.identifiant();
    }

    return identifiants;
}

bool MesTables::enregistrerOccupation(client &cl, occupation &oc, agent ag)
{
    oc.setTerminer(false);

    // enregistrer facture
    factureInitial fi(factureInitial::IdReception);
    int numero = fi.numero() + 1;
    oc.setFacture(fi.initial() + QString::number(numero));
    fi.setNumero(numero);

    if(oc.enregistrer())
    {
        recevoirOccup rv;
        rv.setCodeClient(cl.codeDuClient());
        rv.setNumOccup(oc.numOccupation());
        rv.setDate(Horloge::currentDateTime());
        rv.setMatriculeRecepteur(ag.matricule());

        if(rv.enregistrer())
        {
            chambre ch(oc.chambreOccupee());
            ch.setOccupee(true);
            fi.enregistrer();
            return ch.enregistrer();
        }else
        {
            oc.supprimer();
        }
    }

    return false;
}

bool MesTables::enregistrerReservation(client &cl, reservation &rv, QStringList chambres, agent ag)
{
    rv.enregistrer();

    int avance = rv.avance();

    foreach(QString ch, chambres)
    {
        chambre c(ch);

        emettreReserv em;
        em.setDate(rv.dateDeDemande());
        em.setIdentiteCh(ch);
        em.setMatriculeRecepteur(ag.matricule());
        em.setNumReserv(rv.numReservation());

        chambreReservee chr;
        chr.setIdentiteCh(ch);
        chr.setNumReservation(rv.numReservation());
        chr.setTerminer(false);

        prixChambreTTC pu(c.idTypeChambre(), rv.idProfileClient());
        int put = pu.prixTTC() * rv.dureeOccupation();
        chr.setCout(put);

        if(avance > 0)
        {
            if(avance < put)
            {
                chr.setAvance(avance);
                avance = 0; // fini
            }else
            {
                avance -= put;
                chr.setAvance(put);
            }
        }

        if(!em.enregistrer() || !chr.enregistrer())
        {
            return false; // on interrompt
        }
    }

    return true;
}

bool MesTables::arreterOccupation(chambre &ch, agent ag, QDateTime time)
{
    occupation oc(ch);
    if(oc.existe())
    {
        libererOccup li;
        li.setCodeClient(oc.codeClient());
        li.setMatriculeRecepteur(ag.matricule());
        li.setNumOccup(oc.numOccupation());
        li.setDate(time);

        if(li.enregistrer())
        {
            oc.setTerminer(true);
            oc.enregistrer();
            ch.setOccupee(false);
            return ch.enregistrer();
        }
    }

    return false;
}

bool MesTables::annulerOccupation(chambre &ch, agent ag, QDateTime time)
{
    occupation oc(ch);
    if(oc.existe())
    {
        annulerOccup annul;
        annul.setCodeClient(oc.codeClient());
        annul.setMatriculeRecepteur(ag.matricule());
        annul.setNumOccup(oc.numOccupation());
        annul.setDate(time);

        if(annul.enregistrer())
        {
            oc.setTerminer(true);
            oc.enregistrer();
            ch.setOccupee(false);
            return ch.enregistrer();
        }
    }

    return false;
}

bool MesTables::annulerReservation(reservation &reserv, agent ag, QDateTime time, QString ch)
{
    annulerReserv em;
    em.setDate(time);
    em.setIdentiteCh(ch);
    em.setMatriculeRecepteur(ag.matricule());
    em.setNumReserv(reserv.numReservation());

    chambreReservee chr(reserv.numReservation(), ch);
    chr.setTerminer(true);

    return em.enregistrer() && chr.enregistrer();
}

bool MesTables::effectuerReservation(reservation &reserv, agent ag, QDateTime time, occupation &oc, QString ch)
{
    chambre c(ch);
    c.setOccupee(true);

    effectuerReserv em;
    em.setDate(time);
    em.setIdentiteCh(ch);
    em.setMatriculeRecepteur(ag.matricule());
    em.setNumReserv(reserv.numReservation());

    chambreReservee chr(reserv.numReservation(), ch);
    chr.setTerminer(true);

    oc.setPayee(chr.avance() + oc.payee());
    oc.setCout(chr.cout());
    oc.setChambreOccupee(ch);
    oc.setIdGroupe(reserv.idGroupe());
    oc.setIdProfileClient(reserv.idProfileClient());

    return em.enregistrer() && chr.enregistrer() && c.enregistrer();
}

QString MesTables::convertirAnMoisSemaineJour(int nbJours)
{
    QString dureeStr;

    if(nbJours /360 > 0)
    {
        int annee = nbJours / 360;
        if(annee == 1)
        {
            dureeStr = "1 année";
        }else
        {
            dureeStr = QObject::tr("%1 années").arg(annee);
        }

        nbJours %= 360;
    }

    if(nbJours / 30 > 0)
    {
        int mois = nbJours / 30;
        dureeStr.append(QObject::tr(" %1 mois").arg(mois));

        nbJours %= 30;
    }

    if(nbJours / 7 > 0)
    {
        int semaine = nbJours / 7;
        if(semaine == 1)
        {
            dureeStr.append(" 1 semaine");
        }else
        {
            dureeStr.append(QObject::tr(" %1 semaines").arg(semaine));
        }

        nbJours %= 7;
    }

    if(nbJours != 0)
    {
        if(nbJours == 1)
        {
            dureeStr.append(" 1 jour");
        }else
        {
            dureeStr.append(QObject::tr(" %1 jours").arg(nbJours));
        }
    }

    return dureeStr;
}

QString MesTables::convertirJourHeureMinute(int minute)
{
    QString duree;

    if(minute / 1440 > 0)
    {
        int jour = minute / 1440;
        if(jour == 1)
        {
            duree.append("1 jour");
        }else
        {
            duree.append(QObject::tr("%1 jours").arg(jour));
        }

        minute = minute % 1440;
    }

    if(minute / 60 > 0)
    {
        int heure = minute / 60;
        if(heure == 1)
        {
            duree.append(" 1 heure");
        }else
        {
            duree.append(QObject::tr(" %1 heures").arg(heure));
        }

        minute = minute % 60;
    }

    if(minute <= 1)
    {
        duree.append(QObject::tr(" %1 minute").arg(minute));
    }else
    {
        duree.append(QObject::tr(" %1 minutes").arg(minute));
    }

    return duree;
}

QString MesTables::convertirHeureMinute(int minute)
{
    QString duree;

    if(minute / 60 > 0)
    {
        int heure = minute / 60;
        if(heure == 1)
        {
            duree.append(" 1 heure");
        }else
        {
            duree.append(QObject::tr(" %1 heures").arg(heure));
        }

        minute = minute % 60;
    }

    if(minute <= 1)
    {
        duree.append(QObject::tr(" %1 minute").arg(minute));
    }else
    {
        duree.append(QObject::tr(" %1 minutes").arg(minute));
    }

    return duree;
}

QString MesTables::crypter(QString text)
{
    QStringList liste_de_text_desord;
    QStringList liste_de_text_ord;

    QList<QChar> caracteresOrdonnes;
    for(int i = 0; i < text.count(); i++)
    {
        caracteresOrdonnes << text.at(i);
        liste_de_text_ord << text.at(i);
    }

    liste_de_text_ord.removeDuplicates();
    liste_de_text_desord = liste_de_text_ord;

    for(int i = 0; i < liste_de_text_ord.count() - 1; i += 2)
    {
        liste_de_text_desord.swap(i, i+1);
    }

    QString textCrypte;
    for(int i = 0; i < caracteresOrdonnes.count(); i++)
    {
        textCrypte.append(liste_de_text_desord.at(liste_de_text_ord.indexOf(caracteresOrdonnes.at(i))));
    }

    return textCrypte;
}

QString MesTables::decrypter(QString code)
{
    QStringList liste_de_text_desord;
    QStringList liste_de_text_ord;

    QList<QChar> caracteresDesordonnes;
    for(int i = 0; i < code.count(); i++)
    {
        caracteresDesordonnes << code.at(i);
        liste_de_text_desord << code.at(i);
    }

    liste_de_text_desord.removeDuplicates();
    liste_de_text_ord = liste_de_text_desord;

    for(int i = 0; i < liste_de_text_desord.count() - 1; i += 2)
    {
        liste_de_text_ord.swap(i, i+1);
    }

    QString textDecrypte;
    for(int i = 0; i < caracteresDesordonnes.count(); i++)
    {
        textDecrypte.append(liste_de_text_ord.at(liste_de_text_desord.indexOf(caracteresDesordonnes.at(i))));
    }

    return textDecrypte;
}

bool MesTables::activationEstValide(QString appName, QString id, QString fileName)
{
    QFile file(fileName);

    if(!file.exists())
    {
        // signaler une erreur d'installation
        QMessageBox::warning(0, "Erreur grave",
                                 QObject::tr("Une erreur est survenue durant l'exécution du programme!\n\n Veuillez réinstaller le produit pour corriger le problème."));
        return false;
    }else
    {
        // signaler une erreur de lecture
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(0, "Erreur grave",
                                 QObject::tr("Une erreur est survenue durant l'exécution du programme!\n\n Vérifier que le disque dur n'est pas protégé en lecture."));
            return false;
        }
    }

    // la lecture du fichier d'activation s'est bien déroulée
    QDataStream in(&file);
    QStringList d;
    in >> d;

    bool fichierEstVide = d.isEmpty();

    QString text;
    if(!fichierEstVide)
        text = d.first();

    if(fichierEstVide || text.isEmpty())
    {
        if(QMessageBox::warning(0, "Activation du produit", "Ce produit n'est pas encore activé. \n \n Désirez-vous l'activer maintenant? Cette opération nécessite une connexion Internet.", "Oui", "Non") == 0)
        {
            // activer le produit en ligne
        }

        return false;
    }

    // on peut décrypter maintenant le contenu du texte
    text = decrypter(text);

    // récupérer adresse mac de la machine
    QList<QNetworkInterface> interfaces;
    interfaces << QNetworkInterface::allInterfaces();

    QString itEth, itWifi, adrEth, adrWifi;
    foreach(QNetworkInterface interface, interfaces)
    {
        if(interface.humanReadableName() == QString("Connexion au réseau local"))
        {
            itEth = interface.name();
            adrEth = interface.hardwareAddress();
        }

        if(interface.humanReadableName() == QString("Connexion réseau sans fil"))
        {
            itWifi = interface.name();
            adrWifi = interface.hardwareAddress();
        }
    }

    // tester avec ceux du fichier d'activation
    QStringList parametres = text.split("&?!");

    if(parametres.count() != 9)
        return false;

    if((parametres.first() == appName)      // vérifier nom d'application
        && (parametres.at(1) == id)         // vérifier id d'application
        && (parametres.at(5) == itEth)      // " "  nom de l'interface éthernet
        && (parametres.at(6) == adrEth)     // " " adresse mac Ethernet
        && (parametres.at(7) == itWifi)     // " "  nom de l'interface wifi
        && (parametres.at(8) == adrWifi))   // " " adresse mac wifi
    {
        // vérifier que le délai d'activation est valide
        QString dureeActivation = parametres.at(3);
        if(dureeActivation != QString(DUREE_ILLIMITEE))
        {
            QDateTime dateActivation = QDateTime::fromString(parametres.at(2), Qt::ISODate);
            QDateTime dateFinActivation = dateActivation.addDays(dureeActivation.toInt());

            if(!dateActivation.isValid())
                return false;

            QDateTime now = Horloge::currentDateTime();
            if(now >= dateActivation && now <= dateFinActivation)
            {
                int joursAvantActivation = now.daysTo(dateFinActivation);
                if( joursAvantActivation <= 10)
                {
                    QMessageBox::information(0, "Activation du produit", QObject::tr("Il vous reste %1 jour(s) avant la prochaine réactivation.").arg(joursAvantActivation));
                }
            }else
            {
                // délai passé. voir tolérance
                int tolRestante = parametres.at(4).toInt() - dateFinActivation.daysTo(now);
                if(tolRestante > 0)
                {
                    QMessageBox::information(0, "Activation du produit", QObject::tr("La période de tolérance accordée pour la réactivation du produit est de %1 jour(s).").arg(tolRestante));
                }else
                {
                    if(QMessageBox::warning(0, "Activation du produit", "Le délai d'activation de ce produit est passé. \n \n Désirez-vous le réactiver maintenant? Cette opération nécessite une connexion Internet.", "Oui", "Non") == 0)
                    {
                        // réactiver le produit en ligne
                    }

                    return false;
                }
            }
        }
    }else
    {
        QMessageBox::warning(0, "Lancement du programme", "Impossible de démarrer le programme!\n\n Veuillez contacter notre équipe sur le site www.sitifel.ci");
        return false;
    }

    return true;
}

QString MesTables::contenuDuFichierActivation(QString fileName)
{
    QFile file(fileName);
    file.setPermissions(QFile::ReadOwner);

    if (!file.open(QIODevice::ReadOnly))
        return QString();

    // la lecture du fichier d'activation s'est bien déroulée
    QDataStream in(&file);
    QStringList d;
    in >> d;

    QString text;
    if(!d.isEmpty())
        text = d.first();

    return text;
}

bool MesTables::enregistrerActivation(QString fileName, QStringList parametres)
{
    QFile file(fileName);

    if(!file.exists())
    {
        // signaler une erreur d'installation
        QMessageBox::warning(0, "Erreur grave",
                                 QObject::tr("Une erreur est survenue durant l'exécution du programme!\n\n Veuillez réinstaller le produit pour corriger le problème."));
        return false;
    }else
    {
        file.setPermissions(QFile::WriteOwner);

        // signaler une erreur d'écriture
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::warning(0, "Erreur grave",
                                 QObject::tr("Une erreur est survenue durant l'exécution du programme!\n\n Vérifier que le disque dur n'est pas protégé en écriture."));
            return false;
        }
    }

    QString text;
    for(int i = 0; i < parametres.count() - 1; i++)
    {
        text.append(parametres.at(i)).append("&?!");
    }

    text.append(parametres.last());

    // crypter le text
    text = crypter(text);

    QStringList donnees;
    donnees << text;

    QDataStream out(&file);
    out << donnees;

    // enregistrer la date d'activation
    QDateTime now = Horloge::currentDateTime();

    HeureLimite hl(1);
    hl.setDebutActivation(now);
    hl.setDebutActivites(now);
    hl.enregistrer();
    return true;
}

bool MesTables::enregistrerUneOperationComptable(QDate date, QList<int>numCpts, QString description, QList<bool>debiteurs, QList<int>montants, QString matricule, bool EnDiffere)
{
    int numOp = operationsComptables::numeroLastOperation() + 1;

    for(int i=0; i < numCpts.count(); i++)
    {
        operationsComptables opc;

        opc.setNumOperation(numOp);
        opc.setNumeroCpt(numCpts.at(i));
        opc.setDescription(description);
        opc.setDate(date);
        opc.setSupprime(false);
        opc.setMatriculeAgent(matricule);

        if(debiteurs.at(i))
        {
            opc.setCredit(0);
            opc.setDebit(montants.at(i));
        }else
        {
            opc.setCredit(montants.at(i));
            opc.setDebit(0);
        }

        opc.setEnDiffere(EnDiffere);

        if(!opc.enregistrer())
            return false;

        // signaler au comptable
        actualiser at(opc.tableName());
        at.setActual(true);
        at.enregistrer();
    }

    return true;
}

bool MesTables::supprimerUneOperationComptable(int numeroOp)
{
    bool submitAll = true;
    QList<QSqlRecord> records;
    records << operationsComptables::operationsComptables_record(numeroOp);

    foreach(QSqlRecord r, records)
    {
        operationsComptables opc(r);
        opc.setSupprime(true);
        submitAll = submitAll && opc.enregistrer();

        // signaler au comptable
        actualiser at(opc.tableName());
        at.setActual(true);
        submitAll = submitAll && at.enregistrer();
    }

    return submitAll;
}

bool MesTables::enregistrerUneOperationService(const agent &ag
                                               , recuInitial::IdRecu id
                                               , QDateTime now
                                               , int montant
                                               , QString libelle
                                               , int idModeDePayement
                                               , int idTypeOperation
                                               , QString tableNameOperation
                                               , bool estUneEntree)
{
    bool submitAll = true;
    recuInitial ri(id);

    // enregistrer une opération service
    int numero1 = ri.numero() + 1;
    operationService os;
    os.setRecu(ri.initial() + QString::number(numero1));
    os.setLibelle(libelle);
    os.setCloturee(false);
    os.setDate(now);
    os.setMatriculeAgent(ag.matricule());
    os.setMontantEncaisse(montant);
    os.setIdModeDePayement(idModeDePayement);
    os.setIdTypeOperation(idTypeOperation);
    os.setIdTypeRecu(id);
    os.setEstUneEntree(estUneEntree);
    os.setTableTypeOperation(tableNameOperation);

    submitAll = submitAll && os.enregistrer();

    ri.setNumero(numero1);
    submitAll = submitAll && ri.enregistrer();

    return submitAll;
}

int MesTables::faireUnMouvementCompteClient(  const agent &ag
                                             , QDateTime date
                                             , int idCompteClient
                                             , QString libelle
                                             , int montant
                                             , bool debit
                                             , bool & operationReussie) // id de l'opération
{
    compteClient cc(idCompteClient);
    operationCompteClient occ;

    occ.setDate(date);
    occ.setIdCompteClient(cc.idCompteClient());

    if(debit)
    {
        occ.setDebit(montant);
        occ.setSolde(cc.solde() - montant);
    }else
    {
        occ.setCredit(montant);
        occ.setSolde(cc.solde() + montant);
    }

    cc.setSolde(occ.solde()); // actualiser un solde
    occ.setLibelle(libelle);
    occ.setMatriculeAgent(ag.matricule());

    operationReussie = operationReussie && occ.enregistrer() && cc.enregistrer();

    return occ.idOpCompteClient();
}

double MesTables::doubleToMoney(double value, TypeMoney type)
{
    if(type == FCFA)
    {
        double value_int = QString::number(value, 'f', 2).toDouble();
        double quotientEntier = value_int / 5;
        quotientEntier = QString::number(quotientEntier, 'f', 2).split(".").first().toDouble(); // supprimer partie décimale
        int reste = (int)(value_int - quotientEntier * 5);

        if(reste != 0)
        {
            return value_int - reste + 5;
        }else
            return value_int;
    }else
    {
        return value;
    }
}

QString MesTables::moneyToString(double value, TypeMoney type)
{
    QString money = QString::number(doubleToMoney(value, type), 'f', 2);

    QString moneySansVirgule = money.split(".").first();
    int nbChar = moneySansVirgule.count();

    if(nbChar <= 3)
        return money;
    else
    {
        int pas = nbChar;
        do
        {
            pas -= 3;
            moneySansVirgule.insert(pas, " ");
        }while(pas > 3);

        return moneySansVirgule;
    }
}

QString MesTables::doubleToAllMoney(double value)
{
    QString money = QString::number(value, 'f', 2);

    QString moneySansVirgule = money.split(".").first();
    int nbChar = moneySansVirgule.count();

    if(nbChar <= 3)
        return money;
    else
    {
        int pas = nbChar;
        do
        {
            pas -= 3;
            moneySansVirgule.insert(pas, " ");
        }while(pas > 3);

        return moneySansVirgule;
    }
}

QStringList MesTables::selectionnerChambresOccupees(int idTypeDeChambre, QDate dateArrivee)
{
    occupation oc;
    QString conditionSeChevauche = QString("SELECT %1 FROM %2 WHERE ('%3' BETWEEN DATE(%4) AND ADDDATE(DATE(%4), %5)) AND %6 = %7")
                                   .arg(oc.identiteChName())
                                   .arg(oc.tableName())
                                   .arg(dateArrivee.toString(Qt::ISODate))
                                   .arg(oc.dateOccupName())
                                   .arg(oc.dureeOccupName())
                                   .arg(oc.terminee())
                                   .arg(false);

    chambre ch;
    QString condition = QString("%1 = %2 AND %3 = %4 AND %5 IN (%6)")
                        .arg(ch.occupeeName())
                        .arg(true)
                        .arg(ch.idTypeChambreName())
                        .arg(idTypeDeChambre)
                        .arg(ch.identifiantName())
                        .arg(conditionSeChevauche);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Chambre::Libelle, condition);

    QStringList chambres;
    foreach(QSqlRecord r, records)
    {
        chambres << r.value(Chambre::Id::Identifiant).toString();
    }

    return chambres;
}

QStringList MesTables::selectionnerChambresReservees(int idTypeDeChambre, QDate dateArrivee)
{
    reservation rv;
    chambreReservee chr;
    QString conditionSeChevauche = QString("SELECT %1 FROM %2 WHERE %3 IN (SELECT %4 FROM %5 WHERE ('%6' BETWEEN DATE(%7) AND ADDDATE(DATE(%7), %8))) AND %9 = %10")
                                   .arg(chr.identiteChName())
                                   .arg(chr.tableName())
                                   .arg(chr.numReservName())
                                   .arg(rv.numReservName())
                                   .arg(rv.tableName())
                                   .arg(dateArrivee.toString(Qt::ISODate))
                                   .arg(rv.dateOccupationName())
                                   .arg(rv.dureeOccupName())
                                   .arg(chr.termineeName())
                                   .arg(false);

    chambre ch;
    QString condition = QString("%1 = %2 AND %3 IN (%4)")
                        .arg(ch.idTypeChambreName())
                        .arg(idTypeDeChambre)
                        .arg(ch.identifiantName())
                        .arg(conditionSeChevauche);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(Chambre::Libelle, condition);

    QStringList chambres;
    foreach(QSqlRecord r, records)
    {
        chambres << r.value(Chambre::Id::Identifiant).toString();
    }

    return chambres;
}

QStringList MesTables::selectionnerChambresDisponibles(int idTypeDeChambre, QDate dateArrivee)
{
    chambre ch;
    QString condition = QString("%1 = %2 AND %3 = %4")
                        .arg(ch.idTypeChambreName())
                        .arg(idTypeDeChambre)
                        .arg(ch.horsServiceName())
                        .arg(false);

    QList<QSqlRecord> records;
    records = InfosSurBD::enregistrements(ch.tableName(), condition);

    QStringList chambres_occupees = MesTables::selectionnerChambresOccupees(idTypeDeChambre, dateArrivee);
    QStringList chambres_reservees = MesTables::selectionnerChambresReservees(idTypeDeChambre, dateArrivee);

    QStringList chambres;
    foreach(QSqlRecord r, records)
    {
        QString identite = r.value(Chambre::Id::Identifiant).toString();
        if(!chambres_occupees.contains(identite) && !chambres_reservees.contains(identite))
        {
            chambres << identite;
        }
    }

    return chambres;
}

QStringList MesTables::selectionnerChambresEnService(int idTypeDeChambre)
{
    chambre ch;
    QString condition = QString("%1 = %2 AND %3 = %4")
                        .arg(ch.horsServiceName())
                        .arg(false)
                        .arg(ch.idTypeChambreName())
                        .arg(idTypeDeChambre);

    QList<QSqlRecord> records;
    records = InfosSurBD::enregistrements(Chambre::Libelle, condition);

    QStringList chambres;
    foreach(QSqlRecord r, records)
    {
        chambres << r.value(Chambre::Id::Identifiant).toString();
    }

    return chambres;
}

double MesTables::tva(double value, float tauxTVA, float tauxTotal)
{
    double l_tva = tauxTVA * value / (1 + tauxTotal);

    // arrondi l'unité à l'excès
    QString entier = QString::number(l_tva).split(".").first();
    QString dec = QString::number(l_tva).split(".").last();
    dec.resize(2);

    if(dec.toInt() >= 50)
        return entier.toDouble() + 1;
    else
        return entier.toDouble();
}

double MesTables::tt(double value, float tauxTT, float tauxTotal)
{
    double l_tt = tauxTT * value / (1 + tauxTotal);

    // arrondi l'unité à l'excès
    QString entier = QString::number(l_tt).split(".").first();
    QString dec = QString::number(l_tt).split(".").last();
    dec.resize(2);

    if(dec.toInt() >= 50)
        return entier.toDouble() + 1;
    else
        return entier.toDouble();
}
