#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtGui"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setMouseTracking(true);
    ui->setupUi(this);
    camera=new Camera(QVector3D(0,0,4),30);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool isPressed;
QPoint lastPos;
void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug() << "move";
    if(!isPressed)
        return;
    QPoint diff= ev->pos() -lastPos;
    if(diff.manhattanLength()<4)
        return;
    camera->rotate(transform::RotationMatrix(diff.x(),diff.y(),0));
    drawer->Draw();
    lastPos=ev->pos();

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "press";
    camera->rotate(transform::RotationMatrix(0.31415,0,0));
    drawer->Draw();
    lastPos=event->pos();
    isPressed=true;
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "release";
    isPressed=false;
    //QMainWindow::mouseReleaseEvent(event);
}
