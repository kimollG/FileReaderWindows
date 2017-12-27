#include "mainwindow.h"
#include <QApplication>
#include "OBJLoader.h"
#include "QTest"
#include "QtWidgets"
#include "graphicsview.h"

#include "testobj_loader.h"
#include "display.h"
int main(int argc, char *argv[])
{
    const int n=900;
    QApplication a(argc, argv);
    MainWindow *w=new MainWindow();
    w->resize(n,n);
    w->show();
    QGraphicsScene *scene = new QGraphicsScene(w);
    QPixmap *pix = new QPixmap(n,n);
    QPainter *paint = new QPainter(pix);
    GraphicsView* view=new GraphicsView(scene, w);
      view->show();
      view->resize(n,n);
      view->w=w;
    paint->setPen(*(new QColor(200,200,200,255)));

    //paint->drawRect(15,15,100,100);
    OBJLoader* fileManager=new OBJLoader();
    QString path="C:\\Users\\Kirill_Morozov\\Documents";
    QString errMessage;
    ModelData* data;
    bool b=fileManager->ReadFile(path+"\\africanHead.obj",&data,&errMessage);
    if(b)
    {
        fileManager->SaveToFile(data,path+"\\newTTTCorrupted.obj");
        qDebug()<<"completed";
    }
    else
        qDebug()<<errMessage;

    //Display disp(*data);
    w->drawer=new Display(*data,paint,n,w->camera,scene,pix);
    w->drawer->Draw();
    //disp.Draw(paint,n,w->camera);
    scene->addPixmap(*pix);
    //w.show();
    TestOBJ_Loader* testLoader = new TestOBJ_Loader;

    QStringList testNames;
    testNames << "" << "testWrongFace" << "testWrongVertex";
    //QTest::qExec(testLoader, testNames);
    //QTest::qExec(testLoader);


    return a.exec();
}
