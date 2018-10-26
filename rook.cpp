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
    threat_king=false;
    this->list_r.clear();
    int store;
    int i;
    for(i=1;i<=7;i++)
    {
        if(this->row_r_now+i<=7)
        {
            store=(this->row_r_now+i)*10+(this->column_r_now);
            this->list_r.insert(store);
        }
        else break;
    }
    for(i=1;i<=7;i++)
    {
        if(this->row_r_now-i>=0)
        {
            store=(this->row_r_now-i)*10+(this->column_r_now);
            this->list_r.insert(store);

        }
        else break;
    }
    for(i=1;i<=7;i++)
    {
        if(this->column_r_now+i<=7)
        {
            store=(this->row_r_now)*10+(this->column_r_now+i);
            this->list_r.insert(store);

        }
        else break;
    }
    for(i=1;i<=7;i++)
    {
        if(this->column_r_now-i>=0)
        {
            store=(this->row_r_now)*10+(this->column_r_now-i);
            this->list_r.insert(store);


        }
        else break;
    }
}

bool rook::operator <(const rook &r) const
{
    if(this->column_r_now< r.column_r_now && this->row_r_now<r.row_r_now)
        return true;
    return false;
}

void rook::remove_some_mem(int j, int i)
{
    if(i<this->row_r_now && j==this->column_r_now)
        for(int k=0;k<8;k++)
        {
            int b=(i-1-k)*10+j;
            if(this->list_r.find(b)!=this->list_r.end())
                this->list_r.erase(this->list_r.find(b));
            else break;
        }
    if(i>this->row_r_now && j==this->column_r_now)
        for(int k=0;k<8;k++)
        {
            int b=(i+1+k)*10+j;
            if(this->list_r.find(b)!=this->list_r.end())
                this->list_r.erase(this->list_r.find(b));
            else break;
        }
    if(i==this->row_r_now && j<this->column_r_now)
        for(int k=0;k<8;k++)
        {
            int b=(i*10)+(j-1-k);
            if(this->list_r.find(b)!=this->list_r.end())
                this->list_r.erase(this->list_r.find(b));
            else break;
        }
    if(i==this->row_r_now && j>this->column_r_now)
    {
        for(int k=0;k<8;k++)
        {
            int b=(i*10)+(j+1+k);
            if(this->list_r.find(b)!=this->list_r.end())
                this->list_r.erase(this->list_r.find(b));
            else break;
        }
    }
}

