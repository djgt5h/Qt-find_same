#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include <mypushbutton.h>
#include <QTimer>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    //设置主场景样式
    ui->setupUi(this);
    connect(ui->actionquit, &QAction::triggered, [=](){
        this->close();
    });
    this->setFixedSize(500, 700);
    this->setWindowTitle("找相同 - 首页");
    this->setWindowIcon(QIcon(":/rec/windowIcon.png"));

    //创建出选择关卡场景
    chooseScene = new ChooseLeverScene;
    //监听选择关卡场景中返回按钮的事件
    connect(chooseScene, &ChooseLeverScene::chooseSceneBack, [=](){
        QTimer::singleShot(300, this, [=](){
            chooseScene->hide();
            this->show();
        });
    });

    //开始按钮的创建
    MyPushButton * startBtn = new MyPushButton( "://rec/start1.png" );
    startBtn->setParent(this);
    startBtn->move(this->width()/2 - startBtn->width()/2, this->height() - this->height()/15 - startBtn->height());
    connect(startBtn, &QPushButton::clicked, [=](){
        //点击开始按钮，执行变化效果
        startBtn->zoom1();
        startBtn->zoom2();
        //隐藏当前 延时进入到第二个选择场景的界面中 否则就看不到跳跃了
        QTimer::singleShot(300, this, [=](){
            this->hide();
            chooseScene->show();
        });
    });




}


void MainScene::paintEvent(QPaintEvent *)
{
    //设置主界面的背景
    QPainter painter(this);
    QPixmap pix;
    pix.load("://rec/mainbackground.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //设置标题图片
    pix.load("://rec/findsame.png");
//    pix = pix.scaled(pix.width()/2, pix.height()/2);
    painter.drawPixmap(this->width()/2 - pix.width()/2, 60, pix);

}

MainScene::~MainScene()
{
    delete ui;
}

