#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QMouseEvent>
#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView();

protected:
    void mouseMoveEvent(QMouseEvent * event);
};

#endif // GRAPHICSVIEW_H
