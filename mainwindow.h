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
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
public:
    void simulateMouse(QMouseEvent*);

    QApplication *getApp() const;
    void setApp(QApplication *value);

private slots:
    void on_quit_clicked();

    void on_siml_mouse_clicked();

    void on_quit_pressed();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_selectionChanged();

    void on_siml_keyboard_clicked();

private:
    QApplication *app;
    QWidget *recvWidget;
    QMouseEvent *event;
};

#endif // MAINWINDOW_H
