#ifndef DIALOGCALENDAR_H
#define DIALOGCALENDAR_H

#include <QDialog>
#include <QString>
#include <QDate>

namespace Ui {
    class DialogCalendar;
}

class DialogCalendar : public QDialog {
    Q_OBJECT
public:
    DialogCalendar(QWidget *parent = 0);
    ~DialogCalendar();

    QDate dateSeclectionnee();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DialogCalendar *ui;
};

#endif // DIALOGCALENDAR_H
