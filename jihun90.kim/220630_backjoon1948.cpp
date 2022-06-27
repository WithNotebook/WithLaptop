#include<stdio.h>
#include<list>
#include<vector>
#include<queue>

using namespace std;

list<int> _result;
int _cityCount = 0;
int _start, _end = 0;
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

int main()
{
    scanf("%d", &_cityCount);

    int cmdCount = 0;
    int inDegree[_cityCount+1];

    for(int i= 1; i<=_cityCount; i++)
    {
        inDegree[i] = 0;
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
    }
    
    scanf("%d %d", &_start, &_end);
    
    queue<int> q;
    q.push(_start);
    _town[q.front()].visible = true;
    while(!q.empty())
    {
        int front = q.front();
        if(inDegree[front] == 0)
        {
            printf("%d ", front);
            _result.push_front(front);
            q.pop();
        }

        for(int next=1; next<10001; next++)
        {
            if(_town[front].adj[next] > 0)
            {
                inDegree[next]--;
                if(inDegree[next] == 0)
                {
                    q.push(next);
                }
            }


        }
        
    }

    int maxCount = 0;
    for(int cur = 0; cur<_result.size(); cur++)
    {
        int temp = 0;
        int index = 0;
        int front = _result.front();
        _result.pop_front();
        for(int next = 0; next<10001; next++)
        {
            int nextAdj = _town[next].adj[front];
            if((nextAdj > 0) && temp < nextAdj)
            {
                temp = nextAdj;
                index = next;
            }
        }
        maxCount += temp;
    }

    return 0;
};
