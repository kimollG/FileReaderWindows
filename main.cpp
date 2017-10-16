#include "mainwindow.h"
#include <QApplication>
#include "filereader.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    FileReader* reader=new FileReader();
    reader->ReadFile("C:/Users/Morozov_K/Documents/africanHead.obj.txt");
    return a.exec();
}
