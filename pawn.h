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
    set<int> * list_p;
    bool checked;//white or black
<<<<<<< HEAD
    QList<int> *go_to();
=======
    void go_to();

>>>>>>> 235a4312390dc02575e379360c4fdad252d67352
};

#endif // PAWN_H
