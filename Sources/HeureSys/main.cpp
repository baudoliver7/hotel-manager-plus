#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QCoreApplication>
#include <QString>

#define LAST_HOUR_SYST 3

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.addLibraryPath("plugins/");
    QFile f("Paramètres de connexion.txt");
    if(!f.open(QIODevice::ReadOnly|QIODevice::Text))
        return 1;

    QTextStream in(&f);
    QString parametres = in.readLine();
    QStringList params = parametres.split(" ");

    //connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "heureSys connection");
    db.setDatabaseName(params.at(0));
    db.setHostName(params.at(1));
    db.setUserName(params.at(2));
    db.setPort(params.at(3).toInt());

   int execResult;
   if(db.open())
   {
       QSqlTableModel model(0, db);
       model.setTable("heure_bd");
       model.setEditStrategy(QSqlTableModel::OnFieldChange);
       model.select();

       QSqlRecord record = model.record(0);
       if(record.value(LAST_HOUR_SYST).toDateTime() > QDateTime::currentDateTime())
           return 1;

       record.setValue(LAST_HOUR_SYST, QDateTime::currentDateTime().toString(Qt::ISODate));
       model.setRecord(0, record);
       execResult = 0;
   }else
   {
       execResult = 1;
   }

   db.close();
   return execResult;
}
