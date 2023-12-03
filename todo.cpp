#include "todo.h"

#include <QVector>
#include <QString>
#include <QDateTime>
#include <QMap>

#include "action.h"

Todo::Todo() {
    this->actions = QVector<Action>();
}

void Todo::addAction(QString name) {
    int latestId = 0;
    if (!this->actions.empty()) {
        latestId = this->actions.last().getId();
    }
    Action newAction(latestId+1, name);

    this->actions.append(newAction);
}

void Todo::addEvent(QString name, QDateTime) {}

void Todo::deleteAction(int id) {
    // Find the index of the action with the specified id
    int indexToRemove = -1;
    for (int i = 0; i < this->actions.size(); ++i) {
        if (this->actions[i].getId() == id) {
            indexToRemove = i;
            break;
        }
    }

    // Remove the action if it was found
    if (indexToRemove != -1) {
        this->actions.remove(indexToRemove);
    }
}

QVector<Action> Todo::getActions() {
    return this->actions;
}
