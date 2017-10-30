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
        QString path="C:";

        TestOBJ_Loader* testLoader = new TestOBJ_Loader;
        QStringList testNames;
        testNames << "testWrongVertex" << "testWrongFace";
        //QTest::qExec(testLoader, testNames);

        ModelData* data;
        try
        {
            data=fileManager->ReadFile(path+"\\africanHead.obj");
            fileManager->SaveToFile(data,path+"\\newTTTCorrupted.obj");
        }
        catch(QString exceptionMessage)
        {
            qDebug()<<exceptionMessage;
        }

    return a.exec();
}
