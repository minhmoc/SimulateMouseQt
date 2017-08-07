#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QApplication>
#include <QMouseEvent>
#include <QDebug>
#include <QtTest/QTest>
#include <QDesktopWidget>
#include <simulate_mouse.h>
#include <simulate_keyboard.h>

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

void MainWindow::on_siml_mouse_clicked()
{
    //    QCursor::setPos(mapToGlobal(QPoint(QUIT_BUTTON_X,QUIT_BUTTON_Y)).x(),
    //    mapToGlobal(QPoint(QUIT_BUTTON_X,QUIT_BUTTON_Y)).y());//use global position
    //    qDebug() << "cursor move to " << mapToGlobal(QPoint(QUIT_BUTTON_X, QUIT_BUTTON_Y));

    //    QMouseEvent *press_event = new QMouseEvent(QEvent::MouseButtonPress, QPointF(0, 0),
    //                                         Qt::LeftButton, Qt::LeftButton, 0);//use local position to receiver widget
    //    QMouseEvent *release_event = new QMouseEvent(QEvent::MouseButtonRelease, QPointF(30, 10),
    //                                         Qt::LeftButton, 0, 0);
    //    qDebug() << findChild<QLineEdit*>(QString("lineEdit"));
    //    QApplication::sendEvent(findChild<QLineEdit*>(QString("lineEdit")), press_event);//propagate even: from child to parent. child always on the top.
    //    QApplication::sendEvent(findChild<QLineEdit*>(QString("lineEdit")), release_event);
    //    findChild<QLineEdit*>(QString("lineEdit"))->setFocus();//with LineEdit, cursor blink only when line edit has focus. dont need if send event to button.

    //    QTest::mouseClick(findChild<QLineEdit*>(QString("lineEdit")), Qt::LeftButton, Qt::NoModifier);//auto gain focus and then simulate keyboard
    //    QTest::keyClicks(findChild<QLineEdit*>(QString("lineEdit")),"Hello");

    /* the following try to simulate mouse click on desktop. But not work at all. QWidgetDesktop only
     * give information about desktop, e.x. size, but not the handle of desktop. Must use hwnd of WIN API
    QDesktopWidget *desktop = QApplication::desktop();
    QCursor::setPos(desktop->width()/2.0, desktop->height()/2.0);//use global position
    desktop->setFocus();
    QTest::mouseClick(desktop->screen(), Qt::RightButton, Qt::NoModifier, QPoint(QCursor::pos()));
    */

    QDesktopWidget *desktop = QApplication::desktop();
    SendRightClick(desktop->width()/2.0, desktop->height()/2.0);
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

void MainWindow::on_siml_keyboard_clicked()
{
    QLineEdit *lineEdit = findChild<QLineEdit*>(QString("lineEdit"));
    if(lineEdit->text() != QString::null)
    SendKeyStroke(lineEdit->text().at(0).toLatin1());
}
