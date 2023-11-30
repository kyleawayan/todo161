#ifndef TODO_H
#define TODO_H

#include <QVector>
#include <QString>
#include <QDateTime>
#include <QMap>
#include <QObject>

#include "action.h"

class Todo : public QObject
{
    Q_OBJECT;
public:
    Todo();
    void addAction(QString name);
    void addEvent(QString name, QDateTime date);
    void deleteAction(int id);
    QVector<Action> getActions();
private:
    QVector<Action> actions;
};

#endif // TODO_H
