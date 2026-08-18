#include"array.h"

template<typename t>

class queue{
list<t>l1;
public:
    //1
    void enqueue(t item);
    //2
    t dequeue();
    //3
    int length();
    //4
    t front();

    //5
    t back();

    //6
    bool is_empty();

    //7
    void clear();

    void print();


};

