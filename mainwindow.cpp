#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QMenuBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建菜单栏
    QMenuBar*bar=menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu*startMenu=bar->addMenu("More");
    //创建退出菜单项
    QAction* quitAction=startMenu->addAction("QuitScene");
    QAction* quitAction1=startMenu->addAction("History");
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //设置主场景
    setFixedSize(900,600);
    setWindowIcon(QIcon(":/bgc/res\\Other/headtitle.png"));
    setWindowTitle("植物大战僵尸");
    //开始关卡的按钮
    MyPushButton *startbutton=new MyPushButton(":/bgc/res\\Other/menu1.png",":/bgc/res\\Other/menu2.png");
    //事例化选择关卡场景
    startbutton->setParent(this);
    startbutton->move(this->width()*0.7-startbutton->width()*0.5,this->height()*0.15);

    connect(startbutton,&MyPushButton::clicked,[=](){
        playscene=new PlayScene;
//        点击后停顿0.5s再跳转界面
        QTimer::singleShot(300,this,[=](){
            this->hide();
            playscene->show();
        });

    });


}
void MainWindow::paintEvent(QPaintEvent*)
{
    //利用画家来实现绘图主界面
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/bgc/res\\Other/menu.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}




MainWindow::~MainWindow()
{
    delete ui;

}

