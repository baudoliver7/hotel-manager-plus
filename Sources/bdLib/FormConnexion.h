#ifndef FORMCONNEXION_H
#define FORMCONNEXION_H

#include "bdLib_global.h"

#include <QWidget>

#include "agent.h"
#include "BDWait.h"
#include "serviceEntreprise.h"

namespace Ui {
    class FormConnexion;
}

class BDLIBSHARED_EXPORT FormConnexion : public QWidget {
    Q_OBJECT
public:
    FormConnexion(serviceEntreprise * service, QWidget *parent = 0);
    ~FormConnexion();

    inline agent & utilisateur()const{return *m_agent;};

signals:
    void accepted();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::FormConnexion *ui;
    agent * m_agent;
    serviceEntreprise * m_service;

    QString login();
    QString password();

private slots:
    void valider();
    void deconnecterTousLesComptesInactifs();
};

#endif // FORMCONNEXION_H
