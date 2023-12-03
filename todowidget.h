#ifndef TODOWIDGET_H
#define TODOWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QLCDNumber>
#include "todo.h"

class TodoWidget : public QWidget
{
    Q_OBJECT
public:
    Todo mainTodo;
    QLCDNumber *lcdScreen;
    explicit TodoWidget(QWidget *parent = nullptr);
private:
    QListWidget *listWidget;
    void addItem();
    void addEvent();
    void removeItem();
    void updateList();
};

#endif // TODOWIDGET_H
