#include "BDWaiting.h"
#include "ui_BDWaiting.h"

BDWaiting::BDWaiting(QWidget *parent) :
    QDialog(0),
    ui(new Ui::BDWaiting)
{
    ui->setupUi(this);
    setParent(parent);
    setWindowFlags(Qt::ToolTip | Qt::WindowStaysOnTopHint);
}

BDWaiting::~BDWaiting()
{
    delete ui;
}

void BDWaiting::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void BDWaiting::lancerTacheAExecuter()
{
    emit excuterTache();
}
