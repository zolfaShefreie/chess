#include "rook.h"

rook::rook()
{

}
rook::rook(int r, int c)
{
    this->row_r_now=r;
    this->column_r_now=c;

}

void rook::go_to()
{
    int store;
    int i;
    for(i=1;i<=7;i++)
    {
        if(this->row_r_now+i<=7)
        {
            store=(this->row_r_now+i)*10+(this->column_r_now);
            this->list_r->insert(store);
        }
        else break;
    }
    for(i=1;i<=7;i++)
    {
        if(this->row_r_now-i>=0)
        {
            store=(this->row_r_now-i)*10+(this->column_r_now);
            this->list_r->insert(store);

        }
        else break;
    }
    for(i=1;i<=7;i++)
    {
        if(this->column_r_now+i<=7)
        {
            store=(this->row_r_now)*10+(this->column_r_now+i);
            this->list_r->insert(store);

        }
        else break;
    }
    for(i=1;i<=7;i++)
    {
        if(this->column_r_now-i>=0)
        {
            store=(this->row_r_now)*10+(this->column_r_now-i);
            this->list_r->insert(store);


        }
        else break;
    }
}

