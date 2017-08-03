#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QApplication>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(sendEvent()));
    timer->start(1000);
}

MainWindow::MainWindow(QApplication *a, QWidget *w, QWidget *parent)
{
    Q_UNUSED(parent)

    app = a;
    recvWidget = w;
    event = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::simulateMouse(QMouseEvent *e)
{
    event = e;
}

void MainWindow::sendEvent()
{
    app->sendEvent(recvWidget, event);
}
