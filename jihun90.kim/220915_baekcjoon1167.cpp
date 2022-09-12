#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int V;
map<int, int> tree[100001];
bool visited[100001];
pair<int, int> maxDist;

void dfs(int cur, int distance)
{
    pair<int,int> temp;

    for(map<int,int>::iterator it = tree[cur].begin(); it!=tree[cur].end(); it++)
    {
        int next = (*it).first;
        if(!visited[next])
        {
            int nextDist = distance + (*it).second;

            if(nextDist > maxDist.second)
            {
                maxDist.first = next;
                maxDist.second = nextDist;
            }
            
            visited[next] = true;
            dfs(next, nextDist);
            visited[next] = false;
        }
    }
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

    int start = 2;
    visited[start] = true;
    dfs(start, 0);
    visited[start] = false;

    start = maxDist.first;
    visited[start] = true;
    dfs(start, 0);
    visited[start] = false;

    printf("%d", maxDist.second);
    return 0;
}