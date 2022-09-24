#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 200000000

using namespace std;

int N, E;
vector<pair<int, int>> graph[801];


int dijkstra(int start, int end)
{
    int distToStart[N+1];

    for(int i=1; i<=N; i++)
    {
        distToStart[i] = INF;
    }
    distToStart[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    pq.push(pair<int, int>(0, start));

    int dist = 0;
    while(!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        dist = cur.first;
        for(auto it = graph[cur.second].begin(); it!=graph[cur.second].end(); it++)
        { 
            int nextDist = dist + (*it).first;
            int nextIndex = (*it).second;
            if(nextDist < distToStart[nextIndex])
            {
                distToStart[nextIndex] = nextDist;

                pair<int, int> next(nextDist, nextIndex);
                pq.push(next);
            }

        }
    }

    return distToStart[end]<INF?distToStart[end]:-1;

}

int main()
{
    scanf("%d %d", &N, &E);

    for(int i=1; i<=E; i++)
    {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);

        graph[a].push_back(pair<int, int>(c,b));
        graph[b].push_back(pair<int, int>(c,a));
    }

    int dest1, dest2;
    scanf("%d %d", &dest1, &dest2);
    
    int a2Orb2 =  dijkstra(dest1, dest2);

    int a1 = dijkstra(1, dest1);
    int a3 = dijkstra(dest2, N);
    
    int b1 = dijkstra(1, dest2);
    int b3 = dijkstra(dest1, N);

    int aDist = INF;
    if ((a1 != -1) && (a2Orb2 != -1) && (a3 != -1))
    {
        aDist = a1 + a2Orb2 + a3;
    }

    int bDist = INF;
    if ((b1 != -1) && (a2Orb2 != -1) && (b3 != -1))
    {
        bDist = b1 + a2Orb2 + b3;
    }

    int dist = min(aDist, bDist);

    if (dist == INF) dist = -1; 

    printf("%d", dist);

    return 0;
}