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
        p.p_checked=true;
        p.column_p_now=i;
        p.row_p_now=1;
        this->white_p.push_back(p);
    }
    for(int i=0;i<8;i++)
    {

        p.p_checked=false;
        p.column_p_now=i;
        p.row_p_now=6;
        this->black_p.push_back(p);
    }

    kg.kg_checked=false;
    kg.row_kg_now=7;
    kg.column_kg_now=3;
    this->black_kg.push_back(kg);
    q.q_checked=false;
    q.row_q_now=7;
    q.column_q_now=4;
    this->black_q.push_back(q);

    kg.kg_checked=true;
    kg.row_kg_now=0;
    kg.column_kg_now=3;
    this->white_kg.push_back(kg);
    q.q_checked=false;
    q.row_q_now=0;
    q.column_q_now=4;
    this->white_q.push_back(q);

    b.b_checked=false;
    b.row_b_now=7;
    b.column_b_now=2;
    this->black_b.push_back(b);
    b.column_b_now=5;
    this->black_b.push_back(b);

    b.b_checked=true;
    b.row_b_now=0;
    b.column_b_now=2;
    this->white_b.push_back(b);
    b.column_b_now=5;
    this->white_b.push_back(b);

    k.k_checked=false;
    k.row_k_now=7;
    k.column_k_now=1;
    this->black_k.push_back(k);
    k.column_k_now=6;
    this->black_k.push_back(k);

    k.k_checked=true;
    k.row_k_now=0;
    k.column_k_now=1;
    this->white_k.push_back(k);
    k.column_k_now=6;
    this->white_k.push_back(k);

    r.r_checked=false;
    r.row_r_now=7;
    r.column_r_now=0;
    this->black_r.push_back(r);
    r.column_r_now=7;
    this->black_r.push_back(r);

    r.r_checked=true;
    r.row_r_now=0;
    r.column_r_now=0;
    this->white_r.push_back(r);
    r.column_r_now=7;

}

infobase::nameOfItem infobase::find(int r, int c)
{
    //peyda kardan mohreh ba estefadeh ye position
    pawn p;
    p.column_p_now=c;
    p.row_p_now=r;
    for(pawn p1:this->black_p)
    {
        if(p1==p)
        {
            return black_pawn;
        }
    }
    for(pawn p1:this->white_p)
    {
        if(p1==p)
        {
            return white_pawn;
        }
    }
//    if(this->white_p.find(p)!=this->white_p.end())
//    {
//        //return white_pawn;
//    }

    rook ro;
    ro.column_r_now=c;
    ro.row_r_now=r;
    for(rook ro1:this->black_r)
        if(ro1==ro)
            return black_rook;
    for(rook ro1:this->white_r)
        if(ro1==ro)
            return white_rook;
//    if(this->black_r.find(ro)!=this->black_r.end())
//        return black_rook;
//    if(this->white_r.find(ro)!=this->white_r.end())
//        return white_rook;

    knight k;
    k.column_k_now=c;
    k.row_k_now=r;
    for(knight k2:this->black_k)
        if(k2==k)
            return black_knight;
    for(knight k2:this->white_k)
        if(k2==k)
            return white_knight;
//    if(this->black_k.find(k)!= this->black_k.end())
//        return black_knight;
//    if(this->white_k.find(k)!=this->white_k.end())
//        return white_knight;

    bishop b;
    b.column_b_now=c;
    b.row_b_now=r;
    for(bishop b1:this->black_b)
        if(b1==b)
            return black_bishop;
    for(bishop b1:this->black_b)
        if(b1==b)
            return black_bishop;
//    if(this->black_b.find(b)!=this->black_b.end())
//        return black_bishop;
//    if(this->white_b.find(b)!=this->white_b.end())
//        return white_bishop;

    king kg;
    kg.column_kg_now=c;
    kg.row_kg_now=r;
    for(king kg1:this->black_kg)
        if(kg1==kg)
            return black_king;
    for(king kg1:this->white_kg)
        if(kg1==kg)
            return white_king;
//    if(this->black_kg.find(kg)!=this->black_kg.end())
//        return black_king;
//    if(this->white_kg.find(kg)!=this->white_kg.end())
//        return white_king;

    queen q;
    q.column_q_now=c;
    q.row_q_now=r;
    for(queen q1:this->black_q)
        if(q1==q)
            return black_queen;
    for(queen q1:this->white_q)
        if(q1==q)
            return white_queen;
//    if(this->black_q.find(q)!=this->black_q.end())
//        return black_queen;
//    if(this->white_q.find(q)!=this->white_q.end())
//        return white_queen;

    return none_of_them;


}

void infobase::add_a_piece(int r, int c, int which_item)
{
    // number of which_item likes nameOfItem
    if(which_item==1)
    {
        pawn p;
        p.row_p_now=r;
        p.column_p_now=c;
        p.p_checked=false;
        this->black_p.push_back(p);
    }
    else if(which_item==2)
    {
        king kg;
        kg.row_kg_now=r;
        kg.column_kg_now=c;
        kg.kg_checked=false;
        this->black_kg.push_back(kg);
    }
    else if(which_item==3)
    {
        bishop b;
        b.row_b_now=r;
        b.column_b_now=c;
        b.b_checked=false;
        this->black_b.push_back(b);
    }
    else if(which_item==4)
    {
        knight k;
        k.column_k_now=c;
        k.row_k_now=r;
        k.k_checked=false;
        this->black_k.push_back(k);
    }
    else if(which_item==5)
    {
        queen q;
        q.column_q_now=c;
        q.row_q_now=r;
        q.q_checked=false;
        this->black_q.push_back(q);
    }
    else if(which_item==6)
    {
        rook r1;
        r1.column_r_now=c;
        r1.row_r_now=r;
        r1.r_checked=false;
        this->black_r.push_back(r1);
    }
    else if(which_item==7)
    {
        pawn p;
        p.row_p_now=r;
        p.column_p_now=c;
        p.p_checked=true;
        this->white_p.push_back(p);
    }
    else if(which_item==8)
    {
        king kg;
        kg.row_kg_now=r;
        kg.column_kg_now=c;
        kg.kg_checked=true;
        this->white_kg.push_back(kg);
    }
    else if(which_item==9)
    {
        bishop b;
        b.row_b_now=r;
        b.column_b_now=c;
        b.b_checked=true;
        this->white_b.push_back(b);
    }
    else if(which_item==10)
    {
        knight k;
        k.column_k_now=c;
        k.row_k_now=r;
        k.k_checked=true;
        this->white_k.push_back(k);
    }
    else if(which_item==11)
    {
        queen q;
        q.column_q_now=c;
        q.row_q_now=r;
        q.q_checked=true;
        this->white_q.push_back(q);
    }
    else if(which_item==12)
    {
        rook r1;
        r1.column_r_now=c;
        r1.row_r_now=r;
        r1.r_checked=true;
        this->white_r.push_back(r1);
    }

}

