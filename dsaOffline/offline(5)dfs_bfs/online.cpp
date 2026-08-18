#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
int X, Y;

class point
{

public:
    int x;
    int y;
    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
class poin
{

public:
    int x;
    int y;
    int z;
    poin(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
vector<point> adjList(point p)
{
    int x = p.x;
    int y = p.y;
    int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
    int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

    vector<point> list;
    for (int i = 0; i < 8; i++)
    {
        int m = dx[i] + x;
        int n = dy[i] + y;
        if (m >= 0 && n >= 0 && m < X && n < Y)

        {
            point det(m, n);
            list.push_back(det);
        }
    }
    return list;
}
void bfs(point go, int **grid)
{
    queue<point> q;
    q.push(go);
    grid[go.x][go.y] = 0;
    while (q.size() != 0)
    {
        point current = q.front();
        q.pop();
        int distance = grid[current.x][current.y];
        vector<point> adj = adjList(current);
        for (auto move : adj)
        {
            if (grid[move.x][move.y] == -1)
            {
                grid[move.x][move.y] = distance + 1;
                // point det(move.x, move.y);
                q.push(move);
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int Rnum;
    cin >> X >> Y >> Rnum;
    int **resgrid = new int *[X];
    int **cntgrid = new int *[X];
    for (int i = 0; i < X; i++)
    {
        resgrid[i] = new int[Y]; // Allocate memory for each row
        cntgrid[i] = new int[Y]; // Allocate memory for each row
    }
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            resgrid[i][j] = 0;
            cntgrid[i][j] = 0;
        }
    }

    vector<poin> pos;
    for (int i = 0; i < Rnum; i++)
    {
        int x, y, power;
        cin >> x >> y >> power;

        poin go(x, y, power);

        pos.push_back(go);

        // bfs(go, grid);
        // for (int i = 0; i < X; i++)
        // {
        //     for (int j = 0; j < Y; j++)
        //     {
        //         resgrid[i][j] += ceil(1.0 * grid[i][j] / power);
        //         if (grid[i][j] != -1)
        //         {
        //             cntgrid[i][j]++;
        //         }
        //     }
        // }
    }
    int desx, desy;
    cin >> desx >> desy;
    point check(desx, desy);
    int **grid = new int *[X]; // Allocate an array of pointers to int

    for (int i = 0; i < X; i++)
    {
        grid[i] = new int[Y]; // Allocate memory for each row
    }
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            grid[i][j] = -1;
        }
    }
    bfs(check, grid);
    bool test = true;
    int count = 0;
    for (auto pnt : pos)
    {
        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {

                // grid[i][j] = -1;
                if (i == pnt.x && j == pnt.y)
                {
                    if (grid[i][j] = -1)
                    {
                        test = false;
                        break;
                    }
                    else
                    {
                        count += ceil(1.0 * grid[i][j] / pnt.z);
                    }
                }
            }
        }
    }

    int value = -1;
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            if (cntgrid[i][j] == Rnum)
            {
                if (value == -1)
                    value = resgrid[i][j];
                else if (value > resgrid[i][j])
                    value = resgrid[i][j];
            }
        }
    }
    cout << value << endl;
}