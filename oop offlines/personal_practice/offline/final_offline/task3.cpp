//#include"list.h"
#include "array.h"
#include<cstring>
int main()
{

       int a,b,c,index,cnt;
       cout<<"total cars"<<endl;
    cin >>a;
    cout<<"total garage"<<endl;
    cin>>b;
    cout<<"maximum parking slot "<<endl;
    cin>>c;
     list garage[b+1];
    cout<<"input method: (garage no)" << "(parked cars)" << " (cars no) "<< endl<<endl;

    /* for(int i=1;i<=b;i++)
     {
         garage[i].init(i,c,2);

      garage[i].print();

     }*/

    for(int i=0;i<b;i++)
    {
        cin>>index>>cnt;
       garage[index].init(index,c,cnt);
      //garage[index].print();
    }
  for(int i=1;i<=b;i++)
        garage[i].print();

        char test[10];
        int ck;
        do{
                scanf("%s",test);
        getchar();
ck=strcmp(test,"end");
int m=strcmp(test,"req");
int n=strcmp(test,"ret");
                if(m==0)
                {//request
                    int i;

                    for( i=1;i<=b;i++)
                    {
                        if(garage[i].length()>=1)
                            break;
                        // if(i==b)
                            //break;

                        else continue;
                    }
                   if(i==b+1)
                   {
                     cout<<"no cars available" <<endl;
                   }

                   else
                   {
                       garage[i].moveToStart();
                       int serial=0,temp=garage[i].getValue();
                       for(int j=1;j<garage[i].length();j++)
                       {
                           garage[i].next();
                           if(temp>garage[i].getValue())
                           {
                               serial=garage[i].currPos();
                               temp=garage[i].getValue();
                           }

                       }
                        garage[i].moveToPos(serial);
                       //small number & its location
                      garage[i].remov();
                      garage[i].moveToStart();
                     // garage[i].print();
                     for(int k=1;k<=b;k++)
                        garage[k].print();
                   }

               //req
                }

if(n==0)
            {
                //return
                int add;
                cin>>add;
        int i=0;
       // n++;
        for(i=b;i>=1;i--)
        {

        if(garage[i].length()<c)
        break;
        else continue;

        }
         if(i==0)
                   {
                     cout<<"no slot available" <<endl;
                   }
        else
            {
            garage[i].moveToStart();
                       int serial=0,temp=garage[i].getValue();
                       for(int j=1;j<garage[i].length();j++)
                       {
                           garage[i].next();
                           if(temp<garage[i].getValue())
                           {
                               serial=garage[i].currPos();
                               temp=garage[i].getValue();
                           }
                       }
                        garage[i].moveToPos(serial);
                        garage[i].next();
                       //small number & its location
                      garage[i].insert(add);
                       garage[i].moveToStart();
                      //garage[i].print();
                      for(int k=1;k<=b;k++)
                        garage[k].print();
            }

//return
           }

}
while(ck);

}
