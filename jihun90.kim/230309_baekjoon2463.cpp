#include<stdio.h>
#include<queue>

using namespace std;

#define N_MAX 100001
#define M_MAX 100001
#define MOD 1000000000

int parent[N_MAX];
long long nodeSize[N_MAX];

int find(int a)
{
    if(a == parent[a]) return a;

    return (parent[a] = find(parent[a]));
}

bool unionFunction(int a, int b)
{
    int parentA = find(a);
    int parentB = find(b);

    if(parentA != parentB)
    {
        parent[parentB] = parentA;
        nodeSize[parentA] = nodeSize[parentB] + nodeSize[parentA];

        return true;
    }

    return false;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    priority_queue<pair<long long, pair<int, int>>> pq;

    for(int i=0; i<N_MAX; i++)
    {
        parent[i] = i;
        nodeSize[i] = 1;
    }
    long long totalSum = 0;
    for(int i=1; i<=M; i++)
    {
        int a, b;
        long long dist;
        scanf("%d %d %lld", &a, &b, &dist);

        if(b<a) swap(a, b);
        pair<long long, pair<int ,int>> temp;
        temp.first = dist;
        temp.second = pair<int, int>(a, b);
        pq.push(temp);
        totalSum += dist;
    }

    long long res = 0;
    while (!pq.empty())
    {
        long long dist = pq.top().first;
        pair<int, int> edge = pq.top().second;
        pq.pop();

        int a = edge.first;
        int b = edge.second;

        int parentA = find(a);
        int parentB = find(b);

        long long calcCount = (nodeSize[parentA] * nodeSize[parentB]) % MOD;
        bool isUnion = unionFunction(parentA, parentB);
        if (isUnion)
        {
            res += (totalSum * calcCount) % MOD;
            res %= MOD;
        }
        totalSum -= dist;
    }
    
    printf("%lld\n", res);

    return 0;
}