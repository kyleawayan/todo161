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

    // Create a QListWidget
    listWidget = new QListWidget(this);
    listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    // Add widgets to the toolbar layout
    toolbarLayout->addWidget(addButton);

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

void TodoWidget::updateList()
{
    this->listWidget->clear();

    QVector<Action> actions = this->mainTodo.getActions();
    for (Action &action : actions)
    {
        int latestRow = this->listWidget->currentRow();
        QListWidgetItem *widgetItem = new QListWidgetItem(action.getName());
        this->listWidget->insertItem(latestRow, widgetItem);
    }
}
