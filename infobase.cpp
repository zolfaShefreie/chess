#include "infobase.h"

infobase::infobase()
{

    // the position of pieces at the beginning of the game
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
    //to find pieces ,using their position
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
    for(bishop b1:this->white_b)
        if(b1==b)
            return white_bishop;
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
    // number of which_item like nameOfItem
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
    nameOfItem ind=find(r,c);
    nameOfItem index;
    //    if(ind==white_king)
    //{
        this->threat_kg_b=false;
        king kg;
        kg.kg_checked=true;
        kg.column_kg_now=this->white_kg.at(0).column_kg_now;
        kg.row_kg_now=this->white_kg.at(0).row_kg_now;
        this->white_kg.removeAt(0);
        kg.go_to();
        int cc,rr;
        for(int i=0;i<kg.list_kg.count();i++)
        {
            int s=kg.list_kg.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index>6&&index!=13)
            {
                if(rr-1==kg.row_kg_now)
                    kg.list_kg.removeAt(i);
                else if(rr+1==kg.row_kg_now)
                   kg.list_kg.removeAt(i);
                else if(cc-1==kg.column_kg_now)
                    kg.list_kg.removeAt(i);
                else if(cc+1==kg.column_kg_now)
                    kg.list_kg.removeAt(i);
            }
            if(kg.list_kg.empty())
                break;
        }
        for(int i=0;i<kg.list_kg.count();i++)
        {
            int s=kg.list_kg.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index==2)
            {
                this->threat_kg_b=true;
                this->threat_kg_w=true;
                kg.list_kg.removeAt(i);
            }
        }
        this->white_kg.push_back(kg);


  //}

   // if(ind==black_king)
    //{
        this->threat_kg_w=false;
        king kg1;
        kg1.kg_checked=false;
        kg1.column_kg_now=this->black_kg.at(0).column_kg_now;
        kg1.row_kg_now=this->black_kg.at(0).row_kg_now;
        int it1=this->black_kg.indexOf(kg1);
        if(it1!=-1)
        {
        this->black_kg.removeAt(0);
        kg1.go_to();
        int cc1,rr1;
        for(int i=0;i<kg1.list_kg.count();i++)
        {
            int s=kg1.list_kg.at(i);
            cc1=s%10;
            rr1=(s-cc1)/10;
            index=this->find(rr1,cc1);
            if(index<7)
            {
                if(rr1-1==kg1.row_kg_now)
                    kg1.list_kg.removeAt(i);
                else if(rr1+1==kg1.row_kg_now)
                    kg1.list_kg.removeAt(i);
                else if(cc1-1==kg1.column_kg_now)
                    kg1.list_kg.removeAt(i);
                else if(cc1+1==kg1.column_kg_now)
                    kg1.list_kg.removeAt(i);
            }
//            else if(index==8)
//            {
//                this->threat_kg_b=true;
//                this->threat_kg_w=true;
//                kg1.list_kg.erase(s);
//            }
            if(kg1.list_kg.empty())
                break;
        }
        for(int i=0;i<kg1.list_kg.count();i++)
        {
            int s=kg1.list_kg.at(i);
            cc1=s%10;
            rr1=(s-cc1)/10;
            index=this->find(rr1,cc1);
            if(index==8)
            {
                this->threat_kg_b=true;
                this->threat_kg_w=true;
                kg1.list_kg.removeAt(i);
            }
        }
        this->black_kg.push_back(kg1);
        }
    //}


    if(ind==black_bishop)
    {   
        this->threat_kg_w=false;
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
        for(int i=0;i<b.list_b.count();i++)
        {
            int s=b.list_b.at(i);
           cc=s%10;
           rr=(s-cc)/10;
           index=this->find(rr,cc);
           if(index<7)
           {
               //remove position of pieces with the same color from possible positions
               b.list_b.removeAt(i);
               //not to jump over pieces with the same color
               int f=b.list_b.count();
               b.remove_some_mem(cc,rr);
               if(i!=b.list_b.count()-1&&f!=b.list_b.count())
                   i-=1;
           }
           else if(index!=none_of_them)
           {
               //not to jump over pieces with different color
               int f=b.list_b.count();
               b.remove_some_mem(cc,rr);
               if(i!=b.list_b.count()-1&&f!=b.list_b.count())
                   i-=1;
           }
           if(b.list_b.empty())
               break;
        }
        for(int i=0;i<b.list_b.count();i++)
        {
            int s=b.list_b.at(i);
           cc=s%10;
           rr=(s-cc)/10;
           index=this->find(rr,cc);
           if(index==8)
           {
               //remove the position of the other player's king from possible positions
               b.threat_king=true;
               this->threat_kg_w=true;
               for(king kingw:this->white_kg)
                   kingw.edit_list(r,c);
               b.list_b.removeAt(i);
           }
        }
        this->black_b.insert(it,b);
    }
    }

    if(ind==white_bishop)
    {
        this->threat_kg_b=false;
        bishop b;
        b.b_checked=true;
        b.column_b_now=c;
        b.row_b_now=r;
        int it=this->white_b.indexOf(b);
        if (it!= -1)
        {
        this->white_b.removeAt(it);
        b.go_to();
        int cc,rr;
        for(int i=0;i<b.list_b.count();i++)
        {
            int s=b.list_b.at(i);
           cc=s%10;
           rr=(s-cc)/10;
           index=this->find(rr,cc);
           if(index>6&&index!=13)
           {
               //remove position of pieces with the same color from possible positions
               b.list_b.removeAt(i);
               //not to jump over pieces with the same color
               int f=b.list_b.count();
               b.remove_some_mem(cc,rr);
               if(i!=b.list_b.count()-1&&f!=b.list_b.count())
                   i-=1;
           }
           else if(index!=none_of_them)
           {
               //not to jump over pieces with different color
               int f=b.list_b.count();
               b.remove_some_mem(cc,rr);
               if(i!=b.list_b.count()-1&&f!=b.list_b.count())
                   i-=1;
           }
           if(b.list_b.empty())
               break;
        }
        for(int i=0;i<b.list_b.count();i++)
        {
            int s=b.list_b.at(i);
           cc=s%10;
           rr=(s-cc)/10;
           index=this->find(rr,cc);
           if(index==2)
           {
               //remove the position of the other player's king from possible positions
               b.threat_king=true;
               this->threat_kg_b=true;
               for(king kingw:this->black_kg)
                   kingw.edit_list(r,c);
               b.list_b.removeAt(i);
           }
        }
        this->white_b.insert(it,b);
    }
    }

    if(ind==black_pawn)
    {
        this->threat_kg_w=false;
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
        for(auto itr=p.list_p.begin();itr!=p.list_p.end();itr++)
        {
            int s=*(itr);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index!=none_of_them)
            {
//                    if(rr-2==p.row_p_now)
//                        p.list_p.erase(s);
                    if(rr==p.row_p_now-1)
                    {
                        p.list_p.erase(s);
                    }

            }

           if(p.list_p.empty())
               break;
        }
                        //taking the other player's pieces
        index=this->find(p.row_p_now-1,p.column_p_now-1);
        if(index!= white_king && index>6&&index!=13)
            p.list_p.insert(((p.row_p_now-1)*10+(p.column_p_now-1)));
        else if(index==white_king)
        {
            this->threat_kg_w=true;
            p.threat_king=true;
            for(king kin:this->white_kg)
                kin.edit_list(r,c);
        }
        index=this->find(p.row_p_now-1,p.column_p_now+1);
        if(index!= white_king && index>6&&index!=13)
            p.list_p.insert(((p.row_p_now-1)*10+(p.column_p_now+1)));
        else if(index==white_king)
        {
            this->threat_kg_w=true;
            p.threat_king=true;
            for(king kin:this->white_kg)
                kin.edit_list(r,c);
        }
        this->black_p.insert(it,p);
        }

    }

    if(ind==white_pawn)
    {
        this->threat_kg_b=false;
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
        for(auto itr=p.list_p.begin();itr!=p.list_p.end();itr++)
        {
            int s=*(itr);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index!=none_of_them)
            {
//                    if(rr+2==p.row_p_now)
//                        p.list_p.erase(s);
                    if(rr==p.row_p_now+1)
                    {
                        p.list_p.erase(s);
                    }

            }
            if(p.list_p.empty()||s==*(p.list_p.end()))
                break;

        }
                        //taking the other player's pieces
        index=this->find(p.row_p_now+1,p.column_p_now+1);
        if(index!= black_king && index<7)
            p.list_p.insert(((p.row_p_now+1)*10+(p.column_p_now+1)));
        else if(index==black_king)
        {
            this->threat_kg_b=true;
            p.threat_king=true;
            for(king kingw:this->black_kg)
                kingw.edit_list(r,c);
        }
        index=this->find(p.row_p_now+1,p.column_p_now-1);
        if(index!= black_king && index<7)
            p.list_p.insert(((p.row_p_now+1)*10+(p.column_p_now-1)));
        else if(index==black_king)
        {
            this->threat_kg_b=true;
            p.threat_king=true;
            for(king kingw:this->black_kg)
                kingw.edit_list(r,c);
        }
        this->white_p.insert(it,p);
        }
    }

    if(ind==black_knight)
    {
        this->threat_kg_w=false;
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
        for(int i=0;i<k.list_k.count();i++)
        {
            int s=k.list_k.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index<7)
            {
                //not to take pieces with the same color
                k.list_k.removeAt(i);
                i-=1;
            }
            else if(index==8)
            {
                //not to take the other player's king
                this->threat_kg_w=true;
                k.threat_king=true;
                for(king ki:this->white_kg)
                    ki.edit_list(r,c);
                k.list_k.removeAt(i);
                i-=1;
            }
            if(k.list_k.empty())
                break;
        }
        this->black_k.insert(it,k);

        }

    }

    if(ind==white_knight)
    {
        this->threat_kg_b=false;
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
        for(int i=0;i<k.list_k.count();i++)
        {
            int s=k.list_k.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index>6&&index!=13)
            {
                //ham rang ro natuneh bezaneh
                k.list_k.removeAt(i);
                i-=1;
            }
            else if(index==2)
            {
                //shah harif ro natuneh bezaneh
                this->threat_kg_b=true;
                k.threat_king=true;
                for(king ki:this->black_kg)
                    ki.edit_list(r,c);
                k.list_k.removeAt(i);
                i-=1;
            }
            if(k.list_k.empty())
                break;
        }
        this->white_k.insert(it1,k);

    }
    }

    if(ind==black_queen)
    {
        this->threat_kg_w=false;
        queen q;
        q.q_checked=false;
        q.column_q_now=c;
        q.row_q_now=r;
        int it=this->black_q.indexOf(q);
        if(it!=-1)
        {
        this->black_q.removeAt(it);
        q.go_to1();
        int cc,rr;
        for(int i=0;i<q.list_q.count();i++)
        {
            int s=q.list_q.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index<7)
            {
                q.list_q.removeAt(i);
                int f=q.list_q.count();
                q.remove_some_mem(cc,rr);
                if(i!=q.list_q.count()-1&&f!=q.list_q.count())
                    i-=1;
            }
//            else if(index==8)
//            {
//                this->threat_kg_w=true;
//                q.threat_king=true;
//                for(king k:this->white_kg)
//                    k.edit_list(r,c);
//                int f=q.list_q.count();
//                q.list_q.removeAt(i);
//                if(i!=q.list_q.count()-1&&f!=q.list_q.count())
//                    i-=1;
//            }
            else if(index!=13)
            {
                int f=q.list_q.count();
                q.remove_some_mem(cc,rr);
                if(i!=q.list_q.count()-1&&f!=q.list_q.count())
                    i-=1;
            }
            if(q.list_q.empty())
                break;
        }
        for(int i=0;i<q.list_q.count();i++)
        {
            int s=q.list_q.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index==8)
            {
                this->threat_kg_w=true;
                q.threat_king=true;
                for(king k:this->white_kg)
                    k.edit_list(r,c);
                q.list_q.removeAt(i);
            }
        }

        this->black_q.push_back(q);
        }
    }

    if(ind==white_queen)
    {
        this->threat_kg_b=false;
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
        for(int i=0;i<q.list_q.count();i++)
        {
            int s=q.list_q.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index>6&&index!=13)
            {
                q.list_q.removeAt(i);
                int f=q.list_q.count();
                q.remove_some_mem(cc,rr);
                if(i!=q.list_q.count()-1&&f!=q.list_q.count())
                    i-=1;
            }
//            else if(index==2)
//            {
//                this->threat_kg_b=true;
//                q.threat_king=true;
//                for(king k:this->black_kg)
//                    k.edit_list(r,c);
//                int f=q.list_q.count();
//                q.list_q.removeAt(i);
//                if(i!=q.list_q.count()-1&&f!=q.list_q.count())
//                    i-=1;
//            }
            else if(index!=13)
            {
                int f=q.list_q.count();
                q.remove_some_mem(cc,rr);
                if(i!=q.list_q.count()-1&&f!=q.list_q.count())
                    i-=1;
            }
            if(q.list_q.empty())
                break;
        }
        for(int i=0;i<q.list_q.count();i++)
        {
            int s=q.list_q.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index==2)
            {
                this->threat_kg_b=true;
                q.threat_king=true;
                for(king k:this->black_kg)
                    k.edit_list(r,c);
                q.list_q.removeAt(i);
            }
        }
        this->white_q.push_back(q);
        }

    }

    if(ind==black_rook)
    {
        this->threat_kg_w=false;
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
        for(int i=0;i<r1.list_r.count();i++)
        {
            int s=r1.list_r.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index<7)
            {
                r1.list_r.removeAt(i);
                int f= r1.list_r.count();
                r1.remove_some_mem(cc,rr);
                if(i!=r1.list_r.count()-1&&f!=r1.list_r.count())
                    i-=1;
            }
//            else if(index==8)
//            {
//                this->threat_kg_w=true;
//                r1.threat_king=true;
//                for(king k:this->white_kg)
//                    k.edit_list(r,c);
//                r1.list_r.erase(s);
//            }
            else if(index!=13)
            {
                int f=r1.list_r.count();
                r1.remove_some_mem(cc,rr);
                if(i!=r1.list_r.count()-1&&f!=r1.list_r.count())
                    i-=1;
            }
            if(r1.list_r.empty())
                break;
        }
        for(int i=0;i<r1.list_r.count();i++)
        {
            int s=r1.list_r.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index==8)
            {
                this->threat_kg_w=true;
                r1.threat_king=true;
                for(king k:this->white_kg)
                    k.edit_list(r,c);
                r1.list_r.removeAt(i);
            }
        }

        this->black_r.insert(it,r1);
        }
    }

    if(ind==white_rook)
    {
        this->threat_kg_b=false;
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
        for(int i=0;i<r1.list_r.count();i++)
        {
            int s=r1.list_r.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index>6&&index!=13)
            {
                r1.list_r.removeAt(i);
                int f= r1.list_r.count();
                r1.remove_some_mem(cc,rr);
                if(i!=r1.list_r.count()-1&&f!=r1.list_r.count())
                    i-=1;
            }
            else if(index!=13)
            {
                int f= r1.list_r.count();
                r1.remove_some_mem(cc,rr);
                if(i!=r1.list_r.count()-1&&f!=r1.list_r.count())
                    i-=1;
            }
            if(r1.list_r.empty())
                break;
        }
        for(int i=0;i<r1.list_r.count();i++)
        {
            int s=r1.list_r.at(i);
            cc=s%10;
            rr=(s-cc)/10;
            index=this->find(rr,cc);
            if(index==2)
            {
                this->threat_kg_b=true;
                r1.threat_king=true;
                for(king k:this->black_kg)
                    k.edit_list(r,c);
                r1.list_r.removeAt(i);
            }
        }
        this->white_r.insert(it,r1);
        }
    }

