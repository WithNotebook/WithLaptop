#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define INF 100000000;

typedef long long ll;
typedef pair<long long, long long> pll2;

int N;
ll L;


bool compare(pll2 a, pll2 b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
};

int main()
{
    scanf("%d", &N);

    vector<pll2> v;
    for(int i=0; i<N; i++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll small, large;
        small = min(a, b);
        large = max(a, b);
        v.push_back(pair<ll, ll>(small, large));
    }
    sort(v.begin(), v.end(), compare);
    scanf("%lld", &L);
    
    ll maxCount = 0;
    for(auto it = v.begin(); it!=v.end(); it++)
    {      
        ll start = -INF;
        ll end = -INF;
        ll lineCount = 0;

        vector<pll2>::iterator startIt = it;

        for(auto sIt = startIt; sIt != v.end(); sIt++)
        {
            ll curStart = (*sIt).first;
            ll curEnd = (*sIt).second;

            if ((end < curStart))
            {
                start = curStart;
                lineCount = 0;
            }
            end = max(end, curEnd);

            if ((end-start) > L)
            {
                break;
            }

            lineCount++;
            maxCount = max(maxCount, lineCount);
        }
    }

    printf("%lld\n", maxCount);

    return 0;
}