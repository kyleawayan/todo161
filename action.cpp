#include "action.h"

#include <QString>

Action::Action(int id, QString name) {
    this->id = id;
    this->name = name;
}

int Action::getId() {
    return this->id;
}

QString Action::getName() {
    return this->name;
}
