#ifndef KNIGHT_H
#define KNIGHT_H
#include<Qlist>

class knight
{
public:
    knight();
    knight(int r, int c);
    int row_k_now;
    int column_k_now;
    //bool k_checked=true;//true=white   false=black
    QList<int>* go_to();//return the list of where can it go
};

#endif // KNIGHT_H
