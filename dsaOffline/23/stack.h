
#include"2105172_1_a_queue.cpp"
//#include"2105172_1_ll_queue.cpp"

template<typename t>

class stack{
queue<t> q1,q2;
public:

  //4
  int length()
  {
      return q1.length();
  }
  //5
  t topValue()
  {
      return q1.back();
  }
  //6
  bool isEmpty()
  {
       if(q1.length()==0)
            return true;
        else return false;
  }
  //1
  void clear()
  {
      q1.clear();
      return;
  }
//2
  void push(t item)
  {
      q1.enqueue(item);
//      if(q1.length())
//      {
//          int j=q1.length();
//          for(int i=0;i<j;i++)
//            q2.enqueue(q1.dequeue());
//      }
//      //swap(q1,q2);
//      int j=q2.length();
//      for(int i=0;i<j;i++)
//            q1.enqueue(q2.dequeue());
  }
  //3
  t pop()
  {
  // return q1.dequeue();
  t ret;
  int i,j=q1.length();
     for( i=0;i<j-1;i++)
            q2.enqueue(q1.dequeue());
            if(i==j-1)ret=q1.dequeue();
             j=q2.length();
         for(int i=0;i<j;i++)
            q1.enqueue(q2.dequeue());
            return ret;

  }

  void print()
  {
      q1.print();
//       int j=q1.length();
//          for(int i=0;i<j;i++)
//            q2.enqueue(q1.dequeue());
//      q2.print();
//      j=q2.length();
//      for(int i=0;i<j;i++)
//            q1.enqueue(q2.dequeue());

  }


};

