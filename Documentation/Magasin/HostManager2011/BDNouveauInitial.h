#ifndef BDNOUVEAUINITIAL_H
#define BDNOUVEAUINITIAL_H

#include <QDialog>
#include "NomDesQWidgets.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QCloseEvent>
#include "InfosSurBD.h"
#include <QMessageBox>

namespace Ui {
    class BDNouveauInitial;
}

class BDNouveauInitial : public QDialog {
    Q_OBJECT
public:
    BDNouveauInitial(QWidget *parent = 0);
    ~BDNouveauInitial();

    inline bool accepte(){return m_accepted;};
    QString typeDeChambre();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDNouveauInitial *ui;
    bool m_accepted;
private:
    bool initialExisteDeja(QString initial);
    void enregistrerInitial();

private slots:


private slots:
    void on_btn_Annuler_clicked();
    void on_btn_OK_clicked();
};

#endif // BDNOUVEAUINITIAL_H
