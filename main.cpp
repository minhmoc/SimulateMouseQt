#include "mainwindow.h"
#include <QApplication>
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QTimer>
#include <QCursor>
#include <QDebug>
#include <QScreen>
#include <windows.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setApp(&a);
    w.show();
    w.setGeometry(0,0,w.width(),w.height());

    return a.exec();
}
