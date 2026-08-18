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
    int count = 0;
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
            temp->distance = 0;
            temp->flag = 'w';
            temp->parent = NULL;
            vector<node *> now;
            now.push_back(temp);
            this->adjList.push_back(now);
        }
    }
    void init(){
        for (int i = 0; i < this->vrtx; i++)
        {
            this->adjList[i][0]->distance = 0;
            this->adjList[i][0]->flag = 'w';
            this->adjList[i][0]->parent = NULL;
        }
    }

    void addEdge(int parent, int child)
    {
        this->adjList[parent].push_back(this->adjList[child][0]);
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

    void makeDFS(int start, int end, stack<int> &result)
    {
        count++;
        node *traverse = this->adjList[start][0];
        traverse->distance = count;
        traverse->flag = 'g';
        if (traverse->value == end)
        {
            traverse->parent = NULL;
            result.push(traverse->value);
            return;
        }
        vector<node *> temp = this->adjList[start];
        for (auto rotate : temp)
        {
            if (rotate->flag == 'w')
            {
                count++;
                rotate->flag = 'g';
                rotate->distance = count;
                rotate->parent=traverse;
                makeDFS(rotate->value, end, result);
                rotate=traverse;
                if (!result.empty() ) 
                {
                    result.push(rotate->value);
                    return;
                }
            }
        }
        traverse->flag = 'b'; 
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
   // graph.print();
    int start, end;
    // cout << "enter start & end node: ";
    cin >> start >> end;
    stack<int> get;
    graph.makeDFS(start, end, get);
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