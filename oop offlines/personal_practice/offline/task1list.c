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
