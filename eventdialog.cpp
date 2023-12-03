#include "eventdialog.h"

EventDialog::EventDialog(QWidget *parent)
    : QDialog(parent)
{
    eventNameEdit = new QLineEdit(this);
    eventDateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(), this);
    eventDateTimeEdit->setCalendarPopup(true);

    QPushButton *okButton = new QPushButton(tr("OK"), this);
    QPushButton *cancelButton = new QPushButton(tr("Cancel"), this);

    QFormLayout *layout = new QFormLayout;
    layout->addRow(tr("Event Name:"), eventNameEdit);
    layout->addRow(tr("Event Date and Time:"), eventDateTimeEdit);
    layout->addRow(okButton, cancelButton);

    setLayout(layout);

    connect(okButton, &QPushButton::clicked, this, &EventDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &EventDialog::reject);
}

QString EventDialog::getEventName() const
{
    return eventNameEdit->text();
}

QDateTime EventDialog::getEventDateTime() const
{
    return eventDateTimeEdit->dateTime();
}
