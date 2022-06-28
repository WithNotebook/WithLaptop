#include<stdio.h>
#include<list>
#include<vector>
#include<queue>

using namespace std;

list<int> _result;
int _cityCount = 0;
int _start, _end = 0;
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
int _max[10001];

int main()
{
    scanf("%d", &_cityCount);

    int cmdCount = 0;
    int inDegree[_cityCount+1];
    int tempInDegree[_cityCount+1];
    int tempMax[10001];

    for(int i= 1; i<=_cityCount; i++)
    {
        inDegree[i] = 0;
        tempInDegree[i] = 0;
        tempMax[i] = 0;
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
            tempMax[next] = max(_town[front].adj[next] + _max[front], tempMax[next]);
            if(_town[front].adj[next] > 0)
            {
                inDegree[next]--;
                if(inDegree[next] == 0)
                {   
                    _max[next] = tempMax[next];
                    q.push(next);
                }
            }
        }
    }
    _resultMax = tempMax[_end];


    printf("%d\n", _resultMax);

    return 0;
};
