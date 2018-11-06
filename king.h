#ifndef KING_H
#define KING_H
#include<QList>
#include<set>

using namespace std;

class king
{
public:
    king();
    king(int r ,int c);
    int row_kg_now; //current row
    int column_kg_now; //current column
    bool kg_checked=true; //white:true black:false
    set<int> list_kg;   //this set consists of possible positions that it can move to(without considering the presence of other pieces)
    void go_to();    //this method finds possible positions and adds them to list_kg
    void edit_list(int i,int j);
    bool operator <(king const &k) const;
    bool operator ==(king const &k) const;
    bool threat_king=false;
};

#endif // KING_H