void infobase::edit_list_to_go(int r, int c)
{
    //
    nameOfItem ind=find(r,c);
    nameOfItem index;
    if(ind==black_bishop)
    {   
        bishop b;
        b.b_checked=false;
        b.column_b_now=c;
        b.row_b_now=r;
        int it=this->black_b.indexOf(b);
        if (it!= -1)
        {
        this->black_b.removeAt(it);
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
               b.threat_king=true;
               for(king kingw:this->white_kg)
                   kingw.edit_list(r,c);
               b.list_b.erase(s);
           }
           else if(index!=none_of_them)
           {
               //gheyr ham rang
               b.remove_some_mem(cc,rr);
           }
        }
        this->black_b.push_back(b);
    }
    }

    if(ind==white_bishop)
    {
        bishop b;
        b.b_checked=true;
        b.column_b_now=c;
        b.row_b_now=r;
        int it=this->white_b.indexOf(b);
        if(it!=-1)
        {

        this->white_b.removeAt(it);
        b.go_to();
        int cc,rr;
        for(int s:b.list_b)
        {
           cc=s%10;
           rr=(s-cc)/10;
           index=this->find(rr,cc);
           if(index>6&&index!=13)
           {
               //ham rang
               b.list_b.erase(s);
               b.remove_some_mem(cc,rr);
           }
           else if(index==2)
           {
               //hazf shah moghabel
               b.threat_king=true;
               for(king king:this->black_kg)
                   king.edit_list(r,c);
               b.list_b.erase(s);
           }
           else if(index!=13)
           {
               //gheyr ham rang
               b.remove_some_mem(cc,rr);
           }
        }
        this->white_b.push_back(b);

        }

    }

    if(ind==black_pawn)
    {
        pawn p;
        p.p_checked=false;
        p.column_p_now=c;
        p.row_p_now=r;
        int it=this->black_p.indexOf(p);
        if(it!=-1)
        {
            if(p.row_p_now!=6)
                p.first_step=1;
        this->black_p.removeAt(it);
        p.go_to();
        int cc,rr;
        for(int s:p.list_p)
        {
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index!=none_of_them)
            {
                    if(rr-2==p.row_p_now)
                        p.list_p.erase(s);
                    else if(rr-1==p.row_p_now)
                    {
                        p.list_p.erase(s);
                        //betuneh mohreh harif ro bezaneh
                        index=this->find(rr-1,cc-1);
                        if(index!= white_king && index>6)
                            p.list_p.insert(((rr-1)*10+(cc-1)));
                        index=this->find(rr-1,cc+1);
                        if(index!= white_king && index>6)
                            p.list_p.insert(((rr-1)*10+(cc+1)));
                        else if(index==white_king)
                        {
                            p.threat_king=true;
                            for(king king:this->white_kg)
                                king.edit_list(r,c);
                        }
                    }
            }

        }
        this->black_p.push_back(p);
        }

    }

    if(ind==white_pawn)
    {
        pawn p;
        p.p_checked=true;
        p.column_p_now=c;
        p.row_p_now=r;
        int it=this->white_p.indexOf(p);
        if(it!=-1)
        {
            if(p.row_p_now!=1)
                p.first_step=1;
        this->white_p.removeAt(it);
        p.go_to();
        int cc,rr;
        for(int s:p.list_p)
        {
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index!=none_of_them)
            {
                    if(rr+2==p.row_p_now)
                        p.list_p.erase(s);
                    else if(rr+1==p.row_p_now)
                    {
                        p.list_p.erase(s);
                        //betuneh mohreh harif ro bezaneh
                        index=this->find(rr+1,cc+1);
                        if(index!= black_king && index<7)
                            p.list_p.insert(((rr+1)*10+(cc+1)));
                        index=this->find(rr+1,cc-1);
                        if(index!= black_king && index<7)
                            p.list_p.insert(((rr+1)*10+(cc-1)));
                        else if(index==black_king)
                        {
                            p.threat_king=true;
                            for(king kingw:this->black_kg)
                                kingw.edit_list(r,c);
                        }
                    }
            }

        }
        this->white_p.push_back(p);
        }
    }

    if(ind==black_knight)
    {
        knight k;
        k.k_checked=false;
        k.column_k_now=c;
        k.row_k_now=r;
        int it=this->black_k.indexOf(k);
        if(it!=-1)
        {
        this->black_k.removeAt(it);
        k.go_to();
        int cc,rr;
        for(int s:k.list_k)
        {
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index<7)
                //ham rang ro natuneh bezaneh
                k.list_k.erase(s);
            else if(index==8)
            {
                //shah harif ro natuneh bezaneh
                k.threat_king=true;
                for(king king:this->white_kg)
                    king.edit_list(r,c);
                k.list_k.erase(s);
            }
        }
        this->black_k.push_back(k);

        }

    }

    if(ind==white_knight)
    {
        knight k;
        k.k_checked=true;
        k.column_k_now=c;
        k.row_k_now=r;
        int it1=this->white_k.indexOf(k);
        if(it1!=-1)
        {
        this->white_k.removeAt(it1);
        k.go_to();
        int cc,rr;
        for(int s:k.list_k)
        {
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index>6&&index!=13)
                //ham rang ro natuneh bezaneh
                k.list_k.erase(s);
            else if(index==2)
            {
                //shah harif ro natuneh bezaneh
                k.threat_king=true;
                for(king king:this->black_kg)
                    king.edit_list(r,c);
                k.list_k.erase(s);
            }
        }
        this->white_k.push_back(k);

    }
    }

    if(ind==black_queen)
    {
        queen q;
        q.q_checked=false;
        q.column_q_now=c;
        q.row_q_now=r;
        int it=this->black_q.indexOf(q);
        if(it!=-1)
        {
        this->black_q.removeAt(it);
        q.go_to1();
        int cc ,rr;
        for(int s:q.list_q)
        {
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index<7)
            {
                // ham rang
                q.list_q.erase(s);
                q.remove_some_mem(cc,rr);
            }
            else if(index==8)
            {
                //shah moghabel ro nazaneh
                q.threat_king=true;
                for(king king:this->white_kg)
                    king.edit_list(r,c);
                q.list_q.erase(s);
            }
            else if(index!=13)
                q.remove_some_mem(cc,rr);
        }
        this->black_q.push_back(q);
    }
    }

    if(ind==white_queen)
    {
        queen q;
        q.q_checked=true;
        q.column_q_now=c;
        q.row_q_now=r;
        int it=this->white_q.indexOf(q);
        if(it!=-1)
        {
        this->white_q.removeAt(it);
        q.go_to1();
        int cc,rr;
        for(int s:q.list_q)
        {
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index>6&&index!=13)
            {
                q.list_q.erase(s);
                q.remove_some_mem(cc,rr);
            }
            else if(index==2)
            {
                q.threat_king=true;
                for(king king:this->black_kg)
                    king.edit_list(r,c);
                q.list_q.erase(s);
            }
            else if(index!=13)
                q.remove_some_mem(cc,rr);
        }
        this->white_q.push_back(q);
        }

    }

    if(ind==black_rook)
    {
        rook r1;
        r1.r_checked=false;
        r1.column_r_now=c;
        r1.row_r_now=r;
        int it=this->black_r.indexOf(r1);
        if(it!=-1)
        {
        this->black_r.removeAt(it);
        r1.go_to();
        int cc ,rr;
        for(int s:r1.list_r)
        {
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index<7)
            {
                r1.list_r.erase(s);
                r1.remove_some_mem(cc,rr);
            }
            else if(index==8)
            {
                r1.threat_king=true;
                for(king king:this->white_kg)
                    king.edit_list(r,c);
                r1.list_r.erase(s);
            }
            else if(index!=13)
                r1.remove_some_mem(cc,rr);
        }
        this->black_r.push_back(r1);
        }
    }

    if(ind==white_rook)
    {
        rook r1;
        r1.r_checked=true;
        r1.column_r_now=c;
        r1.row_r_now=r;
        int it=this->white_r.indexOf(r1);
        if(it!=-1)
        {
        this->white_r.removeAt(it);
        r1.go_to();
        int cc,rr;
        for(int s:r1.list_r)
        {
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index>6&&index!=13)
            {
                r1.list_r.erase(s);
                r1.remove_some_mem(cc,rr);
            }
            else if(index==2)
            {
                r1.threat_king=true;
                for(king king:this->black_kg)
                    king.edit_list(r,c);
                r1.list_r.erase(s);
            }
            else if(index!=13)
                r1.remove_some_mem(cc,rr);
        }
        this->white_r.push_back(r1);
        }
    }

    //if(ind==white_king)
    //{
        king kg;
        kg.kg_checked=true;
        kg.column_kg_now=c;
        kg.row_kg_now=r;
        int it=this->white_kg.indexOf(kg);
        if(it!=-1)
        {
        this->white_kg.removeAt(it);
        kg.go_to();
        int cc,rr;
        for(int s:kg.list_kg)
        {
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index>6&&index!=13)
            {
                if(rr-1==kg.row_kg_now)
                    kg.list_kg.erase(s);
                else if(rr+1==kg.row_kg_now)
                    kg.list_kg.erase(s);
                else if(cc-1==kg.column_kg_now)
                    kg.list_kg.erase(s);
                else if(cc+1==kg.column_kg_now)
                    kg.list_kg.erase(s);
            }
        }
        this->white_kg.push_back(kg);
    }

    //if(ind==black_king)
    //{
        king kg1;
        kg1.kg_checked=false;
        kg1.column_kg_now=c;
        kg1.row_kg_now=r;
        int it1=this->black_kg.indexOf(kg1);
        if(it1!=-1)
        {
        this->black_kg.removeAt(it);
        kg1.go_to();
        int cc1,rr1;
        for(int s:kg.list_kg)
        {
            cc1=s%10;
            rr1=(s-cc1)/10;
            index=this->find(rr1,cc1);
            if(index<7)
            {
                if(rr1-1==kg.row_kg_now)
                    kg.list_kg.erase(s);
                else if(rr1+1==kg.row_kg_now)
                    kg.list_kg.erase(s);
                else if(cc1-1==kg.column_kg_now)
                    kg.list_kg.erase(s);
                else if(cc1+1==kg.column_kg_now)
                    kg.list_kg.erase(s);
            }
        }
        this->black_kg.push_back(kg1);
    }

}

