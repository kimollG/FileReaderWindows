#include "transformation.h"
#include "math.h"
Transformation::Transformation(QMatrix4x4 matr)
{
    this->matr=matr;
}
QMatrix4x4 transform::RotationMatrix(double aboutY,double aboutX,double aboutZ)
{

    QMatrix4x4 first(std::cos(aboutY),0,std::sin(aboutY),0,
                     0,1,0,0,
                     -std::sin(aboutY),0,std::cos(aboutY),0,
                     0,0,0,1);
    QMatrix4x4 second(1,0,0,0,
                   0,std::cos(aboutX),-std::sin(aboutX),0,
                   0,std::sin(aboutX),std::cos(aboutX),0,
                   0,0,0,1);

    QMatrix4x4 third(std::cos(aboutZ),-std::sin(aboutZ),0,0,
                     std::sin(aboutZ),std::cos(aboutZ),0,0,
                     0,0,1,0,
                     0,0,0,1);

    return third*second*first;
}
QMatrix4x4 transform::ScaleMatrix(double k)
{
    return QMatrix4x4 (k,0,0,0,
                 0,k,0,0,
                 0,0,k,0,
                 0,0,0,1);
}

QMatrix4x4 transform::OffsetMatrix(double dx, double dy, double dz)
{
    return QMatrix4x4(1,0,0,dx,
                      0,1,0,dy,
                      0,0,1,dz,
                      0,0,0,1);
}

QMatrix4x4 transform::PerspectiveMatrix(double distanse)
{
    return QMatrix4x4(1,0,0,0,
                      0,1,0,0,
                      0,0,1,0,
                      0,0,-1/distanse,1);
}
