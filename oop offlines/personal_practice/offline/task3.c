//#include"list.h"
#include "array.h"

int main()
{
    int a,b,c;
    cin >>a;
    cin>>b;
    cin>>c;
    list garage[b];
    for(int i=0;i<b;i++)
    {
        init(0,c);
    }
    for(int i=0;i<b;i++)
    {
        int cnt=0,nmb,index=0;
        char line[1000];
        cin.getline(line,1000);
        if(int j=0;j<sizeof(line);j++)
        {
            while(line[j]==' ')
                j++;
            while(cnt==0 && line[j]!=' ')
            {
                int temp=line[j]-'0';
                index=index*10+temp;
                j++;
            }
            if(cnt==0 && index!=0)
            {
                cnt=1;
            index=index-1;
            }
             while(cnt==1 && line[j]!=' ')
            {
                int temp=line[j]-'0';
                nmb=nmb*10+temp;
                j++;
            }
            garage[index].insert(nmb);
             garage[index].next();


        }
        garage[index].moveToStart();
    }

    for(int i=0;i<b;i++)
    {
        garage[i].print();
    }
}


