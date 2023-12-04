#include "action.h"

#include <QString>
#include <QDateTime>

#ifndef EVENT_H
#define EVENT_H

class Event : public Action
{
public:
    Event(int id, QString name, QDateTime time);
    QTime getTimeUntilEvent();
    QString getTimeUntilEventString();
    int getType() const override;
private:
    QDateTime eventTime;
};

#endif // EVENT_H
