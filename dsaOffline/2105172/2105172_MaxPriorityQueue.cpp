#include"2105172_MaxpriorityQueue.h"
using namespace std;

template<typename t>
void MaxPriorityQueue<t>:: heapifyUp(int index)
{
        int parent = index / 2;
        if(parent==0){
            return;
        }
        // while (parent > 0 && heap[index] > heap[parent])
        // {
        //     swap(heap[index], heap[parent]);
        //     index = parent;
        //     parent = index / 2;
        // }
        int big=parent;
        if(parent!=0 && heap[index]>heap[parent])
        {
            big=index;
        }
        if(big!=parent)
        {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }




template<typename t>
void MaxPriorityQueue<t>::heapifyDown(int index)
    {
        int leftchild = index * 2;
        int rightchild = index * 2 + 1;
        int largest = index;
        if (leftchild <= size && heap[largest] < heap[leftchild])
        {
            largest = leftchild;
        }
        if (rightchild <= size && heap[largest] < heap[rightchild])
        {
            largest = rightchild;
        }
        if (largest != index)
        {
            swap(heap[largest], heap[index]);
            heapifyDown(largest);
        }
    }









template<typename t>
MaxPriorityQueue<t>::MaxPriorityQueue(int initialCapacity)
    {
        chunk = initialCapacity + 1;
        size = 0;
        heap = new t[chunk];
    }





template<typename t>
MaxPriorityQueue<t>::~MaxPriorityQueue()
    {
        delete[] heap;
    }







template<typename t>
void MaxPriorityQueue<t>:: Insert(t el)
 {
        if (size == chunk - 1)
        {
            chunk *= 2;
            t *newheap = new t[chunk];
            for (int i = 1; i <= size; i++)
            {
                newheap[i] = heap[i];
            }
            delete[] heap;
            heap = newheap;
        }
        size++;
        heap[size] = el;
        heapifyUp(size);
    }






template<typename t>
t MaxPriorityQueue<t>::FindMax()
    {
        if (size == 0)
        {
            cout << "Priority queue is empty." << endl;
            return -1;
        }
        return heap[1];

    }





template<typename t>
t MaxPriorityQueue<t>:: ExtractMax()
    {
        if (size == 0)
        {
            cout << "Priority queue is empty." << endl;
            return -1;
        }
        t max = heap[1];
        heap[1] = heap[size];
        size-- ;
        heapifyDown(1);
        return max;
    }






template<typename t>
void MaxPriorityQueue<t>::IncreaseKey(int i, t newKey)
    {

        if (heap[i] > newKey)
        {
            cout << "New key is not larger than the previous key" << endl;
            return;
        }
        heap[i] = newKey;
        heapifyUp(i);
        cout << "Key increased!" << endl;
    }




template<typename t>
void MaxPriorityQueue<t>::DecreaseKey(int i, t newKey)
    {

        if (heap[i] < newKey)
        {
            cout << "New key is not smaller than the previous key" << endl;
            return;
        }
        heap[i] = newKey;
        heapifyDown(i);
        cout << "Key decreased!" << endl;
    }




template<typename t>
void MaxPriorityQueue<t>::sort()
    {
        int remain = size;
        if (size != 0)
        {
            for (int i = 1; i < remain; i++)
            {
                swap(heap[size], heap[1]);
                size--;
                heapifyDown(1);
            }
        }
        size = remain;
        return;
    }




template<typename t>
void MaxPriorityQueue<t>::print()
    {
        cout << "No of elements: " << size << endl;
        int index = 1;
        int left = index * 2;
        bool ck = true;
        if (size != 0)
        {
            while (ck)
            {
                for (index; index < left; index++)
                {
                    if (index == 1)
                        cout << heap[index];
                    else
                        cout << heap[index] << "\t";
                    if (index == size)
                    {
                        ck = false;
                        break;
                    }
                }
                cout << endl;
                left = index * 2;
            }
        }
        else
        {
            // to do
        }
    }