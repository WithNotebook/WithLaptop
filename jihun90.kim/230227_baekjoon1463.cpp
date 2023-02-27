#include<stdio.h>
#include<algorithm>

using namespace std;

int resCnt = 9999999;

int dfs(long long n, int count)
{
    if (n<1) return 9999999; 
    if (n==1) return (resCnt = min(resCnt, count));
    if (resCnt < count) return resCnt;

    long long in;
    if((n%3) ==0)
    {
        in = n/3;
        resCnt = min(dfs(in, count+1), resCnt);
    }

    if((n%2) ==0)
    {
        in = n/2;
        resCnt = min(dfs(in, count +1), resCnt);
    }

    resCnt = min(dfs(n-1, count+1), resCnt);

    return resCnt;
}

int main()
{
    long long N;
    scanf("%lld", &N);

    printf("%d",dfs(N, 0));
    return 0;
}