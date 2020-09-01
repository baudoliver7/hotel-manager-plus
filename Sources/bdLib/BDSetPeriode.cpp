#include "BDSetPeriode.h"
#include "ui_BDSetPeriode.h"

BDSetPeriode::BDSetPeriode(QDate debut, QDate fin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDSetPeriode)
{
    ui->setupUi(this);

    m_dateDebut = debut;
    m_dateFin = fin;

    ui->dateDebut->setText(m_dateDebut.toString(Qt::SystemLocaleLongDate));
    ui->dateFin->setText(m_dateFin.toString(Qt::SystemLocaleLongDate));

    connect(ui->btn_annuler, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->btn_ok, SIGNAL(clicked()), this, SLOT(accept()));

    connect(ui->btn_dateDebut, SIGNAL(clicked()), this, SLOT(setDateDebut()));
    connect(ui->btn_dateFin, SIGNAL(clicked()), this, SLOT(setDateFin()));

    m_modified = false;
}

BDSetPeriode::~BDSetPeriode()
{
    delete ui;
}

void BDSetPeriode::changeEvent(QEvent *e)
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

QDate BDSetPeriode::dateDebut()
{
    return m_dateDebut;
}

QDate BDSetPeriode::dateFin()
{
    return m_dateFin;
}

void BDSetPeriode::setDateDebut()
{
    DialogCalendar * bdCalendar = new DialogCalendar(this);
    bdCalendar->setWindowTitle("Date de début");
    if(bdCalendar->exec() == QDialog::Accepted)
    {
        QDate date = bdCalendar->dateSeclectionnee();
        m_modified = true;
        if(date <= m_dateFin)
        {
            m_dateDebut = date;
            ui->dateDebut->setText(date.toString(Qt::SystemLocaleLongDate));
        }else
        {
            m_dateDebut = m_dateFin;
            ui->dateDebut->setText(m_dateFin.toString(Qt::SystemLocaleLongDate));
        }
    }

    delete bdCalendar;
}

void BDSetPeriode::setDateFin()
{
    DialogCalendar * bdCalendar = new DialogCalendar(this);
    bdCalendar->setWindowTitle("Date de fin");

    if(bdCalendar->exec() == QDialog::Accepted)
    {
        QDate date = bdCalendar->dateSeclectionnee();
        m_modified = true;
        if(date >= m_dateDebut)
        {
            m_dateFin = date;
            ui->dateFin->setText(date.toString(Qt::SystemLocaleLongDate));
        }else
        {
            m_dateFin = m_dateDebut;
            ui->dateFin->setText(m_dateDebut.toString(Qt::SystemLocaleLongDate));
        }
    }

    delete bdCalendar;
}

bool BDSetPeriode::isModified()
{
    return m_modified;
}
