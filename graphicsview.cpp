#include "graphicsview.h"
#include "QtGui"
GraphicsView::GraphicsView(QGraphicsScene *s,QWidget *w):QGraphicsView(s,w)
{

}
bool isPressed;
QPoint lastPos;
void GraphicsView::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug() << "move";
    if(!isPressed)
        return;
    QPoint diff= ev->pos() -lastPos;
    if(diff.manhattanLength()<4)
        return;
    w->camera->rotate(transform::RotationMatrix(diff.x()/30.0,diff.y()/30.0,0));
    w->drawer->Draw();
    lastPos=ev->pos();

}
void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "press";
    w->camera->rotate(transform::RotationMatrix(0.31415,0,0));
    w->drawer->Draw();
    lastPos=event->pos();
    isPressed=true;
}
void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "release";
    isPressed=false;
    //QMainWindow::mouseReleaseEvent(event);
}
