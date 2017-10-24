#include "mainwindow.h"
#include <QApplication>
#include "filereader.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    FileProducer* fileManager=new FileProducer();
    ModelData* data=fileManager->ReadFile("C:\\africanHead.obj");
    fileManager->SaveToFile(data,"newTTT.obj");
    return a.exec();
}
