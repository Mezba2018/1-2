#include<iostream>
#include<cstring>
using namespace std;

struct node{
int val;
node* left;
node* right;
};



class bst{
    node* rootptr;

    //1
     void insert( node*& root,int data)
    {
        if(root==NULL)
        {
            node* temp=new node;
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
     void inorder(node* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
       // cout<<endl;
    }
    //3
     void preorder(node* root)
    {
        if(root==NULL)
            return;
             cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
       // cout<<endl;
    }
    //4
      void postorder(node* root)
    {
        if(root==NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
       // cout<<endl;
    }



    //3
         bool find(node*& root,int element)
{


        if(root==NULL)
        {
            //cout<<endl;
//            cout<<"not found"<<endl;
            return false;

        }
        if(root->val==element)
        {
           // cout<<endl;
         //cout<<"found"<<endl;
          return true;
        }
        if(element<root->val)
            find(root->left,element);
        else
            find(root->right,element);

    }
    //...
     node* findmin(node* root)
    {
    while(root->left)
        root=root->left;
    return root;
}
    //4
    void Delete(node*& root,int element)
    {
        if(root==NULL) return;
        if(element<root->val)
            Delete(root->left,element);
            else if (element>root->val)Delete(root->right,element);
        else
            {
                if(root->left==NULL)
                {
                  node* temp=root;
                    root=root->right;
                    delete temp;
                }
                else if(root->right==NULL)
                {
                    node* temp=root;
                root=root->left;
                delete temp;

                }
                else
                {
                 node*temp=findmin(root->right);
                 root->val=temp->val;
                Delete(root->right,temp->val);


                }

            }

    }
    //5
    void print(node*& root)
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


public:
    bst()
    {
        rootptr=NULL;
    }
    //1
    void insert(int data)
    {
        insert(rootptr,data);
    }
   //2
     void inorder() {
      inorder(rootptr);
      cout <<endl;
    }
    void preorder() {
      preorder(rootptr);
      cout <<"\n";
    }
    void postorder() {
      postorder(rootptr);
      cout <<"\n";
    }
    //3
    bool find(int element)
    {
       return find (rootptr,element);
    }




    //4
    void Delete(int element)
    {
       Delete(rootptr,element);
    }
    //5
    void print()
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

};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
bst tree;
char ck,str[10];
//cout<<"I for enter"<<endl;
//cout<<"D for delete"<<endl;
//cout<<"F for find"<<endl;
//cout<<"T for traversal"<<endl;
while(cin>>ck)
{
    int el;


    switch(ck)
    {
       case 'I':
           cin>>el;
           tree.insert(el);
           tree.print();
        break;
        case 'D':
            cin>>el;
            tree.Delete(el);
             tree.print();

        break;
        case 'F':
            cin>>el;
            if(tree.find(el))
                 cout<<"found"<<endl;
            else  cout<<"not found"<<endl;
            // tree.print();
        break;
        case 'T':
            cin>>str;
            if(!strcmp(str,"Pre"))
                tree.preorder();
            if(!strcmp(str,"Post"))
                tree.postorder();
                if(!strcmp(str,"In"))
                tree.inorder();

        break;

    }
}



fclose(stdin);
fclose(stdout);
}
