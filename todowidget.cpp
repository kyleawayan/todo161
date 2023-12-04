#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QIcon>
#include <QListWidgetItem>
#include <QInputDialog>
#include <QLCDNumber>
#include <QLabel>
#include <QTimer>

#include "todowidget.h"
#include "todo.h"
#include "eventdialog.h"
#include "event.h"

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
    QPushButton *addEvent = new QPushButton("Add Event", this);
    connect(addEvent, &QPushButton::clicked, this, &TodoWidget::addEvent);
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
    toolbarLayout->addWidget(addEvent);
    toolbarLayout->addWidget(deleteButton);

    // What do you need to do today?
    QLabel* label = new QLabel(this);
    label->setText("Things to do:");

    // Add widgets to the main layout
    mainLayout->addWidget(lcdScreen);
    mainLayout->addWidget(toolbarWidget);
    mainLayout->addWidget(label);
    mainLayout->addWidget(listWidget);

    // Update countdowns
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TodoWidget::updateCountdowns);
    timer->start(1000);

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
    if (ok) {
        this->mainTodo.addAction(text);
        this->updateList();
    }
    delete inputDialog;
}

void TodoWidget::addEvent()
{
    EventDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString eventName = dialog.getEventName();
        QDateTime eventDateTime = dialog.getEventDateTime();

        this->mainTodo.addEvent(eventName, eventDateTime);
        this->updateList();
    }
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

    QVector<Action*> actions = this->mainTodo.getActions();
    int actionsCount = actions.length();
    this->lcdScreen->display(actionsCount);

    for (Action* action : actions)
    {
        int latestRow = this->listWidget->currentRow();
        QListWidgetItem *widgetItem = new QListWidgetItem(action->getName());
        widgetItem->setData(99, action->getId());
        this->listWidget->insertItem(latestRow, widgetItem);
    }

    this->updateCountdowns();
}

void TodoWidget::updateCountdowns()
{
    for (int i = 0; i < this->listWidget->count(); i++)
    {
        QListWidgetItem* widgetItem = this->listWidget->item(i);
        int todoId = widgetItem->data(99).toInt();
        Action* todoItem = this->mainTodo.getActionById(todoId);

        if (todoItem->getType() != 1) {
            continue;
        }

        Event* eventItem = static_cast<Event*>(todoItem);

        QString remainingTimeString = eventItem->getTimeUntilEventString();
        QString actualEventName = eventItem->getName();
        QString spacer = QString(", ");

        QString sentence = actualEventName + spacer + remainingTimeString;

        widgetItem->setText(sentence);
    }
}
