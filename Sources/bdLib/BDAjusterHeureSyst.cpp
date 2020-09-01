#include "BDAjusterHeureSyst.h"
#include "ui_BDAjusterHeureSyst.h"

BDAjusterHeureSyst::BDAjusterHeureSyst(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDAjusterHeureSyst)
{
    ui->setupUi(this);
}

BDAjusterHeureSyst::BDAjusterHeureSyst(QDate date, QTime heure, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDAjusterHeureSyst)
{
    ui->setupUi(this);

    ui->calendarWidget->setSelectedDate(date);
    ui->timeEdit->setTime(heure);
}

BDAjusterHeureSyst::~BDAjusterHeureSyst()
{
    delete ui;
}

void BDAjusterHeureSyst::changeEvent(QEvent *e)
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

QDateTime BDAjusterHeureSyst::dateTimeSelectionnee()const
{
    QDateTime dateTime(ui->calendarWidget->selectedDate());
    dateTime.setTime(ui->timeEdit->time());

    return dateTime;
}
