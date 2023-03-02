#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

#define N_MAX 40001
#define M_MAX 10001
#define LOG_MAX 16 // log2(N_MAX*M_MAX)

vector<pair<int , int>> tree[N_MAX];
int depth[N_MAX];
int parent[N_MAX][LOG_MAX];
int dist[N_MAX];

int LCA(int a, int b)
{
    int target = a;
    int compare = b;

    if(depth[a] != depth[b])
    {
        if(depth[target] < depth[compare]) swap(target, compare);

        int logN = floor(log2(depth[target]));
        for(int i=logN; i>=0; i--)
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
        int logN = floor(log2(depth[target]));
        for(int i=logN; i>=0; i--)
        {
            if(parent[target][i] != parent[compare][i])
            {
                target = parent[target][i];
                compare = parent[compare][i];
            }
            common = parent[target][i];
        }
    }

    return common;
}

void init(int cur)
{
    // time out!!!
    // for(int i=1; i<=LOG_MAX; i++)
    // {
    //     parent[cur][i] = parent[parent[cur][i-1]][i-1];
    // }

    for(auto it = tree[cur].begin(); it!=tree[cur].end(); it++)
    {
        if(parent[cur][0] == (*it).first) it = tree[cur].erase(it);
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

    for(int i=0; i<N_MAX; i++)
    {
        depth[i] = -1;
        dist[i] = 0;
    }

    for(int i=0; i<N_MAX; i++)
    {
        for(int j=0; j<LOG_MAX; j++)
        {
            parent[i][j] = 0;
        }
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

    for(int k=1; k<LOG_MAX; k++)
    {
        for(int i=1; i<=N; i++)
        {
            parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }

    int M;
    scanf("%d", &M);
    for(int i=1; i<=M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int common = LCA(a, b);
        int result = dist[a] + dist[b] - (2*dist[common]);
        printf("%d\n", result);
    }

    return 0;
}