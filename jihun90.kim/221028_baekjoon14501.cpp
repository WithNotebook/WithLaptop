#include<stdio.h>
#include<algorithm>

using namespace std;

int T[16];
int P[16];
int dp[16];


int main()
{  
    int N;
    scanf("%d", &N);

    for(int i = 1; i<=N; i++)
    {
        int t,p;
        scanf("%d %d", &t, &p);
        T[i] = t;
        P[i] = p;
    }

    int result = 0;
    for(int i = 1; i<=N+1; i++)
    {
        dp[i] = max(dp[i-1], dp[i]);
        int date = i + T[i];
        if(date <= N+1)
        {
            dp[date] = max(dp[date] , (P[i] + dp[i]));
        }

        result = max(dp[i], result);
    }

    printf("%d", result);

    return 0;
}