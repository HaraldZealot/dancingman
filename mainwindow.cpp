#include "mainwindow.h"
#include "centralwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(new CentralWidget);
}

MainWindow::~MainWindow()
{
}
