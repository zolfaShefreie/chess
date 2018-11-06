#ifndef KNIGHT_H
#define KNIGHT_H
#include<Qlist>
#include<set>
using namespace std;

class knight
{
public:
    knight();
    knight(int r, int c);
    int row_k_now; //current row
    int column_k_now; //current column
    set<int> list_k; //this set consists of possible positions that it can move to(without considering the presence of other pieces)
    bool k_checked=true;//true=white   false=black
    void go_to();// the list of where it can go
    bool operator <( knight const & k) const;
    bool operator ==( const knight &k) const;
    bool threat_king;


};

#endif // KNIGHT_H
