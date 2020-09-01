#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlDatabase>

#include "factureHotelIndividu.h"
#include "factureHotelGroupe.h"
#include "factureRestoGroupe.h"
#include "factureRestoIndividu.h"
#include "operationService.h"
#include "recu.h"
#include "actualiser.h"
#include "etage.h"
#include "PlanComptable.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QSqlDatabase * db, QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QSqlDatabase * m_db;
    QGraphicsTextItem * m_titre;
    //factureHotelGroupe * m_facture;
    QGraphicsView * m_view;
    double x0;
    double y0;

private slots:
    void on_doubleSpinBoxY_valueChanged(double );
    void on_doubleSpinBoxX_valueChanged(double );
    void on_btn_imprimer_clicked();
};

#endif // MAINWINDOW_H
