#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>

class MyCard : public QPushButton
{
    Q_OBJECT
private:
    QString CardImg;
    QString CoverImg;
    QTimer * timer1;
    int Count;
public:
    int Condition;
    MyCard(QString CardImg, int Number);
    void change();
    void changeandback();
    int Number;
signals:
    void askJduge();

public slots:
};

#endif // MYCOIN_H
