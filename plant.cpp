#include "plant.h"

Plant::Plant()
{
    movie = nullptr;
    atk = counter = state = time = 0;
}

Plant::~Plant()
{
    delete movie;
}
//这个空气墙用于进行图形项的碰撞检测、布局和绘制等操作，确保图形项在场景中正确地被处理和显示。
QRectF Plant::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(boundingRect(), movie->currentImage());
}

bool Plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    // 左右30像素内是否存在僵尸
    return true;//other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

int Plant::type() const
{
    return Type;
}

void Plant::setMovie(QString path)
{
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}
