#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H
#include "QMatrix4x4"

class Transformation
{
    QMatrix4x4 matr;
public:
    Transformation(QMatrix4x4);
};

#endif // TRANSFORMATION_H
