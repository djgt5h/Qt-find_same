#include "chooseleverscene.h"
#include <QAction>
#include <QPainter>
#include <QLabel>
#include <mypushbutton.h>
#include <playscene.h>
#include <QTimer>

ChooseLeverScene::ChooseLeverScene(QWidget *parent) : QMainWindow(parent)
{

    this->setFixedSize(500, 700);
    this->setWindowTitle("找相同 - 选择关卡");
    this->setWindowIcon(QIcon(":/rec/windowIcon.png"));

    //创建菜单栏 菜单项
    QMenuBar * Bar = menuBar();
    this->setMenuBar(Bar);
    QMenu * startMenu = Bar->addMenu("开始");
    QAction * quitAction = startMenu->addAction("退出");
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //创建返回按钮
    MyPushButton * backBtn = new MyPushButton(":/rec/back1.png", ":/rec/back2.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    connect(backBtn, &MyPushButton::clicked, [=](){
        emit this->chooseSceneBack();
    });

    playScene = new PlayScene(1);



    //选择关卡按钮
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            //设置关卡图标
            MyPushButton * menuBtn = new MyPushButton("://rec/levelIcon.png");
            menuBtn->setParent(this);
            int dx = 80 + j * 90, dy = 150 + i * 90;
            int levelid = i * 4 + j + 1;
            menuBtn->move( dx, dy );

            //设置关卡上的数字
            QLabel * levelLabel = new QLabel(this);
            levelLabel->setFixedSize(QSize(menuBtn->width(), menuBtn->height()));
            levelLabel->setText( QString::number(levelid));
            levelLabel->move( dx, dy );
            levelLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            levelLabel->setAttribute(Qt::WA_TransparentForMouseEvents);//设置鼠标穿透，否则点击不到被它覆盖的按钮

            //处理点击按钮后的事件
            connect(menuBtn, &MyPushButton::clicked, [=](){
                  this->hide();
                playScene = new PlayScene(levelid);
                playScene->show();

                //监听游戏界面的返回按钮事件
                connect(playScene, &PlayScene::playSceneBack, [=](){
//                    QTimer::singleShot(500, this, [=](){
                        playScene->close();
                        this->show();
//                    });
                });
            });
        }
    }

}

//重写绘图事件
void ChooseLeverScene::paintEvent(QPaintEvent *)
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
