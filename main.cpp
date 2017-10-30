#include "mainwindow.h"
#include <QApplication>
#include "OBJLoader.h"
#include "QTest"
#include "testobj_loader.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    OBJLoader* fileManager=new OBJLoader();
    QString path="C:\\Users\\Morozov_K\\Documents";
    TestOBJ_Loader* testLoader = new TestOBJ_Loader;

    QStringList testNames;
    testNames << "" << "testWrongFace" << "testWrongVertex";
    //QTest::qExec(testLoader, testNames);
    QTest::qExec(testLoader);
    QString errMessage;
    ModelData* data;
    bool b=fileManager->ReadFile(path+"\\africanHeadCorrupted2.obj",&data,&errMessage);
    if(b)
        fileManager->SaveToFile(data,path+"\\newTTTCorrupted.obj");
    else
        qDebug()<<errMessage;
    return a.exec();
}
