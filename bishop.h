#ifndef BISHOP_H
#define BISHOP_H

#include <QList>


class bishop
{
public:
    bishop();
    bishop(int r, int c);
    int row_b_now;
    int column_b_now;
//    bool b_checked= true; //true:white & false:black
    QList<int> go_to();


};

#endif // BISHOP_H
