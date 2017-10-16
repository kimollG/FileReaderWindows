#include "filereader.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QChar>
#include <QFileInfo>
#include <QDebug>

FileReader::FileReader()
{

}
QVector3D* ExtractCoordinateString(QString s)
{
    QStringList list=s.split(' ',QString::SkipEmptyParts);
    QVector3D* vec= new QVector3D(list.at(1).toDouble(),list.at(2).toDouble(),list.count()>3?list.at(3).toDouble():0);
    return vec;
}
QVector<VertexData> ExtractPolygonString(QString s,QList<QVector3D>* verts,QList<QPointF>* tCoords, QList<QVector3D>* nVecs)
{
    QStringList list=s.split(' ',QString::SkipEmptyParts);
    QList<VertexData>* dataList=new QList<VertexData>();
    for(QStringList::iterator curr=list.begin()+1;curr!=list.end();curr++)
    {
        QStringList vert=(*curr).split('/');
        const QVector3D* coord=&(verts->at(list.at(0).toInt()));
        const QPointF* texture;
        const QVector3D* nVec;
        if(vert.count()>1&&vert[1].toStdString()!="")
            texture =&(tCoords->at(list.at(1).toInt()));
        else texture=0;
        if(vert.count()==3&&vert[2].toStdString()!="")
            nVec=&(nVecs->at(list.at(2).toInt()));
        else nVec=0;
        dataList->push_back(*(new VertexData((QVector3D*)coord,(QPointF*)texture,(QVector3D*)nVec)));
    }
    return dataList->toVector();
}

ModelData* FileReader::ReadFile(QString fileName)
{

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        throw new std::exception();
    }


    ExtractCoordinateString(QString::fromStdString("s 0.5454 2.34343 5.3434"));
    QList<QVector3D>* verts=new QList<QVector3D>();
    QList<QPointF>* tCoords=new QList<QPointF>();
    QList<QVector3D>* nVecs=new QList<QVector3D>();
    QStringList* faces=new QStringList();
    QString inputLine;
    QTextStream in(&file);
    while ((inputLine=in.readLine()).toStdString()!="")
    {

        switch (inputLine.toStdString()[0]) {
        case 'v':
            switch (inputLine.toStdString()[1]) {
            case 't':
            {
                QVector3D v=*ExtractCoordinateString(inputLine);
                tCoords->push_back(QPointF(v.x(),v.y()));}
                break;
            case 'n':

                nVecs->push_back(*ExtractCoordinateString(inputLine));
                break;
            default:
                verts->push_back(*ExtractCoordinateString(inputLine));
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
    QVector<VertexData>* polygVec=new QVector<VertexData>(faces->count());
    for(QStringList::iterator c=faces->begin();c!=faces->end();c++)
    {
        polygVec[c-faces->begin()]=(ExtractPolygonString(*c,verts,tCoords,nVecs));
    }
    return 0;
}

