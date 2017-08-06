#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QApplication>
#include <QMouseEvent>
#include <QDebug>
#include <windows.h>
#include <QtTest/QTest>
#include <QDesktopWidget>
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

    const double XSCALEFACTOR = 65535/(double)(desktop->width() - 1);
    const double YSCALEFACTOR = 65535/(double)(desktop->height() - 1);

    double x = desktop->width()/2.0 * XSCALEFACTOR;
    double y = desktop->height()/2.0 * YSCALEFACTOR;

    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;//must have MOUSEEVENTF_MOVE

    SendInput(1,  &input, sizeof(INPUT));
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
