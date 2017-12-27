#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include "QMatrix4x4"
namespace transform {
    QMatrix4x4 RotationMatrix(double aboutY,double aboutX,double aboutZ);
    QMatrix4x4 ScaleMatrix(double k);
    QMatrix4x4 OffsetMatrix(double dx,double dy,double dz);
    QMatrix4x4 PerspectiveMatrix(double distanse);
    QVector3D PerformTransform(QVector3D,QMatrix4x4);
}
class Transformation
{
    QMatrix4x4 matr;

public:
    Transformation(QMatrix4x4);
};

#endif // TRANSFORMATION_H
