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
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
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
    ll lineCount = 0;
    priority_queue<long, vector<long>, greater<long>> startPq;
    for(auto it = v.begin(); it!=v.end(); it++)
    {      
        ll curStart = (*it).first;
        ll curEnd = (*it).second;

        if((curEnd-curStart) > L) continue;
        else startPq.push(curStart);

        lineCount++;

        while (!startPq.empty())
        {
            long tempStart = curEnd - L;
            if (tempStart > startPq.top()) 
            {
                startPq.pop();
                lineCount--;
            }
            else break;
        }
        maxCount = max(maxCount, lineCount);
    }

    printf("%lld\n", maxCount);

    return 0;
}