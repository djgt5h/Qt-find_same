#include "mypushbutton.h"
#include <QPropertyAnimation>


MyPushButton::MyPushButton( QString normalImg, QString pressImg )
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(this->normalImgPath);
    if(!ret)
    {
        QString str = QString("%1 图片加载失败").arg( this->normalImgPath );
        qDebug() << str;
        return ;
    }

    pix = pix.scaled(pix.width()/2, pix.height()/2);
    //设定图片大小
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet( "QPushButton{border:0px;}");//设置不规则图片样式
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

}

//向下跳跃
void MyPushButton::zoom1()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    //设定时间间隔
    animation->setDuration(200);
    //设置动态对象起始结束位置
    animation->setStartValue((QRect( this->x(), this->y(), this->width(), this->height())));
    animation->setEndValue((QRect( this->x(), this->y()+10, this->width(), this->height())));
    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}
//向上跳跃
void MyPushButton::zoom2()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");
    //设定时间间隔
    animation->setDuration(200);
    //设置动态对象起始结束位置
    animation->setStartValue((QRect( this->x(), this->y()+10, this->width(), this->height())));
    animation->setEndValue((QRect( this->x(), this->y(), this->width(), this->height())));
    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent * e)
{
    if(this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret)
        {
            QString str = QString("%1 图片加载失败").arg( this->pressImgPath );
            qDebug() << str;
            return ;
        }
        pix = pix.scaled(pix.width()/2, pix.height()/2);
        //设定图片大小
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet( "QPushButton{border:0px;}");//设置不规则图片样式
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    //其他交给父亲处理
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent * e)
{
    if(this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret)
        {
            QString str = QString("%1 图片加载失败").arg( this->normalImgPath );
            qDebug() << str;
            return ;
        }
        pix = pix.scaled(pix.width()/2, pix.height()/2);
        //设定图片大小
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet( "QPushButton{border:0px;}");//设置不规则图片样式
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    //其他交给父亲处理
    QPushButton::mouseReleaseEvent(e);
}
