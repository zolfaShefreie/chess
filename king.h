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
<<<<<<< HEAD
    bool kg_checked=true; //white:true black:false
    set<int>* list_kg;
    void go_to();

=======
    QList<int> go_to();
>>>>>>> 64d7edab5b722e1253d9bdb32d3464b4c7ff5132
};

#endif // KING_H
