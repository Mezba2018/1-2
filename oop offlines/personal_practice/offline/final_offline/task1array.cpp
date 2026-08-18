#include<iostream>
using namespace std;

class list
{
    int x,size = 0,current= 0;
    int* arr;

public :
void init(int nai,int p,int ase)
{
    x=p;
    size=0;
    current=0;
    arr= (int*)malloc(x*sizeof(int));
    if(arr == NULL)
    {
        printf("error allocating memory..\n");
        return ;
    }
    for(int i=0;i<ase;i++)
    {
         int item;
         cin>>item;
         insert(item);
         current++;

    }
    current = 0;
    return;
}
/*int clear()
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
}*/
void init(int k,int p)
{
    x = p;
    arr= (int*)malloc(x*sizeof(int));
    if(arr == NULL)
    {
        printf("error allocating memory..\n");
        return ;
    }
   for(int i=0;i<k;i++)
    {
        int el;
        cin>>el;
     insert(el);
     current++;
    }
    current=0;
    return;

}
void print()
{
     printf("\n");
int i;
if(size==0)
   {
       printf("<>");
     //  arr[size]=NULL;
   }

else{
for(i=0;i<size;i++)
{
if(i==0 && current!=0)
{
    printf("<");
    printf("%d",arr[i]);

}
else if(i==0 && current==0)
{
    printf("<");
    printf("|");
    printf("%d",arr[i]);

}
else if(i==current && current!=0)
{
    printf("|");
    printf("%d",arr[i]);

}
else if(i==size-1){
         printf(",");
    printf("%d",arr[i]);

}
else{
     printf(",");
      printf("%d",arr[i]);
}
if(i==size-1 && size!=current)//jhamela
    printf(">");

}
 if(i==current)
{
      printf("|");
       printf(">");
}}
  printf("\n");

}



//10
int getValue()
{
    if(size==0 || current>=size)
    {
        return -1;}
    return arr[current];
}

//9
int moveToPos(int pos)
{
    current=pos;

    return -1;
}



//8
int next()
{

    if(current>=size)
    {

       return -1;
    }

     else
         current++;

   return -1;
}

//7
int prev()
{
    current--;
    if(current<0)
    {
      // printf("invalid operation");
        current=0;
    }
   else{
    /* printf("\n");
    print();*/
   }

   return -1;
}



//6
int currPos()
{

return current;
}



//5
int length()
{

  return size;
}


//4
int moveToEnd()
{
    current=size-1;

      return -1;
}

//3
int moveToStart()
{
    current=0;

    return -1;

}


//2
int remov()
{
    int tem, rm=current;
    if(size==0)
       {

           return -1;
      }

   else if(rm==size )
       {return -1;}
    else if(rm==size-1)
    {

     // current--;
      size--;

      return arr[rm];

    }
    else
    {
        tem=arr[rm];
    for(rm;rm<size;rm++)
    {
        arr[rm]=arr[rm+1];
    }
    size--;
    return tem;
    }
}

//1
int insert(int item)
{
    /*if(size==0)
        size=1;*/
    int i=size;

  if (size == x)
  {
     int* temp;
      x=2*x;
      arr=(int*)realloc(arr,x*sizeof(int));
    /* temp=malloc(x*sizeof(int));
     if(temp == NULL)
     {
        printf("error allocating memory\n");
        return 1;
     }
     for(int j=0;j<size;j++)
        temp[j]=arr[j];
     free(arr);
     arr=temp;*/

  }

    if(size==0)
    {
        arr[size]=item;
        size++;
    }
    else{
  for(i;i>=current;i--)
  {
      arr[i]=arr[i-1];
  }
  arr[current]=item;
      size++;}


  return -1;

}
~list ()
{
    free(arr);
}
} ;







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
