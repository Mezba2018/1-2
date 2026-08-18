#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class time
{
    int val;
    bool aod;

public:
    time(int t, bool ck)
    {
        this->val = t;
        this->aod = ck;
    }
    bool operator<(time &x)
    {
        if (this->val == x.val)
        {
            return !(this->aod);
        }
        return this->val < x.val;
    }
    int getval()
    {
        return this->val;
    }
    bool getaod()
    {
        return this->aod;
    }
};
int main()
{
      freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);
    int tn, arr, dep;
    cin >> tn;
    vector<time> times;
    for (int i = 0; i < tn; i++)
    {
        cin >> arr >> dep;
        time t1(arr, true);
        time t2(dep, false);
        times.push_back(t1);
        times.push_back(t2);
    }
    sort(times.begin(), times.end());
    int count = 0, max = 0;
    for (int i = 0; i < times.size(); i++)
    {
        if (times[i].getaod())
            count++;
        else
            count--;
        if (count > max)
            max = count;
    }
    cout<<max<<endl;
}