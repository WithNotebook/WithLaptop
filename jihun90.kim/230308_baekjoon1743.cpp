#include<stdio.h>
#include<algorithm>
#include<cmath>

using namespace std;

#define N_MAX 102
#define M_MAX 102

char map[N_MAX][M_MAX];
bool visited[N_MAX][M_MAX];
pair<int, int> directions[4] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};

int dfs(int curX, int curY)
{
    int result = 0;
    if (visited[curX][curY]) return result;

    visited[curX][curY] = true;
    result = 1;
    for(auto dir : directions)
    {
        int nextX = dir.first + curX;
        int nextY = dir.second + curY;
        if(map[nextX][nextY] == '#')
        {
           result += dfs(nextX, nextY);
        }
    }
    return result;
}

int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    for(int i=0; i<N_MAX; i++)
    {
        for(int j=0; j<M_MAX; j++)
        {
            map[i][j] = '.';
            visited[i][j] = false;
        }
    }

    for(int i=1; i<=K; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x][y] = '#';
    }

    int res = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(map[i][j]=='#')
            {
                res = max(res, dfs(i, j));
            }
        }
    }
    printf("%d\n", res);

    return 0;
}