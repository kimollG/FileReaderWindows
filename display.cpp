#include "display.h"
#include "QImage"
#include "math.h"
Display::Display()
{
    data=NULL;
}
Display::Display(ModelData &data)
{
    this->data=&data;
}
void Display::Draw(QPainter* painter,int n)
{    
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
        {
            polyg[i]=QPointF((*iter)->at(i).coordinate->x(),(*iter)->at(i).coordinate->y());
            polyg[i]*=k;
            polyg[i].setY(polyg[i].y()*-1);
            polyg[i]+=QPointF(n*0.5,n*0.5);
        }
        painter->drawPolygon(polyg,l);
    }
    //painter->drawPolygon();
    //painter->drawPolygon(points,4);
}

