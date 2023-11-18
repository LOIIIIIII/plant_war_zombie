#include "playscene.h"
#include<QIcon>
#include<QTime>
#include<QMenuBar>
int PlayScene::ZOMBIE_GEN_TIMES_NOW=0;
PlayScene::PlayScene(QWidget *parent) : QWidget(parent)
{
    /*item-->scene-->view//元素-->场景-->视图*/
    //设置主场景
    setFixedSize(900,600);
    setWindowIcon(QIcon(":/bgc/res\\Other/headtitle.png"));
    setWindowTitle("植物大战僵尸");

    //随机数种子
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));

    timer = new QTimer;
    //创建场景
    scene = new QGraphicsScene(this);
    //背景图场景
    view = new QGraphicsView(scene, this);
    view->resize(902, 602);

    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/bgc/res\\Other/map0.jpg"));

    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
/*****************************************************************/
    //设置场景位置保证场景中心到达视图中心位置
     scene->setSceneRect(150, 0, 900, 600);

     //加入卡片槽
     Shop *shop = new Shop;
     shop->setPos(520, 45);
     scene->addItem(shop);
     //加入铲子
     Shovel *shovel = new Shovel;
     shovel->setPos(830, 40);
     scene->addItem(shovel);
     //加入地图事件
     Map *map = new Map;
     map->setPos(618, 326);
     scene->addItem(map);
     //设置割草机
     for (int i = 0; i < 5; ++i)
     {
         Mower *mower = new Mower;
         mower->setPos(210, 130 + 98 * i);
         scene->addItem(mower);
     }


     //绑定信号和槽函数
     connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
 //    connect(timer, &QTimer::timeout, this, &MainWindow::addZombie);
 //    connect(timer, &QTimer::timeout, this, &MainWindow::check);

     //播放音乐，启动定时器等等
 //    sound->play();
     timer->start(33);
}

PlayScene::~PlayScene()
{
    delete sound;
    delete timer;
    delete scene;
    delete view;
}
