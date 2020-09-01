#include "MdiModeDiffere.h"
#include "ui_MdiModeDiffere.h"

MdiModeDiffere::MdiModeDiffere(QSqlDatabase db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MdiModeDiffere)
{
    ui->setupUi(this);

    m_db = db;
    m_dbMySql = QSqlDatabase::addDatabase("QODBC");
    m_dbMySql.setDatabaseName(DSN);

    m_numInst = 0;

    connect(ui->lineEditNom, SIGNAL(textChanged(QString)), this, SLOT(updateBtnActiver()));
    connect(ui->lineEditPrenoms, SIGNAL(textChanged(QString)), this, SLOT(updateBtnActiver()));
    connect(ui->lineEditContacts, SIGNAL(textChanged(QString)), this, SLOT(updateBtnActiver()));
    connect(ui->lineEditHotel, SIGNAL(textChanged(QString)), this, SLOT(updateBtnActiver()));
    connect(ui->lineEditVille, SIGNAL(textChanged(QString)), this, SLOT(updateBtnActiver()));

    on_btn_initialiser_clicked();
    updateBtnActiver();
    on_comboBoxNomProduit_currentIndexChanged(0);
}

MdiModeDiffere::~MdiModeDiffere()
{
    delete ui;
}

void MdiModeDiffere::changeEvent(QEvent *e)
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

void MdiModeDiffere::on_btn_contacts_clicked()
{
    DialogContact * dialog = new DialogContact(ui->lineEditContacts->text()
                                               ,this);
    dialog->setWindowTitle("Contacts");
    if(dialog->exec() == QDialog::Accepted)
    {
        ui->lineEditContacts->setText(dialog->getContact());
    }

    delete dialog;
}

void MdiModeDiffere::on_btn_rechercheUtil_clicked()
{
    BDRechercherUtil * bdRecherch = new BDRechercherUtil(m_db, this);
    bdRecherch->setWindowTitle("Rechercher un utilisateur");
    if(bdRecherch->exec() == QDialog::Accepted)
    {
        afficherUtilisateur(bdRecherch->record());
    }

    delete bdRecherch;
}

void MdiModeDiffere::on_btn_initialiser_clicked()
{
    m_numInst = 0;
    ui->comboBoxNomProduit->setCurrentIndex(0);

    // infos activation
    ui->dateTimeEditActivation->setDateTime(QDateTime::currentDateTime());
    ui->spinBoxDureeActiva->setValue(1);
    ui->spinBoxDureeTol->setValue(0);
    ui->comboBoxPeriode->setCurrentIndex(0);

    // infos utilisateur
    ui->dateTimeEditInscription->setDateTime(QDateTime::currentDateTime());
    ui->lineEditContacts->setText(QString());
    ui->lineEditHotel->setText(QString());
    ui->lineEditNom->setText(QString());
    ui->lineEditPrenoms->setText(QString());
    ui->lineEditVille->setText(QString());
    ui->Masculin->setChecked(true);
}

void MdiModeDiffere::setUtilisateurEnabled(bool enabled)
{
    // infos utilisateur
    ui->dateTimeEditInscription->setEnabled(enabled);
    ui->lineEditContacts->setEnabled(enabled);
    ui->lineEditHotel->setEnabled(enabled);
    ui->lineEditNom->setEnabled(enabled);
    ui->lineEditPrenoms->setEnabled(enabled);
    ui->lineEditVille->setEnabled(enabled);
    ui->Masculin->setEnabled(enabled);
    ui->Feminin->setEnabled(enabled);
}

void MdiModeDiffere::afficherUtilisateur(QSqlRecord record)
{
    m_numInst = record.value(0).toInt();

    // infos utilisateur
    QDateTime dateInscription = QDateTime::fromString(record.value(1).toString(), Qt::ISODate);
    ui->dateTimeEditInscription->setDateTime(dateInscription);

    ui->lineEditNom->setText(record.value(2).toString());
    ui->lineEditPrenoms->setText(record.value(3).toString());
    ui->Masculin->setChecked(record.value(4).toBool());
    ui->lineEditContacts->setText(record.value(5).toString());
    ui->lineEditHotel->setText(record.value(6).toString());
    ui->lineEditVille->setText(record.value(7).toString());

    ui->Feminin->setChecked(!ui->Masculin->isChecked());
    m_record = record;
}


