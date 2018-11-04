#ifndef INFOBASE_H
#define INFOBASE_H
#include<set>
#include <QList>
#include<iterator>
#include<QIcon>
#include"bishop.h"
#include"king.h"
#include"knight.h"
#include"pawn.h"
#include"queen.h"
#include"rook.h"
#include "save.h"

class infobase
{

public:

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
        white_knight=10,
        white_queen=11,
        white_rook=12,
        none_of_them,
    };

    QList<king> white_kg;
    QList<queen> white_q;
    QList<pawn> white_p;
    QList<bishop> white_b;
    QList<knight> white_k;
    QList<rook> white_r;

    QList<king> black_kg;
    QList<queen> black_q;
    QList<pawn> black_p;
    QList<bishop> black_b;
    QList<knight> black_k;
    QList<rook> black_r;
    QList<save> qs;
    infobase();
    nameOfItem find(int r,int c);
    void add_a_piece(int r,int c,int which_item);
    void edit_list_to_go(int r,int c);
    void  change_position(int r,int c,int r1,int r2);
    void delete_a_piece(int r,int c);
    int search_in_list(int r,int c,int r1,int c1);
    QIcon get_icon(int r,int c);
    bool threat_king(int);
    bool vindicative(int,int,int);
    bool delete_threat_king(int r,int c,string bOrW);
    bool win(int bOrW);

};

#endif // INFOBASE_H
