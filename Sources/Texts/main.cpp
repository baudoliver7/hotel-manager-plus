#include <QtGui/QApplication>
#include "mainwindow.h"
#include "bdd.h"
#include "MesTables.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    /*  connexion � la base de donn�es  */
//    BDD db("QODBC");
//    db.setDatabaseName("clientele");
//    db.setHostName("localhost");
//    db.setUserName("root");
//    db.setPort(3306);
//
//    /* Initialiser les diff�rents param�tres si bd est ouvert, sinon quitter l'application */
//    if(!db.open())
//    {
//        QMessageBox::information(0, "infos", "connexion indisponible");
//        return 1;
//    }
//
//    MainWindow w;
//    w.show();

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
    parametres << QString("HMPC")
               << QString("1HMP-0000-0000-0001")
               << QDateTime::currentDateTime().toString(Qt::ISODate)
               << QString::number(20)
               << QString::number(3)
               << itEth
               << adrEth
               << itWifi
               << adrWifi;

    if(!MesTables::enregistrerActivation("shared/1718_hmp_ac.achm", parametres))
    {
        QMessageBox::information(0, "infos", QObject::tr("erreur d'enregistrement!"));
    }

//    QString text = "Je viens � la maison pour me ressourcer afin de mieux attaquer les dangers de la vie";
//
//    QString textCode = MesTables::crypter(text);
//    QMessageBox::information(0, "text cod�", textCode);
//    QMessageBox::information(0, "text d�cod�", MesTables::decrypter(textCode));
    return a.exec();
}
