#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Horloge.h"
#include "bdd.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(Horloge * horloge, BDD * db, QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Horloge * m_horloge;
    BDD * m_db;

private slots:
    void afficherHeure();
    void warningDBState();
};

#endif // MAINWINDOW_H
