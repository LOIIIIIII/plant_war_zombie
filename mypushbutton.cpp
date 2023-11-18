#include "mypushbutton.h"

//MyPushButton::MyPushButton(QWidget *parent)
//    : QWidget{parent}
//{

//}
MyPushButton::MyPushButton(QString normalimg,QString pressimg)
{
    this->NormalButton=normalimg;
    this->PressButton=pressimg;
    QPixmap pix;
    bool ret=pix.load(NormalButton);
    if(!ret)
    {
        //qDebug()<<"图片加载失败";
        return;
    }
    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px}");
    //设置图标
    this->setIcon(pix);
    //设置图表大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}


void MyPushButton::mousePressEvent(QMouseEvent*e)
{
    if(this->PressButton!="")
    {
        QPixmap pix;
        bool ret=pix.load(this->PressButton);
        if(!ret)
        {
            //qDebug()<<"图片加载失败";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图表大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent*e)
{
    if(this->NormalButton!="")
    {
        QPixmap pix;
        bool ret=pix.load(this->NormalButton);
        if(!ret)
        {
            //qDebug()<<"图片加载失败";
            return;
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px}");
        //设置图标
        this->setIcon(pix);
        //设置图表大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}








