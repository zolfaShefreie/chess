#include "bishop.h"

bishop::bishop()
{

}

bishop::bishop(int r, int c)
{
    this->row_b_now = r;
    this->column_b_now = c;
}

void bishop::go_to()
{

    int store;

    for(int i=1; i<8; i++)
    {
        if(this->column_b_now+i<=7&& this->row_b_now+i<=7)
        {
            store=(this->row_b_now+i)*10+(this->column_b_now+i);
            this->list_b.insert(store);
        }
        if(this->column_b_now+i<=7&& this->row_b_now-i>=0)
        {
            store=(this->row_b_now+i)*10+(this->column_b_now-i);
            this->list_b.insert(store);
        }
        if(this->column_b_now-i>=0&& this->row_b_now+i<=7)
        {
            store=(this->row_b_now-i)*10+(this->column_b_now+i);
            this->list_b.insert(store);
        }
        if(this->column_b_now-i>=0&& this->row_b_now-i>=0)
        {
            store=(this->row_b_now-i)*10+(this->column_b_now-i);
            this->list_b.insert(store);
        }
    }


}

bool bishop::operator <(const bishop &b) const
{
    if(this->column_b_now<b.column_b_now && this->row_b_now<b.row_b_now)
        return true;
    return false;

}

