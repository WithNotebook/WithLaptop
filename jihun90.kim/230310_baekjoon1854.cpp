    #include<stdio.h>
    #include<queue>
    #include<vector>

    using namespace std;

    #define INF 2000000001
    #define N_MAX 1001


    void dijkstra(vector<pair<int, int>>* map, int n, int k, int* res)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        priority_queue<int>* dist = new priority_queue<int>[n+1];

        int start = 1;
        q.push(pair<int, int>(0, 1));
        dist[1].push(0);

        while (!q.empty())
        {
            pair<int, int> cur;
            cur = q.top();
            q.pop();
            
            int curDist = cur.first;
            int curPos = cur.second;

            for(auto next : map[curPos])
            {
                int nextDist = next.first + curDist;
                int nextPos = next.second;

                if(dist[nextPos].size() < k)
                {
                    dist[nextPos].push(nextDist);
                    q.push(pair<int, int>(nextDist, nextPos));
                }
                else
                {
                    if(dist[nextPos].top() > nextDist)
                    {
                        dist[nextPos].pop();
                        dist[nextPos].push(nextDist);
                        q.push(pair<int, int>(nextDist, nextPos));
                    }
                }
            }
        }
        
        for(int i=1; i<=n; i++)
        {
            if(dist[i].size() >= k) res[i] = dist[i].top();
            else res[i] = -1;
        }

        delete [] dist;
    }

    int main()
    {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        vector<pair<int, int>>* v = new vector<pair<int, int>>[n+1];
        for(int i=1; i<=m; i++)
        {
            int a, b, c;
            scanf("%d %d %d",&a, &b, &c);
            v[a].push_back(pair<int, int>(c, b));
        }

        int* res = new int[n+1];
        dijkstra(v,n,k,res);

        for(int i=1; i<=n; i++)
        {
            printf("%d\n", res[i]);
        }

        delete [] res;
        delete [] v;
        

        return 0;
    }