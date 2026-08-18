#include"2105172_bst.cpp"

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
bst<int>tree;
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
         case 'd':
            cin>>el;
            int dpt=tree.depth(el);
            cout<<dpt<<endl;

    }
}



//fclose(stdin);
//fclose(stdout);
}
