#ifndef MAP_H
#define MAP_H

#include "other.h"
#include "shop.h"
#include "shovel.h"
#include <QGraphicsSceneDragDropEvent>
//设置一张地图用来种植植物
class Map : public Other
{

public:
    Map();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
private:
    bool dragOver;//用于表示是否有拖拽对象正在悬停在对象的区域上方。

};

#endif // MAP_H
