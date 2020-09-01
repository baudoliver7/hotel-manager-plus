#include "MdiServiceReception.h"
#include "ui_MdiServiceReception.h"

MdiServiceReception::MdiServiceReception(const recepteur * r, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MdiServiceReception)
{
    ui->setupUi(this);
    connect(ui->lineEditTypeChAOccuper, SIGNAL(textChanged(QString)), this, SLOT(chargerIdentifiantsChDispo_occup())); // on charge les identifiants avant d'actualiser
    connect(ui->lineEditTypeChReserv, SIGNAL(textChanged(QString)), this, SLOT(chargerIdentifiantsChDispo_reserv())); // on charge les identifiants avant d'actualiser

    m_clientEnCours = new client();
    m_recepteur = new recepteur(*r);
    m_fermer = false;

    afficherNumeroClient();
    afficherNumeroReservation();

    souhaiterBienvenue();
    afficherDateDeConnection();
    initialiserChambreGV();
    chargerTypesDeChambre();

    initialiserTabWidgetEnregistrement();
    actualiserEtatBtnEnregistrer();

    connect(ui->lineEditContactOcc, SIGNAL(textChanged(QString)), this, SLOT(actualiserEtatBtnEnregistrer()));
    connect(ui->lineEditNomOcc, SIGNAL(textChanged(QString)), this, SLOT(actualiserEtatBtnEnregistrer()));
    connect(ui->comboBoxIdentifiantCh, SIGNAL(currentIndexChanged(QString)), this, SLOT(actualiserEtatBtnEnregistrer()));

    connect(ui->lineEditDateOccupReserv, SIGNAL(textChanged(QString)), this, SLOT(chargerIdentifiantsChDispo_reserv())); // on charge les identifiants avant d'actualiser
    connect(ui->lineEditContactReserv, SIGNAL(textChanged(QString)), this, SLOT(actualiserEtatBtnEnregistrer()));
    connect(ui->lineEditNomReserv, SIGNAL(textChanged(QString)), this, SLOT(actualiserEtatBtnEnregistrer()));
    connect(ui->comboBoxIdentifiantChReserv, SIGNAL(currentIndexChanged(QString)), this, SLOT(actualiserEtatBtnEnregistrer()));

    initialiserCompagnonFidele();
}

MdiServiceReception::~MdiServiceReception()
{
    delete ui;
    delete m_piloteChambreGV;
    delete m_scene;
    delete m_CompagnonFidele;
    delete m_sceneCpgFidele;
    delete m_recepteur;
    m_chambres.clear();
    delete m_clientEnCours;
}

void MdiServiceReception::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MdiServiceReception::closeEvent(QCloseEvent *e)
{
    if(!m_fermer)
    {
        if(!seDeconnecter())
        {
            e->ignore();
        }else
        {
            emit closed();
        }
    }
}

void MdiServiceReception::resizeEvent(QResizeEvent * e)
{          
    QWidget::resizeEvent(e);
    switch(e->type())
    {
    case QResizeEvent::Resize:
        rafraichir();
        break;
    default:
        break;
    }
}

void MdiServiceReception::showEvent(QShowEvent *e)
{
    QWidget::showEvent(e);
    rafraichir();
}

bool MdiServiceReception::seDeconnecter()
{
    bool deconnecte = false;
    QString title = tr("Se déconnecter du compte %1").arg(m_recepteur->login());
    if(QMessageBox::question(this, title, "Désirez-vous vous déconnecter?"
                             , "Oui", "Non") == 0)
    {
        deconnecte = true;
    }

    return deconnecte;
}

void MdiServiceReception::souhaiterBienvenue()
{
    QString message = tr("Bienvenue %1!").arg(m_recepteur->prenoms());
    ui->label_bienvenue->setText(message);
}

void MdiServiceReception::afficherDateDeConnection()
{
    QString message = tr("Vous êtes connecté depuis le %1").arg(QDateTime::currentDateTime().toString(Qt::SystemLocaleLongDate));
    ui->label_heureDeConnection->setText(message);
}

void MdiServiceReception::initialiserTabWidgetEnregistrement()
{
    afficherTabOccuperUneChambre();
    initialiserTabOccuperUneChambre();
    initialiserTabReserverUneChambre();
}

