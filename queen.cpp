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
