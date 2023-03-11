#include<stdio.h>
#include<vector>
#include<cmath>

using namespace std;

#define N_MAX 1000001

vector<int> v[N_MAX];
int dp[N_MAX][2];

void dfs(int prv, int cur)
{
    dp[cur][0] = 0; // if i am not early adaptor, around minium early adaptor count
    dp[cur][1] = 1; // if i am early adaptor, around minium early adaptor count (me)

    for(auto it=v[cur].begin(); it!=v[cur].end(); it++)
    {
        if((*it) == prv) it = v[cur].erase(it);
        if(it == v[cur].end()) break;

        int next = (*it);
        dfs(cur, next);
        dp[cur][0] += dp[next][1];
        dp[cur][1] += min(dp[next][0], dp[next][1]);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i=1; i<=N; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for(int i=1; i<N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);

    int res = min(dp[1][0], dp[1][1]);
    printf("%d\n", res);
    
    return 0;
}