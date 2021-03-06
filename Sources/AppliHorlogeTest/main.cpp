#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QProcess>
#include <QSettings>

#include "bdd.h"
#include "HeureLimite.h"
#include "BDInfosConnection.h"
#include "horloge.h"

#define DSN "clientele"
#define PARAMSCONNECTION "Param�tres de connection"
#define APPNAME "HMP's product win32"
#define PRODUCTNAME "HMP"

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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSettings settings(APPNAME, PRODUCTNAME);

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
    Horloge horloge;

    QObject::connect(&horloge, SIGNAL(fermerApp()), &a, SLOT(quit()));

    MainWindow w(&horloge, &db);
    w.show();
    int id = a.exec();

    horloge.exit();
    return id;
}
