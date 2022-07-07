#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool Visit[50001];
int Depth[50001];
int Parent[50001];
vector<int> Info[50001];

int LCA(int a, int b)
{
    if (Depth[a] > Depth[b])
    {
        swap(a, b);
    }

    while (Depth[a] != Depth[b])
    {
        b = Parent[b];
    }

    while (a != b)
    {
        a = Parent[a];
        b = Parent[b];
    }

    return a;
}

void MakeInfo()
{
    Visit[1] = true;

    queue<int> make;

    make.push(1);

    while (!make.empty())
    {
        int front = make.front();
        make.pop();

        for (int i = 0; i < Info[front].size(); i++)
        {
            if (!Visit[Info[front][i]])
            {
                Depth[Info[front][i]] = Depth[front] + 1;
                Parent[Info[front][i]] = front;
                Visit[Info[front][i]] = true;
                make.push(Info[front][i]);
            }
        }
    }
}

int 11437()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, query, u, v;

    cin >> num;

    for (int i = 0; i < num - 1; i++)
    {
        cin >> u >> v;
        Info[u].push_back(v);
        Info[v].push_back(u);
    }

    MakeInfo();

    cin >> query;

    for (int i = 0; i < query; i++)
    {
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
}