void infobase::change_position(int r, int c,int r1,int c1)
{
    nameOfItem index=this->find(r,c);
    if(index==black_bishop)
    {
        bishop b;
        b.column_b_now=c;
        b.row_b_now=r;
        b.b_checked=false;
        this->black_b.removeAt(this->black_b.indexOf(b));
        b.row_b_now=r1;
        b.column_b_now=c1;
        b.b_checked=false;
        this->black_b.push_back(b);
    }
    else if(index==white_bishop)
    {
        bishop b;
        b.column_b_now=c;
        b.row_b_now=r;
        b.b_checked=true;
        this->white_b.removeAt(this->white_b.indexOf(b));
        b.row_b_now=r1;
        b.column_b_now=c1;
        b.b_checked=true;
        this->white_b.push_back(b);
    }
    else if(index==black_knight)
    {
        knight k;
        k.column_k_now=c;
        k.row_k_now=r;
        k.k_checked=false;
        this->black_k.removeAt(this->black_k.indexOf(k));
        k.row_k_now=r1;
        k.column_k_now=c1;
        k.k_checked=false;
        this->black_k.push_back(k);
    }
    else if(index==white_knight)
    {
        knight k;
        k.column_k_now=c;
        k.row_k_now=r;
        k.k_checked=true;
        this->white_k.removeAt(this->white_k.indexOf(k));
        k.row_k_now=r1;
        k.column_k_now=c1;
        k.k_checked=true;
        this->white_k.push_back(k);
    }
    else if(index==black_queen)
    {
        queen q;
        q.column_q_now=c;
        q.row_q_now=r;
        q.q_checked=false;
        this->black_q.removeAt(this->black_q.indexOf(q));
        q.row_q_now=r1;
        q.column_q_now=c1;
        q.q_checked=false;
        this->black_q.push_back(q);
    }
    else if(index==white_queen)
    {
        queen q;
        q.column_q_now=c;
        q.row_q_now=r;
        q.q_checked=true;
        this->white_q.removeAt(this->white_q.indexOf(q));
        q.row_q_now=r1;
        q.column_q_now=c1;
        q.q_checked=true;
        this->white_q.push_back(q);
    }
    else if(index==black_rook)
    {
        rook r2;
        r2.column_r_now=c;
        r2.row_r_now=r;
        r2.r_checked=false;
        this->black_r.removeAt(this->black_r.indexOf(r2));
        r2.column_r_now=c1;
        r2.row_r_now=r1;
        r2.r_checked=false;
        this->black_r.push_back(r2);
    }
    else if(index==white_rook)
    {
        rook r2;
        r2.column_r_now=c;
        r2.row_r_now=r;
        r2.r_checked=true;
        this->white_r.removeAt(this->white_r.indexOf(r2));
        r2.column_r_now=c1;
        r2.row_r_now=r1;
        r2.r_checked=true;
        this->white_r.push_back(r2);
    }
    else if(index==black_pawn)
    {
        pawn p;
        p.column_p_now=c;
        p.row_p_now=r;
        p.p_checked=false;
        this->black_p.removeAt(this->black_p.indexOf(p));
        pawn p2;
        p2.row_p_now=r1;
        p2.column_p_now=c1;
        p2.p_checked=false;
        this->black_p.push_back(p2);
    }
    else if(index==white_pawn)
    {
        pawn p;
        p.column_p_now=c;
        p.row_p_now=r;
        p.p_checked=true;
        this->white_p.removeAt(this->white_p.indexOf(p));
        pawn p2;
        p2.row_p_now=r1;
        p2.column_p_now=c1;
        p2.p_checked=true;
        this->white_p.push_back(p2);
    }
    else if(index==black_king)
    {
        king kg;
        kg.column_kg_now=c;
        kg.row_kg_now=r;
        kg.kg_checked=false;
        this->black_kg.removeAt(this->black_kg.indexOf(kg));
        kg.column_kg_now=c1;
        kg.row_kg_now=r1;
        kg.kg_checked=false;
        this->black_kg.push_back(kg);
    }
    else if(index==white_king)
    {
        king kg;
        kg.column_kg_now=c;
        kg.row_kg_now=r;
        kg.kg_checked=true;
        this->white_kg.removeAt(this->white_kg.indexOf(kg));
        kg.column_kg_now=c1;
        kg.row_kg_now=r1;
        kg.kg_checked=true;
        this->white_kg.push_back(kg);
    }

}

