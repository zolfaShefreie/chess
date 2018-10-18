#include "bishop.h"

bishop::bishop()
{

}

bishop::bishop(int r, int c)
{
    this->row_b_now = r;
    this->column_b_now = c;
}

QList<int> bishop::go_to()
{
    QList<int> return_list;
    int store;

    for(int i=1; i<8; i++)
    {
        if(this->column_b_now+i<=7&& this->row_b_now+i<=7)
        {
            store=(this->row_b_now+i)*10+(this->column_b_now+i);
            return_list.push_back(store);
        }
        if(this->column_b_now+i<=7&& this->row_b_now-i>=0)
        {
            store=(this->row_b_now+i)*10+(this->column_b_now-i);
            return_list.push_back(store);
        }
        if(this->column_b_now-i>=0&& this->row_b_now+i<=7)
        {
            store=(this->row_b_now-i)*10+(this->column_b_now+i);
            return_list.push_back(store);
        }
        if(this->column_b_now-i>=0&& this->row_b_now-i>=0)
        {
            store=(this->row_b_now-i)*10+(this->column_b_now-i);
            return_list.push_back(store);
        }
    }
}

