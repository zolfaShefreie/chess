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
    this->list_k->clear();
    int store;
    if(this->row_k_now+2<=7)
    {
        if(this->column_k_now+1<=7)
        {
           store=(this->row_k_now+2)*10+(this->column_k_now+1);
           this->list_k->insert(store);
        }
        if(this->column_k_now-1>=0)
        {
            store=(this->row_k_now+2)*10+(this->column_k_now-1);
            this->list_k->insert(store);
        }
    }
    if(this->row_k_now-2>=0)
    {
        if(this->column_k_now+1<=7)
        {
           store=(this->row_k_now-2)*10+(this->column_k_now+1);
           this->list_k->insert(store);
        }
        if(this->column_k_now-1>=0)
        {
            store=(this->row_k_now-2)*10+(this->column_k_now-1);
            this->list_k->insert(store);
        }
    }
    if(this->row_k_now+1<=7)
    {
        if(this->column_k_now+2<=7)
        {
           store=(this->row_k_now+1)*10+(this->column_k_now+2);
           this->list_k->insert(store);
        }
        if(this->column_k_now-2>=0)
        {
            store=(this->row_k_now+1)*10+(this->column_k_now-2);
            this->list_k->insert(store);
        }
    }
    if(this->row_k_now-1>=0)
    {
        if(this->column_k_now+2<=7)
        {
           store=(this->row_k_now-1)*10+(this->column_k_now+2);
           this->list_k->insert(store);;
        }
        if(this->column_k_now-2>=0)
        {
            store=(this->row_k_now-1)*10+(this->column_k_now-2);
            this->list_k->insert(store);
        }
    }

}

bool knight::operator <(const knight &k) const
{
    if(this->row_k_now<k.row_k_now && this->column_k_now<k.column_k_now)
        return true;
    return false;

}
