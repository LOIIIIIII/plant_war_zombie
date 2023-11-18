#include "wallnut.h"

WallNut::WallNut()
{
    hp = hp_WallNut;
    setMovie(":/plant/res\\Plant/WallNut.gif");
}

//受损状态转换
void WallNut::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (hp <= 1333 && state != 2)
    {
        state = 2;
        setMovie(":/plant/res\\Plant/WallNut2.gif");
    }
    else if (1333 < hp && hp <= 2667 && state != 1)
    {
        state = 1;
        setMovie(":/plant/res\\Plant/WallNut1.gif");
    }
    else {;}
}
