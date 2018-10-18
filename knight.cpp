#include "knight.h"

knight::knight()
{

}

knight::knight(int r, int c)
{
    this->column_k_now=c;
    this->row_k_now=r;
}

QList<int>* knight::go_to()
{
    QList<int>* return_list;
    int store;
    if(this->row_k_now+2<=7)
    {
        if(this->column_k_now+1<=7)
        {
           store=(this->row_k_now+2)*10+(this->column_k_now+1);
           return_list->push_back(store);
        }
        if(this->column_k_now-1>=0)
        {
            store=(this->row_k_now+2)*10+(this->column_k_now-1);
            return_list->push_back(store);
        }
    }
    if(this->row_k_now-2>=0)
    {
        if(this->column_k_now+1<=7)
        {
           store=(this->row_k_now-2)*10+(this->column_k_now+1);
           return_list->push_back(store);
        }
        if(this->column_k_now-1>=0)
        {
            store=(this->row_k_now-2)*10+(this->column_k_now-1);
            return_list->push_back(store);
        }
    }
    if(this->row_k_now+1<=7)
    {
        if(this->column_k_now+2<=7)
        {
           store=(this->row_k_now+1)*10+(this->column_k_now+2);
           return_list->push_back(store);
        }
        if(this->column_k_now-2>=0)
        {
            store=(this->row_k_now+1)*10+(this->column_k_now-2);
            return_list->push_back(store);
        }
    }
    if(this->row_k_now-1>=0)
    {
        if(this->column_k_now+2<=7)
        {
           store=(this->row_k_now-1)*10+(this->column_k_now+2);
           return_list->push_back(store);
        }
        if(this->column_k_now-2>=0)
        {
            store=(this->row_k_now-1)*10+(this->column_k_now-2);
            return_list->push_back(store);
        }
    }
    return return_list;


    }
