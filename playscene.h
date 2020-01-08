#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPainter>
#include <mycard.h>

class PlayScene : public QMainWindow
{
    Q_OBJECT
private:
    int levelid;
    int gameArray[4][4];
    int curArray[4][4];
    MyCard * card[5][4];
    int LastX, LastY, LastVal;

public:
//    explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelid);

    void paintEvent(QPaintEvent *);
    bool beSucceed();

signals:
    void playSceneBack();

public slots:
};

#endif // PLAYSCENE_H
