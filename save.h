#ifndef SAVE_H
#define SAVE_H


#include <QList>


class save
{
public:
    save();
    int prev_position_r;
    int prev_position_c;
    int present_position_c;
    int present_position_r;

    int deleted_item=0;//this num must be like infobase::nameOfItem
    int deleted_item_r=-1;
    int deleted_item_c=-1;

};

#endif // SAVE_H

