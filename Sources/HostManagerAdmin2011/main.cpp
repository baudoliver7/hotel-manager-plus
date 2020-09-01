/* classes de qt */
#include <QtGui/QApplication>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QFileDialog>
#include <QSplashScreen>
#include <QSettings>

/* classes personnalis�es */
#include "mainwindow.h"
#include "bdd.h"
#include "HeureLimite.h"
#include "BDInfosConnection.h"
#include "horloge.h"

/* d�finitions */
#define DSN "clientele"
#define APPNAME "HMP's product win32"
#define PRODUCTNAME "HMP"
#define PARAMSCONNECTION "Param�tres de connection"
#define IDPRODUIT "1HMP-0000-0000-0002"
#define IDSERVICE 1

/*-------------------------------------------------------------- d�clarations de fonction -----------------------------------------------------------------*/
int creerUnDSN(QString & parametres)
{
    BDInfosConnection bdInfos(parametres.split("&&"));
    bdInfos.setWindowTitle("Param�tres du serveur");
    if(bdInfos.exec() == QDialog::Rejected)
        return 1;

    QStringList arguments;
    arguments << "-s"
              << "-a"
              << "-c1"
              << "-n"
              << DSN
              << "-t"
              << QObject::tr("DRIVER=MySQL ODBC 5.1 Driver;SERVER=%1;DATABASE=%2;UID=%3;PWD=%4;PORT=%5")
              .arg(bdInfos.serveur()).arg(bdInfos.databaseName()).arg(bdInfos.user()).arg(bdInfos.password()).arg(bdInfos.port());

    if(QProcess::execute("myodbc-installer", arguments) == 1)
    {
        QMessageBox::warning(0, "Erreur de connection", "Il est impossible de cr�er une connexion! \n Veuillez r�installer l'application pour corriger cette erreur.");
        return 1;
    }

    parametres.clear();
    parametres.append(DSN);
    parametres.append("&&" + bdInfos.serveur());
    parametres.append("&&" + bdInfos.databaseName());
    parametres.append("&&" + bdInfos.user());
    parametres.append("&&" + bdInfos.password());
    parametres.append("&&" + QString::number(bdInfos.port()));

    return 0;
}

