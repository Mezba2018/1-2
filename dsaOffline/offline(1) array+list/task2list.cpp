#include"list.h"
//#include"array.h"


list l1;
int clear()
{


    int len = l1.length();
    l1.moveToStart();
    for(int i=0;i<len;i++)
        l1.remov();



    return -1;
}
int append(int item)
{
    int place=l1.currPos();
    l1.moveToEnd();
    l1.next();
    l1.insert(item);
    l1.moveToPos(place);
    return-1;
}
int search(int item)
{
     int place=l1.currPos();
    l1.moveToStart();

    for(int i=0;i<l1.length();i++)
    {
        if(item==l1.getValue())
           {
              l1.moveToPos(place);
             return 1;
           }
        l1.next();
    }
  l1.moveToPos(place);
   return -1;
}
int main()
{
   int k,p;
    printf("Enter the initial length of the list and the memory chunk size: ");
    scanf("%d %d",&k,&p);
    l1.init(k,p);
    l1.print();


printf("\n1.clear\n");
printf("2.append\n");
printf("3.search\n");

    int task;
    do{
        scanf("%d",&task);
        switch(task)
        {
             int ret,item,pos;
            case 0:
                 return 0;
              case 1: ret=clear();
                printf("\n");
                l1.print();
                printf("\n%d\n",ret);
             break;

              case 2: scanf("%d",&item);
                ret=append(item);
                printf("\n");
                l1.print();
                printf("\n%d\n",ret);
             break;
              case 3:  scanf("%d",&item);
                ret=search(item);
                 printf("\n");
                l1.print();
                printf("\n%d\n",ret);
             break;

        }

    }while(task);
}

