#include "queen.h"

queen::queen()
{

}

queen::queen(int rq, int cq)
{
    this->row_q_now = rq;
    this->column_q_now = cq;
}

QList<int> queen::go_to1()
{
    QList<int> return_list;
    int store;


    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            //move in rows and columns

            if( this->row_q_now<=7 && this->column_q_now+j<=7 )
            {
                store=(this->row_q_now+i)*10+(this->column_q_now+i);
                return_list.push_back(store);
            }

            if( this->row_q_now>=0  && this->column_q_now-j<=7 )
            {
                store=(this->row_q_now+i)*10+(this->column_q_now-i);
                return_list.push_back(store);
            }

            if( this->row_q_now+i<=7 && this->column_q_now>=0 )
            {
                store=(this->row_q_now-i)*10+(this->column_q_now+i);
                return_list.push_back(store);
            }

            if( this->row_q_now-i>=0  && this->column_q_now>=0 )
            {
                store=(this->row_q_now-i)*10+(this->column_q_now-i);
                return_list.push_back(store);
            }


        }
    }

    for(int i=1; i<8; i++)
    {
        // move in diagonal

        if(this->column_q_now+i<=7&& this->row_q_now+i<=7)
        {
            store=(this->row_q_now+i)*10+(this->column_q_now+i);
            return_list.push_back(store);
        }
        if(this->column_q_now+i<=7&& this->row_q_now-i>=0)
        {
            store=(this->row_q_now+i)*10+(this->column_q_now-i);
            return_list.push_back(store);
        }
        if(this->column_q_now-i>=0&& this->row_q_now+i<=7)
        {
            store=(this->row_q_now-i)*10+(this->column_q_now+i);
            return_list.push_back(store);
        }
        if(this->column_q_now-i>=0&& this->row_q_now-i>=0)
        {
            store=(this->row_q_now-i)*10+(this->column_q_now-i);
            return_list.push_back(store);
        }


    }
    return return_list;
}
