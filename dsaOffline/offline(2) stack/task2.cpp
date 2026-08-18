#include"stack.h"
#include<cstring>
#define max 100

float todo(float res1,float res2,char optn)
{
    float rec;
    if(optn=='+')
    rec=res1+res2;

    if(optn=='-')
   rec=res1-res2;
    if(optn=='*')
     rec=res1*res2;

    if(optn=='/')
   rec= res1/res2;
   return rec;
}

int precedence(char c)
{
    switch (c)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;

    default:
        return 0;
    }

}

int main()
{
   int ck=0;
   float result=0;
  list<char> brac;
  list<float> res;
  res.init(5);
  brac.init(5);
  char exp[max];
  //scanf("%[^\n]",exp);
  cout<<"enter the expression:  "<<endl;
  gets(exp);
  for(int i=0;i<strlen(exp);i++)
  {
      if(exp[i]=='(')
         brac.push(exp[i]);
      if(exp[i]==')')
      {
          if(brac.length()==0)
          {
              ck=-1;
              cout<<"invalid brackets expression"<<endl;
              break;
          }
          else
            brac.pop();
      }

  }
  if(brac.length()!=0)
  {
      ck=-1;
    cout<<"invalid brackets expression"<<endl;
  }
  else if(brac.length()==0 && ck==0)
     cout<<"valid brackets expression"<<endl;

  if(ck==0)
  {
      char temp;
     for(int i=0;i<strlen(exp);i++)
     {
     if(i==0)
           {
               temp=exp[i];
               if(temp=='*' || temp=='/')
               {
                cout<<"invalid operant expression"<<endl;
                ck=-1;
                break;
               }
           }
     else
     {
         if(temp=='+' || temp=='-' || temp=='/'||temp=='*' )
         {
           if(exp[i]=='+' || exp[i]=='-' || exp[i]=='/'|| exp[i]=='*' || exp[i]==')')
           {
                cout<<"invalid operant expression"<<endl;
                ck=-1;
                break;
           }
           else
            temp=exp[i];

         }
         else if(temp=='0' ||temp=='1' ||temp=='2' ||temp=='3' ||temp=='4' ||temp=='5' ||temp=='6' ||temp=='7' ||temp=='8' ||temp=='9')
         {
             if(exp[i]=='(')
             {
                  cout<<"invalid operant expression"<<endl;
                ck=-1;
                break;
             }
             else
              temp=exp[i];
         }
         else if(temp==')')
         {
            // if( exp[i]=='0' ||exp[i]=='1' exp[i]=='2' ||exp[i]=='3' ||exp[i]=='4' ||exp[i]=='5' ||exp[i]=='6' ||exp[i]=='7' ||exp[i]=='8' ||exp[i]=='9')
             if((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '(')
             {
                cout<<"invalid operant expression"<<endl;
                ck=-1;
                break;

             }
             else
                 temp=exp[i];
         }

         else
         {
          if(exp[i]=='*' || exp[i]=='/')
          {
                cout<<"invalid operant expression"<<endl;
                ck=-1;
                break;
          }
          else
           temp=exp[i];
         }

     }


     }
      if((ck==0) && (exp[strlen(exp)-1]=='+' || exp[strlen(exp)-1]=='-' || exp[strlen(exp)-1]=='/' || exp[strlen(exp)-1]=='*' ))
  {
      ck=-1;
      cout<<"invalid operant expression"<<endl;
  }
  if(ck==0)
   cout<<"valid operant expression"<<endl;

  }

  if(ck==-1)
  {
      return 1;
  }

  if(ck==0)
  {



       for (int i = 0; i < strlen(exp); i++)
       {
           if(exp[0]=='+' ||exp[0]=='-')
             res.push(0);

           if(exp[i]==' ')
            continue;
           else if(exp[i]=='(')
           {
               brac.push(exp[i]);
                if (exp[i+1] == '-' || exp[i+1] == '+')
                res.push(0);
           }
           else if(exp[i]==')')
           {
               while (!brac.isEmpty() && brac.topValue() != '(')
            {

                char c = brac.pop();
                float res2 = res.pop();
                float res1 = res.pop();

                result = todo(res1,res2,c);
                res.push(result);
            }

            if (!brac.isEmpty())
                brac.pop();

           }

        else if(exp[i]=='+' || exp[i]=='-'|| exp[i]=='*'|| exp[i]=='/')
        {
             while (!brac.isEmpty() && precedence(brac.topValue()) >= precedence(exp[i]) && brac.topValue() != '(')
            {
                char c = brac.pop();
                float res2 = res.pop();
                float res1 = res.pop();

                result = todo(res1,res2,c);
                res.push(result);
            }

            brac.push(exp[i]);
        }
        else
        {
            int num = exp[i] - '0';
            while (exp[i + 1] >= '0' && exp[i + 1] <= '9')
            {
                int ran = exp[i + 1] - '0';
                num = num * 10 + ran;
                i++;
            }
            res.push(num);
            //res.print();
        }


       }

        while (!brac.isEmpty())
    {

        char c = brac.pop();
        float res2 = res.pop();
        float res1 = res.pop();
        result = todo(res1,res2,c);
        res.push(result);
    }
    cout << "Result: " << res.pop() << endl;






  }





}
