#include "infobase.h"

infobase::infobase()
{
    // jaygah avalieh mohreha
    pawn p;
    rook r;
    knight k;
    bishop b;
    king kg;
    queen q;
    for(int i=0;i<8;i++)
    {
        p.checked=true;
        p.column_p_now=i;
        p.row_p_now=1;
        this->white_p.insert(p);

        p.checked=false;
        p.column_p_now=i;
        p.row_p_now=6;
        this->white_p.insert(p);
    }

    kg.kg_checked=false;
    kg.row_kg_now=7;
    kg.column_kg_now=3;
    this->black_kg.insert(kg);
    q.q_checked=false;
    q.row_q_now=7;
    q.column_q_now=4;
    this->black_q.insert(q);

    kg.kg_checked=true;
    kg.row_kg_now=0;
    kg.column_kg_now=3;
    this->white_kg.insert(kg);
    q.q_checked=false;
    q.row_q_now=0;
    q.column_q_now=4;
    this->black_q.insert(q);

    b.b_checked=false;
    b.row_b_now=7;
    b.column_b_now=2;
    this->black_b.insert(b);
    b.column_b_now=5;
    this->black_b.insert(b);

    b.b_checked=true;
    b.row_b_now=0;
    b.column_b_now=2;
    this->white_b.insert(b);
    b.column_b_now=5;
    this->white_b.insert(b);

    k.k_checked=false;
    k.row_k_now=7;
    k.column_k_now=1;
    this->black_k.insert(k);
    k.column_k_now=6;
    this->black_k.insert(k);

    k.k_checked=true;
    k.row_k_now=0;
    k.column_k_now=1;
    this->white_k.insert(k);
    k.column_k_now=6;
    this->white_k.insert(k);

    r.r_checked=false;
    r.row_r_now=7;
    r.column_r_now=0;
    this->black_r.insert(r);
    r.column_r_now=7;
    this->black_r.insert(r);

    r.r_checked=true;
    r.row_r_now=0;
    r.column_r_now=0;
    this->white_r.insert(r);
    r.column_r_now=7;
    this->white_r.insert(r);

}

infobase::nameOfItem infobase::find(int r, int c)
{
    //peyda kardan mohreh ba estefadeh ye position
    pawn p;
    p.column_p_now=c;
    p.row_p_now=r;
    if(this->black_p.find(p)!= this->black_p.end())
        return black_pawn;
    if(this->white_p.find(p)!=this->white_p.end())
        return white_pawn;

    rook ro;
    ro.column_r_now=c;
    ro.row_r_now=r;
    if(this->black_r.find(ro)!=this->black_r.end())
        return black_rook;
    if(this->white_r.find(ro)!=this->white_r.end())
        return white_rook;

    knight k;
    k.column_k_now=c;
    k.row_k_now=r;
    if(this->black_k.find(k)!= this->black_k.end())
        return black_knight;
    if(this->white_k.find(k)!=this->white_k.end())
        return white_knite;

    bishop b;
    b.column_b_now=c;
    b.row_b_now=r;
    if(this->black_b.find(b)!=this->black_b.end())
        return black_bishop;
    if(this->white_b.find(b)!=this->white_b.end())
        return white_bishop;

    king kg;
    kg.column_kg_now=c;
    kg.row_kg_now=r;
    if(this->black_kg.find(kg)!=this->black_kg.end())
        return black_king;
    if(this->white_kg.find(kg)!=this->white_kg.end())
        return white_king;

    queen q;
    q.column_q_now=c;
    q.row_q_now=r;
    if(this->black_q.find(q)!=this->black_q.end())
        return black_queen;
    if(this->white_q.find(q)!=this->white_q.end())
        return white_queen;

    return none_of_them;

}

void infobase::edit_list_to_go(int r, int c)
{
    //
    nameOfItem index;
    if(find(r,c)==black_bishop)
    {
        bishop b;
        b.column_b_now=c;
        b.row_b_now=r;
        auto itr=this->black_b.find(b);
        b=(*itr);
        b.go_to();
        int cc,rr;
        for(int s:b.list_b)
        {
           cc=s%10;
           rr=(s-cc)/10;
           index=this->find(rr,cc);
           if(index<7)
           {
               //ham rang
               b.list_b.erase(s);
               b.remove_some_mem(cc,rr);
           }
           else if(index==8)
           {
               //hazf shah moghabel
               b.list_b.erase(s);
           }
           else
           {
               //gheyr ham rang
               b.list_b.erase(s);
               b.remove_some_mem(cc,rr);
           }
        }
    }

    if(find(r,c)==white_bishop)
    {
        bishop b;
        b.column_b_now=c;
        b.row_b_now=r;
        auto itr=this->white_b.find(b);
        b=(*itr);
        b.go_to();
        int cc,rr;
        for(int s:b.list_b)
        {
           cc=s%10;
           rr=(s-cc)/10;
           index=this->find(rr,cc);
           if(index>6)
           {
               //ham rang
               b.list_b.erase(s);
               b.remove_some_mem(cc,rr);
           }
           else if(index==2)
           {
               //hazf shah moghabel
               b.list_b.erase(s);
           }
           else
           {
               //gheyr ham rang
               b.list_b.erase(s);
               b.remove_some_mem(cc,rr);
           }
        }

    }

    if(find(r,c)==black_pawn)
    {

    }

    if(find(r,c)==white_pawn)
    {

    }

    if(find(r,c)==black_knight)
    {

    }

    if(find(r,c)==white_knite)
    {

    }

    if(find(r,c)==black_queen)
    {

    }

    if(find(r,c)==white_queen)
    {

    }
}



