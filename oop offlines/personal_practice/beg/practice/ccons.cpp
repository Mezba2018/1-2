#include<iostream>
using namespace std;
class base
{
public:
   virtual void show()
    {
        cout << "base\n";
    }
};
class d1 : public base
{
public:
  virtual  void show()
    {
        cout << "derived-1\n";
    }
};
class d2 : public base
{
public:
    void show()
    {
        cout << "derived-2\n";
    }
};
int main()
{
    base *pb;
    d1 od1;
    d2 od2;
    int n=0;

while(n>=0){
         cin >> n;
        if (n % 2) pb = &od1;
    else pb = &od2;
    pb->show(); // guess what ??
}
}
