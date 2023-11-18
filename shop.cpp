#include "shop.h"

Shop::Shop()
{
    //初始化阳光值
    sun = INIT_SUN_NUM;
    counter = 0;
    time = int(7.0 * 1000 / 35);
    //将卡片放到卡片槽内，注意放置卡片的位置
    Card *card = nullptr;
    for (int i = 0; i < Card::name.size(); ++i)
    {
        card = new Card(Card::name[i]);
        card->setParentItem(this);
        card->setPos(-157 + 65 * i, -2);
    }
}
//这个边界矩形用于进行图形项的碰撞检测、布局和绘制等操作，确保图形项在场景中正确地被处理和显示。
QRectF Shop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

//绘制卡片槽
void Shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-270, -45, 540, 90), QPixmap(":/bgc/res\\Other/Shop.png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sun));
    painter->drawPoint(-220, 0);
}

void Shop::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (++counter >= time)//定时生产阳光
    {
        counter = 0;
        scene()->addItem(new Sun);//用于获取当前窗口的图形对象
    }
}
//种植植物
void Shop::addPlant(QString s, QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);

    foreach (QGraphicsItem *item, items)
        if (item->type() == Plant::Type)
            return;

    //花费阳光
    sun -= Card::cost[Card::map[s]];
    Plant *plant = nullptr;
    switch (Card::map[s])
    {
    case 0:
        plant = new SunFlower; break;
    case 1:
        plant = new Peashooter; break;
    case 2:
        plant = new CherryBomb; break;
    case 3:
        plant = new WallNut; break;
    case 4:
        plant = new SnowPea; break;
    case 5:
        plant = new PotatoMine; break;
    case 6:
        plant = new Repeater; break;
    }

    //设置卡片的counter为0，重新开始冷冻
    plant->setPos(pos);
    scene()->addItem(plant);
    QList<QGraphicsItem *> child = childItems();

    foreach (QGraphicsItem *item, child)
    {
        Card *card = qgraphicsitem_cast<Card *>(item);
        if (card->text == s)
            card->counter = 0;//将卡片冰冻时间设置为0
    }
    counter = 0;
}

