#ifndef OTHER_H
#define OTHER_H

#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>
#include "Init.h"
class Other : public QGraphicsItem
{
public:
    //植物第一类 僵尸第二类 other第三类
    enum { Type = UserType + 3};
    Other();
    int type() const override;

signals:

};

#endif // OTHER_H
