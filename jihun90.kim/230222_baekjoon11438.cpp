#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

#define N_MAX 100001
#define LOG_N 20 //(log2(N_MAX))

vector<int> tree[N_MAX];
int parents[N_MAX][LOG_N];
int depth[N_MAX];


int LCA(int a, int b)
{
    int targetNode = a;
    int compareNode = b;
    
    if(depth[targetNode] != depth[compareNode])
    {
        if(depth[targetNode] < depth[compareNode]) swap(targetNode, compareNode);
        
        int logN = floor(log2(depth[targetNode])); // 2^(logN+1) >= depth[targetLog]
        for(int i=logN; i>=0; i--)
        {
            int targetDepth = depth[parents[targetNode][i]];
            if(targetDepth >= depth[compareNode])
            {
                targetNode = parents[targetNode][i];
            }
        }
    }

    int result = targetNode;
    if (targetNode != compareNode)
    {
        int logN = floor(log2(depth[targetNode])); // 2^(logN+1) >= depth[targetLog]
        for(int i=logN; i>=0; i--) 
        {
            if(parents[compareNode][i] != parents[targetNode][i])
            {
                targetNode = parents[targetNode][i];
                compareNode = parents[compareNode][i];
            }
            result = parents[targetNode][i];
        }
    }
    return result;
}

void makeTree(int cur)
{
    for(int i=1; i<LOG_N; i++)
    {
        parents[cur][i] = parents[parents[cur][i-1]][i-1];
    }

    for(auto it=tree[cur].begin(); it!=tree[cur].end(); it++)
    {
        if (parents[cur][0] == (*it)) tree[cur].erase(it);
        if(it == tree[cur].end()) break;

        int next = (*it);
        parents[next][0] = cur;
        depth[next] = depth[cur] + 1;
        makeTree(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int N;
    cin >> N;

    for(int i=1; i<N; i++)
    {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for(int i=0; i<=N; i++)
    {
        depth[i] = -1;
    }

    parents[1][0] = 0;
    depth[1] = 0;
    makeTree(1);
    
    int M=0; 
    cin >> M;

    while (M--)
    {
        int a,b;
        cin >> a >> b;
        int result = LCA(a, b);
        cout << result << '\n';
    }
    return 0;
}