#ifndef ACTION_H
#define ACTION_H

#include <QString>

class Action
{
public:
    Action(int id, QString name);
    void markAsCompleted();
    int getId();
    QString getName();
private:
    int id;
    QString name;
    bool completed;
};

#endif // ACTION_H
