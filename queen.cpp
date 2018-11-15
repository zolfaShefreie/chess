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
    threat_king=false;
    this->list_q.clear();

    int store; //the address of possible positions: row*10+column


    for(int i=1; i<8; i++)
    {
            //move in rows and columns

            if(this->column_q_now+i<=7 )
            {
                store=(this->row_q_now)*10+(this->column_q_now+i);
                this->list_q.push_back(store);
            }

            if(this->column_q_now-i>=0 )
            {
                store=(this->row_q_now)*10+(this->column_q_now-i);
                this->list_q.push_back(store);
            }

            if( this->row_q_now+i<=7)
            {
                store=(this->row_q_now+i)*10+(this->column_q_now);
                this->list_q.push_back(store);
            }

            if( this->row_q_now-i>=0 )
            {
                store=(this->row_q_now-i)*10+(this->column_q_now);
                this->list_q.push_back(store);
            }

    }

    for(int i=1; i<8; i++)
    {
        // move in diagonals

        if(this->column_q_now+i<=7&& this->row_q_now+i<=7)
        {
            store=(this->row_q_now+i)*10+(this->column_q_now+i);
            this->list_q.push_back(store);
        }
        if(this->column_q_now+i<=7&& this->row_q_now-i>=0)
        {
            store=(this->row_q_now-i)*10+(this->column_q_now+i);
            this->list_q.push_back(store);
        }
        if(this->column_q_now-i>=0&& this->row_q_now+i<=7)
        {
            store=(this->row_q_now+i)*10+(this->column_q_now-i);
            this->list_q.push_back(store);
        }
        if(this->column_q_now-i>=0&& this->row_q_now-i>=0)
        {
            store=(this->row_q_now-i)*10+(this->column_q_now-i);
            this->list_q.push_back(store);
        }


    }
}

bool queen::operator <(const queen &q) const
{
    if(this->column_q_now<q.column_q_now && this->row_q_now<q.row_q_now)
        return true;
    return false;
}

bool queen::operator ==(const queen &q) const
{
    if(this->column_q_now==q.column_q_now && this->row_q_now==q.row_q_now)
        return true;
    return false;
}

void queen::remove_some_mem(int j, int i)
{
    // removing forbidden positions in a row
    if(i==this->row_q_now && j<this->column_q_now)
        for(int k=0;j-1-k>=0;k++)
        {
            int b=i*10+(j-1-k);
            if(this->list_q.indexOf(b)!=-1)
                this->list_q.removeAt(this->list_q.indexOf(b));
        }
    if(i==this->row_q_now && j>this->column_q_now)
        for(int k=0;j+1+k<8;k++)
        {
            int b=i*10+(j+1+k);
            if(this->list_q.indexOf(b)!=-1)
                this->list_q.removeAt(this->list_q.indexOf(b));
        }
    //removing forbidden positions in a column
    if(j==this->column_q_now && i<this->row_q_now)
        for(int k=0;i-1-k>=0;k++)
        {
            int b=(i-1-k)*10+j;
            if(this->list_q.indexOf(b)!=-1)
                this->list_q.removeAt(this->list_q.indexOf(b));
        }
    if(j==this->column_q_now && i>this->row_q_now)
        for(int k=0;i+1+k<8;k++)
        {
            int b=(i+1+k)*10+j;
            if(this->list_q.indexOf(b)!=-1)
                this->list_q.removeAt(this->list_q.indexOf(b));
        }
    //removing forbidden dioagonal positions
    if(i<this->row_q_now && j<this->column_q_now)
        for(int k=0;i-1-k>=0&&j-1-k>=0;k++)
        {
            int b=(i-1-k)*10+(j-1-k);
            if(this->list_q.indexOf(b)!=-1)
                this->list_q.removeAt(this->list_q.indexOf(b));
        }
    if(i<this->row_q_now && j>this->column_q_now)
        for(int k=0;i-1-k>=0&&j+1+k<8;k++)
        {
            int b=(i-1-k)*10+(j+1+k);
            if(this->list_q.indexOf(b)!=-1)
                this->list_q.removeAt(this->list_q.indexOf(b));
        }
    if(i>this->row_q_now && j<this->column_q_now)
        for(int k=0;i+1+k<8&&j-1-k>=0;k++)
        {
            int b=(i+1+k)*10+(j-1-k);
            if(this->list_q.indexOf(b)!=-1)
                this->list_q.removeAt(this->list_q.indexOf(b));
        }
    if(i>this->row_q_now && j>this->column_q_now)
        for(int k=0;i+1+k<8&&j+1+k<8;k++)
        {
            int b=(i+1+k)*10+(j+1+k);
            if(this->list_q.indexOf(b)!=-1)
                this->list_q.removeAt(this->list_q.indexOf(b));
        }
}
