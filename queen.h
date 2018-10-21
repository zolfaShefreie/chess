#ifndef QUEEN_H
#define QUEEN_H

#include <set>

using namespace std;

class queen
{
public:
    queen();
    queen(int rq, int cq);
    int row_q_now;
    int column_q_now;
    set<int> list_q;
    bool b_checked= true; //true:white & false:black
    void go_to1();
};

#endif // QUEEN_H
