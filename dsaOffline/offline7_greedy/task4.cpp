#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
class point
{
    int x;
    int y;

public:
    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX() { return this->x; }
    int getY() { return this->y; }

    bool operator<(point &p)
    {
        if (this->x == p.x)
        {
            return this->y < p.y;
        }
        return this->x < p.x;
    }
};

int area(point m, point n, point p)
{
    return m.getX() * n.getY() + n.getX() * p.getY() + p.getX() * m.getY() - m.getY() * n.getX() - n.getY() * p.getX() - p.getY() * m.getX();
}

void divide(vector<point> &arr, vector<point> &result, point p1, point p2)
{
    if(arr.size()==0)return;
    int i = 0, mar = 0, mindx=0;

     for (size_t j = 0; j < arr.size(); j++) // Use size_t for the loop variable
    {
        int ar = area(p1, p2, arr[j]);
        if (ar > mar)
        {
            mar = ar;
            mindx = j;
        }
    }
    // for (auto v : arr)
    // {
    //     int ar = area(p1, p2, v);
    //     if (ar > mar)
    //     {
    //         mar = ar;
    //         mindx = i;
    //     }
    //     i++;
    // }
    result.push_back(arr[mindx]);
    vector<point> sec1, sec2;
    for (size_t j = 0; j < arr.size(); j++) // Use size_t for the loop variable
    {
        if (j == mindx)
            continue;
        if (area(p1, arr[mindx], arr[j]) > 0)
            sec1.push_back(arr[j]);
        if (area(arr[mindx], p2, arr[j]) > 0)
            sec2.push_back(arr[j]);
    }
    divide(sec1, result, p1, arr[mindx]);
    divide(sec2, result, arr[mindx], p2);
    // i = 0;
    // for (auto v : arr)
    // {
    //     if (i == mindx)
    //         continue;
    //     if (area(p1, arr[mindx],v) > 0)
    //         sec1.push_back(v);
    //     if (area( arr[mindx],p2,v) > 0)
    //         sec2.push_back(v);

    //     i++;
    // }
    // divide(sec1,result,p1,arr[mindx]);
    // divide(sec1,result,arr[mindx],p2);

}
vector<point> implementer(vector<point> &points)
{
    point p1 = points[0];
    point p2 = points[points.size() - 1];
    vector<point> result;
    result.push_back(p1);
    result.push_back(p2);
    vector<point> arr1;
    vector<point> arr2;
    for (auto v : points)
    {
        int ar = area(p1, p2, v);
        if (ar == 0)
            continue;
        else if (ar > 0)
            arr1.push_back(v);
        else if (ar < 0)
            arr2.push_back(v);
    }
    divide(arr1, result, p1, p2);
    divide(arr2, result, p2,p1);
    return result;
}
int main()
{

     freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);

    // number of point
    int number;
    cin >> number;
    vector<point> points;

    for (int i = 0; i < number; i++)
    {
        int a, b;
        cin >> a >> b;
        point p(a, b);
        points.push_back(p);
        //  points[i]=p;
    }
    sort(points.begin(), points.end());
    // cout<<points.size()<<endl;
    //  for(auto p:points){
    //      cout<<p.getX()<<"   "<<p.getY()<<endl;
    //  }
  vector<point> res=  implementer(points);
  for(auto p:res){
        cout<<p.getX()<<" "<<p.getY()<<endl;
    }

    return 0;
}
