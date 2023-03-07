#include<stdio.h>
#include<vector>

using namespace std;

#define N_MAX 100001

vector<int> v[N_MAX];
int dp[N_MAX];

void makeTree(int prv, int cur)
{
    for(auto it=v[cur].begin(); it!=v[cur].end(); it++)
    {
        if((*it)==prv) v[cur].erase(it);
        if(v[cur].end()==it) break;

        int next = (*it);
        makeTree(cur, next);
    }
}

void dfs(int cur)
{
    dp[cur] = 1;

    for(auto it=v[cur].begin(); it!=v[cur].end(); it++)
    {
        int next = (*it);
        dfs(next);
        dp[cur] += dp[next];
    }
}

int main()
{
    int N, R, Q;
    scanf("%d %d %d", &N, &R, &Q);

    for(int i=1; i<N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    makeTree(0, R);
    dfs(R);
    for(int i=1; i<=Q; i++)
    {
        int u;
        scanf("%d", &u);
        printf("%d\n", dp[u]);
    }

    return 0;
}