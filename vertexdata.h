#ifndef POLYGONDATA_H
#define POLYGONDATA_H
#include <QVector3D>
struct VertexData
{
     VertexData(QVector3D *c, QPointF* t, QVector3D* n);
     QVector3D *coordinate;
     QPointF* textureCoord;
     QVector3D* nVector;
};
#endif // POLYGONDATA_H
