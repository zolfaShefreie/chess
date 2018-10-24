#ifndef BISHOP_H
#define BISHOP_H

#include <set>

using namespace std;

class bishop
{
public:
    bishop();
    bishop(int r, int c);
    int row_b_now;
    int column_b_now;
    set<int> list_b;
    bool b_checked= true; //true:white & false:black
    void go_to();
    void remove_some_mem(int j,int i);
    bool operator <( const bishop &b) const;
    bool operator ==( const bishop &b) const;

};

#endif // BISHOP_H
