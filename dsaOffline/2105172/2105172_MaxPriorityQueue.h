#include <iostream>
using namespace std;
template <typename t>
class MaxPriorityQueue
{

    t *heap;
    int chunk, size;

    // pr1
    void heapifyUp(int index);
    

    // pr2
    void heapifyDown(int index);


public:
    MaxPriorityQueue(int initialCapacity=10);

    ~MaxPriorityQueue();
   
    // 1
    void Insert(t el);
   

    // 2
    t FindMax();
   

    // 3
    t ExtractMax();
    
    // 4
    void IncreaseKey(int i, t newKey);
   

    // 5
    void DecreaseKey(int i, t newKey);


    // 6
    void sort();
  

    // 7
    void print();
    
};
