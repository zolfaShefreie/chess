#ifndef BISHOP_H
#define BISHOP_H

#include <set>
using namespace std;

class bishop
{
public:
    bishop();
    bishop(int r, int c);
    int row_b_now; //current row
    int column_b_now; //current column
    set<int> list_b; //this set consists of possible positions to move to(without considering the presence of other pieces)
    bool b_checked= true; //true:white & false:black
    void go_to(); //this method finds possible positions and ads them to list_
    void remove_some_mem(int j,int i);
    bool operator <( const bishop &b) const;
    bool operator ==( const bishop &b) const;
    bool threat_king;


};

#endif // BISHOP_H
