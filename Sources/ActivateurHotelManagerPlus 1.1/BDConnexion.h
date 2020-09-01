#ifndef BDCONNEXION_H
#define BDCONNEXION_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlDatabase>

namespace Ui {
    class BDConnexion;
}

class BDConnexion : public QDialog {
    Q_OBJECT
public:
    BDConnexion(QSqlDatabase db, QWidget *parent = 0);
    ~BDConnexion();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDConnexion *ui;
    QSqlTableModel * m_model;
    QSqlDatabase m_db;

    void initialiserModel();

private slots:
    void on_btn_ok_clicked();
    void on_btn_annuler_clicked();
};

#endif // BDCONNEXION_H
