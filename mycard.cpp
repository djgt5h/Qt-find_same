#include "mycard.h"
#include <QPixmap>
#include <QTimer>

MyCard::MyCard(QString CardImg, int Number)
{
    this->CardImg = CardImg; this->Number = Number;
    this->CoverImg = ":/rec/BorderNode.png";
    QPixmap pix;
    pix.load(CoverImg);
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
    this->Condition = 0;

//    可以用这种方法创建翻转动画
//    timer1 = new QTimer(this);
//    Count = 1;
//    connect(timer1, &QTimer::timeout, [=](){
//        if(Count == 1) {
//            QPixmap pix;
//            pix.load(CardImg);
//            this->setFixedSize(pix.width(), pix.height());
//            this->setStyleSheet("QPushButton{border:0px;}");
//            this->setIcon(pix);
//            this->setIconSize(QSize(pix.width(), pix.height()));
//            Count++;
//        }
//        if(Count == 2) {
//             QPixmap pix;
//             pix.load(CardImg);
//             this->setFixedSize(pix.width(), pix.height());
//             this->setStyleSheet("QPushButton{border:0px;}");
//             this->setIcon(pix);
//             this->setIconSize(QSize(pix.width(), pix.height()));
//             Count=1;
//             timer1->stop();
//        }
//    });

}

void MyCard::change()
{
    if(Condition == 0) {
        QPixmap pix;
        pix.load(CardImg);
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    else {
        QPixmap pix;
        pix.load(CoverImg);
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }

    Condition = 1 - Condition;
}

//void MyCard::changeandback()
//{
//    timer1->start(30);
//}
