#include<stdio.h>
int k;

typedef struct node
{
    int num;
    struct node* next;
}node;

void freee(node* list)
{
    node *tem=list;
    while(tem)
    {
        node* next=tem->next;
        free(tem);
        tem=next;

    }
}

int main()
{
    do{
            scanf("%d",&k);

 node * list=NULL;
 for (int i=0;i<k;i++)
 {
     int number;
     scanf("%d",&number);
     node* par=malloc(sizeof(node));
     if(par==NULL)
     {
         freee(list);
         printf("ERROR\n");
         return -1;
     }
     par->num=number;
     par->next=list;
     list=par;

 }
 node*temp=list;
 while(temp)
 {
    printf("%d\t",temp->num);


   temp=temp->next;
 }
 freee(list);

}
while(k);
return 0;
}
