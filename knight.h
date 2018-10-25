#ifndef KNIGHT_H
#define KNIGHT_H
#include<Qlist>
#include<QPixmap>
#include<QIcon>
#include<QString>
#include<set>
#include<QIcon>
using namespace std;

class knight
{
public:
    knight();
    knight(int r, int c);
    int row_k_now;
    int column_k_now;
    set<int> list_k;
    bool k_checked=true;//true=white   false=black
    static const bool is_knight = true;
    void go_to();// the list of where can it go
    bool operator <( knight const & k) const;
    bool operator ==( const knight &k) const;

};

#endif // KNIGHT_H
