#include "king.h"

king::king()
{

}
king::king(int r, int c)
{
    this->row_kg_now=r;
    this->column_kg_now=c;

}

void king::go_to()
{

    int store;
    if(this->row_kg_now+1<=7)
    {
        store=(this->row_kg_now+1)*10+(this->column_kg_now);
        this->list_kg.insert(store);
    }
    if(this->row_kg_now-1>=0)
    {
        store=(this->row_kg_now-1)*10+(this->column_kg_now);
        this->list_kg.insert(store);
    }
    if(this->column_kg_now+1<=7)
    {
        store=(this->row_kg_now)*10+(this->column_kg_now+1);
        this->list_kg.insert(store);



    }
    if(this->column_kg_now-1>=0)
    {
        store=(this->row_kg_now)*10+(this->column_kg_now-1);

        this->list_kg.insert(store);


    }
    if(this->row_kg_now+1<=7 &&  this->column_kg_now-1>=0)
    {
        store=(this->row_kg_now+1)*10+(this->column_kg_now-1);
        this->list_kg.insert(store);

    }
    if(this->row_kg_now+1<=7 && this->column_kg_now+1<=7)
    {
        store=(this->row_kg_now+1)*10+(this->column_kg_now+1);
        this->list_kg.insert(store);


    }
    if(this->row_kg_now-1>=0 && this->column_kg_now+1<=7)
    {
        store=(this->row_kg_now-1)*10+(this->column_kg_now+1);
        this->list_kg.insert(store);


    }
    if(this->row_kg_now-1>=0 && this->column_kg_now-1>=0)
    {
        store=(this->row_kg_now-1)*10+(this->column_kg_now-1);
        this->list_kg.insert(store);


    }

}

bool king::operator <(const king &k) const
{
    if(this->column_kg_now<k.column_kg_now && this->row_kg_now<k.row_kg_now)
        return true;
    return false;

}

