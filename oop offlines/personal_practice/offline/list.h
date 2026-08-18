#include <stdio.h>
#include <stdlib.h>
int x,size,current;
typedef struct node{
int num;
struct node* next;

}node;
node* head=NULL;
node* tail=NULL;


void freed()
{
    node* fr=head;
    while(fr)
    {
        node* x=fr->next;
        free(fr);
        fr=x;
    }
}
void init(int k,int p)
{
     size=k;
     current=0;
     input();
}
void input()
{


    for(int i=0;i<size;i++)
    {
        int etr;
        scanf("%d",&etr);
      node* cur=(node*)malloc(sizeof(node));
      if(cur==NULL)
      {
          printf("invalid\n");
          freed(head);
          return -1;
      }
      if(i==0){
      cur->num=etr;
      cur->next=NULL;
      head=cur;
      tail=cur;
      }

      else
      {
          cur->num=etr;
      cur->next=NULL;
      tail->next=cur;
      tail=cur;

      }

    }
    print();
}

void  print()
{
    printf("\n");
    int count=0;
     node* temp=head;
    while(temp)
    {

        if(count==0)printf("<");
        if(count==current)printf("|");
        printf("%d",temp->num);
        if((count+1)!=current && (count+1)!=size)
            printf(",");
        temp=temp->next;
        count++;
         if(count==size && count==current)printf("|>");
        else if(count==size)printf(">");

    }
    if(size==0)
    printf("<>");


    //to check
  //  freed(head);
  printf("\n");
}

//10
int getValue()
{
    if(size==0 || current==size)
      {
          print();
          return -1;
      }
     node* ck=head;
    for(int i=0;i<current;i++)
    {
        ck=ck->next;

    }

     print();
    return ck->num;
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

    if(current<=0)
    {
      // printf("invalid operation");
        current=0;
    }
   else{
        current--;
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
    int tbr;
    node* ck=head;
    node*pre=head;
    if(current==size)
      {
           print();
          return -1;
      }
    else if(current!=0)
    {
    for(int i=0;i<current;i++)
    {
        ck=ck->next;
        if(i!=0)
            pre=pre->next;
    }
    tbr=ck->num;
    pre->next=ck->next;
    }
    else
    {
         tbr=ck->num;
         head=ck->next;

    }
    free(ck);
    size--;
     print();
    return tbr;
}
//1
int insert(int item)
{
    node* value=(node*)malloc(sizeof(node));
    value->num=item;
   node* ck=head;
    node*pre=head;
    if(current==0)
    {
        value->next=head;
        head=value;
    }
    else if(current==size)
    {
        while(ck)
        {
            pre=ck;
            ck=ck->next;
        }
        pre->next=value;
        value->next=NULL;
    }
    else{
     for(int i=0;i<current;i++)
    {
        ck=ck->next;
        if(i!=0)
        pre=pre->next;
    }
    value->next=ck;
    pre->next=value;
    }
size++;
 print();
return -1;
}

