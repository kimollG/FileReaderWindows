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


