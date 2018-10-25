#include "pawn.h"

pawn::pawn()
{

}

pawn::pawn(int r, int c ,bool wob)
{
    this->row_p_now=r;
    this->column_p_now=c;
    this->p_checked=wob;
}

void pawn::go_to()
{
    int store;
    this->list_p->clear();
   if (this->first_step==0)
   {
       if (p_checked)
       {
           store=(this->row_p_now+1)*10+this->column_p_now;
           this->list_p->insert(store);
           store=(this->row_p_now+2)*10+this->column_p_now;
           this->list_p->insert(store);
       }
       else
       {
           store=(this->row_p_now-1)*10+this->column_p_now;
           this->list_p->insert(store);
           store=(this->row_p_now-2)*10+this->column_p_now;
           this->list_p->insert(store);
       }
   }
   else if(this->first_step!=0)
   {
       if(p_checked)
       {
           if(this->row_p_now+1<=7)
           {
               store=(this->row_p_now+1)*10+this->column_p_now;
               this->list_p->insert(store);

           }
       }
       else if(!p_checked)
               if(this->row_p_now-1>=0)
               {
                   store=(this->row_p_now-1)*10+this->column_p_now;
                   this->list_p->insert(store);
               }
   }

}


bool pawn::operator <(const pawn &p) const
{
    if(this->column_p_now<p.column_p_now && this->row_p_now<p.row_p_now)
        return true;
    return false;
}


