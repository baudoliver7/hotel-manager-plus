#ifndef FENSERVICERECEPTION_H
#define FENSERVICERECEPTION_H

/* classes de qt */
#include <QCloseEvent>
#include <QMessageBox>

/* classes personnalisées */
#include "recepteur.h"


/* définitions */
#define NBMAXCHAMBRESVENTILEES 100
#define NBMAXCHAMBRESCLIMATISEES 100
#define NBMAXSUITES 100
#define NUIT "Une nuit"

#define CHAMBRE 0
#define OCCUPANT 1
#define DATE_ENTREE 2
#define DATE_SORTIE 3
#define CODE_CLIENT 4

#define OCCUPER_UNE_CHAMBRE 0
#define RESERVER_UNE_CHAMBRE 1

namespace Ui {
    class FenServiceReception;
}

class FenServiceReception : public QWidget {
    Q_OBJECT
public:
    FenServiceReception(const recepteur * r, QWidget *parent = 0);
    ~FenServiceReception();

    bool seDeconnecter();
    inline void setFermer(bool fermer){m_fermer = fermer;};

signals:
    void closed();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *e);

private:
    Ui::FenServiceReception *ui;
    recepteur * m_recepteur;
    bool m_fermer;

private slots:

};

#endif // FENSERVICERECEPTION_H
