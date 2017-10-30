#include "testobj_loader.h"
#include "extrafunctions.h"

void TestOBJ_Loader::OBJ_LoaderTest_data()
{
    QTest::addColumn<QString>("parameter");
    QTest::addColumn<QVector3D>("result");
    QTest::newRow("normal")<<"v 1 2 3"<<QVector3D(1,2,3);
    QTest::newRow("four coords")<<"vn 1 2 3 1"<<QVector3D(1,2,3);    
    QTest::newRow("no Coords")<<"vt "<<QVector3D(0,0,0);

    //QTEST_ASSERT(1==0);
}

void TestOBJ_Loader::OBJ_LoaderTest()
{
    QFETCH(QString,parameter);
    QFETCH(QVector3D,result);
    try
    {
        QVector3D v=ExtraFunctions::Extract3DCoordinateString(parameter);
        QCOMPARE(v,result);
    }
    catch (QString exMessage)
    {

        qDebug()<<exMessage;
    }
  //QCOMPARE(*(ExtraFunctions::ExtractCoordinateString("v 1 2 3")),QVector3D(1,2,3));
}


void TestOBJ_Loader::testWrongVertex()
{
    QTextStream a("v 12312 1231 1231\nv123123 1231");
    OBJLoader *reader=new OBJLoader();
    QString s="wrongVert";
    bool status = reader->ReadStream(&a,NULL,&s);
    QCOMPARE(status,false);
    QCOMPARE(s,QString::fromStdString("problem in line №2"));
}

void TestOBJ_Loader::testWrongFace()
{
    QTextStream a("v 12312 1231 1231\nv 3123 1231 123\nf 123");

    QString s="wrongFace";

    OBJLoader *reader=new OBJLoader();
    bool status = reader->ReadStream(&a,NULL,&s);
    QCOMPARE(status,false);
    QCOMPARE(s,QString::fromStdString("not enought points in polygon"));
}

void TestOBJ_Loader::testWrongFaceInvalidVertexIndex()
{
    QString s="WrFI";
    QTextStream a("v 12312 1231 1231\nv 123 1231 123\nf 1 2 999");
    OBJLoader *reader=new OBJLoader();
    bool status = reader->ReadStream(&a,NULL,&s);
    QCOMPARE(status,false);
    QCOMPARE(s,QString::fromStdString("The're no element № 999 in vertices list"));
}
/*
void TestOBJ_Loader::testSomething()
{
    QTextStream a;
    a << "v 12312 1231 1231\nv123123 1231 123\nf 1 2 999"
    FileReader reader;
    ModelData modelData;
    bool status = reader.readObj(a, &modelData)

    QVector<QVector3D> verticesRight;
    verticesRight << QVector3D(1,2,3) << QVector3D(2,3,4);

    QVector<int> facesRight;
    facesRight << 1 << 2 << 3 << 2 << 3 << 5;

    QCompare(verticesRight, modelData.vertices);
    QCompare(verticesfacesRight, modelData.faces);
}
*/


