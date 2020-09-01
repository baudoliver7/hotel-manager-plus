#ifndef DIALOGCALENDAR_H
#define DIALOGCALENDAR_H

#include "bdLib_global.h"

#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
    class DialogCalendar;
}

class BDLIBSHARED_EXPORT DialogCalendar : public QDialog {
    Q_OBJECT
public:
    DialogCalendar(QWidget *parent = 0);
    DialogCalendar(QDate date, QWidget *parent = 0);
    ~DialogCalendar();

    QDate dateSeclectionnee();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogCalendar *ui;

private slots:
    void disableBtnOKState();
    void enableBtnOKState();
};

#endif // DIALOGCALENDAR_H
