#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

struct node
{
    int value;
    char flag;
    int distance;
    struct node *parent;
};

class Graph
{

    int vrtx, edg;
    vector<vector<node *>> adjList;

public:
    Graph(int v, int e)
    {
        this->vrtx = v;
        this->edg = e;
        for (int i = 0; i < v; i++)
        {
            node *temp = new node;
            temp->value = i;
            vector<node *> now;
            now.push_back(temp);
            this->adjList.push_back(now);
        }
    }

    void addEdge(int parent, int child)
    {
        // node *temp = adjList[child][0];
        // adjList[parent].push_back(temp);
        this->adjList[parent].push_back(this->adjList[child][0]);
    }

    stack<int> makeBFS(int start, int end)
    {
        for (int i = 0; i < this->vrtx; i++)
        {
            this->adjList[i][0]->distance = 0;
            this->adjList[i][0]->flag = 'w';
            this->adjList[i][0]->parent = NULL;
        }
        queue<node *> traverse;
        stack<int> result;
        node *begin = this->adjList[start][0];
        begin->flag = 'g';
        begin->distance = 0;
        traverse.push(begin);

        while (!traverse.empty())
        {
            begin = traverse.front();
            traverse.pop();

            if (begin->value == end)
            {

                result.push(begin->value);
                while (begin->parent != NULL)
                {
                    begin = begin->parent;
                    result.push(begin->value);
                }
                break;
            }

            for (auto v : this->adjList[begin->value])
            {
                if (v->flag == 'w')
                {
                    v->flag = 'g';
                    v->distance = begin->distance + 1;
                    v->parent = begin;
                    traverse.push(v);
                }
            }
        }
        return result;
    }

    void print()
    {
        for (auto out : this->adjList)
        {
            for (auto output : out)
            {
                cout << output->value << "->";
            }
            cout << endl;
        }
        cout << endl;
    }
    // class ends
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int v, e;

    cin >> v >> e;
    Graph graph(v, e);
    for (int i = 0; i < e; i++)
    {
        // cout << "enter parent & child node: ";
        int parent, child;
        cin >> parent >> child;
        graph.addEdge(parent, child);
    }
  //  graph.print();
    int start, end;
    //  cout << "enter start & end node: ";
    cin >> start >> end;
    stack<int> get = graph.makeBFS(start, end);
    cout << get.size() - 1 << endl;
    if (get.size() == 0)
    {
        cout << -1;
    }
    while (get.size() != 0)
    {
        cout << get.top() << " ";
        get.pop();
    }
}