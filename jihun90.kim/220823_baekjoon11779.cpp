#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_set>
#include <stack>

#define MAX 100001

using namespace std;

vector<pair<int, int>> graph[MAX];
void dijkstra(int start, int end,int num)
{
    pair<int, int> startPoint(0, start);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(startPoint);

    vector<int> result(num+1, 999999);
    result[start] = 0;

    unordered_set<int> resultPath;

    while(!pq.empty())
    {
        pair<int, int> cur = pq.top();
        int currentIndex = cur.second; 
        int currentDist =cur.first;

        pq.pop();
    
        for(int i = 0; i < graph[currentIndex].size(); i++)
        {
            int nextIndex = graph[currentIndex][i].second;
            int nextDist =  currentDist + graph[currentIndex][i].first;

            if(result[nextIndex] > nextDist)
            {
                result[nextIndex] = nextDist;
                pq.push(pair<int, int>(nextIndex, nextDist));
                resultPath.insert(currentIndex);
                if(nextIndex == end)
                {
                    resultPath.insert(end);
                    break;
                }
            }
        }
    }

    printf("%d\n", result[end]);
    printf("%ld\n", resultPath.size());

    stack<int> stk;
    for(auto it = resultPath.begin(); it!=resultPath.end(); it++)
    {
        stk.push(*it);
    }

    while(!stk.empty())
    {
        printf("%d", stk.top());
        stk.pop();
        
        if(!stk.empty())
        {
            printf(" ");
        }
    }
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
        graph[b].push_back(pair<int, int>(dist, a));
    }

    scanf("%d %d", &start, &end);
    dijkstra(start, end, n);

    return 0;
}