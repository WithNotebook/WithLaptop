#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define N_MAX 1001
#define INF 100000001

long long D[N_MAX];
vector<int> build[N_MAX];
int inCount[N_MAX];
long long dp[N_MAX];

void execute(queue<int> q)
{
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto next : build[cur])
        {
            inCount[next]--;
            long long temp = dp[cur] + D[next];
            dp[next] = max(dp[next], temp);
            
            if(inCount[next] != 0) continue;
            q.push(next);
        }
    }
}

void init()
{
    for(int i=0; i<=N_MAX; i++)
    {
        D[i] = 0;
        build[i].clear();
        inCount[i] = 0;
        dp[i] = 0;
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int tIndex=1; tIndex<=T; tIndex++)
    {
        init();

        int N, K;
        scanf("%d %d", &N, &K);

        for(int i=1; i<=N; i++)
        {
            long long d;
            scanf("%lld", &d);
            D[i] = d;
        }

        for(int i=1; i<=K; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            build[x].push_back(y);
            inCount[y]++;
        }

        queue<int> start;
        for(int i=1; i<=N; i++)
        {
            if(inCount[i] == 0)
            {
                start.push(i);
                dp[i] = D[i];
            } 
        }

        int W;
        scanf("%d", &W);

        execute(start);
        printf("%lld\n", dp[W]);

    }
    return 0;
}