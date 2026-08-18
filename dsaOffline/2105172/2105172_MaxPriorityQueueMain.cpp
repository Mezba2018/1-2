
#include "2105172_MaxPriorityQueue.cpp"
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //cout << "1. Insert  2. FindMax  3. ExtractMax  4. IncreaseKey  5. DecreaseKey  6. Print  7. Terminate" << endl;
    MaxPriorityQueue<int> mpqueue;
    int ck;
    while (true)
    {
        cin >> ck;
        switch (ck)
        {
        case 1:
            int element;
            cin >> element;
            mpqueue.Insert(element);

            break;
        case 2:
            cout << "Max: " << mpqueue.FindMax() << endl;

            break;
        case 3:
            cout << "Max: " << mpqueue.ExtractMax() << " has been extracted." << endl;

            break;
        case 4:
            int index, newelement;
            cin >> index >> newelement;
            mpqueue.IncreaseKey(index, newelement);

            break;
        case 5:
            int position, key;
            cin >> position >> key;
            mpqueue.DecreaseKey(position, key);

            break;
        case 6:
            mpqueue.print();
            break;
        case 7:
            mpqueue.sort();
            mpqueue.print();
            return 0;

            break;
        }
    }

    fclose(stdin);
    fclose(stdout);
}

