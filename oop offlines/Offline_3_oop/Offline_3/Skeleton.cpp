#include<iostream>
// your code
using namespace std;

class Point2D
{
    double x,y;
public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void print();
    ~Point2D();
    // your code

     Point2D operator+( Point2D &t)
     {
         Point2D tem;
         tem.x=x+t.x;
         tem.y=y+t.y;
         return tem;

     }
     Point2D operator*(double n)
     {
         Point2D tem;
         tem.x=x*n;
         tem.y=y*n;
         return tem;

     }
     bool operator==( Point2D &t)
     {
         if(x==t.x && y==t.y)
            return true;
         else return false;
     }
     bool operator!=( Point2D &t)
     {
         if(x!=t.x || y!=t.y)
            return true;
         else return false;

     }


};

Point2D::Point2D(double argx,double argy)
{
    x = argx;
    y = argy;
}

void Point2D::setX(double argx)
{
    x=argx;
}

void Point2D::setY(double argy)
{
    y = argy;
}

double Point2D::getX()
{
    return x;
}

double Point2D::getY()
{
    return y;
}

void Point2D::print()
{
    cout << "(" << x << "," << y << ")";
}

Point2D::~Point2D()
{
    x = 0;
    y = 0;
}

// your code

class Circle
{
    Point2D center;
    double radius;
public:
    Circle();
    Circle(Point2D c, double r);
    void setCenter(Point2D c);
    void setRadius(double r);
    Point2D getCenter();
    double getRadius();
    void print();
    ~Circle();
    // your code
    Circle operator+(Point2D &t)
    {
        Circle tem;
        tem.radius=radius;
//         double radx=center.getX()+t.getX();
//         tem.center.setX(radx);
//        double rady=center.getY()+t.getY();
//         tem.center.setY(rady);
//         return tem;
          tem.center = center + t ;
          return tem;

    }
    Circle operator*(double n)
    {
        Circle tem;
        tem.radius=radius*n;
//
//        double radx=center.getX()*n;
//         tem.center.setX(radx);
//        double rady=center.getY()*n;
//         tem.center.setY(rady);
//         return tem;
tem.center=center*n;
return tem;

    }
      Circle operator+(Circle &t)
    {
        Circle tem;
         tem.radius=radius+t.radius;
         double a=radius/(radius+t.radius);
         Point2D m,n;
         m=center*a;
         n=t.center*(1-a);
         tem.center=m+n;

        // double b= 1.0- a ;
//         double radx=center.getX()*a+t.center.getX()*(1-a);
//         tem.center.setX(radx);
////tem.center=(center*a) +(t.center*(1-a) );
//       double rady=center.getY()*a+t.center.getY()*(1-a);
//     tem.center.setY(rady);
////         return tem;
////tem.center=center*a+t.center*(1-a);
return tem;
    }
     Circle operator-(Circle &t)
    {
         Circle tem;
         tem.radius=radius-t.radius;
         if(tem.radius<0)tem.radius=-tem.radius;

         double a=radius/(radius+t.radius);
          Point2D m,n;
         m=center*a;
         n=t.center*(1-a);
         tem.center=m+n;

//       double radx=center.getX()*a+t.center.getX()*(1-a);
//         tem.center.setX(radx);
//         double rady=center.getY()*a+t.center.getY()*(1-a);
//         tem.center.setY(rady);
         return tem;


    }
    bool operator==(Circle &t)
    {
        if(radius==t.radius)
            return true;
        else return false;

    }
     bool operator>(Circle &t)
    {
        if(radius>t.radius)
            return true;
        else return false;
    }
     bool operator>=(Circle &t)
    {
        if(radius>=t.radius)
            return true;
        else return false;
    }
     bool operator<(Circle &t)
    {
        if(radius<t.radius)
            return true;
        else return false;
    }
     bool operator<=(Circle &t)
    {
        if(radius<=t.radius)
            return true;
        else return false;
    }
    //pre
     Circle operator++()
    {
        radius++;
        return *this;

    }
    //post

     Circle operator++(int notused)
    {
        Circle tem;
        tem.center.setX(center.getX());
        tem.center.setY(center.getY());
        tem.radius=radius;
        radius++;
        return tem;

    }

};


Circle:: Circle()
{
    center.setX(0);
    center.setY(0);
    radius=0;
}

Circle::Circle(Point2D c, double r)
{
    center.setX(c.getX());
    center.setY(c.getY());
    radius=r;
}

void Circle::setCenter(Point2D c)
{
    center.setX(c.getX());
    center.setY(c.getY());
}

