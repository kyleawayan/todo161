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
    int latestId = this->actions.last().getId();
    Action newAction(latestId+1, name);

    this->actions.append(newAction);
    emit actionsChanged(this->actions);
}

void Todo::addEvent(QString name, QDateTime) {}

void Todo::deleteAction(int id) {
    this->deleteAction(id);
    emit actionsChanged(this->actions);
}

QVector<Action> Todo::getActions() {
    return this->actions;
}
