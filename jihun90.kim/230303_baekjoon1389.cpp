#include<stdio.h>
#include<set>
#include<cmath>

using namespace std;

#define N_MAX 101
#define INF 10001

set<int> man[N_MAX];
int dist[N_MAX][N_MAX];
int N, M;

void Floyd()
{
    for(int k=1; k<=N; k++)
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

void init()
{
    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<=N; j++)
        {
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i=1; i<=N; i++)
    {
        for(auto j : man[i])
        {
            dist[i][j] = 1;
        }
    }
}

int main()
{
    scanf("%d %d",&N, &M);

    for(int i=1; i<=M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        man[a].insert(b);
        man[b].insert(a);
    }

    init();
    Floyd();

    int result = INF;
    int minSum = INF;
    for(int i=1; i<=N; i++)
    {
        int sum = 0;
        for(int j=1; j<=N; j++)
        {
            sum += dist[i][j];
        }
        if(minSum>sum) 
        {
            minSum = sum;
            result = i;
        }
    }

    printf("%d", result);

    return 0;
}