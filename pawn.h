#ifndef PAWN_H
#define PAWN_H
#include<set>
using namespace std;

class pawn
{
public:
    pawn();
    pawn(int r,int c,bool wob);
    int row_p_now; //current row
    int column_p_now; //current column
    int first_step=0;
    set<int>  list_p; //this set consists of possible positions that it can move to(without considering the presence of other pieces)
    bool p_checked= true; //white or black
    void go_to();  //this method finds possible positions and adds them to list_p
    bool operator <(pawn const & p) const;
    bool operator ==(pawn const & p) const;
    bool threat_king;


};

#endif // PAWN_H
