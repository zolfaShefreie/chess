#ifndef KING_H
#define KING_H
#include<QList>

class king
{
public:
    king();
    king(int r ,int c);
    int row_kg_now;
    int column_kg_now;
    QList<int> go_to();

};

#endif // KING_H
