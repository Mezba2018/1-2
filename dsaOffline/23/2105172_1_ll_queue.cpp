
#include "2105172_1_ll_queue.h"
template<typename t>

//1
void queue<t>::enqueue(t item)
{
     l1.moveToPos(l1.length());
        l1.insert(item);
}

    //2
    template<typename t>

t queue<t>:: dequeue()
{
     l1.moveToStart();
        return l1.remov();
}
    //3
    template<typename t>

int queue<t>::length()
{
 return l1.length();
}
    //4
    template<typename t>

t queue<t>::front()
{
     l1.moveToStart();
     return l1.getValue();
}

    //5
    template<typename t>

t queue<t>::back()
{

        l1.moveToEnd();
        return l1.getValue();
}

    //6
    template<typename t>

bool queue<t>::is_empty()
{
    if(l1.length()==0)
            return true;
        else return false;
}

    //7
    template<typename t>

void queue<t>::clear()
{
    int j=l1.length();
        l1.moveToStart();
        for(int i=0;i<j;i++)
        {
            l1.remov();
        }

}
template<typename t>

void queue<t>::print()
{
   l1.print();
}

