#include "testobj_loader.h"
#include "extrafunctions.h"

void TestOBJ_Loader::OBJ_LoaderTest_data()
{
    QTest::addColumn<QString>("parameter");
    QTest::addColumn<QVector3D>("result");
    QTest::newRow("normal")<<"v 1 2 3"<<QVector3D(1,2,3);
    QTest::newRow("four coords")<<"v 1 2 3 1"<<QVector3D(1,2,3);
    QTest::newRow("two coords")<<"v 1 2"<<QVector3D(1,2,0);
    QTest::newRow("one coord with space at end")<<"v 1 "<<QVector3D(1,0,0);
    QTest::newRow("no Coords")<<"v "<<QVector3D(0,0,0);
}

void TestOBJ_Loader::OBJ_LoaderTest()
{
    QFETCH(QString,parameter);
    QFETCH(QVector3D,result);
    QVector3D v=*(ExtraFunctions::ExtractCoordinateString(parameter));
    QCOMPARE(v,result);
   //QCOMPARE(*(ExtraFunctions::ExtractCoordinateString("v 1 2 3")),QVector3D(1,2,3));
}

