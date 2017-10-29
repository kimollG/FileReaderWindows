#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H
#include <QVector3D>
#include <vertexdata.h>
namespace ExtraFunctions
{
    QVector3D* Extract3DCoordinateString(QString s,int i=0);
    QPointF* Extract2DCoordinateString(QString,int=0);
    QVector<VertexData>* ExtractPolygonString(QString s,QList<QVector3D>* verts,QList<QPointF>* tCoords, QList<QVector3D>* nVecs);
}
#endif // EXTRAFUNCTIONS_H
