#include "king.h"

king::king()
{

}
king::king(int r, int c)
{
    this->row_kg_now=r;
    this->column_kg_now=c;

}


void king::go_to()
{
    this->list_kg.clear();

    int store; //the address of possible positions: row*10+column

    if(this->row_kg_now+1<=7)
    {
        store=(this->row_kg_now+1)*10+(this->column_kg_now);
        this->list_kg.push_back(store);
    }
    if(this->row_kg_now-1>=0)
    {
        store=(this->row_kg_now-1)*10+(this->column_kg_now);
        this->list_kg.push_back(store);
    }
    if(this->column_kg_now+1<=7)
    {
        store=(this->row_kg_now)*10+(this->column_kg_now+1);
        this->list_kg.push_back(store);



    }
    if(this->column_kg_now-1>=0)
    {
        store=(this->row_kg_now)*10+(this->column_kg_now-1);

        this->list_kg.push_back(store);


    }
    if(this->row_kg_now+1<=7 &&  this->column_kg_now-1>=0)
    {
        store=(this->row_kg_now+1)*10+(this->column_kg_now-1);
        this->list_kg.push_back(store);

    }
    if(this->row_kg_now+1<=7 && this->column_kg_now+1<=7)
    {
        store=(this->row_kg_now+1)*10+(this->column_kg_now+1);
        this->list_kg.push_back(store);


    }
    if(this->row_kg_now-1>=0 && this->column_kg_now+1<=7)
    {
        store=(this->row_kg_now-1)*10+(this->column_kg_now+1);
        this->list_kg.push_back(store);


    }
    if(this->row_kg_now-1>=0 && this->column_kg_now-1>=0)
    {
        store=(this->row_kg_now-1)*10+(this->column_kg_now-1);
        this->list_kg.push_back(store);


    }

}


void king::edit_list(int i, int j)
{
    int r=this->row_kg_now,c=this->column_kg_now;
    if(i==this->row_kg_now && j<this->column_kg_now&& j!=c-1)
    {
        if(this->list_kg.indexOf(r*10+c-1)!=-1)
            this->list_kg.removeAt(list_kg.indexOf(r*10+c-1));
    }
    if(i==this->row_kg_now && j>this->column_kg_now && j!=c+1)
    {
        if(this->list_kg.indexOf(r*10+c+1)!=-1)
        this->list_kg.removeAt(list_kg.indexOf(r*10+c+1));
    }
    if(j==this->column_kg_now && i<this->row_kg_now && i!=r-1)
    {
        if(this->list_kg.indexOf((r-1)*10+c)!=-1)
        this->list_kg.removeAt(list_kg.indexOf((r-1)*10+c));
    }
    if(j==this->column_kg_now && i>this->row_kg_now && i!=r+1)
    {
        if(this->list_kg.indexOf((r+1)*10+c)!=-1)
        this->list_kg.removeAt(list_kg.indexOf((r+1)*10+c));
    }
    if(i<this->row_kg_now && j>this->column_kg_now && i!=r-1 && j!=c+1)
    {
        if(this->list_kg.indexOf((r-1)*10+c+1)!=-1)
         this->list_kg.removeAt(list_kg.indexOf((r-1)*10+c+1));
    }
    if(i<this->row_kg_now && j<this->column_kg_now && i!=r-1 && j!=c-1)
    {
        if(this->list_kg.indexOf((r-1)*10+c-1)!=-1)
        this->list_kg.removeAt(list_kg.indexOf((r-1)*10+c-1));
    }
    if(i>this->row_kg_now && j<this->column_kg_now &&  i!=r+1 && j!=c-1)
    {
        if(this->list_kg.indexOf((r+1)*10+c-1)!=-1)
        this->list_kg.removeAt(list_kg.indexOf((r+1)*10+c-1));
    }
    if(i>this->row_kg_now && j>this->column_kg_now && i!=r+1 && j!=c+1)
    {
        if(this->list_kg.indexOf((r+1)*10+c+1)!=-1)
        this->list_kg.removeAt(list_kg.indexOf((r+1)*10+c+1));
    }

}

bool king::operator <(const king &k) const
{
    if(this->column_kg_now<k.column_kg_now && this->row_kg_now<k.row_kg_now)
        return true;
    return false;

}

bool king::operator ==(const king &k) const
{
    if(this->column_kg_now==k.column_kg_now && this->row_kg_now==k.row_kg_now)
        return true;
    return false;

}

