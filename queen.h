#ifndef QUEEN_H
#define QUEEN_H

#include <QList>


class queen
{
public:
    queen();
    queen(int rq, int cq);
    int row_q_now;
    int column_q_now;
//    bool b_checked= true; //true:white & false:black
    QList<int> go_to1();
};

#endif // QUEEN_H
