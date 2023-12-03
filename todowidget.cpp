#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QIcon>
#include <QListWidgetItem>

#include "todowidget.h"
#include "todo.h"

TodoWidget::TodoWidget(QWidget *parent)
    : QWidget(parent)
{
    // For simplicity just make the Todo class here
    Todo mainTodo;

    // Create a vertical layout for the main widget
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Create a toolbar widget
    QWidget *toolbarWidget = new QWidget(this);
    QHBoxLayout *toolbarLayout = new QHBoxLayout(toolbarWidget);

    // Create a QPushButton with a plus icon
    QPushButton *addButton = new QPushButton("Add item", this);
    connect(addButton, &QPushButton::clicked, this, &TodoWidget::addItem);

    QPushButton *deleteButton = new QPushButton("Mark completed", this);
    connect(deleteButton, &QPushButton::clicked, this, &TodoWidget::removeItem);

    // Create a QListWidget
    listWidget = new QListWidget(this);
    listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    // Add widgets to the toolbar layout
    toolbarLayout->addWidget(addButton);
    toolbarLayout->addWidget(deleteButton);

    // Add widgets to the main layout
    mainLayout->addWidget(toolbarWidget);
    mainLayout->addWidget(listWidget);

    // Set the main layout for the custom widget
    setLayout(mainLayout);
}

void TodoWidget::addItem()
{
    QString newItemText = "New Item";
    this->mainTodo.addAction(newItemText);
    this->updateList();
}

void TodoWidget::removeItem()
{
    QList<QListWidgetItem*> selectedItems = this->listWidget->selectedItems();

    for (QListWidgetItem* widgetItem : selectedItems)
    {
        int todoId = widgetItem->data(99).toInt();
        this->mainTodo.deleteAction(todoId);
    }
    this->updateList();
}

void TodoWidget::updateList()
{
    this->listWidget->clear();

    QVector<Action> actions = this->mainTodo.getActions();
    for (Action &action : actions)
    {
        int latestRow = this->listWidget->currentRow();
        QListWidgetItem *widgetItem = new QListWidgetItem(action.getName());
        widgetItem->setData(99, action.getId());
        this->listWidget->insertItem(latestRow, widgetItem);
    }
}
