#include<stdio.h>
#include<queue>

using namespace std;

#define N_MAX 102

struct pos
{
    int x;
    int y;
};


char RGB[N_MAX][N_MAX];
char RG_B[N_MAX][N_MAX];
pos direction[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void dfs(int i, int j)
{
    char color = RGB[i][j];
    if(color == 'N') return;
    
    RGB[i][j] = 'N';
    for(int d=0; d<4; d++)
    {
        pos next;
        next.x = direction[d].x + i;
        next.y = direction[d].y + j;
        if(RGB[next.x][next.y] == color) dfs(next.x, next.y);
    }
}

void bfs(int i, int j)
{
    queue<pos> q;
    q.push({i, j});

    while (!q.empty())
    {
        pos temp = q.front();
        q.pop();
        char color = RG_B[temp.x][temp.y];

        if(color == 'N') continue;
        RG_B[temp.x][temp.y] = 'N';

        for(int d=0; d<4; d++)
        {
            pos next;
            next.x = direction[d].x + temp.x;
            next.y = direction[d].y + temp.y;
            if(RG_B[next.x][next.y]==color) q.push({next.x, next.y});
        }
    }
    
}


int main()
{
    for(int i=0; i<N_MAX; i++)
    {
        for(int j=0; j<N_MAX; j++)
        {
            RGB[i][j] = 'N';
            RG_B[i][j] = 'N';
        }
    } 

    int N;
    scanf("%d", &N);

    
    char c = getchar();
    int index = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            c = getchar();
            RGB[i][j] = c;
            if(c!='B') RG_B[i][j] = 'R';
            else RG_B[i][j] = c;
        }
        getchar();
    }
    
    int cnt = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(RGB[i][j] != 'N')
            {
                dfs(i,j);
                cnt++;
            }
        }
    }

    int cnt2 =0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(RG_B[i][j] != 'N')
            {
                bfs(i, j);
                cnt2++;
            }
        }
    }

    printf("%d %d\n", cnt, cnt2);

    return 0;
}