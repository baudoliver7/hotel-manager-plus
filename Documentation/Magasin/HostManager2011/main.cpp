#include <QtGui/QApplication>
//#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;

    // connexion à la base de données
//    if(w.seConnecterALaBDGestionDeLaClientele())
//    {
//        // lancer la fenetre principale
//        w.showMaximized();
//    }else
//    {
//        return 1;
//    }

    return a.exec();
}
