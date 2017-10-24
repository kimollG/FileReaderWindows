#ifndef MODELDATA_H
#define MODELDATA_H
#include <QVector>
#include <QVector3D>
#include <QPointF>
#include "vertexdata.h"
class ModelData
{
public:
    ModelData();
    ModelData(QVector<QVector3D*>*& verts,QVector<QPointF*>*& tp,QVector<QVector3D*>*& nv,QVector<QVector<VertexData*>*>*& fullVerts);
    QVector<QVector3D*>* vertices;
    QVector<QPointF*>* texturePoints;
    QVector<QVector3D*>* normaleVectors;
    QVector<QVector<VertexData*>*>* polygons;

};

#endif // MODELDATA_H
