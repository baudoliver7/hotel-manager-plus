#ifndef BDMODIFIERUNECHAMBRE_H
#define BDMODIFIERUNECHAMBRE_H

#include <QDialog>
#include "NomDesQWidgets.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "Chambre.h"
#include <QMessageBox>
#include "BDNouveauInitial.h"
#include "InfosSurBD.h"
#include <QSqlRecord>

namespace Ui {
    class BDModifierUneChambre;
}

class BDModifierUneChambre : public QDialog {
    Q_OBJECT
public:
    BDModifierUneChambre(QSqlRecord record, QWidget *parent = 0);
    ~BDModifierUneChambre();

    QString initial();
    int numero();
    QString identifiant();
    QString typeDeChambre();
    int idTypeDeChambre();

protected:
    void changeEvent(QEvent *e);


private:
    Ui::BDModifierUneChambre *ui;
    QSqlTableModel * m_model;
    BDNouveauInitial * m_bdNouveauInitial;
    QMessageBox avertisseur;

private:
    void chargerInitial(QString typeDeChambre);
    void initialiserModel();
    void initialiserComboBoxInitial();
    void initialiserBDNouveauInitial();
    QString trouverInitiauxPourCeTypeDeChambre(QString typeDeChambre);
    void afficherChambre(QSqlRecord record);

private slots:
    void on_btn_nouveauInitial_clicked();
    void on_comboBoxTypeDeCh_currentIndexChanged(int index);
};

#endif // BDMODIFIERUNECHAMBRE_H