void infobase::delete_a_piece(int r, int c)
{
    nameOfItem index=this->find(r,c);
    if(index==black_bishop)
    {
        bishop b;
        b.row_b_now=r;
        b.column_b_now=c;
        save s;
        int ii=qs.count();
        s=*(qs.end());
        qs.pop_back();
        s.deleted_item=3;
        s.deleted_item_c=c;
        s.deleted_item_r=r;
        qs.push_back(s);
        int i=this->black_b.indexOf(b);
        if(i!=-1)
            this->black_b.removeAt(i);
    }
    else if(index==white_bishop)
    {
        bishop b;
        b.row_b_now=r;
        b.column_b_now=c;
        save s;
        int ii=qs.count();
        s=*(qs.end());
        qs.pop_back();
        s.deleted_item=9;
        s.deleted_item_c=c;
        s.deleted_item_r=r;
        qs.push_back(s);
        int i=this->white_b.indexOf(b);
        if(i!=-1)
            this->white_b.removeAt(i);
    }
    else if(index==black_knight)
    {
        knight k;
        k.row_k_now=r;
        k.column_k_now=c;
        save s;
        int ii=qs.count();
        s=*(qs.end());
        qs.pop_back();
        s.deleted_item=4;
        s.deleted_item_c=c;
        s.deleted_item_r=r;
        qs.push_back(s);
        int i=this->black_k.indexOf(k);
        if(i!=-1)
            this->black_k.removeAt(i);
    }
    else if(index==white_knight)
    {
        knight k;
        k.row_k_now=r;
        k.column_k_now=c;
        save s;
        int ii=qs.count();
        s=*(qs.end());
        qs.pop_back();
        s.deleted_item=10;
        s.deleted_item_c=c;
        s.deleted_item_r=r;
        qs.push_back(s);
        int i=this->white_k.indexOf(k);
        if(i!=-1)
            this->white_k.removeAt(i);
    }
    else if(index==black_pawn)
    {
        pawn p;
        p.column_p_now=c;
        p.row_p_now=r;
        save s;
        int ii=qs.count();
        s=*(qs.end());
        qs.pop_back();
        s.deleted_item=1;
        s.deleted_item_r=r;
        s.deleted_item_c=c;
        qs.push_back(s);
        int i=this->black_p.indexOf(p);
        if(i!=-1)
            this->black_p.removeAt(i);
    }
    else if(index==white_pawn)
    {
        pawn p;
        p.column_p_now=c;
        p.row_p_now=r;
        save s;
        int ii=qs.count();
        s=*(qs.end());
        qs.pop_back();
        s.deleted_item=7;
        s.deleted_item_r=r;
        s.deleted_item_c=c;
        qs.push_back(s);
        int i=this->white_p.indexOf(p);
        if(i!=-1)
            this->white_p.removeAt(i);

    }
    else if(index==black_queen)
    {
        queen q;
        q.column_q_now=c;
        q.row_q_now=r;
        save s;
        int ii=qs.count();
        s=*(qs.end());
        qs.pop_back();
        s.deleted_item=5;
        s.deleted_item_c=c;
        s.deleted_item_r=r;
        qs.push_back(s);
        int i=this->black_q.indexOf(q);
        if(i!=-1)
            this->black_q.removeAt(i);
    }
    else if(index==white_queen)
    {
        queen q;
        q.column_q_now=c;
        q.row_q_now=r;
        save s;
        int ii=qs.count();
        s=*(qs.end());
        qs.pop_back();
        s.deleted_item=11;
        s.deleted_item_c=c;
        s.deleted_item_r=r;
        qs.push_back(s);
        int i=this->white_q.indexOf(q);
        if(i!=-1)
            this->white_q.removeAt(i);
    }
    else if(index==black_rook)
    {
        rook r1;
        r1.column_r_now=c;
        r1.row_r_now=r;
        save s;
        int ii=qs.count();
        s=*(qs.end());
        qs.pop_back();
        s.deleted_item=6;
        s.deleted_item_c=c;
        s.deleted_item_r=r;
        qs.push_back(s);
        int i=this->black_r.indexOf(r1);
        if(i!=-1)
            this->black_r.removeAt(i);
    }
    else if(index==white_rook)
    {
        rook r1;
        r1.column_r_now=c;
        r1.row_r_now=r;
        save s;

        int ii=qs.count();
        s=*(qs.end());
        qs.pop_back();
        s.deleted_item=12;
        s.deleted_item_c=c;
        s.deleted_item_r=r;
        qs.push_back(s);
        int i=this->white_r.indexOf(r1);
        if(i!=-1)
            this->white_r.removeAt(i);
    }

}

