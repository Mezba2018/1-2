#include<stdio.h>
#include<stdlib.h>
int arr[]={20, 23 , 12, 15};
void moveToPos(int n)
{
    int size=sizeof(arr)/sizeof(arr[0]);
    if(n<=size+1)
    {
for(int i=0;i<size;i++)
{
    if(i==size-1)
printf("%d",arr[i]);
else{
printf("%d",arr[i]);
if(i==n-2)
printf("|");
else printf(",");

}
}

}
else
{
    printf("non valid");
}
}

int main()
{
    int n;
    scanf("%d",&n);

moveToPos(n);


}
