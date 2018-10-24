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

void bishop::remove_some_mem(int j, int i)
{
    //hazf kardan makanha ye ezafi bar asas bagheye mohreha
    if(i<this->row_b_now && j<this->column_b_now)
        for(int k=0;k<8;k++)
        {
            bishop b;
            b.column_b_now=j-k-1;
            b.row_b_now=i-k-1;
            if(this->list_b.find(b)!=this->list_b.end())
               this->list_b.erase(this->list_b.find(b));
            else break;
        }
    if(i>this->row_b_now && j>this->column_b_now)
        for(int k=0;k<8;k++)
        {
            bishop b;
            b.column_b_now=j+k+1;
            b.row_b_now=i+k+1;
            if(this->list_b.find(b)!=this->list_b.end())
               this->list_b.erase(this->list_b.find(b));
            else break;
        }
    if(i>this->row_b_now && j<this->column_b_now)
        for(int k=0;k<8;k++)
        {
            bishop b;
            b.column_b_now=j-k-1;
            b.row_b_now=i+k+1;
            if(this->list_b.find(b)!=this->list_b.end())
               this->list_b.erase(this->list_b.find(b));
            else break;
        }
    if(i<this->row_b_now && j>this->column_b_now)
        for(int k=0;k<8;k++)
        {
            bishop b;
            b.column_b_now=j+k-1;
            b.row_b_now=i+k+1;
            if(this->list_b.find(b)!=this->list_b.end())
               this->list_b.erase(this->list_b.find(b));
            else break;
        }

}

bool bishop::operator <(const bishop &b) const
{
    if(this->column_b_now<b.column_b_now && this->row_b_now<b.row_b_now)
        return true;
    return false;

}

bool bishop::operator ==(const bishop &b) const
{
    if(this->column_b_now==b.column_b_now&&this->row_b_now==b.row_b_now)
        return true;
    return  false;

}

