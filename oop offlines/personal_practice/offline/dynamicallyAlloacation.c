#include<stdio.h>
int* arr;
void crtarr(int size)
{
    int* temp=malloc(size*sizeof(int));
    arr=temp;
}
void takein(int element)
{
    for(int i=0;i<element;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void out(int element)
{
    for(int i=0;i<element;i++)
    {
        printf("%d\n",arr[i]);
    }
    printf("\n%d",sizeof(arr));
}
int main()
{
    crtarr(5);
    takein(3);
    out(3);
}
