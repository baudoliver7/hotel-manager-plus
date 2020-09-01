#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QSqlDatabase db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_db = db;
    updateEtatsActions(false);
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

void MainWindow::on_actionEn_diff_r_triggered()
{
    BDConnexion * bdConnec = new BDConnexion(m_db, this);
    bdConnec->setWindowTitle("Identification de l'agent");

    if(bdConnec->exec() == QDialog::Accepted)
    {
        // afficher la mdi
        MdiModeDiffere * mdi = new MdiModeDiffere(m_db, this);
        mdi->setWindowTitle("Fenêtre d'activation");
        ui->mdiArea->addSubWindow(mdi);

        mdi->showMaximized();

        updateEtatsActions(true);
    }

    delete bdConnec;
}

void MainWindow::updateEtatsActions(bool connecte)
{
    ui->actionEn_diff_r->setEnabled(!connecte);
    ui->actionEn_ligne->setEnabled(!connecte);
    ui->actionStatut_d_un_produit->setEnabled(connecte);
    ui->menuDriver_odbc->setEnabled(connecte);
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionStatut_d_un_produit_triggered()
{
    BDStatutProduit * bdStatut = new BDStatutProduit(this);
    bdStatut->setWindowTitle("Statut d'un produit");
    bdStatut->exec();

    delete bdStatut;
}

void MainWindow::on_actionWin32_triggered()
{
    QDir dir;
    dir.cdUp();
    dir.cd("drivers odbc");
    QString chemin = dir.absolutePath() + "/mysql-connector-odbc-5.1.6-win32.msi";

    QDesktopServices::openUrl(QUrl(tr("file:///%1").arg(chemin)));
}

void MainWindow::on_actionWin64_triggered()
{
    QDir dir;
    dir.cdUp();
    dir.cd("drivers odbc");
    QString chemin = dir.absolutePath() + "/mysql-connector-odbc-5.1.9-winx64.msi";

    QDesktopServices::openUrl(QUrl(tr("file:///%1").arg(chemin)));
}
