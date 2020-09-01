#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene();

    QRect rect = ui->graphicsView->rect();
    QRect rect1(5,5, rect.width() - 5, rect.height() - 5);
    m_scene->setSceneRect(rect1);
    ui->graphicsView->setScene(m_scene);
    QPixmap pixmap(":/ch.png");
    item1 = new QGraphicsPixmapItem(pixmap, 0, m_scene);
    item2 = new QGraphicsPixmapItem(pixmap, 0, m_scene);

    m_scene->addItem(item1);
    m_scene->addItem(item2);

    item1->setPos(5,5);
    item2->setPos(5 + item1->sceneBoundingRect().width() + 10,5);
}

MainWindow::~MainWindow()
{
    delete ui;

    m_scene->clear();
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

void MainWindow::on_btn_reduire_clicked()
{
    item1->setScale(0.5);
    item2->setScale(0.5);

    item1->setPos(5,5);
    item2->setPos(5 + item1->sceneBoundingRect().width() + 10 * 0.5, 5);
}
