#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*  connexion à la base de données  */
    BDD db("QODBC");
    QStringList params;
    params << "clientele"
            << "localhost"
            << "root"
            << ""
            << "3306";

    db.setDatabaseName(params.first());
    db.setHostName(params.at(1));
    db.setUserName(params.at(2));
    db.setPassword(params.at(3));
    db.setPort(params.at(4).toInt());

    if(!db.open())
    {
        QMessageBox::warning(0, "Echec de connection", QObject::tr("Impossible de se connecter à la base de données: %1").arg(db.lastError().text()));
    }

    agent * ag = new agent("RECEPT01");
    QMessageBox::information(this, "infos", ag->nom());
    ag->setBP("01 BP 3455 Abidjan 01");
    ag->enregistrer();
    delete ag;

    profileClient * p = new profileClient(1);
    QMessageBox::information(this, "infos", p->profile());
    p->setDisponible(true);
    p->enregistrer();
    delete p;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
