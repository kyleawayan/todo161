#include "event.h"

Event::Event(int id, QString name, QDateTime time)
    : Action(id, name), eventTime(time)
{}

QTime Event::getTimeUntilEvent()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    qint64 timeUntilEventInSeconds = currentTime.secsTo(eventTime);

    // Convert seconds to QTime
    int hours = static_cast<int>(timeUntilEventInSeconds / 3600);
    int minutes = static_cast<int>((timeUntilEventInSeconds % 3600) / 60);
    int seconds = static_cast<int>(timeUntilEventInSeconds % 60);

    return QTime(hours, minutes, seconds);
}
