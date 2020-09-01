#include "PiloteDePlanning.h"

PiloteDePlanning::PiloteDePlanning(BDD *db, const agent &ag, QTableWidget *tableWidget, QList<chambre *>chambres, TypePlanning type, QWidget *parent, bool planningsReadOnly)
{
    m_planningsReadOnly = planningsReadOnly;
    m_db = db;
    m_parent = parent;
    m_moisAjoute = false;
    m_planningRecree = true;
    m_rowOfCheckIn = -1; // aucun check-in
    m_typePlanning = type;

    m_agent = new agent(ag);
    m_tableWidget = tableWidget;
    m_tableWidget->setRowCount(0);
    m_tableWidget->setColumnCount(0);
    m_tableWidget->setMouseTracking(true);
    m_chambres = chambres;

    foreach(chambre * ch, m_chambres)
    {
        m_chambres_str << ch->identifiant();
    }

    // sélectionner le mois en cours
//    QDate now = Horloge::currentDate();
//    m_date_debut = QDate(now.year(), now.month(), 1);
//    m_date_fin = QDate(now.year(), now.month(), m_date_debut.daysInMonth());

    QDate now = Horloge::currentDate();
    m_date_debut = now.addDays(-15);
    m_date_fin = now.addDays(15);
}

PiloteDePlanning::~PiloteDePlanning()
{
    m_itemsADeplacer.clear();
    delete m_agent;
}

void PiloteDePlanning::initTable()
{
    initialiserCouleurs();

    m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if(!m_planningsReadOnly)
    {
        m_tableWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        initialiserActions();
    }

    adapterLimitesDuPlanning();
    construirePlanning();
    initialiserCellules();

    if(m_typePlanning == PlanningDeReservation)
    {
        m_tableWidget->setRowHidden(IDOCCUPEE, true);
    }else
    {
        if(m_typePlanning == PlanningDOccupation)
        {
            m_tableWidget->setRowHidden(IDRESERVEE, true);
        }
    }

    // positionner à la date d'aujourd'hui si possible
    QDate now = Horloge::currentDate();
    if((now >= m_date_debut) && (now <= m_date_fin))
    {
        int col = m_date_debut.daysTo(now);
        m_tableWidget->scrollToItem(m_tableWidget->item(0, col));
    }
}

void PiloteDePlanning::initialiserCouleurs()
{
    m_colorAction.setRedF(1.0);
    m_colorAction.setAlphaF(0.3);

    m_colorDisponible = QColor(Qt::transparent);

    m_colorOccupee.setGreenF(1.0);
    m_colorOccupee.setAlphaF(0.3);

    m_colorOccupeeConso.setRgb(41, 167, 74);

    m_colorReservee.setBlueF(1.0);
    m_colorReservee.setAlphaF(0.3);

    m_colorReserveeConso = m_colorReservee;
    m_colorReserveeConso.setAlphaF(0.7);
}

void PiloteDePlanning::showHeaderHorizontal()
{
    if(estPlanningMixte())
        emit typeOperation("Initialisation des jours...");
    else
        if(estPlanningOccup())
            emit typeOperation("Initialisation des jours (location)...");
        else
            emit typeOperation("Initialisation des jours (réservation)...");

    int nbDaysTotal = m_date_debut.daysTo(m_date_fin);

    emit dataATraiter(nbDaysTotal + 1);
    if(m_date_debut.month() == m_date_fin.month())
    {
        for(int i = 0; i <= nbDaysTotal; i++)
        {
            QDate date = m_date_debut.addDays(i);
            QString jour = QObject::tr("%1 %2")
                           .arg(jourLongName(date.dayOfWeek()))
                           .arg(date.day());

            m_tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(jour));
            emit opElt();
        }
    }else
    {
        for(int i = 0; i <= nbDaysTotal; i++)
        {
            QDate date = m_date_debut.addDays(i);
            QString jour = QObject::tr("%1 %2 %3")
                           .arg(jourLongName(date.dayOfWeek()))
                           .arg(date.day())
                           .arg(moisShortName(date.month()));

            m_tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(jour));
            emit opElt();
        }
    }
}

void PiloteDePlanning::dimensionnerHeaderHorizontal()
{
    int nbDaysTotal = m_date_debut.daysTo(m_date_fin);

    m_tableWidget->setColumnCount(0);
    m_tableWidget->setColumnCount(nbDaysTotal + 1);
}

void PiloteDePlanning::showHeaderVertical()
{
    if(estPlanningMixte())
        emit typeOperation("Initialisation des chambres...");
    else
        if(estPlanningOccup())
            emit typeOperation("Initialisation des chambres (location)...");
        else
            emit typeOperation("Initialisation des chambres (réservation)...");


    m_tableWidget->setRowCount(0); // initialiser la verticale

    int countInitial = IDVIDE + 1;
    m_tableWidget->setRowCount(countInitial); // un rang vide
    m_tableWidget->setVerticalHeaderItem(IDDISPONIBLE, new QTableWidgetItem(DISPONIBLE));
    m_tableWidget->setVerticalHeaderItem(IDOCCUPEE, new QTableWidgetItem(OCCUPEE));
    m_tableWidget->setVerticalHeaderItem(IDRESERVEE, new QTableWidgetItem(RESERVEE));
    m_tableWidget->setVerticalHeaderItem(IDVIDE, new QTableWidgetItem(QString()));

    emit dataATraiter(m_chambres_str.count());
    QStringList niveaux = etage::niveaux();
    for(int i = countInitial; i < m_chambres_str.count() + countInitial; i++)
    {
        int j = i - countInitial;
        chambre ch(m_chambres_str.at(j));
        QString libelle = tr("%1 (%2)").arg(ch.identifiant()).arg(niveaux.at(ch.idEtage() - 1));
        QTableWidgetItem * item = new QTableWidgetItem(libelle);
        item->setToolTip(typeDeChambre(m_chambres.at(j)->idTypeChambre()).type());
        item->setTextAlignment(Qt::AlignJustify);
        m_tableWidget->setRowCount(i + 1);
        m_tableWidget->setVerticalHeaderItem(i, item);
        emit opElt();
    }
}

void PiloteDePlanning::showDisponibilite(QDate date, int nb)
{
    if(dayIsIn(date))
    {
        int column = m_date_debut.daysTo(date);
        showCell(IDDISPONIBLE, column, nb);
    }
}

void PiloteDePlanning::showNbOccupee(QDate date, int nb)
{
    if(dayIsIn(date))
    {
        int column = m_date_debut.daysTo(date);
        showCell(IDOCCUPEE, column, nb);
    }
}

void PiloteDePlanning::showNbReservee(QDate date, int nb)
{
    if(dayIsIn(date))
    {
        int column = m_date_debut.daysTo(date);
        showCell(IDRESERVEE, column, nb);
    }
}

bool PiloteDePlanning::dayIsIn(QDate date)
{
    return (date >= m_date_debut && date <= m_date_fin);
}

