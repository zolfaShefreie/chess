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
    bool q_checked= true; //true:white & false:black
    static const bool is_queen = true;
    void go_to1();
    bool operator <(queen const &q) const;
    void remove_some_mem(int j,int i);
};

#endif // QUEEN_H
