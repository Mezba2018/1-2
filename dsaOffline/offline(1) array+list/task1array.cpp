#include "array.h"
//#include "list.h"


int main()
{

   int k,p;
    printf("Enter the initial length of the list and the memory chunk size: ");
    scanf("%d %d",&k,&p);
    list l1;
    l1.init(k,p);
    l1.print();


printf("\n1.insert\n");
printf("2.remove\n");
printf("3.move to start\n");
printf("4.move to end\n");
printf("5.length\n");
printf("6.current position\n");
printf("7.previous position\n");
printf("8.next position\n");
printf("9.move to position\n");
printf("10.get value\n");



int test;
do{
scanf("%d",&test);

switch(test)
{
    int ret,item,pos;
    case 0:
        return 0;
    case 1:
  scanf("%d",&item);
  ret=l1.insert(item);
l1.print();
        printf("%d\n",ret);
        break;
     case 2:
          ret=l1.remov();
l1.print();
         printf("%d\n",ret);
          break;
      case 3:
         ret= l1.moveToStart();
l1.print();
        printf("%d\n",ret);
           break;
      case 4:
          ret=l1.moveToEnd();
l1.print();
         printf("%d\n",ret);
           break;
      case 5:
           ret=l1.length();
l1.print();
         printf("%d\n",ret);
           break;
      case 6:
          ret=l1.currPos();
l1.print();
         printf("%d\n",ret);
           break;
      case 7:
          ret=l1.prev();
l1.print();
         printf("%d\n",ret);
           break;
    case 8:
         ret= l1.next();
l1.print();
        printf("%d\n",ret);
           break;
    case 9:

  scanf("%d",&pos);
  ret=l1.moveToPos(pos);
l1.print();
        printf("%d\n",ret);
           break;
    case 10:
        ret= l1.getValue();
l1.print();
         printf("%d\n",ret);
           break;
}
}
while(test!=0);



}