void MdiServiceReception::initialiserTabOccuperUneChambre()
{
    ui->MasculinOccup->setChecked(true);
    ui->lineEditNomOcc->setText(QString());
    ui->lineEditContactOcc->setText(QString());
    ui->lineEditPrenomOcc->setText(QString());

    ui->comboBoxDureeOcc->setCurrentIndex(0); // une nuit
    ui->spinBoxNbJoursOcc->setEnabled(false);
    ui->spinBoxNbJoursOcc->setValue(1);

    chargerIdentifiantsChDispo_occup();
    chargerTypesClient();
    chargerPrixDeChambre();
}

void MdiServiceReception::initialiserTabReserverUneChambre()
{
    ui->MasculinReserv->setChecked(true);
    ui->lineEditNomReserv->setText(QString());
    ui->lineEditContactReserv->setText(QString());
    ui->lineEditPrenomReserv->setText(QString());
    ui->lineEditDateOccupReserv->setText(QString());

    ui->comboBoxDureeJoursReserv->setCurrentIndex(0); // une nuit
    ui->spinBoxNbJoursReserv->setEnabled(false);
    ui->spinBoxNbJoursReserv->setValue(1);
}

void MdiServiceReception::initialiserChambreGV()
{
    m_scene = new QGraphicsScene(ui->chambreGraphicsView);
    ui->chambreGraphicsView->setScene(m_scene);

    ui->chambreGraphicsView->setAlignment(Qt::AlignCenter);
    ui->chambreGraphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    ui->chambreGraphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter);

    m_piloteChambreGV = new PiloteChambreGraphicView(m_scene);

    QList<QSqlRecord> records;
    records << InfosSurBD::enregistrements(chambre::Libelle);

    for(int i = 0; i < records.count(); i++)
    {
        Chambre * ch = new Chambre(records.at(i));
        m_scene->addItem(ch);
        m_scene->addItem(ch->textItem());
        ch->setVisible(false);
        m_chambres.append(ch);
    }

    afficherLesChambres();
}

void MdiServiceReception::initialiserCompagnonFidele()
{
    bool mute = true;
    QFile file("options.txt");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&file);
        QString options = in.readLine();
        mute = (bool)options.split(" ").last().toInt();
        file.close();
    }    

    m_sceneCpgFidele = new QGraphicsScene();

    ui->compagnonGraphicsView->setScene(m_sceneCpgFidele);
    m_CompagnonFidele = new CompagnonFidele(m_sceneCpgFidele, m_recepteur, ui->historiqueDesMsgs);
    m_CompagnonFidele->setMuteVolume(mute);
    connect(this, SIGNAL(bdModifiee()), m_CompagnonFidele, SLOT(chargerInfos()));
    connect(m_CompagnonFidele, SIGNAL(etatChambreModifie()), this, SLOT(actualiserFenetre()));

    ui->tabWidgetCptService->setCurrentIndex(0);

    ui->tableWidgetSuggestions->setColumnHidden(ID, true);
    ui->tableWidgetSuggestions->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->tableWidgetSuggestions->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(updateBtnCharge(QModelIndex)));
    ui->btn_charger->setEnabled(false);
    ui->tabWidgetCptService->removeTab(TAB_SUGG);
}

void MdiServiceReception::afficherLesChambres()
{
    // effacer toutes les chambres
    Afficheur::effacerDesChambres(m_chambres);

    m_scene->setSceneRect(  0
                          , 0
                          , ui->chambreGraphicsView->size().width()  - 5
                          , ui->chambreGraphicsView->size().height() - 5 );

    // afficher les chambres du type actuel
    m_piloteChambreGV->afficher(chambres(m_typeDeChambreActif));
}

void MdiServiceReception::actualiserFenetre()
{
    // actualiser onglet occupation
    ui->lineEditTypeChAOccuper->setText(m_typeDeChambreActif);
    chargerPrixDeChambre();
    chargerIdentifiantsChDispo_occup();

    // actualiser onglet reservation
    ui->lineEditTypeChReserv->setText(m_typeDeChambreActif);
    chargerIdentifiantsChDispo_reserv();

    // afficher les chambres
    afficherLesChambres();
}

void MdiServiceReception::rafraichir()
{
    // effacer toutes les chambres
    Afficheur::effacerDesChambres(m_chambres);

    m_scene->setSceneRect(  0
                          , 0
                          , ui->chambreGraphicsView->size().width()  - 5
                          , ui->chambreGraphicsView->size().height() - 5 );

    // afficher les chambres du type actuel
    m_piloteChambreGV->rafraichir();
}

