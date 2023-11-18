#include "map.h"

//地图：需要处理拖放事件，执行种植或铲除。
Map::Map()
{
    dragOver = false;
    /*
setAcceptDrops() 是 QWidget 类的一个成员函数，用于设置部件是否接受拖放操作。
它的默认值为 false，即部件默认情况下不接受拖放操作。
如果要使部件能够接受拖放操作，可以调用 setAcceptDrops(true)
来将其设置为接受拖放。这样，当有一个拖拽对象进入部件的区域时，部件
将触发相应的拖拽事件函数（例如 dragEnterEvent、dragMoveEvent 和 dropEvent），
从而允许你处理拖放操作。
*/
    setAcceptDrops(true);
}
//该函数指定了对象在场景中占据的区域。
QRectF Map::boundingRect() const
{
    return QRectF(-369, -235, 738, 470);
}

void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)

}

//开始拖拽
void Map::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    //接受文本类型（植物类和铲子类）的拖拽
    if (event->mimeData()->hasText())
    {
        event->setAccepted(true);
        dragOver = true;
        update();
    }
    else
        event->setAccepted(false);
}
//拖拽离开
void Map::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}
//拖拽后的结果：种植植物 或者 铲除植物
void Map::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if (event->mimeData()->hasText())
    {
        QString s = event->mimeData()->text();
        QPointF pos = mapToScene(event->pos());
        //对场景坐标进行调整，根据一定的计算规则将其映射到特定的位置。
        pos.setX((int(pos.x()) - 249) / 82 * 82 + 290);
        pos.setY((int(pos.y()) - 81) / 98 * 98 + 130);
        if (s == "Shovel")
        {
            Shovel *shovel = qgraphicsitem_cast<Shovel *>(scene()->items(QPointF(830, 15))[0]);
            shovel->removePlant(pos);
        }
        else
        {
            Shop *shop = qgraphicsitem_cast<Shop *>(scene()->items(QPointF(300, 15))[0]);
            shop->addPlant(s, pos);
        }
    }
    update();
}
