#ifndef SAVE_H
#define SAVE_H

#include "infobase.h"

#include <QList>


class save
{
public:
    save();
    int prev_position;
    int present_position;
    int next_position;
    QList<int> qi;

    void bishop(infobase::nameOfItem bishop);

};

#endif // SAVE_H

