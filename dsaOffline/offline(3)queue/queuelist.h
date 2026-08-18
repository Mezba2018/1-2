//#include"list.h"
#include"array.h"

template<typename t>

class queue{
list<t>l1;
public:
    //1
    void enqueue(t item)
    {
        l1.moveToPos(l1.length());
        l1.insert(item);

    }
    //2
    t dequeue()
    {
        l1.moveToStart();
        return l1.remov();

    }
    //3
    int length()
    {
        return l1.length();
    }
    //4
    t front()
    {
     l1.moveToStart();
     return l1.getValue();
    }
    //5
    t back()
    {
        l1.moveToEnd();
        return l1.getValue();
    }
    //6
    bool is_empty()
    {
        if(l1.length()==0)
            return true;
        else return false;

    }
    //7
    void clear()
    {
        int j=l1.length();
        l1.moveToStart();
        for(int i=0;i<j;i++)
        {
            l1.remov();
        }

    }
    void print()
    {
        l1.print();
    }

};

