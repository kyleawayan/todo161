#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QIcon>
#include <QListWidgetItem>
#include <QInputDialog>
#include <QLCDNumber>

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

    // Create toolbar buttons
    QPushButton *addButton = new QPushButton("Add Action", this);
    connect(addButton, &QPushButton::clicked, this, &TodoWidget::addItem);
    QPushButton *deleteButton = new QPushButton("Mark Completed", this);
    connect(deleteButton, &QPushButton::clicked, this, &TodoWidget::removeItem);

    // Create a QListWidget
    listWidget = new QListWidget(this);
    listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

    // Create LCD screen
    lcdScreen = new QLCDNumber(this);
    lcdScreen->setSegmentStyle(QLCDNumber::Flat);
    lcdScreen->setMinimumHeight(50);

    // Add widgets to the toolbar layout
    toolbarLayout->addWidget(addButton);
    toolbarLayout->addWidget(deleteButton);

    // Add widgets to the main layout
    mainLayout->addWidget(lcdScreen);
    mainLayout->addWidget(toolbarWidget);
    mainLayout->addWidget(listWidget);

    // Set the main layout for the custom widget
    setLayout(mainLayout);
}

void TodoWidget::addItem()
{
    bool ok;
    QInputDialog* inputDialog = new QInputDialog();
    QString text = QInputDialog::getText(this, tr("Add Action"),
                                        tr("What do you need to do?"), QLineEdit::Normal,
                                        "" ,&ok);
    if (ok && !text.isEmpty()) {
        this->mainTodo.addAction(text);
        this->updateList();
    }
    delete inputDialog;
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
    int actionsCount = actions.length();
    this->lcdScreen->display(actionsCount);

    for (Action &action : actions)
    {
        int latestRow = this->listWidget->currentRow();
        QListWidgetItem *widgetItem = new QListWidgetItem(action.getName());
        widgetItem->setData(99, action.getId());
        this->listWidget->insertItem(latestRow, widgetItem);
    }
}