void Circle::setRadius(double r)
{
    radius=r;
}
Point2D Circle::getCenter()
{
    return center;
}
double Circle::getRadius()
{
    return radius;
}

void Circle::print()
{
    cout << "[Center: ";
    center.print();
    cout << " Radius: " << radius;
    cout<<"]";
}

Circle::~Circle()
{
    center.setX(0);
    center.setY(0);
    radius=0;
}

// your code

class Rectangle
{
    Point2D topRightPoint,bottomLeftPoint;
public:
    Rectangle();
    Rectangle(Point2D oneCorner,Point2D anotherCorner);
    void setTopRightPoint(Point2D oneCorner);
    void setbottomLeftPoint(Point2D anotherCorner);
    Point2D getTopRightPoint();
    Point2D getBottomLeftPoint();
    void print();
    ~Rectangle();
    // your code
    Rectangle operator+(Point2D &t)
    {
       Rectangle tem;
//       tem.topRightPoint.setX(t.getX()+topRightPoint.getX());
//       tem.topRightPoint.setY(t.getY()+topRightPoint.getY());
//        tem.bottomLeftPoint.setX(t.getX()+bottomLeftPoint.getX());
//     tem.bottomLeftPoint.setY(t.getY()+bottomLeftPoint.getY());

tem.topRightPoint=topRightPoint+t;
tem.bottomLeftPoint=bottomLeftPoint+t;

       return tem;

    }
    Rectangle operator*(double n)
    {
         Rectangle tem;
//        tem.topRightPoint.setX(n*topRightPoint.getX());
//        tem.topRightPoint.setY(n*topRightPoint.getY());
//        tem.bottomLeftPoint.setX(n*bottomLeftPoint.getX());
//        tem.bottomLeftPoint.setY(n*bottomLeftPoint.getY());

tem.topRightPoint=topRightPoint*n;
tem.bottomLeftPoint=bottomLeftPoint*n;
       return tem;

    }
};

Rectangle::Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}
Rectangle::Rectangle(Point2D oneCorner,Point2D anotherCorner)
{
    topRightPoint=oneCorner;
    bottomLeftPoint=anotherCorner;
}

void Rectangle::setTopRightPoint(Point2D oneCorner)
{
    topRightPoint=oneCorner;
}
void Rectangle::setbottomLeftPoint(Point2D anotherCorner)
{
    bottomLeftPoint=anotherCorner;
}
Point2D Rectangle::getTopRightPoint()
{
    return topRightPoint;
}
Point2D Rectangle::getBottomLeftPoint()
{
    return bottomLeftPoint;
}

void Rectangle::print()
{
    cout<<"[Top Right Point: ";
    topRightPoint.print();
    cout<<"  Bottom left Point: ";
    bottomLeftPoint.print();
    cout<<"]";
}
Rectangle::~Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}

// your code

int main()
{
    Point2D p1(5,10),p2(15,10),p3;
    Circle c1(p1,10),c2,c3;
    Rectangle r1(p1,p2),r2;
    // your code

    p3 = p1 + p2;
    cout << "p1 + p2: ";
    p3.print();
    cout << endl;


    p3 = p1 * 5.5;
    cout << "p1 * 5.5: ";
    p3.print();
    cout << endl;

    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;


    c2 = c1 + p2;
    cout << "c1 + p2: ";
    c2.print();
    cout << endl;

    c3 = c1 * 2.5;
    cout << "c1 * 2.5: ";
    c3.print();
    cout << endl;

    c3 = c1 + c2;
    cout << "c1 + c2: ";
    c3.print();
    cout << endl;

    c3 = c1 - c2;
    cout << "c1 - c2: ";
    c3.print();
    cout << endl;

    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 > c2: " << (c1 > c2) << endl;
    cout << "c1 >= c2: " << (c1 >= c2) << endl;
    cout << "c1 < c2: " << (c1 < c2) << endl;
    cout << "c1 <= c2: " << (c1 <= c2) << endl;

    ++c1;
    cout << "++c1: ";
    c1.print();
    cout << endl;

    c2 = c1++;
    cout << "c2 = c1++: ";
    c2.print();
    cout << endl;
    cout<<"c1:";
     c1.print();
    cout << endl;


    r2 = r1 + p2;
    cout << "r1 + p2: ";
    r2.print();
    cout << endl;

    r2 = r1 * 4.5;
    cout << "r1 * 4.5: ";
    r2.print();
    cout << endl;

    return 0;
}
