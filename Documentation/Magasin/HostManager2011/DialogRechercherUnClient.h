#ifndef DIALOGRECHERCHERUNCLIENT_H
#define DIALOGRECHERCHERUNCLIENT_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

#include "InfosSurBD.h"

namespace Ui {
    class DialogRechercherUnClient;
}

class DialogRechercherUnClient : public QDialog {
    Q_OBJECT
public:
    DialogRechercherUnClient(QWidget *parent = 0);
    ~DialogRechercherUnClient();

    QSqlRecord clientChoisi();
    bool occuperUneChambre();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogRechercherUnClient *ui;
    QSqlTableModel * m_clients;

private slots:
    void on_btn_Annuler_clicked();
    void updateEtatDesWidgets(QModelIndex);
    void on_lineEditNom_textChanged(QString);
    void on_btn_OK_clicked();
    void rafraichirTableau();

private:
    bool estUnHomme();
    void afficherClients(QString debutNom, bool sexe);
    void initialiserTableau();
    void initialiserModel();
};

#endif // DIALOGRECHERCHERUNCLIENT_H
