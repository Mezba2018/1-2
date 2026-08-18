#include <iostream>
#include <vector>
using namespace std;

struct Train
{
    int arr;
    int dep;
    bool left;
};
void merge(int left, int mid, int right, vector<Train> &trains)
{
  //  cout << "in mrg" << endl;

    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Train> leftArray(n1);
    vector<Train> rightArray(n2);
    for (int i = 0; i < n1; i++)
    {
        leftArray[i] = trains[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArray[i] = trains[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArray[i].arr < rightArray[i].arr)
        {
            trains[k] = leftArray[i];
            i++;
        }
        else
        {
            trains[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        trains[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        trains[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergesort(int left, int right, vector<Train> &trains)
{
  //  cout << "in mrgst" << endl;
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(left, mid, trains);
        mergesort(mid + 1, right, trains);
        merge(left, mid, right, trains);
    }
}

int main()
{
  //  cout << "before1"<<endl;
    int numTrain;
    cin >> numTrain;

    vector<Train> trains(numTrain);
    for (int i = 0; i < numTrain; i++)
    {
        cin >> trains[i].arr;
        cin >> trains[i].dep;
        trains[i].left = false;
    }

    mergesort(0, numTrain - 1, trains);
    //cout << trains.size();
    for (int i = 0; i < numTrain; i++)
    {
        cout << trains[i].arr << "  " << trains[i].dep;
        cout << endl;
    }
   // cout << "after"<<endl;
//int count=1,max=0;
// for(int i=1;i<numTrain;i++){
//     if(trains[i].arr<trains[i-1].dep &&   )
//}


}