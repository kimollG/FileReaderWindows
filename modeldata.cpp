#include "modeldata.h"

ModelData::ModelData(QVector<QVector3D>*& verts,QVector<QPointF>*& tp,QVector<QVector3D>*& nv,QVector<QVector<VertexData>*>*& fullVerts)
{
    vertices=verts;
    texturePoints=tp;
    normaleVectors=nv;
    polygons=fullVerts;
}
ModelData::ModelData()
{}