void MdiServiceReception::on_btn_enregistrer_clicked()
{
    if(tabOccuperActif())
    {
        // enregistrer occupation
        enregistrerOccupationEnCours();
    }else
    {
        // enregistrer réservation
        enregistrerReservationEnCours();
    }
}

bool MdiServiceReception::tabOccuperActif()
{
    if(ui->tabWidgetEnregistrement->currentIndex() == OCCUPER_UNE_CHAMBRE)
    {
        return true;
    }

    return false;
}

void MdiServiceReception::enregistrerOccupationEnCours()
{
    client cl;
    cl.setCode(m_clientEnCours->codeDuClient());

    cl.setNom(ui->lineEditNomOcc->text());
    cl.setPrenoms(ui->lineEditPrenomOcc->text());
    cl.setContacts(ui->lineEditContactOcc->text());
    cl.setTypeDeClient(ui->comboBoxTypeClient->currentText());
    cl.setSexe(estUnHomme_occup());

    if(cl.enregistrer())
    {
        QDateTime dateEntree = QDateTime::currentDateTime();
        occupation oc;
        oc.setChambreOccupee(ui->comboBoxIdentifiantCh->currentText());
        oc.setCodeOccupant(cl.codeDuClient());
        oc.setDatedEntree(dateEntree);
        oc.setDureeOccupation(ui->spinBoxNbJoursOcc->value());
        oc.setCout(ui->lineEditPrixTotal->text().toLong());

        if(oc.enregistrer())
        {
            recevoir rv;
            rv.setCodeClient(cl.codeDuClient());
            rv.setDateDeReception(dateEntree);
            rv.setMatriculeRecepteur(m_recepteur->matricule());

            if(rv.enregistrer())
            {
                m_chambres.at(oc.chambreOccupee())->actualiser(); // actualiser état
                m_chambres.actualiser(); // ranger
                afficherLesChambres();
                afficherNumeroClient();
                initialiserTabOccuperUneChambre();
                emit bdModifiee();
                return;
            }else
            {
                oc.supprimer(); // ne pas supprimer le client
                QMessageBox::information(this, "Occuper une chambre", "Une erreur s'est produite lors de l'enregistrement de la réception!");
            }
        }else
        {
            QMessageBox::information(this, "Occuper une chambre", "Une erreur s'est produite lors de l'enregistrement de l'occupation!");
        }
    }else
    {
        QMessageBox::information(this, "Occuper une chambre", "Une erreur s'est produite lors de l'enregistrement du client!");
    }
}

void MdiServiceReception::enregistrerReservationEnCours()
{
    client cl;
    cl.setCode(m_clientEnCours->codeDuClient());

    cl.setNom(ui->lineEditNomReserv->text());
    cl.setPrenoms(ui->lineEditPrenomReserv->text());
    cl.setContacts(ui->lineEditContactReserv->text());
    cl.setSexe(estUnHomme_reserv());

    if(cl.enregistrer())
    {
        QDateTime datedeDemande = QDateTime::currentDateTime();
        reservation reserv;
        reserv.setChambreReservee(ui->comboBoxIdentifiantChReserv->currentText());
        reserv.setCodeReservant(cl.codeDuClient());
        reserv.setDateDeDemande(datedeDemande);
        reserv.setDatedEntree(QDate::fromString(ui->lineEditDateOccupReserv->text(), Qt::ISODate));
        reserv.setDureeOccupation(ui->spinBoxNbJoursReserv->value());
        reserv.setAnnuler(false);
        reserv.setEffectuer(false);

        if(reserv.enregistrer())
        {
            recevoir rv;
            rv.setCodeClient(cl.codeDuClient());
            rv.setDateDeReception(datedeDemande);
            rv.setMatriculeRecepteur(m_recepteur->matricule());

            if(rv.enregistrer())
            {
                afficherNumeroReservation();
                initialiserTabReserverUneChambre();
                emit bdModifiee();
                return;
            }else
            {
                reserv.supprimer(); // ne pas supprimer le client
            }
        }
    }

    QMessageBox::information(this, "Réserver une chambre", "Une erreur s'est produite lors de l'enregistrement de la réservation!");
}

void MdiServiceReception::chargerTypesDeChambre()
{
    ui->comboBoxTypeCh->addItems(initialDeChambre::typesDisponibles());
    m_typeDeChambreActif = ui->comboBoxTypeCh->currentText();

    ui->lineEditTypeChAOccuper->setText(m_typeDeChambreActif);
}

