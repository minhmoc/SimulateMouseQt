#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(QApplication *, QWidget *, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
public:
    void simulateMouse(QMouseEvent*);
public slots:
    void sendEvent();
private:
    QApplication *app;
    QWidget *recvWidget;
    QMouseEvent *event;
};

#endif // MAINWINDOW_H
