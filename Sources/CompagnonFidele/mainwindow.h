#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QGraphicsScene>

#include "PiloteCompagnonFidele.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    PiloteCompagnonFidele * m_pilote;
    QGraphicsScene * m_scene;

private slots:
    void on_textEditMessage_textChanged();
    void on_btn_actualiser_clicked();
    void on_btn_planifier_clicked();
};

#endif // MAINWINDOW_H
