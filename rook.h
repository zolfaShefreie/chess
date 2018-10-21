#ifndef ROOK_H
#define ROOK_H
#include<set>
using namespace std;

class rook
{
public:
    rook();
    rook(int r,int c);
    int row_r_now;
    int column_r_now;
    void go_to();
    set<int>* list_r;
    bool r_checked=true; //true:white and false:black

};

#endif // ROOK_H
