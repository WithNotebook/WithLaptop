#include<stdio.h>
#include<vector>

using namespace std;

#define N_MAX 300001

struct node
{
    long long subNodeSum;
    int subNodeCount;
};

vector<int> tree[N_MAX];
bool visited[N_MAX];
long long ans;
long long dp[N_MAX];

node dfs(int cur, long long depth)
{
    visited[cur] = true;

    node result = {0, 0};
    node left = {0, 0};
    node right = {0, 0};
    bool isRight = false;

    for (auto it = tree[cur].begin(); it!=tree[cur].end(); it++)
    {
        int next = (*it);
        if(!visited[next])
        {
            if(!isRight)
            {
                isRight = true;
                left = dfs(next, depth+1);
                dp[cur] += dp[next];
            }
            else
            {
                right = dfs(next, depth+1);
                dp[cur] += dp[next];
            }
        }
    }

    result.subNodeSum = (left.subNodeSum + right.subNodeSum);
                            
    result.subNodeCount = left.subNodeCount + right.subNodeCount;

    result.subNodeSum += depth;
    result.subNodeCount += 1;

    dp[cur] =  ((right.subNodeCount * left.subNodeSum) + (left.subNodeCount * right.subNodeSum) 
                    - (left.subNodeCount * right.subNodeCount * depth));
    if(depth!=1) dp[cur] += depth;
   return result;    
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i<N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for(int i=1; i<=N; i++)
    {
        visited[i] = false;
    }

    node result = dfs(1, 0);
    long long sum=0;

    for(int i=1; i<=N; i++)
    {
        sum += dp[i];
    }

    printf("%lld\n", result.subNodeSum + sum);

    return 0;
}
