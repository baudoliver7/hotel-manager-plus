#include "DialogCalendar.h"
#include "ui_DialogCalendar.h"

DialogCalendar::DialogCalendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCalendar)
{
    ui->setupUi(this);
}

DialogCalendar::~DialogCalendar()
{
    delete ui;
}

void DialogCalendar::changeEvent(QEvent *e)
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

QDate DialogCalendar::dateSeclectionnee()
{
    return ui->calendarWidget->selectedDate();
}
