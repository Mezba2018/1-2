#include<stdio.h>
#include<stdlib.h>
int x,size = 0,current= 0;
 int* arr;

void init(int k,int p)
{
    x=p;
    size = k;
    arr= malloc(x*sizeof(int));
    if(arr == NULL)
    {
        printf("error allocating memory..\n");
        return ;
    }
    input();
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


void input()
{
    int i;

    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i] );
    }
   /* for(i=0;i<size;i++)
    {
        printf("%d \t",arr[i] );
    }*/
  print();

}



//10
int getValue()
{
    if(size==0 || current>=size)
    { print();
        return -1;}
    return arr[current];
}

//9
int moveToPos(int pos)
{
    current=pos;
    print();
    return -1;
}



//8
int next()
{

    if(current>=size)
    {
        print();
       return -1;
    }

     else
         current++;
         print();
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
   print();
   return -1;
}



//6
int currPos()
{
    print();
return current;
}



//5
int length()
{
    print();
  return size;
}


//4
int moveToEnd()
{
    current=size-1;
    print();
      return -1;
}

//3
int moveToStart()
{
    current=0;
    print();
    return -1;

}


//2
int remov()
{
    int tem, rm=current;
    if(size==0)
       {
           print();
           return -1;
      }

   else if(rm==size )
       {print();return -1;}
    else if(rm==size-1)
    {

     // current--;
      size--;
      print();
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
print();
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

print();
  return -1;

}
void freed()
{
    free(arr);
}


int main()
{

   int k,p;
    printf("Enter the initial length of the list and the memory chunk size: ");
    scanf("%d %d",&k,&p);
    init(k,p);


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
    case 0: freed();
        return 0;
    case 1:
  scanf("%d",&item);
  ret=insert(item);

        printf("%d\n",ret);
        break;
     case 2:
          ret=remov();

         printf("%d\n",ret);
          break;
      case 3:
         ret= moveToStart();

        printf("%d\n",ret);
           break;
      case 4:
          ret=moveToEnd();

         printf("%d\n",ret);
           break;
      case 5:
           ret=length();

         printf("%d\n",ret);
           break;
      case 6:
          ret=currPos();

         printf("%d\n",ret);
           break;
      case 7:
          ret=prev();

         printf("%d\n",ret);
           break;
    case 8:
         ret= next();

        printf("%d\n",ret);
           break;
    case 9:

  scanf("%d",&pos);
  ret=moveToPos(pos);

        printf("%d\n",ret);
           break;
    case 10:
        ret= getValue();

         printf("%d\n",ret);
           break;
}
}
while(test!=0);



}

