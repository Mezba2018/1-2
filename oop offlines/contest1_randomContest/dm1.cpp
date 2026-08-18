#include<iostream>
using namespace std;
#define pi 3.1416

class circle{
public:
    int r;
    void detect()
    {
        float area=pi*r*r;
        cout<<"area is:"<<area<<endl;


    }

};


int main()
{

cout<<"hellow world"<<endl;
circle rad;
cout<<"enter circle radious:";
cin>>rad.r;
cout<<"your radious is "<<rad.r<<endl;
rad.detect();

    return 0;

}
