#include <QtGui/QApplication>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include "mainwindow.h"
#include "bdd.h"
#include "HeureLimite.h"
#include "horloge.h"
#include <QFileDialog>
#include <QSplashScreen>
#include <QSettings>

#include "BDInfosConnection.h"

#define DSN "clientele"

#define APPNAME "HMP's product win32"
#define PRODUCTNAME "HMP"
#define PARAMSCONNECTION "Paramètres de connection"
#define IDPRODUIT "1HMP-0000-0000-0002"

int creerUnDSN(QString & parametres)
{
    BDInfosConnection bdInfos(parametres.split("&&"));
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
              << QObject::tr("DRIVER=MySQL ODBC 5.1 Driver;SERVER=%1;DATABASE=%2;UID=%3;PWD=%4;PORT=%5")
              .arg(bdInfos.serveur()).arg(bdInfos.databaseName()).arg(bdInfos.user()).arg(bdInfos.password()).arg(bdInfos.port());

    if(QProcess::execute("myodbc-installer", arguments) == 1)
    {
        QMessageBox::warning(0, "Erreur de connection", "Il est impossible de créer une connexion! \n Veuillez réinstaller l'application pour corriger cette erreur.");
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
    if(!parametres.isEmpty()) params = parametres.split("&&");

    do
    {
        if(params.isEmpty() || bdRenseignee)
        {
            // c'est donc un problème de paramètres. reconfigurer le dsn
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
            QMessageBox::warning(0, "Echec de connexion", QObject::tr("Impossible de se connecter à la base de données: %1").arg(db.lastError().text()));
        }
    }while(!db.isOpen());

    MainWindow w(&db);
    w.show();
    
    return a.exec();
}
