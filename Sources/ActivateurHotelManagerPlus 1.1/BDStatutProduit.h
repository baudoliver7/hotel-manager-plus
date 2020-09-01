#ifndef BDSTATUTPRODUIT_H
#define BDSTATUTPRODUIT_H

#include <QDialog>
#include <QSettings>

#define APPNAME "HMP's product win32"
#define INSTALLATIONID "Installation id"
#define KEY "clé d'utilisation"
#define PARAMSCONNECTION "Paramètres de connection"

namespace Ui {
    class BDStatutProduit;
}

class BDStatutProduit : public QDialog {
    Q_OBJECT
public:
    BDStatutProduit(QWidget *parent = 0);
    ~BDStatutProduit();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDStatutProduit *ui;
    QString m_productName;

private slots:
    void on_comboBoxNomProduit_currentIndexChanged(QString );
    void on_btn_supprimer_clicked();
    void on_btn_fermer_clicked();
};

#endif // BDSTATUTPRODUIT_H
