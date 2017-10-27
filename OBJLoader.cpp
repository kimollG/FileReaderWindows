#include "OBJLoader.h"
#include "extrafunctions.h"

OBJLoader::OBJLoader()
{

}
QPointF* ExtraFunctions::Extract2DCoordinateString(QString s, int i)
{
    QStringList list=s.split(' ',QString::SkipEmptyParts);
    if(list.length()<3)
        throw "problem in document's line № "+QString::number(i)+" : to few arguments";
    return new QPointF(list.at(1).toDouble(),list.at(2).toDouble());
}

QVector3D* ExtraFunctions::Extract3DCoordinateString(QString s,int i)
{
    QStringList list=s.split(' ',QString::SkipEmptyParts);        
    if(list.length()<4)
        throw "problem in document's line № "+QString::number(i)+" : to few arguments";
    return new QVector3D(list.at(1).toDouble(),list.at(2).toDouble(),list.at(3).toDouble());
}
QVector<VertexData*>* ExtraFunctions::ExtractPolygonString(QString s,QList<QVector3D*>* verts,QList<QPointF*>* tCoords, QList<QVector3D*>* nVecs)
{
    QStringList list=s.split(' ',QString::SkipEmptyParts);
    QList<VertexData*>* dataList=new QList<VertexData*>();
    for(QStringList::iterator curr=list.begin()+1;curr!=list.end();curr++)
    {
        QStringList vert=(*curr).split('/');
        int index=vert.at(0).toInt()-1;
        if(index<0)
                index=verts->length()+index;
        if(index>=verts->length())
            throw "The're no element № "+QString::number(index+1)+" in vertices list";
        const QVector3D* coord=verts->at(index);
        const QPointF* texture;
        const QVector3D* nVec;
        if(vert.count()>1&&vert[1].toStdString()!="")
        {
            index=vert.at(1).toInt()-1;
            if(index<0)
                    index=tCoords->length()+index;
            if(index>=tCoords->length())
                throw "The're no element № "+QString::number(index+1)+" in vt list";
            texture =tCoords->at(index);
        }
        else texture=0;
        if(vert.count()==3&&vert[2].toStdString()!="")
        {
            index=vert.at(2).toInt()-1;
            if(index<0)
                    index=nVecs->length()+index;
            if(index>=nVecs->length())
                throw "The're no element № "+QString::number(index+1)+" in vn list";
            nVec=nVecs->at(index);
        }
        else nVec=0;
        dataList->push_back(new VertexData((QVector3D*)coord,(QPointF*)texture,(QVector3D*)nVec));
    }
    QVector<VertexData*>* out=new QVector<VertexData*>(dataList->toVector());
    return out;
}
using namespace ExtraFunctions;

ModelData* OBJLoader::ReadFile(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        throw new std::exception();
    }    
    QList<QVector3D*>* verts=new QList<QVector3D*>();
    QList<QPointF*>* tCoords=new QList<QPointF*>();
    QList<QVector3D*>* nVecs=new QList<QVector3D*>();
    QStringList* faces=new QStringList();
    QString inputLine;
    QTextStream in(&file);
    int i=0;
    while ( !in.atEnd())
    {
        i++;
        (inputLine=in.readLine()).toStdString();
        switch (inputLine.toStdString()[0])
        {
        case 'v':
            switch (inputLine.toStdString()[1]) {
            case 't':
            {
                QVector3D v=*Extract3DCoordinateString(inputLine,i);
                tCoords->push_back(new QPointF(v.x(),v.y()));}
                break;
            case 'n':
                nVecs->push_back(Extract3DCoordinateString(inputLine,i));
                break;
            default:
                verts->push_back(Extract3DCoordinateString(inputLine,i));
                break;
            }
            break;

        case 'f':
        {
            faces->push_back(inputLine);
            }
            break;
        default:
            break;
        }
    }
    QList<QVector<VertexData*>*>* polygVec=new QList<QVector<VertexData*>*>();
    for(QStringList::iterator c=faces->begin();c!=faces->end();c++)
    {
        polygVec->push_back(ExtractPolygonString(*c,verts,tCoords,nVecs));
    }
    QVector<QVector3D*>* v1=new QVector<QVector3D*>(verts->toVector());
    QVector<QPointF*>* v2=new QVector<QPointF*>(tCoords->toVector());
    QVector<QVector3D*>* v3=new QVector<QVector3D*>(nVecs->toVector());
    QVector<QVector<VertexData*>*>* v4=new QVector<QVector<VertexData*>*>(polygVec->toVector());
    ModelData* mod= new ModelData(v1,v2,v3,v4);
    delete verts;
    delete tCoords;
    delete nVecs;
    delete polygVec;
    delete faces;
    return mod;
}
void OBJLoader::SaveToFile(ModelData* data,QString fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadWrite|QFile::Truncate))
    {
            QTextStream stream(&file);
            stream << "#made by fileWriter" << "\r\n";
            for (QVector<QVector3D*>::iterator iter=data->vertices->begin();iter<data->vertices->end();iter++)
            {
                stream<<"v "<<(*iter)->x()<<" "<<(*iter)->y()<<" "<<(*iter)->z()<<"\r\n";
            }
            for (QVector<QPointF*>::iterator iter=data->texturePoints->begin();iter<data->texturePoints->end();iter++)
            {                
                stream<<"vt "<<(*iter)->x()<<" "<<(*iter)->y()<<"\r\n";
            }
            for (QVector<QVector3D*>::iterator iter=data->normaleVectors->begin();iter<data->normaleVectors->end();iter++)
            {
                stream<<"vn "<<(*iter)->x()<<" "<<(*iter)->y()<<" "<<(*iter)->z()<<"\r\n";
            }
            for (QVector<QVector<VertexData*>*>::iterator iter=data->polygons->begin();iter<data->polygons->end();iter++)
            {
                stream<<"f ";
                for (QVector<VertexData*>::iterator iter2=(*iter)->begin();iter2<(*iter)->end();iter2++)
                {
                    stream<<" "<<data->vertices->indexOf(*&((*iter2)->coordinate))+1
                         <<"/"<<data->texturePoints->indexOf((*iter2)->textureCoord)+1
                         <<"/"<<data->normaleVectors->indexOf((*iter2)->nVector)+1;
                }
                stream<<"\r\n";
            }
        }
}


