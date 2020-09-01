#include "BDWait.h"
#include "ui_BDWait.h"

BDWait::BDWait(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDWait)
{
    ui->setupUi(this);
    setWindowTitle("Connexion en cours");
    m_fermer = false;
}

BDWait::~BDWait()
{
    delete ui;
}

void BDWait::changeEvent(QEvent *e)
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

void BDWait::closeEvent(QCloseEvent *e)
{
    if(m_fermer)
    {
        e->accept();
    }else
    {
        e->ignore();
    }
}

void BDWait::wait(int msec)
{
    m_fermer = false;
    QTimer::singleShot(msec, this, SLOT(stop()));
    exec();
}

void BDWait::stop()
{
    m_fermer = true;
    accept();
}
