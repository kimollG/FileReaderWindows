#ifndef DISPLAY_H
#define DISPLAY_H
#include "modeldata.h"
#include "QtWidgets"
class Display
{
    ModelData *data;
public:
    void Draw(QPainter*,int n);
    Display();
    Display(ModelData &data);
};

#endif // DISPLAY_H
