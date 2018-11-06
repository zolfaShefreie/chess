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
    set<int> list_r;  //this set consists of possible positions that it can move to(without considering the presence of other pieces)
    void go_to();    //this method finds possible positions and adds them to list_r

    bool r_checked=true; //true:white and false:black
    static const bool is_rook = true;
    bool operator <( rook const &r) const;
    bool operator ==( rook const &r) const;
    void remove_some_mem(int j,int i);   //this method removes illegal moves(jumping over pieces) from list_r

    bool threat_king;

};

#endif // ROOK_H
