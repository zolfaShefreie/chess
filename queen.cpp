#include "queen.h"

queen::queen()
{

}

queen::queen(int rq, int cq)
{
    this->row_q_now = rq;
    this->column_q_now = cq;
}

void queen::go_to1()
{

    int store;

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            //move in rows and columns

            if( this->row_q_now<=7 && this->column_q_now+j<=7 )
            {
                store=(this->row_q_now+i)*10+(this->column_q_now+i);
                this->list_q.insert(store);
            }

            if( this->row_q_now>=0  && this->column_q_now-j<=7 )
            {
                store=(this->row_q_now+i)*10+(this->column_q_now-i);
                this->list_q.insert(store);
            }

            if( this->row_q_now+i<=7 && this->column_q_now>=0 )
            {
                store=(this->row_q_now-i)*10+(this->column_q_now+i);
                this->list_q.insert(store);
            }

            if( this->row_q_now-i>=0  && this->column_q_now>=0 )
            {
                store=(this->row_q_now-i)*10+(this->column_q_now-i);
                this->list_q.insert(store);
            }
        }
    }

    for(int i=1; i<8; i++)
    {
        // move in diagonals

        if(this->column_q_now+i<=7&& this->row_q_now+i<=7)
        {
            store=(this->row_q_now+i)*10+(this->column_q_now+i);
            this->list_q.insert(store);
        }
        if(this->column_q_now+i<=7&& this->row_q_now-i>=0)
        {
            store=(this->row_q_now+i)*10+(this->column_q_now-i);
            this->list_q.insert(store);
        }
        if(this->column_q_now-i>=0&& this->row_q_now+i<=7)
        {
            store=(this->row_q_now-i)*10+(this->column_q_now+i);
            this->list_q.insert(store);
        }
        if(this->column_q_now-i>=0&& this->row_q_now-i>=0)
        {
            store=(this->row_q_now-i)*10+(this->column_q_now-i);
            this->list_q.insert(store);
        }


    }
}

bool queen::operator <(const queen &q) const
{
    if(this->column_q_now<q.column_q_now && this->row_q_now<q.row_q_now)
        return true;
    return false;
}

void queen::remove_some_mem(int j, int i)
{
    // removing forbidden positions in a row
    if(i==this->row_q_now && j<this->column_q_now)
        for(int k=0;k<8;k++)
        {
            int b=i*10+(j-1-k);
            if(this->list_q.find(b)!=this->list_q.end())
                this->list_q.erase(this->list_q.find(b));
            else break;
        }
    if(i==this->row_q_now && j>this->column_q_now)
        for(int k=0;k<8;k++)
        {
            int b=i*10+(j+1+k);
            if(this->list_q.find(b)!=this->list_q.end())
                this->list_q.erase(this->list_q.find(b));
            else break;
        }
    //removing forbidden positions in a column
    if(j==this->column_q_now && i<this->row_q_now)
        for(k=0;k<8;k++)
        {
            int b=(i-1-k)*10+j;
            if(this->list_q.find(b)!=this->list_q.end())
                this->list_q.erase(this->list_q.find(b));
            else break;
        }
    if(j==this->column_q_now && i>this->row_q_now)
        for(int k=0;k<8;k++)
        {
            int b=(i+1+k)*10+j;
            if(this->list_q.find(b)!=this->list_q.end())
                this->list_q.erase(this->list_q.find(b));
            else break;
        }
    //removing forbidden dioagonal positions
    if(i<this->row_q_now && j<this->column_q_now)
        for(int k=0;k<8;k++)
        {
            int b=(i-1-k)*10+(j-1-k);
            if(this->list_q.find(b)!=this->list_q.end())
                this->list_q.erase(this->list_q.find(b));
            else break;
        }
    if(i<this->row_q_now && j>this->column_q_now)
        for(int k=0;k<8;k++)
        {
            int b=(i-1-k)*10+(j+1+k);
            if(this->list_q.find(b)!=this->list_q.end())
                this->list_q.erase(this->list_q.find(b));
            else break;
        }
    if(i>this->row_q_now && j<this->column_q_now)
        for(int k=0;k<8;k++)
        {
            int b=(i+1+k)*10+(j-1-k);
            if(this->list_q.find(b)!=this->list_q.end())
                this->list_q.erase(this->list_q.find(b));
            else break;
        }
    if(i>this->row_q_now && j>this->column_q_now)
        for(int k=0;k<8;k++)
        {
            int b=(i+1+k)*10+(j+1+k);
            if(this->list_q.find(b)!=this->list_q.end())
                this->list_q.erase(this->list_q.find(b));
        }
}
