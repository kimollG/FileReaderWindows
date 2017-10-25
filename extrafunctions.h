#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H
#include <QVector3D>
#include <vertexdata.h>
namespace ExtraFunctions
{
    QVector3D* ExtractCoordinateString(QString s);
    QVector<VertexData*>* ExtractPolygonString(QString s,QList<QVector3D*>* verts,QList<QPointF*>* tCoords, QList<QVector3D*>* nVecs);
}
#endif // EXTRAFUNCTIONS_H
