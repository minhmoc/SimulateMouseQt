#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QApplication>
#include <QMouseEvent>
#include <QDebug>
#include <windows.h>
#include <QtTest/QTest>
#define QUIT_BUTTON_X 50
#define QUIT_BUTTON_Y 60
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mouse press event: " << QCursor::pos();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse release event: " << QCursor::pos();
}

void MainWindow::simulateMouse(QMouseEvent *e)
{
    event = e;
}

void MainWindow::on_quit_clicked()
{
    qDebug() << "Clicked";
}

void MainWindow::on_start_clicked()
{
//    QCursor::setPos(mapToGlobal(QPoint(QUIT_BUTTON_X,QUIT_BUTTON_Y)).x(),
//                        mapToGlobal(QPoint(QUIT_BUTTON_X,QUIT_BUTTON_Y)).y());//use global position
//    qDebug() << "cursor move to " << mapToGlobal(QPoint(QUIT_BUTTON_X, QUIT_BUTTON_Y));

    QMouseEvent *press_event = new QMouseEvent(QEvent::MouseButtonPress, QPointF(0, 0),
                                         Qt::LeftButton, Qt::LeftButton, 0);//use local position to receiver widget
    QMouseEvent *release_event = new QMouseEvent(QEvent::MouseButtonRelease, QPointF(30, 10),
                                         Qt::LeftButton, 0, 0);
    qDebug() << findChild<QLineEdit*>(QString("lineEdit"));
    QApplication::sendEvent(findChild<QLineEdit*>(QString("lineEdit")), press_event);//propagate even: from child to parent. child always on the top.
    QApplication::sendEvent(findChild<QLineEdit*>(QString("lineEdit")), release_event);
    findChild<QLineEdit*>(QString("lineEdit"))->setFocus();//with LineEdit, cursor blink only when line edit has focus. dont need if send event to button.
//    QTest::mouseClick(findChild<QLineEdit*>(QString("lineEdit")), Qt::LeftButton, Qt::NoModifier);//auto gain focus and then simulate keyboard
//    QTest::keyClicks(findChild<QLineEdit*>(QString("lineEdit")),"Hello");
}

QApplication *MainWindow::getApp() const
{
    return app;
}

void MainWindow::setApp(QApplication *value)
{
    app = value;
}

void MainWindow::on_quit_pressed()
{
    qDebug() << "Pressed";
}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    qDebug() << "on cursor postion changed";
}

void MainWindow::on_lineEdit_selectionChanged()
{
    qDebug() << "on selection changed";
}
