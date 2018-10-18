#include "king.h"

king::king()
{

}
king::king(int r, int c)
{
    this->row_kg_now=r;
    this->column_kg_now=c;

}

QList<int> king::go_to()
{
    QList<int> return_list;
    int store;
    if(this->row_kg_now+1<=7)
    {
        store=(this->row_kg_now+1)*10+(this->column_kg_now);
        return_list.push_back(store);
    }
    if(this->row_kg_now-1>=0)
    {
        store=(this->row_kg_now-1)*10+(this->column_kg_now);
        return_list.push_back(store);
    }
    if(this->column_kg_now+1<=7)
    {
        store=(this->row_kg_now)*10+(this->column_kg_now+1);
        return_list.push_back(store);


    }
    if(this->column_kg_now-1>=0)
    {
        store=(this->row_kg_now)*10+(this->column_kg_now-1);

        return_list.push_back(store);

    }
    if(this->row_kg_now+1<=7 &&  this->column_kg_now-1>=0)
    {
        store=(this->row_kg_now+1)*10+(this->column_kg_now-1);
        return_list.push_back(store);
    }
    if(this->row_kg_now+1<=7 && this->column_kg_now+1<=7)
    {
        store=(this->row_kg_now+1)*10+(this->column_kg_now+1);
        return_list.push_back(store);

    }
    if(this->row_kg_now-1>=0 && this->column_kg_now+1<=7)
    {
        store=(this->row_kg_now-1)*10+(this->column_kg_now+1);
        return_list.push_back(store);

    }
    if(this->row_kg_now-1>=0 && this->column_kg_now-1>=0)
    {
        store=(this->row_kg_now-1)*10+(this->column_kg_now-1);
        return_list.push_back(store);

    }

    return return_list;
}

