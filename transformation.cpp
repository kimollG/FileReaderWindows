#include "transformation.h"
#include "math.h"
Transformation::Transformation(QMatrix4x4 matr)
{
    this->matr=matr;
}
QMatrix4x4 transform::RotationMatrix(double alpha,double beta)
{

    QMatrix4x4 first(std::cos(alpha),0,std::sin(alpha),0,
                     0,1,0,0,
                     -std::sin(alpha),0,std::cos(alpha),0,
                     0,0,0,1);
    QMatrix4x4 second(1,0,0,0,
                   0,std::cos(beta),-std::sin(beta),0,
                   0,std::sin(beta),std::cos(beta),0,
                   0,0,0,1);



    return second*first;
}
QMatrix4x4 transform::ScaleMatrix(double k)
{
    return QMatrix4x4 (k,0,0,0,
                 0,k,0,0,
                 0,0,k,0,
                 0,0,0,1);
}
