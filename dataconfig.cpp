#include "dataconfig.h"
#include <QObject>
#include <QMap>
#include <QVector>

dataconfig::dataconfig(QObject *parent) : QObject(parent)
{
    //1 - 5关 2个数字
    int a1[4][4] = { {1, 2, 2, 1},
                    {1, 1, 1, 1},
                    {1, 1, 1, 1},
                    {1, 1, 1, 1} };
    QVector<QVector<int> > v;
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a1[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(1, v);
    v.clear();


    int a2[4][4] = { {1, 2, 2, 1},
                    {1, 1, 2, 1},
                    {1, 2, 1, 1},
                    {1, 1, 1, 1} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a2[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(2, v);
    v.clear();


    int a3[4][4] = { {1, 4, 4, 1},
                    {1, 4, 4, 1},
                    {1, 4, 4, 1},
                    {1, 1, 1, 1} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a3[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(3, v);
    v.clear();


    int a4[4][4] = { {3, 3, 2, 3},
                    {3, 2, 2, 3},
                    {3, 3, 2, 3},
                    {3, 3, 3, 3} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a4[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(4, v);
    v.clear();


    int a5[4][4] = { {6, 7, 7, 6},
                    {6, 7, 6, 7},
                    {7, 7, 7, 7},
                    {7, 6, 7, 6} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a5[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(5, v);
    v.clear();

    //6 - 10关 3个数字
    int a6[4][4] = { {1, 1, 2, 1},
                    {1, 4, 2, 1},
                    {1, 1, 4, 3},
                    {1, 1, 1, 3} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a6[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(6, v);
    v.clear();

    int a7[4][4] = { {4, 7, 5, 7},
                    {5, 7, 4, 4},
                    {5, 5, 5, 5},
                    {4, 7, 7, 7} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a7[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(7, v);
    v.clear();

    int a8[4][4] = { {2, 3, 2, 1},
                    {2, 3, 2, 1},
                    {1, 2, 3, 2},
                    {1, 1, 3, 1} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a8[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(8, v);
    v.clear();

    int a9[4][4] = { {4, 3, 1, 3},
                    {1, 4, 1, 1},
                    {1, 1, 4, 3},
                    {3, 1, 1, 4} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a9[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(9, v);
    v.clear();

    int a10[4][4] = { {1, 6, 2, 1},
                    {1, 6, 2, 1},
                    {6, 1, 6, 6},
                    {1, 6, 1, 1} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a10[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(10, v);
    v.clear();

    //11 - 15关 4个数字
    int a11[4][4] = { {1, 3, 2, 5},
                    {1, 3, 2, 1},
                    {2, 5, 3, 3},
                    {2, 5, 1, 5} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a11[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(11, v);
    v.clear();

    int a12[4][4] = { {2, 3, 2, 1},
                    {1, 4, 2, 1},
                    {1, 2, 4, 3},
                    {1, 1, 1, 1} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a12[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(12, v);
    v.clear();

    int a13[4][4] = { {2, 3, 2, 1},
                    {1, 4, 2, 1},
                    {1, 1, 4, 3},
                    {1, 2, 1, 1} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a13[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(13, v);
    v.clear();

    int a14[4][4] = { {3, 3, 2, 1},
                    {1, 4, 2, 1},
                    {1, 3, 4, 3},
                    {1, 1, 1, 1} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a14[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(14, v);
    v.clear();

    int a15[4][4] = { {1, 3, 2, 1},
                    {1, 4, 2, 1},
                    {1, 1, 4, 3},
                    {1, 1, 1, 1} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a15[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(15, v);
    v.clear();

    int a16[4][4] = { {1,4,5,5},
                    {5,1,4,5},
                    {4,5,2,5},
                    {4,3,2,3} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a16[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(16, v);
    v.clear();

    int a17[4][4] = { {1, 2, 6, 8},
                    {5, 3, 5, 2},
                    {3, 8, 1, 2},
                    {8, 2, 8, 6} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a17[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(17, v);
    v.clear();

    int a18[4][4] = { {1, 3, 2, 3},
                    { 5, 5, 1, 8},
                    { 6, 2, 8, 5},
                    { 7, 7, 5, 6} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a18[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(18, v);
    v.clear();

    int a19[4][4] = { {1, 3, 2, 8},
                    {4, 1, 2, 6},
                    {5, 5, 4, 3},
                    {8, 7, 6, 7} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a19[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(19, v);
    v.clear();

    int a20[4][4] = { {1, 5, 5, 2},
                    {1, 4, 2, 3},
                    {8, 6, 4, 3},
                    {7, 8, 7, 6} };
    for(int i = 0; i < 4; i++) {
        QVector<int> v1;
        for(int j = 0; j < 4; j++) {
            v1.push_back(a20[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(20, v);
    v.clear();
}