//    if(ind==white_king)
//    {
//        this->threat_kg_b=false;
//        king kg;
//        kg.kg_checked=true;
//        kg.column_kg_now=c;
//        kg.row_kg_now=r;
//        int it=this->white_kg.indexOf(kg);
//        if(it!=-1)
//        {
//        this->white_kg.removeAt(it);
//        kg.go_to();
//        int cc,rr;
//        for(auto itr=kg.list_kg.begin();itr!=kg.list_kg.end();itr++)
//        {
//            int s=*(itr);
//            cc=s%10;
//            rr=(s-cc)/10;
//            index=this->find(rr,cc);
//            if(index>6&&index!=13)
//            {
//                if(rr-1==kg.row_kg_now)
//                    kg.list_kg.erase(s);
//                else if(rr+1==kg.row_kg_now)
//                    kg.list_kg.erase(s);
//                else if(cc-1==kg.column_kg_now)
//                    kg.list_kg.erase(s);
//                else if(cc+1==kg.column_kg_now)
//                    kg.list_kg.erase(s);
//            }
//            if(kg.list_kg.empty())
//                break;
//        }
//        this->white_kg.push_back(kg);
//        }

//    }

//    if(ind==black_king)
//    {
//        this->threat_kg_w=false;
//        king kg1;
//        kg1.kg_checked=false;
//        kg1.column_kg_now=c;
//        kg1.row_kg_now=r;
//        int it1=this->black_kg.indexOf(kg1);
//        if(it1!=-1)
//        {
//        this->black_kg.removeAt(it1);
//        kg1.go_to();
//        int cc1,rr1;
//        for(auto itr=kg1.list_kg.begin();itr!=kg1.list_kg.end();itr++)
//        {
//            int s=*(itr);
//            cc1=s%10;
//            rr1=(s-cc1)/10;
//            index=this->find(rr1,cc1);
//            if(index<7)
//            {
//                if(rr1-1==kg1.row_kg_now)
//                    kg1.list_kg.erase(s);
//                else if(rr1+1==kg1.row_kg_now)
//                    kg1.list_kg.erase(s);
//                else if(cc1-1==kg1.column_kg_now)
//                    kg1.list_kg.erase(s);
//                else if(cc1+1==kg1.column_kg_now)
//                    kg1.list_kg.erase(s);
//            }
//            if(kg1.list_kg.empty())
//                break;
//        }
//        this->black_kg.push_back(kg1);
//        }
//    }

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
        s.present_position_c=qs.at(ii-1).present_position_c;
        s.present_position_r=qs.at(ii-1).present_position_r;
        s.prev_position_c=qs.at(ii-1).prev_position_c;
        s.prev_position_r=qs.at(ii-1).prev_position_r;
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
        s.present_position_c=qs.at(ii-1).present_position_c;
        s.present_position_r=qs.at(ii-1).present_position_r;
        s.prev_position_c=qs.at(ii-1).prev_position_c;
        s.prev_position_r=qs.at(ii-1).prev_position_r;
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
        s.present_position_c=qs.at(ii-1).present_position_c;
        s.present_position_r=qs.at(ii-1).present_position_r;
        s.prev_position_c=qs.at(ii-1).prev_position_c;
        s.prev_position_r=qs.at(ii-1).prev_position_r;
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
        s.present_position_c=qs.at(ii-1).present_position_c;
        s.present_position_r=qs.at(ii-1).present_position_r;
        s.prev_position_c=qs.at(ii-1).prev_position_c;
        s.prev_position_r=qs.at(ii-1).prev_position_r;
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
        s.present_position_c=qs.at(ii-1).present_position_c;
        s.present_position_r=qs.at(ii-1).present_position_r;
        s.prev_position_c=qs.at(ii-1).prev_position_c;
        s.prev_position_r=qs.at(ii-1).prev_position_r;
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
        //s=qs.end();
        s.present_position_c=qs.at(ii-1).present_position_c;
        s.present_position_r=qs.at(ii-1).present_position_r;
        s.prev_position_c=qs.at(ii-1).prev_position_c;
        s.prev_position_r=qs.at(ii-1).prev_position_r;
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
        s.present_position_c=qs.at(ii-1).present_position_c;
        s.present_position_r=qs.at(ii-1).present_position_r;
        s.prev_position_c=qs.at(ii-1).prev_position_c;
        s.prev_position_r=qs.at(ii-1).prev_position_r;
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
        s.present_position_c=qs.at(ii-1).present_position_c;
        s.present_position_r=qs.at(ii-1).present_position_r;
        s.prev_position_c=qs.at(ii-1).prev_position_c;
        s.prev_position_r=qs.at(ii-1).prev_position_r;
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
        s.present_position_c=qs.at(ii-1).present_position_c;
        s.present_position_r=qs.at(ii-1).present_position_r;
        s.prev_position_c=qs.at(ii-1).prev_position_c;
        s.prev_position_r=qs.at(ii-1).prev_position_r;
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
        s.present_position_c=qs.at(ii-1).present_position_c;
        s.present_position_r=qs.at(ii-1).present_position_r;
        s.prev_position_c=qs.at(ii-1).prev_position_c;
        s.prev_position_r=qs.at(ii-1).prev_position_r;
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
            if(this->black_b.at(i).list_b.indexOf(r1*10+c1)==-1)
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
        if(this->white_b.at(i).list_b.indexOf(r1*10+c1)==-1)
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
        if(this->black_k.at(i).list_k.indexOf(r1*10+c1)==-1)
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
        if(this->white_k.at(i).list_k.indexOf(r1*10+c1)==-1)
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
        if(this->black_q.at(i).list_q.indexOf(r1*10+c1)==-1)
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
        if(this->white_q.at(i).list_q.indexOf(r1*10+c1)==-1)
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
        if(this->black_r.at(i).list_r.indexOf(r1*10+c1)==-1)
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
        if(this->white_r.at(i).list_r.indexOf(r1*10+c1)==-1)
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
        if(this->white_kg.at(i).list_kg.indexOf(r1*10+c1)==-1)
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
        if(this->black_kg.at(i).list_kg.indexOf(r1*10+c1)==-1)
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
        icon.addFile(":/chess_icon/ches_icons/icons8-queen-filled-50.png");
    else if(index==3)
        icon.addFile(":/chess_icon/ches_icons/icons8-bishop-filled-50.png");
    else if(index==4)
        icon.addFile(":/chess_icon/ches_icons/icons8-knight-filled-50.png");
    else if(index==5)
        icon.addFile(":/chess_icon/ches_icons/icons8-king-filled-50.png");
    else if(index==6)
        icon.addFile(":/chess_icon/ches_icons/icons8-rook-filled-50.png");
    else if(index==7)
        icon.addFile(":/chess_icon/ches_icons/icons8-pawn-50.png");
    else if(index==8)
        icon.addFile(":/chess_icon/ches_icons/icons8-queen-50.png");
    else if(index==9)
        icon.addFile(":/chess_icon/ches_icons/icons8-bishop-50.png");
    else if(index==10)
        icon.addFile(":/chess_icon/ches_icons/icons8-knight-50.png");
    else if(index==11)
        icon.addFile(":/chess_icon/ches_icons/icons8-king-50.png");
    else if(index==12)
        icon.addFile(":/chess_icon/ches_icons/icons8-rook-50.png");
    return icon;


}

