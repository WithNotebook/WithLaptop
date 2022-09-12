#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int V;
map<int, int> tree[100001];
bool visited[100001];

int dfs(int cur,int distance)
{
    int tempDist = 0;
    for(map<int,int>::iterator it = tree[cur].begin(); it!=tree[cur].end(); it++)
    {
        int next = (*it).first;
        if(!visited[next])
        {
            int nextDist = distance + (*it).second;
            visited[next] = true;
            tempDist = max(dfs(next, nextDist), tempDist);
            visited[next] = false;
        }

    }

    return max(tempDist, distance);
}

int main()
{
    scanf("%d", &V);

    for(int i=0; i<V; i++)
    {
        int parents; 
        scanf("%d", &parents);

        int child =0;
        int distance=0;

        while(child != -1)
        {
            scanf("%d", &child);
            if (child != -1)
            {
                scanf("%d", &distance);
                tree[parents].insert(pair<int, int>{child, distance});
                tree[child].insert(pair<int, int>{parents, distance});
            }
        }
    }
    
    int maxValue = 0;
    for(int i=1; i<=V; i++)
    {
        visited[i] = true;
        maxValue = max(dfs(i, 0), maxValue);
        visited[i] = false;
    }

    printf("%d", maxValue);
    return 0;
}