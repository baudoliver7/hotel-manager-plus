#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

/* classes qt */
#include <QDialog>

/* classes personnalisées */
#include "recepteur.h"

namespace Ui {
    class DialogConnexion;
}

class DialogConnexion : public QDialog {
    Q_OBJECT
public:
    DialogConnexion(QWidget *parent = 0);
    ~DialogConnexion();

public:
    recepteur * m_recepteur;

    inline recepteur & utilisateur()const{return *m_recepteur;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogConnexion *ui;

    QString login();
    QString password();


private slots:
    void on_btn_passer_clicked();
    void on_btn_Annuler_clicked();
    void on_btn_OK_clicked();
};

#endif // DIALOGCONNEXION_H
