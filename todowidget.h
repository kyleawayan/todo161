#ifndef TODOWIDGET_H
#define TODOWIDGET_H

#include <QWidget>
#include <QListWidget>
#include "todo.h"

class TodoWidget : public QWidget
{
    Q_OBJECT
public:
    Todo mainTodo;
    explicit TodoWidget(QWidget *parent = nullptr);
private:
    QListWidget *listWidget;
    void addItem();
    void updateList();
};

#endif // TODOWIDGET_H
