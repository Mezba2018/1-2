#include"stack.h"
int main()
{
    cout<<"Enter your data type"<<endl<<"1.int"<<endl<<"2.double"<<endl<<"3.char"<<endl;
   int dt;
   cin>>dt;
   if(dt==1)
   {
    stack<int> q;
    q.print();

cout<<"0.exit"<<endl;
cout<<"1.push(item)"<<endl;
cout<<"2.pop()"<<endl;
cout<<"3.length()"<<endl;
cout<<"4.topValue()"<<endl;
cout<<"5.isEmpty()"<<endl;
cout<<"6.clear()"<<endl;
while(true)
{
    int ck;
    int in,res;
        cin>>ck;
        switch(ck)
        {
            case 0: return 0;
            case 1:cin>>in;
            q.push(in);
            q.print();
            break;
            case 2:res=q.pop();
            q.print();
            cout<<res<<endl;
            break;
            case 3: res=q.length();
            q.print();
            //
            cout<<res<<endl;
            break;
            case 4:res=q.topValue();
            q.print();
            cout<<res<<endl;
            break;

            case 5:res=q.isEmpty();
             //
            q.print();
            if(res) cout<<"true"<<endl;
            else cout<<"false"<<endl;
            break;
            case 6:q.clear();
            q.print();
            break;

        }

}

}
else if(dt==2)
{
    stack<double> q;
    q.print();

cout<<"0.exit"<<endl;
cout<<"1.push(item)"<<endl;
cout<<"2.pop()"<<endl;
cout<<"3.length()"<<endl;
cout<<"4.topValue()"<<endl;
cout<<"5.isEmpty()"<<endl;
cout<<"6.clear()"<<endl;
while(true)
{
    int ck,left;
    double in,res;
        cin>>ck;
        switch(ck)
        {
            case 0: return 0;
            case 1:cin>>in;
            q.push(in);
            q.print();
            break;
            case 2:res=q.pop();
            q.print();
            cout<<res<<endl;
            break;
            case 3: left=q.length();
            q.print();
            //
            cout<<left<<endl;
            break;
            case 4:res=q.topValue();
            q.print();
            cout<<res<<endl;
            break;

            case 5:left=q.isEmpty();
             //
            q.print();
            if(left) cout<<"true"<<endl;
            else cout<<"false"<<endl;
            break;
            case 6:q.clear();
            q.print();
            break;

        }
}

}
else if(dt==3)
{
    stack<char> q;
    q.print();

cout<<"0.exit"<<endl;
cout<<"1.push(item)"<<endl;
cout<<"2.pop()"<<endl;
cout<<"3.length()"<<endl;
cout<<"4.topValue()"<<endl;
cout<<"5.isEmpty()"<<endl;
cout<<"6.clear()"<<endl;
while(true)
{
    int ck,left;
    char in,res;

        cin>>ck;
        switch(ck)
        {
            case 0: return 0;
            case 1:cin>>in;
            q.push(in);
            q.print();
            break;
            case 2:res=q.pop();
            q.print();
            cout<<res<<endl;
            break;
            case 3: left=q.length();
            q.print();
            //
            cout<<left<<endl;
            break;
            case 4:res=q.topValue();
            q.print();
            cout<<res<<endl;
            break;

            case 5:left=q.isEmpty();
             //
            q.print();
            if(left) cout<<"true"<<endl;
            else cout<<"false"<<endl;
            break;
            case 6:q.clear();
            q.print();
            break;

        }
}

}
else
{
   cout<<"invalid operation"<<endl;
return 0;
}

}
