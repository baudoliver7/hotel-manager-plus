#include <QtGui/QApplication>
//#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;

    // connexion � la base de donn�es
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
