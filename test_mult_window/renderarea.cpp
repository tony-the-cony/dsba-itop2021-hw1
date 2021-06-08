#include "renderarea.h"
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{

}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor color(5, 220, 5);
    painter.setBrush(color);

    painter.drawRect(0, 0, width()-1, height()-1);

    QColor color2(5, 5, 220);
    painter.setBrush(color2);
    QPointF points[4] = {
        QPointF(40, 20),
        QPointF(width()-41, height()-21),
        QPointF(width()-41, 20),
        QPointF(40, height()-21)
    };

    painter.drawConvexPolygon(points, 4);

    QColor color3(220, 5, 5);
    painter.setBrush(color3);

    QPoint center((width()-1)/2, (height()-1)/2);
    painter.drawEllipse(center, 20, 20);
}
