#include<stdio.h>
#include<vector>
#include<set>
#include<queue>

using namespace std;

#define N_MAX 3001

vector<int> subway[N_MAX];
int dist[N_MAX];
int visited[N_MAX];
bool isRing[N_MAX];
set<int> ringPoint;

bool findRing(int prev, int cur)
{
    if(isRing[cur]) return true;
    if(visited[cur])
    {
        return (isRing[cur] = true);
    } 

    bool ring = false;
    visited[cur] = true;

    bool hasFalse = false;
    bool hasTrue = false;
    for(auto it = subway[cur].begin(); it!=subway[cur].end(); it++)
    {
        if(prev == (*it)) continue;

        int next = (*it);
        bool tempRing = findRing(cur, next);
        
        if(isRing[cur]) tempRing = false;

        if (tempRing) hasTrue = true;
        else hasFalse = true;

        ring = tempRing || ring;

    }
    if(hasFalse && hasTrue) ringPoint.insert(cur);
    if(!isRing[cur]) isRing[cur] = ring;

    return ring;
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i=1; i<=N; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        subway[a].push_back(b);
        subway[b].push_back(a);
    }

    findRing(0, 1);

    queue<pair<int, int>> q;

    for(auto ring : ringPoint)
    {
        q.push(pair<int, int>(ring, 0));
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(auto station : subway[cur.first])
        {
            int next = station;
            int depth = cur.second + 1;
            if(!isRing[next] && (dist[next] == 0))
            {
                dist[next] = depth;
                q.push(pair<int, int>(next, depth));
            }   
        }
    }
    
    for(int i=1; i<=N; i++)
    {
        printf("%d ", dist[i]);
    }

    return 0;
}