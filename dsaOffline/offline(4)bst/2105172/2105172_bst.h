#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
struct node{
T val;
node<T>* left;
node<T>* right;
};


template<typename T>
class bst{
    node<T>* rootptr;

    //1
     void insert( node<T>*& root,T data);
    //6
     void inorder(node<T>* root);

    //2
     void preorder(node<T>* root);

    //7
      void postorder(node<T>* root);

    //3
         node<T>* find(node<T>*& root,T element);

    //...
     node<T>* findmin(node<T>* root);

    //4
    void Delete(node<T>*& root,T element);

    //5
    void print(node<T>*& root);
    void destroy(node<T>* root);


public:
    bst();
    ~bst();


    //1
    void insert(T data);
   //2
    void inorder();
     //6
    void preorder();
    //7
    void postorder();
    //3
    node<T>* find(T element);
   //4
    void Delete(T element);
    //5
    void print();
    int depth(T element);

};
