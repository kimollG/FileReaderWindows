#include "testobj_loader.h"
#include "extrafunctions.h"

void TestOBJ_Loader::OBJ_LoaderTest_data()
{
    QTest::addColumn<QString>("parameter");
    QTest::addColumn<QVector3D>("result");
    QTest::newRow("normal")<<"v 1 2 3"<<QVector3D(1,2,3);
    QTest::newRow("four coords")<<"vn 1 2 3 1"<<QVector3D(1,2,3);
    QTest::newRow("two coords")<<"vfgfg 1 2"<<QVector3D(1,2,0);
    QTest::newRow("one coord with space at end")<<"v 1 "<<QVector3D(1,0,0);
    QTest::newRow("no Coords")<<"vt "<<QVector3D(0,0,0);

    QTEST_ASSERT(1==0);
}

void TestOBJ_Loader::OBJ_LoaderTest()
{
    QFETCH(QString,parameter);
    QFETCH(QVector3D,result);
    try
    {
        QVector3D v=*(ExtraFunctions::Extract3DCoordinateString(parameter,7));
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
    QTextStream a;
    a << "v 12312 1231 1231\nv123123 1231"
    FileReader reader;
    bool status = reader.readObj(a)
    QCOMPARE(status,true)
}

void TestOBJ_Loader::testWrongFace()
{
    QTextStream a;
    a << "v 12312 1231 1231\nv123123 1231 123\nf 123"
    FileReader reader;
    bool status = reader.readObj(a)
    QCOMPARE(status,true)
}

void TestOBJ_Loader::testWrongFaceInvalidVertexIndex()
{
    QTextStream a;
    a << "v 12312 1231 1231\nv123123 1231 123\nf 1 2 999"
    FileReader reader;
    bool status = reader.readObj(a)
    QCOMPARE(status,true)
}

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



