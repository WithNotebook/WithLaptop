#include<stdio.h>

using namespace std;

#define N_MAX 201
#define INF 200001

int dist[N_MAX][N_MAX];
int map[N_MAX][N_MAX];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<N_MAX; i++)
    {
        for(int j=0; j<N_MAX; j++)
        {
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
            map[i][j] = 0;
        }
    }

    for(int i=1; i<=m; i++)
    {
        int a,b, d;
        scanf("%d %d %d", &a, &b, &d);
        dist[a][b] = d;
        dist[b][a] = d;
        map[a][b] = b;
        map[b][a] = a;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int temp = dist[i][k] + dist[k][j];
                if(dist[i][j] > temp)
                {
                    map[i][j] = map[i][k];
                    dist[i][j] = temp;
                }
            }   
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if (map[i][j] == 0) printf("- ");
            else printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}