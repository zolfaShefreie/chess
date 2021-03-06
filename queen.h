#ifndef QUEEN_H
#define QUEEN_H

#include <QList>

using namespace std;

class queen
{
public:
    queen();
    queen(int rq, int cq);
    int row_q_now; //current
    int column_q_now;
    QList<int> list_q; //this set consists of possible positions that it can move to(without considering the presence of other pieces)
    bool q_checked= true; //true:white & false:black
    static const bool is_queen = true;
    void go_to1();  //this method finds possible positions and adds them to list_q
    bool operator <(queen const &q) const;
    bool operator ==(queen const &q) const;
    void remove_some_mem(int j,int i);  //this method removes illegal moves(jumping over pieces) from list_q
    bool threat_king=false;

};

#endif // QUEEN_H
