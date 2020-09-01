#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QSqlDatabase *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_db = db;

    QList<QSqlRecord> records;
    records = InfosSurBD::enregistrements(PlanComptable::Libelle);

    foreach(QSqlRecord r, records)
    {
        planComptable p(r);
        p.setLibellePerso(p.libelle());
        p.enregistrer();
    }


//    int count = InfosSurBD::enregistrements(Etage::Libelle).count();
//    QMessageBox::information(this, "Infos", tr("Nb enreg : %1").arg(count));
//    if(db->transaction())
//    {
//        etage at;
//        at.setNiveau("Etage 25");
//        at.enregistrer();
//
//        // opérations
//        //QMessageBox::information(this, "Infos", "Driver supporte la transaction");
//
//        if(!db->rollback())
//        {
//            QMessageBox::information(this, "Infos", "Driver ne supporte pas le rollback");
//        }else
//        {
//                int count = InfosSurBD::enregistrements(Etage::Libelle).count();
//                QMessageBox::information(this, "Infos", tr("Nb enreg : %1").arg(count));
//            //QMessageBox::information(this, "Infos", "Driver supporte le rollback");
//        }
//
//    }else
//    {
//        QMessageBox::information(this, "Infos", "Driver ne supporte pas la transaction");
//    }
//    //groupe gp(4);
//    //m_facture = new factureHotelGroupe(gp);
//
//    //QGraphicsScene * scene = m_facture->scene();
//    QGraphicsScene * scene = new QGraphicsScene();
//    ui->graphicsView->setScene(scene);
//    ui->graphicsView->update();
//
//    QGraphicsPixmapItem * item = new QGraphicsPixmapItem(QPixmap(":/images/facture resto individu A4.png"), 0);
//    //QGraphicsPixmapItem * item = new QGraphicsPixmapItem(QPixmap(), 0);
//    scene->addItem(item);
//    x0 = item->x();
//    y0 = item->y();
//
//    qreal width = item->boundingRect().width();
//    qreal height = item->boundingRect().height();
//
//    m_titre = scene->addText("Facture N° 1 du 31/12/2011", QFont("Garamond", 12));
//    qreal x = width / 2.0 - m_titre->boundingRect().width()/2.0;
//    m_titre->setPos(x0 + x, y0 - 20);
//
//    ui->doubleSpinBoxX->setValue(width);
//    ui->doubleSpinBoxY->setValue(height);
//
//    showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;

    //delete m_facture;
    //delete m_horloge;
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

void MainWindow::on_btn_imprimer_clicked()
{
//    QPixmap p(":/images/logo.png");
//    recuHotel recu(p);
//    recu.setText(recuHotel::NomHotel, "GOLDEN HOTEL");
//    recu.setText(recuHotel::MatriculeAgent, "RECEPT01");
//    recu.setText(recuHotel::NomAgent, "OURA Olivier Baudouin");
//    recu.setText(recuHotel::Profession, "Comptable");
//    recu.setText(recuHotel::NomClient, "KAMAGATE Seydou");
//    recu.setText(recuHotel::TypeDeChambre, "Chambre climatisée");
//    recu.setText(recuHotel::IdentifiantDeChambre, "CC1");
//    recu.setText(recuHotel::PrixDuJour, "30 000");
//    recu.setText(recuHotel::DureeDeLocation, "3 jours");
//    recu.setText(recuHotel::LocationAPayer, "90 000");
//    recu.setText(recuHotel::RestaurantAPayer, "55 000");
//    recu.setText(recuHotel::PenaliteAPayer, "15 000");
//    recu.setText(recuHotel::TotalAPayer, "160 000");
//    recu.setText(recuHotel::TotalPaye, "150 000");
//    recu.setText(recuHotel::PenalitePaye, "5 000");
//    recu.setText(recuHotel::RestaurantPaye, "55 000");
//    recu.setText(recuHotel::LocationPayee, "90 000");
//    recu.setText(recuHotel::ResteAPayer, "10 000 C CFA");
//    recu.setText(recuHotel::SituationGeo, "Marcory Pharmacie Tiacoh");
//    recu.setText(recuHotel::Adresse, "01 BP 1345 Abidjan 01");
//    recu.setText(recuHotel::Tel, "23-34-33-56 / 34-57-44-33");
//    recu.setText(recuHotel::NumFacture, "1");
//    recu.setText(recuHotel::FaitA, "Fait à Yamoussoukro le jeudi 9 Juin 2012");
//
    // impression
//    QPrinter printer(QPrinter::HighResolution);
//    printer.setPageSize(QPrinter::A5);
//    QPrintDialog printDialog(&printer, this);
//
//    // éventuelle pensée
//    if(printDialog.exec() == QDialog::Accepted)
//    {
//        QPainter painter(&printer);
//
//        // print, fitting the viewport contents into a full page
//        m_facture->view()->render(&painter);
//    }
}

void MainWindow::on_doubleSpinBoxX_valueChanged(double x)
{
    //m_titre->setX(x0 + x);
}

void MainWindow::on_doubleSpinBoxY_valueChanged(double y)
{
    //m_titre->setY(y0 + y);
}
