#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define DIST_MAX 10000000001
#define N_MAX 401

struct city
{
    int pos;
    long long dist;
    bool isPaved;
    bool isReturn;

    bool operator<(const city &c) const
    {
        return (c.dist < dist);
    }
};

vector<city> map[N_MAX];
vector<city> inverseMap[N_MAX];

pair<int, long long> dijkstra(int N, int M)
{
    long long dist[N_MAX][2][2]; //[N_MAX][forward/reverse][isPaved]

    for(int i=1; i<=N; i++)
    {
        dist[i][0][0] = DIST_MAX;
        dist[i][0][1] = DIST_MAX;
        dist[i][1][0] = DIST_MAX;
        dist[i][1][1] = DIST_MAX;
    }

    int startPos = 1;
    city start = {1, 0, false, false};
    
    dist[startPos][0][0] = 0;

    priority_queue<city> pq;
    pq.push(start);

    int count[2];
    count[0] = 0;
    count[1] = 0;
    while (!pq.empty())
    {
        city cur = pq.top();
        pq.pop();

        for(auto it=map[cur.pos].begin(); it!=map[cur.pos].end(); it++)
        {
            city next = (*it);
            next.dist = next.dist + cur.dist;
            next.isPaved = cur.isPaved;
            next.isReturn = cur.isReturn;

            if(dist[next.pos][next.isReturn][next.isPaved] >= next.dist)
            {
                if((next.isReturn) && (next.pos == 1))
                {
                    long long tempDist = dist[next.pos][next.isReturn][next.isPaved];
                    bool isEqual = (tempDist == next.dist);
                    count[next.isPaved] = isEqual ? count[next.isPaved]+1 : 1;
                }

                dist[next.pos][next.isReturn][next.isPaved] = next.dist;
                if((next.pos==N) && (!next.isReturn)) 
                {
                    next.isReturn =true;
                    dist[next.pos][next.isReturn][next.isPaved] = next.dist;
                }

                pq.push(next);
            }
        }

        if(!cur.isPaved)
        {
            for(auto it=inverseMap[cur.pos].begin(); it!=inverseMap[cur.pos].end(); it++)
            {
                city next = (*it);
                next.dist = next.dist + cur.dist;
                next.isPaved = true;
                next.isReturn = cur.isReturn;

                if(dist[next.pos][next.isReturn][next.isPaved] >= next.dist)
                {
                    if((next.isReturn) && (next.pos == 1))
                    {
                        long long tempDist = dist[next.pos][next.isReturn][next.isPaved];
                        bool isEqual = (tempDist == next.dist);
                        count[next.isPaved] = isEqual ? count[next.isPaved]+1 : 1;
                    }

                    dist[next.pos][next.isReturn][next.isPaved] = next.dist;
                    if((next.pos==N) && (!next.isReturn)) 
                    {
                        next.isReturn =true;
                        dist[next.pos][next.isReturn][next.isPaved] = next.dist;
                    }

                    pq.push(next);
                }
            }
        }
    }

    if(dist[1][1][0] <= dist[1][1][1])
    {
        return pair<int, long long>(0, -1);
    }
    else
    {
        return pair<int, long long>(count[1], dist[1][1][1]);
    }
}

int main()
{
    int testCase;
    scanf("%d", &testCase);

    for(int testIndex=1; testIndex<=testCase; testIndex++)
    {
        int N, M;
        scanf("%d %d", &N, &M);

        for(int i=1; i<=M; i++)
        {
            int a, b;
            long long c;
            scanf("%d %d %lld", &a, &b, &c);
            
            map[a].push_back({b, c, false, false});
            inverseMap[b].push_back({a, c, false, false});
        }

        pair<int, long long> result = dijkstra(N, M);
        
        printf("#%d ", testIndex);
        if(result.second != -1) printf("%d %lld\n",result.first, result.second);
        else printf("-1\n");
    }

    return 0;
}