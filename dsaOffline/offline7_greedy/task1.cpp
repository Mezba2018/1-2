#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
struct point
{
    int x, y;
};
bool comparePolarAngles(const point &p1, const point &p2, const point &reference)
{
    double angle1 = atan2(p1.y - reference.y, p1.x - reference.x);
    double angle2 = atan2(p2.y - reference.y, p2.x - reference.x);
    return angle1 < angle2;
}

int orientation(point a, point b, point c)
{
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area == 0)
        return 0;
    else if (area > 0)
        return 2; // counter clock
    else
        return 1; // clock
}
void merge(const point &ref, int left, int mid, int right, vector<point> &points)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<point> leftArray(n1);
    vector<point> rightArray(n2);
    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = points[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArray[i] = points[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (comparePolarAngles(leftArray[i], rightArray[j], ref))
        {
            points[k] = leftArray[i];
            i++;
        }
        else
        {
            points[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        points[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        points[k] = rightArray[j];
        j++;
        k++;
    }
}
void mergeshot(const point &ref, int left, int right, vector<point> &points)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeshot(ref, left, mid, points);
        mergeshot(ref, mid + 1, right, points);
        merge(ref, left, mid, right, points);
    }
}

vector<point> taskImplementer(vector<point> &points)
{
    int size = points.size();
    if (size <= 3)
        return points;
    int minY = points[0].y, minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        int y = points[i].y;
        if (y < minY || (y == minY && points[minIndex].x > points[i].x))
        {
            minY = y;
            minIndex = i;
        }
    }

    swap(points[0], points[minIndex]);
    mergeshot(points[0], 1, size - 1, points);

    vector<point> convexHull;
    convexHull.push_back(points[0]);
    convexHull.push_back(points[1]);

    for (int i = 2; i < size; i++)
    {
        while (convexHull.size() >= 2 &&  orientation(convexHull[convexHull.size() - 2], convexHull[convexHull.size() - 1], points[i]) != 2)
        {
            convexHull.pop_back();
        }
        convexHull.push_back(points[i]);
    }

    return convexHull;
}

int main()
{

     freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);

    // number of point
    int number;
    cin >> number;
    vector<point> points(number);

    for (int i = 0; i < number; i++)
    {
        cin >> points[i].x >> points[i].y;
    }
     vector<point> convexHull = taskImplementer(points);

   
    for (const point &p : convexHull)
    {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}

