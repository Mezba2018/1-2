#include<iostream>
using namespace std;

class Vector{
    int a,b,c;
public:
Vector(){
    a=b=c=0;
}

Vector(int x,int y,int z){
    this->a=x;
    this->b=y;
    this->c=z;
}
  Vector& operator+=(const Vector& v) {
         this->a += v.a;
           this-> b += v.b;
            this->c += v.c;
        return *this;
    }
Vector operator ()( Vector &v){
    return v;
}
friend Vector operator+(int a,Vector &v);

void show(){
    cout<<a<<","<<b<<","<<c<<endl;
}

};
Vector operator+(int a,Vector &v){
    v.a+=10;
    v.b+=10;
    v.c+=10;
    return v;
}

int main(){
    Vector v2(1,2,3);
    Vector v1;
    v1 +=(10+v2);
    v1.show();

}
