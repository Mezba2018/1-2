#include "2105172_bst.h"
using namespace std;




    //1
    template<typename T>
     void bst<T>:: insert( node<T>*& root,T data)
    {
        if(root==NULL)
        {
            node<T>* temp=new node<T>;
            temp->val=data;
            temp->left=NULL;
            temp->right=NULL;
            root=temp;
        }
        else if(data<root->val)
            insert(root->left,data);
        else
            insert(root->right,data);

    }





    //2
    template<typename T>
     void bst<T>:: inorder(node<T>* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
       // cout<<endl;
    }




    //3
    template<typename T>
     void bst<T>:: preorder(node<T>* root)
    {
        if(root==NULL)
            return;
             cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
       // cout<<endl;
    }




    //4
    template<typename T>
      void bst<T>:: postorder(node<T>* root)
    {
        if(root==NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
       // cout<<endl;
    }






    //3
    template<typename T>
         node<T>* bst<T>:: find(node<T>*& root,T element)
{


        if(root==NULL)
        {
            //cout<<endl;
//            cout<<"not found"<<endl;
            return NULL;

        }
        if(root->val==element)
        {
           // cout<<endl;
         //cout<<"found"<<endl;
          return root;
        }
        if(element<root->val)
            find(root->left,element);
        else
            find(root->right,element);

    }




    //...
    template<typename T>
     node<T>* bst<T>:: findmin(node<T>* root)
    {
    while(root->left)
        root=root->left;
    return root;
}




    //4
    template<typename T>
    void bst<T>:: Delete(node<T>*& root,T element)
    {  
        if(root==NULL) return;
        if(element<root->val)
            Delete(root->left,element);
            else if (element>root->val)
                Delete(root->right,element);
        else
            {
                if(root->left==NULL)
                {
                  node<T>* temp=root;
                    root=root->right;
                    delete temp;
                }
                else if(root->right==NULL)
                {
                    node<T>* temp=root;
                root=root->left;
                delete temp;

                }
                else
                {
                 node<T>* temp=findmin(root->right);
                 root->val=temp->val;
                Delete(root->right,temp->val);


                }

            }

    }



    //5
    template<typename T>
    void bst<T>:: print()
    {
        cout<<"(";
        if(rootptr==NULL)
        {
             cout<<")";
             cout<<endl;
             return;
        }
        cout<<rootptr->val;
        print(rootptr);
        cout<<")";
        cout <<"\n";
    }

    //5
    template<typename T>
    void bst<T>:: print(node<T>*& root)
    {

        if(root->left==NULL && root->right==NULL)
        {
            return;
        }
        else if (root->left==NULL && root->right!=NULL)
        {
            cout<<"(";
            cout<<",";
            cout<<root->right->val;
            print(root->right);
            cout<<")";

        }
        else if (root->left!=NULL && root->right==NULL)
        {
            cout<<"(";
            cout<<root->left->val;
            print(root->left);
            cout<<",";
            cout<<")";

        }
        else if (root->left!=NULL && root->right!=NULL)
        {
            cout<<"(";
            cout<<root->left->val;
            print(root->left);
            cout<<",";
            cout<<root->right->val;
            print(root->right);
            cout<<")";
        }

    }






    //constructor
template<typename T>

 bst<T>::bst()
    {
        rootptr=NULL;
    }

    template<typename T>

 bst<T>::~bst()
 {
     destroy(rootptr);
 }
  template<typename T>
 void bst<T>::destroy(node<T>* root)
 {
     if(root==NULL)
        return;

     destroy(root->left);
     destroy(root->right);

     delete root;
 }

    //1
    template<typename T>
    void bst<T>:: insert(T data)
    {
        insert(rootptr,data);
    }



   //2
   template<typename T>
     void bst<T>:: inorder() {
      inorder(rootptr);
      cout <<endl;
    }



    //7
    template<typename T>
    void bst<T>:: preorder() {
      preorder(rootptr);
      cout <<"\n";
    }



    //6
    template<typename T>
    void bst<T>:: postorder() {
      postorder(rootptr);
      cout <<"\n";
    }



    //3
    template<typename T>
    node<T>* bst<T>:: find(T element)
    {
       return find (rootptr,element);
    }




    //4
    template<typename T>
    void bst<T>:: Delete(T element)
    {
       Delete(rootptr,element);
    }




    template<typename T>
    int bst<T>::depth(T element)
    {
        int x=0;
        node<T>* test=find(rootptr,element);
        if(test==NULL)
            return x;;
        while(test->left!=NULL)
        {
            x++;
            test=test->left;
        }
        while(test->right!=NULL)
        {
            x++;
            test=test->right;
        }
        return x;

    }