void PiloteDePlanning::showCell(int row, int column, int value)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    item->setText(QString::number(value));

    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::showCell(int row, int column, QString value, QStringList data, QColor color, QIcon icon)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    item->setText(value.toUpper());
    item->setData(Qt::UserRole, data);
    item->setIcon(icon);
    item->setBackgroundColor(color);

    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::showCell(int row, int column, QTableWidgetItem * item)
{
    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::setColorAction(QColor color)
{
    m_colorAction = color;

    // rafraichir planning
}

void PiloteDePlanning::setColorDisponible(QColor color)
{
    m_colorDisponible = color;

    // rafraichir planning
}

void PiloteDePlanning::setColorOccupee(QColor color)
{
    m_colorOccupee = color;

    // rafraichir planning
}

void PiloteDePlanning::setColorOccupeeConso(QColor color)
{
    m_colorOccupeeConso= color;

    // rafraichir planning
}

void PiloteDePlanning::setColorReservee(QColor color)
{
    m_colorReservee = color;

    // rafraichir planning
}

void PiloteDePlanning::setColorReserveeConso(QColor color)
{
    m_colorReserveeConso = color;

    // rafraichir planning
}

void PiloteDePlanning::checkIn()
{
    checkIn(m_tableWidget->currentRow(), m_tableWidget->currentColumn());
}

void PiloteDePlanning::checkIn(int row1, int column)
{
    m_itemsADeplacer.clear();

    int col1 = column;
    int row = row1;

    if(estReservee(row, col1) && estPlanningMixte())
    {
        // on exécute une réservation
        int colFin = colSortie(row, col1);

        int id = data(row, col1, IdTypeReservation).toInt();
        if(id <= 0)
        {
            // réservation pas enregistrée
            QMessageBox::information(m_parent, "Exécution d'une réservation", "Vous devez d'abord enregistrer la réservation, puis l'exécuter.");
            return;
        }

        QDateTime now = Horloge::currentDateTime();
        reservation rv(id);
        client cl(rv.codeClient());
        chambre ch(chambreDe(row));

        occupation oc;
        oc.setCodeClient(cl.codeDuClient());
        oc.setDatedEntree(now);
        oc.setDureeOccupation(colFin - col1 + 1);

        MesTables::effectuerReservation(rv, *m_agent, now, oc, ch.identifiant());

        int prixUnitaire = rv.cout() / rv.dureeOccupation();
        oc.setCout(prixUnitaire * oc.dureeOccupation());

        MesTables::enregistrerOccupation(cl, oc, *m_agent);

        showOccupation(oc);

        afficherInfosGenerales(col1, colFin);
    }else
    {
        // on fait un check-in seul
        QDateTime now = Horloge::currentDateTime();
        if((m_date_debut.addDays(col1) == now.date() && estPlanningMixte())
            || estPlanningOccup())
        {
            // une location en cours
            m_colorOfCheckIn = m_colorOccupee;
            initItemDebutOccup(row, col1);
        }else
        {
                // c'est une réservation
                m_colorOfCheckIn = m_colorReservee;
                initItemDebutReserv(row, col1);
        }

        // pour le moment, ce check est aussi un check-out
        setData(row, col1, ColSortie, col1);

        m_colOfCheckIn = col1;
        m_rowOfCheckIn = row;

        m_nouveauxChecksIn << QPoint(col1, row);
        emit planningModifie(true);
    }

    // alimenter la base de donnees
}

void PiloteDePlanning::checkIn(int row1, int column, bool occuper)
{
    m_itemsADeplacer.clear();

    int col1 = column;
    int row = row1;
    QStringList data = m_tableWidget->item(row, col1)->data(Qt::UserRole).toStringList();

    bool estReservee = data.at(Reservee_r).toInt();
    if(estReservee)
    {
        // on exécute une réservation
        int colFin = data.at(ColSortie).toInt();

        showEspaceReserve(row
                          , col1
                          , colFin);
    }else
    {
        QDate date = m_date_debut.addDays(col1);

        // on fait un check-in seul
        QDate now = Horloge::currentDate();
        if(date == now)
        {
            // une location en cours
            m_colorOfCheckIn = m_colorOccupee;
        }else
        {
            if(date > now)
            {
                // c'est une réservation
                m_colorOfCheckIn = m_colorReservee;

            }else
            {
                // nous sommes dans le passé
                if(occuper)
                {
                    // une location passée
                    m_colorOfCheckIn = m_colorOccupee;
                }else
                {
                    // c'est une réservation passée
                    m_colorOfCheckIn = m_colorReservee;
                }
            }
        }

        initItemDebutOccup(row, col1);

        m_colOfCheckIn = col1;
        m_rowOfCheckIn = row;
    }

    // alimenter la base de donnees
}

void PiloteDePlanning::reserver()
{
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    QTableWidgetSelectionRange range = m_tableWidget->selectedRanges().first();

    int colDebut = range.leftColumn();
    int colFin = colDebut + range.columnCount() - 1;

    for(int i = 0; i < range.rowCount(); i++)
    {
        int row = range.topRow() + i;

        initItemDebutReserv(row, colDebut);
        initItemFinReserv(row, colFin);

        setData(row, colFin, ColEntree, colDebut);
        setData(row, colDebut, ColSortie, colFin);

        showEspaceReserve( row
                          , colDebut
                          , colFin);

        m_nouveauxChecksIn << QPoint(colDebut, row);
        emit planningModifie(true);
    }

    // alimenter la base de donnees
}

void PiloteDePlanning::occuper()
{
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    QTableWidgetSelectionRange range = m_tableWidget->selectedRanges().first();

    int colDebut = range.leftColumn();
    int colFin = colDebut + range.columnCount() - 1;

    for(int i = 0; i < range.rowCount(); i++)
    {
        int row = range.topRow() + i;

        initItemDebutOccup(row, colDebut);
        initItemFinOccup(row, colFin);

        setData(row, colFin, ColEntree, colDebut);
        setData(row, colDebut, ColSortie, colFin);

        showEspaceReserve( row
                          , colDebut
                          , colFin);

        m_nouveauxChecksIn << QPoint(colDebut, row);
        emit planningModifie(true);
    }

    // alimenter la base de donnees
}

void PiloteDePlanning::facturerSelection()
{
    // la sélection est enregistrée
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    int row = m_tableWidget->currentRow();
    int col = m_tableWidget->currentColumn();

    bool estUnGroupe = (bool)data(row, col, Groupe_r).toInt();

    BDFacturerClient bd(m_db
                        ,*m_agent
                        , data(row, col, IdClient).toInt()
                        , data(row, col, IdTypeReservation).toInt()
                        , estOccupee(row, col)
                        , estUnGroupe
                        , m_parent);

    bd.setWindowTitle(tr("Facturer le client de la chambre %1").arg(chambreDe(m_tableWidget->currentRow())));

    if(bd.exec() == QDialog::Accepted)
    {
        int colDeb = colEntree(row, col);
        int colFin = colSortie(row, col);

        setData(row, colDeb, TotalAPayer, bd.coutTotalLocation());
        setData(row, colFin, TotalAPayer, bd.coutTotalLocation());

        setData(row, colDeb, ResteAPayer, bd.resteLocation());
        setData(row, colFin, ResteAPayer, bd.resteLocation());

        showEspaceReserve(row, colDeb, colFin, false);
    }

    // alimenter la base de donnees
}

void PiloteDePlanning::identifierClient()
{
    // on suppose que l'occupation et la réservation n'est pas encore enregistrée

    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    int row = m_tableWidget->currentRow();
    int col = m_tableWidget->currentColumn();

    if(estOccupee(row, col))
    {
        // occupation
        occupation oc;
        BDIdentifierClientOcc * bd = new BDIdentifierClientOcc(oc, m_parent);
        bd->setWindowTitle(tr("Identifier le client"));

        if(bd->exec() == QDialog::Accepted)
        {
            client cl = bd->clientSelectionne(); // aucune modification sur le client
            oc = bd->occupationDuClient();

            pieceIdentiteClient pic = bd->pieceIdentite();
            pic.enregistrer(); // sans enregistrer l'occupation

            // réafficher l'espace réservé
            int colDebut = colEntree(row, col);
            int colFin = colSortie(row, col);

            setData(row, colDebut, IdClient, cl.codeDuClient());
            setData(row, colDebut, Nom, cl.nom());
            showValue(row, colDebut, cl.nom().toUpper());

            setData(row, colFin, IdClient, cl.codeDuClient());
            setData(row, colFin, Nom, cl.nom());

            chambre ch(chambreDe(row));
            int prixTotal = prixChambreTTC(ch.idTypeChambre(), oc.idProfileClient()).prixTTC() * (colFin - colDebut + 1);

            setData(row, colDebut, TotalAPayer, QString::number(prixTotal));
            setData(row, colFin, TotalAPayer, QString::number(prixTotal));

            setData(row, colDebut, ResteAPayer, QString::number(prixTotal));
            setData(row, colFin, ResteAPayer, QString::number(prixTotal));

            setData(row, colDebut, NomComplet, cl.nomComplet());
            setData(row, colFin, NomComplet, cl.nomComplet());

            setData(row, colDebut, Nom, cl.nom());
            setData(row, colFin, Nom, cl.nom());

            setData(row, colDebut, IdPieceIdentite, pic.idPieceIdentite());
            setData(row, colFin, IdPieceIdentite, pic.idPieceIdentite());

            setData(row, colDebut, IdProfileClient, oc.idProfileClient());
            setData(row, colFin, IdProfileClient, oc.idProfileClient());

            setData(row, colDebut, NbEnfAccMoinsDe15, oc.enfAccMoinsDe15());
            setData(row, colFin, NbEnfAccMoinsDe15, oc.enfAccMoinsDe15());

            setData(row, colDebut, DestinationExacte, oc.destinationExacte());
            setData(row, colFin, DestinationExacte, oc.destinationExacte());

            showEspaceReserve(row, colDebut, colFin);
        }

        delete bd;
    }else
    {
        // réservation
        reservation rv;
        client cl;
        cl.setHomme(true);
        BDIdentifierClientHotel * bd = new BDIdentifierClientHotel(m_parent);
        bd->setWindowTitle(tr("Identifier le client"));

        if(bd->exec() == QDialog::Accepted)
        {
            client cl = bd->clientSelectionne(); // aucune modification sur le client
            rv.setIdProfileClient(bd->idProfileClient());

            // réafficher l'espace réservé
            int colDebut = colEntree(row, col);
            int colFin = colSortie(row, col);

            setData(row, colDebut, IdClient, cl.codeDuClient());
            setData(row, colDebut, Nom, cl.nom());
            showValue(row, colDebut, cl.nom().toUpper());

            setData(row, colFin, IdClient, cl.codeDuClient());
            setData(row, colFin, Nom, cl.nom());

            chambre ch(chambreDe(row));
            int prixTotal = prixChambreTTC(ch.idTypeChambre(), rv.idProfileClient()).prixTTC() * (colFin - colDebut + 1);

            setData(row, colDebut, TotalAPayer, QString::number(prixTotal));
            setData(row, colFin, TotalAPayer, QString::number(prixTotal));

            setData(row, colDebut, ResteAPayer, QString::number(prixTotal));
            setData(row, colFin, ResteAPayer, QString::number(prixTotal));

            setData(row, colDebut, NomComplet, cl.nomComplet());
            setData(row, colFin, NomComplet, cl.nomComplet());

            setData(row, colDebut, Nom, cl.nom());
            setData(row, colFin, Nom, cl.nom());

            setData(row, colDebut, IdProfileClient, rv.idProfileClient());
            setData(row, colFin, IdProfileClient, rv.idProfileClient());

            showEspaceReserve(row, colDebut, colFin);
        }

        delete bd;
    }

    // alimenter la base de donnees
}

void PiloteDePlanning::voirDetailsSurClient()
{
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    int row = m_tableWidget->currentRow();
    int col = m_tableWidget->currentColumn();

    int idClient = data(row, col, IdClient).toInt();
    client cl(idClient);

    int id = data(row, col, IdTypeReservation).toInt();
    if(estOccupee(row, col))
    {
        pieceIdentiteClient pic = pieceIdentiteClient::selectionnerPieceDuClient(id);

        occupation oc(id);
        BDFormulaireClient * bd;
        if(oc.terminee())
            bd = new BDFormulaireClient(cl, pic, true, oc, m_parent);
        else
            bd = new BDFormulaireClient(cl, pic, false, oc, m_parent);

        bd->setWindowTitle(tr("Détails sur le client"));

        if(bd->exec() == QDialog::Accepted)
        {
            showOccupation(bd->occup());
        }

        delete bd;
    }else
    {
        int idProfileClient = data(row, col, IdProfileClient).toInt();

        BDFormulaireClientHotelSimple * bd = new BDFormulaireClientHotelSimple(cl, idProfileClient, true, m_parent);
        bd->setWindowTitle(tr("Détails sur le client"));
        bd->exec();

        delete bd;
    }

    // alimenter la base de donnees
}

void PiloteDePlanning::checkOut()
{
    checkOut(m_tableWidget->currentRow(), m_tableWidget->currentColumn());
}

void PiloteDePlanning::checkOut(int row1, int column)
{
    if(m_rowOfCheckIn == -1)
        return;

    m_itemsADeplacer.clear();

    // c'est qu'il y a un check-in déjà

    if(estReservee(row1, m_colOfCheckIn))
    {
        initItemFinReserv(row1, column - 1);
    }else
    {
        initItemFinOccup(row1, column - 1);
    }

    showEspaceReserve( row1
                      , m_colOfCheckIn
                      , column - 1);

    m_rowOfCheckIn = -1;

    // alimenter la base de donnees
}

void PiloteDePlanning::annulerReservation()
{
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    QDateTime now = Horloge::currentDateTime();
    int col = m_tableWidget->currentColumn();
    int row = m_tableWidget->currentRow();
    int colDeb = colEntree(row, col);
    int colFin = colSortie(row, col);

    int id = data(row, col, IdTypeReservation).toInt();
    chambre ch(chambreDe(row));
    if(estOccupee(row, col))
    {
        occupation oc(id);
        if(oc.existe())
        {
            clearOccupation(oc);
            if(col == colDeb)
            {
                // annuler toute l'occupation
                MesTables::annulerOccupation(ch, *m_agent, now);
            }else
            {
                // annuler une partie de l'occupation
                oc.setDureeOccupation((col - 1) - colDeb + 1);

                // actualiser le prix total
                int prixUnitaire = 0;
                prixUnitaire = prixChambreTTC(chambre(chambreDe(row)).idTypeChambre(), data(row, colDeb, IdProfileClient).toInt()).prixTTC();
                int prix = prixUnitaire * oc.dureeOccupation();
                oc.setCout(prix);
                oc.enregistrer();

                showOccupation(oc);
            }
        }else
        {
            // nouvelle occupation
            clearEspace(row, col, colFin);

            QPoint pt(colDeb, row);
            m_nouveauxChecksIn.removeOne(pt);
        }        
    }else
    {
        reservation rv(id);
        if(rv.existe())
        {
            clearReservation(rv);
            if(col == colDeb)
            {
                // annuler toute la réservation
                MesTables::annulerReservation(rv, *m_agent, now, chambreDe(row));
            }else
            {
                // annuler une partie de la réservation
                rv.setDureeOccupation((col - 1) - colDeb + 1);

                // actualiser le prix total
                int prixUnitaire = 0;
                prixUnitaire = prixChambreTTC(chambre(chambreDe(row)).idTypeChambre(), data(row, colDeb, IdProfileClient).toInt()).prixTTC();
                int prix = prixUnitaire * rv.dureeOccupation();
                rv.setCout(prix);
                rv.enregistrer();

                showReservation(rv);
            }
        }else
        {
            // nouvelle réservation
            clearEspace(row, col, colFin);

            QPoint pt(colDeb, row);
            m_nouveauxChecksIn.removeOne(pt);
        }
    }

    // spécifie col de fin
    setData(row, colDeb, ColSortie, col - 1);
    setData(row, col, ColSortie, col - 1);

    showEspaceReserve(row, colDeb, col - 1);

    // alimenter la base de donnees
}

void PiloteDePlanning::debuterDeplacementDeSelection()
{
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    m_itemsADeplacer << m_tableWidget->selectedItems();
}

void PiloteDePlanning::terminerDeplacementDeSelection()
{
    if(m_itemsADeplacer.isEmpty())
        return;

    m_rowOfCheckIn = -1;

    int row = m_tableWidget->currentRow();
    int col = m_tableWidget->currentColumn();

    int colDebutAD = m_itemsADeplacer.first()->column();
    int rowAD = m_itemsADeplacer.first()->row();

    int colFin = colSortie(rowAD, colDebutAD);
    int colDebut = colEntree(rowAD, colDebutAD);
    int colFinPresume = col + (colFin - colDebutAD);

    int id = data(rowAD, colDebutAD, IdTypeReservation).toInt();

    int reste = 0;
    int prixUnitaire = 0;
    if(estOccupee(rowAD, colDebutAD))
    {
        occupation oc(id);
        if(colDebut == colDebutAD)
        {
            // on déloge toute la location. ce qui revient à changer de chambre
            chambre ch(chambreDe(rowAD));
            ch.setOccupee(false);
            ch.enregistrer();

            chambre ch1(chambreDe(row));
            ch1.setOccupee(true);
            ch1.enregistrer();

            oc.setChambreOccupee(ch1.identifiant());
            oc.enregistrer();
        }else
        {
            // on déloge une partie de la location. réduction de la durée et du cout
            prixUnitaire = oc.cout() / oc.dureeOccupation();
            oc.setDureeOccupation(colDebutAD - colDebut);
            oc.setCout(prixUnitaire * oc.dureeOccupation());

            if(oc.cout() < oc.payee())
            {
                reste = oc.payee() - oc.cout();
                oc.setPayee(oc.cout());
            }

            oc.enregistrer();
        }

        initItemDebutOccup(row, col);
        initItemFinOccup(row, colFinPresume);
    }else
    {
        reservation rv(id);
        if(colDebut == colDebutAD)
        {
            // on déloge toute la réservation.
            chambre ch1(chambreDe(row));

            // changement de chambre
            chambreReservee chr(rv.numReservation());
            chr.setIdentiteCh(ch1.identifiant());
            chr.enregistrer();

            // changement de date
            rv.setDatedEntree(QDateTime(date(col), rv.datedEntree().time()));
            rv.enregistrer();
        }else
        {
            // on déloge une partie de la réservation. réduction de la durée et du cout
            prixUnitaire = rv.cout() / rv.dureeOccupation();
            rv.setDureeOccupation(colDebutAD - colDebut);
            rv.setCout(prixUnitaire * rv.dureeOccupation());

            chambreReservee chr(rv.numReservation());
            chr.setCout(rv.cout());

            if(rv.cout() < rv.avance())
            {
                reste = rv.avance() - rv.cout();
                rv.setAvance(rv.cout());
                chr.setAvance(rv.cout());
            }

            rv.enregistrer();
            chr.enregistrer();
        }

        initItemDebutReserv(row, col);
        initItemFinReserv(row, colFinPresume);
    }

    int cout = prixUnitaire * (colFinPresume - col + 1);

    if(col != colDebut)
    {
        int coutVrai = data(rowAD, colDebutAD, TotalAPayer).toInt();
        int pu = coutVrai / (colFin - colDebut + 1);
        int cout1 = pu * (colDebutAD - colDebut);


        setData(rowAD, colDebut, TotalAPayer, cout1);
        setData(rowAD, colDebutAD - 1, TotalAPayer, cout1);

        int reste1 = data(rowAD, colDebut, ResteAPayer).toInt();
        int somme_payee = coutVrai - reste1;

        if(somme_payee > cout1)
        {
            somme_payee = cout1;
            reste1 = 0;
        }else
        {
            reste1 = cout1 - somme_payee;
        }

        setData(rowAD, colDebut, ResteAPayer, reste1);
        setData(rowAD, colDebutAD - 1, ResteAPayer, reste1);

        // recharger
        showEspaceReserve(rowAD, colDebut, colDebutAD - 1);
    }

    setData(row, col, data(rowAD, colDebutAD));
    setData(row, colFinPresume, data(rowAD, colDebutAD));

    setData(row, col, TotalAPayer, cout);
    setData(row, colFinPresume, TotalAPayer, cout);

    setData(row, col, ResteAPayer, cout - reste);
    setData(row, colFinPresume, ResteAPayer, cout - reste);

    setData(row, col, Entree, 1);
    setData(row, colFinPresume, Sortie, 1);

    setData(row, col, IdTypeReservation, 0); // réservation n'existe pas encore
    setData(row, colFinPresume, IdTypeReservation, 0);

    showValue(row, col, data(row, col, Nom).toUpper());

    showEspaceReserve(row, col, colFinPresume);

    m_nouveauxChecksIn << QPoint(col, row);
    emit planningModifie(true);

    // rendre les cellules sources disponibles
    initItemDispo(rowAD, colDebutAD);
    initItemDispo(rowAD, colFin);

    showEspaceReserve(rowAD, colDebutAD, colFin);
    emit rendreChambresDispo(date(colDebutAD), date(colFin), chambreDe(rowAD));

    m_itemsADeplacer.clear();

    // alimenter la base de données
}

void PiloteDePlanning::preparerActions()
{

}

void PiloteDePlanning::initialiserCellules()
{
    if(estPlanningMixte())
        emit typeOperation("Initialisation des espaces...");
    else
        if(estPlanningOccup())
            emit typeOperation("Initialisation des espaces (location)...");
        else
            emit typeOperation("Initialisation des espaces (réservation)...");

    int columns = m_tableWidget->columnCount();
    int rows = m_tableWidget->rowCount();

    emit dataATraiter(rows);
    // initialiser les cellules d'entête du planning
    for(int row = 0; row <= IDVIDE; row++)
    {
        for(int col = 0; col < columns; col++)
        {
            initCelluleEntete(row, col);
        }

        emit opElt();
    }

    // initialiser les cellules des chambres
    for(int row = IDVIDE + 1; row < rows; row++)
    {
        for(int col = 0; col < columns; col++)
        {
            initCelluleCh(row, col);
        }

        emit opElt();
    }
}

void PiloteDePlanning::initialiserCellules(int colDeb, int colFin)
{
    int rows = m_tableWidget->rowCount();

    // initialiser les cellules d'entête du planning
    for(int row = 0; row <= IDVIDE; row++)
    {
        for(int col = colDeb; col <= colFin; col++)
        {
            initCelluleEntete(row, col);
        }
    }

    // initialiser les cellules des chambres
    for(int row = IDVIDE + 1; row < rows; row++)
    {
        for(int col = colDeb; col <= colFin; col++)
        {
            initCelluleCh(row, col);
        }
    }
}

QColor PiloteDePlanning::colorOfEtat(Etat etat) const
{
    // colorer
    QColor color;
    switch(etat)
    {
        case Occupee:
            color = m_colorOccupee;
            break;
        case OccupeeConso:
            color = m_colorOccupeeConso;
            break;
        case Reservee:
            color = m_colorReservee;
            break;
        case ReserveeConso:
            color = m_colorReserveeConso;
            break;
        case Action:
            color = m_colorAction;
            break;
        default:
            // disponible
            color = m_colorDisponible;
    }

    return color;
}

PiloteDePlanning::Etat PiloteDePlanning::etatOfColor(const QColor &color)
{
    if(color == m_colorOccupee)
        return Occupee;

    if(color == m_colorOccupeeConso)
        return OccupeeConso;

    if(color == m_colorReservee)
        return Reservee;

    if(color == m_colorReserveeConso)
        return ReserveeConso;

    if(color == m_colorAction)
        return Action;

    return Disponible;
}

bool PiloteDePlanning::itemIsTheFirst(const QTableWidgetItem *item)
{
    bool caseEstPremiere  = true;
    if(item->column() != 0
       && m_tableWidget->item(item->row(), item->column() - 1)->backgroundColor() == item->backgroundColor())
    {
        caseEstPremiere = false;
    }

    return caseEstPremiere;
}

void PiloteDePlanning::debuterNettoyageDeSelection()
{
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    // alimenter la base de donnees
}

void PiloteDePlanning::terminerNettoyageDeSelection()
{
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;


    // alimenter la base de donnees
}

void PiloteDePlanning::selectionANettoyer()
{
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;


    // alimenter la base de donnees
}

void PiloteDePlanning::rafraichirPlanning()
{
    showOccupations();
    showReservations();

    afficherInfosGenerales();
}

void PiloteDePlanning::rafraichirPlanningOccup()
{
    showOccupations();
    afficherInfosGenerales();
}

void PiloteDePlanning::rafraichirPlanningReserv()
{
    showAllReservations();
    afficherInfosGenerales();
}

void PiloteDePlanning::rafraichirPlanning(int colDebut, int colFin)
{
    initialiserCellules(colDebut, colFin);
    showOccupations(colDebut, colFin); // pour le moment, affiche uniquement les lots complets
    showReservations(colDebut, colFin);

    afficherInfosGenerales(colDebut, colFin);
}

void PiloteDePlanning::rafraichirPlanningOccup(int colDebut, int colFin)
{
    initialiserCellules(colDebut, colFin);
    showOccupations(colDebut, colFin); // pour le moment, affiche uniquement les lots complets

    afficherInfosGenerales(colDebut, colFin);
}

void PiloteDePlanning::rafraichirPlanningReserv(int colDebut, int colFin)
{
    initialiserCellules(colDebut, colFin);
    // pour le moment, affiche uniquement les lots complets
    showAllReservations(colDebut, colFin);

    afficherInfosGenerales(colDebut, colFin);
}

void PiloteDePlanning::construirePlanning()
{
    // construction intelligente
    // on suppose qu'on ne créé ou ne met pas de chambres hors service durant le service des réceptionnistes
    if(m_tableWidget->rowCount() == 0)
        showHeaderVertical(); // c'est maintenant qu'on le créé

    dimensionnerHeaderHorizontal(); // c'est maintenant qu'on le créé

//    if(m_tableWidget->columnCount() == 0)
//    {
//        dimensionnerHeaderHorizontal(); // c'est maintenant qu'on le créé
//        m_planningRecree = true;
//    }else
//    {
//        if(m_date_debut_precedent.year() != m_date_debut.year()
//            || m_date_debut_precedent > m_date_fin || m_date_fin_precedent < m_date_debut)
//        {
//            dimensionnerHeaderHorizontal(); // l'année a changé. donc on recréé
//            m_planningRecree = true;
//        }else
//        {
//            m_planningRecree = false;
//            if(m_date_debut_precedent < m_date_debut || m_date_fin_precedent > m_date_fin)
//            {
//                m_moisAjoute = false;
//                if(m_date_debut_precedent < m_date_debut)
//                {
//                    // on s'est avancé d'au moins un mois. donc on tronque le planning à gauche
//                    int nbCol = m_date_debut_precedent.daysTo(m_date_debut);
//
//                    for(int i = 1; i <= nbCol; i++)
//                    {
//                        m_tableWidget->removeColumn(0);
//                    }
//                }else
//                {
//                    // on a reculé d'au moins un mois. donc on tronque le planning à droite
//                    int nbCol = m_date_fin.daysTo(m_date_fin_precedent);
//
//                    for(int i = 1; i <= nbCol; i++)
//                    {
//                        m_tableWidget->removeColumn(m_tableWidget->columnCount() - 1);
//                    }
//                }
//            }else
//            {
//                m_moisAjoute = true;
//                if(m_date_debut_precedent > m_date_debut || m_date_fin_precedent < m_date_fin)
//                {
//                    if(m_date_debut_precedent > m_date_debut)
//                    {
//                        // on a reculé d'au moins un mois. donc on insère à gauche la période ajoutée
//                        int nbCol = m_date_debut.daysTo(m_date_debut_precedent);
//                        m_colDebMoisAjoute = 0;
//                        m_colFinMoisAjoute = nbCol;
//
//                        for(int i = 1; i <= nbCol; i++)
//                        {
//                            m_tableWidget->insertColumn(0);
//                        }
//                    }else
//                    {
//                        // on a avancé d'au moins un mois. donc on insère à droite la période ajoutée
//                        int nbCol = m_date_fin_precedent.daysTo(m_date_fin);
//                        m_colDebMoisAjoute = column(m_date_fin_precedent) + 1;
//
//                        for(int i = 1; i <= nbCol; i++)
//                        {
//                            m_tableWidget->insertColumn(m_tableWidget->columnCount());
//                        }
//
//                        m_colFinMoisAjoute = m_tableWidget->columnCount() - 1;
//                    }
//                }
//            }
//        }
//    }

    // nommer les colonnes
    showHeaderHorizontal();
}

void PiloteDePlanning::arreterLocation()
{    
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    int row = m_tableWidget->currentRow();
    int col = m_tableWidget->currentColumn();

    QDateTime now = Horloge::currentDateTime();
    int idOccupation = data(row, col, IdTypeReservation).toInt();

    occupation oc(idOccupation);

    chambre ch(chambreDe(row));

    if(QMessageBox::information(m_parent
                                , "Arrêter une location"
                                , "Désirez-vous arrêter la location en cours ?", "Oui", "Non") == 1)
        return;

    if(MesTables::arreterOccupation(ch, *m_agent, now))     // modifications dans la base de données
    {
        // modifications des champs hors zone de location sur le planning
        if(oc.datedSortie().date() <= now.date())
        {
            // sorti comme prévu. Il y 'a donc une croix à supprimer sur la case d'aujourd'hui.
            initItemDispo(row, column(now.date()));
            emit rendreChambresDispo(now.date(), now.date(), chambreDe(row));
        }else
        {
            // on sort avant la date prévue. on rend disponible toutes les nuits non conso
            if(oc.datedSortie().date() > now.date())
            {
                int colFin = colSortie(row, col);
                int colSuivant = column(now.date());

                for(int i = colSuivant; i <= colFin; i++)
                {
                    initItemDispo(row, i);
                }

                emit rendreChambresDispo(date(colSuivant), date(colFin), chambreDe(row));
            }
        }

        // on recharge l'occupation
        oc.actualiser();
        showOccupation(oc);
    }
}

QString PiloteDePlanning::moisLongName(int month)
{
    QStringList tous_les_mois = tousLesMoisLongName();

    if(month < 1 || month > tous_les_mois.count())
        return QString();

    return tous_les_mois.at(month - 1);
}

QString PiloteDePlanning::moisShortName(int month)
{
    QStringList tous_les_mois = tousLesMoisShortName();

    if(month < 1 || month > tous_les_mois.count())
        return QString();

    return tous_les_mois.at(month - 1);
}

int PiloteDePlanning::moisFromLongName(QString name)
{
    if(tousLesMoisLongName().contains(name))
        return tousLesMoisLongName().indexOf(name) + 1;

    return -1;
}

int PiloteDePlanning::moisFromShortName(QString name)
{
    if(tousLesMoisShortName().contains(name))
        return tousLesMoisShortName().indexOf(name) + 1;

    return -1;
}

QStringList PiloteDePlanning::tousLesMoisLongName()
{
    QStringList tous_les_mois;
    tous_les_mois   << "Janvier"
                    << "Février"
                    << "Mars"
                    << "Avril"
                    << "Mai"
                    << "Juin"
                    << "Juillet"
                    << "Août"
                    << "Septembre"
                    << "Octobre"
                    << "Novembre"
                    << "Décembre";

    return tous_les_mois;
}

QStringList PiloteDePlanning::tousLesMoisShortName()
{
    QStringList tous_les_mois_short;
    tous_les_mois_short     << "Jan"
                            << "Fév"
                            << "Mars"
                            << "Avr"
                            << "Mai"
                            << "Juin"
                            << "Juil"
                            << "Août"
                            << "Sept"
                            << "Oct"
                            << "Nov"
                            << "Déc";

    return tous_les_mois_short;
}

QStringList PiloteDePlanning::tousLesJoursLongName()
{
    QStringList m_tous_les_jours;
    m_tous_les_jours << "Lundi"
                     << "Mardi"
                     << "Mercredi"
                     << "Jeudi"
                     << "Vendredi"
                     << "Samedi"
                     << "Dimanche";

    return m_tous_les_jours;
}

QString PiloteDePlanning::jourLongName(int jour)
{
    QStringList tous_les_jours = tousLesJoursLongName();

    if(jour < 1 || jour > tous_les_jours.count())
        return QString();

    return tous_les_jours.at(jour - 1);
}

int PiloteDePlanning::jourFromLongName(QString name)
{
    if(tousLesJoursLongName().contains(name))
        return tousLesJoursLongName().indexOf(name) + 1;

    return -1;
}

void PiloteDePlanning::setDebutMois(QString longName)
{
    int month = moisFromLongName(longName);
    if(month < 1 && month > 12)
        return;

    m_date_debut_precedent = m_date_debut; // sauvegarder
    m_date_debut.setYMD(m_date_debut.year()
                        , month
                        , 1);

}

void PiloteDePlanning::setFinMois(QString longName)
{
    int month = moisFromLongName(longName);
    if(month < 1 && month > 12)
        return;

    m_date_fin_precedent = m_date_fin; // sauvegarder
    m_date_fin.setYMD( m_date_fin.year()
                        , month
                        , QDate(m_date_fin.year(), month, 1).daysInMonth());

}

void PiloteDePlanning::setJourDebut(QDate date)
{
    m_date_debut_precedent = m_date_debut;
    m_date_debut = date;
}

void PiloteDePlanning::setJourFin(QDate date)
{
    m_date_fin_precedent = m_date_fin;
    m_date_fin = date;
}

void PiloteDePlanning::setAnnee(int annee)
{
    if((annee <= 0)
      || (annee == m_date_debut.year())) // année non valide ou même année

        return;

    m_date_debut.setYMD( annee
                        , m_date_debut.month()
                        , 1);

    m_date_fin.setYMD( annee
                        , m_date_fin.month()
                        , QDate(annee, m_date_fin.month(), 1).daysInMonth());
}

void PiloteDePlanning::setAnnee(QString annee)
{
    setAnnee(annee.toInt());
}

QString PiloteDePlanning::moisDebutLongName()const
{
    return moisLongName(m_date_debut.month());
}

QString PiloteDePlanning::moisFinLongName()const
{
    return moisLongName(m_date_fin.month());
}

int PiloteDePlanning::annee()const
{
    return m_date_debut.year();
}

void PiloteDePlanning::show()
{
    m_tableWidget->setEnabled(false);

    if(m_typePlanning == PlanningMixte)
    {
        adapterLimitesDuPlanning();

        construirePlanning();

        if(m_planningRecree)
            rafraichirPlanning();
        else
            if(m_moisAjoute)
            {
                rafraichirPlanning(m_colDebMoisAjoute, m_colFinMoisAjoute);
            }
    }else
    {
        if(m_typePlanning == PlanningDOccupation)
            showOccupationsComplet();
        else
            showReservationsComplet();
    }

    m_tableWidget->setEnabled(true);
}

void PiloteDePlanning::showOccupationsComplet()
{
    adapterLimitesDuPlanningOccup();
    construirePlanning();
    initialiserCellules();
    rafraichirPlanningOccup();

//    adapterLimitesDuPlanningOccup();
//
//    construirePlanning();
//
//    if(m_planningRecree)
//        rafraichirPlanningOccup();
//    else
//        if(m_moisAjoute)
//        {
//            rafraichirPlanningOccup(m_colDebMoisAjoute, m_colFinMoisAjoute);
//        }
}

void PiloteDePlanning::showSigneReservations()
{
    QDate now = Horloge::currentDate();

    QDate debut;
    QDate fin;

    if(dayIsIn(now))
    {
        debut = now;
        fin = m_date_fin;
    }else
    {
        debut = m_date_debut;
        fin = m_date_fin;
    }

    // sélectionner toutes les réservations en cours
    QList<QSqlRecord> records;
    records << reservation::reservation_records_en_cours();

    foreach(QSqlRecord r, records)
    {
        reservation rv(r);

        showSigneReservation(rv);
    }
}

void PiloteDePlanning::showSigneOccupation(occupation oc)
{
    int row = this->row(oc.chambreOccupee());
    for(int i = 0; i < oc.dureeOccupation(); i++) // jusqu'au jour d'hier
    {
        QDate date = oc.datedEntree().date().addDays(i);
        if(dayIsIn(date))
        {
            int col = this->column(date);

            if(estDisponible(row, col))
            {
                initItemSigneOccupe(row, col);
                afficherInfosGenerales(col);
            }
        }
    }
}

void PiloteDePlanning::showSigneReservation(reservation rv)
{
    QList<QSqlRecord> records1;
    records1 << chambreReservee::chambre_reservee_records(rv.numReservation());
    foreach(QSqlRecord r1, records1)
    {
        chambreReservee chr(r1);
        int row = this->row(chr.identiteCh());

        for(int i = 0; i < rv.dureeOccupation(); i++)// jusqu'au jour d'hier
        {
            QDate date = rv.datedEntree().date().addDays(i);
            if(dayIsIn(date))
            {
                int col = this->column(date);

                if(estDisponible(row, col))
                {
                    initItemSigneReserve(row, col);
                    afficherInfosGenerales(col);
                }
            }
        }
    }
}

void PiloteDePlanning::showSigneOccupations()
{
    QDate now = Horloge::currentDate();

    QDate debut;
    QDate fin;

    if(dayIsIn(now))
    {
        debut = now;
        fin = m_date_fin;
    }else
    {
        debut = m_date_debut;
        fin = m_date_fin;
    }

    // sélectionner toutes les occupations en cours
    QList<QSqlRecord> records;
    records << occupation::occupationsEnCours();

    foreach(QSqlRecord r, records)
    {
        occupation oc(r);
        showSigneOccupation(oc);
    }
}

void PiloteDePlanning::showReservationsComplet()
{
    adapterLimitesDuPlanningReserv();
    construirePlanning();
    initialiserCellules();
    rafraichirPlanningReserv();

//    adapterLimitesDuPlanningReserv();
//
//    construirePlanning();
//
//    if(m_planningRecree)
//        rafraichirPlanningReserv();
//    else
//        if(m_moisAjoute)
//        {
//            rafraichirPlanningReserv(m_colDebMoisAjoute, m_colFinMoisAjoute);
//        }
}

void PiloteDePlanning::initialiserActions()
{
    m_actionCheckIn = new QAction("Définir jour entrée", 0);
    m_actionCheckOut = new QAction("Définir jour sortie", 0);
    m_actionNouveauCheckOut = new QAction("Prolonger le séjour", 0);
    m_actionConfirmerSortie = new QAction("Exécuter la sortie du client", 0);
    m_actionReserver = new QAction("Réserver sélection", 0);
    m_actionIdentifierClient = new QAction("Identifier le client", 0);
    m_actionVoirDetailsSurClient = new QAction("Voir détails sur le client", 0);
    m_actionFacturerClient = new QAction("Facturer le client", 0);
    m_actionAnnulerReserv = new QAction("Annuler à partir d'ici", 0);
    m_actionDebuterDeplacement = new QAction("Déloger le client à partir d'ici", 0);
    m_actionTerminerDeplacement = new QAction("Loger le client à partir d'ici", 0);
    m_actionEnregistrer = new QAction("Enregistrer tout sur ce planning", 0);
    m_actionOccuper = new QAction("Occuper sélection", 0);
    m_actionDebuterNettoyage = new QAction("Débuter le nettoyage", 0);
    m_actionTerminerNettoyage = new QAction("Terminer le nettoyage", 0);
    m_actionANettoyer = new QAction("Signaler chambre à nettoyer", 0);
    m_actionImprimerRecu = new QAction("Imprimer réçu", 0);
    m_actionImprimerFacture = new QAction("Imprimer facture", 0);
    m_actionExecuterReserv = new QAction("Exécuter à partir d'ici", 0);
    m_actionLierAUnGroupe = new QAction("Lier à un groupe", 0);

    QAction * separator1 = new QAction(0); separator1->setSeparator(true);
    QAction * separator2 = new QAction(0); separator2->setSeparator(true);
    QAction * separator3 = new QAction(0); separator3->setSeparator(true);
    QAction * separator4 = new QAction(0); separator4->setSeparator(true);

    m_actionImprimerRecu->setVisible(false);

    if(estPlanningOccup())
    {
        m_actionReserver->setVisible(false);
        m_actionExecuterReserv->setVisible(false);
        m_actionDebuterDeplacement->setVisible(false);
        m_actionTerminerDeplacement->setVisible(false);
        separator2->setVisible(false);
    }

    if(estPlanningReserv())
    {
        m_actionOccuper->setVisible(false);
        m_actionConfirmerSortie->setVisible(false);
        m_actionImprimerFacture->setVisible(false);
        m_actionDebuterDeplacement->setVisible(false);
        m_actionTerminerDeplacement->setVisible(false);
        separator2->setVisible(false);
        separator3->setVisible(false);
    }

    m_tableWidget->addAction(m_actionEnregistrer);
    m_tableWidget->addAction(m_actionAnnulerReserv);
    m_tableWidget->addAction(m_actionExecuterReserv);
    m_tableWidget->addAction(separator4);
    m_tableWidget->addAction(m_actionCheckIn);
    m_tableWidget->addAction(m_actionCheckOut);
    m_tableWidget->addAction(m_actionOccuper);
    m_tableWidget->addAction(m_actionReserver);
    m_tableWidget->addAction(m_actionNouveauCheckOut);
    m_tableWidget->addAction(separator1);
    m_tableWidget->addAction(m_actionVoirDetailsSurClient);
    m_tableWidget->addAction(m_actionIdentifierClient);
    m_tableWidget->addAction(m_actionLierAUnGroupe);
    m_tableWidget->addAction(m_actionFacturerClient);
    m_tableWidget->addAction(m_actionConfirmerSortie);
    m_tableWidget->addAction(separator2);
    m_tableWidget->addAction(m_actionDebuterDeplacement);
    m_tableWidget->addAction(m_actionTerminerDeplacement);
    m_tableWidget->addAction(separator3);
    m_tableWidget->addAction(m_actionImprimerFacture);
    m_tableWidget->addAction(m_actionImprimerRecu);
//    m_tableWidget->addAction(m_actionANettoyer);
//    m_tableWidget->addAction(m_actionDebuterNettoyage);
//    m_tableWidget->addAction(m_actionTerminerNettoyage);

    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(verifierZoneValide(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionChecks(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionReserverEtOccuper(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionIdentifierClient(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionVoirDetailsClient(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionDeposerUnMontant(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionAnnulerReservation(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionDeplacerReservation(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionDeposerIci(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionConfirmerSortie(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionProlongerCheckOut(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionEnregistrer(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionExecuterReserv(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionLierAUnGroupe(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionImprimerFacture(QModelIndex)));
    connect(m_tableWidget, SIGNAL(pressed(QModelIndex)), this, SLOT(updateEtatActionFacturerClient(QModelIndex)));

    connect(m_actionCheckIn, SIGNAL(triggered()), this, SLOT(checkIn()));
    connect(m_actionCheckOut, SIGNAL(triggered()), this, SLOT(checkOut()));
    connect(m_actionReserver, SIGNAL(triggered()), this, SLOT(reserver()));
    connect(m_actionOccuper, SIGNAL(triggered()), this, SLOT(occuper()));
    connect(m_actionFacturerClient, SIGNAL(triggered()), this, SLOT(facturerSelection()));
    connect(m_actionAnnulerReserv, SIGNAL(triggered()), this, SLOT(annulerReservation()));
    connect(m_actionIdentifierClient, SIGNAL(triggered()), this, SLOT(identifierClient()));
    connect(m_actionDebuterDeplacement, SIGNAL(triggered()), this, SLOT(debuterDeplacementDeSelection()));
    connect(m_actionTerminerDeplacement, SIGNAL(triggered()), this, SLOT(terminerDeplacementDeSelection()));
    connect(m_actionVoirDetailsSurClient, SIGNAL(triggered()), this, SLOT(voirDetailsSurClient()));
    connect(m_actionConfirmerSortie, SIGNAL(triggered()), this, SLOT(arreterLocation()));
    connect(m_actionNouveauCheckOut, SIGNAL(triggered()), this, SLOT(prolongerCheckOut()));
    connect(m_actionEnregistrer, SIGNAL(triggered()), this, SLOT(enregistrer()));
    connect(m_actionExecuterReserv, SIGNAL(triggered()), this, SLOT(executerReservation()));
    connect(m_actionLierAUnGroupe, SIGNAL(triggered()), this, SLOT(lierAUnGroupe()));
    connect(m_actionImprimerFacture, SIGNAL(triggered()), this, SLOT(imprimerFacture()));

//    connect(m_actionDebuterNettoyage, SIGNAL(triggered()), this, SLOT(debuterNettoyageDeSelection()));
//    connect(m_actionTerminerNettoyage, SIGNAL(triggered()), this, SLOT(terminerNettoyageDeSelection()));
//    connect(m_actionANettoyer, SIGNAL(triggered()), this, SLOT(selectionANettoyer()));
}

void PiloteDePlanning::updateEtatActionChecks(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    QDate now = Horloge::currentDate();
    QDate date = m_date_debut.addDays(index.column());

    // vérifier qu'il y a une seule case sélectionnée
    if(m_tableWidget->selectedItems().count() != 1)
    {
        m_actionCheckIn->setEnabled(false);
        m_actionCheckOut->setEnabled(false);
        return;
    }else
    {
        if(!estDisponible(index.row(), index.column()))
        {
            m_actionCheckIn->setEnabled(false);
            m_actionCheckOut->setEnabled(false);
            return;
        }else
        {
            // vérifier que la date de la sélection n'est pas passée
            if(date < now)
            {
                m_actionCheckIn->setEnabled(false);
                m_actionCheckOut->setEnabled(false);
                return;
            }else
            {
                // vérifier que la case est une case disponible (check-in et check-out)
                if(estDisponible(index.row(), index.column()))
                {
                    if(m_rowOfCheckIn == index.row())
                    {
                        // voir si toutes les cases intermédiaires sont disponibles
                        bool uneCaseEstIndisponible = false;

                        int col = index.column();
                        col--;
                        while((col >= 0) && estDisponible(index.row(), col))
                        {
                            col--;
                        }

                        uneCaseEstIndisponible = (col != m_colOfCheckIn);
                        m_actionCheckOut->setEnabled(!uneCaseEstIndisponible); // check-in déjà sur la même ligne
                    }else
                    {
                        m_actionCheckOut->setEnabled(false); // faire d'abord un check-in
                    }

                    if(m_actionCheckOut->isEnabled())
                    {
                        m_actionCheckIn->setEnabled(false);
                    }else
                    {
                        if(date > now && estPlanningOccup())
                        {
                            m_actionCheckIn->setEnabled(false);
                        }else
                        {
                            m_actionCheckIn->setEnabled(true);
                        }
                    }
                }else
                {
                    m_actionCheckIn->setEnabled(false);
                    m_actionCheckOut->setEnabled(false);
                    return;
                }
            }
        }
    }
}

void PiloteDePlanning::updateEtatActionReserverEtOccuper(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    QDate now = Horloge::currentDate();

    QList<QTableWidgetItem *> items;
    items << m_tableWidget->selectedItems();

    bool uneCaseEstPassee = false;
    bool uneCaseEstIndisponible = false;
    bool plusieursLignes = false;
    bool premiereCaseEstAujourdhui = date(items.first()->column()) == Horloge::currentDate();
    int i = -1;

    int row = items.at(0)->row();
    do
    {
        i++;
        if(m_date_debut.addDays(items.at(i)->column()) < now)
        {
            uneCaseEstPassee = true;
        }

        if(!estDisponible(items.at(i)->row(), items.at(i)->column()))
        {
            uneCaseEstIndisponible = true;
        }

        if(row != items.at(i)->row())
        {
            plusieursLignes = true;
        }

    }while(!uneCaseEstPassee && !uneCaseEstIndisponible && !plusieursLignes && (i < items.count() - 1));

    m_actionReserver->setDisabled(uneCaseEstIndisponible || uneCaseEstPassee || plusieursLignes);
    m_actionOccuper->setDisabled(!premiereCaseEstAujourdhui || uneCaseEstIndisponible || uneCaseEstPassee || plusieursLignes);
}

void PiloteDePlanning::updateEtatActionDeposerUnMontant(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    if(m_tableWidget->selectedItems().count() > 1)
    {
        m_actionFacturerClient->setEnabled(false);
        return;
    }else
    {
        if(!estOccupee(index.row(), index.column()) && !estReservee(index.row(), index.column()))
        {
            m_actionFacturerClient->setEnabled(false);
            return;
        }else
        {
            if(data(index.row(), index.column(), IdTypeReservation).toInt() <= 0)
            {
                m_actionFacturerClient->setEnabled(false);
            }else
            {
                m_actionFacturerClient->setEnabled(clientExiste(index.row(), index.column()));
            }
        }
    }
}

void PiloteDePlanning::updateEtatActionAnnulerReservation(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    if(m_tableWidget->selectedItems().count() != 1)
    {
        m_actionAnnulerReserv->setEnabled(false);
        return;
    }else
    {
        if(!((m_tableWidget->item(index.row(), index.column())->backgroundColor() == m_colorOccupee)
                || (m_tableWidget->item(index.row(), index.column())->backgroundColor() == m_colorReservee)))
        {
            m_actionAnnulerReserv->setEnabled(false);
            return;
        }
    }

    m_actionAnnulerReserv->setEnabled(true);
}

void PiloteDePlanning::updateEtatActionDeplacerReservation(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    int row = index.row();
    int col = index.column();

    if((m_tableWidget->selectedItems().count() != 1))
    {
        m_actionDebuterDeplacement->setEnabled(false);
        return;
    }else
    {
        if(data(row, col, IdTypeReservation).toInt() > 0
            &&
            (((estOccupee(row, col) && !estOccupeeConso(row, col)) && (colEntree(row, col) == col || estOccupeeConso(row, col - 1)))
             || (estReservee(row, col) && !estReserveeConso(row, col))))
        {
            m_actionDebuterDeplacement->setEnabled(true);
            return;
        }else
        {
            m_actionDebuterDeplacement->setEnabled(false);
            return;
        }
    }
}

void PiloteDePlanning::updateEtatActionIdentifierClient(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    if(m_tableWidget->selectedItems().count() > 1)
    {
        m_actionIdentifierClient->setEnabled(false);
        return;
    }else
    {
        if(estDisponible(index.row(), index.column()))
        {
            m_actionIdentifierClient->setEnabled(false);
            return;
        }else
        {
            if(estOccupee(index.row(), index.column()) || estReservee(index.row(), index.column()))
            {
                QDate now = Horloge::currentDate();

                if(date(colSortie(index.row(), index.column())) < now)
                {
                    m_actionIdentifierClient->setEnabled(false);
                    return;
                }else
                {
                    m_actionIdentifierClient->setEnabled(!clientExiste(index.row(), index.column()));
                    return;
                }
            }else
            {
                m_actionIdentifierClient->setEnabled(false);
                return;
            }
        }
    }
}

void PiloteDePlanning::updateEtatActionVoirDetailsClient(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    int id = data(index.row(), index.column(), IdTypeReservation).toInt();
    m_actionVoirDetailsSurClient->setEnabled(clientExiste(index.row(), index.column()) && id > 0);
}

void PiloteDePlanning::updateEtatActionDeposerIci(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    if(m_itemsADeplacer.isEmpty())
    {
        m_actionTerminerDeplacement->setEnabled(false);
        return;
    }else
    {
        if(!estDisponible(index.row(), index.column()))
        {
            m_actionTerminerDeplacement->setEnabled(false);
            return;
        }else
        {
            QDate date = this->date(index.column());

            int row = m_itemsADeplacer.first()->row();
            int col = m_itemsADeplacer.first()->column();
            int colFinPresume = index.column() + (colSortie(row, col) - col);
            if(estOccupee(row, col))
            {
                QDate dateRef = this->date(m_itemsADeplacer.first()->column());
                if(date != dateRef)
                {
                    m_actionTerminerDeplacement->setEnabled(false);
                    return;
                }else
                {
                    bool uneCaseEstIndisponible = false;
                    int i = index.column();
                    do
                    {
                        i++;
                        uneCaseEstIndisponible = !estDisponible(index.row(), i);
                    }while(!uneCaseEstIndisponible && (i < colFinPresume));
                    m_actionTerminerDeplacement->setDisabled(uneCaseEstIndisponible);
                    return;
                }
            }else
            {
                if(estReservee(row, col))
                {
                    if(date < Horloge::currentDate())
                    {
                        m_actionTerminerDeplacement->setEnabled(false);
                        return;
                    }else
                    {
                        bool uneCaseEstIndisponible = false;
                        int i = index.column();
                        do
                        {
                            i++;
                            uneCaseEstIndisponible = !estDisponible(index.row(), i);
                        }while(!uneCaseEstIndisponible && (i < colFinPresume));
                        m_actionTerminerDeplacement->setDisabled(uneCaseEstIndisponible);
                        return;
                    }
                }else
                {
                    m_actionTerminerDeplacement->setEnabled(false);
                }
            }
        }
    }
}

void PiloteDePlanning::showOccupation(const occupation & oc)
{
    if(!oc.existe())
        return;

    QDate dateEntree = oc.datedEntree().date();
    QDate dateSortie = oc.datedSortie().date();
    QDateTime now = Horloge::currentDateTime();

    libererOccup li = libererOccup::selectionner(oc.numOccupation());

    if(!m_chambres_str.contains(oc.chambreOccupee())
        && (dateEntree < m_date_debut || dateSortie > m_date_fin))
        return;

    // afficher l'espace réservé
    QString ch = oc.chambreOccupee();

    int row = m_chambres_str.indexOf(ch) + IDVIDE + 1;
    int colDebut = m_date_debut.daysTo(dateEntree);

    int colFin = m_date_debut.daysTo(dateSortie) - 1;

    if(oc.terminee() && oc.datedSortie() > now)
        colFin = m_date_debut.daysTo(li.date().date()) - 1;

    client cl(oc.codeClient());

    // initialiser le début et la fin de l'occupation
    initItemDebutOccup(row, colDebut);
    if(colDebut != colFin)
        initItemFinOccup(row, colFin);

    // personnaliser les données générales de l'occupation
    QStringList data = m_tableWidget->item(row, colDebut)->data(Qt::UserRole).toStringList();

    data.replace(IdTypeReservation, QString::number(oc.numOccupation()));
    data.replace(IdClient, QString::number(oc.codeClient()));
    data.replace(TotalAPayer, QString::number(oc.cout()));
    data.replace(ResteAPayer, QString::number(oc.reste()));
    data.replace(Nom, cl.nom());
    data.replace(HeureEntree, oc.datedEntree().time().toString(Qt::ISODate));
    data.replace(ColEntree, QString::number(colDebut));
    data.replace(ColSortie, QString::number(colFin));
    data.replace(NomComplet, cl.nomComplet());
    data.replace(Groupe_r, QString::number(oc.idGroupe()));
    data.replace(IdProfileClient, QString::number(oc.idProfileClient()));
    data.replace(IdPieceIdentite, QString::number(pieceIdentiteClient(oc.numOccupation()).idPieceIdentite()));
    data.replace(NbEnfAccMoinsDe15, QString::number(oc.enfAccMoinsDe15()));
    data.replace(DestinationExacte, oc.destinationExacte());

    if(!oc.terminee())
    {
        data.replace(SortieDiffusee, QString::number(0));
        data.replace(HeureDeSortie, oc.datedSortie().time().toString(Qt::ISODate));
    }
    else
    {
        data.replace(SortieDiffusee, QString::number(1));
        data.replace(HeureDeSortie, li.date().toString(Qt::SystemLocaleLongDate));
    }

    if(oc.estReglee())
    {
        setTextureToutPayee(row, colDebut);
        setTextureToutPayee(row, colFin);
    }
    else
    {
        setTextureNonToutPayee(row, colDebut);
        setTextureNonToutPayee(row, colFin);
    }

    setData(row, colDebut, data);
    setData(row, colFin, data);

    // afficher le prénom au début    
    if(oc.idGroupe() > 0)
        showValue(row, colDebut, tr("%1 (%2)").arg(cl.nom().toUpper()).arg(groupe(oc.idGroupe()).libelle()));
    else
        showValue(row, colDebut, cl.nom().toUpper());

    // afficher rétard
    QTableWidgetItem * item = m_tableWidget->takeItem(row, colFin);
    HeureLimite hl(1);
    if(oc.datedSortie() < now)
    {
        // la durée du rétard
        int minutes = 0;
        if(!oc.terminee())
        {
            item->setIcon(QIcon(":/images/present.png"));
            minutes = oc.datedSortie().secsTo(now) / 60 - hl.tempsTolerance();
        }else
        {
            minutes = oc.datedSortie().secsTo(li.date()) / 60 - hl.tempsTolerance();
        }

        if(minutes > 0)
            item->setToolTip(tr("Durée du rétard : %1")
                             .arg(MesTables::convertirJourHeureMinute(minutes)));

        // afficher les espaces intermédiaires au retard
        int colFin2 = 0;
        if(oc.terminee())
            colFin2 = m_date_debut.daysTo(li.date().date()) - 1;
        else
            colFin2 = m_date_debut.daysTo(now.date());

        if(colFin + 1 <= colFin2)
        {
            initItemIndispo(row, colFin + 1);
            initItemIndispo(row, colFin2);

            showEspaceReserve(row, colFin + 1, colFin2, false);

            if(!oc.terminee())
            {
                emit rendreChambresIndispo(date(colFin + 1), date(colFin2), ch); // sur un autre planning de type réservation
            }
        }
    }

    if(oc.terminee())
    {
        item->setIcon(QIcon(":/images/sortie.png"));
    }

    m_tableWidget->setItem(row, colFin, item);

    // afficher l'occupation maintenant
    showEspaceReserve(row, colDebut, colFin, false);

    if(!oc.terminee())
    {
        emit occupationEnregistree(oc); // pour signaler l'enregistrer sur un autre planning
    }
}

void PiloteDePlanning::showEspaceReserve(int row, int colDeb, int colFin, bool actualiserInfosGene)
{
    QDate now = Horloge::currentDate();

    QString he = data(row, colDeb, HeureEntree);
    QString hs = data(row, colFin, HeureDeSortie);

    // données communes
    setData(row, colDeb, HeureDeSortie, hs);
    setData(row, colFin, HeureEntree, he);

    setData(row, colFin, ColEntree, colDeb);
    setData(row, colDeb, ColSortie, colFin);

    QStringList data = this->data(row, colDeb);

    data.replace(Entree, QString::number(0));

    QColor colorDebut = m_tableWidget->item(row, colDeb)->backgroundColor();
    QColor colorFin = m_tableWidget->item(row, colFin)->backgroundColor();

    QIcon iconDebut = m_tableWidget->item(row, colDeb)->icon();
    QIcon iconFin= m_tableWidget->item(row, colFin)->icon();

    QString textTooTip;
    if(estReservee(row, colDeb) || estOccupee(row, colDeb))
    {
        int somme_payee = this->data(row, colDeb, TotalAPayer).toInt() - this->data(row, colDeb, ResteAPayer).toInt();
        textTooTip = tr("Nom et prénom(s) : %1\nFrais de location : %2\nSomme payée : %3\nReste à payer : %4\nHeure d'entrée : %5\nHeure de sortie : %6")
                                 .arg(this->data(row, colDeb, NomComplet))
                                 .arg(this->data(row, colDeb, TotalAPayer))
                                 .arg(QString::number(somme_payee))
                                 .arg(this->data(row, colDeb, ResteAPayer))
                                 .arg(this->data(row, colDeb, HeureEntree))
                                 .arg(this->data(row, colDeb, HeureDeSortie));

        QString retard_str = this->toolTip(row, colFin);
        if(!retard_str.isEmpty())
        {
            retard_str = retard_str.split("\n").last();
            if(retard_str.contains("Durée du rétard :"))
                textTooTip.append(tr(" \n%1").arg(retard_str));
        }          

        setToolTip(row, colDeb, textTooTip);
        setToolTip(row, colFin, textTooTip);
    }

    for(int col = colDeb + 1; col < colFin; col++)
    {
        QDate date = m_date_debut.addDays(col);

        if(date >= now)
        {
            // temps présent
            showCell(row, col, QString(), data, colorFin, iconFin);
        }else
        {
            // date passée
            showCell(row, col, QString(), data, colorDebut, iconDebut);
        }

        if(!textTooTip.isEmpty())
        {
            setToolTip(row, col, textTooTip);
        }

        setTexture(row, col, getTexture(row, colDeb));
    }

    // actualiser infos générales
    if(actualiserInfosGene)
        afficherInfosGenerales(colDeb, colFin);
}

void PiloteDePlanning::showReservation(const reservation &rv, bool AvecCondition)
{
    if(!rv.existe())
        return;

    bool annulee = annulerReserv::selectionner(rv.numReservation()).existe();

    if(annulee)
        return;

    QDateTime now = Horloge::currentDateTime();
    QDate dateEntree = rv.datedEntree().date();
    QDate dateSortie = rv.datedSortie().date();

    if(dateEntree < m_date_debut || dateSortie > m_date_fin)
        return;

    QList<QSqlRecord> records;
    records << chambreReservee::chambre_reservee_records(rv.numReservation());

    client cl(rv.codeClient());
    foreach(QSqlRecord r, records)
    {
        chambreReservee chr(r);

        // on prend les réservations passées non exécutées comme les réservations futures
        if(m_chambres_str.contains(chr.identiteCh())
            && ((AvecCondition && !chr.terminee()) || !AvecCondition))
        {
            QString ch = chr.identiteCh();

            int row = m_chambres_str.indexOf(ch) + IDVIDE + 1;
            int colDebut = m_date_debut.daysTo(dateEntree);
            int colFin = m_date_debut.daysTo(dateSortie) - 1;

            // initialiser le début et la fin de la réservation
            initItemDebutReserv(row, colDebut);
            if(colDebut != colFin)
                initItemFinReserv(row, colFin);

            QStringList data = m_tableWidget->item(row, colDebut)->data(Qt::UserRole).toStringList();
            data.replace(IdTypeReservation, QString::number(rv.numReservation()));
            data.replace(IdClient, QString::number(rv.codeClient()));
            data.replace(TotalAPayer, QString::number(rv.cout()));
            data.replace(ResteAPayer, QString::number(rv.reste()));
            data.replace(Nom, cl.nom());
            data.replace(HeureEntree, rv.datedEntree().time().toString(Qt::ISODate));
            data.replace(HeureDeSortie, rv.datedSortie().time().toString(Qt::ISODate));
            data.replace(ColEntree, QString::number(colDebut));
            data.replace(ColSortie, QString::number(colFin));
            data.replace(NomComplet, cl.nomComplet());
            data.replace(Groupe_r, QString::number(rv.idGroupe()));
            data.replace(IdProfileClient, QString::number(rv.idProfileClient()));

            if(chr.executee())
            {
                data.replace(Executee, QString::number(1));
                QTableWidgetItem * item = m_tableWidget->takeItem(row, colDebut);
                item->setIcon(QIcon(":/images/executee.png"));
                m_tableWidget->setItem(row, colDebut, item);

                QTableWidgetItem * item1 = m_tableWidget->takeItem(row, colFin);
                item1->setIcon(QIcon(":/images/executee.png"));
                m_tableWidget->setItem(row, colFin, item1);
            }else
            {
                data.replace(Executee, QString::number(0));
//                if(rv.datedEntree().date() < now.date())
//                {
//                    chr.setTerminer(true);
//                    chr.enregistrer();
//                }
            }

            setData(row, colDebut, data);
            setData(row, colFin, data);

            if(rv.idGroupe() > 0)
                showValue(row, colDebut, tr("%1 (%2)").arg(cl.nom().toUpper()).arg(groupe(rv.idGroupe()).libelle().toUpper()));
            else
                showValue(row, colDebut, cl.nom().toUpper());

            showEspaceReserve(row, colDebut, colFin, false);
        }
    }

    if(rv.datedSortie().date() >= now.date())
    {
        emit reservationEnregistree(rv);
    }
}

void PiloteDePlanning::showOccupations()
{
    emit typeOperation("Chargement des locations...");

    QList<QSqlRecord> records;
    records << occupation::occupation_records(m_date_debut, m_date_fin);

    emit dataATraiter(records.count());

    foreach(QSqlRecord r, records)
    {
        occupation oc(r);

        if(!oc.terminee() || (oc.terminee() && libererOccup::selectionner(oc.numOccupation()).existe()))
            showOccupation(oc);

        emit opElt();
    }
}

void PiloteDePlanning::showReservations()
{
    QList<QSqlRecord> records1;
    records1 << reservation::reservation_records(m_date_debut, m_date_fin);

    foreach(QSqlRecord r, records1)
    {
        showReservation(reservation(r));
    }
}

void PiloteDePlanning::showAllReservations()
{
    emit typeOperation("Chargement des réservations...");
    QList<QSqlRecord> records1;
    records1 << reservation::reservation_records(m_date_debut, m_date_fin);

    emit dataATraiter(records1.count());

    foreach(QSqlRecord r, records1)
    {
        showReservation(reservation(r), false);

        emit opElt();
    }
}

void PiloteDePlanning::showOccupations(int colDeb, int colFin)
{
    QList<QSqlRecord> records;
    records << occupation::occupation_records(date(colDeb), date(colFin));

    foreach(QSqlRecord r, records)
    {
        occupation oc(r);

        if(!oc.terminee() || (oc.terminee() && libererOccup::selectionner(oc.numOccupation()).existe()))
            showOccupation(oc);
    }
}

void PiloteDePlanning::showReservations(int colDeb, int colFin)
{
    QList<QSqlRecord> records1;
    records1 << reservation::reservation_records(date(colDeb), date(colFin));

    foreach(QSqlRecord r, records1)
    {
        showReservation(reservation(r));
    }
}

void PiloteDePlanning::showAllReservations(int colDeb, int colFin)
{
    QList<QSqlRecord> records1;
    records1 << reservation::reservation_records(date(colDeb), date(colFin));

    foreach(QSqlRecord r, records1)
    {
        showReservation(reservation(r), false);
    }
}

void PiloteDePlanning::clearOccupations()
{
    QList<QSqlRecord> records;
    records << occupation::occupation_records(m_date_debut, m_date_fin);

    foreach(QSqlRecord r, records)
    {
        clearOccupation(occupation(r));
    }
}

void PiloteDePlanning::clearReservations()
{
    QList<QSqlRecord> records1;
    records1 << reservation::reservation_records(m_date_debut, m_date_fin);

    foreach(QSqlRecord r, records1)
    {
        clearReservation(reservation(r));
    }
}

void PiloteDePlanning::clearOccupation(const occupation &oc)
{
    if(!oc.existe())
        return;

    QDate dateEntree = oc.datedEntree().date();
    QDate dateSortie = oc.datedSortie().date();

    if(!m_chambres_str.contains(oc.chambreOccupee())
        && (dateEntree < m_date_debut || dateSortie > m_date_fin))
        return;

    // afficher l'espace réservé
    QString ch = oc.chambreOccupee();

    int row = m_chambres_str.indexOf(ch) + IDVIDE + 1;
    int colDebut = m_date_debut.daysTo(dateEntree);
    int colFin = m_date_debut.daysTo(dateSortie) - 1;

    initItemDispo(row, colDebut);
    initItemDispo(row, colFin);

    showEspaceReserve(row, colDebut, colFin, Liberation);
    emit rendreChambresDispo(date(colDebut), date(colFin), chambreDe(row));

    // afficher rétard
    QDateTime now = Horloge::currentDateTime();

    if(!oc.terminee() && oc.datedSortie() < now)
    {
        int colRetardFin = m_date_debut.daysTo(now.date());

        initItemDispo(row, colFin + 1);
        initItemDispo(row, colRetardFin);

        showEspaceReserve(row, colFin + 1, colRetardFin);
        emit rendreChambresDispo(date(colFin + 1), date(colRetardFin), chambreDe(row));
    }
}

void PiloteDePlanning::clearReservation(const reservation &rv)
{
    if(!rv.existe())
        return;

    QDate dateEntree = rv.datedEntree().date();
    QDate dateSortie = rv.datedSortie().date();

    if(dateEntree < m_date_debut || dateSortie > m_date_fin)
        return;

    QList<QSqlRecord> records;
    records << chambreReservee::chambre_reservee_records(rv.numReservation());

    foreach(QSqlRecord r, records)
    {
        chambreReservee chr(r);

        // on prend les réservations passées non exécutées comme les réservations futures
        if(m_chambres_str.contains(chr.identiteCh()) && !chr.terminee())
        {
            QString ch = chr.identiteCh();

            int row = m_chambres_str.indexOf(ch) + IDVIDE + 1;
            int colDebut = m_date_debut.daysTo(dateEntree);
            int colFin = m_date_debut.daysTo(dateSortie) - 1;

            initItemDispo(row, colDebut);
            initItemDispo(row, colFin);

            showEspaceReserve(row, colDebut, colFin, false);
            emit rendreChambresDispo(date(colDebut), date(colFin), chambreDe(row));
        }
    }
}

void PiloteDePlanning::clearEspace(int row, int colDeb, int colFin)
{
    initItemDispo(row, colDeb);
    initItemDispo(row, colFin);

    showEspaceReserve(  row
                      , colDeb
                      , colFin);

    emit rendreChambresDispo(date(colDeb), date(colFin), chambreDe(row));
}

void PiloteDePlanning::updateEtatActionConfirmerSortie(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    if(data(index.row(), index.column(), SortieDiffusee).toInt() == 1)
    {
        m_actionConfirmerSortie->setEnabled(false);
        return;
    }

    if(m_tableWidget->item(index.row(), index.column())->backgroundColor() != m_colorOccupeeConso)
    {
        m_actionConfirmerSortie->setEnabled(false);
        return;
    }else
    {

        if(index.column() + 1 > m_tableWidget->columnCount() - 1)
        {
            m_actionConfirmerSortie->setEnabled(false);
        }else
        {
            int col = index.column() + 1;
            if(m_tableWidget->item(index.row(), col)->backgroundColor() == m_colorOccupeeConso)
            {
                m_actionConfirmerSortie->setEnabled(false);
            }else
            {
                // c'est la fin courante d'une location
                m_actionConfirmerSortie->setEnabled(true);
//                if((m_tableWidget->item(index.row(), index.column())->icon().pixmap() == QPixmap())
//                    || (m_tableWidget->item(index.row(), index.column())->icon().pixmap() == QPixmap(":/images/pas_sortie.png")))
//                {
//                    m_actionConfirmerSortie->setEnabled(true);
//                    return;
//                }else
//                {
//                    m_actionConfirmerSortie->setEnabled(false);
//                }
            }
        }
    }
}

void PiloteDePlanning::updateEtatActionProlongerCheckOut(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    if(date(index.column()) >= Horloge::currentDate())
    {
        if((estOccupee(index.row(), index.column())
            && (data(index.row(), index.column(), SortieDiffusee).toInt() == 0))
            || estReservee(index.row(), index.column()))
        {
            if(data(index.row(), index.column(), IdTypeReservation).toInt() !=0)
            {
                m_actionNouveauCheckOut->setEnabled(true);
            }else
            {
                m_actionNouveauCheckOut->setEnabled(false);
            }
        }else
        {
             m_actionNouveauCheckOut->setEnabled(false);
        }
    }else
    {
        m_actionNouveauCheckOut->setEnabled(false);
    }
}

void PiloteDePlanning::updateEtatActionEnregistrer(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    if(m_nouveauxChecksIn.isEmpty() || (m_tableWidget->selectedItems().count() == 0))
    {
        m_actionEnregistrer->setEnabled(false);
    }else
    {
        m_actionEnregistrer->setEnabled(true);
    }
}

void PiloteDePlanning::updateEtatActionExecuterReserv(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    if(m_tableWidget->selectedItems().count() > 1)
    {
        m_actionExecuterReserv->setEnabled(false);
        return;
    }else
    {
        QDate now = Horloge::currentDate();
        if(   (date(index.column()) == now)
            && estReservee(index.row(), index.column())
            && (data(index.row(), index.column(), ColEntree).toInt() == index.column()))
        {
            if(data(index.row(), index.column(), Executee).toInt() == 1)
            {
                m_actionExecuterReserv->setEnabled(false);
            }else
            {
                m_actionExecuterReserv->setEnabled(true);
            }
        }else
        {
            m_actionExecuterReserv->setEnabled(false);
        }
    }
}

void PiloteDePlanning::updateEtatActionLierAUnGroupe(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    if(m_tableWidget->selectedItems().count() > 1)
    {
        m_actionLierAUnGroupe->setEnabled(false);
        return;
    }else
    {
        if(estDisponible(index.row(), index.column()))
        {
            m_actionLierAUnGroupe->setEnabled(false);
            return;
        }else
        {
            if(estOccupee(index.row(), index.column()) || estReservee(index.row(), index.column()))
            {
                QDate now = Horloge::currentDate();

                if(date(colSortie(index.row(), index.column())) < now)
                {
                    m_actionLierAUnGroupe->setEnabled(false);
                    return;
                }else
                {
                    m_actionLierAUnGroupe->setEnabled(!clientExiste(index.row(), index.column()));
                    return;
                }
            }else
            {
                m_actionLierAUnGroupe->setEnabled(false);
                return;
            }
        }
    }
}

void PiloteDePlanning::initCelluleCh(int row, int column)
{
    QTableWidgetItem * item = new QTableWidgetItem(QString());
    item->setTextAlignment(Qt::AlignLeft| Qt::AlignVCenter);
    item->setToolTip(QString());

    QStringList data;
    data << QString::number(0)  // IdTypeReservation    (1)
         << QString::number(0)  // IdClient             (2)
         << QString::number(0)  // TotalAPayer          (3)
         << QString::number(0)  // ResteAPayer          (4)
         << QString()           // Prenom               (5)
         << QString::number(1)  // Disponible           (6)
         << QString::number(0)  // Occupee              (7)
         << QString::number(0)  // Reservee             (8)
         << QString()           // Heure entrée         (9)
         << QString()           // Heure de sortie      (10)
         << QString::number(0)  // Modifiee             (11)
         << QString::number(0)  // Creee                (12)
         << QString::number(-1) // ColEntree            (13)
         << QString::number(-1) // ColSortie            (14)
         << QString::number(0)  // Entree               (15)
         << QString::number(0)  // Sortie               (16)
         << QString::number(0)  // Intermediaire        (17)
         << QString()           // Nom complet          (18)
         << QString::number(1)  // SortieDiffusee       (19)
         << QString::number(0)  // Groupe               (20)
         << QString::number(0)  // Executee             (21)
         << QString::number(0)  // IdPieceIdentite      (22)
         << QString::number(0)  // IdProfileClient      (23)
         << QString::number(0)  // NbEnfAccMoinsDe15    (24)
         << QString()           // DestinationExacte    (25)
         ;
    item->setData(Qt::UserRole, data);
    item->setBackgroundColor(m_colorDisponible);
    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::initCelluleEntete(int row, int column)
{
    QTableWidgetItem * item = new QTableWidgetItem(QString());
    item->setTextAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    m_tableWidget->setItem(row, column, item);
}

int PiloteDePlanning::row(QString chambre)
{
    if(m_chambres_str.contains(chambre))
    {
        return m_chambres_str.indexOf(chambre) + IDVIDE + 1;
    }

    return -1;
}

int PiloteDePlanning::column(QDate date)
{
    if(dayIsIn(date))
    {
        return m_date_debut.daysTo(date);
    }

    return -1;
}

QDate PiloteDePlanning::date(int col)
{
    return m_date_debut.addDays(col);
}

QString PiloteDePlanning::chambreDe(int row)
{
    if(row <= IDVIDE || row >= (m_chambres_str.count() + IDVIDE + 1))
        return QString();

    return m_chambres_str.at(row - (IDVIDE + 1));
}

void PiloteDePlanning::initItemDebutOccup(int row, int column)
{
    QTableWidgetItem * itemDebut = m_tableWidget->takeItem(row, column);
    QStringList data = itemDebut->data(Qt::UserRole).toStringList();
    data.replace(Reservee_r, QString::number(0));
    data.replace(Occupee_r, QString::number(1));
    data.replace(Indisponibilite, QString::number(1));
    data.replace(Entree, QString::number(1));
    data.replace(Sortie, QString::number(0));
    data.replace(SortieDiffusee, QString::number(0));
    data.replace(ColEntree, QString::number(column));
    data.replace(IdTypeReservation, QString::number(0));
    data.replace(Disponible_r, QString::number(0));
    data.replace(HeureEntree, Horloge::currentTime().toString(Qt::ISODate));
    itemDebut->setData(Qt::UserRole, data);
    itemDebut->setBackgroundColor(m_colorOccupee);
    itemDebut->setIcon(QIcon());
    itemDebut->setToolTip(QString());

    if(m_date_debut.addDays(column) >= Horloge::currentDate())
        itemDebut->setBackgroundColor(m_colorOccupee);
    else
        itemDebut->setBackgroundColor(m_colorOccupeeConso);

    m_tableWidget->setItem(row, column, itemDebut);
}

void PiloteDePlanning::initItemDebutReserv(int row, int column)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    QStringList data = item->data(Qt::UserRole).toStringList();
    data.replace(Reservee_r, QString::number(1));
    data.replace(Occupee_r, QString::number(0));
    data.replace(Disponible_r, QString::number(0));
    data.replace(Indisponibilite, QString::number(1));
    data.replace(Entree, QString::number(1));
    data.replace(ColEntree, QString::number(column));
    data.replace(Sortie, QString::number(0));
    data.replace(SortieDiffusee, QString::number(0));
    data.replace(IdTypeReservation, QString::number(0));
    data.replace(HeureEntree, HeureLimite(1).heureFinOccupation().toString(Qt::ISODate));
    item->setData(Qt::UserRole, data);
    item->setIcon(QIcon());
    item->setToolTip(QString());

    if(m_date_debut.addDays(column) >= Horloge::currentDate())
        item->setBackgroundColor(m_colorReservee);
    else
        item->setBackgroundColor(m_colorReserveeConso);

    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::initItemFinReserv(int row, int column)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);

    QStringList data = item->data(Qt::UserRole).toStringList();
    data.replace(Reservee_r, QString::number(1));
    data.replace(Occupee_r, QString::number(0));
    data.replace(Disponible_r, QString::number(0));
    data.replace(Indisponibilite, QString::number(1));
    data.replace(Entree, QString::number(0));
    data.replace(Sortie, QString::number(1));
    data.replace(ColSortie, QString::number(column));
    data.replace(SortieDiffusee, QString::number(0));
    data.replace(IdTypeReservation, QString::number(0));
    data.replace(HeureDeSortie, HeureLimite(1).heureFinOccupation().toString(Qt::ISODate));
    item->setData(Qt::UserRole, data);
    item->setIcon(QIcon());
    item->setToolTip(QString());

    if(m_date_debut.addDays(column) >= Horloge::currentDate())
        item->setBackgroundColor(m_colorReservee);
    else
        item->setBackgroundColor(m_colorReserveeConso);

    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::initItemFinOccup(int row, int column)
{
    QTableWidgetItem * itemFin = m_tableWidget->takeItem(row, column);

    QStringList data = itemFin->data(Qt::UserRole).toStringList();
    data.replace(Reservee_r, QString::number(0));
    data.replace(Occupee_r, QString::number(1));
    data.replace(Disponible_r, QString::number(0));
    data.replace(Indisponibilite, QString::number(1));
    data.replace(Entree, QString::number(0));
    data.replace(Sortie, QString::number(1));
    data.replace(ColSortie, QString::number(column));
    data.replace(IdTypeReservation, QString::number(0));
    data.replace(SortieDiffusee, QString::number(0));
    data.replace(HeureDeSortie, HeureLimite(1).heureFinOccupation().toString(Qt::ISODate));
    itemFin->setData(Qt::UserRole, data);
    itemFin->setIcon(QIcon());
    itemFin->setToolTip(QString());

    if(m_date_debut.addDays(column) >= Horloge::currentDate())
        itemFin->setBackgroundColor(m_colorOccupee);
    else
        itemFin->setBackgroundColor(m_colorOccupeeConso);

    m_tableWidget->setItem(row, column, itemFin);
}

void PiloteDePlanning::initItemDispo(int row, int column)
{
    initCelluleCh(row, column);
}

void PiloteDePlanning::initItemIndispo(int row, int column)
{
    initCelluleCh(row, column);

    QTableWidgetItem * itemFin = m_tableWidget->takeItem(row, column);
    itemFin->setToolTip(QString());
    QStringList data = itemFin->data(Qt::UserRole).toStringList();
    data.replace(Indisponibilite, QString::number(1));

    itemFin->setData(Qt::UserRole, data);

    itemFin->setIcon(QIcon(":/images/indisponible.png"));

    m_tableWidget->setItem(row, column, itemFin);
}

void PiloteDePlanning::initItemSigneReserve(int row, int column)
{
    initCelluleCh(row, column);

    QTableWidgetItem * itemFin = m_tableWidget->takeItem(row, column);
    itemFin->setToolTip(QString("Réservée"));
    QStringList data = itemFin->data(Qt::UserRole).toStringList();
    data.replace(Indisponibilite, QString::number(1));

    itemFin->setData(Qt::UserRole, data);

    itemFin->setIcon(QIcon(":/images/reservee.png"));

    m_tableWidget->setItem(row, column, itemFin);
}

void PiloteDePlanning::initItemSigneOccupe(int row, int column)
{
    initCelluleCh(row, column);

    QTableWidgetItem * itemFin = m_tableWidget->takeItem(row, column);
    itemFin->setToolTip(QString("Occupée"));
    QStringList data = itemFin->data(Qt::UserRole).toStringList();
    data.replace(Indisponibilite, QString::number(1));

    itemFin->setData(Qt::UserRole, data);

    itemFin->setIcon(QIcon(":/images/occupee.png"));

    m_tableWidget->setItem(row, column, itemFin);
}

bool PiloteDePlanning::estDisponible(int row, int column)
{
    return (data(row, column, Disponible_r).toInt() == 1) && (data(row, column, Indisponibilite).toInt() == 0);
}

bool PiloteDePlanning::estReservee(int row, int column)
{
    return m_tableWidget->item(row, column)->data(Qt::UserRole).toStringList().at(Reservee_r).toInt() == 1;
}

bool PiloteDePlanning::estOccupee(int row, int column)
{
    return m_tableWidget->item(row, column)->data(Qt::UserRole).toStringList().at(Occupee_r).toInt() == 1;
}

bool PiloteDePlanning::estOccupeeConso(int row, int column)
{
    QDate now = Horloge::currentDate();

    if(estOccupee(row, column) && date(column) < now)
    {
        return true;
    }else
    {
        return false;
    }
}

bool PiloteDePlanning::estReserveeConso(int row, int column)
{
    QDate now = Horloge::currentDate();

    if(estReservee(row, column) && date(column) < now)
    {
        return true;
    }else
    {
        return false;
    }
}

bool PiloteDePlanning::estEntree(int row, int column)
{
    return m_tableWidget->item(row, column)->data(Qt::UserRole).toStringList().at(Entree).toInt() == 1;
}

bool PiloteDePlanning::estSortie(int row, int column)
{
    return m_tableWidget->item(row, column)->data(Qt::UserRole).toStringList().at(Sortie).toInt() == 1;
}

int PiloteDePlanning::colEntree(int row, int column)
{
    return m_tableWidget->item(row, column)->data(Qt::UserRole).toStringList().at(ColEntree).toInt();
}

int PiloteDePlanning::colSortie(int row, int column)
{
    return m_tableWidget->item(row, column)->data(Qt::UserRole).toStringList().at(ColSortie).toInt();
}

bool PiloteDePlanning::estHorsZoneChambre(int row, int column)
{
    if(row <= IDVIDE)
        return true;

    QList<QTableWidgetItem *> items;
    items << m_tableWidget->selectedItems();

    bool uneCaseEstHorsZone = false;
    int i = -1;

    do
    {
        i++;
        if(items.at(i)->row() <= IDVIDE)
        {
            uneCaseEstHorsZone = true;
        }
    }while(!uneCaseEstHorsZone && (i < items.count() - 1));

    return uneCaseEstHorsZone;
}

bool PiloteDePlanning::clientExiste(int row, int column)
{
    return data(row, column, IdClient).toInt() != 0;
}

void PiloteDePlanning::setData(int row, int column, int key, int value)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    QStringList data = item->data(Qt::UserRole).toStringList();

    data.replace(key, QString::number(value));
    item->setData(Qt::UserRole, data);
    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::setData(int row, int column, int key, QString value)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    QStringList data = item->data(Qt::UserRole).toStringList();

    data.replace(key, value);
    item->setData(Qt::UserRole, data);
    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::setData(int row, int column, QStringList data)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);

    item->setData(Qt::UserRole, data);
    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::showValue(int row, int column, QString value)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    item->setText(value);

    m_tableWidget->setItem(row, column, item);
}

QString PiloteDePlanning::data(int row, int column, int key)
{
    return m_tableWidget->item(row, column)->data(Qt::UserRole).toStringList().at(key);
}

QStringList PiloteDePlanning::data(int row, int column)
{
    return m_tableWidget->item(row, column)->data(Qt::UserRole).toStringList();
}

void PiloteDePlanning::setToolTip(int row, int column, QString text)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    item->setToolTip(text);

    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::setTextureToutPayee(int row, int column)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    item->setForeground(QBrush(Qt::NoBrush));

    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::setTextureNonToutPayee(int row, int column)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    item->setForeground(QBrush(Qt::BDiagPattern));

    m_tableWidget->setItem(row, column, item);
}

void PiloteDePlanning::setTexture(int row, int column, QBrush brush)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    item->setForeground(brush);

    m_tableWidget->setItem(row, column, item);
}

QBrush PiloteDePlanning::getTexture(int row, int column)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    QBrush brush = item->foreground();

    m_tableWidget->setItem(row, column, item);
    return brush;
}

QString PiloteDePlanning::toolTip(int row, int column)
{
    QTableWidgetItem * item = m_tableWidget->takeItem(row, column);
    QString text = item->toolTip();

    m_tableWidget->setItem(row, column, item);

    return text;
}

void PiloteDePlanning::prolongerCheckOut()
{
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    BDProlongerCheckOut bd(m_parent);
    bd.setWindowTitle("Prolonger le check-out");

    if(bd.exec() == QDialog::Accepted)
    {
        int row = m_tableWidget->currentRow();
        int col = m_tableWidget->currentColumn();

        int id =  data(row, col, IdTypeReservation).toInt();
        client cl(data(row, col, IdClient).toInt());

        int prixUnitaire = 0;
        if(cl.existe())
            prixUnitaire = prixChambreTTC(chambre(chambreDe(row)).idTypeChambre(), data(row, col, IdProfileClient).toInt()).prixTTC();

        if(estReservee(row, col))
        {
            reservation rv(id);
            rv.setDureeOccupation(rv.dureeOccupation() + bd.nbDeJoursAAjouter());
            int prix = prixUnitaire * bd.nbDeJoursAAjouter();
            rv.setCout(rv.cout() + prix);
            rv.enregistrer();

            showReservation(rv);
        }else
        {
            occupation oc(id);
            oc.setDureeOccupation(oc.dureeOccupation() + bd.nbDeJoursAAjouter());
            int prix = prixUnitaire * bd.nbDeJoursAAjouter();
            oc.setCout(oc.cout() + prix);
            oc.enregistrer();

            showOccupation(oc);
        }
    }
}

void PiloteDePlanning::enregistrer()
{
    if(m_nouveauxChecksIn.isEmpty())
    {
        emit planningModifie(false);
        return;
    }

    QDateTime now = Horloge::currentDateTime();

    // vérifier que toutes les réservations ont des clients
    for(int i = 0; i < m_nouveauxChecksIn.count(); i++)
    {
        int row = (int)m_nouveauxChecksIn.at(i).y();
        int col = (int)m_nouveauxChecksIn.at(i).x();

        QString title;
        if(estPlanningMixte())
            title = tr("Enregistrer tout");
        else
        if(estPlanningOccup())
            title = tr("Enregistrer tout - Location");
        else
            title = tr("Enregistrer tout - Réservation");

        if(!clientExiste(row, col))
        {
            QMessageBox::information(m_parent, title, "Vous devez identifier tous les clients avant l'enregistrement!");
            return;
        }
    }

    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    for(int i = 0; i < m_nouveauxChecksIn.count(); i++)
    {
        int row = (int)m_nouveauxChecksIn.at(i).y();
        int col = (int)m_nouveauxChecksIn.at(i).x();

        if(estOccupee(row, col))
        {
            occupation oc;
            oc.setCodeClient(data(row, col, IdClient).toInt());
            client cl(oc.codeClient());

            QDate dateDeb = date(col);
            QTime timeDeb = QTime::fromString(data(row, col, HeureEntree), Qt::ISODate);

            oc.setDatedEntree(QDateTime(dateDeb, timeDeb));

            int duree = data(row, col, ColSortie).toInt() - col + 1;

            oc.setDureeOccupation(duree);
            oc.setCout(data(row, col, TotalAPayer).toInt());
            oc.setPayee(data(row, col, TotalAPayer).toInt() - data(row, col, ResteAPayer).toInt());
            oc.setChambreOccupee(chambreDe(row));
            oc.setIdGroupe(data(row, col, Groupe_r).toInt());
            oc.setEnfAccMoinsDe15(data(row, col, NbEnfAccMoinsDe15).toInt());
            oc.setDestinationExacte(data(row, col, DestinationExacte));
            oc.setIdProfileClient(data(row, col, IdProfileClient).toInt());

            if(oc.estUnGroupe())
            {
                // s'il existe avance
                groupe gr(oc.idGroupe());
                if(gr.avanceActu() > 0)
                {
                    int montantVerse = gr.avanceActu();
                    int montantRetire = oc.reglerMontantTotal(montantVerse);
                    gr.setAvanceActu(gr.avanceActu() - montantRetire);
                    gr.enregistrer();

                    // apprêter un reçu pour ce réglement
                    // rechercher l'opération traitant de l'avance
                    operationService os;
                    QString condition = tr("%1 = %2 AND %3 = %4 AND %5 = '%6'").arg(os.idTypeOperationName()).arg(gr.idGroupe())
                                                                 .arg(os.idTypeRecuName()).arg(recuInitial::IdReservation)
                                                                 .arg(os.tableOperationName()).arg(gr.tableName());

                    QList<QSqlRecord> records;
                    records = InfosSurBD::enregistrements(os.tableName(), condition);
                    os = operationService(records.first());

                    QString message = QString("Réglement de la facture de location %1 par avance (groupe)").arg(oc.facture());
                    MesTables::enregistrerUneOperationService(*m_agent
                                                              , recuInitial::IdLocation
                                                              , now
                                                              , montantRetire
                                                              , message
                                                              , os.idModeDePayement()                                                              
                                                              , gr.idGroupe()
                                                              , occupation().tableName());
                }
            }

            MesTables::enregistrerOccupation(cl, oc, *m_agent);

            // joindre à la pièce
            pieceIdentiteClient pic(data(row, col, IdPieceIdentite).toInt());
            pic.setNumOccupation(oc.numOccupation());
            pic.enregistrer();

            showOccupation(oc);
        }else
        {
            // c'est une réservation
            reservation rv;
            rv.setCodeClient(data(row, col, IdClient).toInt());
            client cl(rv.codeClient());

            QDate dateDeb = date(col);
            QTime timeDeb = QTime::fromString(data(row, col, HeureEntree), Qt::ISODate);

            rv.setDatedEntree(QDateTime(dateDeb, timeDeb));
            rv.setDateDeDemande(Horloge::currentDateTime());

            int duree = data(row, col, ColSortie).toInt() - col + 1;

            rv.setDureeOccupation(duree);
            rv.setCout(data(row, col, TotalAPayer).toInt());
            rv.setAvance(data(row, col, TotalAPayer).toInt() - data(row, col, ResteAPayer).toInt());
            rv.setIdGroupe(data(row, col, Groupe_r).toInt());
            rv.setIdProfileClient(data(row, col, IdProfileClient).toInt());

            MesTables::enregistrerReservation(cl, rv, QStringList(chambreDe(row)), *m_agent);
            showReservation(rv);
        }
    }

    emit planningModifie(false);

    m_nouveauxChecksIn.clear();
}

void PiloteDePlanning::executerReservation()
{

    int row = m_tableWidget->currentIndex().row();

    if(QMessageBox::information(  m_parent
                                , "Exécuter une réservation"
                                , tr("Vous êtes sur le point d'exécuter la réservation de la chambre %1.\n\nDésirez-vous continuer ?").arg(chambreDe(row))
                                , "Oui", "Abandonner") == 0)
    {
        m_db->transaction();
        bool submitAll = true;

        m_itemsADeplacer.clear();
        m_rowOfCheckIn = -1;

        int col = m_tableWidget->currentIndex().column();

        // on exécute une réservation
        int colFin = colSortie(row, col);

        int id = data(row, col, IdTypeReservation).toInt();
        if(id <= 0)
        {
            // réservation pas enregistrée
            QMessageBox::information(m_parent, "Exécution d'une réservation", "Vous devez d'abord enregistrer la réservation, puis l'exécuter.");
            return;
        }

        QDateTime now = Horloge::currentDateTime();
        reservation rv(id);
        client cl(rv.codeClient());

        occupation oc;
        oc.setCodeClient(cl.codeDuClient());
        oc.setDatedEntree(now);
        oc.setDureeOccupation(rv.dureeOccupation());

        submitAll = submitAll && MesTables::effectuerReservation(rv, *m_agent, now, oc, chambreDe(row));

        int prixUnitaire = rv.cout() / rv.dureeOccupation();
        oc.setCout(prixUnitaire * oc.dureeOccupation());        

        int montantRetire = 0;
        int idTypeOperation = 0;        
        QString message;
        if(oc.estUnGroupe())
        {
            // s'il reste avance
            groupe gr(oc.idGroupe());
            if(gr.avanceActu() > 0)
            {
                int montantVerse = gr.avanceActu();
                montantRetire = oc.reglerMontantTotal(montantVerse);
                gr.setAvanceActu(gr.avanceActu() - montantRetire);
                gr.setFraisLocation(gr.fraisLocation() + montantRetire);
                submitAll = submitAll && gr.enregistrer();
                idTypeOperation = gr.idGroupe();
                message = QString("Réglement de la facture de location %1 par avance (groupe)").arg(oc.facture());
            }
        }else
        {
            montantRetire = rv.avance();
            idTypeOperation = oc.numOccupation();
            message = QString("Réglement de la facture de location %1 par avance").arg(oc.facture());
        }

        if(montantRetire > 0)
        {
            // apprêter un reçu pour ce réglement
            // rechercher l'opération traitant de l'avance
            operationService os;            

            int idOpAnt;
            QString tableTypeOperation;

            if(oc.estUnGroupe())
            {
                idOpAnt = oc.idGroupe();
                tableTypeOperation = groupe().tableName();                
            }else
            {
                idOpAnt = rv.numReservation();
                tableTypeOperation = reservation().tableName();
            }

            QString condition = tr("%1 = %2 AND %3 = %4 AND %5 = '%6'").arg(os.idTypeOperationName()).arg(idOpAnt)
                                                         .arg(os.idTypeRecuName()).arg(recuInitial::IdReservation)
                                                         .arg(os.tableOperationName()).arg(tableTypeOperation);

            QList<QSqlRecord> records;
            records = InfosSurBD::enregistrements(os.tableName(), condition);
            if(records.isEmpty())
            {
                m_db->rollback();
                QMessageBox::warning(m_parent, "Exécution d'une réservation", "Echec lors de l'exécution de la réservation : type opération non trouvé!");
                return;
            }
            os = operationService(records.first());

            submitAll = submitAll && MesTables::enregistrerUneOperationService(*m_agent
                                                                              , recuInitial::IdLocation
                                                                              , now
                                                                              , montantRetire
                                                                              , message
                                                                              , os.idModeDePayement()                                                                              
                                                                              , idTypeOperation
                                                                              , occupation().tableName());
        }        

        submitAll = submitAll && MesTables::enregistrerOccupation(cl, oc, *m_agent);

        if(submitAll)
        {
            m_db->commit();
            showReservation(rv, false);
            afficherInfosGenerales(col, colFin);

            emit occupationEnregistree(oc);
            emit factureModifiee();
        }
        else
            m_db->rollback();
    }
}

void PiloteDePlanning::lierAUnGroupe()
{
    // on suppose que l'occupation et la réservation n'est pas encore enregistrée

    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    int row = m_tableWidget->currentRow();
    int col = m_tableWidget->currentColumn();

    if(estOccupee(row, col))
    {
        occupation oc;
        BDChoisirUnClientDeGroupe * bd = new BDChoisirUnClientDeGroupe(oc, m_parent);
        bd->setWindowTitle("Lier à un groupe");
        if(bd->exec() == QDialog::Accepted)
        {
            client cl = bd->clientChoisi();
            oc = bd->occupationDuClient();

            pieceIdentiteClient pic = bd->pieceDuClient();
            pic.enregistrer();

            // réafficher l'espace réservé
            int colDebut = colEntree(row, col);
            int colFin = colSortie(row, col);

            setData(row, colDebut, IdClient, cl.codeDuClient());
            setData(row, colDebut, Nom, cl.nom());
            showValue(row, colDebut, tr("%1 (%2)").arg(cl.nom().toUpper()).arg(groupe(bd->idGroupe()).libelle()));

            setData(row, colFin, IdClient, cl.codeDuClient());
            setData(row, colFin, Nom, cl.nom());

            chambre ch(chambreDe(row));
            int prixTotal = prixChambreTTC(ch.idTypeChambre(), oc.idProfileClient()).prixTTC() * (colFin - colDebut + 1);

            setData(row, colDebut, TotalAPayer, QString::number(prixTotal));
            setData(row, colFin, TotalAPayer, QString::number(prixTotal));

            setData(row, colDebut, ResteAPayer, QString::number(prixTotal));
            setData(row, colFin, ResteAPayer, QString::number(prixTotal));

            setData(row, colDebut, NomComplet, cl.nomComplet());
            setData(row, colFin, NomComplet, cl.nomComplet());

            setData(row, colDebut, Groupe_r, bd->idGroupe());
            setData(row, colFin, Groupe_r, bd->idGroupe());

            setData(row, colDebut, Nom, cl.nom());
            setData(row, colFin, Nom, cl.nom());

            setData(row, colDebut, IdPieceIdentite, pic.idPieceIdentite());
            setData(row, colFin, IdPieceIdentite, pic.idPieceIdentite());

            setData(row, colDebut, IdProfileClient, oc.idProfileClient());
            setData(row, colFin, IdProfileClient, oc.idProfileClient());

            setData(row, colDebut, NbEnfAccMoinsDe15, oc.enfAccMoinsDe15());
            setData(row, colFin, NbEnfAccMoinsDe15, oc.enfAccMoinsDe15());

            setData(row, colDebut, DestinationExacte, oc.destinationExacte());
            setData(row, colFin, DestinationExacte, oc.destinationExacte());

            showEspaceReserve(row, colDebut, colFin);
        }

        delete bd;
    }else
    {
        BDChoisirUnClientDeGroupeSimple * bd = new BDChoisirUnClientDeGroupeSimple(m_parent);
        bd->setWindowTitle("Lier à un groupe");
        if(bd->exec() == QDialog::Accepted)
        {
            reservation rv;
            client cl = bd->clientChoisi();
            rv.setIdProfileClient(bd->idProfileClient());

            // réafficher l'espace réservé
            int colDebut = colEntree(row, col);
            int colFin = colSortie(row, col);

            setData(row, colDebut, IdClient, cl.codeDuClient());
            setData(row, colDebut, Nom, cl.nom());
            showValue(row, colDebut, tr("%1 (%2)").arg(cl.nom().toUpper()).arg(groupe(bd->idGroupe()).libelle()));

            setData(row, colFin, IdClient, cl.codeDuClient());
            setData(row, colFin, Nom, cl.nom());

            chambre ch(chambreDe(row));
            int prixTotal = prixChambreTTC(ch.idTypeChambre(), rv.idProfileClient()).prixTTC() * (colFin - colDebut + 1);

            setData(row, colDebut, TotalAPayer, QString::number(prixTotal));
            setData(row, colFin, TotalAPayer, QString::number(prixTotal));

            setData(row, colDebut, ResteAPayer, QString::number(prixTotal));
            setData(row, colFin, ResteAPayer, QString::number(prixTotal));

            setData(row, colDebut, NomComplet, cl.nomComplet());
            setData(row, colFin, NomComplet, cl.nomComplet());

            setData(row, colDebut, Groupe_r, bd->idGroupe());
            setData(row, colFin, Groupe_r, bd->idGroupe());

            setData(row, colDebut, Nom, cl.nom());
            setData(row, colFin, Nom, cl.nom());

            setData(row, colDebut, IdProfileClient, rv.idProfileClient());
            setData(row, colFin, IdProfileClient, rv.idProfileClient());

            showEspaceReserve(row, colDebut, colFin);
        }

        delete bd;
    }
}

void PiloteDePlanning::afficherInfosGenerales(int col)
{
    if(dayIsIn(date(col)))
    {
        int nbDispo = 0;
        int nbReservee = 0;
        int nbOccupee = 0;

        if(m_typePlanning == PlanningDeReservation)
        {
            for(int row = IDVIDE + 1; row < m_tableWidget->rowCount(); row++)
            {
                if(estReservee(row, col))
                    nbReservee++;

                if(estDisponible(row, col))
                    nbDispo++;
            }

            showDisponibilite(col, nbDispo);
            showNbReservee(col, nbReservee);
        }

        if(m_typePlanning == PlanningDOccupation)
        {
            for(int row = IDVIDE + 1; row < m_tableWidget->rowCount(); row++)
            {
                if(estOccupee(row, col))
                    nbOccupee++;

                if(estDisponible(row, col))
                    nbDispo++;
            }

            showDisponibilite(col, nbDispo);
            showNbOccupee(col, nbOccupee);
        }

        if(m_typePlanning == PlanningMixte)
        {
            for(int row = IDVIDE + 1; row < m_tableWidget->rowCount(); row++)
            {
                if(estOccupee(row, col))
                    nbOccupee++;

                if(estReservee(row, col))
                    nbReservee++;

                if(estDisponible(row, col))
                    nbDispo++;
            }

            showDisponibilite(col, nbDispo);
            showNbOccupee(col, nbOccupee);
            showNbReservee(col, nbReservee);
        }
    }
}

void PiloteDePlanning::afficherInfosGenerales(int colDeb, int colFin)
{
    for(int col = colDeb; col <= colFin; col++)
    {
        afficherInfosGenerales(col);
    }
}

void PiloteDePlanning::afficherInfosGenerales()
{
    afficherInfosGenerales(0, m_tableWidget->columnCount() - 1);
}

void PiloteDePlanning::showDisponibilite(int col, int nb)
{
    showCell(IDDISPONIBLE, col, nb);
}

void PiloteDePlanning::showNbOccupee(int col, int nb)
{
    showCell(IDOCCUPEE, col, nb);
}

void PiloteDePlanning::showNbReservee(int col, int nb)
{
    showCell(IDRESERVEE, col, nb);
}

void PiloteDePlanning::setActionsEnabled(bool enabled)
{
    m_actionCheckIn->setEnabled(enabled);
    m_actionCheckOut->setEnabled(enabled);
    m_actionConfirmerSortie->setEnabled(enabled);
    m_actionIdentifierClient->setEnabled(enabled);
    m_actionAnnulerReserv->setEnabled(enabled);
    m_actionFacturerClient->setEnabled(enabled);
    m_actionDebuterDeplacement->setEnabled(enabled);
    m_actionTerminerDeplacement->setEnabled(enabled);
    m_actionDebuterNettoyage->setEnabled(enabled);
    m_actionTerminerNettoyage->setEnabled(enabled);
    m_actionANettoyer->setEnabled(enabled);
    m_actionNouveauCheckOut->setEnabled(enabled);
    m_actionReserver->setEnabled(enabled);
    m_actionVoirDetailsSurClient->setEnabled(enabled);
    m_actionEnregistrer->setEnabled(enabled);
    m_actionOccuper->setEnabled(enabled);
    m_actionImprimerFacture->setEnabled(enabled);
    m_actionLierAUnGroupe->setEnabled(enabled);
    m_actionExecuterReserv->setEnabled(enabled);
}

void PiloteDePlanning::verifierZoneValide(QModelIndex index)
{
    m_estHorsZoneChambre = estHorsZoneChambre(index.row(), index.column());

    if(m_estHorsZoneChambre)
    {
        setActionsEnabled(false);
    }
}

void PiloteDePlanning::adapterLimitesDuPlanning()
{
    QDate dateMin = m_date_debut;
    QDate dateMax = m_date_fin;

    // principe : réculer les bornes du planning pour afficher tout
    // rechercher min
    // occupations (min)
    occupation oc_ref;
    QString condition1;
    if(dayIsIn(m_date_debut))
    {
        condition1 = tr("%1 = %2")
                       .arg(oc_ref.termineeName())
                       .arg(false);
    }else
    {
        condition1 = tr("'%1' BETWEEN DATE(%2) AND ADDDATE(DATE(%2), %3)")
                       .arg(m_date_debut.toString(Qt::ISODate))
                       .arg(oc_ref.dateOccupName())
                       .arg(oc_ref.dureeOccupName());
    }

    QList<QSqlRecord> m_recordOccupMin;
    m_recordOccupMin = InfosSurBD::enregistrements(Occupation::Libelle, condition1);

    foreach(QSqlRecord r, m_recordOccupMin)
    {
        occupation oc(r);
        if(oc.datedEntree().date() < dateMin)
        {
            dateMin = oc.datedEntree().date();
        }
    }

    // reservations (min)
    reservation rv_ref;
    QString condition2 = tr("'%1' BETWEEN DATE(%2) AND ADDDATE(DATE(%2), %3)")
                         .arg(m_date_debut.toString(Qt::ISODate))
                         .arg(rv_ref.dateOccupationName())
                         .arg(rv_ref.dureeOccupName());

    QList<QSqlRecord> m_recordReservMin;
    m_recordReservMin = InfosSurBD::enregistrements(Reservation::Libelle, condition2);

    foreach(QSqlRecord r, m_recordReservMin)
    {
        reservation rv(r);
        if(rv.datedEntree().date() < dateMin)
        {
            dateMin = rv.datedEntree().date();
        }
    }

    m_date_debut = dateMin;

    // rechercher max
    // occupations (max)
    occupation oc_ref1;
    QString condition3 = tr("'%1' BETWEEN DATE(%2) AND ADDDATE(DATE(%2), %3)")
                         .arg(m_date_fin.toString(Qt::ISODate))
                         .arg(oc_ref1.dateOccupName())
                         .arg(oc_ref1.dureeOccupName());

    QList<QSqlRecord> m_recordOccupMin1;
    m_recordOccupMin1 = InfosSurBD::enregistrements(Occupation::Libelle, condition3);

    foreach(QSqlRecord r, m_recordOccupMin1)
    {
        occupation oc(r);
        if(oc.datedSortie().date() > dateMax)
        {
            dateMax = oc.datedSortie().date();
        }
    }

    // reservations (max)
    reservation rv_ref1;
    QString condition4 = tr("'%1' BETWEEN DATE(%2) AND ADDDATE(DATE(%2), %3)")
                         .arg(m_date_fin.toString(Qt::ISODate))
                         .arg(rv_ref1.dateOccupationName())
                         .arg(rv_ref1.dureeOccupName());

    QList<QSqlRecord> m_recordReservMin1;
    m_recordReservMin1 = InfosSurBD::enregistrements(Reservation::Libelle, condition4);

    foreach(QSqlRecord r, m_recordReservMin1)
    {
        reservation rv(r);
        if(rv.datedSortie().date() > dateMax)
        {
            dateMax = rv.datedSortie().date();
        }
    }

    m_date_fin = dateMax;

    // écart de 10 jours de la fin si moins que ça
    QDate now = Horloge::currentDate();
    if(dayIsIn(now))
    {
        int ecartFin = now.daysTo(m_date_fin);
        if(ecartFin < 10)
        {
            int reste = 10 - ecartFin;
            m_date_fin = m_date_fin.addDays(reste);
        }
    }
}

void PiloteDePlanning::adapterLimitesDuPlanningOccup()
{
    QDate dateMin = m_date_debut;
    QDate dateMax = m_date_fin;

    // principe : réculer les bornes du planning pour afficher tout
    // rechercher min
    // occupations (min)
    occupation oc_ref;

    QString condition1 =  tr("'%1' BETWEEN DATE(%2) AND ADDDATE(DATE(%2), %3)")
                           .arg(m_date_debut.toString(Qt::ISODate))
                           .arg(oc_ref.dateOccupName())
                           .arg(oc_ref.dureeOccupName());

    QList<QSqlRecord> m_recordOccupMin;
    m_recordOccupMin = InfosSurBD::enregistrements(Occupation::Libelle, condition1);

    foreach(QSqlRecord r, m_recordOccupMin)
    {
        occupation oc(r);
        if(oc.datedEntree().date() < dateMin)
        {
            dateMin = oc.datedEntree().date();
        }
    }

    // occupations (max)
    occupation oc_ref1;
    QString condition3 = tr("'%1' BETWEEN DATE(%2) AND ADDDATE(DATE(%2), %3)")
                         .arg(m_date_fin.toString(Qt::ISODate))
                         .arg(oc_ref1.dateOccupName())
                         .arg(oc_ref1.dureeOccupName());

    QList<QSqlRecord> m_recordOccupMin1;
    m_recordOccupMin1 = InfosSurBD::enregistrements(Occupation::Libelle, condition3);

    foreach(QSqlRecord r, m_recordOccupMin1)
    {
        occupation oc(r);
        if(oc.datedSortie().date() > dateMax)
        {
            dateMax = oc.datedSortie().date();
        }
    }

    m_date_debut = dateMin;
    m_date_fin = dateMax;
}

void PiloteDePlanning::adapterLimitesDuPlanningReserv()
{
    QDate dateMin = m_date_debut;
    QDate dateMax = m_date_fin;

    // reservations (min)
    reservation rv_ref;
    QString condition2 = tr("'%1' BETWEEN DATE(%2) AND ADDDATE(DATE(%2), %3)")
                         .arg(m_date_debut.toString(Qt::ISODate))
                         .arg(rv_ref.dateOccupationName())
                         .arg(rv_ref.dureeOccupName());

    QList<QSqlRecord> m_recordReservMin;
    m_recordReservMin = InfosSurBD::enregistrements(Reservation::Libelle, condition2);

    foreach(QSqlRecord r, m_recordReservMin)
    {
        reservation rv(r);
        if(rv.datedEntree().date() < dateMin)
        {
            dateMin = rv.datedEntree().date();
        }
    }

    m_date_debut = dateMin;

    // reservations (max)
    reservation rv_ref1;
    QString condition4 = tr("'%1' BETWEEN DATE(%2) AND ADDDATE(DATE(%2), %3)")
                         .arg(m_date_fin.toString(Qt::ISODate))
                         .arg(rv_ref1.dateOccupationName())
                         .arg(rv_ref1.dureeOccupName());

    QList<QSqlRecord> m_recordReservMin1;
    m_recordReservMin1 = InfosSurBD::enregistrements(Reservation::Libelle, condition4);

    foreach(QSqlRecord r, m_recordReservMin1)
    {
        reservation rv(r);
        if(rv.datedSortie().date() > dateMax)
        {
            dateMax = rv.datedSortie().date();
        }
    }

    m_date_debut = dateMin;
    m_date_fin = dateMax;
}

QDate PiloteDePlanning::dateDebut()const
{
    return m_date_debut;
}

QDate PiloteDePlanning::dateFin()const
{
    return m_date_fin;
}

bool PiloteDePlanning::estPlanningMixte()
{
    return m_typePlanning == PlanningMixte;
}

bool PiloteDePlanning::estPlanningOccup()
{
    return m_typePlanning == PlanningDOccupation;
}

bool PiloteDePlanning::estPlanningReserv()
{
    return m_typePlanning == PlanningDeReservation;
}

void PiloteDePlanning::showChambresIndispo(QDate debut, QDate fin, QString ch)
{
    int nbDays = debut.daysTo(fin);
    for(int i = 0; i <= nbDays; i++)
    {
        int col = column(debut.addDays(i));
        int row = this->row(ch);

        if(dayIsIn(debut.addDays(i)) && m_chambres_str.contains(ch))
        {
            initItemIndispo(row, col);
            afficherInfosGenerales(col);
        }
    }
}

void PiloteDePlanning::showChambresDispo(QDate debut, QDate fin, QString ch)
{
    int nbDays = debut.daysTo(fin);
    for(int i = 0; i <= nbDays; i++)
    {
        int col = column(debut.addDays(i));
        int row = this->row(ch);

        if(dayIsIn(debut.addDays(i)) && m_chambres_str.contains(ch))
        {
            initItemDispo(row, col);
            afficherInfosGenerales(col);
        }
    }
}

void PiloteDePlanning::imprimerFacture()
{
    m_itemsADeplacer.clear();
    m_rowOfCheckIn = -1;

    int numOccup = data(m_tableWidget->currentRow(), m_tableWidget->currentColumn()
                        , IdTypeReservation).toInt();

    occupation oc(numOccup);
    emit imprimerOccupation(oc);
}

void PiloteDePlanning::updateEtatActionImprimerFacture(QModelIndex index)
{
    if(m_estHorsZoneChambre)
        return;

    if(data(index.row(), index.column(), IdTypeReservation).toInt() > 0)
    {
        m_actionImprimerFacture->setEnabled(true);
    }else
    {
        m_actionImprimerFacture->setEnabled(false);
    }
}

void PiloteDePlanning::updateEtatActionFacturerClient(QModelIndex index)
{
    /*if(m_estHorsZoneChambre)
        return;

    if(data(index.row(), index.column(), IdTypeReservation).toInt() > 0)
    {
        // Facturer uniquement les réservations non exécutées et en cours
        QDate now = Horloge::currentDate();
        int colDebut = data(index.row(), index.column(), ColEntree).toInt();
        QDate date = m_date_debut.addDays(colDebut);

        bool executee = (bool)data(index.row(), index.column(), Executee).toInt();
        m_actionFacturerClient->setEnabled(!executee && date >= now);
    }else
    {
        m_actionFacturerClient->setEnabled(false);
    }*/
}

void PiloteDePlanning::rafraichirLocationsEnCours()
{
    emit typeOperation("Chargement des locations...");

    occupation oc1;
    QString condition = tr("%1 = %2").arg(oc1.termineeName()).arg(false);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(oc1.tableName(), condition);

    emit dataATraiter(records.count());

    foreach(QSqlRecord r, records)
    {
        occupation oc(r);
        showOccupation(oc);

        emit opElt();
    }
}

void PiloteDePlanning::rafraichirReservationsEnCours()
{
    emit typeOperation("Chargement des réservations...");

    reservation rv1;
    QString condition = tr("ADDDATE(%1, %2) >= '%3'")
                        .arg(rv1.dateOccupationName())
                        .arg(rv1.dureeOccupName())
                        .arg(Horloge::currentDate().toString(Qt::ISODate));

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(rv1.tableName(), condition);

    emit dataATraiter(records.count());

    foreach(QSqlRecord r, records)
    {
        reservation rv(r);
        showReservation(rv);

        emit opElt();
    }
}

void PiloteDePlanning::enregisterTout()
{
    enregistrer();
}
