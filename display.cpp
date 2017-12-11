#include "display.h"
#include "QImage"
#include "math.h"
#include "transformation.h"
Display::Display()
{
    data=NULL;
}
Display::Display(ModelData &data)
{
    this->data=&data;
}
QPointF Projection(QVector3D q)
{
    QPointF p(q.x(),-q.y());
    //p*=k;

    return p;
}
QVector3D Transform(QVector3D v,QMatrix4x4 matr)
{
    QVector4D projV(v,1);
    projV=matr*projV;
    return projV.toVector3DAffine();
}

void Display::Draw(QPainter* painter,int n)
{    
    QMatrix matr;
    double maxR=0;
    for(int i=0;i<data->vertices->length();i++)
    {
        double x=data->vertices->at(i).x();
        double y=data->vertices->at(i).y();
        double r=std::sqrt(x*x+y*y);
        if(r>maxR)
            maxR=r;
    }
    double k=n/maxR/2;
    for(QVector<QVector<VertexData>*>::iterator iter=data->polygons->begin();iter<data->polygons->end();iter++)
    {
        double dist =5;
        double FoV=22.6;
        double rotAboutY=0,rotAboutX=0,rotAboutZ=0;
        double offsX=n/2,offsY=-n/2,offsZ=0;
        int l=(*iter)->length();
        QPointF* polyg=new QPointF[l];
        for(int i=0;i<l;i++)
        {
            QVector3D v=*((*iter)->at(i).coordinate);
            //v.setZ(0); //for debug only, makes image flat
            QVector<QMatrix4x4> transforms{
                transform::RotationMatrix(rotAboutY,rotAboutX,rotAboutZ),transform::PerspectiveMatrix(dist),
                transform::ScaleMatrix(k/dist/std::tan(3.1415/180*FoV/2)),transform::OffsetMatrix(offsX,offsY,offsZ)};
            for(int j=0;j<transforms.length();j++)
                v=Transform(v,transforms[j]);

            polyg[i]=Projection(v);
        }
        painter->drawPolygon(polyg,l);
    }    
}