void MdiServiceReception::chargerTypesClient()
{
    ui->comboBoxTypeClient->clear();
    ui->comboBoxTypeClient->addItems(client::listeTypeDeClientStr());
}

void MdiServiceReception::on_comboBoxDureeOcc_currentIndexChanged(int index)
{
    if(index == 0) // une nuit
    {
        ui->spinBoxNbJoursOcc->setMinimum(1);
        ui->spinBoxNbJoursOcc->setValue(1);
        ui->spinBoxNbJoursOcc->setEnabled(false);
    }else // un séjour
    {
        ui->spinBoxNbJoursOcc->setMinimum(2);
        ui->spinBoxNbJoursOcc->setEnabled(true);
    }
}

void MdiServiceReception::on_btn_contactOcc_clicked()
{
    ouvrirBoiteAContacts(ui->lineEditContactOcc);
}

void MdiServiceReception::ouvrirBoiteAContacts(QLineEdit *lineEdit)
{
    DialogContact * dbContact = new DialogContact(lineEdit->text(), this);

    if(dbContact->exec())
    {
        lineEdit->setText(dbContact->getContact());
    }

    delete dbContact;
}

void MdiServiceReception::afficherNumeroClient()
{
    static int numero = 0;

    numero++;
    ui->label_NumeroClient->setText(tr("Client N° %1").arg(numero));
}

void MdiServiceReception::afficherNumeroReservation()
{
    static int numero = 0;

    numero++;
    ui->label_NumeroReservation->setText(tr("Réservation N° %1").arg(numero));
}

void MdiServiceReception::afficherPrixTotal()
{
    long prix = ui->lineEditPrixNuit->text().toLong() * ui->spinBoxNbJoursOcc->value();

    ui->lineEditPrixTotal->setText(QString::number(prix));
}

void MdiServiceReception::chargerPrixDeChambre()
{
    client::TypeDeClient typeClient = client::typeDeClient(ui->comboBoxTypeClient->currentText());
    QString prix = QString::number(tarif(m_typeDeChambreActif).prixUnitaire(typeClient));

    ui->lineEditPrixNuit->setText(prix);
    afficherPrixTotal();
}

void MdiServiceReception::on_comboBoxTypeCh_currentIndexChanged(QString type)
{
    m_typeDeChambreActif = type;

    actualiserFenetre();
}

ListeDeChambres<Chambre *> MdiServiceReception::chambres(QString type)
{  
    ListeDeChambres<Chambre *> liste;
    for(int i = 0; i < m_chambres.count(); i++)
    {
        if(m_chambres.at(i)->typeStr() == type)
        {
            liste.append(m_chambres.at(i));
        }
    }

    return liste;
}

void MdiServiceReception::on_comboBoxTypeClient_currentIndexChanged(QString )
{
    chargerPrixDeChambre();
}

void MdiServiceReception::on_spinBoxNbJoursOcc_valueChanged(int )
{
    afficherPrixTotal();
    chargerIdentifiantsChDispo_occup();
}


void MdiServiceReception::on_btn_initialiser_clicked()
{
    if(tabOccuperActif())
    {
        initialiserTabOccuperUneChambre();
    }else
    {
        initialiserTabReserverUneChambre();
    }
}

void MdiServiceReception::chargerIdentifiantsChDispo_occup()
{
    QStringList l;
    l << MesTables::selectionnerChambresDisponibles(m_typeDeChambreActif, ui->spinBoxNbJoursOcc->value());
    arrangerParOrdreCroissant(l);

    ui->comboBoxIdentifiantCh->clear();
    ui->comboBoxIdentifiantCh->addItems(l);
}

void MdiServiceReception::chargerIdentifiantsChDispo_reserv()
{
    QDate dateOccup = QDate::fromString(ui->lineEditDateOccupReserv->text());

    QStringList l;
    l << MesTables::selectionnerChambresDisponibles(m_typeDeChambreActif, dateOccup, ui->spinBoxNbJoursReserv->value());
    arrangerParOrdreCroissant(l);

    ui->comboBoxIdentifiantChReserv->clear();
    ui->comboBoxIdentifiantChReserv->addItems(l);
}

