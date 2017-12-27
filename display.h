#ifndef DISPLAY_H
#define DISPLAY_H
#include "modeldata.h"
#include "QtWidgets"
#include "camera.h"
#include "QWidget"
class Display
{
    Camera* cam;
    QPainter* painter;
    int size;
    ModelData *data;
    QGraphicsScene* scene;
    QPixmap* pix;
public:
    void Draw();
    void Draw(QPainter*,int n,Camera* cam);
    Display();
    Display(ModelData &data,QPainter*,int size,Camera*,QGraphicsScene* scene, QPixmap* pix);
};

#endif // DISPLAY_H
