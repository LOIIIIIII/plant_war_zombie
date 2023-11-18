#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSound>
#include <QTimer>
#include"shop.h"
#include"shovel.h"
#include"map.h"
#include"mower.h"
class PlayScene : public QWidget
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    ~PlayScene() override;
private:
    QSound *sound;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;

    static int ZOMBIE_GEN_TIMES_NOW;
signals:

};

#endif // PLAYSCENE_H
