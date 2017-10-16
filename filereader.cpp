#include "filereader.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QChar>
FileReader::FileReader()
{

}
QVector3D* ExtractCoordinateString(QString s)
{
    QStringList list=s.split(' ',QString::SkipEmptyParts);
    QVector3D* vec= new QVector3D(list.at(1).toDouble(),list.at(2).toDouble(),list.count()>3?list.at(3).toDouble():0);
    return vec;
}
VertexData* ExtractPolygonString(QString s,QList<QVector3D>* verts,QList<QPointF>* tCoords, QList<QVector3D>* nVecs)
{
    QStringList list=s.split(' ',QString::SkipEmptyParts);
    for(QStringList::iterator curr=list.begin();curr!=list.end();curr++)
    {
        QStringList vert=(*curr).split('/');
    }
}

ModelData* FileReader::ReadFile(std::string fileName)
{
    QFile file(fileName.c_str());

    if (!file.open(QIODevice::ReadOnly))
    {
        throw new std::exception();
    }
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
    for(QStringList::iterator c=faces->begin();c!=faces->end();c++)
    {
        ExtractPolygonString(*c,verts,tCoords,nVecs);
    }
    return 0;
}

