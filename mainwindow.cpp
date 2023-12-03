#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "todowidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // ui->setupUi(this);
    setCentralWidget(new TodoWidget());
    setWindowTitle("todo161");
}

MainWindow::~MainWindow()
{
    delete ui;
}
