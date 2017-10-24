#ifndef FILEREADER_H
#define FILEREADER_H
#include "modeldata.h"
#include <string>
class FileProducer
{
    ModelData data;
public:
    FileProducer();
    ModelData* ReadFile(QString);
    void SSS()
    {}
};

#endif // FILEREADER_H
