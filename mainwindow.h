#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "camera.h"
#include <QMainWindow>
#include "display.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Camera* camera;
    Display* drawer;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