void MdiModeDiffere::on_btn_activer_clicked()
{
    ui->btn_activer->setEnabled(false);

    // vérifier la bd mysql
    m_dbMySql.setHostName(ui->lineEditServeur->text());
    m_dbMySql.setUserName(ui->lineEditUtil->text());
    m_dbMySql.setPassword(ui->lineEditPassword->text());
    m_dbMySql.setPort(ui->lineEditPort->text().toInt());

    if(!m_dbMySql.open())
    {
        QMessageBox::warning(this, "Activation du produit", "L'activation du produit a échouée! \n\n Le serveur est indisponible actuellement!");
        return;
    }

    // serveur disponible
    QSqlTableModel modelUtil(0, m_db);
    QSqlTableModel modelActiva(0, m_db);
    modelUtil.setTable("Utilisateurs");
    modelActiva.setTable(nomActiva);

    modelActiva.select();
    modelUtil.select();

    int row;
    if(m_numInst == 0)
    {
        row = modelUtil.rowCount();
        modelUtil.insertRow(row);
        m_numInst = row + 1;
    }else
    {
        row = m_numInst - 1;
    }

    // enregistrer l'utilisateur
    modelUtil.setData(modelUtil.index(row, 0), row + 1);
    modelUtil.setData(modelUtil.index(row, 1), ui->dateTimeEditInscription->dateTime().toString(Qt::ISODate));
    modelUtil.setData(modelUtil.index(row, 2), ui->lineEditNom->text());
    modelUtil.setData(modelUtil.index(row, 3), ui->lineEditPrenoms->text());
    modelUtil.setData(modelUtil.index(row, 4), ui->Masculin->isChecked());
    modelUtil.setData(modelUtil.index(row, 5), ui->lineEditContacts->text());
    modelUtil.setData(modelUtil.index(row, 6), ui->lineEditHotel->text());
    modelUtil.setData(modelUtil.index(row, 7), ui->lineEditVille->text());

    modelUtil.submitAll();

    // enregistrer l'activation
    int idAjout = modelActiva.rowCount();
    modelActiva.insertRow(idAjout);
    QString dateActivaStr = ui->dateTimeEditActivation->dateTime().toString(Qt::ISODate);
    modelActiva.setData(modelActiva.index(idAjout, 0), dateActivaStr);
    modelActiva.setData(modelActiva.index(idAjout, 1), m_numInst);
    modelActiva.setData(modelActiva.index(idAjout, 2), ui->spinBoxDureeActiva->value());
    modelActiva.setData(modelActiva.index(idAjout, 3), ui->spinBoxDureeTol->value());
    modelActiva.setData(modelActiva.index(idAjout, 4), true); // enregistré

    modelActiva.submitAll();

    // enregistrer sur l'ordinateur
    QSettings settings(QSettings::SystemScope, APPNAME, productName);

    settings.setValue(APPNAME, productName);
    settings.setValue(INSTALLATIONID, m_numInst);

    QString key = tr("%1_%2_%3_%4").arg(dateActivaStr)
                                   .arg(ui->spinBoxDureeActiva->value())
                                   .arg(m_numInst)
                                   .arg(1);
    settings.setValue(KEY, key);
    QString parametres = tr("%1 %2 %3 %4 %5").arg(DSN)
                                          .arg(ui->lineEditServeur->text())
                                          .arg(ui->lineEditUtil->text())
                                          .arg(ui->lineEditPassword->text())
                                          .arg(ui->lineEditPort->text());

    settings.setValue(PARAMSCONNECTION, parametres);

    //  enregistrer dans la base de données gestion de clientèle
    HeureLimite hl(1);
    hl.setDebutActivation(ui->dateTimeEditActivation->dateTime());

    int duree = ui->spinBoxDureeActiva->value();
    if(ui->comboBoxPeriode->currentIndex() == 1) // si c'est mois
    {
        duree = duree * 30;
    }

    hl.setDureeActivation(duree);
    hl.setDureeTolerance(ui->spinBoxDureeTol->value());
    hl.setUtilEnregistrer(true);
    hl.setIID(m_numInst);
    hl.enregistrer();

    // pas d'initialisation
    // avertir que l'activation a réussi
    QMessageBox::information(this, "activation du produit", "L'activation du produit s'est déroulée avec succès!");

     ui->btn_activer->setEnabled(true);
}

void MdiModeDiffere::on_btn_test_clicked()
{
    // créer d'abord un dsn
    QStringList arguments;
    arguments << "-s"
              << "-a"
              << "-c1"
              << "-n"
              << DSN
              << "-t"
              << QObject::tr("DRIVER=MySQL ODBC 5.1 Driver;SERVER=%1;DATABASE=gestion_clientele;UID=%2;PWD=%3").arg(ui->lineEditServeur->text()).arg(ui->lineEditUtil->text()).arg(ui->lineEditPassword->text());

    if(QProcess::execute("myodbc-installer", arguments) == 1)
    {
        QMessageBox::warning(this, "Erreur de connection", "Il est impossible de créer une connexion! \n\n Veuillez réinstaller le pilote odbc pour corriger cette erreur.");
        return;
    }

    m_dbMySql.setHostName(ui->lineEditServeur->text());
    m_dbMySql.setUserName(ui->lineEditUtil->text());
    m_dbMySql.setPassword(ui->lineEditPassword->text());
    m_dbMySql.setPort(ui->lineEditPort->text().toInt());

    if(m_dbMySql.open())
    {
        QMessageBox::information(this, "Etat de la connection", "Connection réussie!");
    }else
    {
        QMessageBox::information(this, "Etat de la connection", m_dbMySql.lastError().text());
    }  
}

void MdiModeDiffere::updateBtnActiver()
{
    bool disabled = ui->lineEditNom->text().isEmpty()
                    || ui->lineEditPrenoms->text().isEmpty()
                    || ui->lineEditContacts->text().isEmpty()
                    || ui->lineEditHotel->text().isEmpty()
                    || ui->lineEditVille->text().isEmpty();

    ui->btn_activer->setDisabled(disabled);
}

void MdiModeDiffere::on_btn_charger_clicked()
{
   QSettings settings(QSettings::SystemScope, APPNAME, productName);

   if(settings.contains(PARAMSCONNECTION))
   {
        QStringList params = settings.value(PARAMSCONNECTION).toString().split(" ");
        ui->lineEditServeur->setText(params.at(1));
        ui->lineEditUtil->setText(params.at(2));
        ui->lineEditPassword->setText(params.at(3));
        ui->lineEditPort->setText(params.at(4));
   }else
   {
       QMessageBox::information(this, "Charger paramètres", "Aucun paramètre de connection n'a été trouvé pour ce produit!");
   }
}

void MdiModeDiffere::on_comboBoxNomProduit_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0:
        nomActiva = "activationsHMPA";
        productName = "HMPA";
        break;
    case 1:
        nomActiva = "activationsHMPC";
        productName = "HMPC";
        break;
    default:
        nomActiva = "activationsHMPR";
        productName = "HMPR";
    }
}
