#include "mainwindow.h"
#include <QApplication>
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QDesktopWidget *desktop = QApplication::desktop();
    desktop->setMouseTracking(true);

    QPointF desPos(desktop->width()/2.0, desktop->height()/2.0);

    QMouseEvent *event = new QMouseEvent(QEvent::MouseMove, desPos, Qt::NoButton, Qt::NoButton,Qt::NoModifier);

    MainWindow w(&a, desktop);
    w.simulateMouse(event);
    w.show();

    return a.exec();
}
