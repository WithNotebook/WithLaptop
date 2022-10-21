#include<stdio.h>
#include<algorithm>

using namespace std;

#define R 0
#define G 1
#define B 2
#define MAX 1001 * 1001

int cost[1001][3];
int dp[1001][3];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++ )
	{
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		cost[i][R] = r;
		cost[i][G] = g;
		cost[i][B] = b;
	}

	int result = MAX;
    for(int k=0; k<=2; k++)
    {
        for(int j=0; j<=2; j++)
        {
            if(j==k) dp[1][j] = cost[1][j];
            else dp[1][j] = MAX;
        }

        for (int i = 2; i <= N; i++)
        {
            dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + cost[i][R];
            dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + cost[i][G];
            dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + cost[i][B];
        }

        for(int j=0; j<=2; j++)
        {
            if(j!=k)
            {
                if (result > dp[N][j]) result = dp[N][j];
            } 
        }

    }

	printf("%d", result);
    
    return 0;

}