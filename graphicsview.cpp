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
    if(diff.manhattanLength()<1)
        return;
    double sensivity=130;
    if(ev->buttons()==Qt::LeftButton)
        w->camera->rotate(transform::RotationMatrix(-diff.x()/sensivity,-diff.y()/sensivity,0));
    else if(ev->buttons()==Qt::RightButton)
        w->camera->setFoV(w->camera->getFoV()-diff.y());
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
