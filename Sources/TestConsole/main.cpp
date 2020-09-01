#include <QtCore/QCoreApplication>
#include "bdd.h"
#include "iostream"
#include "MesTables.h"
#include "QDateTime"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*  connexion à la base de données  */
    BDD db("QODBC");
    db.setDatabaseName("clientele");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPort(3306);

    /* Initialiser les différents paramètres si bd est ouvert, sinon quitter l'application */
    if(db.open())
    {
        if(MesTables::selectionnerChambresDisponibles("Chambre ventilée", QDateTime::currentDateTime(), 3).isEmpty())
        {
            cout << "ok!";
        }
    }

    db.close();
    return a.exec();
}
