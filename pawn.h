#ifndef PAWN_H
#define PAWN_H
#include<QList>

class pawn
{
public:
    pawn();
    pawn(int r,int c,bool wob);
    int row_p_now;
    int column_p_now;
    int first_step=0;
    bool checked;//white or black
    QList<int> *go_to();
};

#endif // PAWN_H
