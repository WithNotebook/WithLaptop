#include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;

#define N_MAX 40001
#define M_MAX 10001
#define LOG_MAX 15 // log2(N_MAX*M_MAX)

vector<pair<int , int>> tree[N_MAX];
int depth[N_MAX];
int parent[N_MAX][LOG_MAX];
int dist[N_MAX];

int LCA(int a, int b)
{
    int target = a;
    int compare = b;

    int result = 0;
    if(depth[a] != depth[b])
    {
        if(depth[a] < depth[b]) swap(a, b);

        target = a;
        compare = b;

        for(int i=LOG_MAX; i>=0; i--)
        {
            if(depth[parent[target][i]] >= depth[compare])
            {
                target = parent[target][i];
            }
        }
    }

    int common = target;
    if(target != compare)
    {
        for(int i=LOG_MAX; i>=0; i--)
        {
            if(parent[target][i] != parent[compare][i])
            {
                target = parent[target][i];
                compare = parent[target][i];
            }
            common = parent[target][i];
        }
    }

    result = dist[a] + dist[b] - (2*dist[common]);


    return result;
}

void init(int cur)
{
    for(int i=1; i<=LOG_MAX; i++)
    {
        parent[cur][i] = parent[parent[cur][i-1]][i-1];
    }

    for(auto it = tree[cur].begin(); it!=tree[cur].end(); it++)
    {
        if(parent[cur][0] == (*it).first)
        {
            //tree[cur].erase(it);
            continue;
        }
        if(it == tree[cur].end()) break;

        int next = (*it).first;
        
        dist[next] = (*it).second + dist[cur];
        depth[next] = depth[cur] + 1;
        parent[next][0] = cur;
        
        init(next);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i=0; i<=N; i++)
    {
        depth[i] = -1;
    }

    for(int i=1; i<=N-1; i++)
    {
        int a, b;
        int dist;
        scanf("%d %d %d",&a ,&b ,&dist);
        pair<int, int> temp1(a, dist);
        pair<int, int> temp2(b, dist);
        tree[a].push_back(temp2);
        tree[b].push_back(temp1);
    }

    depth[1] = 0;
    init(1);

    int M;
    scanf("%d", &M);
    for(int i=1; i<=M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int res = LCA(a, b);
        printf("%d\n", res);
    }

    return 0;
}