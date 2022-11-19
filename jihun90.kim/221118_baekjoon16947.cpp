#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

bool visited[3001];
vector<int> graph[3001];
bool isCycle[3001];

int BFS(int target) // Calc distance to SoonHwanSun 
{
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push(pair<int, int>(target, 0));

    visited[q.front().first] = true;

    while (!q.empty())
    {
        int index = q.front().first;
        int count = q.front().second;
        bool isSHS = isCycle[index];
        if (isSHS) break;

        q.pop();

        count++;
        visited[index] = true;

        for(auto it = graph[index].begin(); it != graph[index].end(); it++)
        {
            if (!visited[(*it)]) q.push(pair<int, int>((*it), count));
        }
    }
    
    return q.front().second;
}

bool DFS(int start, int cur, int prev) //Update Subway type
{
    bool isSHS = false; //isSoonHwanSun
    
    if ((start == cur) && visited[cur])
    {
        isSHS = true;
        return (isCycle[cur] = isSHS);
    }
    
    if (visited[cur])
    {
        isSHS = true;
        return (isCycle[cur] = isSHS);
    } 

    visited[cur] = true;
    for(vector<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++)
    {
        int next = (*it);
        if (next != prev)
        {
            isSHS = isSHS || DFS(start, next, cur);
        }
    }
    return (isCycle[cur] = isSHS);
}

int main()
{
    int N;

    scanf("%d", &N);

    vector<pair<int, int>> vii;
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);

        vii.push_back(pair<int, int>(a, b));
    }

    int stationIndex = 1;
    DFS(stationIndex, stationIndex, stationIndex);

    for(int i = 1; i<N; i++)
    {
        printf("%d ", BFS(i));
    }
    printf("%d", BFS(N));

    return 0;
}