int infobase::search_in_list(int r, int c, int r1, int c1)
{
    nameOfItem index= find(r,c);

    if(index==black_bishop)
    {
        bishop b;
        b.column_b_now=c;
        b.row_b_now=r;
        int i=this->black_b.indexOf(b);
        if(i!=-1)
        {
            if(this->black_b.at(i).list_b.empty()) return -1;
            if(this->black_b.at(i).list_b.find(r1*10+c1)==this->black_b.at(i).list_b.end())
                return 0;
        else return 1;
        }

    }

    if(index==white_bishop)
    {
        bishop b;
        b.column_b_now=c;
        b.row_b_now=r;
        int i=this->white_b.indexOf(b);
        if(i!=-1)
        {

        if(this->white_b.at(i).list_b.empty()) return -1;
        if(this->white_b.at(i).list_b.find(r1*10+c1)==this->white_b.at(i).list_b.end())
            return 0;
        else return 1;
        }

    }

    if(index==black_pawn)
    {
        pawn p;
        p.column_p_now=c;
        p.row_p_now=r;
        int i=this->black_p.indexOf(p);
        if(i!=-1)
        {
        if(this->black_p.at(i).list_p.empty()) return -1;
        if(this->black_p.at(i).list_p.find(r1*10+c1)==this->black_p.at(i).list_p.end())
            return 0;
        return 1;
        }

    }

    if(index==white_pawn)
    {
        pawn p;
        p.column_p_now=c;
        p.row_p_now=r;
        int i=this->white_p.indexOf(p);
        if(i!=-1)
        {
        if(this->white_p.at(i).list_p.empty()) return -1;
        if(this->white_p.at(i).list_p.find(r1*10+c1)==this->white_p.at(i).list_p.end())
            return 0;
        return 1;
        }
    }

    if(index==black_knight)
    {
        knight k;
        k.column_k_now=c;
        k.row_k_now=r;
        int i=this->black_k.indexOf(k);
        if(i!=-1)
        {
        if(this->black_k.at(i).list_k.empty()) return -1;
        if(this->black_k.at(i).list_k.find(r1*10+c1)==this->black_k.at(i).list_k.end())
            return 0;
        return 1;
        }
    }

    if(index==white_knight)
    {
        knight k;
        k.column_k_now=c;
        k.row_k_now=r;
        int i= this->white_k.indexOf(k);
        if(i!=-1)
        {
        if(this->white_k.at(i).list_k.empty())return -1;
        if(this->white_k.at(i).list_k.find(r1*10+c1)==this->white_k.at(i).list_k.end())
            return 0;
        return 1;
        }
    }

    if(index==black_queen)
    {
        queen q;
        q.column_q_now=c;
        q.row_q_now=r;
        int i=this->black_q.indexOf(q);
        if(i!=-1)
        {
        if(this->black_q.at(i).list_q.empty())return -1;
        if(this->black_q.at(i).list_q.find(r1*10+c1)==this->black_q.at(i).list_q.end())
            return 0;
        return 1;
        }
    }

    if(index==white_queen)
    {
        queen q;
        q.column_q_now=c;
        q.row_q_now=r;
        int i = this->white_q.indexOf(q);
        if(i!=-1)
        {

        if(this->white_q.at(i).list_q.empty())return -1;
        if(this->white_q.at(i).list_q.find(r1*10+c1)==this->white_q.at(i).list_q.end())
            return 0;
        return 1;
        }
    }

    if(index==black_rook)
    {
        rook ro;
        ro.column_r_now=c;
        ro.row_r_now=r;
        int i=this->black_r.indexOf(ro);
        if(i!=-1)
        {
        if(this->black_r.at(i).list_r.empty())return -1;
        if(this->black_r.at(i).list_r.find(r1*10+c1)==this->black_r.at(i).list_r.end())
            return 0;
        return 1;
        }
    }

    if(index==white_rook)
    {
        rook ro;
        ro.column_r_now=c;
        ro.row_r_now=r;
        int i= this->white_r.indexOf(ro);
        if(i!=-1)
        {
        if(this->white_r.at(i).list_r.empty())return -1;
        if(this->white_r.at(i).list_r.find(r1*10+c1)==this->white_r.at(i).list_r.end())
            return 0;
        return 1;
        }
    }

    if(index==white_king)
    {
        king kg;
        kg.column_kg_now=c;
        kg.row_kg_now=r;
        int i=this->white_kg.indexOf(kg);
        if(i!=-1)
        {
        if(this->white_kg.at(i).list_kg.empty())return -1;
        if(this->white_kg.at(i).list_kg.find(r1*10+c1)==this->white_kg.at(i).list_kg.end())
            return 0;
        return 1;
        }
    }

    if(index==black_king)
    {
        king kg;
        kg.column_kg_now=c;
        kg.row_kg_now=r;
        int i=this->black_kg.indexOf(kg);
        if(i!=-1)
        {
        if(this->black_kg.at(i).list_kg.empty())return -1;
        if(this->black_kg.at(i).list_kg.find(r1*10+c1)==this->black_kg.at(i).list_kg.end())
            return 0;
        return 1;
        }
    }
    return 0;
}

