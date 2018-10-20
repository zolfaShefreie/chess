#ifndef ROOK_H
#define ROOK_H

#include<QList>
class rook
{
public:
    rook();
    rook(int r,int c);
    int row_r_now;
    int column_r_now;
    QList<int> go_to();
};

#endif // ROOK_H
