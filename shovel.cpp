#include "shovel.h"
//这个边界矩形用于进行图形项的碰撞检测、布局和绘制等操作，确保图形项在场景中正确地被处理和显示。
QRectF Shovel::boundingRect() const
{
    return QRectF(-40, -40, 80, 80);
}

void Shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-40, -40, 80, 80), QPixmap(":/bgc/res\\Other/ShovelBank.png"));//铲子框
    painter->drawPixmap(QRect(-35, -35, 70, 70), QPixmap(":/bgc/res\\Other/Shovel.png"));
}

//---------------------------------鼠标事件：按下 拖动 释放-----------------------------------
void Shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
        return;
    //用于鼠标拖拽，可以传输数据
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image(":/bgc/res\\Other/Shovel.png");
    mime->setText("Shovel");
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image).scaled(70, 70));
    /*拖动物体的热点位置将被设置为 (35, 35)，以便在释放拖动物体时准确确定其放置位置。*/
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
     Q_UNUSED(event)
     setCursor(Qt::ArrowCursor);
}
//铲除植物：遍历，找到之后删除对象
void Shovel::removePlant(QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    foreach (QGraphicsItem *item, items)
        if (item->type() == Plant::Type)
        {
            delete item;
            return;
        }
}
