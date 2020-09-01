#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene();

    ui->compagnonGraphicsView->setScene(m_scene);

    m_pilote = new PiloteCompagnonFidele(m_scene);
    ui->heure->setDateTime(QDateTime::currentDateTime());
    on_textEditMessage_textChanged();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_scene;
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

void MainWindow::on_btn_planifier_clicked()
{
    QDateTime heure = ui->heure->dateTime();
    QString msg = ui->textEditMessage->toPlainText();

    m_pilote->planifierUneTache(msg, heure);

    ui->textEditMessage->setText(QString());
    ui->heure->setDateTime(QDateTime::currentDateTime());
}

void MainWindow::on_btn_actualiser_clicked()
{
    ui->heure->setDateTime(QDateTime::currentDateTime());
}

void MainWindow::on_textEditMessage_textChanged()
{
    if(ui->textEditMessage->toPlainText().isEmpty())
    {
        ui->btn_planifier->setEnabled(false);
    }else
    {
        ui->btn_planifier->setEnabled(true);
    }
}
