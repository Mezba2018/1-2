#include"list.h"
//#include "array.h"
#include<cstring>

int main()
{
    int a,b,c;
    cin >>a;
    cin>>b;
    cin>>c;
    //cout<<endl;
    list garage[b];
    for(int i=0;i<b;i++)
    {
        garage[i].init(c);
    }
    for(int i=0;i<b;i++)
    {
      /*  char line[100];
        int j,cnt=0,nmb=0,index=0;
        int k=0;
       // cin >> index;
        /*getchar(); // Consume the newline character

        scanf("%[^\n]s", line);
        getchar(); // Consume the newline character

      // printf("%s\n",line);
       //printf("%d\n",strlen(line));
       //break;

        for(j=0;j<strlen(line);j++)
        {
            /*while(line[j]==' ')
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
           // index=index-1;
            }
             while(cnt==1 && line[j]!=' ')
            {
                int temp=line[j]-'0';
                nmb=nmb*10+temp;
                j++;
                cnt = 2;
            }
            if(cnt==2)
            {
             //garage[index-1].insert(nmb);
             //garage[index-1].next();
             cout << nmb<<endl;;
             cnt=1;
             nmb = 0;
            }
            if(line[j] == ' ')
                 continue;
            else if( cnt == 0)
            {
                int temp = line[j] - '0';


            }*/



        }
        garage[index-1].moveToStart();
}


   for(int i=0;i<b;i++)
    {
        garage[i].print();
    }
}



