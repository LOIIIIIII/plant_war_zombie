#ifndef PLANT_H
#define PLANT_H

#include "Init.h"
#include"other.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
class Plant : public QGraphicsItem
{
public:
    int hp;
    int state;
    //第一类植物类
    enum { Type = UserType + 1};
    Plant();
    ~Plant() override;

    //多态重写
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type() const override;
    //设置动画
    void setMovie(QString path);
protected:
    QMovie *movie;
    int atk;
    int counter;
    int time;
};

#endif // PLANT_H
