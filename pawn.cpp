#include "pawn.h"

pawn::pawn()
{

}

pawn::pawn(int r, int c ,bool wob)
{
    this->row_p_now=r;
    this->column_p_now=c;
    this->checked=wob;
}

void pawn::go_to()
{
    int store;
<<<<<<< HEAD

    QList<int>* return_list;
    if (this->first_step==0)
    {
        if (checked)
        {
            store=(this->row_p_now+1)*10+this->column_p_now;
            return_list->push_back(store);
            store=(this->row_p_now+2)*10+this->column_p_now;
            return_list->push_back(store);
        }
        else
        {
            store=(this->row_p_now-1)*10+this->column_p_now;
            return_list->push_back(store);
            store=(this->row_p_now-2)*10+this->column_p_now;
            return_list->push_back(store);
        }
    }
    else if(this->first_step!=0)
    {
        if(checked)
        {
            if(this->row_p_now+1<=7)
            {
                store=(this->row_p_now+1)*10+this->column_p_now;
                return_list->push_back(store);

            }
        }
        else if(!checked)
            if(this->row_p_now-1>=0)
            {
                store=(this->row_p_now-1)*10+this->column_p_now;
                return_list->push_back(store);
            }
    }
    return return_list;
=======
   if (this->first_step==0)
   {
       if (checked)
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
       if(checked)
       {
           if(this->row_p_now+1<=7)
           {
               store=(this->row_p_now+1)*10+this->column_p_now;
               this->list_p->insert(store);

           }
       }
       else if(!checked)
               if(this->row_p_now-1>=0)
               {
                   store=(this->row_p_now-1)*10+this->column_p_now;
                   this->list_p->insert(store);
               }
   }

>>>>>>> 235a4312390dc02575e379360c4fdad252d67352


}


