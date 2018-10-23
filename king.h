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
    int row_kg_now;
    int column_kg_now;
    bool kg_checked=true; //white:true black:false
    set<int>* list_kg;
    void go_to();
    bool operator <(king const &k) const;
};

#endif // KING_H
