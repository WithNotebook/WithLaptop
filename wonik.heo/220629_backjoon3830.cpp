#include <iostream>
#include <string>

const int MAX = 100001;

using namespace std;

int N, M;
int parent[MAX];
long long cost[MAX];

int Find(int node)
{
    if (parent[node] == -1) return node;

    int p = Find(parent[node]);
    cost[node] += cost[parent[node]];
    return parent[node] = p;
}

void Union(int a, int b, int w)
{
    int parent_A = Find(a);
    int parent_B = Find(b);

    if (parent_A == parent_B) return;

    cost[parent_B] = cost[a] - cost[b] + w;
    parent[parent_B] = parent_A;
    return;
}

int Problem_3830()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        for (int i = 1; i <= N; i++)
        {
            parent[i] = -1;
            cost[i] = 0;
        }

        char c;
        int a, b, w;

        for (int i = 0; i < M; i++)
        {
            cin >> c;
            if (c == '!')
            {
                cin >> a >> b >> w;
                Union(a, b, w);
            }
            else
            {
                cin >> a >> b;
                if (Find(a) != Find(b))
                {
                    cout << "UNKNOWN" << "\n";
                }
                else
                {
                    cout << cost[b] - cost[a] << "\n";
                }
            }
        }

    }
}
