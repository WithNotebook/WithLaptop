#include<stdio.h>
#include<vector>

using namespace std;

#define M_MAX 502
#define N_MAX 502

struct pos
{
    int x;
    int y;
};

int N, M;
int map[N_MAX][M_MAX];
unsigned long long dp[N_MAX][M_MAX];
pos direction[4] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};

unsigned long long dfs(pos cur)
{
    if (dp[cur.x][cur.y] == -1) return 0; 
    if (map[cur.x][cur.y] == -1) return 0;

    if ((cur.x == N) && (cur.y == M)) return 1;
    if (dp[cur.x][cur.y] > 0) return dp[cur.x][cur.y];

    for(int i=0; i<4; i++)
    {
        pos next = { cur.x + direction[i].x, cur.y + direction[i].y };
        
        if(map[cur.x][cur.y] > map[next.x][next.y])
        {
            dp[cur.x][cur.y] += dfs(next);
            
        }
    }
    if (dp[cur.x][cur.y] == 0)
    {
        dp[cur.x][cur.y] = -1;
        return 0;
    }

    return dp[cur.x][cur.y];
}

int main()
{
    for(int i=0; i<N_MAX; i++)
    {
        for(int j=0; j<M_MAX; j++)
        {
            map[i][j] = -1;
            dp[i][j] = 0;
        }
    }

    scanf("%d %d", &N, &M);

    for(int i=1; i<=N; i++)
    {
        for(int j=1;j<=M; j++)
        {
            int h;
            scanf("%d", &h);
            map[i][j] = h;
        }
    }

    unsigned long long result = dfs(pos({1,1}));
    printf("%llu\n", result);
    return 0;
}