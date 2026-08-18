#include<iostream>
using namespace std;
template<typename t>

class list
{
    int x,size ,current,front,rear,maxsize;
    t* arr;

public :
list()
{
 x=5;
 size=0;
 current=0;
 front=1;
 rear=0;
 maxsize=x+1;
 arr= (t*)malloc(maxsize*sizeof(t));
    if(arr == NULL)
    {
        printf("error allocating memory..\n");
        return ;
    }

}
void init(int nai,int p,int ase)
{
    x=p;
    size=0;
    current=0;
    arr= (t*)malloc(x*sizeof(t));
    if(arr == NULL)
    {
        printf("error allocating memory..\n");
        return ;
    }
    for(int i=0;i<ase;i++)
    {
         t item;
         cin>>item;
         insert(item);
         current++;

    }
    current = 0;
    return;
}

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
        t el;
        cin>>el;
     insert(el);
     current++;
    }
    current=0;
    return;

}
void print()
{
    cout<<endl<<"<";
    for(int i=0;i<size;i++)
    {
        if(i==0)
        cout<<arr[(front+i)%maxsize];
        else
            cout<<","<<arr[(front+i)%maxsize];
    }
     cout<<">"<<endl;
//     printf("\n");
//int i;
//if(size==0)
//   {
//       printf("<>");
//     //  arr[size]=NULL;
//   }
//
//else{
//for(i=0;i<size;i++)
//{
//if(i==0 && current!=0)
//{
//    printf("<");
//    printf("%d",arr[i]);
//
//}
//else if(i==0 && current==0)
//{
//    printf("<");
//    printf("|");
//    printf("%d",arr[i]);
//
//}
//else if(i==current && current!=0)
//{
//    printf("|");
//    printf("%d",arr[i]);
//
//}
//else if(i==size-1){
//         printf(",");
//    printf("%d",arr[i]);
//
//}
//else{
//     printf(",");
//      printf("%d",arr[i]);
//}
//if(i==size-1 && size!=current)//jhamela
//    printf(">");
//
//}
// if(i==current)
//{
//      printf("|");
//       printf(">");
//}}
//  printf("\n");

}



//10
t getValue()
{
    if(size==0 || current>=size)
    {
        return -1;}
    return arr[(current+front)%maxsize];
}

//9
int moveToPos(int pos)
{
    if(pos>size)return -1;
    else
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

        current=0;
    }
   else{

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
t remov()
{
    t rmv;
    if(size==0)
       {

           return -1;
      }
      else if(current==0)
      {
          rmv=arr[front];
          front=(front+1)%maxsize;

      }
      else
      {
          rmv=arr[(front+current)%maxsize];
          //for(i=(front+current)%maxsize;i>(front+maxsize)%maxsize;i=(i+maxsize-1)%maxsize)
            for(int i=current;i>0;i--)
          {
           arr[(front+current)%maxsize]= arr[(front+current+maxsize-1)%maxsize]  ;
           front=(front+1)%maxsize;
          }

      }
//    int tem, rm=current;
//    if(size==0)
//       {
//
//           return -1;
//      }
//
//   else if(rm==size )
//       {return -1;}
//    else if(rm==size-1)
//    {
//
//
//      size--;
//
//      return arr[rm];
//
//    }
//    else
//    {
//        tem=arr[rm];
//    for(rm;rm<size;rm++)
//    {
//        arr[rm]=arr[rm+1];
//    }
   size--;

//   cout<<"front:"<<front<<endl;
//   cout<<"rear:"<<rear<<endl;
    return rmv;
//     }
}

//1
int insert(t item)
{
    if(size==x)
    {
        x=2*x;
        t* temp=new t[x+1];
        if(temp==NULL)
        {
            cout<<"cannot alocate memory"<<endl;
            return -1;
        }
        for(int i=0;i<size;i++)
        {
            temp[i+1]=arr[(front+i)%maxsize];
        }
        delete [] arr;
            arr=temp;
        front=1;
        rear=size;
        maxsize=x+1;
    }

    if(current==size)
    {
        rear=(front+current)%maxsize;
        arr[(front+current)%maxsize]=item;
//        rear=(rear+1)%maxsize;
    }
    else{

//        int pos=front+current;
        for(int i=rear;i>=((front+current)%maxsize);i=((maxsize+i-1)%maxsize))
        {
            arr[(i+1)%maxsize]=arr[i];

        }
        rear=(rear+1)%maxsize;
        arr[(front+current)%maxsize]=item;
    }

//    int i=size;
//
//  if (size == x)
//  {
//     int* temp;
//      x=2*x;
//      arr=(int*)realloc(arr,x*sizeof(int));
//
//  }
//
//    if(size==0)
//    {
//        arr[size]=item;
//        size++;
//    }
//    else{
//  for(i;i>=current;i--)
//  {
//      arr[i]=arr[i-1];
//  }
//  arr[current]=item;
//      size++;}

size ++;
// cout<<"front:"<<front<<endl;
//   cout<<"rear:"<<rear<<endl;
  return -1;

}
~list ()
{
    free(arr);
}
} ;



