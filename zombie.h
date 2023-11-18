#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include"Init.h"
enum class ZombieType { WALK=0, ATTACK, DIE, BURN};

class Zombie : public QGraphicsItem
{
public:
    int hp;
    int atk;
    qreal speed;

    //僵尸状态
    ZombieType state;

    //僵尸属于第二类（植物是第一类）
    enum { Type = UserType + 2};


    Zombie();
    ~Zombie() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type() const override;
    void setMovie(QString path);
    void setHead(QString path);
protected:
    static int numImage;
    QMovie *movie;
    QMovie *head;
};
#endif // ZOOMBIE_H
