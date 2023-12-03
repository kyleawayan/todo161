#ifndef EVENTDIALOG_H
#define EVENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QPushButton>
#include <QFormLayout>

class EventDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EventDialog(QWidget *parent = nullptr);
    QString getEventName() const;
    QDateTime getEventDateTime() const;

private:
    QLineEdit *eventNameEdit;
    QDateTimeEdit *eventDateTimeEdit;
};

#endif // EVENTDIALOG_H
