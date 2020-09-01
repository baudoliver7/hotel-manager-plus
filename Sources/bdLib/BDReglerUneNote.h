#ifndef BDREGLERUNENOTE_H
#define BDREGLERUNENOTE_H

#include "bdLib_global.h"
#include <QDialog>

#include "repasCompletResto.h"
#include "operationService.h"
#include "agent.h"
#include "horloge.h"

namespace Ui {
    class BDReglerUneNote;
}

class BDLIBSHARED_EXPORT BDReglerUneNote : public QDialog {
    Q_OBJECT
public:
    BDReglerUneNote(const agent & ag, int idRepasCResto, QWidget *parent = 0);
    ~BDReglerUneNote();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::BDReglerUneNote *ui;
    int m_idRepasCResto;
    agent * m_agent;

private slots:
    void on_spinBoxMontantEncaisse_valueChanged(int );
    void on_btn_ok_clicked();
    void on_btn_annuler_clicked();
};

#endif // BDREGLERUNENOTE_H
