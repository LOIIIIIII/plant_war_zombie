#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QGraphicsItem>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalimg,QString pressimg="");
    QString NormalButton;
    QString PressButton;
    //重定义鼠标按下和抬起的操作
    void mousePressEvent(QMouseEvent*e);
    void mouseReleaseEvent(QMouseEvent*e);
signals:

};

#endif // MYPUSHBUTTON_H
