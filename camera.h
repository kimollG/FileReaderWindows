#ifndef CAMERA_H
#define CAMERA_H
#include "QVector3D"
class Camera
{
public:
    QVector3D position;
    QVector3D direction;
    Camera(QVector3D pos,QVector3D dir);
};

#endif // CAMERA_H
