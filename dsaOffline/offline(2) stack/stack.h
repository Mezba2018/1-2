#include<iostream>
#include<cstdlib>
using namespace std;
template <typename t>

class list{
 int x,chunk,size = 0,current=0,cnt=0;
    t* arr;
public:

void init(int p)
{
    x = p;
    chunk=p;
    arr= new t[x];
    if(arr == NULL)
    {
        printf("error allocating memory..\n");
        return ;
    }


    return;

}
void push(t item)
{
    current++;

  if (size == x)
  {
      x=2*x;
     //t* temp;
   arr=(t*)realloc(arr,x*sizeof(t));
   if(arr==NULL)
   {
       cout<<"error allocation";
       return ;
   }
  }
  if(size==0)
   {
       current=0;
    arr[current]=item;
     size++;
   }
     else
     {
          arr[current]=item;
     size++;
     }

  return ;

}
t pop()
{

    t rm=arr[current];
     current--;
    if(size==0)
       {

          // return -1;
          if(cnt==0)
          cout<<"nothing to pop"<<endl;
          if(cnt==1)cnt=0;
          return -1;
      }

   //else if(rm==size )
       //{return -1;}
    else
    {

     // current--;
      size--;

      return rm;

    }

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
    //printf("%d",arr[i]);
    cout<<arr[i];

}
else if(i==0 && current==0)
{
    printf("<");
    printf("|");
    //printf("%d",arr[i]);
     cout<<arr[i];

}
else if(i==current && current!=0)
{
    printf("|");
   // printf("%d",arr[i]);
    cout<<arr[i];

}
else if(i==size-1){
         printf(",");
 //   printf("%d",arr[i]);
  cout<<arr[i];

}
else{
     printf(",");
     // printf("%d",arr[i]);
      cout<<arr[i];
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
void clear()
{
    cnt++;
    for(int i=size;i>=0;i--)
    {
        pop();
    }

}
int length()
{
    return size;
}
t topValue()
{

    if(size==0 || current>=size)
    {
        return -1;
    }
   else return arr[current];
}
bool isEmpty()
{
    if (size==0) return true;
    else return false;
}

~list ()
{
    free(arr);
}
};
