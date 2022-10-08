#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define INF 10000000

vector<pair<int, int>> graph[10001];

int dijkstra(int start, int end, int N)
{
    int arr[N];
    for(int i=1; i<=N; i++)
    {
        arr[i]= INF;
    }
    arr[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(pair<int, int>(0, start));

    while (!pq.empty())
    {
        pair<int, int> temp = pq.top();
        pq.pop();

        int dist = temp.first;
        int cur = temp.second;

        for(vector<pair<int, int>>::iterator it = graph[cur].begin(); it!=graph[cur].end(); it++)
        {
            int next = it->second;
            int nextDist = it->first + dist;

            if(arr[next] > nextDist)
            {
                pq.push(pair<int, int>(nextDist, next));
                arr[next]= nextDist;
            }
        }
    }
    return arr[end];
}

int main()
{
    int N, M, X;
    scanf("%d %d %d", &N, &M, &X);

    for(int i = 0; i<M; i++)
    {
        int start, end, dist;
        scanf("%d %d %d", &start, &end, &dist);

        graph[start].push_back(pair<int, int>(dist, end));
    }
    
    int maxVal = 0;
    for(int i=1; i<=N; i++)
    {
        if(i == X) continue;

        int dist = dijkstra(i, X, N);
        dist = dist + dijkstra(X, i,  N);

        maxVal = max(maxVal, dist);
    }
    
    printf("%d", maxVal);
    return 0;
}