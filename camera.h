#ifndef CAMERA_H
#define CAMERA_H
#include "QVector3D"
#include "transformation.h"
#include "math.h"
class Camera
{
    double FoV;
    QVector3D position;
    QVector3D direction;
public:
    double getFoV();
    void setFoV(double );
    Camera(QVector3D pos,double FoV);
    void move(double dx,double dy,double dz);
    QMatrix4x4 getTransformationMatrix();
    QVector3D getPosition();
    void setDistance(double );
    double getDistance();
};

#endif // CAMERA_H
