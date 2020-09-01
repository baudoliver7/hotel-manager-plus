#include "DialogCalendar.h"
#include "ui_DialogCalendar.h"
#include <QDialogButtonBox>
#include <QPushButton>

DialogCalendar::DialogCalendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCalendar)
{    
    ui->setupUi(this);    

    connect(ui->calendarWidget, SIGNAL(currentPageChanged(int,int)),  this, SLOT(disableBtnOKState()));
    connect(ui->calendarWidget, SIGNAL(selectionChanged()),  this, SLOT(enableBtnOKState()));
}

DialogCalendar::DialogCalendar(QDate date, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCalendar)
{
    ui->setupUi(this);
    ui->calendarWidget->setSelectedDate(date);
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

void DialogCalendar::disableBtnOKState()
{
    QPushButton * button = ui->buttonBox->button(QDialogButtonBox::Ok);
    button->setEnabled(false);
}

void DialogCalendar::enableBtnOKState()
{
    QPushButton * button = ui->buttonBox->button(QDialogButtonBox::Ok);
    button->setEnabled(true);
}
