#include "snowpea.h"

SnowPea::SnowPea()
{
    atk = atk_SnowPea;
    hp = hp_NormalPlant;
    time = int(1.4 * 1000 / 33);
    setMovie(":/plant/res\\Plant/SnowPea.gif");
}

void SnowPea::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            Pea *pea = new Pea(atk, true);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool SnowPea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return true;//other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}
