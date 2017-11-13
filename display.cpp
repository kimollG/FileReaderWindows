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
QPointF Projection(QVector3D q,double k,double offset)
{
    QPointF p(q.x(),-q.y());
    p*=k;
    p+=QPointF(offset*0.5,offset*0.5);
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
    double k=n/maxR/2*0.8;
    for(QVector<QVector<VertexData>*>::iterator iter=data->polygons->begin();iter<data->polygons->end();iter++)
    {
        int l=(*iter)->length();
        QPointF* polyg=new QPointF[l];
        for(int i=0;i<l;i++)        
            polyg[i]=Projection(Transform(*((*iter)->at(i).coordinate),transform::RotationMatrix(1.5708,1.5708)),k,n);
            //polyg[i]=Projection((*iter)->at(i).coordinate,k,n);
        painter->drawPolygon(polyg,l);
    }    
}

