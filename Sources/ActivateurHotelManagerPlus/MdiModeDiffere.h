#ifndef MDIMODEDIFFERE_H
#define MDIMODEDIFFERE_H

#include <QWidget>
#include <QSettings>
#include <QMessageBox>
#include <QSqlError>
#include <QProcess>
#include <QSqlDatabase>

#include "DialogContact.h"
#include "BDRechercherUtil.h"
#include "HeureLimite.h"

#define DSN "clientele"

#define APPNAME "HMP's product win32"
#define INSTALLATIONID "Installation id"
#define KEY "clé d'utilisation"
#define PARAMSCONNECTION "Paramètres de connection"

namespace Ui {
    class MdiModeDiffere;
}

class MdiModeDiffere : public QWidget {
    Q_OBJECT
public:
    MdiModeDiffere(QSqlDatabase db, QWidget *parent = 0);
    ~MdiModeDiffere();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MdiModeDiffere *ui;
    int m_numInst;
    QSqlRecord m_record;
    QSqlDatabase m_dbMySql;
    QString productName;
    QString nomActiva;
    QSqlDatabase m_db;

    void setUtilisateurEnabled(bool enabled);
    void afficherUtilisateur(QSqlRecord record);

private slots:
    void on_comboBoxNomProduit_currentIndexChanged(int index);
    void on_btn_charger_clicked();
    void updateBtnActiver();
    void on_btn_test_clicked();
    void on_btn_activer_clicked();
    void on_btn_initialiser_clicked();
    void on_btn_rechercheUtil_clicked();
    void on_btn_contacts_clicked();
};

#endif // MDIMODEDIFFERE_H