QIcon infobase::get_icon(int r, int c)
{
    QIcon icon;
    nameOfItem index=this->find(r,c);
    if(index==1)
       icon.addFile(":/chess_icon/ches_icons/icons8-pawn-filled-50.png");
    else if(index==2)
        icon.addFile(":/chess_icon/ches_icons/icons8-king-filled-50.png");
    else if(index==3)
        icon.addFile(":/chess_icon/ches_icons/icons8-bishop-filled-50.png");
    else if(index==4)
        icon.addFile(":/chess_icon/ches_icons/icons8-knight-filled-50.png");
    else if(index==5)
        icon.addFile(":/chess_icon/ches_icons/icons8-queen-filled-50.png");
    else if(index==6)
        icon.addFile(":/chess_icon/ches_icons/icons8-rook-filled-50.png");
    else if(index==7)
        icon.addFile(":/chess_icon/ches_icons/icons8-pawn-50.png");
    else if(index==8)
        icon.addFile(":/chess_icon/ches_icons/icons8-king-50.png");
    else if(index==9)
        icon.addFile(":/chess_icon/ches_icons/icons8-bishop-50.png");
    else if(index==10)
        icon.addFile(":/chess_icon/ches_icons/icons8-knight-50.png");
    else if(index==11)
        icon.addFile(":/chess_icon/ches_icons/icons8-queen-50.png");
    else if(index==12)
        icon.addFile(":/chess_icon/ches_icons/icons8-rook-50.png");
    return icon;


}

bool infobase::threat_king(int bOrW)
{
    //black pieces &  threat white king
    if(bOrW==0)
    {
    for(pawn p: this->black_p)
    {
        this->edit_list_to_go(p.row_p_now,p.column_p_now);
        if(p.threat_king==true)
            return true;
    }

    for(bishop b: this->black_b)
    {
        this->edit_list_to_go(b.row_b_now,b.column_b_now);
        if(b.threat_king==true)
            return true;

    }

    for(king kg: this->black_kg)
    {
        this->edit_list_to_go(kg.row_kg_now,kg.column_kg_now);
        if(kg.threat_king==true)
            return true;
    }

    for(knight k: this->black_k)
    {
        this->edit_list_to_go(k.row_k_now,k.column_k_now);
        if(k.threat_king==true)
            return true;
    }

    for(queen q: this->black_q)
    {
        this->edit_list_to_go(q.row_q_now,q.column_q_now);
        if(q.threat_king==true)
            return true;
    }

    for(rook r: this->black_r)
    {
        this->edit_list_to_go(r.row_r_now,r.column_r_now);
        if(r.threat_king==true)
            return true;
    }
    }
    else if(bOrW==1)
    {
        //white pieces &  threat black king
    for(pawn p: this->white_p)
    {
        this->edit_list_to_go(p.row_p_now,p.column_p_now);
        if(p.threat_king==true)
            return true;
    }

    for(bishop b: this->white_b)
    {
        this->edit_list_to_go(b.row_b_now,b.column_b_now);
        if(b.threat_king==true)
            return true;
    }

    for(king kg: this->white_kg)
    {
        this->edit_list_to_go(kg.row_kg_now,kg.column_kg_now);
        if(kg.threat_king==true)
            return true;
    }

    for(knight k: this->white_k)
    {
        this->edit_list_to_go(k.row_k_now,k.column_k_now);
        if(k.threat_king==true)
            return true;
    }

    for(queen q: this->white_q)
    {
        this->edit_list_to_go(q.row_q_now,q.column_q_now);
        if(q.threat_king==true)
            return true;
    }

    for(rook r: this->white_r)
    {
        if(r.threat_king==true)
        {
            this->edit_list_to_go(r.row_r_now,r.column_r_now);
            if(r.threat_king==true)
                return true;
        }
   }
    }
    return false;
}


