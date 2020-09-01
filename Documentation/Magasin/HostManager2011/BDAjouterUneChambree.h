#ifndef BDAJOUTERUNECHAMBREE_H
#define BDAJOUTERUNECHAMBREE_H

#include <QDialog>
#include "NomDesQWidgets.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "Chambre.h"
#include <QMessageBox>
#include "BDNouveauInitial.h"
#include <QCloseEvent>
#include <QSqlRelationalTableModel>

#include "InfosSurBD.h"

namespace Ui {
    class BDAjouterUneChambre;
}

class BDAjouterUneChambre : public QDialog {
    Q_OBJECT
public:
    BDAjouterUneChambre(QWidget *parent = 0);
    ~BDAjouterUneChambre();

    QString initial();
    int numero();
    QString identifiant();
    int idTypeDeChambre();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *);

private:
    Ui::BDAjouterUneChambre *ui;
    QSqlTableModel * m_model;
    BDNouveauInitial * m_bdNouveauInitial;
    QMessageBox avertisseur;

private:
    void chargerInitial(QString typeDeChambre);
    void initialiserModel();
    void initialiserComboBoxInitial();
    void initialiserBDNouveauInitial();
    QString trouverInitiauxPourCeTypeDeChambre(QString typeDeChambre);

private slots:
    void on_btn_nouveauInitial_clicked();
    void on_comboBoxTypeDeCh_currentIndexChanged(int index);
};

#endif // BDAJOUTERUNECHAMBREE_H
