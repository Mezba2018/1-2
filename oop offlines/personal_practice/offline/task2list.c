#include"list.h"
//#include"arr.h"
int clear()
{


    int len = size;
    moveToStart();
    for(int i=0;i<len;i++)
        remov();



    return -1;
}
int append(int item)
{
    int place=current;
    moveToEnd();
    next();
    insert(item);
    moveToPos(place);
    return-1;
}
int search(int item)
{
     int place=currPos();
    moveToStart();

    for(int i=0;i<size;i++)
    {
        if(item==getValue())
           {
              moveToPos(place);
             return 1;
           }
        next();
    }
  moveToPos(place);
   return -1;
}
int main()
{
   int k,p;
    printf("Enter the initial length of the list and the memory chunk size: ");
    scanf("%d %d",&k,&p);
    init(k,p);


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
                print();
                printf("\n%d\n",ret);
             break;

              case 2: scanf("%d",&item);
                ret=append(item);
                printf("\n");
                print();
                printf("\n%d\n",ret);
             break;
              case 3:  scanf("%d",&item);
                ret=search(item);
                 printf("\n");
                print();
                printf("\n%d\n",ret);
             break;

        }

    }while(task);
}