bool infobase::vindicative(int bOrW, int i, int j)
{
    // mohreie peyda mishe ke rah tahdid konandeh ro sad koneh?
    if(bOrW==0)//white king
    {
        king kg= *(this->white_kg.begin());
        nameOfItem index=this->find(i,j);
        if(index!= black_knight && index!= black_pawn)
        {
            int r=kg.row_kg_now,c=kg.column_kg_now;
            if(i==r && j<c&& j-1!=c)
            {
                for(int k=c-1;k>=j+1;k--)
                {

                    for(bishop b: this->white_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,i,k))
                            return true;

                    }


                    for(queen q: this->white_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,i,k))
                            return true;
                    }

                    for(rook ro: this->white_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,i,k))
                            return true;
                    }
                }
            }

            else if(i==r && j>c && j+1!=c)
            {
                for(int k=c+1;k<=j;k++)
                {

                    for(bishop b: this->white_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,i,k))
                            return true;

                    }


                    for(queen q: this->white_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,i,k))
                            return true;
                    }

                    for(rook ro: this->white_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,i,k))
                            return true;
                    }
                }
            }

            else if(j==c && i<r && i-1!=r)
            {
                for(int k=r-1;k>=i+1;k--)
                {

                    for(bishop b: this->white_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,k,j))
                            return true;

                    }


                    for(queen q: this->white_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,k,j))
                            return true;
                    }

                    for(rook ro: this->white_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,k,j))
                            return true;
                    }
                }
            }
            else if(j==c && i>r && i+1!=r)
            {
                for(int k=r+1;k<=i-1;k--)
                {

                    for(bishop b: this->white_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,k,j))
                            return true;

                    }


                    for(queen q: this->white_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,k,j))
                            return true;
                    }

                    for(rook ro: this->white_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,k,j))
                            return true;
                    }

                }
            }
            else if(i<r && j>c && i-1!=r && j+1!=c)
                {
                    for(int k=1;k<=j-c-1;k++)
                    {

                        for(bishop b: this->white_b)
                        {
                            this->edit_list_to_go(b.row_b_now,b.column_b_now);
                            if(this->search_in_list(b.row_b_now,b.column_b_now,r-k,c+k))
                                return true;

                        }


                        for(queen q: this->white_q)
                        {
                            this->edit_list_to_go(q.row_q_now,q.column_q_now);
                            if(this->search_in_list(q.row_q_now,q.column_q_now,r-k,c+k))
                                return true;
                        }

                        for(rook ro: this->white_r)
                        {
                            this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                            if(this->search_in_list(ro.row_r_now,ro.column_r_now,r-k,c+k))
                                return true;
                        }
                    }
                }
            else if(i<r && j<c && i-1!=r && j-1!=c)
            {
                for(int k=1;k<=c-j-1;k++)
                {

                    for(bishop b: this->white_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,r-k,c-k))
                            return true;

                    }


                    for(queen q: this->white_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,r-k,c-k))
                            return true;
                    }

                    for(rook ro: this->white_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,r-k,c-k))
                            return true;
                    }
                }
            }
            else if(i>r && j<c &&  i+1!=r && j-1!=c)
            {
                for(int k=1;k<=c-j-1;k++)
                {

                    for(bishop b: this->white_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,r+k,c-k))
                            return true;

                    }


                    for(queen q: this->white_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,r+k,c-k))
                            return true;
                    }

                    for(rook ro: this->white_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,r+k,c-k))
                            return true;
                    }
                }
            }
            else if(i>r && j>c && i+1!=r && j+1!=c)
            {
                for(int k=1;k<=j-c-1;k++)
                {

                    for(bishop b: this->white_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,r+k,c+k))
                            return true;

                    }


                    for(queen q: this->white_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,r+k,c+k))
                            return true;
                    }

                    for(rook ro: this->white_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,r+k,c+k))
                            return true;
                    }
                }
            }

        }
        else return false;
    }
    else if(bOrW==1)//black king
    {
        king kg= *(this->black_kg.begin());
        nameOfItem index=this->find(i,j);
        if(index!= white_knight && index!= white_pawn && index!=white_king)
        {
            int r=kg.row_kg_now,c=kg.column_kg_now;
            if(i==r && j<c&& j-1!=c)
            {
                for(int k=c-1;k>=j+1;k--)
                {

                    for(bishop b: this->black_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,i,k))
                            return true;

                    }


                    for(queen q: this->black_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,i,k))
                            return true;
                    }

                    for(rook ro: this->black_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,i,k))
                            return true;
                    }
                }
            }

            else if(i==r && j>c && j+1!=c)
            {
                for(int k=c+1;k<=j;k++)
                {

                    for(bishop b: this->black_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,i,k))
                            return true;

                    }


                    for(queen q: this->black_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,i,k))
                            return true;
                    }

                    for(rook ro: this->black_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,i,k))
                            return true;
                    }
                }
            }

            else if(j==c && i<r && i-1!=r)
            {
                for(int k=r-1;k>=i+1;k--)
                {

                    for(bishop b: this->black_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,k,j))
                            return true;

                    }


                    for(queen q: this->black_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,k,j))
                            return true;
                    }

                    for(rook ro: this->black_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,k,j))
                            return true;
                    }
                }
            }
            else if(j==c && i>r && i+1!=r)
            {
                for(int k=r+1;k<=i-1;k--)
                {

                    for(bishop b: this->black_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,k,j))
                            return true;

                    }


                    for(queen q: this->black_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,k,j))
                            return true;
                    }

                    for(rook ro: this->black_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,k,j))
                            return true;
                    }

                }
            }
            else if(i<r && j>c && i-1!=r && j+1!=c)
                {
                    for(int k=1;k<=j-c-1;k++)
                    {

                        for(bishop b: this->black_b)
                        {
                            this->edit_list_to_go(b.row_b_now,b.column_b_now);
                            if(this->search_in_list(b.row_b_now,b.column_b_now,r-k,c+k))
                                return true;

                        }


                        for(queen q: this->black_q)
                        {
                            this->edit_list_to_go(q.row_q_now,q.column_q_now);
                            if(this->search_in_list(q.row_q_now,q.column_q_now,r-k,c+k))
                                return true;
                        }

                        for(rook ro: this->black_r)
                        {
                            this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                            if(this->search_in_list(ro.row_r_now,ro.column_r_now,r-k,c+k))
                                return true;
                        }
                    }
                }
            else if(i<r && j<c && i-1!=r && j-1!=c)
            {
                for(int k=1;k<=c-j-1;k++)
                {

                    for(bishop b: this->black_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,r-k,c-k))
                            return true;

                    }


                    for(queen q: this->black_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,r-k,c-k))
                            return true;
                    }

                    for(rook ro: this->black_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,r-k,c-k))
                            return true;
                    }
                }
            }
            else if(i>r && j<c &&  i+1!=r && j-1!=c)
            {
                for(int k=1;k<=c-j-1;k++)
                {

                    for(bishop b: this->black_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,r+k,c-k))
                            return true;

                    }


                    for(queen q: this->black_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,r+k,c-k))
                            return true;
                    }

                    for(rook ro: this->black_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,r+k,c-k))
                            return true;
                    }
                }
            }
            else if(i>r && j>c && i+1!=r && j+1!=c)
            {
                for(int k=1;k<=j-c-1;k++)
                {

                    for(bishop b: this->black_b)
                    {
                        this->edit_list_to_go(b.row_b_now,b.column_b_now);
                        if(this->search_in_list(b.row_b_now,b.column_b_now,r+k,c+k))
                            return true;

                    }


                    for(queen q: this->black_q)
                    {
                        this->edit_list_to_go(q.row_q_now,q.column_q_now);
                        if(this->search_in_list(q.row_q_now,q.column_q_now,r+k,c+k))
                            return true;
                    }

                    for(rook ro: this->black_r)
                    {
                        this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
                        if(this->search_in_list(ro.row_r_now,ro.column_r_now,r+k,c+k))
                            return true;
                    }
                }
            }

        }
        else return false;
    }
    return false;

}
bool infobase::delete_threat_king(int r, int c, string bOrW)
{
    //mohreh e mituneh tahdid konandeh ro bezaneh?
    //bOrW: rang tahdid konandeh
    if(bOrW=="b")
    {
      for(bishop b: this->white_b)
          if(b.list_b.find(r*10+c)!= b.list_b.end())
              return true;
      for(pawn p: this->white_p)
          if(p.list_p.find(r*10+c)!= p.list_p.end())
              return true;
      for(knight k:this->white_k)
          if(k.list_k.find(r*10+c)!=k.list_k.end())
              return true;
      for(queen q :this->white_q)
          if(q.list_q.find(r*10+c)!=q.list_q.end())
              return true;
      for(rook ro:this->white_r)
          if(ro.list_r.find(r*10+c)!=ro.list_r.end())
              return true;
    }
    else if(bOrW=="w")
    {
        for(bishop b: this->black_b)
            if(b.list_b.find(r*10+c)!= b.list_b.end())
                return true;
        for(pawn p: this->black_p)
            if(p.list_p.find(r*10+c)!= p.list_p.end())
                return true;
        for(knight k:this->black_k)
            if(k.list_k.find(r*10+c)!=k.list_k.end())
                return true;
        for(queen q :this->black_q)
            if(q.list_q.find(r*10+c)!=q.list_q.end())
                return true;
        for(rook ro:this->black_r)
            if(ro.list_r.find(r*10+c)!=ro.list_r.end())
                return true;
    }
    return false;
}



