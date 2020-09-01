#ifndef BDRECHERCHERUTIL_H
#define BDRECHERCHERUTIL_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlDatabase>

namespace Ui {
    class BDRechercherUtil;
}

class BDRechercherUtil : public QDialog {
    Q_OBJECT
public:
    BDRechercherUtil(QSqlDatabase db, QWidget *parent = 0);
    ~BDRechercherUtil();

    inline QSqlRecord record()const{return m_record;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDRechercherUtil *ui;
    QSqlTableModel * m_model;
    QSqlRecord m_record;
    QSqlDatabase m_db;

    void initialiserModel();

private slots:
    void updateBtnChoisir(QModelIndex index);
    void chargerUtilisateurs();
    void on_btn_Annuler_clicked();
    void on_btn_choisir_clicked();
};

#endif // BDRECHERCHERUTIL_H
