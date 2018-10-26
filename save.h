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
    void king(infobase::nameOfItem king);
    void knight(infobase::nameOfItem knight);
    void pawn(infobase::nameOfItem pawn);
    void queen(infobase::nameOfItem queen);
    void rook(infobase::nameOfItem rook);
};

#endif // SAVE_H

