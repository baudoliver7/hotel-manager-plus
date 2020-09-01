/* classes de qt */
#include <QtGui/QApplication>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QFileDialog>
#include <QSplashScreen>
#include <QSettings>

/* classes personnalisées */
#include "mainwindow.h"
#include "bdd.h"
#include "HeureLimite.h"
#include "BDInfosConnection.h"
#include "horloge.h"

/* définitions */
#define DSN "clientele"
#define APPNAME "HMP's product win32"
#define PRODUCTNAME "HMPResto"
#define PARAMSCONNECTION "Paramètres de connection"
#define IDPRODUIT "1HMP-0000-0000-0002"
#define IDSERVICE 4

/*-------------------------------------------------------------- déclarations de fonction -----------------------------------------------------------------*/
int creerUnDSN(QString & parametres)
{
    parametres.clear();
    BDInfosConnection bdInfos;
    bdInfos.setWindowTitle("Paramètres du serveur");
    if(bdInfos.exec() == QDialog::Rejected)
        return 1;

    QStringList arguments;
    arguments << "-s"
              << "-a"
              << "-c1"
              << "-n"
              << DSN
              << "-t"
              << QObject::tr("DRIVER=MySQL ODBC 5.1 Driver;SERVER=%1;DATABASE=gestion_clientele;UID=%2;PWD=%3").arg(bdInfos.serveur()).arg(bdInfos.user()).arg(bdInfos.password());

    if(QProcess::execute("myodbc-installer", arguments) == 1)
    {
        QMessageBox::warning(0, "Erreur de connection", "Il est impossible de créer une connexion! \n Veuillez réinstaller l'application pour corriger cette erreur.");
        return 1;
    }

    parametres.append(DSN);
    parametres.append(QObject::tr(" %1").arg(bdInfos.serveur()));
    parametres.append(QObject::tr(" %1").arg(bdInfos.user()));
    parametres.append(QObject::tr(" %1").arg(bdInfos.password()));
    parametres.append(QObject::tr(" %1").arg(bdInfos.port()));

    return 0;
}

/* ---------------------------------------------- programme principal -------------------------------------------------*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString path = QDir::fromNativeSeparators(a.arguments().first());
    path.remove(path.split("/").last());

    QSettings settings(APPNAME, PRODUCTNAME);

    // le produit est maintenant enregistré
    QCoreApplication::addLibraryPath(path + "plugins/");

    /* Récupération des paramètres de connection */
    QString parametresOrig = settings.value(PARAMSCONNECTION).toString();
    QString parametres = parametresOrig;

    /*  connexion à la base de données  */
    BDD db("QODBC");
    bool bdRenseignee = false;
    QStringList params;
    if(!parametres.isEmpty()) params = parametres.split(" ");

    do
    {
        if(params.isEmpty() || bdRenseignee)
        {
            // c'est donc un problème de paramètres. reconfigurer le dsn
            int id = creerUnDSN(parametres);
            if(id) return id;
            params = parametres.split(" ");
        }

        db.setDatabaseName(params.first());
        db.setHostName(params.at(1));
        db.setUserName(params.at(2));
        db.setPassword(params.at(3));
        db.setPort(params.at(4).toInt());
        bdRenseignee = true;

        if(!db.open())
        {
            QMessageBox::warning(0, "Echec de connection", QObject::tr("Impossible de se connecter à la base de données: %1").arg(db.lastError().text()));
        }
    }while(!db.isOpen());

    /* Nous sommes maintenant connectés à la base de données */

    // on enregistre les paramètres de connection si changés
    if(parametres != parametresOrig)
    {
        settings.setValue(PARAMSCONNECTION, parametres);
    }

    // vérifier que l'heure du serveur est à jour
    HeureLimite hl(1);
    QDateTime lastDate = hl.lastHourSyst();
    QDateTime now = hl.currentHourSyst();
    if(lastDate > now) // si anomalie
    {
        hl.setLastHourSyst(lastDate);
        hl.enregistrer(); // remettre la dernière heure

        QMessageBox::warning(0, "Heure du serveur", "L'heure du serveur n'est pas à jour! \n Veuillez la mettre à jour, puis redémarrez l'application.");
        return 0;
    }

    // on a la bonne heure
    Horloge horloge(now);

    // on enregistre la durée restante de l'activation
    if(hl.dureeRestante() > 0)
    {
        hl.setDureeRestante(now.daysTo(hl.finActivation()));
        hl.enregistrer();
    }

    // on vérifie que la période d'activation est valide
//    QString fichier_activation = path + QString("shared/1718_hmp_ac.achm");
//    if(!MesTables::activationEstValide(PRODUCTNAME, IDPRODUIT, fichier_activation))
//        return 0;

//    QPixmap pixmap(":/maquette/splash screen.jpg");
//    QSplashScreen splash(pixmap);
//    splash.show();

    QSplashScreen * splash = 0;
    MainWindow w(&horloge, splash, path, IDSERVICE);

    w.lancerFenetre(); // pour le moment

    // attendre 5s
    //QTimer::singleShot(5 * 1000, &w, SLOT(lancerFenetre()));

    int id = a.exec();

    hl.currentHourSyst(); // pour enregistrer l'heure en cours;

    // enregistrer la sortie d'application pour ce compte
    if(w.utilisateur() != 0) // si existe
    {
        w.utilisateur()->setCodeDeSortie(id);
        w.utilisateur()->setConnecte(false);
        w.utilisateur()->setEtatFinConnection(0); // bon
        w.utilisateur()->enregistrer();
    }

    return id;
}

/* ---------------------------------------------- Fin programme principal -------------------------------------------------*/
