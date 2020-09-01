#include <QtCore/QCoreApplication>
#include "bdd.h"
#include "iostream"
#include "MesTables.h"
#include "QDateTime"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*  connexion � la base de donn�es  */
    BDD db("QODBC");
    db.setDatabaseName("clientele");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPort(3306);

    /* Initialiser les diff�rents param�tres si bd est ouvert, sinon quitter l'application */
    if(db.open())
    {
        if(MesTables::selectionnerChambresDisponibles("Chambre ventil�e", QDateTime::currentDateTime(), 3).isEmpty())
        {
            cout << "ok!";
        }
    }

    db.close();
    return a.exec();
}
