#include<stdio.h>
#include<stack>
#include<algorithm>

using namespace std;

long long h[100002];

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
    for(int i = 1; i < N+2; i++)
    {
        while( !lls.empty() && (h[i] < h[lls.top()]))
        {
            long long temp = lls.top();
            lls.pop();
            maxVal = max(maxVal, h[temp] * (i - lls.top() - 1));
        }

        lls.push(i);
    
    }

    printf("%lld\n", maxVal);
    return 0;
}