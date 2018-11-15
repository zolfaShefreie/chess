#include "knight.h"

knight::knight()
{
}

knight::knight(int r, int c)
{
    this->column_k_now=c;
    this->row_k_now=r;
}


void knight::go_to()
{
    threat_king=false;

    this->list_k.clear();
    int store;    //the address of possible positions: row*10+column

    if(this->row_k_now+2<=7)
    {
        if(this->column_k_now+1<=7)
        {
           store=(this->row_k_now+2)*10+(this->column_k_now+1);
           this->list_k.push_back(store);
        }
        if(this->column_k_now-1>=0)
        {
            store=(this->row_k_now+2)*10+(this->column_k_now-1);
            this->list_k.push_back(store);
        }
    }
    if(this->row_k_now-2>=0)
    {
        if(this->column_k_now+1<=7)
        {
           store=(this->row_k_now-2)*10+(this->column_k_now+1);
           this->list_k.push_back(store);
        }
        if(this->column_k_now-1>=0)
        {
            store=(this->row_k_now-2)*10+(this->column_k_now-1);
            this->list_k.push_back(store);
        }
    }
    if(this->row_k_now+1<=7)
    {
        if(this->column_k_now+2<=7)
        {
           store=(this->row_k_now+1)*10+(this->column_k_now+2);
           this->list_k.push_back(store);
        }
        if(this->column_k_now-2>=0)
        {
            store=(this->row_k_now+1)*10+(this->column_k_now-2);
            this->list_k.push_back(store);
        }
    }
    if(this->row_k_now-1>=0)
    {
        if(this->column_k_now+2<=7)
        {
           store=(this->row_k_now-1)*10+(this->column_k_now+2);
           this->list_k.push_back(store);;
        }
        if(this->column_k_now-2>=0)
        {
            store=(this->row_k_now-1)*10+(this->column_k_now-2);
            this->list_k.push_back(store);
        }
    }

}

bool knight::operator <(const knight &k) const
{
    if(this->row_k_now<k.row_k_now && this->column_k_now<k.column_k_now)
        return true;
    return false;

}

bool knight::operator ==(const knight &k) const
{
    if(k.column_k_now==this->column_k_now && k.row_k_now==this->row_k_now)
        return true;
    return false;

}
