#ifndef SHOP_H
#define SHOP_H

#include "other.h"
#include"card.h"
#include"sun.h"
#include"plant.h"
#include"cherrybomb.h"
#include"peashooter.h"
#include"potatomine.h"
#include"sunflower.h"
#include"potatomine.h"
#include"wallnut.h"
#include"snowpea.h"
#include"repeater.h"
class Shop : public Other
{

public:
    int sun;
    Shop();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;//重写advance()用于记录掉落阳光
    void addPlant(QString s, QPointF pos);
private:
    int counter;//用于阳光生产记录时间
    int time;

};

#endif // SHOP_H
