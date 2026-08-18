#include<iostream>
using namespace std;

struct node{
int val;
node *left,*right;

node(int data)
{
    val=data;
    left=NULL;
    right=NULL;
}
};

node* insert(node*root,int data)
{
    if(root==NULL)
    {
        return new node(data);
    }
    if(data < root->val)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}
node* search(node *root,int element)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->val==element)
    {
        return root;
    } if(root->val>element)
    {
        return search(root->left,element);
    }
    else return search(root->right,element);


}
node* findmin(node* root)
{
   // root=root->right;
    while(root->left)
        root=root->left;
    return root;
}
node* Delete(node* root,int element)
{
    if(root==NULL) return root;
    else if(element>root->val) root->right=Delete(root->right,element);
        else if(element<root->val) root->left=Delete(root->left,element);
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
            else{
                node*temp=findmin(root->right);
                root->val=temp->val;
                root->right=Delete(root->right,temp->val);

            }
        }
        return root;

}
int main()
{
    node* root=NULL;
    root=insert(root,5);
    insert(root,3);
     insert(root,9);
      insert(root,0);
       insert(root,4);
        insert(root,7);
         insert(root,10);
           // insert(root,9);


       inorder(root);
       if(search(root,9)==NULL)
        cout<<"doesn't exist"<<endl;
       else cout<<"exists"<<endl;
       Delete(root,5);
          inorder(root);

}
