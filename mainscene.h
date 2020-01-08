#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <chooseleverscene.h>
#include <playscene.h>

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT
private:
    ChooseLeverScene * chooseScene;

public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //绘图事件
    void paintEvent(QPaintEvent *);


private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
