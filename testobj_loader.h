#ifndef TESTOBJ_LOADER_H
#define TESTOBJ_LOADER_H
#include <QtTest/QtTest>
#include <QObject>
#include <QDebug>
#include <QSTring>
class TestOBJ_Loader : public QObject
{
    Q_OBJECT
private slots:
    void OBJ_LoaderTest_data();
    void OBJ_LoaderTest();
};
#endif // TESTOBJ_LOADER_H
