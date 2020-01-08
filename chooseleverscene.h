#ifndef CHOOSELEVERSCENE_H
#define CHOOSELEVERSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <playscene.h>

class ChooseLeverScene : public QMainWindow
{
    Q_OBJECT
private:
    PlayScene   * playScene;
public:
    explicit ChooseLeverScene(QWidget *parent = nullptr);

    //重写绘图函数
    void paintEvent(QPaintEvent *);

signals:
    //自定义信号只需要申明不需要实现
    void chooseSceneBack();

public slots:
};

#endif // CHOOSELEVERSCENE_H
