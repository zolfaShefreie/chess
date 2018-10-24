#ifndef INFOBASE_H
#define INFOBASE_H
#include<set>
#include<iterator>
#include"bishop.h"
#include"king.h"
#include"knight.h"
#include"pawn.h"
#include"queen.h"
#include"rook.h"

class infobase
{
    enum nameOfItem
    {
        black_pawn=1,
        black_king=2,
        black_bishop=3,
        black_knight=4,
        black_queen=5,
        black_rook=6,
        white_pawn=7,
        white_king=8,
        white_bishop=9,
        white_knite=10,
        white_queen=11,
        white_rook=12,
        none_of_them,
    };

public:
    std::set<king> white_kg;
    std::set<queen> white_q;
    std::set<pawn> white_p;
    std::set<bishop> white_b;
    std::set<knight> white_k;
    std::set<rook> white_r;

    std::set<king> black_kg;
    std::set<queen> black_q;
    std::set<pawn> black_p;
    std::set<bishop> black_b;
    std::set<knight> black_k;
    std::set<rook> black_r;
    // list zakhireh
    infobase();
    nameOfItem find(int r,int c);
    void edit_list_to_go(int r,int c);

};

#endif // INFOBASE_H
