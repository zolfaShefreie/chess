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
    threat_king=false;
    this->list_b.clear();
    int store; //the address of possible positions: row*10+column

    for(int i=1; i<8; i++)
    {
        if(this->column_b_now+i<=7&& this->row_b_now+i<=7)
        {
            store=(this->row_b_now+i)*10+(this->column_b_now+i);
            this->list_b.push_back(store);
        }
        if(this->column_b_now+i<=7&& (this->row_b_now-i)>=0)
        {
            store=(this->row_b_now-i)*10+(this->column_b_now+i);
            this->list_b.push_back(store);
        }
        if((this->column_b_now-i)>=0&& (this->row_b_now+i)<=7)
        {
            store=(this->row_b_now+i)*10+(this->column_b_now-i);
            this->list_b.push_back(store);
        }
        if((this->column_b_now-i)>=0&& this->row_b_now-i>=0)
        {
            store=(this->row_b_now-i)*10+(this->column_b_now-i);
            this->list_b.push_back(store);
        }
    }


}

void bishop::remove_some_mem(int j, int i)
{
    //hazf kardan makanha ye ezafi bar asas bagheye mohreha
    if(i<this->row_b_now && j<this->column_b_now)
        for(int k=0;i-k-1>=0&&j-k-1>=0;k++)
        {
            int b;
            b=((i-k-1)*10)+(j-k-1);
            if(this->list_b.indexOf(b)!=-1)
               this->list_b.removeAt(this->list_b.indexOf(b));
        }
    else if(i>this->row_b_now && j>this->column_b_now)
        for(int k=0;i+k+1<8&&j+k+1<8;k++)
        {
            int b;
            b=((i+k+1)*10)+(j+k+1);
            if(this->list_b.indexOf(b)!=-1)
               this->list_b.removeAt(this->list_b.indexOf(b));
        }
    else if(i>this->row_b_now && j<this->column_b_now)
        for(int k=0;i+k+1<8&&j-k-1>=0;k++)
        {
            int b;
            b=((i+k+1)*10)+(j-k-1);
            if(this->list_b.indexOf(b)!=-1)
               this->list_b.removeAt(this->list_b.indexOf(b));
        }
    else if(i<this->row_b_now && j>this->column_b_now)
        for(int k=0;i-k-1>=0&&j+k+1>=0;k++)
        {
            int b;
            b=((i-k-1)*10)+(j+k+1);
            if(this->list_b.indexOf(b)!=-1)
               this->list_b.removeAt(this->list_b.indexOf(b));
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


