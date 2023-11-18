#include "basiczombie.h"

BasicZombie::BasicZombie()
{
    hp = hp_BasicZombie;
    atk = atk_Zombie;
    speed = speed_zombie_1;

    //if (qrand() % 2)
        //setMovie(":/images/ZombieDie.gif");
    //else
        setMovie(":/images/ZombieDie.gif");
}

//僵尸的状态变化
void BasicZombie::advance(int phase)
{
    if (!phase)
    {
        return;
    }

    update();


    QList<QGraphicsItem *> items = collidingItems();

    //如果死亡
    if (hp <= 0)
    {
        if (state < ZombieType::DIE)
        {
            state = ZombieType::DIE;
            setMovie(":/images/ZombieDie.gif");
            setHead(":/images/ZombieHead.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }

    //如果发生碰撞
    else if (!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        plant->hp -= atk;
        if (state != ZombieType::ATTACK)
        {
            state = ZombieType::ATTACK;
            setMovie(":/images/ZombieAttack.gif");
        }
        return;
    }

    //没死，没碰撞，就继续行走
    else//if ( state==ZombieType::ATTACK || state==ZombieType::DIE )
    {
        state = ZombieType::WALK;
        switch (numImage++) {
        case 0:setMovie(":/images/ZombieWalk2.gif");break;
        case 1:setMovie(":/images/ZombieWalk2.gif");break;
        case 2:setMovie(":/images/ZombieWalk2.gif");break;
        }
        //两个都要可能会显示混乱
//        if (qrand() % 2)
//            setMovie(":/images/ZombieWalk1.gif");
//        else
        numImage=numImage%3;
    }

    // 向前移动
    setX(x() - speed);
}
