#include "event.h"

Event::Event(int id, QString name, QDateTime time)
    : Action(id, name), eventTime(time)
{}

int Event::getType() const {
    return 1;
}

QTime Event::getTimeUntilEvent()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    qint64 timeUntilEventInSeconds = currentTime.secsTo(eventTime);

    // If the event has already occurred, make timeUntilEventInSeconds positive
    if (timeUntilEventInSeconds < 0) {
        timeUntilEventInSeconds = -timeUntilEventInSeconds;
    }

    // Convert seconds to QTime
    int hours = static_cast<int>(timeUntilEventInSeconds / 3600);
    int minutes = static_cast<int>((timeUntilEventInSeconds % 3600) / 60);
    int seconds = static_cast<int>(timeUntilEventInSeconds % 60);

    return QTime(hours, minutes, seconds);
}

QString Event::getTimeUntilEventString()
{
    QTime timeUntilEvent = getTimeUntilEvent();

    // Check if the event is in the future
    if (eventTime > QDateTime::currentDateTime()) {
        return "in " + timeUntilEvent.toString("hh:mm:ss");
    } else {
        return "happened " + timeUntilEvent.toString("hh:mm:ss") + " ago";
    }
}
