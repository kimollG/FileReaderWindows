#ifndef FILEREADER_H
#define FILEREADER_H
#include "modeldata.h"
#include <string>
#include <fstream>
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QChar>
#include <QFileInfo>
#include <QDebug>
class OBJLoader
{
    ModelData data;
public:
    OBJLoader();
    bool ReadFile(QString,ModelData**);
    bool ReadStream(QTextStream stream,ModelData**);
    void SaveToFile(ModelData*,QString fileName);
};

#endif // FILEREADER_H
