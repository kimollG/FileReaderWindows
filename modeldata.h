#ifndef MODELDATA_H
#define MODELDATA_H
#include <QVector>
#include <QVector3D>
#include <QPointF>
#include "vertexdata.h"
class ModelData
{
public:

    QVector<QVector3D> vertices;
    QVector<QPointF> texturePoints;
    QVector<QVector3D> normaleVectors;
    QVector<VertexData> fullVertexData;

};

#endif // MODELDATA_H
