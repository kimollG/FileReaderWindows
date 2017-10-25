#include "mainwindow.h"
#include <QApplication>
#include "filereader.h"
#include "QTest"
#include "testobj_loader.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    FileProducer* fileManager=new FileProducer();
    QString path="C:\\Users\\Morozov_K\\Documents";
    QTest::qExec(new TestOBJ_Loader);
    ModelData* data=fileManager->ReadFile(path+"\\africanHeadCorrupted2.obj");
    fileManager->SaveToFile(data,path+"\\newTTTCorrupted.obj");
    return a.exec();
}