void MdiServiceReception::actualiserEtatBtnEnregistrer()
{
    bool enabled;
    if(tabOccuperActif())
    {
        DialogContact dbContact(ui->lineEditContactOcc->text(), 0);
        enabled = !(dbContact.estVide() || ui->lineEditNomOcc->text().isEmpty()
                         || ui->comboBoxIdentifiantCh->currentText().isEmpty());
    }else
    {
        DialogContact dbContact(ui->lineEditContactReserv->text(), 0);
        enabled = !(dbContact.estVide() || ui->lineEditNomReserv->text().isEmpty()
                         || ui->comboBoxIdentifiantChReserv->currentText().isEmpty()
                         || ui->lineEditDateOccupReserv->text().isEmpty());
    }


    ui->btn_enregistrer->setEnabled(enabled);
}

void MdiServiceReception::on_btn_calendrier_clicked()
{
    ouvrirCalendrier();
}

void MdiServiceReception::on_btn_contactReserv_clicked()
{
    ouvrirBoiteAContacts(ui->lineEditContactReserv);
}

void MdiServiceReception::ouvrirCalendrier()
{
    DialogCalendar * calendar = new DialogCalendar(this);

    if(calendar->exec())
    {
        ui->lineEditDateOccupReserv->setText(calendar->dateSeclectionnee().toString(Qt::ISODate));
    }

    delete calendar;
}

void MdiServiceReception::on_comboBoxDureeJoursReserv_currentIndexChanged(int index)
{
    if(index == 0) // une nuit
    {
        ui->spinBoxNbJoursReserv->setEnabled(false);
        ui->spinBoxNbJoursReserv->setMinimum(1);
        ui->spinBoxNbJoursReserv->setValue(1);
    }else
    {
        // un séjour
        ui->spinBoxNbJoursReserv->setEnabled(true);
        ui->spinBoxNbJoursReserv->setMinimum(2);
    }
}

void MdiServiceReception::on_spinBoxNbJoursReserv_valueChanged(int )
{
    chargerIdentifiantsChDispo_reserv();
}

void MdiServiceReception::arrangerParOrdreCroissant(QStringList &l)
{
    for(int i = 0; i < l.count()-1; i++)
    {
        for(int j = i+1; j < l.count();j++)
        {
            if(l.at(i) > l.at(j))
            {
                l.swap(i, j);
            }
        }
    }
}

void MdiServiceReception::remplirOccuperUneChambre(client cl)
{
    afficherTabOccuperUneChambre();
    ui->lineEditNomOcc->setText(cl.nom());
    ui->lineEditPrenomOcc->setText(cl.prenoms());
    ui->lineEditContactOcc->setText(cl.contacts());
    ui->MasculinOccup->setChecked(cl.homme());

    if(!cl.typeDeClientStr().isEmpty())
    {
        ui->comboBoxTypeClient->setCurrentIndex(cl.typeDeClient());
    }

    m_clientEnCours->setCode(cl.codeDuClient());
}

void MdiServiceReception::remplirReserverUneChambre(client cl)
{
    afficherTabReserverUneChambre();
    ui->lineEditNomReserv->setText(cl.nom());
    ui->lineEditPrenomReserv->setText(cl.prenoms());
    ui->lineEditContactReserv->setText(cl.contacts());
    ui->MasculinReserv->setChecked(cl.homme());

    m_clientEnCours->setCode(cl.codeDuClient());
}

bool MdiServiceReception::estUnHomme_occup()
{
    return ui->MasculinOccup->isChecked();
}

bool MdiServiceReception::estUnHomme_reserv()
{
    return ui->MasculinReserv->isChecked();
}

void MdiServiceReception::afficherTabOccuperUneChambre()
{
    ui->tabWidgetEnregistrement->setCurrentIndex(OCCUPER_UNE_CHAMBRE);
}

void MdiServiceReception::afficherTabReserverUneChambre()
{
    ui->tabWidgetEnregistrement->setCurrentIndex(RESEVER_UNE_CHAMBRE);
}

void MdiServiceReception::remplirOccuperUneChambre(reservation rv)
{
    client cl(rv.codeReservant());

    remplirOccuperUneChambre(cl);

    Chambre ch(rv.chambreReservee());
    ui->comboBoxTypeCh->setCurrentIndex(ch.typeCh());

    QStringList l = MesTables::selectionnerChambresDisponibles(ch.typeStr(), rv.dureeOccupation());
    QString currentText = ui->comboBoxIdentifiantCh->currentText();
    ui->comboBoxIdentifiantCh->setCurrentIndex(l.indexOf(currentText));

    if(rv.dureeOccupation() == 1)
    {
        ui->comboBoxDureeOcc->setCurrentIndex(0);
    }else
    {
        ui->comboBoxDureeOcc->setCurrentIndex(1);
        ui->spinBoxNbJoursOcc->setValue(rv.dureeOccupation());
    }

    m_clientEnCours->setCode(cl.codeDuClient());
}

