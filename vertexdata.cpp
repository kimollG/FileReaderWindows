#include <vertexdata.h>
VertexData::VertexData(QVector3D * c, QPointF * t, QVector3D *n)
{
    coordinate=c;
    textureCoord=t;
    nVector=n;
}
