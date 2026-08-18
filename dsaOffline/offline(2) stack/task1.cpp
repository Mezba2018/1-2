#include "stack.h"
int main()
{
     int k,p,test;
     cout<<"type 1 for integer,2 for character"<<endl;
     cin>>test;
    printf("Enter the memory chunk size & size of stack: ");
    scanf("%d %d",&p,&k);



    if(test==1)
    {
         list<int> l1;
         l1.init(p);
        for(int i=0;i<k;i++)
    {
        int el;
        cin>>el;
    l1.push(el);
     //current++;
    }
    l1.print();


    printf("\n1.clear\n");
printf("2.push\n");
printf("3.pop\n");
printf("4.length\n");
printf("5.topValue\n");
printf("6.isEmpty\n");

  int cs;
  int item,ret;
do
{
    cin>>cs;
    switch(cs){
        case 0:
        return 0;
        case 1: l1.clear();
        l1.print();
        //printf("%d\n",ret);
        break;
        case 2:cin>>item;
         l1.push(item);
         l1.print();
        //printf("%d\n",ret);
        break;

        case 3:ret=l1.pop();
        l1.print();
        printf("%d\n",ret);
        break;
        case 4: ret=l1.length();
            l1.print();
        printf("%d\n",ret);
        break;
        case 5:ret=l1.topValue();
        l1.print();
        printf("%d\n",ret);
        break;
        case 6:ret=l1.isEmpty();
        l1.print();
        if(ret==0) cout<<"false"<<endl;
        else cout<<"true"<<endl;
        break;

    }

}while(1);

    }
     if(test==2)
    {
         list<char> l1;
          l1.init(p);
        for(int i=0;i<k;i++)
    {
        char el;
        cin>>el;
     l1.push(el);
    }
     l1.print();


       printf("\n1.clear\n");
printf("2.push\n");
printf("3.pop\n");
printf("4.length\n");
printf("5.topValue\n");
printf("6.isEmpty\n");

  int cs;
  char item,ret;
  int rec;
do
{
    cin>>cs;
    switch(cs){
        case 0:
        return 0;
        case 1: l1.clear();
        l1.print();
        //printf("%d\n",ret);
        break;
        case 2:cin>>item;
         l1.push(item);
         l1.print();
        //printf("%d\n",ret);
        break;

        case 3:ret=l1.pop();
        l1.print();
        printf("%c\n",ret);
        break;
        case 4: rec=l1.length();
            l1.print();
        printf("%d\n",rec);
        break;
        case 5:ret=l1.topValue();
        l1.print();
        printf("%c\n",ret);
        break;
        case 6:rec=l1.isEmpty();
        l1.print();
        if(rec==0) cout<<"false"<<endl;
        else cout<<"true"<<endl;
        break;

    }

}while(1);





    }


}
