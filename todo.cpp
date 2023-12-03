#include "todo.h"

#include <QVector>
#include <QString>
#include <QDateTime>
#include <QMap>

#include "action.h"
#include "event.h"

Todo::Todo() {
    this->actions = QVector<Action*>();
}

int Todo::getLastId() {
    int latestId = 0;
    if (!this->actions.empty()) {
        latestId = this->actions.last()->getId();
    }
    return latestId;
}

void Todo::addAction(QString name) {
    int latestId = this->getLastId();

    Action* newAction = new Action(latestId+1, name);
    this->actions.append(newAction);
}

void Todo::addEvent(QString name, QDateTime time) {
    int latestId = this->getLastId();

    Event* newEvent = new Event(latestId+1, name, time);
    this->actions.append(newEvent);
}

void Todo::deleteAction(int id) {

    int indexToRemove = -1;
    for (int i = 0; i < this->actions.size(); ++i) {
        if (this->actions[i]->getId() == id) {
            indexToRemove = i;
            break;
        }
    }

    // Remove the action if it was found
    if (indexToRemove != -1) {
        // Delete object
        delete this->actions[indexToRemove];
        // Remove pointer from vector
        this->actions.remove(indexToRemove);
    }
}

QVector<Action*> Todo::getActions() {
    return this->actions;
}
