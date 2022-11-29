#include <iostream>
#include <string>

const int MAX = 1000001;

using namespace std;

int N, M;
int parent[MAX];

int Find(int node)
{
    if (parent[node] == node) return node;

    int p = Find(parent[node]);
    return parent[node] = p;
}

void Union(int a, int b)
{
    int parent_A = Find(a);
    int parent_B = Find(b);

    if (parent_A == parent_B) return;

    parent[parent_B] = parent_A;
    return;
}

int 1717()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    int q, a, b;

    for (int i = 0; i < M; i++)
    {
        cin >> q >> a >> b;
        if (q == 0)
        {
            Union(a, b);
        }
        else
        {
            if (Find(a) != Find(b))
            {
                cout << "NO" << "\n";
            }
            else
            {
                cout << "YES" << "\n";
            }
        }
    }

    return 0;

}
