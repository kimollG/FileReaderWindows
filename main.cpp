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

        TestObjLoder testLoader = new TestOBJ_Loader;
        QStringList testNames;
        testNames << "testWrongVertex" << "testWrongFace";
        QTest::qExec(testLoader, testNames);

        ModelData* data;
        try
        {
            data=fileManager->ReadFile(path+"\\africanHeadCorrupted.obj");
            fileManager->SaveToFile(data,path+"\\newTTTCorrupted.obj");
        }
        catch(QString exceptionMessage)
        {
            qDebug()<<exceptionMessage;
        }

    return a.exec();
}
