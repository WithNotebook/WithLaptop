#include<stdio.h>
#include<cmath>
#include<vector>

using namespace std;

#define N_MAX 100001

vector<int> graph[N_MAX];
vector<int> tree[N_MAX];
vector<int> parents[N_MAX];
int nodeDepth[N_MAX];
bool visited[N_MAX] = {false, };

int log_N;
int N;

int LCA(int a, int b)
{
    int targetNode = a;
    int compareNode = b;
    
    if(nodeDepth[targetNode] != nodeDepth[compareNode])
    {
        if(nodeDepth[targetNode] < nodeDepth[compareNode]) swap(targetNode, compareNode);
        
        for(int i=log_N-1; i>=0; i--)
        {
            int targetDepth = nodeDepth[parents[targetNode][i]];
            if(targetDepth >= nodeDepth[compareNode])
            {
                targetNode = parents[targetNode][i];
            }
        }
    }

    int result = targetNode;
    if (targetNode != compareNode)
    {
        for(int i=log_N-1; i>=0; i--) 
        {
            if(parents[targetNode][i] != 0)
            {
                if(parents[compareNode][i] != parents[targetNode][i])
                {
                    targetNode = parents[targetNode][i];
                    compareNode = parents[compareNode][i];
                }
            }
            
            result = parents[targetNode][0];//result = parents[targetNode][i]; ***
        }
    }
    return result;
}

void setParents() //*** 별표 3개!
{
    for(int j=1; j<log_N; j++)
    {
        for(int i=1; i<=N; i++)    
        {
            parents[i][j] = parents[parents[i][j-1]][j-1];
        }
    }
}

void setTree(int cur)
{

    for(vector<int>::iterator it = graph[cur].begin(); it!=graph[cur].end(); it++)
    {
        int next = (*it);
        if(!visited[next])
        {
            parents[next][0] = cur;
            visited[next] = true;
            tree[cur].push_back(next);
            nodeDepth[next] = nodeDepth[cur] +1;
            setTree(next);
        }
    }
    return ;
}

int main()
{
    scanf("%d", &N);

    for(int i=1; i<N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    log_N = log(N_MAX)+1;

    for(int i=0; i<=N; i++)
    {
        parents[i].resize(log_N);
    }

    visited[0] = true;
    visited[1] = true;
    nodeDepth[1] = 1;
    parents[1][0] = 0;
    setTree(1);
    setParents();
    
    int M=0; 
    scanf("%d", &M);

    for(int i=0; i<M; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        int result = LCA(a, b);
        printf("%d\n", result);
    }

    return 0;
}