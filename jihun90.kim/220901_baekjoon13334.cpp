#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

#define INF 100000000;

typedef long long ll;
typedef pair<long long, long long> pll2;

int N;
ll L;

struct compare
{
    bool operator()(pll2 a, pll2 b)
    {
        if(a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int main()
{
    scanf("%d", &N);

    priority_queue<pll2, vector<pll2>, compare> pq;
    for(int i=0; i<N; i++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll small, large;
        small = min(a, b);
        large = max(a, b);
        pq.push(pair<ll, ll>(small, large));
    }
    scanf("%lld", &L);

    priority_queue<pll2, vector<pll2>, compare> tempPq;
    tempPq = pq;
    
    ll maxCount = 0;
    while (!tempPq.empty())
    {      
        ll start = -INF;
        ll end = -INF;
        ll lineCount = 0;

        pq = tempPq;
         while(!pq.empty())
        {
            pair<ll, ll> ho = pq.top();
            ll curStart = ho.first;
            ll curEnd = ho.second;
            pq.pop();

            if ((end < curStart))
            {
                start = curStart;
                lineCount = 0;
            }
            end = max(end, curEnd);

            if ((end-start) > L)
            {
                lineCount = 0;
                break;
            }

            lineCount++;
            if(maxCount < lineCount) maxCount = lineCount;
        }
        tempPq.pop();
    }

    printf("%lld", maxCount);

    return 0;
}