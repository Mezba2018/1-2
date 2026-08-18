#include<stdio.h>
#include<string.h>
int main()
{
    int test;
    scanf("%d",&test);
    for(int m=1;m<=test;m++)
    {


  int a,i,k=1,p=0;
  scanf("%d",&a);
  char str[101],res[101];
  scanf("%s",str);

 // printf("%c",str[0]);
 res[p]=str[0];
p++;
do{
  for(i=k;i<a;i++)
  {
      if(str[i]==str[0])
      {
          res[p]=str[i+1];p++;
         //printf("%c",str[i+1]);

str[0]=str[i+1];
         k=i+2;


         break;
      }
  }


  }
  while(k<=a);
  res[p]='\0';
  printf("%s\n",res);


    }

    return 0;
}