void MdiServiceReception::on_btn_effacer_clicked()
{
    ui->historiqueDesMsgs->clear();
}

void MdiServiceReception::ajouterUnEltSuggestion(int row, int column, QString valeur)
{
    QTableWidgetItem * item = new QTableWidgetItem(valeur);
    item->setTextAlignment(Qt::AlignCenter);

    ui->tableWidgetSuggestions->setItem(row, column, item);
}

void MdiServiceReception::ajouterUneSuggestion(client cl)
{
    QString sexe("Masculin");

    if(!cl.homme())
        sexe = "Féminin";

    QStringList l;
    l << QString::number(cl.codeDuClient())
      << cl.nom() + " " + cl.prenoms()
      << sexe
      << cl.cel()
      << cl.typeDeClientStr()
      << typeConseille(cl);

    int row = ui->tableWidgetSuggestions->rowCount();
    ui->tableWidgetSuggestions->setRowCount(row + 1);
    for(int i = ID; i < TYPE_CONSEILLE; i++)
    {
        ajouterUnEltSuggestion(row, i, l.at(i));
    }
}

void MdiServiceReception::on_lineEditNomOcc_textChanged(QString text)
{
    m_demandeSuggProvOccup = true;
   afficherSuggestions(text, ui->lineEditPrenomOcc->text());
}

QString MdiServiceReception::typeConseille(client cl)
{
    return cl.typeDeClientStr();
}

void MdiServiceReception::afficherSuggestions(QString nom, QString prenom)
{
    QList<QSqlRecord> records;

    if(!nom.isEmpty() || !prenom.isEmpty())
        records << InfosSurBD::enregistrements(Client::Libelle, tr("%1 LIKE '%2%' AND %3 LIKE '%4%'").arg(client().nomName())
                                                                                                     .arg(nom)
                                                                                                     .arg(client().prenomsName())
                                                                                                     .arg(prenom));
    if(!records.isEmpty())
    {
        if(ui->tabWidgetCptService->count() != TAB_SUGG + 1)
        {
            ui->tabWidgetCptService->addTab(ui->tabSuggestions, "Suggestions");
        }

        ui->tabWidgetCptService->setCurrentIndex(TAB_SUGG);
        ui->tableWidgetSuggestions->setRowCount(0);
        for(int i = 0; i < records.count(); i++)
        {
            client cl(records.at(i));
            ajouterUneSuggestion(cl);
        }
    }else
    {
        if(ui->tabWidgetCptService->count() == TAB_SUGG + 1)
        {
            ui->tabWidgetCptService->removeTab(TAB_SUGG);
        }

        ui->tabWidgetCptService->setCurrentIndex(TAB_MSG);
    }
}

void MdiServiceReception::on_lineEditPrenomOcc_textChanged(QString prenom)
{
    m_demandeSuggProvOccup = true;
    afficherSuggestions(ui->lineEditNomOcc->text(), prenom);
}

void MdiServiceReception::on_lineEditNomReserv_textChanged(QString nom)
{
    m_demandeSuggProvOccup = false;
    afficherSuggestions(nom, ui->lineEditPrenomReserv->text());
}

void MdiServiceReception::on_lineEditPrenomReserv_textChanged(QString prenom)
{
    m_demandeSuggProvOccup = false;
    afficherSuggestions(ui->lineEditNomReserv->text(), prenom);
}

void MdiServiceReception::on_btn_charger_clicked()
{
    int currentRow = ui->tableWidgetSuggestions->currentRow();
    int code = ui->tableWidgetSuggestions->item(currentRow, ID)->text().toInt();
    client cl(code);

    if(m_demandeSuggProvOccup)
    {
        remplirOccuperUneChambre(cl);
    }
    else
    {
        remplirReserverUneChambre(cl);
    }
}

void MdiServiceReception::updateBtnCharge(QModelIndex index)
{
    if(index.isValid())
    {
        ui->btn_charger->setEnabled(true);
    }else
    {
        ui->btn_charger->setEnabled(false);
    }
}
