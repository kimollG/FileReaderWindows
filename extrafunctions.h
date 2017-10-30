#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H
#include <QVector3D>
#include <vertexdata.h>
namespace ExtraFunctions
{
    QVector3D Extract3DCoordinateString(QString s);
    QPointF Extract2DCoordinateString(QString);
    QVector<VertexData>* ExtractPolygonString(QString s,QVector<QVector3D>* verts,QVector<QPointF>* tCoords, QVector<QVector3D>* nVecs);
}
#endif // EXTRAFUNCTIONS_H
