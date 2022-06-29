    #include<stdio.h>
    #include<list>
    #include<vector>
    #include<queue>

    using namespace std;

    list<int> _result;
    int _cityCount = 0;
    int _start = 0;
    int _end = 0;
    int _resultMax;

    struct town
    {
        int adj[10001];
        bool visible = false;
        int adjCount = 0;

        town()
        {
            for(int i=0; i < 10000; i++)
            {
                adj[i] = 0;
            }
        }
    };

    town _town[10001];
    town _town_rev[10001];
    int _max[10001];
    int _max2[10001];

    int main()
    {
        scanf("%d", &_cityCount);

        int cmdCount = 0;
        int inDegree[_cityCount+1];
        int tempMax[10001];
        int tempMax2[10001];
        int outDegree[_cityCount +1];

        for(int i= 1; i<=_cityCount; i++)
        {
            inDegree[i] = 0;
            tempMax[i] = 0;
            outDegree[i]  = 0;
            tempMax2[i] = 0;
        }
        
        scanf("%d", &cmdCount);
        for(int i = 0; i < cmdCount; i++)
        {
            int cur;
            int next;
            int adj;
            scanf("%d %d %d", &cur, &next, &adj);
            _town[cur].adj[next] = adj;
            inDegree[next]++;
            _town[cur].adjCount++;

            _town_rev[next].adj[cur] = adj;
            outDegree[cur]++;
        }
        
        scanf("%d %d", &_start, &_end);
        
        queue<int> q;
        _max[_start] = 0;
        
        q.push(_start);
        while(!q.empty())
        {
            int front = q.front();
            if(inDegree[front] == 0)
            {
                q.pop();
            }

            for(int next=1; next<10001; next++)
            {
                if(_town[front].adj[next] > 0)
                {
                    tempMax[next] = max(_town[front].adj[next] + _max[front], tempMax[next]);
                    inDegree[next]--;
                    if(inDegree[next] == 0)
                    {   
                        _max[next] = tempMax[next];
                        q.push(next);
                    }
                }
            }
        }
        _resultMax = _max[_end];

        queue<int> q2;
        q2.push(_end);
        queue<pair<int,int>> result;
        while(!q2.empty())
        {
            int front = q2.front();

            if(outDegree[front] == 0)
            {
                q2.pop();
            }

            for(int next = 0; next < 10001; next++)
            {

                if(_town_rev[front].adj[next] > 0)
                {
                    tempMax2[next] = max(_max2[front] + _town_rev[front].adj[next] ,tempMax2[next]);
                    outDegree[next]--;
                    if(outDegree[next] == 0)
                    {
                        _max2[next] = tempMax2[next];
                        q2.push(next);
                    }
                }
            }


        }

        for(int front = 1; front <= _cityCount; front++)
        {
            for(int next = 1; next<=_cityCount; next++)
            {
                if(front == next)
                {
                    continue;
                }

                if(_town_rev[front].adj[next] > 0)
                {
                    if(
                        (((_max2[front] + _town_rev[front].adj[next]) + _max[next]) == _max[_end] )
                        )
                    {
                        result.emplace(front, next);
                    }
                }
            }
        }



        printf("%d\n", _resultMax);
        int count = result.size();
        printf("%d", count);
        return 0;
    };
