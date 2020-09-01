#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include "bdLib_global.h"

/* classes qt */
#include <QDialog>

/* classes personnalisées */
#include "agent.h"
#include "BDWait.h"
#include "serviceEntreprise.h"

namespace Ui {
    class DialogConnexion;
}

class BDLIBSHARED_EXPORT DialogConnexion : public QDialog {
    Q_OBJECT
public:
    DialogConnexion(serviceEntreprise * service, QWidget *parent = 0);
    ~DialogConnexion();

public:
    inline agent & utilisateur()const{return *m_agent;};

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogConnexion *ui;
    agent * m_agent;
    serviceEntreprise * m_service;

    QString login();
    QString password();

    void deconnecterTousLesComptesInactifs();

private slots:
    void on_btn_Annuler_clicked();
    void on_btn_OK_clicked();
};

#endif // DIALOGCONNEXION_H
