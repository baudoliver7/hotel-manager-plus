#ifndef BDACTIVERNVCPTE_H
#define BDACTIVERNVCPTE_H

#include "bdLib_global.h"

#include <QDialog>
#include <QAbstractButton>
#include "horloge.h"
#include "agent.h"

#define ADMINISTRATION 1
#define COMPTABILITE 2
#define RECEPTION 3

namespace Ui {
    class BDActiverNvCpte;
}

class BDLIBSHARED_EXPORT  BDActiverNvCpte : public QDialog {
    Q_OBJECT
public:
    BDActiverNvCpte(int idService, QWidget *parent = 0);
    ~BDActiverNvCpte();

    inline bool fermer()const{return m_fermer;};
    inline agent utilisateur()const{return *m_recepteur;};

protected:
    void changeEvent(QEvent *e);
    bool m_fermer;
    bool m_matriculeValide;

private:
    Ui::BDActiverNvCpte *ui;
    agent * m_recepteur;
    int m_idService;

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
    void updateBtnOK();
    void on_lineEditMatricule_textChanged(QString );
};

#endif // BDACTIVERNVCPTE_H
