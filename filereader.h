#ifndef FILEREADER_H
#define FILEREADER_H
#include "modeldata.h"
#include <string>
class FileReader
{
    ModelData data;
public:
    FileReader();
    ModelData* ReadFile(std::string fileName);
};

#endif // FILEREADER_H
