#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QProcess>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

//    QStringList arguments;
//    arguments << "-u"
//              << "root"
//              << "-h"
//              << "localhost"
//              << "-P"
//              << "3308"
//              << "--password"
//              << "12345"
//              << "elevage"
//              << "<"
//              << "elevage_sauvegarde.sql";
//
//    QString program = "mysql.exe";

    //process.setWorkingDirectory("C:\\Program Files\\MySQL\\MySQL Server 5.1\\bin");
    QProcess process1;
    QProcess process2;
    QProcess process3;

    process1.setStandardOutputProcess(&process2);
    process2.setStandardOutputProcess(&process3);

    process1.start("mysql -u root -h localhost -P 3308 -p12345");
    process2.start("DROP DATABASE elevage;");
    process3.start("exit;");

    //QString standardError(process.readAllStandardOutput());
    QMessageBox::information(0, "Message error", QString("Code de sortie 1 : %1;Code de sortie 2 : %2;Code de sortie 3 : %3")
                             .arg(process1.exitCode())
                             .arg(process2.exitCode())
                             .arg(process3.exitCode()));

//    if(process.exitStatus() == QProcess::NormalExit)
//        QMessageBox::information(0, "Importation de BD", QString("Code de sortie : %1").arg(process.exitCode()));
//    else
//        QMessageBox::information(0, "Importation de BD", QString("Erreur d'exécution : %1").arg(process.exitCode()));

    return a.exec();
}
