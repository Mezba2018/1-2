#include<iostream>
using namespace std;

typedef struct node{
int num;
struct node* next;

}node;

class list{
int x,size=0,current=0;
node* head=NULL;
node* tail=NULL;
public:
    ~list()
{
    node* fr=head;
    while(fr)
    {
        node* x=fr->next;
        free(fr);
        fr=x;
    }
}
void init(int nai,int p,int ase)
{
    // head=NULL;
    size=0;
    current=0;
     for(int i=0;i<ase;i++)
    {
        int el;
        cin>>el;
        insert(el);
        current++;
    }
current=0;
}

void init(int k,int p)
{

    for(int i=0;i<k;i++)
    {
        int el;
        cin>>el;
     insert(el);
     current++;
    }
     current=0;

     /*size=k;
     current=0;
     input();*/
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
          return -1;
      }
     node* ck=head;
    for(int i=0;i<current;i++)
    {
        ck=ck->next;

    }

    return ck->num;
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
    int tbr;
    node* ck=head;
    node*pre=head;
    if(current==size)
      {

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

return -1;
}

};