bool infobase::threat_king(int bOrW)
{
    //black pieces &  threat white king
    if(bOrW==0)
    {
    for(int i=0;i<this->black_p.count();i++)
    {
        this->edit_list_to_go(this->black_p.at(i).row_p_now,this->black_p.at(i).column_p_now);
        if(this->black_p.at(i).threat_king==true)
            return true;
    }

    for(int i=0;i<this->black_b.count();i++)
    {
        this->edit_list_to_go(this->black_b.at(i).row_b_now,this->black_b.at(i).column_b_now);
        if(this->black_b.at(i).threat_king==true)
            return true;

    }

    for(int i=0;i<this->black_kg.count();i++)
    {
        this->edit_list_to_go(this->black_kg.at(i).row_kg_now,this->black_kg.at(i).column_kg_now);
        if(this->black_kg.at(i).threat_king==true)
            return true;
    }

    for(int i=0;i<this->black_k.count();i++)
    {
        this->edit_list_to_go(this->black_k.at(i).row_k_now,this->black_k.at(i).column_k_now);
        if(this->black_k.at(i).threat_king==true)
            return true;
    }

    for(int i=0;i<this->black_q.count();i++)
    {
        this->edit_list_to_go(this->white_q.at(i).row_q_now,this->white_q.at(i).column_q_now);
        if(this->white_q.at(i).threat_king==true)
            return true;
    }

    for(int i=0;i<this->black_r.count();i++)
    {
        this->edit_list_to_go(this->black_r.at(i).row_r_now,this->black_r.at(i).column_r_now);
        if(this->black_r.at(i).threat_king==true)
            return true;
    }
    }
    else if(bOrW==1)
    {
        //white pieces &  threat black king
    for(int i=0;i<this->white_p.count();i++)
    {
        this->edit_list_to_go(this->white_p.at(i).row_p_now,this->white_p.at(i).column_p_now);
        if(this->white_p.at(i).threat_king==true)
            return true;
    }

    for(int i=0;i<this->white_b.count();i++)
    {
        this->edit_list_to_go(this->white_b.at(i).row_b_now,this->white_b.at(i).column_b_now);
        if(this->white_b.at(i).threat_king==true)
            return true;
    }

    for(int i=0;i<this->white_kg.count();i++)
    {
        this->edit_list_to_go(this->white_kg.at(i).row_kg_now,this->white_kg.at(i).column_kg_now);
        if(this->white_kg.at(i).threat_king==true)
            return true;
    }

    for(int i=0;i<this->white_k.count();i++)
    {
        this->edit_list_to_go(this->white_k.at(i).row_k_now,this->white_k.at(i).column_k_now);
        if(this->white_k.at(i).threat_king==true)
            return true;
    }

    for(int i=0;i<this->white_q.count();i++)
    {
        this->edit_list_to_go(this->white_q.at(i).row_q_now,this->white_q.at(i).column_q_now);
        if(this->white_q.at(i).threat_king==true)
            return true;
    }

    for(int i=0;i<this->white_r.count();i++)
    {
            this->edit_list_to_go(this->white_r.at(i).row_r_now,this->white_r.at(i).column_r_now);
            if(this->white_r.at(i).threat_king==true)
                return true;
   }
    }
    return false;
}


