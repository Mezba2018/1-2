#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node
{
    int value;
    char flag;
    int distance;
    bool vc;
    struct node *parent;
    bool truth_value;
    bool is_assign;
    int sccNumber;
};

class Graph
{
private:
    int vrtx, endx;
    vector<vector<node *>> adjList;
    vector<vector<node *>> radjList;

    node *createNode(int value)
    {
        node *newNode = new node;
        newNode->value = value;
        newNode->distance = 0;
        newNode->flag = 'w';
        newNode->parent = NULL;
        newNode->vc = false;
        newNode->is_assign = false;
        newNode->truth_value = false;
        newNode->sccNumber = 0;
        return newNode;
    }

public:
    Graph()
    {
        this->vrtx = 52;

        for (int i = 0; i < this->vrtx; i++)
        {

            vector<node *> now;
            now.push_back(createNode(i));
            this->adjList.push_back(now);
            this->radjList.push_back(now);
        }
    }
    void reset()
    {
        for (auto adj : radjList)
        {
            adj[0]->flag = 'w';
        }
    }
    void addEdge(int parent, int child)
    {
        int p2 = parent;
        if (p2 > 25)
            p2 = p2 - 26;
        else
            p2 = p2 + 26;
        int c2 = child;
        if (c2 > 25)
            c2 = c2 - 26;
        else
            c2 = c2 + 26;

        adjList[p2].push_back(adjList[child][0]);
        adjList[c2].push_back(adjList[parent][0]);
        radjList[child].push_back(radjList[p2][0]);
        radjList[parent].push_back(radjList[c2][0]);
        adjList[p2][0]->vc = true;
        adjList[c2][0]->vc = true;
        adjList[parent][0]->vc = true;
        adjList[child][0]->vc = true;
        radjList[p2][0]->vc = true;
        radjList[c2][0]->vc = true;
        radjList[parent][0]->vc = true;
        radjList[child][0]->vc = true;
    }
    void addEdge(int child)
    {
        int c2 = child;
        if (c2 > 25)
            c2 = c2 - 26;
        else
            c2 = c2 + 26;

        adjList[c2].push_back(adjList[child][0]);
        adjList[child][0]->vc = true;
        adjList[c2][0]->vc = true;
        radjList[child].push_back(radjList[c2][0]);
        radjList[child][0]->vc = true;
        adjList[c2][0]->vc = true;
    }
    void print()
    {
        for (auto out : this->adjList)
        {
            if (out[0]->vc)

            {
                for (auto output : out)
                {

                    cout << output->value << "->";
                }
                cout << endl;
            }
        }
        cout << endl;
        cout << endl;
        cout << endl;
        for (auto out : this->radjList)
        {
            if (out[0]->vc)
            {
                for (auto output : out)
                {

                    cout << output->value << "->";
                }
                cout << endl;
            }
        }
    }

    void dfs2(node *start, vector<node *> &ref)
    {

        start->flag = 'g';

        for (auto adj3 : radjList[start->value])
        {
            if (adj3->flag == 'w')
            {
                adj3->flag = 'g';
                dfs2(adj3, ref);
            }
        }
        ref.push_back(start);

        //
    }
    stack<vector<node *>> dfsS()
    {
        stack<node *> order;
        for (auto adj : adjList)
        {
            if (!(adj[0]->vc))
                continue;
            else
            {

                if (adj[0]->flag == 'w')
                {
                    dfsV(adj, order);
                }
            }
        }
        reset();

        int count = 0;
        stack<vector<node *>> scc;
        while (order.size() != 0)
        {
            vector<node *> ref;

            node *start = order.top();
            order.pop();
            if (start->flag == 'w')
            {
                dfs2(start, ref);
                count++;
                for (auto assin : ref)
                {
                    assin->sccNumber = count;
                }
                scc.push(ref);
            }
        }
        return scc;
    }
    void dfsV(vector<node *> adj2, stack<node *> &order)
    {

        adj2[0]->flag = 'g';
        for (auto adj3 : adj2)
        {
            if (adj3->flag == 'w')
            {
                adj3->flag = 'g';
                // adj3->parent = adj2[0];
                dfsV(adjList[adj3->value], order);
            }

            // time++;
        }
        order.push(adj2[0]);

        //
    }
    bool checkPossibility(stack<vector<node *>> &scc)
    {
        while (!scc.empty())
        {
            vector<node *> sccNodes = scc.top();
            scc.pop();
            for (auto temp : sccNodes)
            {
                if (!temp->is_assign)
                {
                    temp->is_assign = true;
                    if (temp->value > 25)
                    {
                        radjList[temp->value - 26][0]->is_assign = true;

                        if (temp->sccNumber == radjList[temp->value - 26][0]->sccNumber)
                        {
                            return 0;
                        }
                        else
                        {
                            temp->truth_value = true;
                            radjList[temp->value - 26][0]->truth_value = false;
                        }
                    }
                    else
                    {
                        radjList[temp->value + 26][0]->is_assign = true;

                        if (temp->sccNumber == radjList[temp->value + 26][0]->sccNumber)
                        {
                            return 0;
                        }
                        else
                        {
                            temp->truth_value = true;
                            radjList[temp->value + 26][0]->truth_value = false;
                        }
                    }
                }
            }
        }
        return true;
    }
    void printResult()
    {
        int cnt = 0;
        for (auto res : radjList)
        {
            cnt++;
            if (res[0]->vc)
            {
                if (res[0]->truth_value)
                    cout << char(res[0]->value + 97) << " true" << endl;
                else
                    cout << char(res[0]->value + 97) << " false" << endl;
            }
            if (cnt == 26)
                break;
        }
    }
};

int main()
{
     freopen("in92_.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
    Graph graph;
    int inLine, i;

    int nd1 = -1, nd2 = -2;
    cin >> inLine;
    cin.ignore();
    string input[inLine];
    for (i = 0; i < inLine; i++)
    {
        getline(cin, input[i]);
    }

    for (int i = 0; i < inLine; i++)
    {
        string clause = input[i];

        int size = clause.length();
        for (int k = 0; k < size; k++)
        {
            if (clause[k] == ' ')
                continue;
            if (size <= 2)
            {
                if (clause[k] == '~')
                {
                    nd1 = 26 + (clause[k + 1] - 'a');
                }
                else
                {
                    nd1 = clause[k] - 'a';
                }

                graph.addEdge(nd1);

                nd1 = -1;
                break;
            }

            else
            {

                if (nd1 == -1)
                {
                    if (clause[k] == '~')
                    {
                        nd1 = 26 + (clause[k + 1] - 'a');

                        k++;
                    }
                    else
                    {
                        nd1 = clause[k] - 'a';
                    }
                }
                else
                {
                    if (clause[k] == '~')
                    {
                        nd2 = 26 + (clause[k + 1] - 'a');
                        k++;
                    }
                    else
                    {
                        nd2 = clause[k] - 'a';
                    }
                    break;
                }
            }
        }
        if (nd1 != -1 && nd2 != -2)

            graph.addEdge(nd1, nd2);
        nd1 = -1;
        nd2 = -2;
    }

    stack<vector<node *>> scc = graph.dfsS();
    bool check = graph.checkPossibility(scc);
    if (!check)
    {
        cout << "No assignment possible" << endl;
    }
    else
    {
        graph.printResult();
    }
}