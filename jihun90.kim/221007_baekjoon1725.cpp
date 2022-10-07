#include<stdio.h>
#include<stack>
#include<algorithm>

using namespace std;

long long h[100001];

int main()
{

    int N;
    scanf("%d", &N);

    for(int i = 1; i<=N; i++)
    {
        long long in;
        scanf("%lld", &in);
        h[i] = in;
    }

    stack<long long> lls; 
    long long maxVal = 0;
    lls.push(0);
    for(int i = 1; i < N+1; i++)
    {
        if(!lls.empty())
        {
            while(h[i] < h[lls.top()])
            {
                maxVal = max(maxVal, h[lls.top()] * (i - lls.top()));
                lls.pop();
            }

            lls.push(i);
        }
}

    return 0;
}