#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlRecord>
#include "operationService.h"
#include "recuInitial.h"

MainWindow::MainWindow(Horloge * horloge, BDD * db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_horloge = horloge;
    m_db = db;    
    
    connect(m_horloge, SIGNAL(minuteOvered()), this, SLOT(afficherHeure()));
    connect(m_horloge, SIGNAL(connexionIsBroken()), this, SLOT(warningDBState()));
    m_horloge->startHorloge();

    afficherHeure();

    /*recuInitial ri(7); // operations_compte_client

    operationService os;
    QList<QSqlRecord> records = InfosSurBD::enregistrements(os.tableName());
    for(int i = 0; i < records.count(); i++)
    {
        operationService os1(records.at(i));
        if(os1.recu().contains(ri.initial()))
        {
            os1.setTableOperation("operations_compte_client");
            os1.enregistrer();
        }
    }*/
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

void MainWindow::afficherHeure()
{    
    QTime now = Horloge::currentTime();
    QStringList heure;
    heure = now.toString(Qt::ISODate).split(":");

    ui->labelDate->setText(tr("%1 h %2").arg(heure.first()).arg(heure.at(1)));
}

void MainWindow::warningDBState()
{
    bool connected = false;
    bool fermerApp = false;
    do
    {
        if(QMessageBox::information(0
                                     , "Problème de connexion"
                                     , "La connexion à la base de données a été interrompue. \n\n"
                                     ,"Reconnecter", "Quitter l'application") == 0)
        {
            if(m_db->open())
            {
                connected = true;
            }else
            {
                QMessageBox::warning(0, "Echec de connexion", QObject::tr("Impossible de se connecter à la base de données: %1").arg(m_db->lastError().text()));
            }
        }else
        {
            fermerApp = true;
            m_horloge->quitApp();
        }
    }while(!connected && !fermerApp);

    if(connected)
    {
        m_horloge->restartHorloge();
    }
}
