#include <QtCore/QCoreApplication>
#include <QHostInfo>
#include <QHostAddress>
#include <QNetworkInterface>
#include <iostream>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <QStringList>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QNetworkInterface ethernet = QNetworkInterface::interfaceFromName("Carte Ethernet Connexion au r�seau local");
//    QNetworkInterface wifi = QNetworkInterface::interfaceFromName("Carte r�seau sans fil Connexion r�seau sans fil");
//
//    if(ethernet.isValid())
//    {
//        cout << ethernet.humanReadableName().toStdString() << " " << ethernet.hardwareAddress().toStdString();
//    }
//
//    if(wifi.isValid())
//    {
//        cout << wifi.humanReadableName().toStdString() << " " << wifi.hardwareAddress().toStdString();
//    }

//    QList<QNetworkInterface> interfaces;
//    interfaces << QNetworkInterface::allInterfaces();
//
//    foreach(QNetworkInterface interface, interfaces)
//    {
//        if(interface.humanReadableName() == QString("Connexion au r�seau local")
//            || interface.humanReadableName() == QString("Connexion r�seau sans fil"))
//        cout << interface.name().toStdString() << " " << interface.hardwareAddress().toStdString() << endl;
//    }

//    QFile file(":/fichiers/code wifi.txt");
//    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//    {
//        cout << "ferme!";
//    }else
//    {
//        cout << "ouvert en �criture!";
////        if(file.copy("../fichiers/code wifi1.txt"))
////        {
////            cout << "copie!";
////        }else
////        {
////            cout << "impossible de copie!";
////        }
//    }

//    if(QFile::copy("../data/catalogue_de_recepteurs.mdb", "catalogue_de_recepteurs.mdb"))
//    {
//        cout << "copie";
//    }else
//    {
//        cout << "non copie";
//    }

//    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "catalogue_de_recepteurs");
//    db.setDatabaseName(QObject::tr("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=%1").arg(":/data/catalogue_de_recepteurs.mdb"));
//    db.setPassword("aigleroyal7");
//
//    bool connecte = db.open();
//    if(!connecte)
//    {
//        cout << QObject::tr("La base de donn�es du catalogue des mat�riels est indisponible! : %1").arg(db.lastError().text()).toStdString();
//    }

    QStringList liste;
    liste << "a" << "a";

    liste.removeDuplicates();

    cout << liste.first().toStdString();

    return a.exec();
}
