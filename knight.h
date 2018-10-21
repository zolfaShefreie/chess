#ifndef KNIGHT_H
#define KNIGHT_H
<<<<<<< HEAD
#include<Qlist>
#include<QPixmap>
#include<QIcon>
#include<QString>
using namespace std;
=======
#include<set>
#include<QIcon>
using namespace std;

>>>>>>> 64d7edab5b722e1253d9bdb32d3464b4c7ff5132
class knight
{
public:
    knight();
    knight(int r, int c);
    int row_k_now;
    int column_k_now;

<<<<<<< HEAD

    //bool k_checked=true;//true=white   false=black
    QList<int>* go_to();//return the list of where can it go
=======
    set<int> *list_k;
    bool k_checked=true;//true=white   false=black
    void go_to();// the list of where can it go
>>>>>>> 64d7edab5b722e1253d9bdb32d3464b4c7ff5132
};

#endif // KNIGHT_H
