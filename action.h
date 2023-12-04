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
    virtual int getType() const;
private:
    int id;
    QString name;
    bool completed;
};

#endif // ACTION_H
