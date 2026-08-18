//#include"2105172_1_a_queue.cpp"
#include"2105172_1_ll_queue.cpp"
#include<string>

int main()
{
    queue<int> a,b,c;
    int cst,x;
    string ck,ch="egfewug";





        while(ck!="terminate")
        {
           cin>>ch;

             if(ch=="terminate")
                return 0;

           else if(ch=="enter")
           {

                cin>>cst;
                if(b.length()==c.length())
                    {
                        b.enqueue(cst);
                         cout<<"customer "<< cst <<" enters B queue"<<endl;
                    }
                else if(b.length()<c.length())
                      {
                        b.enqueue(cst);
                         cout<<"customer "<< cst <<" enters B queue"<<endl;
                    }
                else   {
                        c.enqueue(cst);
                         cout<<"customer "<< cst <<" enters C queue"<<endl;
                      }
        }



            else if(ch=="A")
            {cin>>ck;
            if(ck=="approve")
            {

                if(a.length()==0)
            cout<<"no customer"<<endl;
            else
            {
                x=a.dequeue();
                cout<<"customer "<< x <<" gets the loan"<<endl;

            }

            }
            }

            else if(ch=="B"){cin>>ck;
            if(ck=="approve")
            {
                if(b.length()==0)
            cout<<"no customer"<<endl;
                else{
                cout<<"approve from B"<<endl;
            x=b.dequeue();
            cout<<"customer "<< x <<" enters A queue"<<endl;
            a.enqueue(x);}
            }
                else if(ck=="reject")
                {
                if(b.length()==0)
            cout<<"no customer"<<endl;
            else{
                    cout<<"reject from B"<<endl;
            x=b.dequeue();
             if(b.length()==c.length())
                    {
                        c.enqueue(cst);
                         cout<<"customer "<< x <<" enters C queue"<<endl;
                    }
                else if(b.length()>c.length())
                      {
                        b.enqueue(cst);
                         cout<<"customer "<< x <<" enters B queue"<<endl;
                    }
                else   {
                        c.enqueue(cst);
                         cout<<"customer "<< x <<" enters C queue"<<endl;
                      }

            }
            }
            }

            if(ch=="C"){cin>>ck;
            if(ck=="approve")
            {

                if(c.length()==0)
            cout<<"no customer"<<endl;
                else{
                cout<<"approve from C"<<endl;
            x=c.dequeue();
            cout<<"customer "<< x <<" enters A queue"<<endl;
            a.enqueue(x);}
            }
                else if(ck=="reject")
                {
                if(c.length()==0)
            cout<<"no customer"<<endl;
            else{
                    cout<<"reject from C"<<endl;
            x=c.dequeue();
             if(b.length()==c.length())
                    {
                        b.enqueue(cst);
                         cout<<"customer "<< x <<" enters B queue"<<endl;
                    }
                else if(b.length()>c.length())
                      {
                        b.enqueue(cst);
                         cout<<"customer "<< x <<" enters B queue"<<endl;
                    }
                else   {
                        c.enqueue(cst);
                         cout<<"customer "<< x <<" enters C queue"<<endl;
                      }

            }}
            }

            }
        }

