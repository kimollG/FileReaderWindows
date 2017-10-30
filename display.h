#ifndef DISPLAY_H
#define DISPLAY_H
#include "modeldata.h"

class Display
{
    ModelData *data;
public:
    void Draw();
    Display();
    Display(ModelData &data);
};

#endif // DISPLAY_H
