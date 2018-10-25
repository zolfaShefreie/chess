#ifndef PAWN_H
#define PAWN_H
#include<set>
using namespace std;

class pawn
{
public:
    pawn();
    pawn(int r,int c,bool wob);
    int row_p_now;
    int column_p_now;
    int first_step=0;
    set<int>  list_p;
    bool p_checked= true;//white or black
    static const bool is_pawn = true;
    void go_to();
    bool operator <(pawn const & p) const;

};

#endif // PAWN_H