/* ---------------------------------------------- programme principal -------------------------------------------------*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString path = QDir::fromNativeSeparators(a.arguments().first());
    path.remove(path.split("/").last());

    QSettings settings(APPNAME, PRODUCTNAME);

    // le produit est maintenant enregistr�
    QCoreApplication::addLibraryPath(path + "plugins/");

    /* R�cup�ration des param�tres de connection */
    QString parametresOrig = settings.value(PARAMSCONNECTION).toString();
    QString parametres = parametresOrig;

    /*  connexion � la base de donn�es  */
    BDD db("QODBC");
    bool bdRenseignee = false;
    QStringList params;
    if(!parametres.isEmpty()) params = parametres.split("&&");

    do
    {
        if(params.isEmpty() || bdRenseignee)
        {
            // c'est donc un probl�me de param�tres. reconfigurer le dsn
            int id = creerUnDSN(parametres);
            if(id) return id;
            params = parametres.split("&&");
        }

        db.setDatabaseName(params.at(IDALIAS));
        db.setHostName(params.at(IDSERVER));
        db.setUserName(params.at(IDUSER));
        db.setPassword(params.at(IDPASSWORD));
        db.setPort(params.at(IDPORT).toInt());
        bdRenseignee = true;

        if(!db.open())
        {
            QMessageBox::warning(0, "Echec de connexion", QObject::tr("Impossible de se connecter � la base de donn�es: %1").arg(db.lastError().text()));
        }
    }while(!db.isOpen());
    /* Nous sommes maintenant connect�s � la base de donn�es */

    // on enregistre les param�tres de connection si chang�s
    if(parametres != parametresOrig)
    {
        settings.setValue(PARAMSCONNECTION, parametres);
    }

    // v�rifier que l'heure du serveur est � jour
    HeureLimite hl(1);
    QDateTime lastDate = hl.lastHourSyst();
    QDateTime now = hl.currentHourSyst();
    if(lastDate > now) // si anomalie
    {
        hl.setLastHourSyst(lastDate);
        hl.enregistrer(); // remettre la derni�re heure

        QMessageBox::warning(0, "Heure du serveur", "L'heure du serveur n'est pas � jour! \n Veuillez la mettre � jour, puis red�marrez l'application.");
        return 0;
    }

    // on a la bonne heure
    // on d�marre l'horloge dans un thread ind�pendant
    Horloge horloge;
    horloge.startHorloge();

    // on enregistre la dur�e restante de l'activation
    if(hl.dureeRestante() > 0)
    {
        hl.setDureeRestante(now.daysTo(hl.finActivation()));
        hl.enregistrer();
    }

    // on v�rifie que la p�riode d'activation est valide
    QString fichier_activation = QString("C:/Windows/System32/winachm.dll");

    QFile file(fichier_activation);
    if(file.exists() && MesTables::contenuDuFichierActivation(fichier_activation).isEmpty())
    {
        // enregistrer sur l'ordinateur dans le fichier d'activation
        // r�cup�rer adresse mac de la machine
        QList<QNetworkInterface> interfaces;
        interfaces << QNetworkInterface::allInterfaces();

        QString itEth, itWifi, adrEth, adrWifi;
        foreach(QNetworkInterface interface, interfaces)
        {
            if(interface.humanReadableName() == QString("Connexion au r�seau local"))
            {
                itEth = interface.name();
                adrEth = interface.hardwareAddress();
            }

            if(interface.humanReadableName() == QString("Connexion r�seau sans fil"))
            {
                itWifi = interface.name();
                adrWifi = interface.hardwareAddress();
            }
        }

        QStringList parametres;
        parametres << QString(PRODUCTNAME)
                   << IDPRODUIT
                   << Horloge::currentDateTime().toString(Qt::ISODate)
                   << QString::number(15)
                   << QString::number(0)
                   << itEth
                   << adrEth
                   << itWifi
                   << adrWifi;

        if(!MesTables::enregistrerActivation(fichier_activation, parametres))
        {
            return 1;
        }
    }else
    {
        if(!file.exists())
        {
            QMessageBox::information(0, "Installation du logiciel", "Erreur d'initialisation! \n\nVeuillez r�installer le produit pour corriger ce probl�me.");
            return 1;
        }
    }

    // on effectue le test de validation
    if(!MesTables::activationEstValide(PRODUCTNAME, IDPRODUIT, fichier_activation))
        return 0;

    QPixmap pixmap(":/maquette/splash screen.jpg");
    QSplashScreen splash(pixmap);
    splash.show();

    //QSplashScreen * splash = 0;
    MainWindow w(&db, &horloge, &splash, path, IDSERVICE);

    //w.lancerFenetre(); // pour le moment

    // attendre 5s
    QTimer::singleShot(5 * 1000, &w, SLOT(lancerFenetre()));

    QObject::connect(&horloge, SIGNAL(fermerApp()), &a, SLOT(quit()));
    int id = a.exec();

    if(horloge.dbIsOpen())
    {
        hl.currentHourSyst(); // pour enregistrer l'heure en cours;

        // enregistrer la sortie d'application pour ce compte
        if(w.utilisateur() != 0) // si existe
        {
            w.utilisateur()->setCodeDeSortie(id);
            w.utilisateur()->setConnecte(false);
            w.utilisateur()->setEtatFinConnection(0); // bon
            w.utilisateur()->enregistrer();
        }
    }

    horloge.exit(); // on arr�te le thread de l'horloge

    return id;
}

/* ---------------------------------------------- Fin programme principal -------------------------------------------------*/
