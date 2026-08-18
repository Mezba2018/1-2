#include"queuelist.h"

int main()
{
    queue<int>q;
    q.print();

cout<<"0.exit"<<endl;
cout<<"1.enqueue(item)"<<endl;
cout<<"2.dequeue()"<<endl;
cout<<"3.length()"<<endl;
cout<<"4.front()"<<endl;
cout<<"5.back()"<<endl;
cout<<"6.is_empty()"<<endl;
cout<<"7.clear()"<<endl;
    while(true)
    {
        int ck,in,res;
        cin>>ck;
        switch(ck)
        {
            case 0: return 0;
            case 1:cin>>in;
            q.enqueue(in);
            q.print();
            break;
            case 2:res=q.dequeue();
            q.print();
            cout<<res<<endl;
            break;
            case 3: res=q.length();
            q.print();
            cout<<res<<endl;
            break;
            case 4:res=q.front();
            q.print();
            cout<<res<<endl;
            break;
            case 5:res=q.back();
            q.print();
            cout<<res<<endl;
            break;
            case 6:res=q.is_empty();

            q.print();
            if(res) cout<<"true"<<endl;
            else cout<<"false"<<endl;
            break;
            case 7:q.clear();
            q.print();
            break;

        }

    }

}
