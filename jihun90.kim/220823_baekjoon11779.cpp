#include <stdio.h>
#include <vector>
#include <queue>

#define MAX 100001
#define INF 1000 * 100000

using namespace std;

vector<pair<int, int>> graph[MAX];
int root[MAX];

void dijkstra(int start, int end,int num)
{
    pair<int, int> startPoint(0, start);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(startPoint);

    vector<int> result(num+1, INF);

    result[start] = 0;
    root[start] = 0;

    vector<int> resultPath;

    while(!pq.empty())
    {
        pair<int, int> cur = pq.top();
        int currentIndex = cur.second; 
        int currentDist =cur.first;

        pq.pop();

        if(result[currentIndex] < currentDist)
        {
            continue;
        }
    
        for(int i = 0; i < graph[currentIndex].size(); i++)
        {
            int nextIndex = graph[currentIndex][i].second;
            int nextDist =  currentDist + graph[currentIndex][i].first;

            if(result[nextIndex] > nextDist)
            {
                root[nextIndex] = currentIndex;
                result[nextIndex] = nextDist;
                pq.push(pair<int, int>(nextDist, nextIndex));
            }
        }
    }

    printf("%d\n", result[end]);

    int temp = end;
    while(temp)
    {
        resultPath.push_back(temp);
        temp = root[temp];
    }
    printf("%ld\n", resultPath.size());

    for(vector<int>::reverse_iterator it = resultPath.rbegin(); it!=resultPath.rend(); it++)
    {
        printf("%d ", *it);
    }
    printf("\b\n");
}

int main()
{
    int n, m;
    int start, end;

    scanf("%d", &n);
    scanf("%d", &m);
    
    for(int i = 0; i<m; i++)
    {
        int a, b, dist;
        scanf("%d %d %d", &a, &b, &dist);
        graph[a].push_back(pair<int, int>(dist, b));
    }

    scanf("%d %d", &start, &end);
    dijkstra(start, end, n);

    return 0;
}