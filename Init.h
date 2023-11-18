#ifndef INIT_H
#define INIT_H
//初始化工作

//产生僵尸的数量
#define ZOMBIE_GEN_TIMES 50

//产生一个僵尸需要一个变量从0累加到这个值
#define GEN_ONE_TIME 100

//初始化阳光值
#define INIT_SUN_NUM 200

//初始化卡片冷却时间
#define cooltime_SunFlower  227
#define cooltime_Peashooter 227
#define cooltime_CherryBomb 227
#define cooltime_WallNut    227
#define cooltime_PotatoMine 227
#define cooltime_SnowPea    227
#define cooltime_Repeater   227


//植物的生命值和攻击力
#define hp_WallNut 4000
#define hp_NormalPlant 300

#define atk_CherryBomb 1800
#define atk_PotatoMine 1800

#define atk_Peashooter 25
#define atk_Repeater 25
#define atk_SnowPea 25


//僵尸的生命值，攻击力，行走速度
#define hp_BasicZombie  270
#define hp_ConeZombie  640
#define hp_ScreenZombie  1370
#define hp_BucketZombie  1370
#define hp_FootballZombie  1670

#define atk_Zombie  (100 * 33 / 1000)

#define speed_zombie_1  (80.0 * 33 / 1000 / 4.7)
#define speed_zombie_2  (80.0 * 33 / 1000 / 2.5)
#endif // INIT_H
