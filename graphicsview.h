#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include "QWidget"
#include "QtWidgets"
#include <QObject>
#include  "mainwindow.h"
class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MainWindow *w;
    explicit GraphicsView(QGraphicsScene *s,QWidget *w);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // GRAPHICSVIEW_H
