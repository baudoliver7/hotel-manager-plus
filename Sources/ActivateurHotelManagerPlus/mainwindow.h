#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QDesktopServices>
#include <QUrl>

#include "MdiModeDiffere.h"
#include "BDConnexion.h"
#include "BDStatutProduit.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QSqlDatabase db, QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;

    void updateEtatsActions(bool connecte);

private slots:
    void on_actionWin64_triggered();
    void on_actionWin32_triggered();
    void on_actionStatut_d_un_produit_triggered();
    void on_actionQuitter_triggered();
    void on_actionEn_diff_r_triggered();
};

#endif // MAINWINDOW_H
