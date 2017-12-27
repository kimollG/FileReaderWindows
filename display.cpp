#include "display.h"
#include "QImage"
#include "math.h"
#include "transformation.h"

Display::Display()
{
    data=NULL;
}
Display::Display(ModelData &data,QPainter* paint,int size,Camera* cam,QGraphicsScene* scene, QPixmap* pix)
{
    this->data=&data;
    this->painter=paint;
    this->size=size;
    this->cam=cam;
    this->scene=scene;
    this->pix=pix;
}
QPointF Projection(QVector3D q)
{
    QPointF p(q.x(),-q.y());
    //p*=k;

    return p;
}

void Display::Draw()
{
    Display::Draw(painter,size,cam);
}
void Display::Draw(QPainter* painter,int pictureSize,Camera* cam)
{    
    //painter->setBackground(QBrush(QColor(255,255,255,255)));
    painter->fillRect(0,0,pictureSize,pictureSize,QBrush(QColor(0,0,0)));
    double maxR=0;
    for(int i=0;i<data->vertices->length();i++)
    {
        double x=data->vertices->at(i).x();
        double y=data->vertices->at(i).y();
        double r=std::sqrt(x*x+y*y);
        if(r>maxR)
            maxR=r;
    }

    double k=pictureSize/maxR/2;
    double offsX=pictureSize/2,offsY=-pictureSize/2,offsZ=0;
    QVector<QMatrix4x4> transforms{
        cam->getTransformationMatrix(),
        transform::ScaleMatrix(k),transform::OffsetMatrix(offsX,offsY,offsZ)};

    for(QVector<QVector<VertexData>*>::iterator iter=data->polygons->begin();iter<data->polygons->end();iter++)
    {
        int l=(*iter)->length();
        QPointF* polyg=new QPointF[l];
        for(int i=0;i<l;i++)
        {
            QVector3D v=*((*iter)->at(i).coordinate);
            //v.setZ(0); //for debug only, makes image flat

            for(int j=0;j<transforms.length();j++)
                v=transform::PerformTransform(v,transforms[j]);

            polyg[i]=Projection(v);
        }
        painter->drawPolygon(polyg,l);
    }    
    scene->addPixmap(*pix);
}

