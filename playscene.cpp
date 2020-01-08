#include "playscene.h"
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <mypushbutton.h>
#include <QLabel>
#include <QFont>
#include <mycard.h>
#include <dataconfig.h>
#include <QTimer>
#include <synchapi.h>

PlayScene::PlayScene(int levelid)
{
    //初始化关卡号、待匹配的块等信息
    this->levelid = levelid;
    LastX = 4; LastY = 4; LastVal = -1;

    //构建尺寸、标题、应用图标
    this->setFixedSize(500, 700);
    QString tmp;
    tmp = QString("找相同 - 第%1关").arg(levelid);
    this->setWindowTitle(tmp);
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
        emit this->playSceneBack();
    });

    //显示具体关卡号
    QLabel * label = new QLabel(this);
    QString str = QString("Level: %1").arg(this->levelid);
    label->setText(str);
    QFont font;
    font.setFamily("宋体");
    font.setPointSize(20);
    label->setFont(font);
    label->setGeometry(30, this->height() - 50, 200, 50);
//    label->setGeometry(30, this->height() - label->height(), 120, 50);

    //构建游戏信息数组
    dataconfig data;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            gameArray[i][j] = data.mData[levelid][i][j];
            curArray[i][j] = 0;
        }
    }

    //提前准备好胜利标志，放在界面以外的地方
    QLabel * succeed = new QLabel(this);
    QPixmap pix;
    pix.load("://rec/succeed.png");
    succeed->setGeometry(-100, -100, pix.width(), pix.height());
    succeed->setPixmap(pix);



    //创建游戏主场景
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            //创建底边
            QLabel * bg = new QLabel(this);
            QPixmap pix;
            pix.load("://rec/BorderNode.png");
            bg->setGeometry(0, 0, pix.width(), pix.height());
            bg->setPixmap(pix);
            bg->move(129 + j * (pix.width()), 250 + i * (pix.height()));

            //创建卡片
            QString str;
            str = QString(":/rec/%1.png").arg(gameArray[i][j]);
            card[i][j] = new MyCard(str, gameArray[i][j]);
            card[i][j]->setParent(this);
            card[i][j]->move(129 + j * (card[i][j]->width()), 250 + i * (card[i][j]->height()));
            connect(card[i][j], &MyCard::clicked, [=](){
                if(card[i][j]->Condition == 0) {
                    if(LastX == 4 && LastY == 4) { //没有待匹配的块
                        Sleep(200);
                        card[i][j]->change();
                        curArray[i][j] = card[i][j]->Condition;
                        LastX = i; LastY = j; LastVal = gameArray[i][j];
                        curArray[i][j] = card[i][j]->Condition;
                    }
                    else { //有待匹配的块
                        if(card[i][j]->Number == card[LastX][LastY]->Number) {//匹配成功
                            Sleep(200);
                            card[i][j]->change();
                            curArray[i][j] = card[i][j]->Condition;
                            LastX = LastY = 4;
                        }
                        else {//匹配失败
                            Sleep(200);
                            curArray[i][j] = card[i][j]->Condition;
                            card[LastX][LastY]->change();
                            curArray[LastX][LastY] = card[LastX][LastY]->Condition;
                            LastX = LastY = 4;
                        }
                    }
                }
                if(this->beSucceed()) {
//                    qDebug() << "Succeed";
                    succeed->move(50, 130);

                }
            });
        }
    }

}

void PlayScene::paintEvent(QPaintEvent *)
{
    QPainter painter (this);
    QPixmap pix;
    //设置背景图
    pix.load(":/rec/playBackground");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    //设置标题图
    pix.load("://rec/findsame_1.png");
    painter.drawPixmap(this->width()/2 - pix.width()/2, 60, pix);


}

bool PlayScene::beSucceed()
{
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(this->curArray[i][j] == 0)
                return false;
        }
    }
    return true;
}