bool infobase::vindicative(int bOrW, int i, int j)
{
    //is there a piece that blocks the way of threatening piece?
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
    //is there a piece that can take the threatening piece?
    //bOrW: the color of threatening
    if(bOrW=="b")
    {
      for(bishop b: this->white_b)
      {
          this->edit_list_to_go(b.row_b_now,b.column_b_now);
          if(b.list_b.indexOf(r*10+c)!= -1)
              return true;
      }
      for(pawn p: this->white_p)
      {
          this->edit_list_to_go(p.row_p_now,p.column_p_now);
          if(p.list_p.find(r*10+c)!= p.list_p.end())
              return true;
      }
      for(knight k:this->white_k)
      {
          this->edit_list_to_go(k.row_k_now,k.column_k_now);
          if(k.list_k.indexOf(r*10+c)!=-1)
              return true;
      }
      for(queen q :this->white_q)
      {
          this->edit_list_to_go(q.row_q_now,q.column_q_now);
          if(q.list_q.indexOf(r*10+c)!=-1)
              return true;
      }
      for(rook ro:this->white_r)
      {
          this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
          if(ro.list_r.indexOf(r*10+c)!=-1)
              return true;
      }
    }
    else if(bOrW=="w")
    {
        for(bishop b: this->black_b)
        {
            this->edit_list_to_go(b.row_b_now,b.column_b_now);
            if(b.list_b.indexOf(r*10+c)!= -1)
                return true;
        }
        for(pawn p: this->black_p)
        {
            this->edit_list_to_go(p.row_p_now,p.column_p_now);
            if(p.list_p.find(r*10+c)!= p.list_p.end())
                return true;
        }
        for(knight k:this->black_k)
        {
            edit_list_to_go(k.row_k_now,k.column_k_now);
            if(k.list_k.indexOf(r*10+c)!=-1)
                return true;
        }
        for(queen q :this->black_q)
        {
            this->edit_list_to_go(q.row_q_now,q.column_q_now);
            if(q.list_q.indexOf(r*10+c)!=-1)
                return true;
        }
        for(rook ro:this->black_r)
        {

            this->edit_list_to_go(ro.row_r_now,ro.column_r_now);
            if(ro.list_r.indexOf(r*10+c)!=-1)
                return true;
        }
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
                if(this->white_kg.at(0).list_kg.empty()&& !(this->delete_threat_king(p.row_p_now,p.column_p_now,"b")) && !(this->vindicative(0, p.row_p_now, p.column_p_now)))
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
        //this->edit_list_to_go(p.row_p_now,p.column_p_now);
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