bool infobase::win(int bOrW)
{

    //black pieces &  threat white king
    if(bOrW==0)
    {
    for(pawn p: this->black_p)
    {
        if(p.threat_king==true)
        {
            for(king kg:this->white_kg)
                if(kg.list_kg.empty()&& !(this->delete_threat_king(p.row_p_now,p.column_p_now,"b")) && !(this->vindicative(0, p.row_p_now, p.column_p_now)))
                    return true;
        }
    }

    for(bishop b: this->black_b)
    {
        if(b.threat_king==true)
        {
            for(king kg:this->white_kg)
                if(kg.list_kg.empty()&& !(this->delete_threat_king(b.row_b_now,b.column_b_now,"b")) && !(this->vindicative(0, b.row_b_now, b.column_b_now)))
                    return true;
        }
    }

    for(king kg: this->black_kg)
    {
        if(kg.threat_king==true)
        {
            for(king kg:this->white_kg)
                if(kg.list_kg.empty()&& !(this->delete_threat_king(kg.row_kg_now,kg.column_kg_now,"b")) && !(this->vindicative(0, kg.row_kg_now, kg.column_kg_now)))
                    return true;
        }
    }

    for(knight k: this->black_k)
    {
        if(k.threat_king==true)
        {
            for(king kg:this->white_kg)
                if(kg.list_kg.empty()&&!(this->delete_threat_king(k.row_k_now,k.column_k_now,"b")) && !(this->vindicative(0, k.row_k_now, k.column_k_now)))
                    return true;
        }
    }

    for(queen q: this->black_q)
    {
        if(q.threat_king==true)
        {
            for(king kg:this->white_kg)
                if(kg.list_kg.empty()&& !(this->delete_threat_king(q.row_q_now,q.column_q_now,"b"))&& !(this->vindicative(0, q.row_q_now, q.column_q_now)))
                    return true;
        }
    }

    for(rook r: this->black_r)
    {
        if(r.threat_king==true)
        {
            for(king kg:this->white_kg)
                if(kg.list_kg.empty()&& !(this->delete_threat_king(r.row_r_now,r.column_r_now,"b"))&& !(this->vindicative(0, r.row_r_now, r.column_r_now)))
                    return true;
        }
    }
    }


        //white pieces &  threat black king
    else if(bOrW==1)
    {
    for(pawn p: this->white_p)
    {
        if(p.threat_king==true)
        {
            for(king kg:this->black_kg)
                if(kg.list_kg.empty()&& !(this->delete_threat_king(p.row_p_now,p.column_p_now,"w"))&& !(this->vindicative(1, p.row_p_now, p.column_p_now)))
                    return true;
        }
    }

    for(bishop b: this->white_b)
    {
        if(b.threat_king==true)
        {
            for(king kg:this->black_kg)
                if(kg.list_kg.empty()&&!(this->delete_threat_king(b.row_b_now,b.column_b_now,"w"))&& !(this->vindicative(1, b.row_b_now, b.column_b_now)))
                    return true;
        }
    }

    for(king kg: this->white_kg)
    {
        if(kg.threat_king==true)
        {
            for(king kg:this->black_kg)
                if(kg.list_kg.empty()&& !(this->delete_threat_king(kg.row_kg_now,kg.column_kg_now,"w"))&& !(this->vindicative(1, kg.row_kg_now, kg.column_kg_now)))
                    return true;
        }
    }

    for(knight k: this->white_k)
    {
        if(k.threat_king==true)
        {
            for(king kg:this->black_kg)
                if(kg.list_kg.empty()&&!(this->delete_threat_king(k.row_k_now,k.column_k_now,"w"))&& !(this->vindicative(1, k.row_k_now, k.column_k_now)))
                    return true;
        }
    }

    for(queen q: this->white_q)
    {
        if(q.threat_king==true)
        {
            for(king kg:this->black_kg)
                if(kg.list_kg.empty()&&!(this->delete_threat_king(q.row_q_now,q.column_q_now,"w"))&& !(this->vindicative(1, q.row_q_now, q.column_q_now)))
                    return true;
        }
    }

    for(rook r: this->white_r)
    {
        if(r.threat_king==true)
        {
            for(king kg:this->black_kg)
                if(kg.list_kg.empty()&&!(this->delete_threat_king(r.row_r_now,r.column_r_now,"w"))&& !(this->vindicative(1, r.row_r_now, r.column_r_now)))
                    return true;
        }
   }
}

    return false;




}



