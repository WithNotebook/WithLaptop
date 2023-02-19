#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define N_MAX 100001

long long city[N_MAX];
long long dp[N_MAX][2];
vector<long long> tree[N_MAX];
bool visited[N_MAX];

void dfs(int cur)
{
    visited[cur] = true;

    dp[cur][0] = 0;
    dp[cur][1] = city[cur];

    for(auto it = tree[cur].begin(); it!=tree[cur].end(); it++)
    {
        int next = (*it);
        if(!visited[next])
        {
            dfs(next);

            dp[cur][0] += max(dp[next][0], dp[next][1]);  
            dp[cur][1] += dp[next][0];
        }
    }
}

void init(int N)
{
    for(int i=1; i<=N; i++)
    {
        visited[i] = false;
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i=1; i<=N; i++)
    {
        long long people;
        scanf("%lld", &people);
        city[i] = people;
    }

    for(int i=1; i<=N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    printf("%lld\n", max(dp[1][0],dp[1][1]));

    return 0;
}