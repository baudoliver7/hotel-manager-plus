#include <QtGui/QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::addLibraryPath("plugins/");

    // ouvrir bd access
    QSqlDatabase bd = QSqlDatabase::addDatabase("QODBC", "access");
    bd.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=../data/data.mdb");
    bd.setPassword("aigleroyal7");

    if(!bd.open())
    {
        QMessageBox::warning(0, "Base de données indisponible", QObject::tr("La base de données est indisponible! : %1").arg(bd.lastError().text()));
        return 0;
    }

    MainWindow w(bd);
    w.show();
    return a.exec();
}
